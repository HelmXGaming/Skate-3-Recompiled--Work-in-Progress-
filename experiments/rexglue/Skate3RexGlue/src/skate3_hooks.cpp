#include "generated/default/skate3rexglue_init.h"

#include <rex/memory.h>
#include <rex/runtime.h>

namespace {

bool IsUsableGuestDataPointer(uint32_t address, uint32_t size) {
  if (address + size < address) {
    return false;
  }

  // Skate 3 is currently producing middle-range values like 0x42220E54 as
  // stale parser/hash pointers. ReXGlue's generated direct loads can fault on
  // those even when the heap range query says they are readable.
  return address < 0x40000000 || address >= 0x80000000;
}

bool CanReadGuestRange(uint32_t address, uint32_t size) {
  if (!IsUsableGuestDataPointer(address, size)) {
    return false;
  }

  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return false;
  }

  auto* heap = runtime->memory()->LookupHeap(address);
  if (!heap) {
    return false;
  }

  const auto access = heap->QueryRangeAccess(address, address + size);
  return access == rex::memory::PageAccess::kReadOnly ||
         access == rex::memory::PageAccess::kReadWrite ||
         access == rex::memory::PageAccess::kExecuteReadOnly ||
         access == rex::memory::PageAccess::kExecuteReadWrite;
}

bool CanWriteGuestRange(uint32_t address, uint32_t size) {
  if (!IsUsableGuestDataPointer(address, size)) {
    return false;
  }

  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return false;
  }

  auto* heap = runtime->memory()->LookupHeap(address);
  if (!heap) {
    return false;
  }

  const auto access = heap->QueryRangeAccess(address, address + size);
  return access == rex::memory::PageAccess::kReadWrite ||
         access == rex::memory::PageAccess::kExecuteReadWrite;
}

}  // namespace

bool Skate3GuardListClearRange(PPCRegister& r8, PPCRegister& r7) {
  if (r8.u32 > r7.u32) {
    return false;
  }

  const uint32_t first_write = r8.u32 + 4;
  const uint32_t size = r7.u32 - r8.u32 + sizeof(uint32_t);
  if (!CanWriteGuestRange(first_write, size)) {
    REXLOG_WARN("Skipping Skate 3 list clear over non-writable guest range {:08X}-{:08X}",
                first_write, first_write + size);
    return true;
  }

  return false;
}

