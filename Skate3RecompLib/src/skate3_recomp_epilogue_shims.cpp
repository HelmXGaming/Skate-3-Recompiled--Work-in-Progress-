#include "ppc_recomp_shared.h"

namespace {

void RestoreSharedEpilogue(PPCContext& ctx, uint8_t* base, int first_register)
{
    if (first_register <= 15) ctx.r15.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
    if (first_register <= 16) ctx.r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
    if (first_register <= 17) ctx.r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
    if (first_register <= 18) ctx.r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
    if (first_register <= 19) ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
    if (first_register <= 20) ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
    if (first_register <= 21) ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
    if (first_register <= 22) ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
    if (first_register <= 23) ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
    if (first_register <= 24) ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
    if (first_register <= 25) ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
    if (first_register <= 26) ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
    if (first_register <= 27) ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
    if (first_register <= 28) ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
    if (first_register <= 29) ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
    if (first_register <= 30) ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
    if (first_register <= 31) ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);

    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
    ctx.lr = ctx.r12.u64;
}

} // namespace

void sub_82F274E4(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 15); }
void sub_82F274E8(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 16); }
void sub_82F274EC(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 17); }
void sub_82F274F0(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 18); }
void sub_82F274F4(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 19); }
void sub_82F274F8(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 20); }
void sub_82F274FC(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 21); }
void sub_82F27500(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 22); }
void sub_82F27504(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 23); }
void sub_82F27508(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 24); }
void sub_82F2750C(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 25); }
void sub_82F27510(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 26); }
void sub_82F27514(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 27); }
void sub_82F27518(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 28); }
void sub_82F2751C(PPCContext& ctx, uint8_t* base) { RestoreSharedEpilogue(ctx, base, 29); }
