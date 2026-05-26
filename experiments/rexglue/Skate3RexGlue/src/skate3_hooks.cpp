#include "generated/default/skate3rexglue_init.h"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#include <rex/memory.h>
#include <rex/runtime.h>

namespace {

bool IsUsableGuestDataPointer(uint32_t address, uint32_t size) {
  return address + size >= address;
}

const uint8_t* GeneratedHostAddress(uint32_t address) {
  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return nullptr;
  }

  const uint32_t heap_offset = address >= 0xE0000000 ? 0x1000 : 0;
  return runtime->memory()->virtual_membase() + address + heap_offset;
}

bool CanAccessHostRange(const uint8_t* begin, uint32_t size, bool write) {
  if (!begin) {
    return false;
  }

  const auto* end = begin + size;
  const auto* cursor = begin;

  while (cursor < end) {
    MEMORY_BASIC_INFORMATION info{};
    if (!VirtualQuery(cursor, &info, sizeof(info))) {
      return false;
    }

    if (info.State != MEM_COMMIT ||
        (info.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0) {
      return false;
    }

    if (write) {
      const DWORD writable = PAGE_READWRITE | PAGE_WRITECOPY |
                             PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;
      if ((info.Protect & writable) == 0) {
        return false;
      }
    }

    const auto* region_end =
        static_cast<const uint8_t*>(info.BaseAddress) + info.RegionSize;
    if (region_end <= cursor) {
      return false;
    }
    cursor = region_end < end ? region_end : end;
  }

  return true;
}

bool CanAccessTranslatedRange(uint32_t address, uint32_t size, bool write) {
  if (size == 0) {
    return true;
  }

  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return false;
  }

#ifdef _WIN32
  const auto* begin = runtime->memory()->TranslateVirtual<const uint8_t*>(address);
  if (!CanAccessHostRange(begin, size, write)) {
    return false;
  }

  const auto* generated_begin = GeneratedHostAddress(address);
  if (generated_begin != begin &&
      !CanAccessHostRange(generated_begin, size, write)) {
    return false;
  }
#endif

  return true;
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
  const bool readable = access == rex::memory::PageAccess::kReadOnly ||
                        access == rex::memory::PageAccess::kReadWrite ||
                        access == rex::memory::PageAccess::kExecuteReadOnly ||
                        access == rex::memory::PageAccess::kExecuteReadWrite;
  return readable && CanAccessTranslatedRange(address, size, false);
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
  const bool writable = access == rex::memory::PageAccess::kReadWrite ||
                        access == rex::memory::PageAccess::kExecuteReadWrite;
  return writable && CanAccessTranslatedRange(address, size, true);
}

bool ReadGuestU32(uint32_t address, uint32_t& value) {
  if (!CanReadGuestRange(address, sizeof(uint32_t))) {
    return false;
  }

  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return false;
  }

  value = __builtin_bswap32(*runtime->memory()->TranslateVirtual<const uint32_t*>(address));
  return true;
}

bool ReadGuestU8(uint32_t address, uint8_t& value) {
  if (!CanReadGuestRange(address, sizeof(uint8_t))) {
    return false;
  }

  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return false;
  }

  value = *runtime->memory()->TranslateVirtual<const uint8_t*>(address);
  return true;
}