bool Skate3GuardListOwner(PPCRegister& r4) {
  const uint32_t address = r4.u32;
  if (!CanReadGuestRange(address + 8, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 20, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 32, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 40, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 48, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 72, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 76, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 list owner cleanup for unreadable owner {:08X}", address);
    return true;
  }

  return false;
}

bool Skate3GuardListTableRead(PPCRegister& r11) {
  const uint32_t address = r11.u32 + 8;
  if (!CanReadGuestRange(address, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 list table scan at unreadable word {:08X}", address);
    return true;
  }

  return false;
}

bool Skate3GuardListItemRead(PPCRegister& r8) {
  const uint32_t address = r8.u32;
  if (!CanReadGuestRange(address, 8)) {
    REXLOG_WARN("Skipping Skate 3 list item scan at unreadable range {:08X}-{:08X}",
                address, address + 8);
    return true;
  }

  return false;
}

bool Skate3GuardParserStackCopy(PPCRegister& r3, PPCRegister& r11) {
  const uint32_t destination = r11.u32;
  const uint32_t source = r11.u32 - 0x10;

  const bool source_readable = source >= 0x10000 && CanReadGuestRange(source, 8);
  const bool destination_writable =
      destination >= 0x10000 && CanWriteGuestRange(destination, 8);

  static uint32_t probe_count = 0;
  if (probe_count < 16 || !source_readable || !destination_writable) {
    REXLOG_WARN(
        "Skate 3 parser stack copy probe source {:08X}-{:08X} readable={} destination "
        "{:08X}-{:08X} writable={}",
        source, source + 8, source_readable, destination, destination + 8,
        destination_writable);
    ++probe_count;
  }

  if (!source_readable || !destination_writable) {
    REXLOG_WARN(
        "Returning null for Skate 3 parser stack copy with unreadable source {:08X}-{:08X} "
        "or non-writable destination {:08X}-{:08X}",
        source, source + 8, destination, destination + 8);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardParserInitialRead(PPCRegister& r3, PPCRegister& r11) {
  const uint32_t source = r11.u32 - 0x10;
  const bool source_readable = source >= 0x10000 && CanReadGuestRange(source, 4);
  if (!source_readable) {
    REXLOG_WARN("Returning null for Skate 3 parser initial read from unreadable source {:08X}",
                source);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardHashBucketRead(PPCRegister& r3, PPCRegister& r11, PPCRegister& r9) {
  const uint32_t address = r11.u32 + r9.u32;
  const bool readable = CanReadGuestRange(address, sizeof(uint32_t));

  static uint32_t probe_count = 0;
  if (probe_count < 16 || !readable) {
    REXLOG_WARN("Skate 3 hash bucket probe address {:08X} readable={}", address, readable);
    ++probe_count;
  }

  if (!readable) {
    REXLOG_WARN("Returning null for unreadable Skate 3 hash bucket {:08X}", address);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardStringByteRead(PPCRegister& r10, PPCRegister& r11, PPCRegister& r4) {
  const uint32_t address = r11.u32;
  if (!CanReadGuestRange(address, sizeof(uint8_t))) {
    REXLOG_WARN("Returning empty string for unreadable Skate 3 string byte {:08X}", address);
    r10.u64 = 0;
    r11.u64 = r4.u32 + 1;
    return true;
  }

  return false;
}

bool Skate3GuardStringFlagUpdate(PPCRegister& r10) {
  const uint32_t address = r10.u32;
  if (!CanReadGuestRange(address, sizeof(uint8_t)) ||
      !CanWriteGuestRange(address, sizeof(uint8_t))) {
    REXLOG_WARN("Skipping Skate 3 string flag update at unreadable/non-writable byte {:08X}",
                address);
    return true;
  }

  return false;
}

void Skate3TreeCleanupNoop() {}

bool Skate3GuardTreeFlagClear(PPCRegister& r11) {
  const uint32_t address = r11.u32 + 5;
  if (!CanReadGuestRange(address, sizeof(uint8_t)) ||
      !CanWriteGuestRange(address, sizeof(uint8_t))) {
    REXLOG_WARN("Skipping Skate 3 tree flag clear at unreadable/non-writable byte {:08X}",
                address);
    return true;
  }

  return false;
}

bool Skate3GuardTreeLoopTable(PPCRegister& r3) {
  if (!CanReadGuestRange(r3.u32 + 12, sizeof(uint32_t)) ||
      !CanReadGuestRange(r3.u32 + 28, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 tree table loop for unreadable root {:08X}", r3.u32);
    return true;
  }

  return false;
}

bool Skate3GuardTreeChildFlagRead(PPCRegister& r8) {
  const uint32_t address = r8.u32 + 5;
  if (!CanReadGuestRange(address, sizeof(uint8_t))) {
    REXLOG_WARN("Skipping Skate 3 tree child flag read from unreadable byte {:08X}",
                address);
    return true;
  }

  return false;
}

bool Skate3GuardTreeOwnerCounter(PPCRegister& r11) {
  const uint32_t address = r11.u32 + 4;
  if (!CanReadGuestRange(address, sizeof(uint32_t)) ||
      !CanWriteGuestRange(address, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 tree owner counter decrement at unreadable/non-writable word {:08X}",
        address);
    return true;
  }

  return false;
}

bool Skate3GuardLinkedListHead(PPCRegister& r3, PPCRegister& r4) {
  const uint32_t owner = r3.u32;
  const uint32_t head_slot = r4.u32;
  if (!CanReadGuestRange(owner + 16, sizeof(uint32_t)) ||
      !CanReadGuestRange(head_slot, sizeof(uint32_t)) ||
      !CanWriteGuestRange(head_slot, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 linked-list cleanup for unreadable owner {:08X} or head slot {:08X}",
        owner, head_slot);
    r3.u64 = r4.u64;
    return true;
  }

  return false;
}

bool Skate3GuardLinkedListNode(PPCRegister& r31) {
  const uint32_t node = r31.u32;
  if (node == 0) {
    return false;
  }

  if (!CanReadGuestRange(node, sizeof(uint32_t)) ||
      !CanReadGuestRange(node + 4, sizeof(uint8_t)) ||
      !CanReadGuestRange(node + 5, sizeof(uint8_t)) ||
      !CanWriteGuestRange(node + 5, sizeof(uint8_t))) {
    REXLOG_WARN("Stopping Skate 3 linked-list cleanup at unreadable node {:08X}", node);
    return true;
  }

  return false;
}

bool Skate3GuardLinkedListUnlink(PPCRegister& r30, PPCRegister& r31) {
  const uint32_t previous_link = r30.u32;
  const uint32_t node = r31.u32;
  if (!CanWriteGuestRange(previous_link, sizeof(uint32_t)) ||
      !CanReadGuestRange(node, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Stopping Skate 3 linked-list unlink for previous link {:08X} and node {:08X}",
        previous_link, node);
    return true;
  }

  return false;
}

bool Skate3GuardLinkedListNext(PPCRegister& r30) {
  const uint32_t previous_link = r30.u32;
  if (!CanReadGuestRange(previous_link, sizeof(uint32_t))) {
    REXLOG_WARN("Stopping Skate 3 linked-list cleanup before unreadable next link {:08X}",
                previous_link);
    return true;
  }

  return false;
}

bool Skate3GuardValueStackPush(PPCRegister& r31, PPCRegister& r11) {
  const uint32_t owner = r31.u32;
  const uint32_t cursor = r11.u32;
  if (!CanReadGuestRange(owner + 8, sizeof(uint32_t)) ||
      !CanWriteGuestRange(owner + 8, sizeof(uint32_t)) ||
      !CanWriteGuestRange(cursor, 8)) {
    REXLOG_WARN(
        "Skipping Skate 3 value-stack push for owner {:08X} at non-writable cursor {:08X}",
        owner, cursor);
    return true;
  }

  return false;
}

bool Skate3GuardStartupValueSlot(PPCRegister& r31, PPCRegister& r11) {
  const uint32_t owner = r31.u32;
  const uint32_t cursor = r11.u32;
  if (!CanReadGuestRange(owner + 8, sizeof(uint32_t)) ||
      !CanWriteGuestRange(owner + 8, sizeof(uint32_t)) ||
      !CanWriteGuestRange(cursor, 8)) {
    REXLOG_WARN(
        "Skipping Skate 3 startup value slot for owner {:08X} at non-writable cursor {:08X}",
        owner, cursor);
    return true;
  }

  return false;
}

bool Skate3GuardValueTableRead(PPCRegister& r3, PPCRegister& r10, PPCRegister& r9) {
  const uint32_t address = r10.u32 + r9.u32;
  if (!CanReadGuestRange(address, sizeof(uint32_t))) {
    REXLOG_WARN("Returning null for Skate 3 value table read at unreadable slot {:08X}",
                address);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardValueObjectRead(PPCRegister& r3, PPCRegister& r11) {
  const uint32_t address = r11.u32 + 8;
  if (!CanReadGuestRange(address, sizeof(uint32_t))) {
    REXLOG_WARN("Returning null for Skate 3 value object read at unreadable slot {:08X}",
                address);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardValueListHeader(PPCRegister& r4, PPCRegister& r29) {
  const uint32_t header = r4.u32;
  if (!CanReadGuestRange(header, 12)) {
    REXLOG_WARN("Falling back for Skate 3 value list with unreadable header {:08X}", header);
    r29.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardDrawCommandContext(PPCRegister& r6) {
  const uint32_t address = r6.u32;
  if (!CanReadGuestRange(address + 0x30, sizeof(uint32_t)) ||
      !CanReadGuestRange(address + 0xCC, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 draw command with unreadable context {:08X}", address);
    return true;
  }

  return false;
}

bool Skate3GuardDrawCommandWrite(PPCRegister& r11) {
  const uint32_t address = r11.u32;
  if (!CanWriteGuestRange(address, 0x10)) {
    REXLOG_WARN("Skipping Skate 3 draw command write to non-writable guest range {:08X}-{:08X}",
                address, address + 0x10);
    return true;
  }

  return false;
}