bool ReadGuestU64(uint32_t address, uint64_t& value) {
  if (!CanReadGuestRange(address, sizeof(uint64_t))) {
    return false;
  }

  auto* runtime = rex::Runtime::instance();
  if (!runtime || !runtime->memory()) {
    return false;
  }

  value = __builtin_bswap64(*runtime->memory()->TranslateVirtual<const uint64_t*>(address));
  return true;
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

bool Skate3GuardHashTableHeader(PPCRegister& r3) {
  uint32_t table = 0;
  if (!ReadGuestU32(r3.u32 + 16, table) ||
      !CanReadGuestRange(table, sizeof(uint32_t)) ||
      !CanReadGuestRange(table + 8, sizeof(uint32_t))) {
    REXLOG_WARN("Returning null for Skate 3 hash table with unreadable owner {:08X}",
                r3.u32);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardHashNodeRead(PPCRegister& r3, PPCRegister& r7) {
  const uint32_t node = r7.u32;
  if (!CanReadGuestRange(node, 20)) {
    REXLOG_WARN("Returning null for unreadable Skate 3 hash node {:08X}", node);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardHashStringCompare(PPCRegister& r9, PPCRegister& r11, PPCRegister& r10) {
  const uint32_t left = r11.u32;
  const uint32_t right = r10.u32;
  if (!CanReadGuestRange(left, sizeof(uint8_t)) ||
      !CanReadGuestRange(right, sizeof(uint8_t))) {
    REXLOG_WARN(
        "Treating Skate 3 hash string compare as mismatch for unreadable bytes {:08X} / "
        "{:08X}",
        left, right);
    r9.u64 = 1;
    return true;
  }

  return false;
}

bool Skate3GuardHashMatchNodeFlags(PPCRegister& r3, PPCRegister& r7) {
  const uint32_t node_flags = r7.u32 + 5;
  if (!CanReadGuestRange(node_flags, sizeof(uint8_t)) ||
      !CanWriteGuestRange(node_flags, sizeof(uint8_t)) ||
      !CanReadGuestRange(r3.u32 + 16, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Returning null for Skate 3 hash match with unreadable node flags {:08X} "
        "or table owner {:08X}",
        node_flags, r3.u32);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardHashMatchTableFlags(PPCRegister& r3, PPCRegister& r10) {
  const uint32_t table_flags = r10.u32 + 20;
  if (!CanReadGuestRange(table_flags, sizeof(uint8_t))) {
    REXLOG_WARN("Returning null for Skate 3 hash match with unreadable table flags {:08X}",
                table_flags);
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

bool Skate3GuardValueWriterCursor(PPCRegister& r31) {
  const uint32_t cursor_slot = r31.u32 + 8;
  if (!CanReadGuestRange(cursor_slot, sizeof(uint32_t)) ||
      !CanWriteGuestRange(cursor_slot, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 value writer cursor update at unreadable slot {:08X}",
                cursor_slot);
    return true;
  }

  return false;
}

bool Skate3GuardValueWriterOutput(PPCRegister& r30) {
  if (!CanWriteGuestRange(r30.u32, 8)) {
    REXLOG_WARN("Skipping Skate 3 value writer output at unwritable cursor {:08X}",
                r30.u32);
    return true;
  }

  return false;
}

bool Skate3GuardValueStringScan(PPCRegister& r4, PPCRegister& r11) {
  const uint32_t string_start = r4.u32;
  const uint32_t cursor = r11.u32;
  if (!CanReadGuestRange(cursor, sizeof(uint8_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 value-string write for unreadable byte {:08X} from string {:08X}",
        cursor, string_start);
    return true;
  }

  return false;
}

bool Skate3SkipStartupBugCheck() {
  REXLOG_WARN("Skipping Skate 3 startup KeBugCheck while runtime services are incomplete");
  return true;
}

extern "C" REX_FUNC(__imp__KeBugCheck) {
  (void)base;
  REXLOG_WARN("Ignoring Skate 3 KeBugCheck({:#x}) during runtime bring-up", ctx.r3.u32);
}

extern "C" REX_FUNC(__imp__KeBugCheckEx) {
  (void)base;
  REXLOG_WARN(
      "Ignoring Skate 3 KeBugCheckEx({:#x}, {:#x}, {:#x}, {:#x}, {:#x}) during runtime "
      "bring-up",
      ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32);
}

bool Skate3GuardValueStackRoot(PPCRegister& r25) {
  const uint32_t stack_root_slot = r25.u32 + 12;
  if (!CanReadGuestRange(stack_root_slot, sizeof(uint32_t))) {
    REXLOG_WARN("Stopping Skate 3 value-stack collapse for unreadable root slot {:08X}",
                stack_root_slot);
    return true;
  }

  return false;
}

bool Skate3GuardValueStackSlice(PPCRegister& r24) {
  if (r24.u32 < 16 || !CanReadGuestRange(r24.u32 - 16, 16)) {
    REXLOG_WARN("Stopping Skate 3 value-stack collapse for unreadable slice ending {:08X}",
                r24.u32);
    return true;
  }

  return false;
}

bool Skate3GuardValueFormatResult(PPCRegister& r3, PPCRegister& r31,
                                  PPCRegister& r6) {
  const uint32_t cursor_slot = r31.u32 + 8;
  const uint32_t value_slot = r6.u32 - 8;
  if (r6.u32 < 8 ||
      !CanReadGuestRange(cursor_slot, sizeof(uint32_t)) ||
      !CanWriteGuestRange(cursor_slot, sizeof(uint32_t)) ||
      !CanReadGuestRange(value_slot, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Returning null for Skate 3 formatted value with cursor slot {:08X} and value slot {:08X}",
        cursor_slot, value_slot);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardValueObjectSwap(PPCRegister& r30, PPCRegister& r31) {
  uint32_t cursor = 0;
  const uint32_t cursor_slot = r31.u32 + 8;
  if (!CanReadGuestRange(r30.u32, 8) ||
      !ReadGuestU32(cursor_slot, cursor) ||
      !CanWriteGuestRange(cursor_slot, sizeof(uint32_t)) ||
      cursor < 8 ||
      !CanReadGuestRange(cursor - 8, 8) ||
      !CanWriteGuestRange(cursor - 8, 16)) {
    REXLOG_WARN(
        "Skipping Skate 3 value-object swap with source {:08X} and cursor {:08X}",
        r30.u32, cursor);
    return true;
  }

  return false;
}

bool Skate3GuardValueOwnerFormat(PPCRegister& r31) {
  uint32_t owner = 0;
  uint32_t table = 0;
  uint32_t table_type = 0;
  const uint32_t owner_slot = r31.u32 + 20;
  if (!ReadGuestU32(owner_slot, owner) ||
      !ReadGuestU32(owner + 4, table) ||
      !ReadGuestU32(table + 4, table_type)) {
    REXLOG_WARN(
        "Skipping Skate 3 value owner formatter with invalid owner chain owner {:08X}, slot {:08X}, table {:08X}",
        r31.u32, owner, table);
    return true;
  }

  if (table_type == 6) {
    uint32_t nested = 0;
    if (!ReadGuestU32(table, nested) ||
        !CanReadGuestRange(nested + 6, sizeof(uint8_t)) ||
        !CanReadGuestRange(nested + 16, sizeof(uint32_t))) {
      REXLOG_WARN(
          "Skipping Skate 3 nested value owner formatter with invalid table {:08X}, nested {:08X}",
          table, nested);
      return true;
    }
  }

  if (!CanReadGuestRange(owner, 8) || !CanReadGuestRange(table, 8)) {
    REXLOG_WARN(
        "Skipping Skate 3 value owner formatter with unreadable owner/table owner {:08X}, table {:08X}",
        owner, table);
    return true;
  }

  return false;
}

bool Skate3GuardValueNestedFormatter(PPCRegister& r11) {
  const uint32_t formatter_slot = r11.u32 + 32;
  if (r11.u32 < 0x10000000 || !CanReadGuestRange(formatter_slot, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 nested value formatter at unreadable slot {:08X}",
                formatter_slot);
    return true;
  }

  return false;
}

bool Skate3GuardFramePumpCallback(PPCRegister& r3) {
  uint32_t vtable = 0;
  uint32_t callback = 0;
  if (!ReadGuestU32(r3.u32, vtable) ||
      !ReadGuestU32(vtable + 28, callback) ||
      callback == 0) {
    static uint32_t log_count = 0;
    if (log_count < 16) {
      REXLOG_WARN(
          "Skipping Skate 3 frame pump callback with invalid object {:08X}, vtable {:08X}, callback {:08X}",
          r3.u32, vtable, callback);
      ++log_count;
    }
    return true;
  }

  return false;
}

bool Skate3GuardValueStringArgument(PPCRegister& r11) {
  constexpr uint32_t kMaxBringupStringLength = 4096;

  uint8_t byte = 0;
  for (uint32_t offset = 0; offset < kMaxBringupStringLength; ++offset) {
    const uint32_t address = r11.u32 + offset;
    if (!ReadGuestU8(address, byte)) {
      REXLOG_WARN("Skipping Skate 3 value string with unreadable byte {:08X}",
                  address);
      return true;
    }
    if (byte == 0) {
      return false;
    }
  }

  REXLOG_WARN("Skipping Skate 3 value string without terminator near {:08X}",
              r11.u32);
  return true;
}

bool Skate3GuardFrontendSetupWriter(PPCRegister& r31) {
  uint32_t writer = 0;
  const uint32_t writer_slot = r31.u32 + 8276;
  if (!ReadGuestU32(writer_slot, writer) ||
      !CanReadGuestRange(writer + 8, sizeof(uint32_t)) ||
      !CanWriteGuestRange(writer + 8, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 frontend setup writer with owner {:08X} and writer {:08X}",
        r31.u32, writer);
    return true;
  }

  return false;
}

bool Skate3GuardFrontendOwnerState(PPCRegister& r31) {
  const uint32_t cache_slot = r31.u32 + 8284;
  const uint32_t cursor_slot = r31.u32 + 8288;
  const uint32_t count_slot = r31.u32 + 8292;
  const uint32_t limit_slot = r31.u32 + 8296;
  const uint32_t asset_slot = r31.u32 + 8732;
  if (!CanWriteGuestRange(cache_slot, sizeof(uint32_t)) ||
      !CanWriteGuestRange(cursor_slot, sizeof(uint32_t)) ||
      !CanReadGuestRange(count_slot, sizeof(uint32_t)) ||
      !CanReadGuestRange(limit_slot, sizeof(uint32_t)) ||
      !CanReadGuestRange(asset_slot, sizeof(uint32_t))) {
    REXLOG_WARN("Skipping Skate 3 frontend owner setup with invalid owner {:08X}",
                r31.u32);
    return true;
  }

  return false;
}

bool Skate3GuardCareerWidgetLink(PPCRegister& r1, PPCRegister& r12,
                                  PPCRegister& r14, PPCRegister& r15,
                                  PPCRegister& r16, PPCRegister& r17,
                                  PPCRegister& r18, PPCRegister& r19,
                                  PPCRegister& r20, PPCRegister& r21,
                                  PPCRegister& r22, PPCRegister& r23,
                                  PPCRegister& r24, PPCRegister& r25,
                                  PPCRegister& r26, PPCRegister& r27,
                                  PPCRegister& r28, PPCRegister& r29,
                                  PPCRegister& r30, PPCRegister& r31) {
  uint32_t link = 0;
  const uint32_t widget_slot = r31.u32 + 408;
  const uint32_t companion_slot = r31.u32 + 412;
  const uint32_t link_slot = r31.u32 + 456;
  if (CanWriteGuestRange(widget_slot, sizeof(uint32_t)) &&
      CanWriteGuestRange(companion_slot, sizeof(uint32_t)) &&
      ReadGuestU32(link_slot, link) &&
      CanWriteGuestRange(link + 8, sizeof(uint32_t))) {
    return false;
  }

  REXLOG_WARN(
      "Skipping Skate 3 career widget link with owner {:08X} and link {:08X}",
      r31.u32, link);

  const uint32_t caller_stack = r1.u32 + 400;
  auto restore_gpr = [&](PPCRegister& reg, uint32_t offset) {
    uint64_t saved = 0;
    if (ReadGuestU64(caller_stack + offset, saved)) {
      reg.u64 = saved;
    }
  };

  restore_gpr(r14, static_cast<uint32_t>(-152));
  restore_gpr(r15, static_cast<uint32_t>(-144));
  restore_gpr(r16, static_cast<uint32_t>(-136));
  restore_gpr(r17, static_cast<uint32_t>(-128));
  restore_gpr(r18, static_cast<uint32_t>(-120));
  restore_gpr(r19, static_cast<uint32_t>(-112));
  restore_gpr(r20, static_cast<uint32_t>(-104));
  restore_gpr(r21, static_cast<uint32_t>(-96));
  restore_gpr(r22, static_cast<uint32_t>(-88));
  restore_gpr(r23, static_cast<uint32_t>(-80));
  restore_gpr(r24, static_cast<uint32_t>(-72));
  restore_gpr(r25, static_cast<uint32_t>(-64));
  restore_gpr(r26, static_cast<uint32_t>(-56));
  restore_gpr(r27, static_cast<uint32_t>(-48));
  restore_gpr(r28, static_cast<uint32_t>(-40));
  restore_gpr(r29, static_cast<uint32_t>(-32));
  restore_gpr(r30, static_cast<uint32_t>(-24));
  restore_gpr(r31, static_cast<uint32_t>(-16));

  uint32_t saved_lr = 0;
  if (ReadGuestU32(caller_stack - 8, saved_lr)) {
    r12.u64 = saved_lr;
  }
  r1.u32 = caller_stack;

  return true;
}

bool Skate3GuardWidgetAttach(PPCRegister& r29, PPCRegister& r30) {
  const uint32_t active_flag = r29.u32 + 0x12793;
  if (!CanWriteGuestRange(r30.u32 + 4, sizeof(uint32_t)) ||
      !CanReadGuestRange(r30.u32, sizeof(uint32_t)) ||
      !CanReadGuestRange(active_flag, sizeof(uint8_t))) {
    REXLOG_WARN("Skipping Skate 3 widget attach with owner {:08X} and widget {:08X}",
                r29.u32, r30.u32);
    return true;
  }

  return false;
}

bool Skate3GuardWidgetAttachGrow(PPCRegister& r29, PPCRegister& r30) {
  REXLOG_WARN(
      "Skipping Skate 3 widget attach vector grow for owner {:08X} and widget {:08X}",
      r29.u32, r30.u32);
  return true;
}

bool Skate3GuardFrontendCleanupNode(PPCRegister& r29, PPCRegister& r30,
                                    PPCRegister& r31) {
  if (!CanReadGuestRange(r29.u32 + 8732, sizeof(uint32_t)) ||
      !CanReadGuestRange(r31.u32, sizeof(uint32_t)) ||
      !CanReadGuestRange(r31.u32 + 8, sizeof(uint32_t)) ||
      !CanWriteGuestRange(r30.u32, 12)) {
    REXLOG_WARN(
        "Skipping Skate 3 frontend cleanup list with owner {:08X}, head {:08X}, node {:08X}",
        r29.u32, r30.u32, r31.u32);
    return true;
  }

  return false;
}

bool Skate3GuardFrontendClearNode(PPCRegister& r30, PPCRegister& r31) {
  if (!CanReadGuestRange(r31.u32, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 frontend clear list node with head {:08X}, node {:08X}",
        r30.u32, r31.u32);
    return true;
  }

  return false;
}

bool Skate3GuardVectorInsertWordSlot(PPCRegister& r29, PPCRegister& r30,
                                     PPCRegister& r31) {
  const bool source_readable = CanReadGuestRange(r29.u32, sizeof(uint32_t));
  const bool slot_writable = CanWriteGuestRange(r30.u32, sizeof(uint32_t));
  const bool cursor_writable = CanWriteGuestRange(r31.u32 + 4, sizeof(uint32_t));

  static uint32_t probe_count = 0;
  if (probe_count < 16 || !source_readable || !slot_writable ||
      !cursor_writable) {
    REXLOG_WARN(
        "Skate 3 word-vector probe source {:08X} readable={} slot {:08X} writable={} vector {:08X} cursor_writable={}",
        r29.u32, source_readable, r30.u32, slot_writable, r31.u32,
        cursor_writable);
    ++probe_count;
  }

  if (!source_readable || !slot_writable || !cursor_writable) {
    REXLOG_WARN(
        "Skipping Skate 3 word-vector insert with source {:08X}, slot {:08X}, vector {:08X}",
        r29.u32, r30.u32, r31.u32);
    return true;
  }

  return false;
}

bool Skate3GuardVectorGrowWordSlot(PPCRegister& r29, PPCRegister& r11) {
  if (!CanReadGuestRange(r29.u32, sizeof(uint32_t)) ||
      !CanWriteGuestRange(r11.u32, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 word-vector grow insert with source {:08X}, slot {:08X}",
        r29.u32, r11.u32);
    return true;
  }

  return false;
}

bool Skate3GuardFrontendQueuePush(PPCRegister& r3, PPCRegister& r11) {
  if (!CanWriteGuestRange(r3.u32 + 4, sizeof(uint32_t)) ||
      !CanWriteGuestRange(r11.u32, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 frontend queue push with vector {:08X}, slot {:08X}",
        r3.u32, r11.u32);
    return true;
  }

  return false;
}

bool Skate3GuardSearchStringByte(PPCRegister& r3, PPCRegister& r6) {
  const uint32_t address = r3.u32;
  if (!CanReadGuestRange(address, sizeof(uint8_t))) {
    REXLOG_WARN("Returning null for Skate 3 string scan at unreadable byte {:08X}",
                address);
    r3.u64 = 0;
    r6.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardSearchStringNextByte(PPCRegister& r3, PPCRegister& r6) {
  const uint32_t address = r3.u32 + 1;
  if (!CanReadGuestRange(address, sizeof(uint8_t))) {
    REXLOG_WARN("Returning null for Skate 3 string scan next byte {:08X}", address);
    r3.u64 = 0;
    r6.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardFileHeaderProbe(PPCRegister& r3) {
  const uint32_t address = r3.u32;
  if (!CanReadGuestRange(address, sizeof(uint32_t))) {
    REXLOG_WARN("Returning unknown Skate 3 file/header type for unreadable probe {:08X}",
                address);
    r3.u64 = 5;
    return true;
  }

  return false;
}

bool Skate3GuardResourceTableRoot(PPCRegister& r3) {
  const uint32_t header_slot = r3.u32 + 16;
  if (!CanReadGuestRange(header_slot, sizeof(uint32_t))) {
    REXLOG_WARN("Returning empty Skate 3 resource table for unreadable header slot {:08X}",
                header_slot);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardStreamNodeInit(PPCRegister& r3, PPCRegister& r4) {
  const uint32_t node = r3.u32;
  const uint32_t stream = r4.u32;

  uint32_t parent = 0;
  if (!CanWriteGuestRange(node, 32) ||
      !CanReadGuestRange(stream + 20, sizeof(uint32_t)) ||
      !CanReadGuestRange(stream + 24, sizeof(uint32_t)) ||
      !CanWriteGuestRange(stream + 24, sizeof(uint32_t)) ||
      !CanReadGuestRange(stream + 32, sizeof(uint32_t)) ||
      !ReadGuestU32(node, parent) ||
      !CanReadGuestRange(parent + 4, 24)) {
    REXLOG_WARN(
        "Skipping Skate 3 stream node init for node {:08X}, stream {:08X}, parent {:08X}",
        node, stream, parent);
    return true;
  }

  return false;
}

bool Skate3GuardAllocatedStreamChunk(PPCRegister& r30) {
  const uint32_t chunk = r30.u32;
  if (!CanReadGuestRange(chunk, 12)) {
    REXLOG_WARN("Skipping Skate 3 stream chunk processing for unreadable chunk {:08X}",
                chunk);
    return true;
  }

  return false;
}

bool Skate3GuardAllocatedStreamChunkReturn(PPCRegister& r30, PPCRegister& r3,
                                           PPCRegister& r29) {
  const uint32_t chunk = r30.u32;
  if (!CanReadGuestRange(chunk, 12)) {
    REXLOG_WARN(
        "Returning Skate 3 resource object early for unreadable stream chunk {:08X}",
        chunk);
    r3.u64 = r29.u64;
    return true;
  }

  return false;
}

bool Skate3GuardMemcpyRange(PPCRegister& r3, PPCRegister& r4, PPCRegister& r5) {
  const uint32_t destination = r3.u32;
  const uint32_t source = r4.u32;
  const uint32_t size = r5.u32;

  if (size == 0) {
    return false;
  }

  const bool source_readable = CanReadGuestRange(source, size);
  const bool destination_writable = CanWriteGuestRange(destination, size);

  static uint32_t probe_count = 0;
  if (probe_count < 24 || !source_readable || !destination_writable) {
    REXLOG_WARN(
        "Skate 3 memory copy probe src {:08X}, dst {:08X}, size {}, readable={}, writable={}",
        source, destination, size, source_readable, destination_writable);
    ++probe_count;
  }

  if (!source_readable || !destination_writable) {
    REXLOG_WARN(
        "Skipping Skate 3 memory copy with invalid guest range src {:08X}, dst {:08X}, size {}",
        source, destination, size);
    return true;
  }

  return false;
}

bool Skate3GuardPatchLinkStore(PPCRegister& r31) {
  const uint32_t patch_header = r31.u32;
  const uint32_t link_slot = patch_header + 8;

  if (!CanWriteGuestRange(link_slot, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 active patch link store for non-writable header {:08X}",
        patch_header);
    return true;
  }

  return false;
}

bool Skate3GuardPatchTableDescriptor(PPCRegister& r29) {
  const uint32_t descriptor = r29.u32;
  const uint32_t table_header = descriptor + 872;

  uint32_t table_offset = 0;
  if (!CanReadGuestRange(table_header + 20, sizeof(uint32_t)) ||
      !ReadGuestU32(table_header + 20, table_offset)) {
    REXLOG_WARN(
        "Skipping Skate 3 patch table with unreadable descriptor {:08X}",
        descriptor);
    return true;
  }

  if (table_offset == 0) {
    return false;
  }

  const uint32_t table = table_header + table_offset;
  uint32_t table_size = 0;
  if (!CanReadGuestRange(table, 20) ||
      !ReadGuestU32(table + 16, table_size) ||
      !CanReadGuestRange(table + 20, table_size)) {
    REXLOG_WARN(
        "Skipping Skate 3 patch table with invalid records descriptor {:08X}, table {:08X}, size {}",
        descriptor, table, table_size);
    return true;
  }

  return false;
}

bool Skate3GuardActivePatchHeaders(PPCRegister& r25, PPCRegister& r27) {
  const uint32_t current_header = r25.u32;
  const uint32_t previous_header = r27.u32;

  if (!CanReadGuestRange(current_header + 20, sizeof(uint32_t)) ||
      !CanReadGuestRange(previous_header + 20, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 resource update with invalid patch headers current {:08X}, previous {:08X}",
        current_header, previous_header);
    return true;
  }

  return false;
}

bool Skate3GuardResourceUpdateRoot(PPCRegister& r30) {
  const uint32_t resource = r30.u32;
  if (!CanReadGuestRange(resource + 904, sizeof(uint32_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 resource update with unreadable active resource {:08X}",
        resource);
    return true;
  }

  return false;
}

bool Skate3GuardContainerOwnerList(PPCRegister& r3) {
  const uint32_t owner = r3.u32;
  uint32_t list = 0;

  if (!CanReadGuestRange(owner + 8, sizeof(uint32_t)) ||
      !ReadGuestU32(owner + 8, list) ||
      !CanReadGuestRange(list + 38, sizeof(uint16_t))) {
    REXLOG_WARN(
        "Skipping Skate 3 container owner list with unreadable owner {:08X}",
        owner);
    return true;
  }

  return false;
}

bool Skate3GuardContainerListHeader(PPCRegister& r3, PPCRegister& r31) {
  if (!CanReadGuestRange(r31.u32, sizeof(uint32_t)) ||
      !CanReadGuestRange(r31.u32 + 4, sizeof(uint16_t))) {
    REXLOG_WARN("Returning null for Skate 3 container list with unreadable header {:08X}",
                r31.u32);
    r3.u64 = 0;
    return true;
  }

  return false;
}

bool Skate3GuardContainerOwner(PPCRegister& r3) {
  const uint32_t owner_slot = r3.u32 + 4;
  if (!CanReadGuestRange(owner_slot, sizeof(uint32_t))) {
    REXLOG_WARN("Returning null for Skate 3 container with unreadable owner slot {:08X}",
                owner_slot);
    r3.u64 = 0;
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
