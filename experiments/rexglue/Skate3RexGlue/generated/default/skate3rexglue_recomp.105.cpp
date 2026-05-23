#include "skate3rexglue_init.h"

DEFINE_REX_FUNC(sub_82F66CA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31710
	ctx.r11.s64 = -2078146560;
	// lis r9,-13326
	ctx.r9.s64 = -873332736;
	// ori r10,r11,8997
	ctx.r10.u64 = ctx.r11.u64 | 8997;
	// ori r8,r9,40164
	ctx.r8.u64 = ctx.r9.u64 | 40164;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// rldimi r10,r8,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// li r7,435
	ctx.r7.s64 = 435;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r9,r11,18600
	ctx.r9.s64 = ctx.r11.s64 + 18600;
	// li r11,73
	ctx.r11.s64 = 73;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
loc_82F66CCC:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// mulld r5,r10,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r10.u64 * ctx.r7.u64);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// xor r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f66ccc
	if (!ctx.cr6.eq) goto loc_82F66CCC;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// std r10,-7648(r11)
	REX_STORE_U64(ctx.r11.u32 + -7648, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F66CF8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,18620
	ctx.r4.s64 = ctx.r11.s64 + 18620;
	// addi r3,r10,-7632
	ctx.r3.s64 = ctx.r10.s64 + -7632;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F66D10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,18636
	ctx.r4.s64 = ctx.r11.s64 + 18636;
	// addi r3,r10,-7656
	ctx.r3.s64 = ctx.r10.s64 + -7656;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F66D28) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// ld r11,-7656(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + -7656);
	// std r11,-7640(r10)
	REX_STORE_U64(ctx.r10.u32 + -7640, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F66D40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r10,-7624
	ctx.r9.s64 = ctx.r10.s64 + -7624;
	// ld r11,-7656(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + -7656);
	// std r11,-7624(r10)
	REX_STORE_U64(ctx.r10.u32 + -7624, ctx.r11.u64);
	// std r11,8(r9)
	REX_STORE_U64(ctx.r9.u32 + 8, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F66D60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,18576
	ctx.r9.s64 = ctx.r11.s64 + 18576;
	// addi r8,r10,-7584
	ctx.r8.s64 = ctx.r10.s64 + -7584;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F66D80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,-7568
	ctx.r7.s64 = ctx.r8.s64 + -7568;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F66DA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,-7600
	ctx.r8.s64 = ctx.r10.s64 + -7600;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F66DC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82883b10
	ctx.lr = 0x82F66DE0;
	sub_82883B10(ctx, base);
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r11,-11168
	ctx.r30.s64 = ctx.r11.s64 + -11168;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66E04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66e28
	if (ctx.cr6.eq) goto loc_82F66E28;
	// lis r10,-32206
	ctx.r10.s64 = -2110652416;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r9,r10,13964
	ctx.r9.s64 = ctx.r10.s64 + 13964;
	// addi r31,r11,-7552
	ctx.r31.s64 = ctx.r11.s64 + -7552;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r3,-7552(r11)
	REX_STORE_U32(ctx.r11.u32 + -7552, ctx.r3.u32);
	// b 0x82f66e38
	goto loc_82F66E38;
loc_82F66E28:
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r31,r10,-7552
	ctx.r31.s64 = ctx.r10.s64 + -7552;
	// stw r11,-7552(r10)
	REX_STORE_U32(ctx.r10.u32 + -7552, ctx.r11.u32);
loc_82F66E38:
	// bl 0x82883b10
	ctx.lr = 0x82F66E3C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66E58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66e74
	if (ctx.cr6.eq) goto loc_82F66E74;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,13980
	ctx.r10.s64 = ctx.r11.s64 + 13980;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// b 0x82f66e7c
	goto loc_82F66E7C;
loc_82F66E74:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_82F66E7C:
	// bl 0x82883b10
	ctx.lr = 0x82F66E80;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66E9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66eb8
	if (ctx.cr6.eq) goto loc_82F66EB8;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,13996
	ctx.r10.s64 = ctx.r11.s64 + 13996;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// b 0x82f66ec0
	goto loc_82F66EC0;
loc_82F66EB8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82F66EC0:
	// bl 0x82883b10
	ctx.lr = 0x82F66EC4;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66EE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66efc
	if (ctx.cr6.eq) goto loc_82F66EFC;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14012
	ctx.r10.s64 = ctx.r11.s64 + 14012;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// b 0x82f66f04
	goto loc_82F66F04;
loc_82F66EFC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82F66F04:
	// bl 0x82883b10
	ctx.lr = 0x82F66F08;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66F24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66f40
	if (ctx.cr6.eq) goto loc_82F66F40;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14028
	ctx.r10.s64 = ctx.r11.s64 + 14028;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// b 0x82f66f48
	goto loc_82F66F48;
loc_82F66F40:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_82F66F48:
	// bl 0x82883b10
	ctx.lr = 0x82F66F4C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66F68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66f84
	if (ctx.cr6.eq) goto loc_82F66F84;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14044
	ctx.r10.s64 = ctx.r11.s64 + 14044;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// b 0x82f66f8c
	goto loc_82F66F8C;
loc_82F66F84:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_82F66F8C:
	// bl 0x82883b10
	ctx.lr = 0x82F66F90;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66FAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f66fc8
	if (ctx.cr6.eq) goto loc_82F66FC8;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14060
	ctx.r10.s64 = ctx.r11.s64 + 14060;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// b 0x82f66fd0
	goto loc_82F66FD0;
loc_82F66FC8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_82F66FD0:
	// bl 0x82883b10
	ctx.lr = 0x82F66FD4;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F66FF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6700c
	if (ctx.cr6.eq) goto loc_82F6700C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14076
	ctx.r10.s64 = ctx.r11.s64 + 14076;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// b 0x82f67014
	goto loc_82F67014;
loc_82F6700C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_82F67014:
	// bl 0x82883b10
	ctx.lr = 0x82F67018;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67034;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67050
	if (ctx.cr6.eq) goto loc_82F67050;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14092
	ctx.r10.s64 = ctx.r11.s64 + 14092;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// b 0x82f67058
	goto loc_82F67058;
loc_82F67050:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_82F67058:
	// bl 0x82883b10
	ctx.lr = 0x82F6705C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67078;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67094
	if (ctx.cr6.eq) goto loc_82F67094;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14108
	ctx.r10.s64 = ctx.r11.s64 + 14108;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// b 0x82f6709c
	goto loc_82F6709C;
loc_82F67094:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_82F6709C:
	// bl 0x82883b10
	ctx.lr = 0x82F670A0;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F670BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f670d8
	if (ctx.cr6.eq) goto loc_82F670D8;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14124
	ctx.r10.s64 = ctx.r11.s64 + 14124;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// b 0x82f670e0
	goto loc_82F670E0;
loc_82F670D8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_82F670E0:
	// bl 0x82883b10
	ctx.lr = 0x82F670E4;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67100;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6711c
	if (ctx.cr6.eq) goto loc_82F6711C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14140
	ctx.r10.s64 = ctx.r11.s64 + 14140;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// b 0x82f67124
	goto loc_82F67124;
loc_82F6711C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_82F67124:
	// bl 0x82883b10
	ctx.lr = 0x82F67128;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67144;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67160
	if (ctx.cr6.eq) goto loc_82F67160;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14156
	ctx.r10.s64 = ctx.r11.s64 + 14156;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// b 0x82f67168
	goto loc_82F67168;
loc_82F67160:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_82F67168:
	// bl 0x82883b10
	ctx.lr = 0x82F6716C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67188;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f671a4
	if (ctx.cr6.eq) goto loc_82F671A4;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14172
	ctx.r10.s64 = ctx.r11.s64 + 14172;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// b 0x82f671ac
	goto loc_82F671AC;
loc_82F671A4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_82F671AC:
	// bl 0x82883b10
	ctx.lr = 0x82F671B0;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F671CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f671e8
	if (ctx.cr6.eq) goto loc_82F671E8;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14188
	ctx.r10.s64 = ctx.r11.s64 + 14188;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// b 0x82f671f0
	goto loc_82F671F0;
loc_82F671E8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_82F671F0:
	// bl 0x82883b10
	ctx.lr = 0x82F671F4;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67210;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6722c
	if (ctx.cr6.eq) goto loc_82F6722C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14204
	ctx.r10.s64 = ctx.r11.s64 + 14204;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r3.u32);
	// b 0x82f67234
	goto loc_82F67234;
loc_82F6722C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_82F67234:
	// bl 0x82883b10
	ctx.lr = 0x82F67238;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67254;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67270
	if (ctx.cr6.eq) goto loc_82F67270;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14220
	ctx.r10.s64 = ctx.r11.s64 + 14220;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// b 0x82f67278
	goto loc_82F67278;
loc_82F67270:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_82F67278:
	// bl 0x82883b10
	ctx.lr = 0x82F6727C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f672b4
	if (ctx.cr6.eq) goto loc_82F672B4;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14236
	ctx.r10.s64 = ctx.r11.s64 + 14236;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
	// b 0x82f672bc
	goto loc_82F672BC;
loc_82F672B4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_82F672BC:
	// bl 0x82883b10
	ctx.lr = 0x82F672C0;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F672DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f672f8
	if (ctx.cr6.eq) goto loc_82F672F8;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14252
	ctx.r10.s64 = ctx.r11.s64 + 14252;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r3.u32);
	// b 0x82f67300
	goto loc_82F67300;
loc_82F672F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_82F67300:
	// bl 0x82883b10
	ctx.lr = 0x82F67304;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67320;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6733c
	if (ctx.cr6.eq) goto loc_82F6733C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14268
	ctx.r10.s64 = ctx.r11.s64 + 14268;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// b 0x82f67344
	goto loc_82F67344;
loc_82F6733C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_82F67344:
	// bl 0x82883b10
	ctx.lr = 0x82F67348;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67364;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67380
	if (ctx.cr6.eq) goto loc_82F67380;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14284
	ctx.r10.s64 = ctx.r11.s64 + 14284;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x82f67388
	goto loc_82F67388;
loc_82F67380:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_82F67388:
	// bl 0x82883b10
	ctx.lr = 0x82F6738C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F673A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f673c4
	if (ctx.cr6.eq) goto loc_82F673C4;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14300
	ctx.r10.s64 = ctx.r11.s64 + 14300;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// b 0x82f673cc
	goto loc_82F673CC;
loc_82F673C4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_82F673CC:
	// bl 0x82883b10
	ctx.lr = 0x82F673D0;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F673EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67408
	if (ctx.cr6.eq) goto loc_82F67408;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14316
	ctx.r10.s64 = ctx.r11.s64 + 14316;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// b 0x82f67410
	goto loc_82F67410;
loc_82F67408:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_82F67410:
	// bl 0x82883b10
	ctx.lr = 0x82F67414;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67430;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6744c
	if (ctx.cr6.eq) goto loc_82F6744C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14332
	ctx.r10.s64 = ctx.r11.s64 + 14332;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// b 0x82f67454
	goto loc_82F67454;
loc_82F6744C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_82F67454:
	// bl 0x82883b10
	ctx.lr = 0x82F67458;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67474;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67490
	if (ctx.cr6.eq) goto loc_82F67490;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14348
	ctx.r10.s64 = ctx.r11.s64 + 14348;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// b 0x82f67498
	goto loc_82F67498;
loc_82F67490:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
loc_82F67498:
	// bl 0x82883b10
	ctx.lr = 0x82F6749C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F674B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f674d4
	if (ctx.cr6.eq) goto loc_82F674D4;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14364
	ctx.r10.s64 = ctx.r11.s64 + 14364;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// b 0x82f674dc
	goto loc_82F674DC;
loc_82F674D4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_82F674DC:
	// bl 0x82883b10
	ctx.lr = 0x82F674E0;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F674FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67518
	if (ctx.cr6.eq) goto loc_82F67518;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14380
	ctx.r10.s64 = ctx.r11.s64 + 14380;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r3.u32);
	// b 0x82f67520
	goto loc_82F67520;
loc_82F67518:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_82F67520:
	// bl 0x82883b10
	ctx.lr = 0x82F67524;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67540;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6755c
	if (ctx.cr6.eq) goto loc_82F6755C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14396
	ctx.r10.s64 = ctx.r11.s64 + 14396;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r3.u32);
	// b 0x82f67564
	goto loc_82F67564;
loc_82F6755C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
loc_82F67564:
	// bl 0x82883b10
	ctx.lr = 0x82F67568;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67584;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f675a0
	if (ctx.cr6.eq) goto loc_82F675A0;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14412
	ctx.r10.s64 = ctx.r11.s64 + 14412;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// b 0x82f675a8
	goto loc_82F675A8;
loc_82F675A0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
loc_82F675A8:
	// bl 0x82883b10
	ctx.lr = 0x82F675AC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F675C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f675e4
	if (ctx.cr6.eq) goto loc_82F675E4;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14428
	ctx.r10.s64 = ctx.r11.s64 + 14428;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r3.u32);
	// b 0x82f675ec
	goto loc_82F675EC;
loc_82F675E4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
loc_82F675EC:
	// bl 0x82883b10
	ctx.lr = 0x82F675F0;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6760C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67628
	if (ctx.cr6.eq) goto loc_82F67628;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14444
	ctx.r10.s64 = ctx.r11.s64 + 14444;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r3.u32);
	// b 0x82f67630
	goto loc_82F67630;
loc_82F67628:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
loc_82F67630:
	// bl 0x82883b10
	ctx.lr = 0x82F67634;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67650;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6766c
	if (ctx.cr6.eq) goto loc_82F6766C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14460
	ctx.r10.s64 = ctx.r11.s64 + 14460;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// b 0x82f67674
	goto loc_82F67674;
loc_82F6766C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
loc_82F67674:
	// bl 0x82883b10
	ctx.lr = 0x82F67678;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67694;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f676b0
	if (ctx.cr6.eq) goto loc_82F676B0;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14476
	ctx.r10.s64 = ctx.r11.s64 + 14476;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// b 0x82f676b8
	goto loc_82F676B8;
loc_82F676B0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
loc_82F676B8:
	// bl 0x82883b10
	ctx.lr = 0x82F676BC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F676D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f676f4
	if (ctx.cr6.eq) goto loc_82F676F4;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14492
	ctx.r10.s64 = ctx.r11.s64 + 14492;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// b 0x82f676fc
	goto loc_82F676FC;
loc_82F676F4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
loc_82F676FC:
	// bl 0x82883b10
	ctx.lr = 0x82F67700;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6771C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67738
	if (ctx.cr6.eq) goto loc_82F67738;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14508
	ctx.r10.s64 = ctx.r11.s64 + 14508;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r3.u32);
	// b 0x82f67740
	goto loc_82F67740;
loc_82F67738:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
loc_82F67740:
	// bl 0x82883b10
	ctx.lr = 0x82F67744;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67760;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6777c
	if (ctx.cr6.eq) goto loc_82F6777C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14524
	ctx.r10.s64 = ctx.r11.s64 + 14524;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r3.u32);
	// b 0x82f67784
	goto loc_82F67784;
loc_82F6777C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_82F67784:
	// bl 0x82883b10
	ctx.lr = 0x82F67788;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F677A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f677c0
	if (ctx.cr6.eq) goto loc_82F677C0;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14540
	ctx.r10.s64 = ctx.r11.s64 + 14540;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r3.u32);
	// b 0x82f677c8
	goto loc_82F677C8;
loc_82F677C0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
loc_82F677C8:
	// bl 0x82883b10
	ctx.lr = 0x82F677CC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F677E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67804
	if (ctx.cr6.eq) goto loc_82F67804;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14556
	ctx.r10.s64 = ctx.r11.s64 + 14556;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// b 0x82f6780c
	goto loc_82F6780C;
loc_82F67804:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
loc_82F6780C:
	// bl 0x82883b10
	ctx.lr = 0x82F67810;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6782C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67848
	if (ctx.cr6.eq) goto loc_82F67848;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14572
	ctx.r10.s64 = ctx.r11.s64 + 14572;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r3.u32);
	// b 0x82f67850
	goto loc_82F67850;
loc_82F67848:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
loc_82F67850:
	// bl 0x82883b10
	ctx.lr = 0x82F67854;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67870;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6788c
	if (ctx.cr6.eq) goto loc_82F6788C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14588
	ctx.r10.s64 = ctx.r11.s64 + 14588;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r3.u32);
	// b 0x82f67894
	goto loc_82F67894;
loc_82F6788C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
loc_82F67894:
	// bl 0x82883b10
	ctx.lr = 0x82F67898;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F678B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f678d0
	if (ctx.cr6.eq) goto loc_82F678D0;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14604
	ctx.r10.s64 = ctx.r11.s64 + 14604;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r3.u32);
	// b 0x82f678d8
	goto loc_82F678D8;
loc_82F678D0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
loc_82F678D8:
	// bl 0x82883b10
	ctx.lr = 0x82F678DC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F678F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67914
	if (ctx.cr6.eq) goto loc_82F67914;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14620
	ctx.r10.s64 = ctx.r11.s64 + 14620;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r3.u32);
	// b 0x82f6791c
	goto loc_82F6791C;
loc_82F67914:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_82F6791C:
	// bl 0x82883b10
	ctx.lr = 0x82F67920;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6793C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67958
	if (ctx.cr6.eq) goto loc_82F67958;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14636
	ctx.r10.s64 = ctx.r11.s64 + 14636;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r3.u32);
	// b 0x82f67960
	goto loc_82F67960;
loc_82F67958:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
loc_82F67960:
	// bl 0x82883b10
	ctx.lr = 0x82F67964;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67980;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6799c
	if (ctx.cr6.eq) goto loc_82F6799C;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14652
	ctx.r10.s64 = ctx.r11.s64 + 14652;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r3.u32);
	// b 0x82f679a4
	goto loc_82F679A4;
loc_82F6799C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
loc_82F679A4:
	// bl 0x82883b10
	ctx.lr = 0x82F679A8;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F679C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f679e0
	if (ctx.cr6.eq) goto loc_82F679E0;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14668
	ctx.r10.s64 = ctx.r11.s64 + 14668;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r3.u32);
	// b 0x82f679e8
	goto loc_82F679E8;
loc_82F679E0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
loc_82F679E8:
	// bl 0x82883b10
	ctx.lr = 0x82F679EC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67A08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67a24
	if (ctx.cr6.eq) goto loc_82F67A24;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14684
	ctx.r10.s64 = ctx.r11.s64 + 14684;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// b 0x82f67a2c
	goto loc_82F67A2C;
loc_82F67A24:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
loc_82F67A2C:
	// bl 0x82883b10
	ctx.lr = 0x82F67A30;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67A4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67a68
	if (ctx.cr6.eq) goto loc_82F67A68;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14700
	ctx.r10.s64 = ctx.r11.s64 + 14700;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// b 0x82f67a70
	goto loc_82F67A70;
loc_82F67A68:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
loc_82F67A70:
	// bl 0x82883b10
	ctx.lr = 0x82F67A74;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67A90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67aac
	if (ctx.cr6.eq) goto loc_82F67AAC;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14716
	ctx.r10.s64 = ctx.r11.s64 + 14716;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r3.u32);
	// b 0x82f67ab4
	goto loc_82F67AB4;
loc_82F67AAC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
loc_82F67AB4:
	// bl 0x82883b10
	ctx.lr = 0x82F67AB8;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67AD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67af0
	if (ctx.cr6.eq) goto loc_82F67AF0;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14732
	ctx.r10.s64 = ctx.r11.s64 + 14732;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r3.u32);
	// b 0x82f67af8
	goto loc_82F67AF8;
loc_82F67AF0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
loc_82F67AF8:
	// bl 0x82883b10
	ctx.lr = 0x82F67AFC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67B18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67b34
	if (ctx.cr6.eq) goto loc_82F67B34;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14748
	ctx.r10.s64 = ctx.r11.s64 + 14748;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r3.u32);
	// b 0x82f67b3c
	goto loc_82F67B3C;
loc_82F67B34:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
loc_82F67B3C:
	// bl 0x82883b10
	ctx.lr = 0x82F67B40;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67B5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f67b78
	if (ctx.cr6.eq) goto loc_82F67B78;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// addi r10,r11,14764
	ctx.r10.s64 = ctx.r11.s64 + 14764;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r3,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r3.u32);
	// b 0x82f67b80
	goto loc_82F67B80;
loc_82F67B78:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
loc_82F67B80:
	// bl 0x82883b10
	ctx.lr = 0x82F67B84;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F67BA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x82f67bc4
	if (ctx.cr6.eq) goto loc_82F67BC4;
	// lis r10,-32206
	ctx.r10.s64 = -2110652416;
	// addi r9,r10,14780
	ctx.r9.s64 = ctx.r10.s64 + 14780;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r3,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// stw r11,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// b 0x82f67bd0
	goto loc_82F67BD0;
loc_82F67BC4:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// stw r10,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r10.u32);
loc_82F67BD0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67BE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-1440
	ctx.r9.s64 = ctx.r11.s64 + -1440;
	// addi r8,r10,6624
	ctx.r8.s64 = ctx.r10.s64 + 6624;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67C08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-1432
	ctx.r9.s64 = ctx.r11.s64 + -1432;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,65
	ctx.r11.s64 = 65;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F67C24:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f67c24
	if (!ctx.cr6.eq) goto loc_82F67C24;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6576(r11)
	REX_STORE_U32(ctx.r11.u32 + 6576, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67C48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-1328
	ctx.r9.s64 = ctx.r11.s64 + -1328;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,67
	ctx.r11.s64 = 67;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F67C64:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f67c64
	if (!ctx.cr6.eq) goto loc_82F67C64;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6572(r11)
	REX_STORE_U32(ctx.r11.u32 + 6572, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,6640
	ctx.r7.s64 = ctx.r8.s64 + 6640;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67CB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,6608
	ctx.r8.s64 = ctx.r10.s64 + 6608;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67CD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// lfs f0,19856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-18836(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18836);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stfs f0,-7340(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67CF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,6488
	ctx.r3.s64 = ctx.r11.s64 + 6488;
	// bl 0x82db9d98
	ctx.lr = 0x82F67D08;
	sub_82DB9D98(ctx, base);
	// lis r10,-32009
	ctx.r10.s64 = -2097741824;
	// addi r3,r10,4336
	ctx.r3.s64 = ctx.r10.s64 + 4336;
	// bl 0x82f22d28
	ctx.lr = 0x82F67D14;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67D28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31710
	ctx.r11.s64 = -2078146560;
	// lis r9,-13326
	ctx.r9.s64 = -873332736;
	// ori r10,r11,8997
	ctx.r10.u64 = ctx.r11.u64 | 8997;
	// ori r8,r9,40164
	ctx.r8.u64 = ctx.r9.u64 | 40164;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// rldimi r10,r8,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// li r7,435
	ctx.r7.s64 = 435;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r9,r11,-944
	ctx.r9.s64 = ctx.r11.s64 + -944;
	// li r11,73
	ctx.r11.s64 = 73;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
loc_82F67D54:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// mulld r5,r10,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r10.u64 * ctx.r7.u64);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// xor r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f67d54
	if (!ctx.cr6.eq) goto loc_82F67D54;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// std r10,6592(r11)
	REX_STORE_U64(ctx.r11.u32 + 6592, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67D80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-924
	ctx.r4.s64 = ctx.r11.s64 + -924;
	// addi r3,r10,6600
	ctx.r3.s64 = ctx.r10.s64 + 6600;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F67D98) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-908
	ctx.r4.s64 = ctx.r11.s64 + -908;
	// addi r3,r10,6584
	ctx.r3.s64 = ctx.r10.s64 + 6584;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F67DB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r10,384
	ctx.r10.s64 = 384;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r11,r11,-7336
	ctx.r11.s64 = ctx.r11.s64 + -7336;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82F67DCC:
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stwu r9,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82f67dcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F67DCC;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67DE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r10,384
	ctx.r10.s64 = 384;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r11,r11,-1192
	ctx.r11.s64 = ctx.r11.s64 + -1192;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82F67E00:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stwu r10,20(r11)
	ea = 20 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82f67e00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F67E00;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67E30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82f274b0
	ctx.lr = 0x82F67E38;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82dbbad0
	ctx.lr = 0x82F67E40;
	sub_82DBBAD0(ctx, base);
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r22,r11,-1192
	ctx.r22.s64 = ctx.r11.s64 + -1192;
	// lis r11,-31998
	ctx.r11.s64 = -2097020928;
	// addi r31,r10,-7336
	ctx.r31.s64 = ctx.r10.s64 + -7336;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r26,r11,11856
	ctx.r26.s64 = ctx.r11.s64 + 11856;
loc_82F67E60:
	// li r23,2
	ctx.r23.s64 = 2;
loc_82F67E64:
	// li r24,2
	ctx.r24.s64 = 2;
loc_82F67E68:
	// li r25,2
	ctx.r25.s64 = 2;
loc_82F67E6C:
	// li r27,4
	ctx.r27.s64 = 4;
loc_82F67E70:
	// li r28,6
	ctx.r28.s64 = 6;
loc_82F67E74:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r26,-3072
	ctx.r10.s64 = ctx.r26.s64 + -3072;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r8,r26,-1536
	ctx.r8.s64 = ctx.r26.s64 + -1536;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stwx r11,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r11.u32);
	// stwx r9,r30,r8
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, ctx.r9.u32);
	// bl 0x823b3760
	ctx.lr = 0x82F67E98;
	sub_823B3760(ctx, base);
	// lwz r7,12(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// stwx r7,r30,r26
	REX_STORE_U32(ctx.r30.u32 + ctx.r26.u32, ctx.r7.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82f67e74
	if (!ctx.cr0.eq) goto loc_82F67E74;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x82f67e70
	if (!ctx.cr0.eq) goto loc_82F67E70;
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x82f67e6c
	if (!ctx.cr0.eq) goto loc_82F67E6C;
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne 0x82f67e68
	if (!ctx.cr0.eq) goto loc_82F67E68;
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne 0x82f67e64
	if (!ctx.cr0.eq) goto loc_82F67E64;
	// addi r11,r22,7680
	ctx.r11.s64 = ctx.r22.s64 + 7680;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82f67e60
	if (ctx.cr6.lt) goto loc_82F67E60;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82f27500
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F67EE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-11176
	ctx.r9.s64 = ctx.r11.s64 + -11176;
	// addi r8,r10,6768
	ctx.r8.s64 = ctx.r10.s64 + 6768;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67F08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-10900
	ctx.r9.s64 = ctx.r11.s64 + -10900;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,65
	ctx.r11.s64 = 65;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F67F24:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f67f24
	if (!ctx.cr6.eq) goto loc_82F67F24;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6696(r11)
	REX_STORE_U32(ctx.r11.u32 + 6696, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67F48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-10892
	ctx.r9.s64 = ctx.r11.s64 + -10892;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,67
	ctx.r11.s64 = 67;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F67F64:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f67f64
	if (!ctx.cr6.eq) goto loc_82F67F64;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6692(r11)
	REX_STORE_U32(ctx.r11.u32 + 6692, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67F88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F67F98;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-2160
	ctx.r5.s64 = ctx.r11.s64 + -2160;
	// addi r4,r10,-10880
	ctx.r4.s64 = ctx.r10.s64 + -10880;
	// bl 0x826a61b0
	ctx.lr = 0x82F67FAC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6679(r9)
	REX_STORE_U8(ctx.r9.u32 + 6679, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F67FC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F67FD8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-2000
	ctx.r5.s64 = ctx.r11.s64 + -2000;
	// addi r4,r10,-10864
	ctx.r4.s64 = ctx.r10.s64 + -10864;
	// bl 0x826a61b0
	ctx.lr = 0x82F67FEC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6735(r9)
	REX_STORE_U8(ctx.r9.u32 + 6735, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68008) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68018;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-1840
	ctx.r5.s64 = ctx.r11.s64 + -1840;
	// addi r4,r10,-10836
	ctx.r4.s64 = ctx.r10.s64 + -10836;
	// bl 0x826a61b0
	ctx.lr = 0x82F6802C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6684(r9)
	REX_STORE_U8(ctx.r9.u32 + 6684, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68048) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68058;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-1680
	ctx.r5.s64 = ctx.r11.s64 + -1680;
	// addi r4,r10,-10824
	ctx.r4.s64 = ctx.r10.s64 + -10824;
	// bl 0x826a61b0
	ctx.lr = 0x82F6806C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6690(r9)
	REX_STORE_U8(ctx.r9.u32 + 6690, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68098;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-1520
	ctx.r5.s64 = ctx.r11.s64 + -1520;
	// addi r4,r10,-10808
	ctx.r4.s64 = ctx.r10.s64 + -10808;
	// bl 0x826a61b0
	ctx.lr = 0x82F680AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6673(r9)
	REX_STORE_U8(ctx.r9.u32 + 6673, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F680C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F680D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-1360
	ctx.r5.s64 = ctx.r11.s64 + -1360;
	// addi r4,r10,-10788
	ctx.r4.s64 = ctx.r10.s64 + -10788;
	// bl 0x826a61b0
	ctx.lr = 0x82F680EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6748(r9)
	REX_STORE_U8(ctx.r9.u32 + 6748, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68108) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68118;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-1200
	ctx.r5.s64 = ctx.r11.s64 + -1200;
	// addi r4,r10,-10768
	ctx.r4.s64 = ctx.r10.s64 + -10768;
	// bl 0x826a61b0
	ctx.lr = 0x82F6812C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6728(r9)
	REX_STORE_U8(ctx.r9.u32 + 6728, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68148) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68158;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-1040
	ctx.r5.s64 = ctx.r11.s64 + -1040;
	// addi r4,r10,-10756
	ctx.r4.s64 = ctx.r10.s64 + -10756;
	// bl 0x826a61b0
	ctx.lr = 0x82F6816C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6665(r9)
	REX_STORE_U8(ctx.r9.u32 + 6665, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68188) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68198;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-880
	ctx.r5.s64 = ctx.r11.s64 + -880;
	// addi r4,r10,-10744
	ctx.r4.s64 = ctx.r10.s64 + -10744;
	// bl 0x826a61b0
	ctx.lr = 0x82F681AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6668(r9)
	REX_STORE_U8(ctx.r9.u32 + 6668, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F681C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F681D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-720
	ctx.r5.s64 = ctx.r11.s64 + -720;
	// addi r4,r10,-10724
	ctx.r4.s64 = ctx.r10.s64 + -10724;
	// bl 0x826a61b0
	ctx.lr = 0x82F681EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6671(r9)
	REX_STORE_U8(ctx.r9.u32 + 6671, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68208) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68218;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-560
	ctx.r5.s64 = ctx.r11.s64 + -560;
	// addi r4,r10,-10704
	ctx.r4.s64 = ctx.r10.s64 + -10704;
	// bl 0x826a61b0
	ctx.lr = 0x82F6822C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6701(r9)
	REX_STORE_U8(ctx.r9.u32 + 6701, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68248) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68258;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-400
	ctx.r5.s64 = ctx.r11.s64 + -400;
	// addi r4,r10,-10684
	ctx.r4.s64 = ctx.r10.s64 + -10684;
	// bl 0x826a61b0
	ctx.lr = 0x82F6826C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6744(r9)
	REX_STORE_U8(ctx.r9.u32 + 6744, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68288) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68298;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-80
	ctx.r5.s64 = ctx.r11.s64 + -80;
	// addi r4,r10,-10668
	ctx.r4.s64 = ctx.r10.s64 + -10668;
	// bl 0x826a61b0
	ctx.lr = 0x82F682AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6730(r9)
	REX_STORE_U8(ctx.r9.u32 + 6730, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F682C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F682D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-240
	ctx.r5.s64 = ctx.r11.s64 + -240;
	// addi r4,r10,-10652
	ctx.r4.s64 = ctx.r10.s64 + -10652;
	// bl 0x826a61b0
	ctx.lr = 0x82F682EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6725(r9)
	REX_STORE_U8(ctx.r9.u32 + 6725, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68308) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68318;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,-80
	ctx.r5.s64 = ctx.r11.s64 + -80;
	// addi r4,r10,-10628
	ctx.r4.s64 = ctx.r10.s64 + -10628;
	// bl 0x826a61b0
	ctx.lr = 0x82F6832C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6660(r9)
	REX_STORE_U8(ctx.r9.u32 + 6660, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68348) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68358;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,80
	ctx.r5.s64 = ctx.r11.s64 + 80;
	// addi r4,r10,-10612
	ctx.r4.s64 = ctx.r10.s64 + -10612;
	// bl 0x826a61b0
	ctx.lr = 0x82F6836C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6724(r9)
	REX_STORE_U8(ctx.r9.u32 + 6724, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68388) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68398;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,80
	ctx.r5.s64 = ctx.r11.s64 + 80;
	// addi r4,r10,-10600
	ctx.r4.s64 = ctx.r10.s64 + -10600;
	// bl 0x826a61b0
	ctx.lr = 0x82F683AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6659(r9)
	REX_STORE_U8(ctx.r9.u32 + 6659, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F683C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F683D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,240
	ctx.r5.s64 = ctx.r11.s64 + 240;
	// addi r4,r10,-10588
	ctx.r4.s64 = ctx.r10.s64 + -10588;
	// bl 0x826a61b0
	ctx.lr = 0x82F683EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6750(r9)
	REX_STORE_U8(ctx.r9.u32 + 6750, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68408) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68418;
	sub_826A37A8(ctx, base);
	// lis r11,-32149
	ctx.r11.s64 = -2106916864;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6328
	ctx.r5.s64 = ctx.r11.s64 + 6328;
	// addi r4,r10,-10576
	ctx.r4.s64 = ctx.r10.s64 + -10576;
	// bl 0x826a61b0
	ctx.lr = 0x82F6842C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6687(r9)
	REX_STORE_U8(ctx.r9.u32 + 6687, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68448) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68458;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,400
	ctx.r5.s64 = ctx.r11.s64 + 400;
	// addi r4,r10,-10552
	ctx.r4.s64 = ctx.r10.s64 + -10552;
	// bl 0x826a61b0
	ctx.lr = 0x82F6846C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6720(r9)
	REX_STORE_U8(ctx.r9.u32 + 6720, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68488) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68498;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,560
	ctx.r5.s64 = ctx.r11.s64 + 560;
	// addi r4,r10,-10532
	ctx.r4.s64 = ctx.r10.s64 + -10532;
	// bl 0x826a61b0
	ctx.lr = 0x82F684AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6672(r9)
	REX_STORE_U8(ctx.r9.u32 + 6672, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F684C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F684D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,720
	ctx.r5.s64 = ctx.r11.s64 + 720;
	// addi r4,r10,-10512
	ctx.r4.s64 = ctx.r10.s64 + -10512;
	// bl 0x826a61b0
	ctx.lr = 0x82F684EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6691(r9)
	REX_STORE_U8(ctx.r9.u32 + 6691, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68508) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68518;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,880
	ctx.r5.s64 = ctx.r11.s64 + 880;
	// addi r4,r10,-10492
	ctx.r4.s64 = ctx.r10.s64 + -10492;
	// bl 0x826a61b0
	ctx.lr = 0x82F6852C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6656(r9)
	REX_STORE_U8(ctx.r9.u32 + 6656, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68548) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68558;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,1040
	ctx.r5.s64 = ctx.r11.s64 + 1040;
	// addi r4,r10,-10472
	ctx.r4.s64 = ctx.r10.s64 + -10472;
	// bl 0x826a61b0
	ctx.lr = 0x82F6856C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6723(r9)
	REX_STORE_U8(ctx.r9.u32 + 6723, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68588) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68598;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,1200
	ctx.r5.s64 = ctx.r11.s64 + 1200;
	// addi r4,r10,-10460
	ctx.r4.s64 = ctx.r10.s64 + -10460;
	// bl 0x826a61b0
	ctx.lr = 0x82F685AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6676(r9)
	REX_STORE_U8(ctx.r9.u32 + 6676, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F685C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F685D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,1360
	ctx.r5.s64 = ctx.r11.s64 + 1360;
	// addi r4,r10,-10440
	ctx.r4.s64 = ctx.r10.s64 + -10440;
	// bl 0x826a61b0
	ctx.lr = 0x82F685EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6703(r9)
	REX_STORE_U8(ctx.r9.u32 + 6703, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68608) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68618;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,1520
	ctx.r5.s64 = ctx.r11.s64 + 1520;
	// addi r4,r10,-10420
	ctx.r4.s64 = ctx.r10.s64 + -10420;
	// bl 0x826a61b0
	ctx.lr = 0x82F6862C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6689(r9)
	REX_STORE_U8(ctx.r9.u32 + 6689, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68648) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68658;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,1680
	ctx.r5.s64 = ctx.r11.s64 + 1680;
	// addi r4,r10,-10392
	ctx.r4.s64 = ctx.r10.s64 + -10392;
	// bl 0x826a61b0
	ctx.lr = 0x82F6866C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6681(r9)
	REX_STORE_U8(ctx.r9.u32 + 6681, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68688) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68698;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,1840
	ctx.r5.s64 = ctx.r11.s64 + 1840;
	// addi r4,r10,-10368
	ctx.r4.s64 = ctx.r10.s64 + -10368;
	// bl 0x826a61b0
	ctx.lr = 0x82F686AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6686(r9)
	REX_STORE_U8(ctx.r9.u32 + 6686, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F686C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F686D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2000
	ctx.r5.s64 = ctx.r11.s64 + 2000;
	// addi r4,r10,-10348
	ctx.r4.s64 = ctx.r10.s64 + -10348;
	// bl 0x826a61b0
	ctx.lr = 0x82F686EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6664(r9)
	REX_STORE_U8(ctx.r9.u32 + 6664, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68708) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68718;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2160
	ctx.r5.s64 = ctx.r11.s64 + 2160;
	// addi r4,r10,-10324
	ctx.r4.s64 = ctx.r10.s64 + -10324;
	// bl 0x826a61b0
	ctx.lr = 0x82F6872C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6685(r9)
	REX_STORE_U8(ctx.r9.u32 + 6685, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68748) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68758;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2320
	ctx.r5.s64 = ctx.r11.s64 + 2320;
	// addi r4,r10,-10304
	ctx.r4.s64 = ctx.r10.s64 + -10304;
	// bl 0x826a61b0
	ctx.lr = 0x82F6876C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6658(r9)
	REX_STORE_U8(ctx.r9.u32 + 6658, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68788) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68798;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2480
	ctx.r5.s64 = ctx.r11.s64 + 2480;
	// addi r4,r10,-10272
	ctx.r4.s64 = ctx.r10.s64 + -10272;
	// bl 0x826a61b0
	ctx.lr = 0x82F687AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6661(r9)
	REX_STORE_U8(ctx.r9.u32 + 6661, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F687C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F687D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2640
	ctx.r5.s64 = ctx.r11.s64 + 2640;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// bl 0x826a61b0
	ctx.lr = 0x82F687EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6746(r9)
	REX_STORE_U8(ctx.r9.u32 + 6746, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68808) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68818;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2800
	ctx.r5.s64 = ctx.r11.s64 + 2800;
	// addi r4,r10,-10228
	ctx.r4.s64 = ctx.r10.s64 + -10228;
	// bl 0x826a61b0
	ctx.lr = 0x82F6882C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6657(r9)
	REX_STORE_U8(ctx.r9.u32 + 6657, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68848) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68858;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,2960
	ctx.r5.s64 = ctx.r11.s64 + 2960;
	// addi r4,r10,-10212
	ctx.r4.s64 = ctx.r10.s64 + -10212;
	// bl 0x826a61b0
	ctx.lr = 0x82F6886C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6732(r9)
	REX_STORE_U8(ctx.r9.u32 + 6732, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68888) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68898;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,3120
	ctx.r5.s64 = ctx.r11.s64 + 3120;
	// addi r4,r10,-10196
	ctx.r4.s64 = ctx.r10.s64 + -10196;
	// bl 0x826a61b0
	ctx.lr = 0x82F688AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6745(r9)
	REX_STORE_U8(ctx.r9.u32 + 6745, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F688C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F688D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,3280
	ctx.r5.s64 = ctx.r11.s64 + 3280;
	// addi r4,r10,-10176
	ctx.r4.s64 = ctx.r10.s64 + -10176;
	// bl 0x826a61b0
	ctx.lr = 0x82F688EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6675(r9)
	REX_STORE_U8(ctx.r9.u32 + 6675, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68908) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68918;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,3440
	ctx.r5.s64 = ctx.r11.s64 + 3440;
	// addi r4,r10,-10160
	ctx.r4.s64 = ctx.r10.s64 + -10160;
	// bl 0x826a61b0
	ctx.lr = 0x82F6892C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6667(r9)
	REX_STORE_U8(ctx.r9.u32 + 6667, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68948) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68958;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,3600
	ctx.r5.s64 = ctx.r11.s64 + 3600;
	// addi r4,r10,-10140
	ctx.r4.s64 = ctx.r10.s64 + -10140;
	// bl 0x826a61b0
	ctx.lr = 0x82F6896C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6674(r9)
	REX_STORE_U8(ctx.r9.u32 + 6674, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68988) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68998;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,3760
	ctx.r5.s64 = ctx.r11.s64 + 3760;
	// addi r4,r10,-10120
	ctx.r4.s64 = ctx.r10.s64 + -10120;
	// bl 0x826a61b0
	ctx.lr = 0x82F689AC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6680(r9)
	REX_STORE_U8(ctx.r9.u32 + 6680, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F689C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F689D8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,3920
	ctx.r5.s64 = ctx.r11.s64 + 3920;
	// addi r4,r10,-10092
	ctx.r4.s64 = ctx.r10.s64 + -10092;
	// bl 0x826a61b0
	ctx.lr = 0x82F689EC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6726(r9)
	REX_STORE_U8(ctx.r9.u32 + 6726, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68A18;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,4080
	ctx.r5.s64 = ctx.r11.s64 + 4080;
	// addi r4,r10,-10072
	ctx.r4.s64 = ctx.r10.s64 + -10072;
	// bl 0x826a61b0
	ctx.lr = 0x82F68A2C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6663(r9)
	REX_STORE_U8(ctx.r9.u32 + 6663, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68A48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68A58;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,4240
	ctx.r5.s64 = ctx.r11.s64 + 4240;
	// addi r4,r10,-10052
	ctx.r4.s64 = ctx.r10.s64 + -10052;
	// bl 0x826a61b0
	ctx.lr = 0x82F68A6C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6722(r9)
	REX_STORE_U8(ctx.r9.u32 + 6722, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68A88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68A98;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,4400
	ctx.r5.s64 = ctx.r11.s64 + 4400;
	// addi r4,r10,-10036
	ctx.r4.s64 = ctx.r10.s64 + -10036;
	// bl 0x826a61b0
	ctx.lr = 0x82F68AAC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6670(r9)
	REX_STORE_U8(ctx.r9.u32 + 6670, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68AC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68AD8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,4600
	ctx.r5.s64 = ctx.r11.s64 + 4600;
	// addi r4,r10,-10016
	ctx.r4.s64 = ctx.r10.s64 + -10016;
	// bl 0x826a61b0
	ctx.lr = 0x82F68AEC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6729(r9)
	REX_STORE_U8(ctx.r9.u32 + 6729, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68B08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68B18;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,4760
	ctx.r5.s64 = ctx.r11.s64 + 4760;
	// addi r4,r10,-9996
	ctx.r4.s64 = ctx.r10.s64 + -9996;
	// bl 0x826a61b0
	ctx.lr = 0x82F68B2C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6727(r9)
	REX_STORE_U8(ctx.r9.u32 + 6727, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68B48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68B58;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,4968
	ctx.r5.s64 = ctx.r11.s64 + 4968;
	// addi r4,r10,-9972
	ctx.r4.s64 = ctx.r10.s64 + -9972;
	// bl 0x826a61b0
	ctx.lr = 0x82F68B6C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6734(r9)
	REX_STORE_U8(ctx.r9.u32 + 6734, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68B88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68B98;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,5168
	ctx.r5.s64 = ctx.r11.s64 + 5168;
	// addi r4,r10,-9960
	ctx.r4.s64 = ctx.r10.s64 + -9960;
	// bl 0x826a61b0
	ctx.lr = 0x82F68BAC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6700(r9)
	REX_STORE_U8(ctx.r9.u32 + 6700, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68BC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68BD8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,5328
	ctx.r5.s64 = ctx.r11.s64 + 5328;
	// addi r4,r10,-9948
	ctx.r4.s64 = ctx.r10.s64 + -9948;
	// bl 0x826a61b0
	ctx.lr = 0x82F68BEC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6688(r9)
	REX_STORE_U8(ctx.r9.u32 + 6688, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68C08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68C18;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,5488
	ctx.r5.s64 = ctx.r11.s64 + 5488;
	// addi r4,r10,-9932
	ctx.r4.s64 = ctx.r10.s64 + -9932;
	// bl 0x826a61b0
	ctx.lr = 0x82F68C2C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6702(r9)
	REX_STORE_U8(ctx.r9.u32 + 6702, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68C48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68C58;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,5648
	ctx.r5.s64 = ctx.r11.s64 + 5648;
	// addi r4,r10,-9916
	ctx.r4.s64 = ctx.r10.s64 + -9916;
	// bl 0x826a61b0
	ctx.lr = 0x82F68C6C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6747(r9)
	REX_STORE_U8(ctx.r9.u32 + 6747, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68C88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68C98;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,5808
	ctx.r5.s64 = ctx.r11.s64 + 5808;
	// addi r4,r10,-9896
	ctx.r4.s64 = ctx.r10.s64 + -9896;
	// bl 0x826a61b0
	ctx.lr = 0x82F68CAC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6666(r9)
	REX_STORE_U8(ctx.r9.u32 + 6666, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68CC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68CD8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,5968
	ctx.r5.s64 = ctx.r11.s64 + 5968;
	// addi r4,r10,-9872
	ctx.r4.s64 = ctx.r10.s64 + -9872;
	// bl 0x826a61b0
	ctx.lr = 0x82F68CEC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6683(r9)
	REX_STORE_U8(ctx.r9.u32 + 6683, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68D08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68D18;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6128
	ctx.r5.s64 = ctx.r11.s64 + 6128;
	// addi r4,r10,-9844
	ctx.r4.s64 = ctx.r10.s64 + -9844;
	// bl 0x826a61b0
	ctx.lr = 0x82F68D2C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6682(r9)
	REX_STORE_U8(ctx.r9.u32 + 6682, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68D48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68D58;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6288
	ctx.r5.s64 = ctx.r11.s64 + 6288;
	// addi r4,r10,-9816
	ctx.r4.s64 = ctx.r10.s64 + -9816;
	// bl 0x826a61b0
	ctx.lr = 0x82F68D6C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6677(r9)
	REX_STORE_U8(ctx.r9.u32 + 6677, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68D88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68D98;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6448
	ctx.r5.s64 = ctx.r11.s64 + 6448;
	// addi r4,r10,-9788
	ctx.r4.s64 = ctx.r10.s64 + -9788;
	// bl 0x826a61b0
	ctx.lr = 0x82F68DAC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6669(r9)
	REX_STORE_U8(ctx.r9.u32 + 6669, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68DC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68DD8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6608
	ctx.r5.s64 = ctx.r11.s64 + 6608;
	// addi r4,r10,-9760
	ctx.r4.s64 = ctx.r10.s64 + -9760;
	// bl 0x826a61b0
	ctx.lr = 0x82F68DEC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6749(r9)
	REX_STORE_U8(ctx.r9.u32 + 6749, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68E18;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6768
	ctx.r5.s64 = ctx.r11.s64 + 6768;
	// addi r4,r10,-9728
	ctx.r4.s64 = ctx.r10.s64 + -9728;
	// bl 0x826a61b0
	ctx.lr = 0x82F68E2C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6721(r9)
	REX_STORE_U8(ctx.r9.u32 + 6721, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68E48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68E58;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,6928
	ctx.r5.s64 = ctx.r11.s64 + 6928;
	// addi r4,r10,-9708
	ctx.r4.s64 = ctx.r10.s64 + -9708;
	// bl 0x826a61b0
	ctx.lr = 0x82F68E6C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6731(r9)
	REX_STORE_U8(ctx.r9.u32 + 6731, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68E88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68E98;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,7088
	ctx.r5.s64 = ctx.r11.s64 + 7088;
	// addi r4,r10,-9688
	ctx.r4.s64 = ctx.r10.s64 + -9688;
	// bl 0x826a61b0
	ctx.lr = 0x82F68EAC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6678(r9)
	REX_STORE_U8(ctx.r9.u32 + 6678, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68EC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a37a8
	ctx.lr = 0x82F68ED8;
	sub_826A37A8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,7248
	ctx.r5.s64 = ctx.r11.s64 + 7248;
	// addi r4,r10,-9672
	ctx.r4.s64 = ctx.r10.s64 + -9672;
	// bl 0x826a61b0
	ctx.lr = 0x82F68EEC;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6662(r9)
	REX_STORE_U8(ctx.r9.u32 + 6662, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68F08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x826a36e8
	ctx.lr = 0x82F68F18;
	sub_826A36E8(ctx, base);
	// lis r11,-32035
	ctx.r11.s64 = -2099445760;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r5,r11,7408
	ctx.r5.s64 = ctx.r11.s64 + 7408;
	// addi r4,r10,-9648
	ctx.r4.s64 = ctx.r10.s64 + -9648;
	// bl 0x826a61b0
	ctx.lr = 0x82F68F2C;
	sub_826A61B0(ctx, base);
	// lis r9,-31993
	ctx.r9.s64 = -2096693248;
	// stb r3,6733(r9)
	REX_STORE_U8(ctx.r9.u32 + 6733, ctx.r3.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68F48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,6784
	ctx.r7.s64 = ctx.r8.s64 + 6784;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68F70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,6752
	ctx.r8.s64 = ctx.r10.s64 + 6752;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68F90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31710
	ctx.r11.s64 = -2078146560;
	// lis r9,-13326
	ctx.r9.s64 = -873332736;
	// ori r10,r11,8997
	ctx.r10.u64 = ctx.r11.u64 | 8997;
	// ori r8,r9,40164
	ctx.r8.u64 = ctx.r9.u64 | 40164;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// rldimi r10,r8,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// li r7,435
	ctx.r7.s64 = 435;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r9,r11,-9384
	ctx.r9.s64 = ctx.r11.s64 + -9384;
	// li r11,73
	ctx.r11.s64 = 73;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
loc_82F68FBC:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// mulld r5,r10,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r10.u64 * ctx.r7.u64);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// xor r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f68fbc
	if (!ctx.cr6.eq) goto loc_82F68FBC;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// std r10,6712(r11)
	REX_STORE_U64(ctx.r11.u32 + 6712, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F68FE8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-9364
	ctx.r4.s64 = ctx.r11.s64 + -9364;
	// addi r3,r10,6736
	ctx.r3.s64 = ctx.r10.s64 + 6736;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F69000) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-9348
	ctx.r4.s64 = ctx.r11.s64 + -9348;
	// addi r3,r10,6704
	ctx.r3.s64 = ctx.r10.s64 + 6704;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F69018) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-20196
	ctx.r9.s64 = ctx.r11.s64 + -20196;
	// addi r8,r10,6832
	ctx.r8.s64 = ctx.r10.s64 + 6832;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69038) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-20188
	ctx.r9.s64 = ctx.r11.s64 + -20188;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,65
	ctx.r11.s64 = 65;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F69054:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f69054
	if (!ctx.cr6.eq) goto loc_82F69054;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6804(r11)
	REX_STORE_U32(ctx.r11.u32 + 6804, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69078) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-20080
	ctx.r9.s64 = ctx.r11.s64 + -20080;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,67
	ctx.r11.s64 = 67;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F69094:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f69094
	if (!ctx.cr6.eq) goto loc_82F69094;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6800(r11)
	REX_STORE_U32(ctx.r11.u32 + 6800, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F690B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,6848
	ctx.r7.s64 = ctx.r8.s64 + 6848;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F690E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,6816
	ctx.r8.s64 = ctx.r10.s64 + 6816;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69100) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-28572
	ctx.r9.s64 = ctx.r11.s64 + -28572;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,65
	ctx.r11.s64 = 65;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F6911C:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f6911c
	if (!ctx.cr6.eq) goto loc_82F6911C;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6916(r11)
	REX_STORE_U32(ctx.r11.u32 + 6916, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69140) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,-28564
	ctx.r9.s64 = ctx.r11.s64 + -28564;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,67
	ctx.r11.s64 = 67;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F6915C:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f6915c
	if (!ctx.cr6.eq) goto loc_82F6915C;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,6912(r11)
	REX_STORE_U32(ctx.r11.u32 + 6912, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69180) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31710
	ctx.r11.s64 = -2078146560;
	// lis r9,-13326
	ctx.r9.s64 = -873332736;
	// ori r10,r11,8997
	ctx.r10.u64 = ctx.r11.u64 | 8997;
	// ori r8,r9,40164
	ctx.r8.u64 = ctx.r9.u64 | 40164;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// rldimi r10,r8,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// li r7,435
	ctx.r7.s64 = 435;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r9,r11,-28552
	ctx.r9.s64 = ctx.r11.s64 + -28552;
	// li r11,73
	ctx.r11.s64 = 73;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
loc_82F691AC:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// mulld r5,r10,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r10.u64 * ctx.r7.u64);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// xor r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f691ac
	if (!ctx.cr6.eq) goto loc_82F691AC;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// std r10,6928(r11)
	REX_STORE_U64(ctx.r11.u32 + 6928, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F691D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-28532
	ctx.r4.s64 = ctx.r11.s64 + -28532;
	// addi r3,r10,6936
	ctx.r3.s64 = ctx.r10.s64 + 6936;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F691F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-28516
	ctx.r4.s64 = ctx.r11.s64 + -28516;
	// addi r3,r10,6920
	ctx.r3.s64 = ctx.r10.s64 + 6920;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F69208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28580
	ctx.r9.s64 = ctx.r11.s64 + -28580;
	// addi r8,r10,6960
	ctx.r8.s64 = ctx.r10.s64 + 6960;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69228) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,6976
	ctx.r7.s64 = ctx.r8.s64 + 6976;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,6944
	ctx.r8.s64 = ctx.r10.s64 + 6944;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69270) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// lwz r11,-18812(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -18812);
	// rlwinm r11,r11,0,0,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFF000000;
	// stw r11,-18812(r10)
	REX_STORE_U32(ctx.r10.u32 + -18812, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69288) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,-28328
	ctx.r4.s64 = ctx.r11.s64 + -28328;
	// addi r3,r10,6872
	ctx.r3.s64 = ctx.r10.s64 + 6872;
	// b 0x82746a10
	sub_82746A10(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F692A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r11,-28308
	ctx.r3.s64 = ctx.r11.s64 + -28308;
	// bl 0x82b4b300
	ctx.lr = 0x82F692BC;
	sub_82B4B300(ctx, base);
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// std r3,6864(r10)
	REX_STORE_U64(ctx.r10.u32 + 6864, ctx.r3.u64);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F692D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,28216
	ctx.r9.s64 = ctx.r11.s64 + 28216;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,65
	ctx.r11.s64 = 65;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F692F4:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f692f4
	if (!ctx.cr6.eq) goto loc_82F692F4;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,7004(r11)
	REX_STORE_U32(ctx.r11.u32 + 7004, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69318) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,28224
	ctx.r9.s64 = ctx.r11.s64 + 28224;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,67
	ctx.r11.s64 = 67;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F69334:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f69334
	if (!ctx.cr6.eq) goto loc_82F69334;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,7000(r11)
	REX_STORE_U32(ctx.r11.u32 + 7000, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69358) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31710
	ctx.r11.s64 = -2078146560;
	// lis r9,-13326
	ctx.r9.s64 = -873332736;
	// ori r10,r11,8997
	ctx.r10.u64 = ctx.r11.u64 | 8997;
	// ori r8,r9,40164
	ctx.r8.u64 = ctx.r9.u64 | 40164;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// rldimi r10,r8,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// li r7,435
	ctx.r7.s64 = 435;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r9,r11,28236
	ctx.r9.s64 = ctx.r11.s64 + 28236;
	// li r11,73
	ctx.r11.s64 = 73;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
loc_82F69384:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// mulld r5,r10,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r10.u64 * ctx.r7.u64);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// xor r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f69384
	if (!ctx.cr6.eq) goto loc_82F69384;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// std r10,7016(r11)
	REX_STORE_U64(ctx.r11.u32 + 7016, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F693B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,28256
	ctx.r4.s64 = ctx.r11.s64 + 28256;
	// addi r3,r10,7024
	ctx.r3.s64 = ctx.r10.s64 + 7024;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F693C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,28272
	ctx.r4.s64 = ctx.r11.s64 + 28272;
	// addi r3,r10,7008
	ctx.r3.s64 = ctx.r10.s64 + 7008;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F693E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,28208
	ctx.r9.s64 = ctx.r11.s64 + 28208;
	// addi r8,r10,7056
	ctx.r8.s64 = ctx.r10.s64 + 7056;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,7072
	ctx.r7.s64 = ctx.r8.s64 + 7072;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,7040
	ctx.r8.s64 = ctx.r10.s64 + 7040;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69448) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r3,r11,28928
	ctx.r3.s64 = ctx.r11.s64 + 28928;
	// bl 0x82b4b300
	ctx.lr = 0x82F69464;
	sub_82B4B300(ctx, base);
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// std r3,6992(r10)
	REX_STORE_U64(ctx.r10.u32 + 6992, ctx.r3.u64);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69480) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,14924
	ctx.r4.s64 = ctx.r11.s64 + 14924;
	// addi r3,r10,7088
	ctx.r3.s64 = ctx.r10.s64 + 7088;
	// b 0x823b35e8
	sub_823B35E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F69498) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,14948
	ctx.r4.s64 = ctx.r11.s64 + 14948;
	// addi r3,r10,7208
	ctx.r3.s64 = ctx.r10.s64 + 7208;
	// b 0x823b35e8
	sub_823B35E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F694B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,14972
	ctx.r4.s64 = ctx.r11.s64 + 14972;
	// addi r3,r10,7160
	ctx.r3.s64 = ctx.r10.s64 + 7160;
	// b 0x823b35e8
	sub_823B35E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F694C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,14984
	ctx.r4.s64 = ctx.r11.s64 + 14984;
	// addi r3,r10,7136
	ctx.r3.s64 = ctx.r10.s64 + 7136;
	// b 0x823b35e8
	sub_823B35E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F694E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,15004
	ctx.r4.s64 = ctx.r11.s64 + 15004;
	// addi r3,r10,7112
	ctx.r3.s64 = ctx.r10.s64 + 7112;
	// b 0x823b35e8
	sub_823B35E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F694F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,15388
	ctx.r9.s64 = ctx.r11.s64 + 15388;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,65
	ctx.r11.s64 = 65;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F69514:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f69514
	if (!ctx.cr6.eq) goto loc_82F69514;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,7188(r11)
	REX_STORE_U32(ctx.r11.u32 + 7188, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69538) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-32484
	ctx.r10.s64 = -2128871424;
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// addi r9,r11,15396
	ctx.r9.s64 = ctx.r11.s64 + 15396;
	// ori r10,r10,40389
	ctx.r10.u64 = ctx.r10.u64 | 40389;
	// li r11,67
	ctx.r11.s64 = 67;
	// ori r7,r8,403
	ctx.r7.u64 = ctx.r8.u64 | 403;
loc_82F69554:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// xor r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f69554
	if (!ctx.cr6.eq) goto loc_82F69554;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// stw r10,7184(r11)
	REX_STORE_U32(ctx.r11.u32 + 7184, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69578) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31710
	ctx.r11.s64 = -2078146560;
	// lis r9,-13326
	ctx.r9.s64 = -873332736;
	// ori r10,r11,8997
	ctx.r10.u64 = ctx.r11.u64 | 8997;
	// ori r8,r9,40164
	ctx.r8.u64 = ctx.r9.u64 | 40164;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// rldimi r10,r8,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// li r7,435
	ctx.r7.s64 = 435;
	// li r8,256
	ctx.r8.s64 = 256;
	// addi r9,r11,15408
	ctx.r9.s64 = ctx.r11.s64 + 15408;
	// li r11,73
	ctx.r11.s64 = 73;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
loc_82F695A4:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// mulld r5,r10,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r10.u64 * ctx.r7.u64);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// xor r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82f695a4
	if (!ctx.cr6.eq) goto loc_82F695A4;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// std r10,7200(r11)
	REX_STORE_U64(ctx.r11.u32 + 7200, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F695D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,15428
	ctx.r4.s64 = ctx.r11.s64 + 15428;
	// addi r3,r10,7232
	ctx.r3.s64 = ctx.r10.s64 + 7232;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F695E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,15444
	ctx.r4.s64 = ctx.r11.s64 + 15444;
	// addi r3,r10,7192
	ctx.r3.s64 = ctx.r10.s64 + 7192;
	// b 0x82372768
	sub_82372768(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F69600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,14916
	ctx.r9.s64 = ctx.r11.s64 + 14916;
	// addi r8,r10,7296
	ctx.r8.s64 = ctx.r10.s64 + 7296;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69620) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32209
	ctx.r11.s64 = -2110849024;
	// li r10,2216
	ctx.r10.s64 = 2216;
	// addi r9,r11,12960
	ctx.r9.s64 = ctx.r11.s64 + 12960;
	// lis r8,-31993
	ctx.r8.s64 = -2096693248;
	// addi r7,r8,7312
	ctx.r7.s64 = ctx.r8.s64 + 7312;
	// lvlx128 v63,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r11,-28336
	ctx.r9.s64 = ctx.r11.s64 + -28336;
	// addi r8,r10,7280
	ctx.r8.s64 = ctx.r10.s64 + 7280;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F69668) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r11,15952
	ctx.r3.s64 = ctx.r11.s64 + 15952;
	// bl 0x82b4b300
	ctx.lr = 0x82F69684;
	sub_82B4B300(ctx, base);
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// std r3,7240(r10)
	REX_STORE_U64(ctx.r10.u32 + 7240, ctx.r3.u64);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F696A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,16804
	ctx.r4.s64 = ctx.r11.s64 + 16804;
	// addi r3,r10,7248
	ctx.r3.s64 = ctx.r10.s64 + 7248;
	// b 0x823b35e8
	sub_823B35E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F696B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4352
	ctx.r3.s64 = ctx.r11.s64 + 4352;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F696C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4432
	ctx.r3.s64 = ctx.r11.s64 + 4432;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F696D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// li r10,140
	ctx.r10.s64 = 140;
	// addi r11,r11,7328
	ctx.r11.s64 = ctx.r11.s64 + 7328;
	// lis r9,-32005
	ctx.r9.s64 = -2097479680;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// addi r9,r9,-25728
	ctx.r9.s64 = ctx.r9.s64 + -25728;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82F696F4:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82f696f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F696F4;
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4464
	ctx.r3.s64 = ctx.r11.s64 + 4464;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F69708) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82f274c0
	ctx.lr = 0x82F69710;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// li r5,246
	ctx.r5.s64 = 246;
	// addi r31,r11,-7088
	ctx.r31.s64 = ctx.r11.s64 + -7088;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,18
	ctx.r3.s64 = ctx.r31.s64 + 18;
	// bl 0x82f273f0
	ctx.lr = 0x82F6972C;
	sub_82F273F0(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r30,r10,9896
	ctx.r30.s64 = ctx.r10.s64 + 9896;
	// li r10,6
	ctx.r10.s64 = 6;
	// sth r11,264(r31)
	REX_STORE_U16(ctx.r31.u32 + 264, ctx.r11.u16);
	// sth r11,268(r31)
	REX_STORE_U16(ctx.r31.u32 + 268, ctx.r11.u16);
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r10,266(r31)
	REX_STORE_U16(ctx.r31.u32 + 266, ctx.r10.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,270(r31)
	REX_STORE_U16(ctx.r31.u32 + 270, ctx.r9.u16);
	// lwz r11,1488(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1488);
	// addi r3,r31,279
	ctx.r3.s64 = ctx.r31.s64 + 279;
	// lhz r10,1492(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 1492);
	// lbz r8,1494(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1494);
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// sth r10,276(r31)
	REX_STORE_U16(ctx.r31.u32 + 276, ctx.r10.u16);
	// stb r8,278(r31)
	REX_STORE_U8(ctx.r31.u32 + 278, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69778;
	sub_82F273F0(ctx, base);
	// lwz r7,1472(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1472);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1476(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1476);
	// li r10,13
	ctx.r10.s64 = 13;
	// lwz r29,1480(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1480);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r28,1484(r30)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r30.u32 + 1484);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,242
	ctx.r5.s64 = 242;
	// sth r11,528(r31)
	REX_STORE_U16(ctx.r31.u32 + 528, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,530(r31)
	REX_STORE_U16(ctx.r31.u32 + 530, ctx.r10.u16);
	// addi r3,r31,550
	ctx.r3.s64 = ctx.r31.s64 + 550;
	// sth r9,532(r31)
	REX_STORE_U16(ctx.r31.u32 + 532, ctx.r9.u16);
	// sth r8,534(r31)
	REX_STORE_U16(ctx.r31.u32 + 534, ctx.r8.u16);
	// stw r7,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r7.u32);
	// stw r6,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r6.u32);
	// stw r29,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r29.u32);
	// sth r28,548(r31)
	REX_STORE_U16(ctx.r31.u32 + 548, ctx.r28.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F697C8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1464(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1464);
	// lhz r7,1468(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 1468);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,792(r31)
	REX_STORE_U16(ctx.r31.u32 + 792, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,794(r31)
	REX_STORE_U16(ctx.r31.u32 + 794, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,796(r31)
	REX_STORE_U16(ctx.r31.u32 + 796, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,798(r31)
	REX_STORE_U16(ctx.r31.u32 + 798, ctx.r11.u16);
	// addi r3,r31,806
	ctx.r3.s64 = ctx.r31.s64 + 806;
	// stw r8,800(r31)
	REX_STORE_U32(ctx.r31.u32 + 800, ctx.r8.u32);
	// sth r7,804(r31)
	REX_STORE_U16(ctx.r31.u32 + 804, ctx.r7.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F69808;
	sub_82F273F0(ctx, base);
	// lwz r6,1452(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1452);
	// lwz r7,1456(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1456);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r29,1460(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1460);
	// li r10,11
	ctx.r10.s64 = 11;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,1056(r31)
	REX_STORE_U16(ctx.r31.u32 + 1056, ctx.r11.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r10,1058(r31)
	REX_STORE_U16(ctx.r31.u32 + 1058, ctx.r10.u16);
	// li r5,244
	ctx.r5.s64 = 244;
	// sth r9,1060(r31)
	REX_STORE_U16(ctx.r31.u32 + 1060, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r8,1062(r31)
	REX_STORE_U16(ctx.r31.u32 + 1062, ctx.r8.u16);
	// addi r3,r31,1076
	ctx.r3.s64 = ctx.r31.s64 + 1076;
	// stw r6,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r6.u32);
	// stw r7,1068(r31)
	REX_STORE_U32(ctx.r31.u32 + 1068, ctx.r7.u32);
	// stw r29,1072(r31)
	REX_STORE_U32(ctx.r31.u32 + 1072, ctx.r29.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F69850;
	sub_82F273F0(ctx, base);
	// lwz r6,1440(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1440);
	// lwz r7,1444(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1444);
	// lhz r29,1448(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 1448);
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r28,1450(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 1450);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,1320(r31)
	REX_STORE_U16(ctx.r31.u32 + 1320, ctx.r11.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r10,1322(r31)
	REX_STORE_U16(ctx.r31.u32 + 1322, ctx.r10.u16);
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r9,1324(r31)
	REX_STORE_U16(ctx.r31.u32 + 1324, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r8,1326(r31)
	REX_STORE_U16(ctx.r31.u32 + 1326, ctx.r8.u16);
	// addi r3,r31,1339
	ctx.r3.s64 = ctx.r31.s64 + 1339;
	// stw r6,1328(r31)
	REX_STORE_U32(ctx.r31.u32 + 1328, ctx.r6.u32);
	// stw r7,1332(r31)
	REX_STORE_U32(ctx.r31.u32 + 1332, ctx.r7.u32);
	// sth r29,1336(r31)
	REX_STORE_U16(ctx.r31.u32 + 1336, ctx.r29.u16);
	// stb r28,1338(r31)
	REX_STORE_U8(ctx.r31.u32 + 1338, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F698A0;
	sub_82F273F0(ctx, base);
	// lwz r6,1424(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1424);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,1428(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1428);
	// li r10,13
	ctx.r10.s64 = 13;
	// lwz r29,1432(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1432);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r28,1436(r30)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r30.u32 + 1436);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,242
	ctx.r5.s64 = 242;
	// sth r11,1584(r31)
	REX_STORE_U16(ctx.r31.u32 + 1584, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,1586(r31)
	REX_STORE_U16(ctx.r31.u32 + 1586, ctx.r10.u16);
	// addi r3,r31,1606
	ctx.r3.s64 = ctx.r31.s64 + 1606;
	// sth r9,1588(r31)
	REX_STORE_U16(ctx.r31.u32 + 1588, ctx.r9.u16);
	// sth r8,1590(r31)
	REX_STORE_U16(ctx.r31.u32 + 1590, ctx.r8.u16);
	// stw r6,1592(r31)
	REX_STORE_U32(ctx.r31.u32 + 1592, ctx.r6.u32);
	// stw r7,1596(r31)
	REX_STORE_U32(ctx.r31.u32 + 1596, ctx.r7.u32);
	// stw r29,1600(r31)
	REX_STORE_U32(ctx.r31.u32 + 1600, ctx.r29.u32);
	// sth r28,1604(r31)
	REX_STORE_U16(ctx.r31.u32 + 1604, ctx.r28.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F698F0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1416(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1416);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,1848(r31)
	REX_STORE_U16(ctx.r31.u32 + 1848, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,1850(r31)
	REX_STORE_U16(ctx.r31.u32 + 1850, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,1852(r31)
	REX_STORE_U16(ctx.r31.u32 + 1852, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,1854(r31)
	REX_STORE_U16(ctx.r31.u32 + 1854, ctx.r11.u16);
	// addi r3,r31,1864
	ctx.r3.s64 = ctx.r31.s64 + 1864;
	// std r8,1856(r31)
	REX_STORE_U64(ctx.r31.u32 + 1856, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69928;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1408(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1408);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,2112(r31)
	REX_STORE_U16(ctx.r31.u32 + 2112, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,2114(r31)
	REX_STORE_U16(ctx.r31.u32 + 2114, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,2116(r31)
	REX_STORE_U16(ctx.r31.u32 + 2116, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,2118(r31)
	REX_STORE_U16(ctx.r31.u32 + 2118, ctx.r11.u16);
	// addi r3,r31,2128
	ctx.r3.s64 = ctx.r31.s64 + 2128;
	// std r8,2120(r31)
	REX_STORE_U64(ctx.r31.u32 + 2120, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69960;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r6,1392(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1392);
	// sth r11,2376(r31)
	REX_STORE_U16(ctx.r31.u32 + 2376, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r8,1396(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1396);
	// lwz r7,1400(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1400);
	// li r5,243
	ctx.r5.s64 = 243;
	// lbz r29,1404(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 1404);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,2378(r31)
	REX_STORE_U16(ctx.r31.u32 + 2378, ctx.r10.u16);
	// addi r3,r31,2397
	ctx.r3.s64 = ctx.r31.s64 + 2397;
	// sth r9,2380(r31)
	REX_STORE_U16(ctx.r31.u32 + 2380, ctx.r9.u16);
	// sth r11,2382(r31)
	REX_STORE_U16(ctx.r31.u32 + 2382, ctx.r11.u16);
	// stw r6,2384(r31)
	REX_STORE_U32(ctx.r31.u32 + 2384, ctx.r6.u32);
	// stw r8,2388(r31)
	REX_STORE_U32(ctx.r31.u32 + 2388, ctx.r8.u32);
	// stw r7,2392(r31)
	REX_STORE_U32(ctx.r31.u32 + 2392, ctx.r7.u32);
	// stb r29,2396(r31)
	REX_STORE_U8(ctx.r31.u32 + 2396, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F699B0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1384(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1384);
	// lhz r8,1388(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1388);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,2640(r31)
	REX_STORE_U16(ctx.r31.u32 + 2640, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,2642(r31)
	REX_STORE_U16(ctx.r31.u32 + 2642, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,2644(r31)
	REX_STORE_U16(ctx.r31.u32 + 2644, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,2646(r31)
	REX_STORE_U16(ctx.r31.u32 + 2646, ctx.r11.u16);
	// addi r3,r31,2654
	ctx.r3.s64 = ctx.r31.s64 + 2654;
	// stw r6,2648(r31)
	REX_STORE_U32(ctx.r31.u32 + 2648, ctx.r6.u32);
	// sth r8,2652(r31)
	REX_STORE_U16(ctx.r31.u32 + 2652, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F699F0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,1376(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1376);
	// li r10,5
	ctx.r10.s64 = 5;
	// lhz r6,1380(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1380);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,2904(r31)
	REX_STORE_U16(ctx.r31.u32 + 2904, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r10,2906(r31)
	REX_STORE_U16(ctx.r31.u32 + 2906, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,2908(r31)
	REX_STORE_U16(ctx.r31.u32 + 2908, ctx.r9.u16);
	// addi r3,r31,2918
	ctx.r3.s64 = ctx.r31.s64 + 2918;
	// sth r11,2910(r31)
	REX_STORE_U16(ctx.r31.u32 + 2910, ctx.r11.u16);
	// stw r7,2912(r31)
	REX_STORE_U32(ctx.r31.u32 + 2912, ctx.r7.u32);
	// sth r6,2916(r31)
	REX_STORE_U16(ctx.r31.u32 + 2916, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F69A30;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1364(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1364);
	// lwz r7,1368(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1368);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r6,1372(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1372);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,3168(r31)
	REX_STORE_U16(ctx.r31.u32 + 3168, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r10,3170(r31)
	REX_STORE_U16(ctx.r31.u32 + 3170, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,3172(r31)
	REX_STORE_U16(ctx.r31.u32 + 3172, ctx.r9.u16);
	// addi r3,r31,3185
	ctx.r3.s64 = ctx.r31.s64 + 3185;
	// sth r11,3174(r31)
	REX_STORE_U16(ctx.r31.u32 + 3174, ctx.r11.u16);
	// stw r8,3176(r31)
	REX_STORE_U32(ctx.r31.u32 + 3176, ctx.r8.u32);
	// stw r7,3180(r31)
	REX_STORE_U32(ctx.r31.u32 + 3180, ctx.r7.u32);
	// stb r6,3184(r31)
	REX_STORE_U8(ctx.r31.u32 + 3184, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69A78;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1356(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1356);
	// lhz r7,1360(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 1360);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r6,1362(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1362);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,3432(r31)
	REX_STORE_U16(ctx.r31.u32 + 3432, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,3434(r31)
	REX_STORE_U16(ctx.r31.u32 + 3434, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,3436(r31)
	REX_STORE_U16(ctx.r31.u32 + 3436, ctx.r9.u16);
	// addi r3,r31,3447
	ctx.r3.s64 = ctx.r31.s64 + 3447;
	// sth r11,3438(r31)
	REX_STORE_U16(ctx.r31.u32 + 3438, ctx.r11.u16);
	// stw r8,3440(r31)
	REX_STORE_U32(ctx.r31.u32 + 3440, ctx.r8.u32);
	// sth r7,3444(r31)
	REX_STORE_U16(ctx.r31.u32 + 3444, ctx.r7.u16);
	// stb r6,3446(r31)
	REX_STORE_U8(ctx.r31.u32 + 3446, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69AC0;
	sub_82F273F0(ctx, base);
	// lwz r7,1344(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1344);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1348(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1348);
	// li r10,9
	ctx.r10.s64 = 9;
	// lhz r29,1352(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 1352);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,246
	ctx.r5.s64 = 246;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,3696(r31)
	REX_STORE_U16(ctx.r31.u32 + 3696, ctx.r11.u16);
	// addi r3,r31,3714
	ctx.r3.s64 = ctx.r31.s64 + 3714;
	// sth r10,3698(r31)
	REX_STORE_U16(ctx.r31.u32 + 3698, ctx.r10.u16);
	// sth r9,3700(r31)
	REX_STORE_U16(ctx.r31.u32 + 3700, ctx.r9.u16);
	// sth r8,3702(r31)
	REX_STORE_U16(ctx.r31.u32 + 3702, ctx.r8.u16);
	// stw r7,3704(r31)
	REX_STORE_U32(ctx.r31.u32 + 3704, ctx.r7.u32);
	// stw r6,3708(r31)
	REX_STORE_U32(ctx.r31.u32 + 3708, ctx.r6.u32);
	// sth r29,3712(r31)
	REX_STORE_U16(ctx.r31.u32 + 3712, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F69B08;
	sub_82F273F0(ctx, base);
	// lwz r7,1328(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1328);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1332(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1332);
	// li r10,13
	ctx.r10.s64 = 13;
	// lwz r29,1336(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1336);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r28,1340(r30)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r30.u32 + 1340);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,242
	ctx.r5.s64 = 242;
	// sth r11,3960(r31)
	REX_STORE_U16(ctx.r31.u32 + 3960, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,3962(r31)
	REX_STORE_U16(ctx.r31.u32 + 3962, ctx.r10.u16);
	// addi r3,r31,3982
	ctx.r3.s64 = ctx.r31.s64 + 3982;
	// sth r9,3964(r31)
	REX_STORE_U16(ctx.r31.u32 + 3964, ctx.r9.u16);
	// sth r8,3966(r31)
	REX_STORE_U16(ctx.r31.u32 + 3966, ctx.r8.u16);
	// stw r7,3968(r31)
	REX_STORE_U32(ctx.r31.u32 + 3968, ctx.r7.u32);
	// stw r6,3972(r31)
	REX_STORE_U32(ctx.r31.u32 + 3972, ctx.r6.u32);
	// stw r29,3976(r31)
	REX_STORE_U32(ctx.r31.u32 + 3976, ctx.r29.u32);
	// sth r28,3980(r31)
	REX_STORE_U16(ctx.r31.u32 + 3980, ctx.r28.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F69B58;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1320(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1320);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,4224(r31)
	REX_STORE_U16(ctx.r31.u32 + 4224, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,4226(r31)
	REX_STORE_U16(ctx.r31.u32 + 4226, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,4228(r31)
	REX_STORE_U16(ctx.r31.u32 + 4228, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,4230(r31)
	REX_STORE_U16(ctx.r31.u32 + 4230, ctx.r11.u16);
	// addi r3,r31,4240
	ctx.r3.s64 = ctx.r31.s64 + 4240;
	// std r8,4232(r31)
	REX_STORE_U64(ctx.r31.u32 + 4232, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69B90;
	sub_82F273F0(ctx, base);
	// lwz r7,1304(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1304);
	// lwz r6,1308(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1308);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r29,1312(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1312);
	// li r10,12
	ctx.r10.s64 = 12;
	// lbz r28,1316(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 1316);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,4488(r31)
	REX_STORE_U16(ctx.r31.u32 + 4488, ctx.r11.u16);
	// li r5,243
	ctx.r5.s64 = 243;
	// sth r10,4490(r31)
	REX_STORE_U16(ctx.r31.u32 + 4490, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,4492(r31)
	REX_STORE_U16(ctx.r31.u32 + 4492, ctx.r9.u16);
	// addi r3,r31,4509
	ctx.r3.s64 = ctx.r31.s64 + 4509;
	// sth r8,4494(r31)
	REX_STORE_U16(ctx.r31.u32 + 4494, ctx.r8.u16);
	// stw r7,4496(r31)
	REX_STORE_U32(ctx.r31.u32 + 4496, ctx.r7.u32);
	// stw r6,4500(r31)
	REX_STORE_U32(ctx.r31.u32 + 4500, ctx.r6.u32);
	// stw r29,4504(r31)
	REX_STORE_U32(ctx.r31.u32 + 4504, ctx.r29.u32);
	// stb r28,4508(r31)
	REX_STORE_U8(ctx.r31.u32 + 4508, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69BE0;
	sub_82F273F0(ctx, base);
	// lwz r3,1296(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 1296);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r8,1300(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1300);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,4752(r31)
	REX_STORE_U16(ctx.r31.u32 + 4752, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,4754(r31)
	REX_STORE_U16(ctx.r31.u32 + 4754, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,4756(r31)
	REX_STORE_U16(ctx.r31.u32 + 4756, ctx.r9.u16);
	// stw r3,4760(r31)
	REX_STORE_U32(ctx.r31.u32 + 4760, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,4766
	ctx.r3.s64 = ctx.r31.s64 + 4766;
	// sth r11,4758(r31)
	REX_STORE_U16(ctx.r31.u32 + 4758, ctx.r11.u16);
	// sth r8,4764(r31)
	REX_STORE_U16(ctx.r31.u32 + 4764, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F69C20;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1292(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1292);
	// li r10,3
	ctx.r10.s64 = 3;
	// sth r11,5016(r31)
	REX_STORE_U16(ctx.r31.u32 + 5016, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,5018(r31)
	REX_STORE_U16(ctx.r31.u32 + 5018, ctx.r10.u16);
	// li r5,252
	ctx.r5.s64 = 252;
	// sth r9,5020(r31)
	REX_STORE_U16(ctx.r31.u32 + 5020, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,5022(r31)
	REX_STORE_U16(ctx.r31.u32 + 5022, ctx.r11.u16);
	// addi r3,r31,5028
	ctx.r3.s64 = ctx.r31.s64 + 5028;
	// stw r8,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r8.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F69C58;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,1284(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1284);
	// li r10,4
	ctx.r10.s64 = 4;
	// lbz r6,1288(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1288);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,5280(r31)
	REX_STORE_U16(ctx.r31.u32 + 5280, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r10,5282(r31)
	REX_STORE_U16(ctx.r31.u32 + 5282, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,5284(r31)
	REX_STORE_U16(ctx.r31.u32 + 5284, ctx.r9.u16);
	// addi r3,r31,5293
	ctx.r3.s64 = ctx.r31.s64 + 5293;
	// sth r11,5286(r31)
	REX_STORE_U16(ctx.r31.u32 + 5286, ctx.r11.u16);
	// stw r7,5288(r31)
	REX_STORE_U32(ctx.r31.u32 + 5288, ctx.r7.u32);
	// stb r6,5292(r31)
	REX_STORE_U8(ctx.r31.u32 + 5292, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69C98;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1272(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1272);
	// lwz r7,1276(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1276);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r6,1280(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1280);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,5544(r31)
	REX_STORE_U16(ctx.r31.u32 + 5544, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r10,5546(r31)
	REX_STORE_U16(ctx.r31.u32 + 5546, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,5548(r31)
	REX_STORE_U16(ctx.r31.u32 + 5548, ctx.r9.u16);
	// addi r3,r31,5561
	ctx.r3.s64 = ctx.r31.s64 + 5561;
	// sth r11,5550(r31)
	REX_STORE_U16(ctx.r31.u32 + 5550, ctx.r11.u16);
	// stw r8,5552(r31)
	REX_STORE_U32(ctx.r31.u32 + 5552, ctx.r8.u32);
	// stw r7,5556(r31)
	REX_STORE_U32(ctx.r31.u32 + 5556, ctx.r7.u32);
	// stb r6,5560(r31)
	REX_STORE_U8(ctx.r31.u32 + 5560, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69CE0;
	sub_82F273F0(ctx, base);
	// lwz r7,1264(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1264);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,1268(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1268);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r29,1270(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 1270);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,5808(r31)
	REX_STORE_U16(ctx.r31.u32 + 5808, ctx.r11.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,5810(r31)
	REX_STORE_U16(ctx.r31.u32 + 5810, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,5812(r31)
	REX_STORE_U16(ctx.r31.u32 + 5812, ctx.r9.u16);
	// addi r3,r31,5823
	ctx.r3.s64 = ctx.r31.s64 + 5823;
	// sth r8,5814(r31)
	REX_STORE_U16(ctx.r31.u32 + 5814, ctx.r8.u16);
	// stw r7,5816(r31)
	REX_STORE_U32(ctx.r31.u32 + 5816, ctx.r7.u32);
	// sth r6,5820(r31)
	REX_STORE_U16(ctx.r31.u32 + 5820, ctx.r6.u16);
	// stb r29,5822(r31)
	REX_STORE_U8(ctx.r31.u32 + 5822, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69D28;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r8,1260(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1260);
	// lbz r7,1262(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1262);
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r11,6072(r31)
	REX_STORE_U16(ctx.r31.u32 + 6072, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,6074(r31)
	REX_STORE_U16(ctx.r31.u32 + 6074, ctx.r10.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r9,6076(r31)
	REX_STORE_U16(ctx.r31.u32 + 6076, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,6078(r31)
	REX_STORE_U16(ctx.r31.u32 + 6078, ctx.r11.u16);
	// addi r3,r31,6083
	ctx.r3.s64 = ctx.r31.s64 + 6083;
	// sth r8,6080(r31)
	REX_STORE_U16(ctx.r31.u32 + 6080, ctx.r8.u16);
	// stb r7,6082(r31)
	REX_STORE_U8(ctx.r31.u32 + 6082, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69D68;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1252(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1252);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,6336(r31)
	REX_STORE_U16(ctx.r31.u32 + 6336, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,6338(r31)
	REX_STORE_U16(ctx.r31.u32 + 6338, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,6340(r31)
	REX_STORE_U16(ctx.r31.u32 + 6340, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,6342(r31)
	REX_STORE_U16(ctx.r31.u32 + 6342, ctx.r11.u16);
	// addi r3,r31,6352
	ctx.r3.s64 = ctx.r31.s64 + 6352;
	// std r8,6344(r31)
	REX_STORE_U64(ctx.r31.u32 + 6344, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69DA0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1244(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1244);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,6600(r31)
	REX_STORE_U16(ctx.r31.u32 + 6600, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,6602(r31)
	REX_STORE_U16(ctx.r31.u32 + 6602, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,6604(r31)
	REX_STORE_U16(ctx.r31.u32 + 6604, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,6606(r31)
	REX_STORE_U16(ctx.r31.u32 + 6606, ctx.r11.u16);
	// addi r3,r31,6616
	ctx.r3.s64 = ctx.r31.s64 + 6616;
	// std r8,6608(r31)
	REX_STORE_U64(ctx.r31.u32 + 6608, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69DD8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,1240(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1240);
	// li r10,2
	ctx.r10.s64 = 2;
	// lbz r8,1242(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1242);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,6864(r31)
	REX_STORE_U16(ctx.r31.u32 + 6864, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r10,6866(r31)
	REX_STORE_U16(ctx.r31.u32 + 6866, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,6868(r31)
	REX_STORE_U16(ctx.r31.u32 + 6868, ctx.r9.u16);
	// addi r3,r31,6875
	ctx.r3.s64 = ctx.r31.s64 + 6875;
	// sth r11,6870(r31)
	REX_STORE_U16(ctx.r31.u32 + 6870, ctx.r11.u16);
	// sth r6,6872(r31)
	REX_STORE_U16(ctx.r31.u32 + 6872, ctx.r6.u16);
	// stb r8,6874(r31)
	REX_STORE_U8(ctx.r31.u32 + 6874, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69E18;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1232(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1232);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,7128(r31)
	REX_STORE_U16(ctx.r31.u32 + 7128, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,7130(r31)
	REX_STORE_U16(ctx.r31.u32 + 7130, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,7132(r31)
	REX_STORE_U16(ctx.r31.u32 + 7132, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,7134(r31)
	REX_STORE_U16(ctx.r31.u32 + 7134, ctx.r11.u16);
	// addi r3,r31,7144
	ctx.r3.s64 = ctx.r31.s64 + 7144;
	// std r8,7136(r31)
	REX_STORE_U64(ctx.r31.u32 + 7136, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69E50;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1224(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1224);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,7392(r31)
	REX_STORE_U16(ctx.r31.u32 + 7392, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,7394(r31)
	REX_STORE_U16(ctx.r31.u32 + 7394, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,7396(r31)
	REX_STORE_U16(ctx.r31.u32 + 7396, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,7398(r31)
	REX_STORE_U16(ctx.r31.u32 + 7398, ctx.r11.u16);
	// addi r3,r31,7408
	ctx.r3.s64 = ctx.r31.s64 + 7408;
	// std r8,7400(r31)
	REX_STORE_U64(ctx.r31.u32 + 7400, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69E88;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lhz r7,1220(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 1220);
	// sth r11,7656(r31)
	REX_STORE_U16(ctx.r31.u32 + 7656, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r6,1222(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1222);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,7658(r31)
	REX_STORE_U16(ctx.r31.u32 + 7658, ctx.r10.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,7660(r31)
	REX_STORE_U16(ctx.r31.u32 + 7660, ctx.r9.u16);
	// addi r3,r31,7667
	ctx.r3.s64 = ctx.r31.s64 + 7667;
	// sth r11,7662(r31)
	REX_STORE_U16(ctx.r31.u32 + 7662, ctx.r11.u16);
	// sth r7,7664(r31)
	REX_STORE_U16(ctx.r31.u32 + 7664, ctx.r7.u16);
	// stb r6,7666(r31)
	REX_STORE_U8(ctx.r31.u32 + 7666, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69EC8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r8,1216(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1216);
	// lbz r7,1218(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1218);
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r11,7920(r31)
	REX_STORE_U16(ctx.r31.u32 + 7920, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,7922(r31)
	REX_STORE_U16(ctx.r31.u32 + 7922, ctx.r10.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r9,7924(r31)
	REX_STORE_U16(ctx.r31.u32 + 7924, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,7926(r31)
	REX_STORE_U16(ctx.r31.u32 + 7926, ctx.r11.u16);
	// addi r3,r31,7931
	ctx.r3.s64 = ctx.r31.s64 + 7931;
	// sth r8,7928(r31)
	REX_STORE_U16(ctx.r31.u32 + 7928, ctx.r8.u16);
	// stb r7,7930(r31)
	REX_STORE_U8(ctx.r31.u32 + 7930, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69F08;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1208(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1208);
	// li r10,5
	ctx.r10.s64 = 5;
	// lhz r8,1212(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1212);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,8184(r31)
	REX_STORE_U16(ctx.r31.u32 + 8184, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r10,8186(r31)
	REX_STORE_U16(ctx.r31.u32 + 8186, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,8188(r31)
	REX_STORE_U16(ctx.r31.u32 + 8188, ctx.r9.u16);
	// addi r3,r31,8198
	ctx.r3.s64 = ctx.r31.s64 + 8198;
	// sth r11,8190(r31)
	REX_STORE_U16(ctx.r31.u32 + 8190, ctx.r11.u16);
	// stw r6,8192(r31)
	REX_STORE_U32(ctx.r31.u32 + 8192, ctx.r6.u32);
	// sth r8,8196(r31)
	REX_STORE_U16(ctx.r31.u32 + 8196, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F69F48;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r7,1204(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 1204);
	// lbz r6,1206(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1206);
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r11,8448(r31)
	REX_STORE_U16(ctx.r31.u32 + 8448, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,8450(r31)
	REX_STORE_U16(ctx.r31.u32 + 8450, ctx.r10.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r9,8452(r31)
	REX_STORE_U16(ctx.r31.u32 + 8452, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,8454(r31)
	REX_STORE_U16(ctx.r31.u32 + 8454, ctx.r11.u16);
	// addi r3,r31,8459
	ctx.r3.s64 = ctx.r31.s64 + 8459;
	// sth r7,8456(r31)
	REX_STORE_U16(ctx.r31.u32 + 8456, ctx.r7.u16);
	// stb r6,8458(r31)
	REX_STORE_U8(ctx.r31.u32 + 8458, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69F88;
	sub_82F273F0(ctx, base);
	// lhz r8,1200(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1200);
	// lbz r7,1202(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1202);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,8712(r31)
	REX_STORE_U16(ctx.r31.u32 + 8712, ctx.r11.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r10,8714(r31)
	REX_STORE_U16(ctx.r31.u32 + 8714, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,8716(r31)
	REX_STORE_U16(ctx.r31.u32 + 8716, ctx.r11.u16);
	// addi r3,r31,8723
	ctx.r3.s64 = ctx.r31.s64 + 8723;
	// sth r9,8718(r31)
	REX_STORE_U16(ctx.r31.u32 + 8718, ctx.r9.u16);
	// sth r8,8720(r31)
	REX_STORE_U16(ctx.r31.u32 + 8720, ctx.r8.u16);
	// stb r7,8722(r31)
	REX_STORE_U8(ctx.r31.u32 + 8722, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F69FC4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,1192(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 1192);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,8976(r31)
	REX_STORE_U16(ctx.r31.u32 + 8976, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,8978(r31)
	REX_STORE_U16(ctx.r31.u32 + 8978, ctx.r10.u16);
	// sth r9,8980(r31)
	REX_STORE_U16(ctx.r31.u32 + 8980, ctx.r9.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,8982(r31)
	REX_STORE_U16(ctx.r31.u32 + 8982, ctx.r11.u16);
	// addi r3,r31,8992
	ctx.r3.s64 = ctx.r31.s64 + 8992;
	// std r8,8984(r31)
	REX_STORE_U64(ctx.r31.u32 + 8984, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F69FFC;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1184(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1184);
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r8,1188(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1188);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r7,1190(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1190);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,9240(r31)
	REX_STORE_U16(ctx.r31.u32 + 9240, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,9242(r31)
	REX_STORE_U16(ctx.r31.u32 + 9242, ctx.r10.u16);
	// addi r3,r31,9255
	ctx.r3.s64 = ctx.r31.s64 + 9255;
	// sth r9,9244(r31)
	REX_STORE_U16(ctx.r31.u32 + 9244, ctx.r9.u16);
	// sth r11,9246(r31)
	REX_STORE_U16(ctx.r31.u32 + 9246, ctx.r11.u16);
	// stw r6,9248(r31)
	REX_STORE_U32(ctx.r31.u32 + 9248, ctx.r6.u32);
	// sth r8,9252(r31)
	REX_STORE_U16(ctx.r31.u32 + 9252, ctx.r8.u16);
	// stb r7,9254(r31)
	REX_STORE_U8(ctx.r31.u32 + 9254, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A044;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1176(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1176);
	// lhz r8,1180(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1180);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,9504(r31)
	REX_STORE_U16(ctx.r31.u32 + 9504, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,9506(r31)
	REX_STORE_U16(ctx.r31.u32 + 9506, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,9508(r31)
	REX_STORE_U16(ctx.r31.u32 + 9508, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,9510(r31)
	REX_STORE_U16(ctx.r31.u32 + 9510, ctx.r11.u16);
	// addi r3,r31,9518
	ctx.r3.s64 = ctx.r31.s64 + 9518;
	// stw r6,9512(r31)
	REX_STORE_U32(ctx.r31.u32 + 9512, ctx.r6.u32);
	// sth r8,9516(r31)
	REX_STORE_U16(ctx.r31.u32 + 9516, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A084;
	sub_82F273F0(ctx, base);
	// lwz r7,1164(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1164);
	// lwz r6,1168(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1168);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r29,1172(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 1172);
	// li r10,10
	ctx.r10.s64 = 10;
	// lbz r28,1174(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 1174);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,9768(r31)
	REX_STORE_U16(ctx.r31.u32 + 9768, ctx.r11.u16);
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r10,9770(r31)
	REX_STORE_U16(ctx.r31.u32 + 9770, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,9772(r31)
	REX_STORE_U16(ctx.r31.u32 + 9772, ctx.r9.u16);
	// addi r3,r31,9787
	ctx.r3.s64 = ctx.r31.s64 + 9787;
	// sth r8,9774(r31)
	REX_STORE_U16(ctx.r31.u32 + 9774, ctx.r8.u16);
	// stw r7,9776(r31)
	REX_STORE_U32(ctx.r31.u32 + 9776, ctx.r7.u32);
	// stw r6,9780(r31)
	REX_STORE_U32(ctx.r31.u32 + 9780, ctx.r6.u32);
	// sth r29,9784(r31)
	REX_STORE_U16(ctx.r31.u32 + 9784, ctx.r29.u16);
	// stb r28,9786(r31)
	REX_STORE_U8(ctx.r31.u32 + 9786, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A0D4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1156(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1156);
	// lbz r7,1160(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1160);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,10032(r31)
	REX_STORE_U16(ctx.r31.u32 + 10032, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,10034(r31)
	REX_STORE_U16(ctx.r31.u32 + 10034, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,10036(r31)
	REX_STORE_U16(ctx.r31.u32 + 10036, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,10038(r31)
	REX_STORE_U16(ctx.r31.u32 + 10038, ctx.r11.u16);
	// addi r3,r31,10045
	ctx.r3.s64 = ctx.r31.s64 + 10045;
	// stw r8,10040(r31)
	REX_STORE_U32(ctx.r31.u32 + 10040, ctx.r8.u32);
	// stb r7,10044(r31)
	REX_STORE_U8(ctx.r31.u32 + 10044, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A114;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r6,1148(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1148);
	// sth r11,10296(r31)
	REX_STORE_U16(ctx.r31.u32 + 10296, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r8,1152(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1152);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,10298(r31)
	REX_STORE_U16(ctx.r31.u32 + 10298, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,10300(r31)
	REX_STORE_U16(ctx.r31.u32 + 10300, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,10302(r31)
	REX_STORE_U16(ctx.r31.u32 + 10302, ctx.r11.u16);
	// addi r3,r31,10310
	ctx.r3.s64 = ctx.r31.s64 + 10310;
	// stw r6,10304(r31)
	REX_STORE_U32(ctx.r31.u32 + 10304, ctx.r6.u32);
	// sth r8,10308(r31)
	REX_STORE_U16(ctx.r31.u32 + 10308, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A154;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,1140(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1140);
	// li r10,5
	ctx.r10.s64 = 5;
	// lhz r6,1144(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1144);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,10560(r31)
	REX_STORE_U16(ctx.r31.u32 + 10560, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r10,10562(r31)
	REX_STORE_U16(ctx.r31.u32 + 10562, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,10564(r31)
	REX_STORE_U16(ctx.r31.u32 + 10564, ctx.r9.u16);
	// addi r3,r31,10574
	ctx.r3.s64 = ctx.r31.s64 + 10574;
	// sth r11,10566(r31)
	REX_STORE_U16(ctx.r31.u32 + 10566, ctx.r11.u16);
	// stw r7,10568(r31)
	REX_STORE_U32(ctx.r31.u32 + 10568, ctx.r7.u32);
	// sth r6,10572(r31)
	REX_STORE_U16(ctx.r31.u32 + 10572, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A194;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1128(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1128);
	// lwz r7,1132(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1132);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r6,1136(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 1136);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,10824(r31)
	REX_STORE_U16(ctx.r31.u32 + 10824, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r10,10826(r31)
	REX_STORE_U16(ctx.r31.u32 + 10826, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,10828(r31)
	REX_STORE_U16(ctx.r31.u32 + 10828, ctx.r9.u16);
	// addi r3,r31,10841
	ctx.r3.s64 = ctx.r31.s64 + 10841;
	// sth r11,10830(r31)
	REX_STORE_U16(ctx.r31.u32 + 10830, ctx.r11.u16);
	// stw r8,10832(r31)
	REX_STORE_U32(ctx.r31.u32 + 10832, ctx.r8.u32);
	// stw r7,10836(r31)
	REX_STORE_U32(ctx.r31.u32 + 10836, ctx.r7.u32);
	// stb r6,10840(r31)
	REX_STORE_U8(ctx.r31.u32 + 10840, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A1DC;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r8,1124(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 1124);
	// lbz r7,1126(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1126);
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r11,11088(r31)
	REX_STORE_U16(ctx.r31.u32 + 11088, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,11090(r31)
	REX_STORE_U16(ctx.r31.u32 + 11090, ctx.r10.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r9,11092(r31)
	REX_STORE_U16(ctx.r31.u32 + 11092, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,11094(r31)
	REX_STORE_U16(ctx.r31.u32 + 11094, ctx.r11.u16);
	// addi r3,r31,11099
	ctx.r3.s64 = ctx.r31.s64 + 11099;
	// sth r8,11096(r31)
	REX_STORE_U16(ctx.r31.u32 + 11096, ctx.r8.u16);
	// stb r7,11098(r31)
	REX_STORE_U8(ctx.r31.u32 + 11098, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A21C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,1120(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1120);
	// li r10,2
	ctx.r10.s64 = 2;
	// lbz r8,1122(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1122);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,11352(r31)
	REX_STORE_U16(ctx.r31.u32 + 11352, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r10,11354(r31)
	REX_STORE_U16(ctx.r31.u32 + 11354, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,11356(r31)
	REX_STORE_U16(ctx.r31.u32 + 11356, ctx.r9.u16);
	// addi r3,r31,11363
	ctx.r3.s64 = ctx.r31.s64 + 11363;
	// sth r11,11358(r31)
	REX_STORE_U16(ctx.r31.u32 + 11358, ctx.r11.u16);
	// sth r6,11360(r31)
	REX_STORE_U16(ctx.r31.u32 + 11360, ctx.r6.u16);
	// stb r8,11362(r31)
	REX_STORE_U8(ctx.r31.u32 + 11362, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A25C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,1112(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1112);
	// lhz r6,1116(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1116);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r8,1118(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1118);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,11616(r31)
	REX_STORE_U16(ctx.r31.u32 + 11616, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,11618(r31)
	REX_STORE_U16(ctx.r31.u32 + 11618, ctx.r10.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r9,11620(r31)
	REX_STORE_U16(ctx.r31.u32 + 11620, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,11622(r31)
	REX_STORE_U16(ctx.r31.u32 + 11622, ctx.r11.u16);
	// addi r3,r31,11631
	ctx.r3.s64 = ctx.r31.s64 + 11631;
	// stw r7,11624(r31)
	REX_STORE_U32(ctx.r31.u32 + 11624, ctx.r7.u32);
	// sth r6,11628(r31)
	REX_STORE_U16(ctx.r31.u32 + 11628, ctx.r6.u16);
	// stb r8,11630(r31)
	REX_STORE_U8(ctx.r31.u32 + 11630, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A2A4;
	sub_82F273F0(ctx, base);
	// lwz r7,1096(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1096);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1100(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1100);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r29,1104(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1104);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r28,1108(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 1108);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,243
	ctx.r5.s64 = 243;
	// sth r11,11880(r31)
	REX_STORE_U16(ctx.r31.u32 + 11880, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,11882(r31)
	REX_STORE_U16(ctx.r31.u32 + 11882, ctx.r10.u16);
	// addi r3,r31,11901
	ctx.r3.s64 = ctx.r31.s64 + 11901;
	// sth r9,11884(r31)
	REX_STORE_U16(ctx.r31.u32 + 11884, ctx.r9.u16);
	// sth r8,11886(r31)
	REX_STORE_U16(ctx.r31.u32 + 11886, ctx.r8.u16);
	// stw r7,11888(r31)
	REX_STORE_U32(ctx.r31.u32 + 11888, ctx.r7.u32);
	// stw r6,11892(r31)
	REX_STORE_U32(ctx.r31.u32 + 11892, ctx.r6.u32);
	// stw r29,11896(r31)
	REX_STORE_U32(ctx.r31.u32 + 11896, ctx.r29.u32);
	// stb r28,11900(r31)
	REX_STORE_U8(ctx.r31.u32 + 11900, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A2F4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1088(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1088);
	// lbz r7,1092(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1092);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,12144(r31)
	REX_STORE_U16(ctx.r31.u32 + 12144, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,12146(r31)
	REX_STORE_U16(ctx.r31.u32 + 12146, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,12148(r31)
	REX_STORE_U16(ctx.r31.u32 + 12148, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,12150(r31)
	REX_STORE_U16(ctx.r31.u32 + 12150, ctx.r11.u16);
	// addi r3,r31,12157
	ctx.r3.s64 = ctx.r31.s64 + 12157;
	// stw r8,12152(r31)
	REX_STORE_U32(ctx.r31.u32 + 12152, ctx.r8.u32);
	// stb r7,12156(r31)
	REX_STORE_U8(ctx.r31.u32 + 12156, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A334;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1076(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1076);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12408(r31)
	REX_STORE_U16(ctx.r31.u32 + 12408, ctx.r11.u16);
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r9,1080(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1080);
	// li r5,247
	ctx.r5.s64 = 247;
	// lbz r8,1084(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1084);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,12410(r31)
	REX_STORE_U16(ctx.r31.u32 + 12410, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r31,12425
	ctx.r3.s64 = ctx.r31.s64 + 12425;
	// stw r6,12416(r31)
	REX_STORE_U32(ctx.r31.u32 + 12416, ctx.r6.u32);
	// sth r10,12412(r31)
	REX_STORE_U16(ctx.r31.u32 + 12412, ctx.r10.u16);
	// sth r11,12414(r31)
	REX_STORE_U16(ctx.r31.u32 + 12414, ctx.r11.u16);
	// stw r9,12420(r31)
	REX_STORE_U32(ctx.r31.u32 + 12420, ctx.r9.u32);
	// stb r8,12424(r31)
	REX_STORE_U8(ctx.r31.u32 + 12424, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A37C;
	sub_82F273F0(ctx, base);
	// lwz r7,1064(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1064);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1068(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1068);
	// li r10,9
	ctx.r10.s64 = 9;
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r29,1072(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 1072);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,12672(r31)
	REX_STORE_U16(ctx.r31.u32 + 12672, ctx.r11.u16);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r10,12674(r31)
	REX_STORE_U16(ctx.r31.u32 + 12674, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,12676(r31)
	REX_STORE_U16(ctx.r31.u32 + 12676, ctx.r9.u16);
	// addi r3,r31,12690
	ctx.r3.s64 = ctx.r31.s64 + 12690;
	// sth r8,12678(r31)
	REX_STORE_U16(ctx.r31.u32 + 12678, ctx.r8.u16);
	// stw r7,12680(r31)
	REX_STORE_U32(ctx.r31.u32 + 12680, ctx.r7.u32);
	// stw r6,12684(r31)
	REX_STORE_U32(ctx.r31.u32 + 12684, ctx.r6.u32);
	// sth r29,12688(r31)
	REX_STORE_U16(ctx.r31.u32 + 12688, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A3C4;
	sub_82F273F0(ctx, base);
	// lwz r7,1048(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1048);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1052(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1052);
	// li r10,15
	ctx.r10.s64 = 15;
	// lwz r29,1056(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 1056);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r28,1060(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 1060);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,240
	ctx.r5.s64 = 240;
	// sth r11,12936(r31)
	REX_STORE_U16(ctx.r31.u32 + 12936, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,12938(r31)
	REX_STORE_U16(ctx.r31.u32 + 12938, ctx.r10.u16);
	// addi r3,r31,12960
	ctx.r3.s64 = ctx.r31.s64 + 12960;
	// sth r9,12940(r31)
	REX_STORE_U16(ctx.r31.u32 + 12940, ctx.r9.u16);
	// addi r11,r30,1048
	ctx.r11.s64 = ctx.r30.s64 + 1048;
	// sth r8,12942(r31)
	REX_STORE_U16(ctx.r31.u32 + 12942, ctx.r8.u16);
	// addi r10,r31,12944
	ctx.r10.s64 = ctx.r31.s64 + 12944;
	// stw r7,12944(r31)
	REX_STORE_U32(ctx.r31.u32 + 12944, ctx.r7.u32);
	// stw r6,12948(r31)
	REX_STORE_U32(ctx.r31.u32 + 12948, ctx.r6.u32);
	// stw r29,12952(r31)
	REX_STORE_U32(ctx.r31.u32 + 12952, ctx.r29.u32);
	// stw r28,12956(r31)
	REX_STORE_U32(ctx.r31.u32 + 12956, ctx.r28.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A41C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,1040(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1040);
	// lbz r7,1044(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1044);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,13200(r31)
	REX_STORE_U16(ctx.r31.u32 + 13200, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,13202(r31)
	REX_STORE_U16(ctx.r31.u32 + 13202, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,13204(r31)
	REX_STORE_U16(ctx.r31.u32 + 13204, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,13206(r31)
	REX_STORE_U16(ctx.r31.u32 + 13206, ctx.r11.u16);
	// addi r3,r31,13213
	ctx.r3.s64 = ctx.r31.s64 + 13213;
	// stw r8,13208(r31)
	REX_STORE_U32(ctx.r31.u32 + 13208, ctx.r8.u32);
	// stb r7,13212(r31)
	REX_STORE_U8(ctx.r31.u32 + 13212, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A45C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1032(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1032);
	// li r10,4
	ctx.r10.s64 = 4;
	// lbz r8,1036(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 1036);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,13464(r31)
	REX_STORE_U16(ctx.r31.u32 + 13464, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r10,13466(r31)
	REX_STORE_U16(ctx.r31.u32 + 13466, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,13468(r31)
	REX_STORE_U16(ctx.r31.u32 + 13468, ctx.r9.u16);
	// addi r3,r31,13477
	ctx.r3.s64 = ctx.r31.s64 + 13477;
	// sth r11,13470(r31)
	REX_STORE_U16(ctx.r31.u32 + 13470, ctx.r11.u16);
	// stw r6,13472(r31)
	REX_STORE_U32(ctx.r31.u32 + 13472, ctx.r6.u32);
	// stb r8,13476(r31)
	REX_STORE_U8(ctx.r31.u32 + 13476, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A49C;
	sub_82F273F0(ctx, base);
	// lwz r7,1024(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1024);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,1028(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1028);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r29,1030(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 1030);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,13728(r31)
	REX_STORE_U16(ctx.r31.u32 + 13728, ctx.r11.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,13730(r31)
	REX_STORE_U16(ctx.r31.u32 + 13730, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,13732(r31)
	REX_STORE_U16(ctx.r31.u32 + 13732, ctx.r9.u16);
	// addi r3,r31,13743
	ctx.r3.s64 = ctx.r31.s64 + 13743;
	// sth r8,13734(r31)
	REX_STORE_U16(ctx.r31.u32 + 13734, ctx.r8.u16);
	// stw r7,13736(r31)
	REX_STORE_U32(ctx.r31.u32 + 13736, ctx.r7.u32);
	// sth r6,13740(r31)
	REX_STORE_U16(ctx.r31.u32 + 13740, ctx.r6.u16);
	// stb r29,13742(r31)
	REX_STORE_U8(ctx.r31.u32 + 13742, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A4E4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,1016(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1016);
	// lhz r6,1020(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1020);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r29,1022(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 1022);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,13992(r31)
	REX_STORE_U16(ctx.r31.u32 + 13992, ctx.r11.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r10,13994(r31)
	REX_STORE_U16(ctx.r31.u32 + 13994, ctx.r10.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r9,13996(r31)
	REX_STORE_U16(ctx.r31.u32 + 13996, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r8,13998(r31)
	REX_STORE_U16(ctx.r31.u32 + 13998, ctx.r8.u16);
	// addi r3,r31,14007
	ctx.r3.s64 = ctx.r31.s64 + 14007;
	// stw r7,14000(r31)
	REX_STORE_U32(ctx.r31.u32 + 14000, ctx.r7.u32);
	// sth r6,14004(r31)
	REX_STORE_U16(ctx.r31.u32 + 14004, ctx.r6.u16);
	// stb r29,14006(r31)
	REX_STORE_U8(ctx.r31.u32 + 14006, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A52C;
	sub_82F273F0(ctx, base);
	// lwz r7,1008(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1008);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,1012(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1012);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r29,1014(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 1014);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,14256(r31)
	REX_STORE_U16(ctx.r31.u32 + 14256, ctx.r11.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,14258(r31)
	REX_STORE_U16(ctx.r31.u32 + 14258, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,14260(r31)
	REX_STORE_U16(ctx.r31.u32 + 14260, ctx.r9.u16);
	// addi r3,r31,14271
	ctx.r3.s64 = ctx.r31.s64 + 14271;
	// sth r8,14262(r31)
	REX_STORE_U16(ctx.r31.u32 + 14262, ctx.r8.u16);
	// stw r7,14264(r31)
	REX_STORE_U32(ctx.r31.u32 + 14264, ctx.r7.u32);
	// sth r6,14268(r31)
	REX_STORE_U16(ctx.r31.u32 + 14268, ctx.r6.u16);
	// stb r29,14270(r31)
	REX_STORE_U8(ctx.r31.u32 + 14270, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A574;
	sub_82F273F0(ctx, base);
	// lwz r7,996(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 996);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,1000(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1000);
	// li r10,9
	ctx.r10.s64 = 9;
	// lhz r29,1004(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 1004);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,14520(r31)
	REX_STORE_U16(ctx.r31.u32 + 14520, ctx.r11.u16);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r10,14522(r31)
	REX_STORE_U16(ctx.r31.u32 + 14522, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,14524(r31)
	REX_STORE_U16(ctx.r31.u32 + 14524, ctx.r9.u16);
	// addi r3,r31,14538
	ctx.r3.s64 = ctx.r31.s64 + 14538;
	// sth r8,14526(r31)
	REX_STORE_U16(ctx.r31.u32 + 14526, ctx.r8.u16);
	// stw r7,14528(r31)
	REX_STORE_U32(ctx.r31.u32 + 14528, ctx.r7.u32);
	// stw r6,14532(r31)
	REX_STORE_U32(ctx.r31.u32 + 14532, ctx.r6.u32);
	// sth r29,14536(r31)
	REX_STORE_U16(ctx.r31.u32 + 14536, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A5BC;
	sub_82F273F0(ctx, base);
	// lwz r3,984(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 984);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,988(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 988);
	// li r10,10
	ctx.r10.s64 = 10;
	// lhz r7,992(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 992);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r6,994(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 994);
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r11,14784(r31)
	REX_STORE_U16(ctx.r31.u32 + 14784, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,14792(r31)
	REX_STORE_U32(ctx.r31.u32 + 14792, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,14803
	ctx.r3.s64 = ctx.r31.s64 + 14803;
	// stw r8,14796(r31)
	REX_STORE_U32(ctx.r31.u32 + 14796, ctx.r8.u32);
	// sth r10,14786(r31)
	REX_STORE_U16(ctx.r31.u32 + 14786, ctx.r10.u16);
	// sth r9,14788(r31)
	REX_STORE_U16(ctx.r31.u32 + 14788, ctx.r9.u16);
	// sth r11,14790(r31)
	REX_STORE_U16(ctx.r31.u32 + 14790, ctx.r11.u16);
	// sth r7,14800(r31)
	REX_STORE_U16(ctx.r31.u32 + 14800, ctx.r7.u16);
	// stb r6,14802(r31)
	REX_STORE_U8(ctx.r31.u32 + 14802, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A60C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,968(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 968);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r6,972(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 972);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r29,976(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 976);
	// lbz r28,980(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 980);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,243
	ctx.r5.s64 = 243;
	// sth r11,15048(r31)
	REX_STORE_U16(ctx.r31.u32 + 15048, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,15050(r31)
	REX_STORE_U16(ctx.r31.u32 + 15050, ctx.r10.u16);
	// addi r3,r31,15069
	ctx.r3.s64 = ctx.r31.s64 + 15069;
	// sth r9,15052(r31)
	REX_STORE_U16(ctx.r31.u32 + 15052, ctx.r9.u16);
	// sth r8,15054(r31)
	REX_STORE_U16(ctx.r31.u32 + 15054, ctx.r8.u16);
	// stw r7,15056(r31)
	REX_STORE_U32(ctx.r31.u32 + 15056, ctx.r7.u32);
	// stw r6,15060(r31)
	REX_STORE_U32(ctx.r31.u32 + 15060, ctx.r6.u32);
	// stw r29,15064(r31)
	REX_STORE_U32(ctx.r31.u32 + 15064, ctx.r29.u32);
	// stb r28,15068(r31)
	REX_STORE_U8(ctx.r31.u32 + 15068, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A65C;
	sub_82F273F0(ctx, base);
	// lwz r7,956(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 956);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,960(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 960);
	// li r10,9
	ctx.r10.s64 = 9;
	// lhz r29,964(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 964);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,15312(r31)
	REX_STORE_U16(ctx.r31.u32 + 15312, ctx.r11.u16);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r10,15314(r31)
	REX_STORE_U16(ctx.r31.u32 + 15314, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,15316(r31)
	REX_STORE_U16(ctx.r31.u32 + 15316, ctx.r9.u16);
	// addi r3,r31,15330
	ctx.r3.s64 = ctx.r31.s64 + 15330;
	// sth r8,15318(r31)
	REX_STORE_U16(ctx.r31.u32 + 15318, ctx.r8.u16);
	// stw r7,15320(r31)
	REX_STORE_U32(ctx.r31.u32 + 15320, ctx.r7.u32);
	// stw r6,15324(r31)
	REX_STORE_U32(ctx.r31.u32 + 15324, ctx.r6.u32);
	// sth r29,15328(r31)
	REX_STORE_U16(ctx.r31.u32 + 15328, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A6A4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,948(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 948);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,15576(r31)
	REX_STORE_U16(ctx.r31.u32 + 15576, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,15578(r31)
	REX_STORE_U16(ctx.r31.u32 + 15578, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,15580(r31)
	REX_STORE_U16(ctx.r31.u32 + 15580, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,15582(r31)
	REX_STORE_U16(ctx.r31.u32 + 15582, ctx.r11.u16);
	// addi r3,r31,15592
	ctx.r3.s64 = ctx.r31.s64 + 15592;
	// std r8,15584(r31)
	REX_STORE_U64(ctx.r31.u32 + 15584, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A6DC;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,940(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 940);
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r7,944(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 944);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r6,946(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 946);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,15840(r31)
	REX_STORE_U16(ctx.r31.u32 + 15840, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,15842(r31)
	REX_STORE_U16(ctx.r31.u32 + 15842, ctx.r10.u16);
	// addi r3,r31,15855
	ctx.r3.s64 = ctx.r31.s64 + 15855;
	// sth r9,15844(r31)
	REX_STORE_U16(ctx.r31.u32 + 15844, ctx.r9.u16);
	// sth r11,15846(r31)
	REX_STORE_U16(ctx.r31.u32 + 15846, ctx.r11.u16);
	// stw r8,15848(r31)
	REX_STORE_U32(ctx.r31.u32 + 15848, ctx.r8.u32);
	// sth r7,15852(r31)
	REX_STORE_U16(ctx.r31.u32 + 15852, ctx.r7.u16);
	// stb r6,15854(r31)
	REX_STORE_U8(ctx.r31.u32 + 15854, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A724;
	sub_82F273F0(ctx, base);
	// lwz r7,928(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 928);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,932(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 932);
	// li r10,11
	ctx.r10.s64 = 11;
	// lwz r29,936(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 936);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,16104(r31)
	REX_STORE_U16(ctx.r31.u32 + 16104, ctx.r11.u16);
	// li r5,244
	ctx.r5.s64 = 244;
	// sth r10,16106(r31)
	REX_STORE_U16(ctx.r31.u32 + 16106, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,16108(r31)
	REX_STORE_U16(ctx.r31.u32 + 16108, ctx.r9.u16);
	// addi r3,r31,16124
	ctx.r3.s64 = ctx.r31.s64 + 16124;
	// sth r8,16110(r31)
	REX_STORE_U16(ctx.r31.u32 + 16110, ctx.r8.u16);
	// stw r7,16112(r31)
	REX_STORE_U32(ctx.r31.u32 + 16112, ctx.r7.u32);
	// stw r6,16116(r31)
	REX_STORE_U32(ctx.r31.u32 + 16116, ctx.r6.u32);
	// stw r29,16120(r31)
	REX_STORE_U32(ctx.r31.u32 + 16120, ctx.r29.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A76C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,916(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 916);
	// lwz r6,920(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 920);
	// li r10,11
	ctx.r10.s64 = 11;
	// lwz r29,924(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 924);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,16368(r31)
	REX_STORE_U16(ctx.r31.u32 + 16368, ctx.r11.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r10,16370(r31)
	REX_STORE_U16(ctx.r31.u32 + 16370, ctx.r10.u16);
	// li r5,244
	ctx.r5.s64 = 244;
	// sth r9,16372(r31)
	REX_STORE_U16(ctx.r31.u32 + 16372, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r8,16374(r31)
	REX_STORE_U16(ctx.r31.u32 + 16374, ctx.r8.u16);
	// addi r3,r31,16388
	ctx.r3.s64 = ctx.r31.s64 + 16388;
	// stw r7,16376(r31)
	REX_STORE_U32(ctx.r31.u32 + 16376, ctx.r7.u32);
	// stw r6,16380(r31)
	REX_STORE_U32(ctx.r31.u32 + 16380, ctx.r6.u32);
	// stw r29,16384(r31)
	REX_STORE_U32(ctx.r31.u32 + 16384, ctx.r29.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A7B4;
	sub_82F273F0(ctx, base);
	// lwz r7,904(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 904);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,908(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 908);
	// li r10,9
	ctx.r10.s64 = 9;
	// lhz r29,912(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 912);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,16632(r31)
	REX_STORE_U16(ctx.r31.u32 + 16632, ctx.r11.u16);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r10,16634(r31)
	REX_STORE_U16(ctx.r31.u32 + 16634, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,16636(r31)
	REX_STORE_U16(ctx.r31.u32 + 16636, ctx.r9.u16);
	// addi r3,r31,16650
	ctx.r3.s64 = ctx.r31.s64 + 16650;
	// sth r8,16638(r31)
	REX_STORE_U16(ctx.r31.u32 + 16638, ctx.r8.u16);
	// stw r7,16640(r31)
	REX_STORE_U32(ctx.r31.u32 + 16640, ctx.r7.u32);
	// stw r6,16644(r31)
	REX_STORE_U32(ctx.r31.u32 + 16644, ctx.r6.u32);
	// sth r29,16648(r31)
	REX_STORE_U16(ctx.r31.u32 + 16648, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A7FC;
	sub_82F273F0(ctx, base);
	// lwz r7,888(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 888);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,892(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 892);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r29,896(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 896);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r28,900(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 900);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,243
	ctx.r5.s64 = 243;
	// sth r11,16896(r31)
	REX_STORE_U16(ctx.r31.u32 + 16896, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,16898(r31)
	REX_STORE_U16(ctx.r31.u32 + 16898, ctx.r10.u16);
	// addi r3,r31,16917
	ctx.r3.s64 = ctx.r31.s64 + 16917;
	// sth r9,16900(r31)
	REX_STORE_U16(ctx.r31.u32 + 16900, ctx.r9.u16);
	// sth r8,16902(r31)
	REX_STORE_U16(ctx.r31.u32 + 16902, ctx.r8.u16);
	// stw r7,16904(r31)
	REX_STORE_U32(ctx.r31.u32 + 16904, ctx.r7.u32);
	// stw r6,16908(r31)
	REX_STORE_U32(ctx.r31.u32 + 16908, ctx.r6.u32);
	// stw r29,16912(r31)
	REX_STORE_U32(ctx.r31.u32 + 16912, ctx.r29.u32);
	// stb r28,16916(r31)
	REX_STORE_U8(ctx.r31.u32 + 16916, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A84C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,880(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 880);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,17160(r31)
	REX_STORE_U16(ctx.r31.u32 + 17160, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,17162(r31)
	REX_STORE_U16(ctx.r31.u32 + 17162, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,17164(r31)
	REX_STORE_U16(ctx.r31.u32 + 17164, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,17166(r31)
	REX_STORE_U16(ctx.r31.u32 + 17166, ctx.r11.u16);
	// addi r3,r31,17176
	ctx.r3.s64 = ctx.r31.s64 + 17176;
	// std r8,17168(r31)
	REX_STORE_U64(ctx.r31.u32 + 17168, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A884;
	sub_82F273F0(ctx, base);
	// lwz r7,868(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 868);
	// lwz r6,872(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 872);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r29,876(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 876);
	// li r10,9
	ctx.r10.s64 = 9;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,17424(r31)
	REX_STORE_U16(ctx.r31.u32 + 17424, ctx.r11.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r10,17426(r31)
	REX_STORE_U16(ctx.r31.u32 + 17426, ctx.r10.u16);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r9,17428(r31)
	REX_STORE_U16(ctx.r31.u32 + 17428, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r8,17430(r31)
	REX_STORE_U16(ctx.r31.u32 + 17430, ctx.r8.u16);
	// addi r3,r31,17442
	ctx.r3.s64 = ctx.r31.s64 + 17442;
	// stw r7,17432(r31)
	REX_STORE_U32(ctx.r31.u32 + 17432, ctx.r7.u32);
	// stw r6,17436(r31)
	REX_STORE_U32(ctx.r31.u32 + 17436, ctx.r6.u32);
	// sth r29,17440(r31)
	REX_STORE_U16(ctx.r31.u32 + 17440, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A8CC;
	sub_82F273F0(ctx, base);
	// li r10,17
	ctx.r10.s64 = 17;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r7,r30,848
	ctx.r7.s64 = ctx.r30.s64 + 848;
	// li r9,16
	ctx.r9.s64 = 16;
	// sth r11,17688(r31)
	REX_STORE_U16(ctx.r31.u32 + 17688, ctx.r11.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,17692(r31)
	REX_STORE_U16(ctx.r31.u32 + 17692, ctx.r11.u16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// sth r9,17690(r31)
	REX_STORE_U16(ctx.r31.u32 + 17690, ctx.r9.u16);
	// sth r8,17694(r31)
	REX_STORE_U16(ctx.r31.u32 + 17694, ctx.r8.u16);
	// addi r10,r31,17695
	ctx.r10.s64 = ctx.r31.s64 + 17695;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_82F6A8FC:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6a8fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6A8FC;
	// li r5,239
	ctx.r5.s64 = 239;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,17713
	ctx.r3.s64 = ctx.r31.s64 + 17713;
	// bl 0x82f273f0
	ctx.lr = 0x82F6A918;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,836(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 836);
	// li r10,9
	ctx.r10.s64 = 9;
	// lwz r7,840(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 840);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r6,844(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 844);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r11,17952(r31)
	REX_STORE_U16(ctx.r31.u32 + 17952, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,17954(r31)
	REX_STORE_U16(ctx.r31.u32 + 17954, ctx.r10.u16);
	// addi r3,r31,17970
	ctx.r3.s64 = ctx.r31.s64 + 17970;
	// sth r9,17956(r31)
	REX_STORE_U16(ctx.r31.u32 + 17956, ctx.r9.u16);
	// sth r11,17958(r31)
	REX_STORE_U16(ctx.r31.u32 + 17958, ctx.r11.u16);
	// stw r8,17960(r31)
	REX_STORE_U32(ctx.r31.u32 + 17960, ctx.r8.u32);
	// stw r7,17964(r31)
	REX_STORE_U32(ctx.r31.u32 + 17964, ctx.r7.u32);
	// sth r6,17968(r31)
	REX_STORE_U16(ctx.r31.u32 + 17968, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A960;
	sub_82F273F0(ctx, base);
	// lwz r7,824(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 824);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,828(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 828);
	// li r10,10
	ctx.r10.s64 = 10;
	// lhz r29,832(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 832);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r28,834(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 834);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r11,18216(r31)
	REX_STORE_U16(ctx.r31.u32 + 18216, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,18218(r31)
	REX_STORE_U16(ctx.r31.u32 + 18218, ctx.r10.u16);
	// addi r3,r31,18235
	ctx.r3.s64 = ctx.r31.s64 + 18235;
	// sth r9,18220(r31)
	REX_STORE_U16(ctx.r31.u32 + 18220, ctx.r9.u16);
	// sth r8,18222(r31)
	REX_STORE_U16(ctx.r31.u32 + 18222, ctx.r8.u16);
	// stw r7,18224(r31)
	REX_STORE_U32(ctx.r31.u32 + 18224, ctx.r7.u32);
	// stw r6,18228(r31)
	REX_STORE_U32(ctx.r31.u32 + 18228, ctx.r6.u32);
	// sth r29,18232(r31)
	REX_STORE_U16(ctx.r31.u32 + 18232, ctx.r29.u16);
	// stb r28,18234(r31)
	REX_STORE_U8(ctx.r31.u32 + 18234, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A9B0;
	sub_82F273F0(ctx, base);
	// lwz r7,812(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 812);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,816(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 816);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r29,820(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 820);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,18480(r31)
	REX_STORE_U16(ctx.r31.u32 + 18480, ctx.r11.u16);
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r10,18482(r31)
	REX_STORE_U16(ctx.r31.u32 + 18482, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,18484(r31)
	REX_STORE_U16(ctx.r31.u32 + 18484, ctx.r9.u16);
	// addi r3,r31,18497
	ctx.r3.s64 = ctx.r31.s64 + 18497;
	// sth r8,18486(r31)
	REX_STORE_U16(ctx.r31.u32 + 18486, ctx.r8.u16);
	// stw r7,18488(r31)
	REX_STORE_U32(ctx.r31.u32 + 18488, ctx.r7.u32);
	// stw r6,18492(r31)
	REX_STORE_U32(ctx.r31.u32 + 18492, ctx.r6.u32);
	// stb r29,18496(r31)
	REX_STORE_U8(ctx.r31.u32 + 18496, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6A9F8;
	sub_82F273F0(ctx, base);
	// lwz r7,800(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 800);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,804(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 804);
	// li r10,9
	ctx.r10.s64 = 9;
	// lhz r29,808(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 808);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,18744(r31)
	REX_STORE_U16(ctx.r31.u32 + 18744, ctx.r11.u16);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r10,18746(r31)
	REX_STORE_U16(ctx.r31.u32 + 18746, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,18748(r31)
	REX_STORE_U16(ctx.r31.u32 + 18748, ctx.r9.u16);
	// addi r3,r31,18762
	ctx.r3.s64 = ctx.r31.s64 + 18762;
	// sth r8,18750(r31)
	REX_STORE_U16(ctx.r31.u32 + 18750, ctx.r8.u16);
	// stw r7,18752(r31)
	REX_STORE_U32(ctx.r31.u32 + 18752, ctx.r7.u32);
	// stw r6,18756(r31)
	REX_STORE_U32(ctx.r31.u32 + 18756, ctx.r6.u32);
	// sth r29,18760(r31)
	REX_STORE_U16(ctx.r31.u32 + 18760, ctx.r29.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AA40;
	sub_82F273F0(ctx, base);
	// lhz r5,796(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 796);
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r8,798(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 798);
	// sth r11,19008(r31)
	REX_STORE_U16(ctx.r31.u32 + 19008, ctx.r11.u16);
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r5,19016(r31)
	REX_STORE_U16(ctx.r31.u32 + 19016, ctx.r5.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,19010(r31)
	REX_STORE_U16(ctx.r31.u32 + 19010, ctx.r10.u16);
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r9,19012(r31)
	REX_STORE_U16(ctx.r31.u32 + 19012, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,19014(r31)
	REX_STORE_U16(ctx.r31.u32 + 19014, ctx.r11.u16);
	// addi r3,r31,19019
	ctx.r3.s64 = ctx.r31.s64 + 19019;
	// stb r8,19018(r31)
	REX_STORE_U8(ctx.r31.u32 + 19018, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AA80;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r7,792(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 792);
	// li r10,2
	ctx.r10.s64 = 2;
	// lbz r6,794(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 794);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,19272(r31)
	REX_STORE_U16(ctx.r31.u32 + 19272, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,253
	ctx.r5.s64 = 253;
	// sth r10,19274(r31)
	REX_STORE_U16(ctx.r31.u32 + 19274, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,19276(r31)
	REX_STORE_U16(ctx.r31.u32 + 19276, ctx.r9.u16);
	// addi r3,r31,19283
	ctx.r3.s64 = ctx.r31.s64 + 19283;
	// sth r11,19278(r31)
	REX_STORE_U16(ctx.r31.u32 + 19278, ctx.r11.u16);
	// sth r7,19280(r31)
	REX_STORE_U16(ctx.r31.u32 + 19280, ctx.r7.u16);
	// stb r6,19282(r31)
	REX_STORE_U8(ctx.r31.u32 + 19282, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AAC0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,784(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 784);
	// lhz r7,788(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 788);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,19536(r31)
	REX_STORE_U16(ctx.r31.u32 + 19536, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,19538(r31)
	REX_STORE_U16(ctx.r31.u32 + 19538, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,19540(r31)
	REX_STORE_U16(ctx.r31.u32 + 19540, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,19542(r31)
	REX_STORE_U16(ctx.r31.u32 + 19542, ctx.r11.u16);
	// addi r3,r31,19550
	ctx.r3.s64 = ctx.r31.s64 + 19550;
	// stw r8,19544(r31)
	REX_STORE_U32(ctx.r31.u32 + 19544, ctx.r8.u32);
	// sth r7,19548(r31)
	REX_STORE_U16(ctx.r31.u32 + 19548, ctx.r7.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AB00;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,776(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 776);
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r8,780(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 780);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r7,782(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 782);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,19800(r31)
	REX_STORE_U16(ctx.r31.u32 + 19800, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,19802(r31)
	REX_STORE_U16(ctx.r31.u32 + 19802, ctx.r10.u16);
	// addi r3,r31,19815
	ctx.r3.s64 = ctx.r31.s64 + 19815;
	// sth r9,19804(r31)
	REX_STORE_U16(ctx.r31.u32 + 19804, ctx.r9.u16);
	// sth r11,19806(r31)
	REX_STORE_U16(ctx.r31.u32 + 19806, ctx.r11.u16);
	// stw r6,19808(r31)
	REX_STORE_U32(ctx.r31.u32 + 19808, ctx.r6.u32);
	// sth r8,19812(r31)
	REX_STORE_U16(ctx.r31.u32 + 19812, ctx.r8.u16);
	// stb r7,19814(r31)
	REX_STORE_U8(ctx.r31.u32 + 19814, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AB48;
	sub_82F273F0(ctx, base);
	// lwz r6,760(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 760);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,764(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 764);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r29,768(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 768);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lbz r28,772(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 772);
	// li r5,243
	ctx.r5.s64 = 243;
	// sth r11,20064(r31)
	REX_STORE_U16(ctx.r31.u32 + 20064, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,20066(r31)
	REX_STORE_U16(ctx.r31.u32 + 20066, ctx.r10.u16);
	// addi r3,r31,20085
	ctx.r3.s64 = ctx.r31.s64 + 20085;
	// sth r9,20068(r31)
	REX_STORE_U16(ctx.r31.u32 + 20068, ctx.r9.u16);
	// sth r8,20070(r31)
	REX_STORE_U16(ctx.r31.u32 + 20070, ctx.r8.u16);
	// stw r6,20072(r31)
	REX_STORE_U32(ctx.r31.u32 + 20072, ctx.r6.u32);
	// stw r7,20076(r31)
	REX_STORE_U32(ctx.r31.u32 + 20076, ctx.r7.u32);
	// stw r29,20080(r31)
	REX_STORE_U32(ctx.r31.u32 + 20080, ctx.r29.u32);
	// stb r28,20084(r31)
	REX_STORE_U8(ctx.r31.u32 + 20084, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AB98;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,752(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 752);
	// lhz r8,756(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 756);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,20328(r31)
	REX_STORE_U16(ctx.r31.u32 + 20328, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,20330(r31)
	REX_STORE_U16(ctx.r31.u32 + 20330, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,20332(r31)
	REX_STORE_U16(ctx.r31.u32 + 20332, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,20334(r31)
	REX_STORE_U16(ctx.r31.u32 + 20334, ctx.r11.u16);
	// addi r3,r31,20342
	ctx.r3.s64 = ctx.r31.s64 + 20342;
	// stw r6,20336(r31)
	REX_STORE_U32(ctx.r31.u32 + 20336, ctx.r6.u32);
	// sth r8,20340(r31)
	REX_STORE_U16(ctx.r31.u32 + 20340, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6ABD8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,744(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 744);
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r6,748(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 748);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,750(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 750);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,20592(r31)
	REX_STORE_U16(ctx.r31.u32 + 20592, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,20594(r31)
	REX_STORE_U16(ctx.r31.u32 + 20594, ctx.r10.u16);
	// addi r3,r31,20607
	ctx.r3.s64 = ctx.r31.s64 + 20607;
	// sth r9,20596(r31)
	REX_STORE_U16(ctx.r31.u32 + 20596, ctx.r9.u16);
	// sth r11,20598(r31)
	REX_STORE_U16(ctx.r31.u32 + 20598, ctx.r11.u16);
	// stw r7,20600(r31)
	REX_STORE_U32(ctx.r31.u32 + 20600, ctx.r7.u32);
	// sth r6,20604(r31)
	REX_STORE_U16(ctx.r31.u32 + 20604, ctx.r6.u16);
	// stb r8,20606(r31)
	REX_STORE_U8(ctx.r31.u32 + 20606, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AC20;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,736(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 736);
	// lhz r6,740(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 740);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,20856(r31)
	REX_STORE_U16(ctx.r31.u32 + 20856, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,20858(r31)
	REX_STORE_U16(ctx.r31.u32 + 20858, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,20860(r31)
	REX_STORE_U16(ctx.r31.u32 + 20860, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,20862(r31)
	REX_STORE_U16(ctx.r31.u32 + 20862, ctx.r11.u16);
	// addi r3,r31,20870
	ctx.r3.s64 = ctx.r31.s64 + 20870;
	// stw r7,20864(r31)
	REX_STORE_U32(ctx.r31.u32 + 20864, ctx.r7.u32);
	// sth r6,20868(r31)
	REX_STORE_U16(ctx.r31.u32 + 20868, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AC60;
	sub_82F273F0(ctx, base);
	// lwz r7,724(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 724);
	// lwz r6,728(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 728);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r29,732(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 732);
	// li r10,10
	ctx.r10.s64 = 10;
	// lbz r28,734(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 734);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,21120(r31)
	REX_STORE_U16(ctx.r31.u32 + 21120, ctx.r11.u16);
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r10,21122(r31)
	REX_STORE_U16(ctx.r31.u32 + 21122, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,21124(r31)
	REX_STORE_U16(ctx.r31.u32 + 21124, ctx.r9.u16);
	// addi r3,r31,21139
	ctx.r3.s64 = ctx.r31.s64 + 21139;
	// sth r8,21126(r31)
	REX_STORE_U16(ctx.r31.u32 + 21126, ctx.r8.u16);
	// stw r7,21128(r31)
	REX_STORE_U32(ctx.r31.u32 + 21128, ctx.r7.u32);
	// stw r6,21132(r31)
	REX_STORE_U32(ctx.r31.u32 + 21132, ctx.r6.u32);
	// sth r29,21136(r31)
	REX_STORE_U16(ctx.r31.u32 + 21136, ctx.r29.u16);
	// stb r28,21138(r31)
	REX_STORE_U8(ctx.r31.u32 + 21138, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6ACB0;
	sub_82F273F0(ctx, base);
	// lwz r10,716(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 716);
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r9,720(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 720);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r11,21384(r31)
	REX_STORE_U16(ctx.r31.u32 + 21384, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,21397
	ctx.r3.s64 = ctx.r31.s64 + 21397;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,21392(r31)
	REX_STORE_U32(ctx.r31.u32 + 21392, ctx.r10.u32);
	// stb r9,21396(r31)
	REX_STORE_U8(ctx.r31.u32 + 21396, ctx.r9.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,21386(r31)
	REX_STORE_U16(ctx.r31.u32 + 21386, ctx.r11.u16);
	// sth r10,21388(r31)
	REX_STORE_U16(ctx.r31.u32 + 21388, ctx.r10.u16);
	// sth r9,21390(r31)
	REX_STORE_U16(ctx.r31.u32 + 21390, ctx.r9.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6ACF0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,708(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 708);
	// lbz r7,712(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 712);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,21648(r31)
	REX_STORE_U16(ctx.r31.u32 + 21648, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,21650(r31)
	REX_STORE_U16(ctx.r31.u32 + 21650, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,21652(r31)
	REX_STORE_U16(ctx.r31.u32 + 21652, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,21654(r31)
	REX_STORE_U16(ctx.r31.u32 + 21654, ctx.r11.u16);
	// addi r3,r31,21661
	ctx.r3.s64 = ctx.r31.s64 + 21661;
	// stw r8,21656(r31)
	REX_STORE_U32(ctx.r31.u32 + 21656, ctx.r8.u32);
	// stb r7,21660(r31)
	REX_STORE_U8(ctx.r31.u32 + 21660, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AD30;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,696(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 696);
	// li r10,9
	ctx.r10.s64 = 9;
	// lwz r8,700(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 700);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r7,704(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 704);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r11,21912(r31)
	REX_STORE_U16(ctx.r31.u32 + 21912, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,21914(r31)
	REX_STORE_U16(ctx.r31.u32 + 21914, ctx.r10.u16);
	// addi r3,r31,21930
	ctx.r3.s64 = ctx.r31.s64 + 21930;
	// sth r9,21916(r31)
	REX_STORE_U16(ctx.r31.u32 + 21916, ctx.r9.u16);
	// sth r11,21918(r31)
	REX_STORE_U16(ctx.r31.u32 + 21918, ctx.r11.u16);
	// stw r6,21920(r31)
	REX_STORE_U32(ctx.r31.u32 + 21920, ctx.r6.u32);
	// stw r8,21924(r31)
	REX_STORE_U32(ctx.r31.u32 + 21924, ctx.r8.u32);
	// sth r7,21928(r31)
	REX_STORE_U16(ctx.r31.u32 + 21928, ctx.r7.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AD78;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,688(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 688);
	// lbz r8,692(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 692);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,22176(r31)
	REX_STORE_U16(ctx.r31.u32 + 22176, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,22178(r31)
	REX_STORE_U16(ctx.r31.u32 + 22178, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,22180(r31)
	REX_STORE_U16(ctx.r31.u32 + 22180, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,22182(r31)
	REX_STORE_U16(ctx.r31.u32 + 22182, ctx.r11.u16);
	// addi r3,r31,22189
	ctx.r3.s64 = ctx.r31.s64 + 22189;
	// stw r6,22184(r31)
	REX_STORE_U32(ctx.r31.u32 + 22184, ctx.r6.u32);
	// stb r8,22188(r31)
	REX_STORE_U8(ctx.r31.u32 + 22188, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6ADB8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,680(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 680);
	// li r10,4
	ctx.r10.s64 = 4;
	// lbz r6,684(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 684);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,22440(r31)
	REX_STORE_U16(ctx.r31.u32 + 22440, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r10,22442(r31)
	REX_STORE_U16(ctx.r31.u32 + 22442, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,22444(r31)
	REX_STORE_U16(ctx.r31.u32 + 22444, ctx.r9.u16);
	// addi r3,r31,22453
	ctx.r3.s64 = ctx.r31.s64 + 22453;
	// sth r11,22446(r31)
	REX_STORE_U16(ctx.r31.u32 + 22446, ctx.r11.u16);
	// stw r7,22448(r31)
	REX_STORE_U32(ctx.r31.u32 + 22448, ctx.r7.u32);
	// stb r6,22452(r31)
	REX_STORE_U8(ctx.r31.u32 + 22452, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6ADF8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,676(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 676);
	// li r5,252
	ctx.r5.s64 = 252;
	// sth r11,22704(r31)
	REX_STORE_U16(ctx.r31.u32 + 22704, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,22716
	ctx.r3.s64 = ctx.r31.s64 + 22716;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,22706(r31)
	REX_STORE_U16(ctx.r31.u32 + 22706, ctx.r11.u16);
	// sth r10,22708(r31)
	REX_STORE_U16(ctx.r31.u32 + 22708, ctx.r10.u16);
	// sth r9,22710(r31)
	REX_STORE_U16(ctx.r31.u32 + 22710, ctx.r9.u16);
	// stw r8,22712(r31)
	REX_STORE_U32(ctx.r31.u32 + 22712, ctx.r8.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AE30;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,668(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 668);
	// lbz r7,672(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 672);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,22968(r31)
	REX_STORE_U16(ctx.r31.u32 + 22968, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,22970(r31)
	REX_STORE_U16(ctx.r31.u32 + 22970, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,22972(r31)
	REX_STORE_U16(ctx.r31.u32 + 22972, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,22974(r31)
	REX_STORE_U16(ctx.r31.u32 + 22974, ctx.r11.u16);
	// addi r3,r31,22981
	ctx.r3.s64 = ctx.r31.s64 + 22981;
	// stw r8,22976(r31)
	REX_STORE_U32(ctx.r31.u32 + 22976, ctx.r8.u32);
	// stb r7,22980(r31)
	REX_STORE_U8(ctx.r31.u32 + 22980, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AE70;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,660(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 660);
	// li r10,4
	ctx.r10.s64 = 4;
	// lbz r8,664(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 664);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,23232(r31)
	REX_STORE_U16(ctx.r31.u32 + 23232, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r10,23234(r31)
	REX_STORE_U16(ctx.r31.u32 + 23234, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,23236(r31)
	REX_STORE_U16(ctx.r31.u32 + 23236, ctx.r9.u16);
	// addi r3,r31,23245
	ctx.r3.s64 = ctx.r31.s64 + 23245;
	// sth r11,23238(r31)
	REX_STORE_U16(ctx.r31.u32 + 23238, ctx.r11.u16);
	// stw r6,23240(r31)
	REX_STORE_U32(ctx.r31.u32 + 23240, ctx.r6.u32);
	// stb r8,23244(r31)
	REX_STORE_U8(ctx.r31.u32 + 23244, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AEB0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,652(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 652);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,23496(r31)
	REX_STORE_U16(ctx.r31.u32 + 23496, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,23498(r31)
	REX_STORE_U16(ctx.r31.u32 + 23498, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,23500(r31)
	REX_STORE_U16(ctx.r31.u32 + 23500, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,23502(r31)
	REX_STORE_U16(ctx.r31.u32 + 23502, ctx.r11.u16);
	// addi r3,r31,23512
	ctx.r3.s64 = ctx.r31.s64 + 23512;
	// std r8,23504(r31)
	REX_STORE_U64(ctx.r31.u32 + 23504, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AEE8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,644(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 644);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,23760(r31)
	REX_STORE_U16(ctx.r31.u32 + 23760, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,23762(r31)
	REX_STORE_U16(ctx.r31.u32 + 23762, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,23764(r31)
	REX_STORE_U16(ctx.r31.u32 + 23764, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,23766(r31)
	REX_STORE_U16(ctx.r31.u32 + 23766, ctx.r11.u16);
	// addi r3,r31,23776
	ctx.r3.s64 = ctx.r31.s64 + 23776;
	// std r8,23768(r31)
	REX_STORE_U64(ctx.r31.u32 + 23768, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AF20;
	sub_82F273F0(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// lwz r7,636(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 636);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,640(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 640);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,24026(r31)
	REX_STORE_U16(ctx.r31.u32 + 24026, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r9,642(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 642);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,24024(r31)
	REX_STORE_U16(ctx.r31.u32 + 24024, ctx.r11.u16);
	// addi r3,r31,24039
	ctx.r3.s64 = ctx.r31.s64 + 24039;
	// stw r7,24032(r31)
	REX_STORE_U32(ctx.r31.u32 + 24032, ctx.r7.u32);
	// sth r6,24036(r31)
	REX_STORE_U16(ctx.r31.u32 + 24036, ctx.r6.u16);
	// sth r11,24028(r31)
	REX_STORE_U16(ctx.r31.u32 + 24028, ctx.r11.u16);
	// sth r10,24030(r31)
	REX_STORE_U16(ctx.r31.u32 + 24030, ctx.r10.u16);
	// stb r9,24038(r31)
	REX_STORE_U8(ctx.r31.u32 + 24038, ctx.r9.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AF64;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,628(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 628);
	// lhz r7,632(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 632);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,24288(r31)
	REX_STORE_U16(ctx.r31.u32 + 24288, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,24290(r31)
	REX_STORE_U16(ctx.r31.u32 + 24290, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,24292(r31)
	REX_STORE_U16(ctx.r31.u32 + 24292, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,24294(r31)
	REX_STORE_U16(ctx.r31.u32 + 24294, ctx.r11.u16);
	// addi r3,r31,24302
	ctx.r3.s64 = ctx.r31.s64 + 24302;
	// stw r8,24296(r31)
	REX_STORE_U32(ctx.r31.u32 + 24296, ctx.r8.u32);
	// sth r7,24300(r31)
	REX_STORE_U16(ctx.r31.u32 + 24300, ctx.r7.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AFA4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,616(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 616);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r8,620(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 620);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r7,624(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 624);
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r11,24552(r31)
	REX_STORE_U16(ctx.r31.u32 + 24552, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,24554(r31)
	REX_STORE_U16(ctx.r31.u32 + 24554, ctx.r10.u16);
	// addi r3,r31,24569
	ctx.r3.s64 = ctx.r31.s64 + 24569;
	// sth r9,24556(r31)
	REX_STORE_U16(ctx.r31.u32 + 24556, ctx.r9.u16);
	// sth r11,24558(r31)
	REX_STORE_U16(ctx.r31.u32 + 24558, ctx.r11.u16);
	// stw r6,24560(r31)
	REX_STORE_U32(ctx.r31.u32 + 24560, ctx.r6.u32);
	// stw r8,24564(r31)
	REX_STORE_U32(ctx.r31.u32 + 24564, ctx.r8.u32);
	// stb r7,24568(r31)
	REX_STORE_U8(ctx.r31.u32 + 24568, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6AFEC;
	sub_82F273F0(ctx, base);
	// lwz r6,608(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 608);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r7,612(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 612);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r29,614(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 614);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,24816(r31)
	REX_STORE_U16(ctx.r31.u32 + 24816, ctx.r11.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,24818(r31)
	REX_STORE_U16(ctx.r31.u32 + 24818, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,24820(r31)
	REX_STORE_U16(ctx.r31.u32 + 24820, ctx.r9.u16);
	// addi r3,r31,24831
	ctx.r3.s64 = ctx.r31.s64 + 24831;
	// sth r8,24822(r31)
	REX_STORE_U16(ctx.r31.u32 + 24822, ctx.r8.u16);
	// stw r6,24824(r31)
	REX_STORE_U32(ctx.r31.u32 + 24824, ctx.r6.u32);
	// sth r7,24828(r31)
	REX_STORE_U16(ctx.r31.u32 + 24828, ctx.r7.u16);
	// stb r29,24830(r31)
	REX_STORE_U8(ctx.r31.u32 + 24830, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B034;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,600(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 600);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,25080(r31)
	REX_STORE_U16(ctx.r31.u32 + 25080, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,25082(r31)
	REX_STORE_U16(ctx.r31.u32 + 25082, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,25084(r31)
	REX_STORE_U16(ctx.r31.u32 + 25084, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,25086(r31)
	REX_STORE_U16(ctx.r31.u32 + 25086, ctx.r11.u16);
	// addi r3,r31,25096
	ctx.r3.s64 = ctx.r31.s64 + 25096;
	// std r8,25088(r31)
	REX_STORE_U64(ctx.r31.u32 + 25088, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B06C;
	sub_82F273F0(ctx, base);
	// lhz r9,596(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 596);
	// lwz r6,592(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r8,598(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 598);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,25344(r31)
	REX_STORE_U16(ctx.r31.u32 + 25344, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,25359
	ctx.r3.s64 = ctx.r31.s64 + 25359;
	// sth r9,25356(r31)
	REX_STORE_U16(ctx.r31.u32 + 25356, ctx.r9.u16);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r6,25352(r31)
	REX_STORE_U32(ctx.r31.u32 + 25352, ctx.r6.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,25346(r31)
	REX_STORE_U16(ctx.r31.u32 + 25346, ctx.r10.u16);
	// sth r9,25348(r31)
	REX_STORE_U16(ctx.r31.u32 + 25348, ctx.r9.u16);
	// sth r11,25350(r31)
	REX_STORE_U16(ctx.r31.u32 + 25350, ctx.r11.u16);
	// stb r8,25358(r31)
	REX_STORE_U8(ctx.r31.u32 + 25358, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B0B4;
	sub_82F273F0(ctx, base);
	// lwz r7,580(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 580);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,584(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 584);
	// li r10,10
	ctx.r10.s64 = 10;
	// lhz r29,588(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 588);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r28,590(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 590);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r11,25608(r31)
	REX_STORE_U16(ctx.r31.u32 + 25608, ctx.r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,25610(r31)
	REX_STORE_U16(ctx.r31.u32 + 25610, ctx.r10.u16);
	// addi r3,r31,25627
	ctx.r3.s64 = ctx.r31.s64 + 25627;
	// sth r9,25612(r31)
	REX_STORE_U16(ctx.r31.u32 + 25612, ctx.r9.u16);
	// sth r8,25614(r31)
	REX_STORE_U16(ctx.r31.u32 + 25614, ctx.r8.u16);
	// stw r7,25616(r31)
	REX_STORE_U32(ctx.r31.u32 + 25616, ctx.r7.u32);
	// stw r6,25620(r31)
	REX_STORE_U32(ctx.r31.u32 + 25620, ctx.r6.u32);
	// sth r29,25624(r31)
	REX_STORE_U16(ctx.r31.u32 + 25624, ctx.r29.u16);
	// stb r28,25626(r31)
	REX_STORE_U8(ctx.r31.u32 + 25626, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B104;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,576(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 576);
	// li r10,3
	ctx.r10.s64 = 3;
	// sth r11,25872(r31)
	REX_STORE_U16(ctx.r31.u32 + 25872, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,25874(r31)
	REX_STORE_U16(ctx.r31.u32 + 25874, ctx.r10.u16);
	// li r5,252
	ctx.r5.s64 = 252;
	// sth r9,25876(r31)
	REX_STORE_U16(ctx.r31.u32 + 25876, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,25878(r31)
	REX_STORE_U16(ctx.r31.u32 + 25878, ctx.r11.u16);
	// addi r3,r31,25884
	ctx.r3.s64 = ctx.r31.s64 + 25884;
	// stw r8,25880(r31)
	REX_STORE_U32(ctx.r31.u32 + 25880, ctx.r8.u32);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B13C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,564(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 564);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r7,568(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 568);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r6,572(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 572);
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r11,26136(r31)
	REX_STORE_U16(ctx.r31.u32 + 26136, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,26138(r31)
	REX_STORE_U16(ctx.r31.u32 + 26138, ctx.r10.u16);
	// addi r3,r31,26153
	ctx.r3.s64 = ctx.r31.s64 + 26153;
	// sth r9,26140(r31)
	REX_STORE_U16(ctx.r31.u32 + 26140, ctx.r9.u16);
	// sth r11,26142(r31)
	REX_STORE_U16(ctx.r31.u32 + 26142, ctx.r11.u16);
	// stw r8,26144(r31)
	REX_STORE_U32(ctx.r31.u32 + 26144, ctx.r8.u32);
	// stw r7,26148(r31)
	REX_STORE_U32(ctx.r31.u32 + 26148, ctx.r7.u32);
	// stb r6,26152(r31)
	REX_STORE_U8(ctx.r31.u32 + 26152, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B184;
	sub_82F273F0(ctx, base);
	// lwz r7,556(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 556);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r6,560(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 560);
	// li r10,6
	ctx.r10.s64 = 6;
	// lbz r29,562(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 562);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,26400(r31)
	REX_STORE_U16(ctx.r31.u32 + 26400, ctx.r11.u16);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r10,26402(r31)
	REX_STORE_U16(ctx.r31.u32 + 26402, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,26404(r31)
	REX_STORE_U16(ctx.r31.u32 + 26404, ctx.r9.u16);
	// addi r3,r31,26415
	ctx.r3.s64 = ctx.r31.s64 + 26415;
	// sth r8,26406(r31)
	REX_STORE_U16(ctx.r31.u32 + 26406, ctx.r8.u16);
	// stw r7,26408(r31)
	REX_STORE_U32(ctx.r31.u32 + 26408, ctx.r7.u32);
	// sth r6,26412(r31)
	REX_STORE_U16(ctx.r31.u32 + 26412, ctx.r6.u16);
	// stb r29,26414(r31)
	REX_STORE_U8(ctx.r31.u32 + 26414, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B1CC;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r5,548(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 548);
	// lhz r8,552(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 552);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,26664(r31)
	REX_STORE_U16(ctx.r31.u32 + 26664, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r5,26672(r31)
	REX_STORE_U32(ctx.r31.u32 + 26672, ctx.r5.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r10,26666(r31)
	REX_STORE_U16(ctx.r31.u32 + 26666, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,26668(r31)
	REX_STORE_U16(ctx.r31.u32 + 26668, ctx.r9.u16);
	// addi r3,r31,26678
	ctx.r3.s64 = ctx.r31.s64 + 26678;
	// sth r11,26670(r31)
	REX_STORE_U16(ctx.r31.u32 + 26670, ctx.r11.u16);
	// sth r8,26676(r31)
	REX_STORE_U16(ctx.r31.u32 + 26676, ctx.r8.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B20C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,540(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 540);
	// li r10,5
	ctx.r10.s64 = 5;
	// lhz r6,544(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 544);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,26928(r31)
	REX_STORE_U16(ctx.r31.u32 + 26928, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r10,26930(r31)
	REX_STORE_U16(ctx.r31.u32 + 26930, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,26932(r31)
	REX_STORE_U16(ctx.r31.u32 + 26932, ctx.r9.u16);
	// addi r3,r31,26942
	ctx.r3.s64 = ctx.r31.s64 + 26942;
	// sth r11,26934(r31)
	REX_STORE_U16(ctx.r31.u32 + 26934, ctx.r11.u16);
	// stw r7,26936(r31)
	REX_STORE_U32(ctx.r31.u32 + 26936, ctx.r7.u32);
	// sth r6,26940(r31)
	REX_STORE_U16(ctx.r31.u32 + 26940, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B24C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,532(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 532);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,27192(r31)
	REX_STORE_U16(ctx.r31.u32 + 27192, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,27194(r31)
	REX_STORE_U16(ctx.r31.u32 + 27194, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,27196(r31)
	REX_STORE_U16(ctx.r31.u32 + 27196, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,27198(r31)
	REX_STORE_U16(ctx.r31.u32 + 27198, ctx.r11.u16);
	// addi r3,r31,27208
	ctx.r3.s64 = ctx.r31.s64 + 27208;
	// std r8,27200(r31)
	REX_STORE_U64(ctx.r31.u32 + 27200, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B284;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,520(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 520);
	// li r10,9
	ctx.r10.s64 = 9;
	// lwz r7,524(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 524);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r6,528(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 528);
	// li r5,246
	ctx.r5.s64 = 246;
	// sth r11,27456(r31)
	REX_STORE_U16(ctx.r31.u32 + 27456, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,27458(r31)
	REX_STORE_U16(ctx.r31.u32 + 27458, ctx.r10.u16);
	// addi r3,r31,27474
	ctx.r3.s64 = ctx.r31.s64 + 27474;
	// sth r9,27460(r31)
	REX_STORE_U16(ctx.r31.u32 + 27460, ctx.r9.u16);
	// sth r11,27462(r31)
	REX_STORE_U16(ctx.r31.u32 + 27462, ctx.r11.u16);
	// stw r8,27464(r31)
	REX_STORE_U32(ctx.r31.u32 + 27464, ctx.r8.u32);
	// stw r7,27468(r31)
	REX_STORE_U32(ctx.r31.u32 + 27468, ctx.r7.u32);
	// sth r6,27472(r31)
	REX_STORE_U16(ctx.r31.u32 + 27472, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B2CC;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,31
	ctx.r11.s64 = 31;
	// sth r10,27720(r31)
	REX_STORE_U16(ctx.r31.u32 + 27720, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,488
	ctx.r7.s64 = ctx.r30.s64 + 488;
	// li r9,30
	ctx.r9.s64 = 30;
	// sth r10,27726(r31)
	REX_STORE_U16(ctx.r31.u32 + 27726, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,27722(r31)
	REX_STORE_U16(ctx.r31.u32 + 27722, ctx.r9.u16);
	// sth r8,27724(r31)
	REX_STORE_U16(ctx.r31.u32 + 27724, ctx.r8.u16);
	// addi r10,r31,27727
	ctx.r10.s64 = ctx.r31.s64 + 27727;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_82F6B300:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b300
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B300;
	// li r5,225
	ctx.r5.s64 = 225;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,27759
	ctx.r3.s64 = ctx.r31.s64 + 27759;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B31C;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,25
	ctx.r11.s64 = 25;
	// sth r10,27984(r31)
	REX_STORE_U16(ctx.r31.u32 + 27984, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,460
	ctx.r7.s64 = ctx.r30.s64 + 460;
	// li r9,24
	ctx.r9.s64 = 24;
	// sth r10,27990(r31)
	REX_STORE_U16(ctx.r31.u32 + 27990, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,27986(r31)
	REX_STORE_U16(ctx.r31.u32 + 27986, ctx.r9.u16);
	// sth r8,27988(r31)
	REX_STORE_U16(ctx.r31.u32 + 27988, ctx.r8.u16);
	// addi r10,r31,27991
	ctx.r10.s64 = ctx.r31.s64 + 27991;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_82F6B350:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b350
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B350;
	// li r5,231
	ctx.r5.s64 = 231;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,28017
	ctx.r3.s64 = ctx.r31.s64 + 28017;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B36C;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,25
	ctx.r11.s64 = 25;
	// sth r10,28248(r31)
	REX_STORE_U16(ctx.r31.u32 + 28248, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,432
	ctx.r7.s64 = ctx.r30.s64 + 432;
	// li r9,24
	ctx.r9.s64 = 24;
	// sth r10,28254(r31)
	REX_STORE_U16(ctx.r31.u32 + 28254, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,28250(r31)
	REX_STORE_U16(ctx.r31.u32 + 28250, ctx.r9.u16);
	// sth r8,28252(r31)
	REX_STORE_U16(ctx.r31.u32 + 28252, ctx.r8.u16);
	// addi r10,r31,28255
	ctx.r10.s64 = ctx.r31.s64 + 28255;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_82F6B3A0:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b3a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B3A0;
	// li r5,231
	ctx.r5.s64 = 231;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,28281
	ctx.r3.s64 = ctx.r31.s64 + 28281;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B3BC;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,13
	ctx.r11.s64 = 13;
	// sth r10,28512(r31)
	REX_STORE_U16(ctx.r31.u32 + 28512, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,404
	ctx.r7.s64 = ctx.r30.s64 + 404;
	// li r9,25
	ctx.r9.s64 = 25;
	// sth r10,28518(r31)
	REX_STORE_U16(ctx.r31.u32 + 28518, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,28514(r31)
	REX_STORE_U16(ctx.r31.u32 + 28514, ctx.r9.u16);
	// sth r8,28516(r31)
	REX_STORE_U16(ctx.r31.u32 + 28516, ctx.r8.u16);
	// addi r10,r31,28518
	ctx.r10.s64 = ctx.r31.s64 + 28518;
	// addi r11,r7,-2
	ctx.r11.s64 = ctx.r7.s64 + -2;
loc_82F6B3F0:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b3f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B3F0;
	// li r5,230
	ctx.r5.s64 = 230;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,28546
	ctx.r3.s64 = ctx.r31.s64 + 28546;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B40C;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,33
	ctx.r11.s64 = 33;
	// sth r10,28776(r31)
	REX_STORE_U16(ctx.r31.u32 + 28776, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,368
	ctx.r7.s64 = ctx.r30.s64 + 368;
	// li r9,32
	ctx.r9.s64 = 32;
	// sth r10,28782(r31)
	REX_STORE_U16(ctx.r31.u32 + 28782, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,28778(r31)
	REX_STORE_U16(ctx.r31.u32 + 28778, ctx.r9.u16);
	// sth r8,28780(r31)
	REX_STORE_U16(ctx.r31.u32 + 28780, ctx.r8.u16);
	// addi r10,r31,28783
	ctx.r10.s64 = ctx.r31.s64 + 28783;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_82F6B440:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b440
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B440;
	// li r5,223
	ctx.r5.s64 = 223;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,28817
	ctx.r3.s64 = ctx.r31.s64 + 28817;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B45C;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,8
	ctx.r11.s64 = 8;
	// sth r10,29040(r31)
	REX_STORE_U16(ctx.r31.u32 + 29040, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,336
	ctx.r7.s64 = ctx.r30.s64 + 336;
	// li r9,31
	ctx.r9.s64 = 31;
	// sth r10,29046(r31)
	REX_STORE_U16(ctx.r31.u32 + 29046, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,29042(r31)
	REX_STORE_U16(ctx.r31.u32 + 29042, ctx.r9.u16);
	// sth r8,29044(r31)
	REX_STORE_U16(ctx.r31.u32 + 29044, ctx.r8.u16);
	// addi r10,r31,29044
	ctx.r10.s64 = ctx.r31.s64 + 29044;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
loc_82F6B490:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b490
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B490;
	// li r5,224
	ctx.r5.s64 = 224;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,29080
	ctx.r3.s64 = ctx.r31.s64 + 29080;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B4AC;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,8
	ctx.r11.s64 = 8;
	// sth r10,29304(r31)
	REX_STORE_U16(ctx.r31.u32 + 29304, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,304
	ctx.r7.s64 = ctx.r30.s64 + 304;
	// li r9,31
	ctx.r9.s64 = 31;
	// sth r10,29310(r31)
	REX_STORE_U16(ctx.r31.u32 + 29310, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,29306(r31)
	REX_STORE_U16(ctx.r31.u32 + 29306, ctx.r9.u16);
	// sth r8,29308(r31)
	REX_STORE_U16(ctx.r31.u32 + 29308, ctx.r8.u16);
	// addi r10,r31,29308
	ctx.r10.s64 = ctx.r31.s64 + 29308;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
loc_82F6B4E0:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b4e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B4E0;
	// li r5,224
	ctx.r5.s64 = 224;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,29344
	ctx.r3.s64 = ctx.r31.s64 + 29344;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B4FC;
	sub_82F273F0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,17
	ctx.r11.s64 = 17;
	// sth r10,29568(r31)
	REX_STORE_U16(ctx.r31.u32 + 29568, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r30,268
	ctx.r7.s64 = ctx.r30.s64 + 268;
	// li r9,33
	ctx.r9.s64 = 33;
	// sth r10,29574(r31)
	REX_STORE_U16(ctx.r31.u32 + 29574, ctx.r10.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// sth r9,29570(r31)
	REX_STORE_U16(ctx.r31.u32 + 29570, ctx.r9.u16);
	// sth r8,29572(r31)
	REX_STORE_U16(ctx.r31.u32 + 29572, ctx.r8.u16);
	// addi r10,r31,29574
	ctx.r10.s64 = ctx.r31.s64 + 29574;
	// addi r11,r7,-2
	ctx.r11.s64 = ctx.r7.s64 + -2;
loc_82F6B530:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6b530
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6B530;
	// li r5,222
	ctx.r5.s64 = 222;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,29610
	ctx.r3.s64 = ctx.r31.s64 + 29610;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B54C;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,260(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 260);
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r7,264(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 264);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r6,266(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 266);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,29832(r31)
	REX_STORE_U16(ctx.r31.u32 + 29832, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,29834(r31)
	REX_STORE_U16(ctx.r31.u32 + 29834, ctx.r10.u16);
	// addi r3,r31,29847
	ctx.r3.s64 = ctx.r31.s64 + 29847;
	// sth r9,29836(r31)
	REX_STORE_U16(ctx.r31.u32 + 29836, ctx.r9.u16);
	// sth r11,29838(r31)
	REX_STORE_U16(ctx.r31.u32 + 29838, ctx.r11.u16);
	// stw r8,29840(r31)
	REX_STORE_U32(ctx.r31.u32 + 29840, ctx.r8.u32);
	// sth r7,29844(r31)
	REX_STORE_U16(ctx.r31.u32 + 29844, ctx.r7.u16);
	// stb r6,29846(r31)
	REX_STORE_U8(ctx.r31.u32 + 29846, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B594;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,252(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// lhz r7,256(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 256);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,30096(r31)
	REX_STORE_U16(ctx.r31.u32 + 30096, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,30098(r31)
	REX_STORE_U16(ctx.r31.u32 + 30098, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,30100(r31)
	REX_STORE_U16(ctx.r31.u32 + 30100, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,30102(r31)
	REX_STORE_U16(ctx.r31.u32 + 30102, ctx.r11.u16);
	// addi r3,r31,30110
	ctx.r3.s64 = ctx.r31.s64 + 30110;
	// stw r8,30104(r31)
	REX_STORE_U32(ctx.r31.u32 + 30104, ctx.r8.u32);
	// sth r7,30108(r31)
	REX_STORE_U16(ctx.r31.u32 + 30108, ctx.r7.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B5D4;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,244(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 244);
	// li r10,4
	ctx.r10.s64 = 4;
	// lbz r8,248(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 248);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,30360(r31)
	REX_STORE_U16(ctx.r31.u32 + 30360, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r10,30362(r31)
	REX_STORE_U16(ctx.r31.u32 + 30362, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,30364(r31)
	REX_STORE_U16(ctx.r31.u32 + 30364, ctx.r9.u16);
	// addi r3,r31,30373
	ctx.r3.s64 = ctx.r31.s64 + 30373;
	// sth r11,30366(r31)
	REX_STORE_U16(ctx.r31.u32 + 30366, ctx.r11.u16);
	// stw r6,30368(r31)
	REX_STORE_U32(ctx.r31.u32 + 30368, ctx.r6.u32);
	// stb r8,30372(r31)
	REX_STORE_U8(ctx.r31.u32 + 30372, ctx.r8.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B614;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,236(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 236);
	// lhz r6,240(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 240);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,30624(r31)
	REX_STORE_U16(ctx.r31.u32 + 30624, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,30626(r31)
	REX_STORE_U16(ctx.r31.u32 + 30626, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,30628(r31)
	REX_STORE_U16(ctx.r31.u32 + 30628, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,30630(r31)
	REX_STORE_U16(ctx.r31.u32 + 30630, ctx.r11.u16);
	// addi r3,r31,30638
	ctx.r3.s64 = ctx.r31.s64 + 30638;
	// stw r7,30632(r31)
	REX_STORE_U32(ctx.r31.u32 + 30632, ctx.r7.u32);
	// sth r6,30636(r31)
	REX_STORE_U16(ctx.r31.u32 + 30636, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B654;
	sub_82F273F0(ctx, base);
	// lwz r9,228(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 228);
	// li r10,5
	ctx.r10.s64 = 5;
	// lhz r8,232(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 232);
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r10,30890(r31)
	REX_STORE_U16(ctx.r31.u32 + 30890, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,30888(r31)
	REX_STORE_U16(ctx.r31.u32 + 30888, ctx.r11.u16);
	// addi r3,r31,30902
	ctx.r3.s64 = ctx.r31.s64 + 30902;
	// stw r9,30896(r31)
	REX_STORE_U32(ctx.r31.u32 + 30896, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r8,30900(r31)
	REX_STORE_U16(ctx.r31.u32 + 30900, ctx.r8.u16);
	// sth r11,30892(r31)
	REX_STORE_U16(ctx.r31.u32 + 30892, ctx.r11.u16);
	// sth r10,30894(r31)
	REX_STORE_U16(ctx.r31.u32 + 30894, ctx.r10.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B690;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r7,220(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// lhz r6,224(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 224);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r11,31152(r31)
	REX_STORE_U16(ctx.r31.u32 + 31152, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,31154(r31)
	REX_STORE_U16(ctx.r31.u32 + 31154, ctx.r10.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// sth r9,31156(r31)
	REX_STORE_U16(ctx.r31.u32 + 31156, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,31158(r31)
	REX_STORE_U16(ctx.r31.u32 + 31158, ctx.r11.u16);
	// addi r3,r31,31166
	ctx.r3.s64 = ctx.r31.s64 + 31166;
	// stw r7,31160(r31)
	REX_STORE_U32(ctx.r31.u32 + 31160, ctx.r7.u32);
	// sth r6,31164(r31)
	REX_STORE_U16(ctx.r31.u32 + 31164, ctx.r6.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B6D0;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,212(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 212);
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r7,216(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 216);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r6,218(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 218);
	// li r5,249
	ctx.r5.s64 = 249;
	// sth r11,31416(r31)
	REX_STORE_U16(ctx.r31.u32 + 31416, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,31418(r31)
	REX_STORE_U16(ctx.r31.u32 + 31418, ctx.r10.u16);
	// addi r3,r31,31431
	ctx.r3.s64 = ctx.r31.s64 + 31431;
	// sth r9,31420(r31)
	REX_STORE_U16(ctx.r31.u32 + 31420, ctx.r9.u16);
	// sth r11,31422(r31)
	REX_STORE_U16(ctx.r31.u32 + 31422, ctx.r11.u16);
	// stw r8,31424(r31)
	REX_STORE_U32(ctx.r31.u32 + 31424, ctx.r8.u32);
	// sth r7,31428(r31)
	REX_STORE_U16(ctx.r31.u32 + 31428, ctx.r7.u16);
	// stb r6,31430(r31)
	REX_STORE_U8(ctx.r31.u32 + 31430, ctx.r6.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B718;
	sub_82F273F0(ctx, base);
	// lwz r7,200(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 200);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,204(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r29,208(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 208);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,31680(r31)
	REX_STORE_U16(ctx.r31.u32 + 31680, ctx.r11.u16);
	// li r5,247
	ctx.r5.s64 = 247;
	// sth r10,31682(r31)
	REX_STORE_U16(ctx.r31.u32 + 31682, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,31684(r31)
	REX_STORE_U16(ctx.r31.u32 + 31684, ctx.r9.u16);
	// addi r3,r31,31697
	ctx.r3.s64 = ctx.r31.s64 + 31697;
	// sth r8,31686(r31)
	REX_STORE_U16(ctx.r31.u32 + 31686, ctx.r8.u16);
	// stw r7,31688(r31)
	REX_STORE_U32(ctx.r31.u32 + 31688, ctx.r7.u32);
	// stw r6,31692(r31)
	REX_STORE_U32(ctx.r31.u32 + 31692, ctx.r6.u32);
	// stb r29,31696(r31)
	REX_STORE_U8(ctx.r31.u32 + 31696, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B760;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// ld r8,192(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 192);
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r11,31944(r31)
	REX_STORE_U16(ctx.r31.u32 + 31944, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,31946(r31)
	REX_STORE_U16(ctx.r31.u32 + 31946, ctx.r10.u16);
	// li r5,248
	ctx.r5.s64 = 248;
	// sth r9,31948(r31)
	REX_STORE_U16(ctx.r31.u32 + 31948, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,31950(r31)
	REX_STORE_U16(ctx.r31.u32 + 31950, ctx.r11.u16);
	// addi r3,r31,31960
	ctx.r3.s64 = ctx.r31.s64 + 31960;
	// std r8,31952(r31)
	REX_STORE_U64(ctx.r31.u32 + 31952, ctx.r8.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B798;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,180(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 180);
	// li r5,245
	ctx.r5.s64 = 245;
	// lwz r7,184(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r6,188(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 188);
	// addi r3,r31,32227
	ctx.r3.s64 = ctx.r31.s64 + 32227;
	// lbz r29,190(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 190);
	// li r10,10
	ctx.r10.s64 = 10;
	// sth r11,32208(r31)
	REX_STORE_U16(ctx.r31.u32 + 32208, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r8,32216(r31)
	REX_STORE_U32(ctx.r31.u32 + 32216, ctx.r8.u32);
	// stw r7,32220(r31)
	REX_STORE_U32(ctx.r31.u32 + 32220, ctx.r7.u32);
	// sth r10,32210(r31)
	REX_STORE_U16(ctx.r31.u32 + 32210, ctx.r10.u16);
	// sth r9,32212(r31)
	REX_STORE_U16(ctx.r31.u32 + 32212, ctx.r9.u16);
	// sth r11,32214(r31)
	REX_STORE_U16(ctx.r31.u32 + 32214, ctx.r11.u16);
	// sth r6,32224(r31)
	REX_STORE_U16(ctx.r31.u32 + 32224, ctx.r6.u16);
	// stb r29,32226(r31)
	REX_STORE_U8(ctx.r31.u32 + 32226, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B7E8;
	sub_82F273F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,172(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// lbz r7,176(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 176);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r11,32472(r31)
	REX_STORE_U16(ctx.r31.u32 + 32472, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,32474(r31)
	REX_STORE_U16(ctx.r31.u32 + 32474, ctx.r10.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// sth r9,32476(r31)
	REX_STORE_U16(ctx.r31.u32 + 32476, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,32478(r31)
	REX_STORE_U16(ctx.r31.u32 + 32478, ctx.r11.u16);
	// addi r3,r31,32485
	ctx.r3.s64 = ctx.r31.s64 + 32485;
	// stw r8,32480(r31)
	REX_STORE_U32(ctx.r31.u32 + 32480, ctx.r8.u32);
	// stb r7,32484(r31)
	REX_STORE_U8(ctx.r31.u32 + 32484, ctx.r7.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B828;
	sub_82F273F0(ctx, base);
	// lwz r6,160(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 160);
	// lwz r7,164(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 164);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r29,168(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 168);
	// li r10,10
	ctx.r10.s64 = 10;
	// lbz r28,170(r30)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + 170);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,32736(r31)
	REX_STORE_U16(ctx.r31.u32 + 32736, ctx.r11.u16);
	// li r5,245
	ctx.r5.s64 = 245;
	// sth r10,32738(r31)
	REX_STORE_U16(ctx.r31.u32 + 32738, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r9,32740(r31)
	REX_STORE_U16(ctx.r31.u32 + 32740, ctx.r9.u16);
	// addi r3,r31,32755
	ctx.r3.s64 = ctx.r31.s64 + 32755;
	// sth r8,32742(r31)
	REX_STORE_U16(ctx.r31.u32 + 32742, ctx.r8.u16);
	// stw r6,32744(r31)
	REX_STORE_U32(ctx.r31.u32 + 32744, ctx.r6.u32);
	// stw r7,32748(r31)
	REX_STORE_U32(ctx.r31.u32 + 32748, ctx.r7.u32);
	// sth r29,32752(r31)
	REX_STORE_U16(ctx.r31.u32 + 32752, ctx.r29.u16);
	// stb r28,32754(r31)
	REX_STORE_U8(ctx.r31.u32 + 32754, ctx.r28.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B878;
	sub_82F273F0(ctx, base);
	// lwz r6,144(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r9,152(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 152);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r4,148(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 148);
	// ori r8,r5,33000
	ctx.r8.u64 = ctx.r5.u64 | 33000;
	// lhz r7,156(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 156);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lbz r29,158(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 158);
	// stw r6,-32528(r11)
	REX_STORE_U32(ctx.r11.u32 + -32528, ctx.r6.u32);
	// addi r6,r11,-32528
	ctx.r6.s64 = ctx.r11.s64 + -32528;
	// ori r3,r3,33002
	ctx.r3.u64 = ctx.r3.u64 | 33002;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r27,r10,33006
	ctx.r27.u64 = ctx.r10.u64 | 33006;
	// ori r28,r5,33004
	ctx.r28.u64 = ctx.r5.u64 | 33004;
	// sthx r11,r31,r8
	REX_STORE_U16(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u16);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r9,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// stw r4,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// sthx r10,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r10.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r7,12(r6)
	REX_STORE_U16(ctx.r6.u32 + 12, ctx.r7.u16);
	// li r5,241
	ctx.r5.s64 = 241;
	// sthx r9,r31,r28
	REX_STORE_U16(ctx.r31.u32 + ctx.r28.u32, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r27
	REX_STORE_U16(ctx.r31.u32 + ctx.r27.u32, ctx.r11.u16);
	// addi r3,r8,-32513
	ctx.r3.s64 = ctx.r8.s64 + -32513;
	// stb r29,14(r6)
	REX_STORE_U8(ctx.r6.u32 + 14, ctx.r29.u8);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B8FC;
	sub_82F273F0(ctx, base);
	// lwz r10,128(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 128);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r4,r9,33264
	ctx.r4.u64 = ctx.r9.u64 | 33264;
	// lwz r5,136(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// addi r28,r11,-32264
	ctx.r28.s64 = ctx.r11.s64 + -32264;
	// lhz r3,140(r30)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r30.u32 + 140);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r10,-32264(r11)
	REX_STORE_U32(ctx.r11.u32 + -32264, ctx.r10.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lwz r7,132(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 132);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lbz r29,142(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 142);
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r27,r9,33268
	ctx.r27.u64 = ctx.r9.u64 | 33268;
	// stw r5,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r5.u32);
	// ori r26,r8,33270
	ctx.r26.u64 = ctx.r8.u64 | 33270;
	// sthx r11,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u16);
	// ori r6,r6,33266
	ctx.r6.u64 = ctx.r6.u64 | 33266;
	// sth r3,12(r28)
	REX_STORE_U16(ctx.r28.u32 + 12, ctx.r3.u16);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// stw r7,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r7.u32);
	// li r10,14
	ctx.r10.s64 = 14;
	// stb r29,14(r28)
	REX_STORE_U8(ctx.r28.u32 + 14, ctx.r29.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,241
	ctx.r5.s64 = 241;
	// sthx r10,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r9,r31,r27
	REX_STORE_U16(ctx.r31.u32 + ctx.r27.u32, ctx.r9.u16);
	// addi r3,r8,-32249
	ctx.r3.s64 = ctx.r8.s64 + -32249;
	// sthx r11,r31,r26
	REX_STORE_U16(ctx.r31.u32 + ctx.r26.u32, ctx.r11.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6B980;
	sub_82F273F0(ctx, base);
	// lwz r5,120(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lhz r4,124(r30)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r30.u32 + 124);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r3,33528
	ctx.r9.u64 = ctx.r3.u64 | 33528;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r5,-32000(r11)
	REX_STORE_U32(ctx.r11.u32 + -32000, ctx.r5.u32);
	// addi r6,r11,-32000
	ctx.r6.s64 = ctx.r11.s64 + -32000;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r5,r10,33530
	ctx.r5.u64 = ctx.r10.u64 | 33530;
	// ori r3,r8,33532
	ctx.r3.u64 = ctx.r8.u64 | 33532;
	// sthx r11,r31,r9
	REX_STORE_U16(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u16);
	// lis r7,0
	ctx.r7.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r4,4(r6)
	REX_STORE_U16(ctx.r6.u32 + 4, ctx.r4.u16);
	// ori r7,r7,33534
	ctx.r7.u64 = ctx.r7.u64 | 33534;
	// li r9,1
	ctx.r9.s64 = 1;
	// sthx r10,r31,r5
	REX_STORE_U16(ctx.r31.u32 + ctx.r5.u32, ctx.r10.u16);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r11,0
	ctx.r11.s64 = 0;
	// sthx r9,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r9.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u16);
	// addi r3,r8,-31994
	ctx.r3.s64 = ctx.r8.s64 + -31994;
	// bl 0x82f273f0
	ctx.lr = 0x82F6B9EC;
	sub_82F273F0(ctx, base);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// ori r7,r6,33792
	ctx.r7.u64 = ctx.r6.u64 | 33792;
	// lwz r6,112(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 112);
	// ori r4,r5,33794
	ctx.r4.u64 = ctx.r5.u64 | 33794;
	// lbz r29,116(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 116);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,8
	ctx.r10.s64 = 8;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// sthx r11,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u16);
	// sthx r10,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r10.u16);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r3,-31736(r8)
	REX_STORE_U32(ctx.r8.u32 + -31736, ctx.r3.u32);
	// addi r3,r9,-31727
	ctx.r3.s64 = ctx.r9.s64 + -31727;
	// stw r6,-31732(r8)
	REX_STORE_U32(ctx.r8.u32 + -31732, ctx.r6.u32);
	// ori r9,r7,33796
	ctx.r9.u64 = ctx.r7.u64 | 33796;
	// stb r29,-31728(r8)
	REX_STORE_U8(ctx.r8.u32 + -31728, ctx.r29.u8);
	// ori r7,r10,33798
	ctx.r7.u64 = ctx.r10.u64 | 33798;
	// li r5,247
	ctx.r5.s64 = 247;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// sthx r11,r31,r9
	REX_STORE_U16(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u16);
	// sthx r10,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r10.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6BA58;
	sub_82F273F0(ctx, base);
	// lwz r6,100(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lbz r9,106(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 106);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lhz r4,104(r30)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r30.u32 + 104);
	// ori r8,r5,34056
	ctx.r8.u64 = ctx.r5.u64 | 34056;
	// ori r3,r3,34058
	ctx.r3.u64 = ctx.r3.u64 | 34058;
	// stw r6,-31472(r11)
	REX_STORE_U32(ctx.r11.u32 + -31472, ctx.r6.u32);
	// addi r6,r11,-31472
	ctx.r6.s64 = ctx.r11.s64 + -31472;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r7,0
	ctx.r7.s64 = 0;
	// sthx r11,r31,r8
	REX_STORE_U16(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u16);
	// ori r29,r5,34062
	ctx.r29.u64 = ctx.r5.u64 | 34062;
	// ori r7,r7,34060
	ctx.r7.u64 = ctx.r7.u64 | 34060;
	// stb r9,6(r6)
	REX_STORE_U8(ctx.r6.u32 + 6, ctx.r9.u8);
	// li r10,6
	ctx.r10.s64 = 6;
	// sth r4,4(r6)
	REX_STORE_U16(ctx.r6.u32 + 4, ctx.r4.u16);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r9,1
	ctx.r9.s64 = 1;
	// sthx r10,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r10.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,249
	ctx.r5.s64 = 249;
	// sthx r9,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r29
	REX_STORE_U16(ctx.r31.u32 + ctx.r29.u32, ctx.r11.u16);
	// addi r3,r8,-31465
	ctx.r3.s64 = ctx.r8.s64 + -31465;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BACC;
	sub_82F273F0(ctx, base);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ld r8,92(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 92);
	// ori r4,r6,34320
	ctx.r4.u64 = ctx.r6.u64 | 34320;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r3,r3,34324
	ctx.r3.u64 = ctx.r3.u64 | 34324;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r28,r9,34328
	ctx.r28.u64 = ctx.r9.u64 | 34328;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r6,r5,34322
	ctx.r6.u64 = ctx.r5.u64 | 34322;
	// ori r29,r10,34326
	ctx.r29.u64 = ctx.r10.u64 | 34326;
	// sthx r11,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// stdx r8,r31,r28
	REX_STORE_U64(ctx.r31.u32 + ctx.r28.u32, ctx.r8.u64);
	// li r10,7
	ctx.r10.s64 = 7;
	// sthx r9,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r9.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,248
	ctx.r5.s64 = 248;
	// sthx r10,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r29
	REX_STORE_U16(ctx.r31.u32 + ctx.r29.u32, ctx.r11.u16);
	// addi r3,r7,-31200
	ctx.r3.s64 = ctx.r7.s64 + -31200;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BB30;
	sub_82F273F0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r7,r11,34586
	ctx.r7.u64 = ctx.r11.u64 | 34586;
	// ori r6,r10,34584
	ctx.r6.u64 = ctx.r10.u64 | 34584;
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// ori r4,r9,34588
	ctx.r4.u64 = ctx.r9.u64 | 34588;
	// li r11,1
	ctx.r11.s64 = 1;
	// sthx r10,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r10.u16);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// ld r10,84(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 84);
	// li r9,1
	ctx.r9.s64 = 1;
	// sthx r11,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u16);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// sthx r9,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r9.u16);
	// addi r3,r8,-30936
	ctx.r3.s64 = ctx.r8.s64 + -30936;
	// ori r9,r7,34590
	ctx.r9.u64 = ctx.r7.u64 | 34590;
	// ori r8,r6,34592
	ctx.r8.u64 = ctx.r6.u64 | 34592;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,248
	ctx.r5.s64 = 248;
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r9
	REX_STORE_U16(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u16);
	// stdx r10,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r10.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6BB94;
	sub_82F273F0(ctx, base);
	// lwz r7,76(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lhz r5,80(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 80);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r3,r6,34848
	ctx.r3.u64 = ctx.r6.u64 | 34848;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r7,-30680(r11)
	REX_STORE_U32(ctx.r11.u32 + -30680, ctx.r7.u32);
	// addi r7,r11,-30680
	ctx.r7.s64 = ctx.r11.s64 + -30680;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r6,r4,34850
	ctx.r6.u64 = ctx.r4.u64 | 34850;
	// sthx r11,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u16);
	// ori r4,r10,34852
	ctx.r4.u64 = ctx.r10.u64 | 34852;
	// ori r3,r9,34854
	ctx.r3.u64 = ctx.r9.u64 | 34854;
	// sth r5,4(r7)
	REX_STORE_U16(ctx.r7.u32 + 4, ctx.r5.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r10,5
	ctx.r10.s64 = 5;
	// sthx r9,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r9.u16);
	// sthx r11,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u16);
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r10,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u16);
	// addi r3,r8,-30674
	ctx.r3.s64 = ctx.r8.s64 + -30674;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BC00;
	sub_82F273F0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lwz r9,64(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// addi r29,r11,-30416
	ctx.r29.s64 = ctx.r11.s64 + -30416;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lhz r5,72(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 72);
	// ori r4,r8,35112
	ctx.r4.u64 = ctx.r8.u64 | 35112;
	// lwz r7,68(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// ori r3,r3,35116
	ctx.r3.u64 = ctx.r3.u64 | 35116;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r10,-30416(r11)
	REX_STORE_U32(ctx.r11.u32 + -30416, ctx.r10.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r5,12(r29)
	REX_STORE_U16(ctx.r29.u32 + 12, ctx.r5.u16);
	// ori r28,r8,35118
	ctx.r28.u64 = ctx.r8.u64 | 35118;
	// stw r7,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r7.u32);
	// ori r6,r6,35114
	ctx.r6.u64 = ctx.r6.u64 | 35114;
	// sthx r11,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r10,13
	ctx.r10.s64 = 13;
	// sthx r9,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r9.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,242
	ctx.r5.s64 = 242;
	// sthx r10,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r28
	REX_STORE_U16(ctx.r31.u32 + ctx.r28.u32, ctx.r11.u16);
	// addi r3,r8,-30402
	ctx.r3.s64 = ctx.r8.s64 + -30402;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BC7C;
	sub_82F273F0(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r7,r10,35378
	ctx.r7.u64 = ctx.r10.u64 | 35378;
	// li r10,7
	ctx.r10.s64 = 7;
	// ori r8,r11,35376
	ctx.r8.u64 = ctx.r11.u64 | 35376;
	// lis r6,0
	ctx.r6.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// sthx r10,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r10.u16);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r7,r6,35380
	ctx.r7.u64 = ctx.r6.u64 | 35380;
	// ori r6,r10,35382
	ctx.r6.u64 = ctx.r10.u64 | 35382;
	// sthx r11,r31,r8
	REX_STORE_U16(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u16);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r9,-30144
	ctx.r3.s64 = ctx.r9.s64 + -30144;
	// sthx r11,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u16);
	// ld r9,52(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 52);
	// li r5,248
	ctx.r5.s64 = 248;
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r10,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u16);
	// ori r11,r8,35384
	ctx.r11.u64 = ctx.r8.u64 | 35384;
	// stdx r9,r31,r11
	REX_STORE_U64(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u64);
	// bl 0x82f273f0
	ctx.lr = 0x82F6BCDC;
	sub_82F273F0(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,40(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r5,48(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// ori r6,r10,35640
	ctx.r6.u64 = ctx.r10.u64 | 35640;
	// lwz r7,44(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// addi r29,r11,-29888
	ctx.r29.s64 = ctx.r11.s64 + -29888;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r4,r4,35642
	ctx.r4.u64 = ctx.r4.u64 | 35642;
	// sthx r11,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u16);
	// ori r3,r3,35644
	ctx.r3.u64 = ctx.r3.u64 | 35644;
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// ori r6,r10,35646
	ctx.r6.u64 = ctx.r10.u64 | 35646;
	// stw r5,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r5.u32);
	// li r10,11
	ctx.r10.s64 = 11;
	// stw r7,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r7.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// sthx r10,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r10.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// sthx r9,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r9.u16);
	// li r5,244
	ctx.r5.s64 = 244;
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u16);
	// addi r3,r8,-29876
	ctx.r3.s64 = ctx.r8.s64 + -29876;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BD50;
	sub_82F273F0(ctx, base);
	// lwz r5,28(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,36(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r4,32(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r3,35904
	ctx.r7.u64 = ctx.r3.u64 | 35904;
	// lis r3,0
	ctx.r3.s64 = 0;
	// stw r5,-29624(r11)
	REX_STORE_U32(ctx.r11.u32 + -29624, ctx.r5.u32);
	// addi r5,r11,-29624
	ctx.r5.s64 = ctx.r11.s64 + -29624;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r3,r3,35910
	ctx.r3.u64 = ctx.r3.u64 | 35910;
	// lis r6,0
	ctx.r6.s64 = 0;
	// sthx r11,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u16);
	// ori r29,r8,35906
	ctx.r29.u64 = ctx.r8.u64 | 35906;
	// ori r6,r6,35908
	ctx.r6.u64 = ctx.r6.u64 | 35908;
	// stw r9,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r4.u32);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r10,11
	ctx.r10.s64 = 11;
	// sthx r11,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r5,244
	ctx.r5.s64 = 244;
	// sthx r10,r31,r29
	REX_STORE_U16(ctx.r31.u32 + ctx.r29.u32, ctx.r10.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r9,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r9.u16);
	// addi r3,r8,-29612
	ctx.r3.s64 = ctx.r8.s64 + -29612;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BDC4;
	sub_82F273F0(ctx, base);
	// lwz r9,16(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r8,20(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lbz r7,24(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 24);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-29351
	ctx.r3.s64 = ctx.r11.s64 + -29351;
	// li r5,247
	ctx.r5.s64 = 247;
	// stw r8,-29356(r10)
	REX_STORE_U32(ctx.r10.u32 + -29356, ctx.r8.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stb r7,-29352(r10)
	REX_STORE_U8(ctx.r10.u32 + -29352, ctx.r7.u8);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stw r9,-29360(r10)
	REX_STORE_U32(ctx.r10.u32 + -29360, ctx.r9.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r6,r6,36168
	ctx.r6.u64 = ctx.r6.u64 | 36168;
	// ori r29,r9,36170
	ctx.r29.u64 = ctx.r9.u64 | 36170;
	// ori r8,r8,36172
	ctx.r8.u64 = ctx.r8.u64 | 36172;
	// ori r7,r7,36174
	ctx.r7.u64 = ctx.r7.u64 | 36174;
	// li r10,8
	ctx.r10.s64 = 8;
	// sthx r11,r31,r6
	REX_STORE_U16(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// sthx r10,r31,r29
	REX_STORE_U16(ctx.r31.u32 + ctx.r29.u32, ctx.r10.u16);
	// sthx r9,r31,r8
	REX_STORE_U16(ctx.r31.u32 + ctx.r8.u32, ctx.r9.u16);
	// sthx r11,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u16);
	// bl 0x82f273f0
	ctx.lr = 0x82F6BE34;
	sub_82F273F0(ctx, base);
	// lwz r6,8(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lbz r9,14(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 14);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lhz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r30.u32 + 12);
	// ori r8,r5,36432
	ctx.r8.u64 = ctx.r5.u64 | 36432;
	// ori r3,r3,36434
	ctx.r3.u64 = ctx.r3.u64 | 36434;
	// stw r6,-29096(r11)
	REX_STORE_U32(ctx.r11.u32 + -29096, ctx.r6.u32);
	// addi r6,r11,-29096
	ctx.r6.s64 = ctx.r11.s64 + -29096;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r7,0
	ctx.r7.s64 = 0;
	// sthx r11,r31,r8
	REX_STORE_U16(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u16);
	// ori r29,r5,36438
	ctx.r29.u64 = ctx.r5.u64 | 36438;
	// ori r7,r7,36436
	ctx.r7.u64 = ctx.r7.u64 | 36436;
	// stb r9,6(r6)
	REX_STORE_U8(ctx.r6.u32 + 6, ctx.r9.u8);
	// li r10,6
	ctx.r10.s64 = 6;
	// sth r4,4(r6)
	REX_STORE_U16(ctx.r6.u32 + 4, ctx.r4.u16);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r9,1
	ctx.r9.s64 = 1;
	// sthx r10,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r10.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,249
	ctx.r5.s64 = 249;
	// sthx r9,r31,r7
	REX_STORE_U16(ctx.r31.u32 + ctx.r7.u32, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r11,r31,r29
	REX_STORE_U16(ctx.r31.u32 + ctx.r29.u32, ctx.r11.u16);
	// addi r3,r8,-29089
	ctx.r3.s64 = ctx.r8.s64 + -29089;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BEA8;
	sub_82F273F0(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lbz r7,4(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 4);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r4,r6,36696
	ctx.r4.u64 = ctx.r6.u64 | 36696;
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r3,-28832(r11)
	REX_STORE_U32(ctx.r11.u32 + -28832, ctx.r3.u32);
	// addi r6,r11,-28832
	ctx.r6.s64 = ctx.r11.s64 + -28832;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r3,r9,36702
	ctx.r3.u64 = ctx.r9.u64 | 36702;
	// ori r5,r5,36698
	ctx.r5.u64 = ctx.r5.u64 | 36698;
	// sthx r11,r31,r4
	REX_STORE_U16(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u16);
	// ori r30,r10,36700
	ctx.r30.u64 = ctx.r10.u64 | 36700;
	// stb r7,4(r6)
	REX_STORE_U8(ctx.r6.u32 + 4, ctx.r7.u8);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,0
	ctx.r11.s64 = 0;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r9,1
	ctx.r9.s64 = 1;
	// sthx r10,r31,r5
	REX_STORE_U16(ctx.r31.u32 + ctx.r5.u32, ctx.r10.u16);
	// sthx r11,r31,r3
	REX_STORE_U16(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u16);
	// li r5,251
	ctx.r5.s64 = 251;
	// li r4,0
	ctx.r4.s64 = 0;
	// sthx r9,r31,r30
	REX_STORE_U16(ctx.r31.u32 + ctx.r30.u32, ctx.r9.u16);
	// addi r3,r8,-28827
	ctx.r3.s64 = ctx.r8.s64 + -28827;
	// bl 0x82f273f0
	ctx.lr = 0x82F6BF14;
	sub_82F273F0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82f27510
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6BF20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,7952
	ctx.r3.s64 = ctx.r11.s64 + 7952;
	// bl 0x82f71ecc
	ctx.lr = 0x82F6BF38;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32009
	ctx.r10.s64 = -2097741824;
	// addi r3,r10,4584
	ctx.r3.s64 = ctx.r10.s64 + 4584;
	// bl 0x82f22d28
	ctx.lr = 0x82F6BF44;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6BF58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,7888
	ctx.r3.s64 = ctx.r11.s64 + 7888;
	// bl 0x82f71ecc
	ctx.lr = 0x82F6BF70;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32009
	ctx.r10.s64 = -2097741824;
	// addi r3,r10,4592
	ctx.r3.s64 = ctx.r10.s64 + 4592;
	// bl 0x82f22d28
	ctx.lr = 0x82F6BF7C;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6BF90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,7920
	ctx.r3.s64 = ctx.r11.s64 + 7920;
	// bl 0x82f71ecc
	ctx.lr = 0x82F6BFA8;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32009
	ctx.r10.s64 = -2097741824;
	// addi r3,r10,4600
	ctx.r3.s64 = ctx.r10.s64 + 4600;
	// bl 0x82f22d28
	ctx.lr = 0x82F6BFB4;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6BFC8) {
	REX_FUNC_PROLOGUE();
	// b 0x82e3a120
	sub_82E3A120(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6BFD0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4608
	ctx.r3.s64 = ctx.r11.s64 + 4608;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6BFE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4688
	ctx.r3.s64 = ctx.r11.s64 + 4688;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6BFF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4832
	ctx.r3.s64 = ctx.r11.s64 + 4832;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C000) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4840
	ctx.r3.s64 = ctx.r11.s64 + 4840;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C010) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// li r31,9
	ctx.r31.s64 = 9;
	// addi r30,r11,8104
	ctx.r30.s64 = ctx.r11.s64 + 8104;
loc_82F6C030:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82f71ecc
	ctx.lr = 0x82F6C038;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// bge 0x82f6c030
	if (!ctx.cr0.lt) goto loc_82F6C030;
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,4864
	ctx.r3.s64 = ctx.r11.s64 + 4864;
	// bl 0x82f22d28
	ctx.lr = 0x82F6C050;
	sub_82F22D28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C068) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31993
	ctx.r7.s64 = -2096693248;
	// lis r6,-31993
	ctx.r6.s64 = -2096693248;
	// addi r10,r7,8104
	ctx.r10.s64 = ctx.r7.s64 + 8104;
	// lwz r5,-26504(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + -26504);
	// lwz r11,-26504(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -26504);
	// rlwinm r9,r5,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r4,-26504(r8)
	REX_STORE_U32(ctx.r8.u32 + -26504, ctx.r4.u32);
	// stw r11,7984(r6)
	REX_STORE_U32(ctx.r6.u32 + 7984, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C098) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,5036
	ctx.r4.s64 = ctx.r11.s64 + 5036;
	// addi r3,r10,8660
	ctx.r3.s64 = ctx.r10.s64 + 8660;
	// b 0x823b3760
	sub_823B3760(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C0B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r4,r11,5048
	ctx.r4.s64 = ctx.r11.s64 + 5048;
	// addi r3,r10,8640
	ctx.r3.s64 = ctx.r10.s64 + 8640;
	// b 0x823b3760
	sub_823B3760(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C0C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x1)));
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r10,r11,8720
	ctx.r10.s64 = ctx.r11.s64 + 8720;
	// vcsxwfp128 v63,v63,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C0E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r10,8768
	ctx.r9.s64 = ctx.r10.s64 + 8768;
	// lvsl v0,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vspltb v0,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_set1_epi8(char(0xF))));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r11,7
	ctx.r11.s64 = 7;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r10,8736
	ctx.r9.s64 = ctx.r10.s64 + 8736;
	// lvsl v0,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vspltb v0,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_set1_epi8(char(0xF))));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C120) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r9,r11,8784
	ctx.r9.s64 = ctx.r11.s64 + 8784;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r9,r11,8704
	ctx.r9.s64 = ctx.r11.s64 + 8704;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C150) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,8752
	ctx.r9.s64 = ctx.r11.s64 + 8752;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r11,0
	ctx.r11.s64 = 0;
	// vspltisb v0,15
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0xF)));
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r9,r10,8688
	ctx.r9.s64 = ctx.r10.s64 + 8688;
	// lvsl v13,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vsububm v0,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C188) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18388
	ctx.r5.s64 = ctx.r6.s64 + -18388;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26427(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26427);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18388(r6)
	REX_STORE_U32(ctx.r6.u32 + -18388, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,4872
	ctx.r3.s64 = ctx.r4.s64 + 4872;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C1C8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18364
	ctx.r5.s64 = ctx.r6.s64 + -18364;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26426(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26426);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18364(r6)
	REX_STORE_U32(ctx.r6.u32 + -18364, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,4960
	ctx.r3.s64 = ctx.r4.s64 + 4960;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C208) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18340
	ctx.r5.s64 = ctx.r6.s64 + -18340;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26425(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26425);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18340(r6)
	REX_STORE_U32(ctx.r6.u32 + -18340, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5048
	ctx.r3.s64 = ctx.r4.s64 + 5048;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C248) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18316
	ctx.r5.s64 = ctx.r6.s64 + -18316;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26420(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26420);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18316(r6)
	REX_STORE_U32(ctx.r6.u32 + -18316, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5136
	ctx.r3.s64 = ctx.r4.s64 + 5136;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C288) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18292
	ctx.r5.s64 = ctx.r6.s64 + -18292;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26419(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26419);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18292(r6)
	REX_STORE_U32(ctx.r6.u32 + -18292, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5224
	ctx.r3.s64 = ctx.r4.s64 + 5224;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C2C8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18268
	ctx.r5.s64 = ctx.r6.s64 + -18268;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26418(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26418);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18268(r6)
	REX_STORE_U32(ctx.r6.u32 + -18268, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5312
	ctx.r3.s64 = ctx.r4.s64 + 5312;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C308) {
	REX_FUNC_PROLOGUE();
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18244
	ctx.r11.s64 = ctx.r11.s64 + -18244;
	// lwz r10,-32112(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + -32112);
	// lwz r9,-32108(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// beq cr6,0x82f6c334
	if (ctx.cr6.eq) goto loc_82F6C334;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_82F6C334:
	// stw r11,-32112(r7)
	REX_STORE_U32(ctx.r7.u32 + -32112, ctx.r11.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// stw r10,-32108(r8)
	REX_STORE_U32(ctx.r8.u32 + -32108, ctx.r10.u32);
	// addi r3,r11,5400
	ctx.r3.s64 = ctx.r11.s64 + 5400;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C350) {
	REX_FUNC_PROLOGUE();
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18228
	ctx.r11.s64 = ctx.r11.s64 + -18228;
	// lwz r10,-32112(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + -32112);
	// lwz r9,-32108(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// beq cr6,0x82f6c37c
	if (ctx.cr6.eq) goto loc_82F6C37C;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_82F6C37C:
	// stw r11,-32112(r7)
	REX_STORE_U32(ctx.r7.u32 + -32112, ctx.r11.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// stw r10,-32108(r8)
	REX_STORE_U32(ctx.r8.u32 + -32108, ctx.r10.u32);
	// addi r3,r11,5480
	ctx.r3.s64 = ctx.r11.s64 + 5480;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C398) {
	REX_FUNC_PROLOGUE();
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18212
	ctx.r11.s64 = ctx.r11.s64 + -18212;
	// lwz r10,-32112(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + -32112);
	// lwz r9,-32108(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// beq cr6,0x82f6c3c4
	if (ctx.cr6.eq) goto loc_82F6C3C4;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_82F6C3C4:
	// stw r11,-32112(r7)
	REX_STORE_U32(ctx.r7.u32 + -32112, ctx.r11.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// stw r10,-32108(r8)
	REX_STORE_U32(ctx.r8.u32 + -32108, ctx.r10.u32);
	// addi r3,r11,5560
	ctx.r3.s64 = ctx.r11.s64 + 5560;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C3E0) {
	REX_FUNC_PROLOGUE();
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18196
	ctx.r11.s64 = ctx.r11.s64 + -18196;
	// lwz r10,-32112(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + -32112);
	// lwz r9,-32108(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// beq cr6,0x82f6c40c
	if (ctx.cr6.eq) goto loc_82F6C40C;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_82F6C40C:
	// stw r11,-32112(r7)
	REX_STORE_U32(ctx.r7.u32 + -32112, ctx.r11.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// stw r10,-32108(r8)
	REX_STORE_U32(ctx.r8.u32 + -32108, ctx.r10.u32);
	// addi r3,r11,5640
	ctx.r3.s64 = ctx.r11.s64 + 5640;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C428) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-18004
	ctx.r5.s64 = ctx.r6.s64 + -18004;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26417(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26417);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-18004(r6)
	REX_STORE_U32(ctx.r6.u32 + -18004, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5720
	ctx.r3.s64 = ctx.r4.s64 + 5720;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C468) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17980
	ctx.r5.s64 = ctx.r6.s64 + -17980;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26416(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26416);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17980(r6)
	REX_STORE_U32(ctx.r6.u32 + -17980, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5808
	ctx.r3.s64 = ctx.r4.s64 + 5808;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C4A8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17768
	ctx.r5.s64 = ctx.r6.s64 + -17768;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26415(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26415);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17768(r6)
	REX_STORE_U32(ctx.r6.u32 + -17768, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5896
	ctx.r3.s64 = ctx.r4.s64 + 5896;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C4E8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17744
	ctx.r5.s64 = ctx.r6.s64 + -17744;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26414(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26414);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17744(r6)
	REX_STORE_U32(ctx.r6.u32 + -17744, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,5984
	ctx.r3.s64 = ctx.r4.s64 + 5984;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C528) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17720
	ctx.r5.s64 = ctx.r6.s64 + -17720;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26413(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26413);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17720(r6)
	REX_STORE_U32(ctx.r6.u32 + -17720, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,6072
	ctx.r3.s64 = ctx.r4.s64 + 6072;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C568) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17696
	ctx.r5.s64 = ctx.r6.s64 + -17696;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26408(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26408);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17696(r6)
	REX_STORE_U32(ctx.r6.u32 + -17696, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,6160
	ctx.r3.s64 = ctx.r4.s64 + 6160;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C5A8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17672
	ctx.r5.s64 = ctx.r6.s64 + -17672;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26407(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26407);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17672(r6)
	REX_STORE_U32(ctx.r6.u32 + -17672, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,6248
	ctx.r3.s64 = ctx.r4.s64 + 6248;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C5E8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17648
	ctx.r5.s64 = ctx.r6.s64 + -17648;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26406(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26406);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17648(r6)
	REX_STORE_U32(ctx.r6.u32 + -17648, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,6336
	ctx.r3.s64 = ctx.r4.s64 + 6336;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C628) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-31997
	ctx.r7.s64 = -2096955392;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-17448
	ctx.r5.s64 = ctx.r6.s64 + -17448;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,-26399(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + -26399);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-17448(r6)
	REX_STORE_U32(ctx.r6.u32 + -17448, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,6424
	ctx.r3.s64 = ctx.r4.s64 + 6424;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C668) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32005
	ctx.r10.s64 = -2097479680;
	// lis r9,-32004
	ctx.r9.s64 = -2097414144;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r7,r9,-12448
	ctx.r7.s64 = ctx.r9.s64 + -12448;
	// lis r6,-31993
	ctx.r6.s64 = -2096693248;
	// lbz r11,-30709(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -30709);
	// addi r5,r8,2760
	ctx.r5.s64 = ctx.r8.s64 + 2760;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r3,r11,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC;
	// stb r11,-30709(r10)
	REX_STORE_U8(ctx.r10.u32 + -30709, ctx.r11.u8);
	// stw r11,8800(r6)
	REX_STORE_U32(ctx.r6.u32 + 8800, ctx.r11.u32);
	// stwx r5,r3,r7
	REX_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r5.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C6A0) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r7,-32006
	ctx.r7.s64 = -2097545216;
	// lis r6,-32002
	ctx.r6.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r5,r6,-16896
	ctx.r5.s64 = ctx.r6.s64 + -16896;
	// lwz r11,-32092(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -32092);
	// addi r10,r10,4032
	ctx.r10.s64 = ctx.r10.s64 + 4032;
	// lbz r9,28298(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + 28298);
	// lis r4,-32009
	ctx.r4.s64 = -2097741824;
	// stw r10,-16896(r6)
	REX_STORE_U32(ctx.r6.u32 + -16896, ctx.r10.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r3,r4,6512
	ctx.r3.s64 = ctx.r4.s64 + 6512;
	// stw r5,-32092(r8)
	REX_STORE_U32(ctx.r8.u32 + -32092, ctx.r5.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stb r9,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r9.u8);
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C6E0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32005
	ctx.r10.s64 = -2097479680;
	// lis r9,-32004
	ctx.r9.s64 = -2097414144;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r7,r9,-12448
	ctx.r7.s64 = ctx.r9.s64 + -12448;
	// lis r6,-31993
	ctx.r6.s64 = -2096693248;
	// lbz r11,-30709(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -30709);
	// addi r5,r8,2672
	ctx.r5.s64 = ctx.r8.s64 + 2672;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r3,r11,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC;
	// stb r11,-30709(r10)
	REX_STORE_U8(ctx.r10.u32 + -30709, ctx.r11.u8);
	// stw r11,8804(r6)
	REX_STORE_U32(ctx.r6.u32 + 8804, ctx.r11.u32);
	// stwx r5,r3,r7
	REX_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r5.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C718) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32005
	ctx.r10.s64 = -2097479680;
	// lis r9,-32004
	ctx.r9.s64 = -2097414144;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r7,r9,-12448
	ctx.r7.s64 = ctx.r9.s64 + -12448;
	// lis r6,-31993
	ctx.r6.s64 = -2096693248;
	// lbz r11,-30709(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -30709);
	// addi r5,r8,2680
	ctx.r5.s64 = ctx.r8.s64 + 2680;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r3,r11,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC;
	// stb r11,-30709(r10)
	REX_STORE_U8(ctx.r10.u32 + -30709, ctx.r11.u8);
	// stw r11,8812(r6)
	REX_STORE_U32(ctx.r6.u32 + 8812, ctx.r11.u32);
	// stwx r5,r3,r7
	REX_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r5.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C750) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32005
	ctx.r10.s64 = -2097479680;
	// lis r9,-32004
	ctx.r9.s64 = -2097414144;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r7,r9,-12448
	ctx.r7.s64 = ctx.r9.s64 + -12448;
	// lis r6,-31993
	ctx.r6.s64 = -2096693248;
	// lbz r11,-30709(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -30709);
	// addi r5,r8,2696
	ctx.r5.s64 = ctx.r8.s64 + 2696;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r3,r11,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC;
	// stb r11,-30709(r10)
	REX_STORE_U8(ctx.r10.u32 + -30709, ctx.r11.u8);
	// stw r11,8808(r6)
	REX_STORE_U32(ctx.r6.u32 + 8808, ctx.r11.u32);
	// stwx r5,r3,r7
	REX_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r5.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C788) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6648
	ctx.r3.s64 = ctx.r11.s64 + 6648;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82f274c4
	ctx.lr = 0x82F6C7A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// addi r31,r11,-27304
	ctx.r31.s64 = ctx.r11.s64 + -27304;
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
	// bl 0x82eaa840
	ctx.lr = 0x82F6C7B4;
	sub_82EAA840(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r10,4
	ctx.r10.s64 = 4;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,-15172(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15172);
	ctx.f13.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f13,504(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 504, temp.u32);
	// lfs f12,-15460(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -15460);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r11.u32);
	// lfs f0,-15464(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -15464);
	ctx.f0.f64 = double(temp.f32);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// stfs f12,512(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 512, temp.u32);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stfs f0,532(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 532, temp.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// stfs f0,536(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 536, temp.u32);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stb r9,244(r31)
	REX_STORE_U8(ctx.r31.u32 + 244, ctx.r9.u8);
	// addi r10,r31,184
	ctx.r10.s64 = ctx.r31.s64 + 184;
	// stw r11,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r11.u32);
	// stw r11,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r11.u32);
	// stw r11,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r11.u32);
	// stw r11,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r11.u32);
loc_82F6C818:
	// sthu r11,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6c818
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6C818;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stfs f0,608(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 608, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,628(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 628, temp.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r11,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r11.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r10,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r10.u32);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stw r10,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r10.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,552(r31)
	REX_STORE_U32(ctx.r31.u32 + 552, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,556(r31)
	REX_STORE_U32(ctx.r31.u32 + 556, ctx.r11.u32);
	// lfs f0,-15456(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -15456);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// stfs f0,612(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 612, temp.u32);
	// stw r11,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r11.u32);
	// stfs f0,616(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 616, temp.u32);
	// stw r11,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r11.u32);
	// stfs f0,620(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 620, temp.u32);
	// stw r11,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r11.u32);
	// stw r11,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r11.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// stw r11,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r11.u32);
	// lis r6,-32009
	ctx.r6.s64 = -2097741824;
	// stw r11,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r11.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r9,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r9.u32);
	// addi r3,r6,6784
	ctx.r3.s64 = ctx.r6.s64 + 6784;
	// stw r11,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r11.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r11,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r11.u32);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r11,600(r31)
	REX_STORE_U32(ctx.r31.u32 + 600, ctx.r11.u32);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// stw r11,604(r31)
	REX_STORE_U32(ctx.r31.u32 + 604, ctx.r11.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stb r11,624(r31)
	REX_STORE_U8(ctx.r31.u32 + 624, ctx.r11.u8);
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// stb r4,625(r31)
	REX_STORE_U8(ctx.r31.u32 + 625, ctx.r4.u8);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// stb r11,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r11.u8);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stb r11,633(r31)
	REX_STORE_U8(ctx.r31.u32 + 633, ctx.r11.u8);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stb r11,634(r31)
	REX_STORE_U8(ctx.r31.u32 + 634, ctx.r11.u8);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bl 0x82f22d28
	ctx.lr = 0x82F6C8F0;
	sub_82F22D28(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82f27514
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C8F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32000
	ctx.r11.s64 = -2097152000;
	// addi r3,r11,2168
	ctx.r3.s64 = ctx.r11.s64 + 2168;
	// bl 0x82ea5f48
	ctx.lr = 0x82F6C910;
	sub_82EA5F48(ctx, base);
	// lis r10,-32009
	ctx.r10.s64 = -2097741824;
	// addi r3,r10,6672
	ctx.r3.s64 = ctx.r10.s64 + 6672;
	// bl 0x82f22d28
	ctx.lr = 0x82F6C91C;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C930) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32001
	ctx.r11.s64 = -2097217536;
	// addi r10,r11,-22488
	ctx.r10.s64 = ctx.r11.s64 + -22488;
	// addis r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 65536;
	// addi r3,r11,24576
	ctx.r3.s64 = ctx.r11.s64 + 24576;
	// bl 0x82f71ecc
	ctx.lr = 0x82F6C950;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r9,-32009
	ctx.r9.s64 = -2097741824;
	// addi r3,r9,6664
	ctx.r3.s64 = ctx.r9.s64 + 6664;
	// bl 0x82f22d28
	ctx.lr = 0x82F6C95C;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6C970) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6688
	ctx.r3.s64 = ctx.r11.s64 + 6688;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C980) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6712
	ctx.r3.s64 = ctx.r11.s64 + 6712;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C990) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6736
	ctx.r3.s64 = ctx.r11.s64 + 6736;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6C9A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82f274c4
	ctx.lr = 0x82F6C9A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// addi r31,r11,-26664
	ctx.r31.s64 = ctx.r11.s64 + -26664;
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
	// bl 0x82eaa840
	ctx.lr = 0x82F6C9BC;
	sub_82EAA840(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r10,4
	ctx.r10.s64 = 4;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,-15172(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15172);
	ctx.f13.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f13,504(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 504, temp.u32);
	// lfs f12,-15460(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -15460);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r11.u32);
	// lfs f0,-15464(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -15464);
	ctx.f0.f64 = double(temp.f32);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// stfs f12,512(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 512, temp.u32);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stfs f0,532(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 532, temp.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// stfs f0,536(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 536, temp.u32);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stb r9,244(r31)
	REX_STORE_U8(ctx.r31.u32 + 244, ctx.r9.u8);
	// addi r10,r31,184
	ctx.r10.s64 = ctx.r31.s64 + 184;
	// stw r11,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r11.u32);
	// stw r11,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r11.u32);
	// stw r11,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r11.u32);
	// stw r11,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r11.u32);
loc_82F6CA20:
	// sthu r11,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x82f6ca20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82F6CA20;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stfs f0,608(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 608, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,628(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 628, temp.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r11,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r11.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r10,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r10.u32);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stw r10,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r10.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,552(r31)
	REX_STORE_U32(ctx.r31.u32 + 552, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,556(r31)
	REX_STORE_U32(ctx.r31.u32 + 556, ctx.r11.u32);
	// lfs f0,-15456(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -15456);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// stfs f0,612(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 612, temp.u32);
	// stw r11,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r11.u32);
	// stfs f0,616(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 616, temp.u32);
	// stw r11,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r11.u32);
	// stfs f0,620(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 620, temp.u32);
	// stw r11,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r11.u32);
	// stw r11,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r11.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// stw r11,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r11.u32);
	// lis r6,-32009
	ctx.r6.s64 = -2097741824;
	// stw r11,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r11.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r9,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r9.u32);
	// addi r3,r6,6760
	ctx.r3.s64 = ctx.r6.s64 + 6760;
	// stw r11,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r11.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r11,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r11.u32);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r11,600(r31)
	REX_STORE_U32(ctx.r31.u32 + 600, ctx.r11.u32);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// stw r11,604(r31)
	REX_STORE_U32(ctx.r31.u32 + 604, ctx.r11.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stb r11,624(r31)
	REX_STORE_U8(ctx.r31.u32 + 624, ctx.r11.u8);
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// stb r4,625(r31)
	REX_STORE_U8(ctx.r31.u32 + 625, ctx.r4.u8);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// stb r11,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r11.u8);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stb r11,633(r31)
	REX_STORE_U8(ctx.r31.u32 + 633, ctx.r11.u8);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stb r11,634(r31)
	REX_STORE_U8(ctx.r31.u32 + 634, ctx.r11.u8);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bl 0x82f22d28
	ctx.lr = 0x82F6CAF8;
	sub_82F22D28(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82f27514
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6CB00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,504
	ctx.r5.s64 = 504;
	// addi r31,r11,-18144
	ctx.r31.s64 = ctx.r11.s64 + -18144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CB28;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CB3C;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CB4C;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CB90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,502
	ctx.r5.s64 = 502;
	// addi r31,r11,-17072
	ctx.r31.s64 = ctx.r11.s64 + -17072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,26
	ctx.r3.s64 = ctx.r31.s64 + 26;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CBB8;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CBCC;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CBDC;
	sub_82F273F0(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CC20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,498
	ctx.r5.s64 = 498;
	// addi r31,r11,-16000
	ctx.r31.s64 = ctx.r11.s64 + -16000;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,30
	ctx.r3.s64 = ctx.r31.s64 + 30;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CC48;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CC5C;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CC6C;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,63
	ctx.r9.s64 = 63;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CCB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,480
	ctx.r5.s64 = 480;
	// addi r31,r11,-14928
	ctx.r31.s64 = ctx.r11.s64 + -14928;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CCD8;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CCEC;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CCFC;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CD40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,484
	ctx.r5.s64 = 484;
	// addi r31,r11,-13856
	ctx.r31.s64 = ctx.r11.s64 + -13856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CD68;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CD7C;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CD8C;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,11
	ctx.r9.s64 = 11;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CDD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,488
	ctx.r5.s64 = 488;
	// addi r31,r11,-12784
	ctx.r31.s64 = ctx.r11.s64 + -12784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CDF8;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CE0C;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CE1C;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,63
	ctx.r9.s64 = 63;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CE60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,498
	ctx.r5.s64 = 498;
	// addi r31,r11,-11712
	ctx.r31.s64 = ctx.r11.s64 + -11712;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,30
	ctx.r3.s64 = ctx.r31.s64 + 30;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CE88;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CE9C;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CEAC;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,30
	ctx.r9.s64 = 30;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CEF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r11,-23736
	ctx.r3.s64 = ctx.r11.s64 + -23736;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82f273f0
	sub_82F273F0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6CF08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// li r5,504
	ctx.r5.s64 = 504;
	// addi r31,r11,17312
	ctx.r31.s64 = ctx.r11.s64 + 17312;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CF30;
	sub_82F273F0(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,-16648
	ctx.r4.s64 = ctx.r11.s64 + -16648;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x82f27ee0
	ctx.lr = 0x82F6CF44;
	sub_82F27EE0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x82f273f0
	ctx.lr = 0x82F6CF54;
	sub_82F273F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,31
	ctx.r9.s64 = 31;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CF98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// addi r11,r11,19728
	ctx.r11.s64 = ctx.r11.s64 + 19728;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// bl 0x82f71ecc
	ctx.lr = 0x82F6CFB4;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6808
	ctx.r3.s64 = ctx.r11.s64 + 6808;
	// bl 0x82f22d28
	ctx.lr = 0x82F6CFC0;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6CFD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23480
	ctx.r3.s64 = ctx.r11.s64 + -23480;
	// bl 0x82f228c8
	ctx.lr = 0x82F6CFE8;
	sub_82F228C8(ctx, base);
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6832
	ctx.r3.s64 = ctx.r11.s64 + 6832;
	// bl 0x82f22d28
	ctx.lr = 0x82F6CFF4;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D008) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6848
	ctx.r3.s64 = ctx.r11.s64 + 6848;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D018) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23224
	ctx.r3.s64 = ctx.r11.s64 + -23224;
	// bl 0x82f229c0
	ctx.lr = 0x82F6D030;
	sub_82F229C0(ctx, base);
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6928
	ctx.r3.s64 = ctx.r11.s64 + 6928;
	// bl 0x82f22d28
	ctx.lr = 0x82F6D03C;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D050) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23144
	ctx.r3.s64 = ctx.r11.s64 + -23144;
	// bl 0x82f229c0
	ctx.lr = 0x82F6D068;
	sub_82F229C0(ctx, base);
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6944
	ctx.r3.s64 = ctx.r11.s64 + 6944;
	// bl 0x82f22d28
	ctx.lr = 0x82F6D074;
	sub_82F22D28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D088) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32009
	ctx.r11.s64 = -2097741824;
	// addi r3,r11,6960
	ctx.r3.s64 = ctx.r11.s64 + 6960;
	// b 0x82f22d28
	sub_82F22D28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D098) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// li r4,114
	ctx.r4.s64 = 114;
	// addi r3,r11,-20412
	ctx.r3.s64 = ctx.r11.s64 + -20412;
	// b 0x82f3a9b0
	sub_82F3A9B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D0A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// lis r10,-31999
	ctx.r10.s64 = -2097086464;
	// addi r4,r11,-20412
	ctx.r4.s64 = ctx.r11.s64 + -20412;
	// addi r3,r10,-20368
	ctx.r3.s64 = ctx.r10.s64 + -20368;
	// b 0x82f3aa10
	sub_82F3AA10(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D0C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11856(r10)
	REX_STORE_U32(ctx.r10.u32 + 11856, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D0D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11864(r10)
	REX_STORE_U32(ctx.r10.u32 + 11864, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D0F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11872(r10)
	REX_STORE_U32(ctx.r10.u32 + 11872, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D108) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11880(r10)
	REX_STORE_U32(ctx.r10.u32 + 11880, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D120) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11888(r10)
	REX_STORE_U32(ctx.r10.u32 + 11888, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D138) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11896(r10)
	REX_STORE_U32(ctx.r10.u32 + 11896, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D150) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11904(r10)
	REX_STORE_U32(ctx.r10.u32 + 11904, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D168) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11912(r10)
	REX_STORE_U32(ctx.r10.u32 + 11912, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D180) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11920(r10)
	REX_STORE_U32(ctx.r10.u32 + 11920, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D198) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11928(r10)
	REX_STORE_U32(ctx.r10.u32 + 11928, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D1B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11936(r10)
	REX_STORE_U32(ctx.r10.u32 + 11936, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D1C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11944(r10)
	REX_STORE_U32(ctx.r10.u32 + 11944, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D1E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11952(r10)
	REX_STORE_U32(ctx.r10.u32 + 11952, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D1F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11960(r10)
	REX_STORE_U32(ctx.r10.u32 + 11960, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D210) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11968(r10)
	REX_STORE_U32(ctx.r10.u32 + 11968, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D228) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11976(r10)
	REX_STORE_U32(ctx.r10.u32 + 11976, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D240) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11984(r10)
	REX_STORE_U32(ctx.r10.u32 + 11984, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D258) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,11992(r10)
	REX_STORE_U32(ctx.r10.u32 + 11992, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D270) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12000(r10)
	REX_STORE_U32(ctx.r10.u32 + 12000, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D288) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12008(r10)
	REX_STORE_U32(ctx.r10.u32 + 12008, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D2A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12016(r10)
	REX_STORE_U32(ctx.r10.u32 + 12016, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D2B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12024(r10)
	REX_STORE_U32(ctx.r10.u32 + 12024, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D2D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12032(r10)
	REX_STORE_U32(ctx.r10.u32 + 12032, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D2E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12040(r10)
	REX_STORE_U32(ctx.r10.u32 + 12040, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D300) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12048(r10)
	REX_STORE_U32(ctx.r10.u32 + 12048, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D318) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12056(r10)
	REX_STORE_U32(ctx.r10.u32 + 12056, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D330) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12064(r10)
	REX_STORE_U32(ctx.r10.u32 + 12064, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D348) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12072(r10)
	REX_STORE_U32(ctx.r10.u32 + 12072, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D360) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12080(r10)
	REX_STORE_U32(ctx.r10.u32 + 12080, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D378) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12088(r10)
	REX_STORE_U32(ctx.r10.u32 + 12088, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D390) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12096(r10)
	REX_STORE_U32(ctx.r10.u32 + 12096, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D3A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12104(r10)
	REX_STORE_U32(ctx.r10.u32 + 12104, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D3C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12112(r10)
	REX_STORE_U32(ctx.r10.u32 + 12112, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D3D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12120(r10)
	REX_STORE_U32(ctx.r10.u32 + 12120, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D3F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12128(r10)
	REX_STORE_U32(ctx.r10.u32 + 12128, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D408) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12136(r10)
	REX_STORE_U32(ctx.r10.u32 + 12136, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D420) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12144(r10)
	REX_STORE_U32(ctx.r10.u32 + 12144, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D438) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12152(r10)
	REX_STORE_U32(ctx.r10.u32 + 12152, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D450) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12160(r10)
	REX_STORE_U32(ctx.r10.u32 + 12160, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D468) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12168(r10)
	REX_STORE_U32(ctx.r10.u32 + 12168, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D480) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12176(r10)
	REX_STORE_U32(ctx.r10.u32 + 12176, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D498) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12184(r10)
	REX_STORE_U32(ctx.r10.u32 + 12184, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D4B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12192(r10)
	REX_STORE_U32(ctx.r10.u32 + 12192, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D4C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12200(r10)
	REX_STORE_U32(ctx.r10.u32 + 12200, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D4E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12208(r10)
	REX_STORE_U32(ctx.r10.u32 + 12208, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D4F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12216(r10)
	REX_STORE_U32(ctx.r10.u32 + 12216, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D510) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12224(r10)
	REX_STORE_U32(ctx.r10.u32 + 12224, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D528) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12232(r10)
	REX_STORE_U32(ctx.r10.u32 + 12232, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D540) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12240(r10)
	REX_STORE_U32(ctx.r10.u32 + 12240, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D558) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12248(r10)
	REX_STORE_U32(ctx.r10.u32 + 12248, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D570) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12256(r10)
	REX_STORE_U32(ctx.r10.u32 + 12256, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D588) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12264(r10)
	REX_STORE_U32(ctx.r10.u32 + 12264, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D5A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12272(r10)
	REX_STORE_U32(ctx.r10.u32 + 12272, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D5B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12280(r10)
	REX_STORE_U32(ctx.r10.u32 + 12280, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D5D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12288(r10)
	REX_STORE_U32(ctx.r10.u32 + 12288, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D5E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12296(r10)
	REX_STORE_U32(ctx.r10.u32 + 12296, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D600) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12304(r10)
	REX_STORE_U32(ctx.r10.u32 + 12304, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D618) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12312(r10)
	REX_STORE_U32(ctx.r10.u32 + 12312, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D630) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12320(r10)
	REX_STORE_U32(ctx.r10.u32 + 12320, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D648) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12328(r10)
	REX_STORE_U32(ctx.r10.u32 + 12328, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D660) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12336(r10)
	REX_STORE_U32(ctx.r10.u32 + 12336, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D678) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,996
	ctx.r11.s64 = ctx.r11.s64 + 996;
	// stw r11,12344(r10)
	REX_STORE_U32(ctx.r10.u32 + 12344, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D690) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,-8320
	ctx.r3.s64 = ctx.r11.s64 + -8320;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D6A0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D6A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,171
	ctx.r30.s64 = 171;
	// addi r11,r11,-7408
	ctx.r11.s64 = ctx.r11.s64 + -7408;
	// addi r31,r11,688
	ctx.r31.s64 = ctx.r11.s64 + 688;
loc_82F6D6CC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d71c
	if (ctx.cr6.eq) goto loc_82F6D71C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6D6DC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6d6dc
	if (!ctx.cr0.eq) goto loc_82F6D6DC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6d71c
	if (!ctx.cr6.eq) goto loc_82F6D71C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d71c
	if (ctx.cr6.eq) goto loc_82F6D71C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6D71C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6D71C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6d6cc
	if (!ctx.cr0.lt) goto loc_82F6D6CC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D740) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,21280
	ctx.r3.s64 = ctx.r11.s64 + 21280;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D750) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D758) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,570
	ctx.r30.s64 = 570;
	// addi r11,r11,-14016
	ctx.r11.s64 = ctx.r11.s64 + -14016;
	// addi r31,r11,2284
	ctx.r31.s64 = ctx.r11.s64 + 2284;
loc_82F6D77C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d7cc
	if (ctx.cr6.eq) goto loc_82F6D7CC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6D78C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6d78c
	if (!ctx.cr0.eq) goto loc_82F6D78C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6d7cc
	if (!ctx.cr6.eq) goto loc_82F6D7CC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d7cc
	if (ctx.cr6.eq) goto loc_82F6D7CC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6D7CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6D7CC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6d77c
	if (!ctx.cr0.lt) goto loc_82F6D77C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D7F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,30040
	ctx.r3.s64 = ctx.r11.s64 + 30040;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D800) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D808) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,10
	ctx.r30.s64 = 10;
	// addi r11,r11,8620
	ctx.r11.s64 = ctx.r11.s64 + 8620;
	// addi r31,r11,44
	ctx.r31.s64 = ctx.r11.s64 + 44;
loc_82F6D82C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d87c
	if (ctx.cr6.eq) goto loc_82F6D87C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6D83C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6d83c
	if (!ctx.cr0.eq) goto loc_82F6D83C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6d87c
	if (!ctx.cr6.eq) goto loc_82F6D87C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d87c
	if (ctx.cr6.eq) goto loc_82F6D87C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6D87C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6D87C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6d82c
	if (!ctx.cr0.lt) goto loc_82F6D82C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D8A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,25488
	ctx.r3.s64 = ctx.r11.s64 + 25488;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D8B0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D8B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,98
	ctx.r30.s64 = 98;
	// addi r11,r11,-14416
	ctx.r11.s64 = ctx.r11.s64 + -14416;
	// addi r31,r11,396
	ctx.r31.s64 = ctx.r11.s64 + 396;
loc_82F6D8DC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d92c
	if (ctx.cr6.eq) goto loc_82F6D92C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6D8EC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6d8ec
	if (!ctx.cr0.eq) goto loc_82F6D8EC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6d92c
	if (!ctx.cr6.eq) goto loc_82F6D92C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d92c
	if (ctx.cr6.eq) goto loc_82F6D92C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6D92C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6D92C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6d8dc
	if (!ctx.cr0.lt) goto loc_82F6D8DC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D950) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,-4000
	ctx.r3.s64 = ctx.r11.s64 + -4000;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6D960) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6D968) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,90
	ctx.r30.s64 = 90;
	// addi r11,r11,29672
	ctx.r11.s64 = ctx.r11.s64 + 29672;
	// addi r31,r11,364
	ctx.r31.s64 = ctx.r11.s64 + 364;
loc_82F6D98C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d9dc
	if (ctx.cr6.eq) goto loc_82F6D9DC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6D99C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6d99c
	if (!ctx.cr0.eq) goto loc_82F6D99C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6d9dc
	if (!ctx.cr6.eq) goto loc_82F6D9DC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6d9dc
	if (ctx.cr6.eq) goto loc_82F6D9DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6D9DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6D9DC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6d98c
	if (!ctx.cr0.lt) goto loc_82F6D98C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DA00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// addi r3,r11,-22880
	ctx.r3.s64 = ctx.r11.s64 + -22880;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DA10) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DA18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,8
	ctx.r30.s64 = 8;
	// addi r11,r11,4404
	ctx.r11.s64 = ctx.r11.s64 + 4404;
	// addi r31,r11,36
	ctx.r31.s64 = ctx.r11.s64 + 36;
loc_82F6DA3C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6da8c
	if (ctx.cr6.eq) goto loc_82F6DA8C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DA4C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6da4c
	if (!ctx.cr0.eq) goto loc_82F6DA4C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6da8c
	if (!ctx.cr6.eq) goto loc_82F6DA8C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6da8c
	if (ctx.cr6.eq) goto loc_82F6DA8C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DA8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DA8C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6da3c
	if (!ctx.cr0.lt) goto loc_82F6DA3C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DAB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// addi r3,r11,-31312
	ctx.r3.s64 = ctx.r11.s64 + -31312;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DAC0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DAC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,-6720
	ctx.r11.s64 = ctx.r11.s64 + -6720;
	// addi r31,r11,40
	ctx.r31.s64 = ctx.r11.s64 + 40;
loc_82F6DAEC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6db3c
	if (ctx.cr6.eq) goto loc_82F6DB3C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DAFC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6dafc
	if (!ctx.cr0.eq) goto loc_82F6DAFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6db3c
	if (!ctx.cr6.eq) goto loc_82F6DB3C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6db3c
	if (ctx.cr6.eq) goto loc_82F6DB3C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DB3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DB3C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6daec
	if (!ctx.cr0.lt) goto loc_82F6DAEC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DB60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,4440
	ctx.r3.s64 = ctx.r11.s64 + 4440;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DB70) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DB78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// lwz r3,-21164(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -21164);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DB8C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6db8c
	if (!ctx.cr0.eq) goto loc_82F6DB8C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F6DBD0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,17096
	ctx.r3.s64 = ctx.r11.s64 + 17096;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DBE0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DBE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,-4104
	ctx.r11.s64 = ctx.r11.s64 + -4104;
	// addi r31,r11,40
	ctx.r31.s64 = ctx.r11.s64 + 40;
loc_82F6DC0C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6dc5c
	if (ctx.cr6.eq) goto loc_82F6DC5C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DC1C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6dc1c
	if (!ctx.cr0.eq) goto loc_82F6DC1C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6dc5c
	if (!ctx.cr6.eq) goto loc_82F6DC5C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6dc5c
	if (ctx.cr6.eq) goto loc_82F6DC5C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DC5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DC5C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6dc0c
	if (!ctx.cr0.lt) goto loc_82F6DC0C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DC80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,12880
	ctx.r3.s64 = ctx.r11.s64 + 12880;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DC90) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DC98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-8340
	ctx.r11.s64 = ctx.r11.s64 + -8340;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
loc_82F6DCBC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6dd0c
	if (ctx.cr6.eq) goto loc_82F6DD0C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DCCC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6dccc
	if (!ctx.cr0.eq) goto loc_82F6DCCC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6dd0c
	if (!ctx.cr6.eq) goto loc_82F6DD0C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6dd0c
	if (ctx.cr6.eq) goto loc_82F6DD0C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DD0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DD0C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6dcbc
	if (!ctx.cr0.lt) goto loc_82F6DCBC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DD30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// addi r3,r11,-11728
	ctx.r3.s64 = ctx.r11.s64 + -11728;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DD40) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DD48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r11,r11,-25376
	ctx.r11.s64 = ctx.r11.s64 + -25376;
	// addi r31,r11,32
	ctx.r31.s64 = ctx.r11.s64 + 32;
loc_82F6DD6C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ddbc
	if (ctx.cr6.eq) goto loc_82F6DDBC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DD7C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6dd7c
	if (!ctx.cr0.eq) goto loc_82F6DD7C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6ddbc
	if (!ctx.cr6.eq) goto loc_82F6DDBC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ddbc
	if (ctx.cr6.eq) goto loc_82F6DDBC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DDBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DDBC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6dd6c
	if (!ctx.cr0.lt) goto loc_82F6DD6C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DDE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// addi r3,r11,-27128
	ctx.r3.s64 = ctx.r11.s64 + -27128;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DDF0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DDF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r11,r11,12844
	ctx.r11.s64 = ctx.r11.s64 + 12844;
	// addi r31,r11,32
	ctx.r31.s64 = ctx.r11.s64 + 32;
loc_82F6DE1C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6de6c
	if (ctx.cr6.eq) goto loc_82F6DE6C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DE2C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6de2c
	if (!ctx.cr0.eq) goto loc_82F6DE2C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6de6c
	if (!ctx.cr6.eq) goto loc_82F6DE6C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6de6c
	if (ctx.cr6.eq) goto loc_82F6DE6C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DE6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DE6C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6de1c
	if (!ctx.cr0.lt) goto loc_82F6DE1C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DE90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,-16832
	ctx.r3.s64 = ctx.r11.s64 + -16832;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DEA0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DEA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// lwz r3,-4140(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -4140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DEBC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6debc
	if (!ctx.cr0.eq) goto loc_82F6DEBC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F6DF00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,-21160
	ctx.r3.s64 = ctx.r11.s64 + -21160;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DF10) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DF18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r11,r11,-7440
	ctx.r11.s64 = ctx.r11.s64 + -7440;
	// addi r31,r11,32
	ctx.r31.s64 = ctx.r11.s64 + 32;
loc_82F6DF3C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6df8c
	if (ctx.cr6.eq) goto loc_82F6DF8C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DF4C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6df4c
	if (!ctx.cr0.eq) goto loc_82F6DF4C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6df8c
	if (!ctx.cr6.eq) goto loc_82F6DF8C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6df8c
	if (ctx.cr6.eq) goto loc_82F6DF8C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6DF8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6DF8C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6df3c
	if (!ctx.cr0.lt) goto loc_82F6DF3C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DFB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,-12520
	ctx.r3.s64 = ctx.r11.s64 + -12520;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6DFC0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6DFC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,8
	ctx.r30.s64 = 8;
	// addi r11,r11,-12652
	ctx.r11.s64 = ctx.r11.s64 + -12652;
	// addi r31,r11,36
	ctx.r31.s64 = ctx.r11.s64 + 36;
loc_82F6DFEC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e03c
	if (ctx.cr6.eq) goto loc_82F6E03C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6DFFC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6dffc
	if (!ctx.cr0.eq) goto loc_82F6DFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e03c
	if (!ctx.cr6.eq) goto loc_82F6E03C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e03c
	if (ctx.cr6.eq) goto loc_82F6E03C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E03C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E03C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6dfec
	if (!ctx.cr0.lt) goto loc_82F6DFEC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E060) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// addi r3,r11,-18696
	ctx.r3.s64 = ctx.r11.s64 + -18696;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6E070) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E078) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,2
	ctx.r30.s64 = 2;
	// addi r11,r11,180
	ctx.r11.s64 = ctx.r11.s64 + 180;
	// addi r31,r11,12
	ctx.r31.s64 = ctx.r11.s64 + 12;
loc_82F6E09C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e0ec
	if (ctx.cr6.eq) goto loc_82F6E0EC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E0AC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e0ac
	if (!ctx.cr0.eq) goto loc_82F6E0AC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e0ec
	if (!ctx.cr6.eq) goto loc_82F6E0EC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e0ec
	if (ctx.cr6.eq) goto loc_82F6E0EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E0EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E0EC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e09c
	if (!ctx.cr0.lt) goto loc_82F6E09C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E110) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,224
	ctx.r3.s64 = ctx.r11.s64 + 224;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6E120) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E128) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,5
	ctx.r30.s64 = 5;
	// addi r11,r11,25460
	ctx.r11.s64 = ctx.r11.s64 + 25460;
	// addi r31,r11,24
	ctx.r31.s64 = ctx.r11.s64 + 24;
loc_82F6E14C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e19c
	if (ctx.cr6.eq) goto loc_82F6E19C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E15C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e15c
	if (!ctx.cr0.eq) goto loc_82F6E15C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e19c
	if (!ctx.cr6.eq) goto loc_82F6E19C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e19c
	if (ctx.cr6.eq) goto loc_82F6E19C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E19C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E19C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e14c
	if (!ctx.cr0.lt) goto loc_82F6E14C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E1C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,8664
	ctx.r3.s64 = ctx.r11.s64 + 8664;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6E1D0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E1D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,-7548
	ctx.r11.s64 = ctx.r11.s64 + -7548;
	// addi r31,r11,40
	ctx.r31.s64 = ctx.r11.s64 + 40;
loc_82F6E1FC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e24c
	if (ctx.cr6.eq) goto loc_82F6E24C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E20C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e20c
	if (!ctx.cr0.eq) goto loc_82F6E20C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e24c
	if (!ctx.cr6.eq) goto loc_82F6E24C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e24c
	if (ctx.cr6.eq) goto loc_82F6E24C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E24C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E24C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e1fc
	if (!ctx.cr0.lt) goto loc_82F6E1FC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E270) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// addi r3,r11,-25344
	ctx.r3.s64 = ctx.r11.s64 + -25344;
	// b 0x823c2418
	sub_823C2418(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6E280) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E288) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31997
	ctx.r11.s64 = -2096955392;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-16980
	ctx.r11.s64 = ctx.r11.s64 + -16980;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
loc_82F6E2AC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e2fc
	if (ctx.cr6.eq) goto loc_82F6E2FC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E2BC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e2bc
	if (!ctx.cr0.eq) goto loc_82F6E2BC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e2fc
	if (!ctx.cr6.eq) goto loc_82F6E2FC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e2fc
	if (ctx.cr6.eq) goto loc_82F6E2FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E2FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E2FC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e2ac
	if (!ctx.cr0.lt) goto loc_82F6E2AC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E320) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,8
	ctx.r30.s64 = 8;
	// addi r11,r11,-4628
	ctx.r11.s64 = ctx.r11.s64 + -4628;
	// addi r31,r11,36
	ctx.r31.s64 = ctx.r11.s64 + 36;
loc_82F6E344:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e394
	if (ctx.cr6.eq) goto loc_82F6E394;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E354:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e354
	if (!ctx.cr0.eq) goto loc_82F6E354;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e394
	if (!ctx.cr6.eq) goto loc_82F6E394;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e394
	if (ctx.cr6.eq) goto loc_82F6E394;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E394;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E394:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e344
	if (!ctx.cr0.lt) goto loc_82F6E344;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E3B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,11
	ctx.r30.s64 = 11;
	// addi r11,r11,-9272
	ctx.r11.s64 = ctx.r11.s64 + -9272;
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
loc_82F6E3DC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e42c
	if (ctx.cr6.eq) goto loc_82F6E42C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E3EC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e3ec
	if (!ctx.cr0.eq) goto loc_82F6E3EC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e42c
	if (!ctx.cr6.eq) goto loc_82F6E42C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e42c
	if (ctx.cr6.eq) goto loc_82F6E42C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E42C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E42C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e3dc
	if (!ctx.cr0.lt) goto loc_82F6E3DC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E450) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r11,r11,-4820
	ctx.r11.s64 = ctx.r11.s64 + -4820;
	// addi r31,r11,32
	ctx.r31.s64 = ctx.r11.s64 + 32;
loc_82F6E474:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e4c4
	if (ctx.cr6.eq) goto loc_82F6E4C4;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E484:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e484
	if (!ctx.cr0.eq) goto loc_82F6E484;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e4c4
	if (!ctx.cr6.eq) goto loc_82F6E4C4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e4c4
	if (ctx.cr6.eq) goto loc_82F6E4C4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E4C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E4C4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e474
	if (!ctx.cr0.lt) goto loc_82F6E474;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E4E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-4852
	ctx.r11.s64 = ctx.r11.s64 + -4852;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
loc_82F6E50C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e55c
	if (ctx.cr6.eq) goto loc_82F6E55C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E51C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e51c
	if (!ctx.cr0.eq) goto loc_82F6E51C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e55c
	if (!ctx.cr6.eq) goto loc_82F6E55C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e55c
	if (ctx.cr6.eq) goto loc_82F6E55C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E55C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E55C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e50c
	if (!ctx.cr0.lt) goto loc_82F6E50C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E580) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,12
	ctx.r30.s64 = 12;
	// addi r11,r11,11176
	ctx.r11.s64 = ctx.r11.s64 + 11176;
	// addi r31,r11,52
	ctx.r31.s64 = ctx.r11.s64 + 52;
loc_82F6E5A4:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e5f4
	if (ctx.cr6.eq) goto loc_82F6E5F4;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E5B4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e5b4
	if (!ctx.cr0.eq) goto loc_82F6E5B4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e5f4
	if (!ctx.cr6.eq) goto loc_82F6E5F4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e5f4
	if (ctx.cr6.eq) goto loc_82F6E5F4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E5F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E5F4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e5a4
	if (!ctx.cr0.lt) goto loc_82F6E5A4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E618) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,12
	ctx.r30.s64 = 12;
	// addi r11,r11,-4788
	ctx.r11.s64 = ctx.r11.s64 + -4788;
	// addi r31,r11,52
	ctx.r31.s64 = ctx.r11.s64 + 52;
loc_82F6E63C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e68c
	if (ctx.cr6.eq) goto loc_82F6E68C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E64C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e64c
	if (!ctx.cr0.eq) goto loc_82F6E64C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e68c
	if (!ctx.cr6.eq) goto loc_82F6E68C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e68c
	if (ctx.cr6.eq) goto loc_82F6E68C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E68C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E68C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e63c
	if (!ctx.cr0.lt) goto loc_82F6E63C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E6B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,2
	ctx.r30.s64 = 2;
	// addi r11,r11,-4832
	ctx.r11.s64 = ctx.r11.s64 + -4832;
	// addi r31,r11,12
	ctx.r31.s64 = ctx.r11.s64 + 12;
loc_82F6E6D4:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e724
	if (ctx.cr6.eq) goto loc_82F6E724;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E6E4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e6e4
	if (!ctx.cr0.eq) goto loc_82F6E6E4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e724
	if (!ctx.cr6.eq) goto loc_82F6E724;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e724
	if (ctx.cr6.eq) goto loc_82F6E724;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E724;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E724:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e6d4
	if (!ctx.cr0.lt) goto loc_82F6E6D4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E748) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,11
	ctx.r30.s64 = 11;
	// addi r11,r11,-4676
	ctx.r11.s64 = ctx.r11.s64 + -4676;
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
loc_82F6E76C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e7bc
	if (ctx.cr6.eq) goto loc_82F6E7BC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E77C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e77c
	if (!ctx.cr0.eq) goto loc_82F6E77C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e7bc
	if (!ctx.cr6.eq) goto loc_82F6E7BC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e7bc
	if (ctx.cr6.eq) goto loc_82F6E7BC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E7BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E7BC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e76c
	if (!ctx.cr0.lt) goto loc_82F6E76C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E7E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,11
	ctx.r30.s64 = 11;
	// addi r11,r11,-9224
	ctx.r11.s64 = ctx.r11.s64 + -9224;
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
loc_82F6E804:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e854
	if (ctx.cr6.eq) goto loc_82F6E854;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E814:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e814
	if (!ctx.cr0.eq) goto loc_82F6E814;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e854
	if (!ctx.cr6.eq) goto loc_82F6E854;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e854
	if (ctx.cr6.eq) goto loc_82F6E854;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E854:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e804
	if (!ctx.cr0.lt) goto loc_82F6E804;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E878) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,13
	ctx.r30.s64 = 13;
	// addi r11,r11,-5040
	ctx.r11.s64 = ctx.r11.s64 + -5040;
	// addi r31,r11,56
	ctx.r31.s64 = ctx.r11.s64 + 56;
loc_82F6E89C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e8ec
	if (ctx.cr6.eq) goto loc_82F6E8EC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E8AC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e8ac
	if (!ctx.cr0.eq) goto loc_82F6E8AC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e8ec
	if (!ctx.cr6.eq) goto loc_82F6E8EC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e8ec
	if (ctx.cr6.eq) goto loc_82F6E8EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E8EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E8EC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e89c
	if (!ctx.cr0.lt) goto loc_82F6E89C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E910) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,14
	ctx.r30.s64 = 14;
	// addi r11,r11,-4736
	ctx.r11.s64 = ctx.r11.s64 + -4736;
	// addi r31,r11,60
	ctx.r31.s64 = ctx.r11.s64 + 60;
loc_82F6E934:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e984
	if (ctx.cr6.eq) goto loc_82F6E984;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E944:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e944
	if (!ctx.cr0.eq) goto loc_82F6E944;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6e984
	if (!ctx.cr6.eq) goto loc_82F6E984;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6e984
	if (ctx.cr6.eq) goto loc_82F6E984;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6E984;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6E984:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e934
	if (!ctx.cr0.lt) goto loc_82F6E934;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6E9A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,2
	ctx.r30.s64 = 2;
	// addi r11,r11,-9284
	ctx.r11.s64 = ctx.r11.s64 + -9284;
	// addi r31,r11,12
	ctx.r31.s64 = ctx.r11.s64 + 12;
loc_82F6E9CC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ea1c
	if (ctx.cr6.eq) goto loc_82F6EA1C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6E9DC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6e9dc
	if (!ctx.cr0.eq) goto loc_82F6E9DC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6ea1c
	if (!ctx.cr6.eq) goto loc_82F6EA1C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ea1c
	if (ctx.cr6.eq) goto loc_82F6EA1C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EA1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EA1C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6e9cc
	if (!ctx.cr0.lt) goto loc_82F6E9CC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EA40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,17
	ctx.r30.s64 = 17;
	// addi r11,r11,-4984
	ctx.r11.s64 = ctx.r11.s64 + -4984;
	// addi r31,r11,72
	ctx.r31.s64 = ctx.r11.s64 + 72;
loc_82F6EA64:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6eab4
	if (ctx.cr6.eq) goto loc_82F6EAB4;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6EA74:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6ea74
	if (!ctx.cr0.eq) goto loc_82F6EA74;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6eab4
	if (!ctx.cr6.eq) goto loc_82F6EAB4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6eab4
	if (ctx.cr6.eq) goto loc_82F6EAB4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EAB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EAB4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6ea64
	if (!ctx.cr0.lt) goto loc_82F6EA64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EAD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r11,r11,-4912
	ctx.r11.s64 = ctx.r11.s64 + -4912;
	// addi r31,r11,32
	ctx.r31.s64 = ctx.r11.s64 + 32;
loc_82F6EAFC:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6eb4c
	if (ctx.cr6.eq) goto loc_82F6EB4C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6EB0C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6eb0c
	if (!ctx.cr0.eq) goto loc_82F6EB0C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6eb4c
	if (!ctx.cr6.eq) goto loc_82F6EB4C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6eb4c
	if (ctx.cr6.eq) goto loc_82F6EB4C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EB4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EB4C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6eafc
	if (!ctx.cr0.lt) goto loc_82F6EAFC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EB70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,201
	ctx.r30.s64 = 201;
	// addi r11,r11,-7320
	ctx.r11.s64 = ctx.r11.s64 + -7320;
	// addi r31,r11,808
	ctx.r31.s64 = ctx.r11.s64 + 808;
loc_82F6EB94:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ebe4
	if (ctx.cr6.eq) goto loc_82F6EBE4;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6EBA4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6eba4
	if (!ctx.cr0.eq) goto loc_82F6EBA4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6ebe4
	if (!ctx.cr6.eq) goto loc_82F6EBE4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ebe4
	if (ctx.cr6.eq) goto loc_82F6EBE4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EBE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EBE4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6eb94
	if (!ctx.cr0.lt) goto loc_82F6EB94;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EC08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,462
	ctx.r30.s64 = 462;
	// addi r11,r11,-9176
	ctx.r11.s64 = ctx.r11.s64 + -9176;
	// addi r31,r11,1852
	ctx.r31.s64 = ctx.r11.s64 + 1852;
loc_82F6EC2C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ec7c
	if (ctx.cr6.eq) goto loc_82F6EC7C;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6EC3C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6ec3c
	if (!ctx.cr0.eq) goto loc_82F6EC3C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6ec7c
	if (!ctx.cr6.eq) goto loc_82F6EC7C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ec7c
	if (ctx.cr6.eq) goto loc_82F6EC7C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EC7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EC7C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6ec2c
	if (!ctx.cr0.lt) goto loc_82F6EC2C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6ECA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,6
	ctx.r30.s64 = 6;
	// addi r11,r11,-4880
	ctx.r11.s64 = ctx.r11.s64 + -4880;
	// addi r31,r11,28
	ctx.r31.s64 = ctx.r11.s64 + 28;
loc_82F6ECC4:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ed14
	if (ctx.cr6.eq) goto loc_82F6ED14;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6ECD4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6ecd4
	if (!ctx.cr0.eq) goto loc_82F6ECD4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6ed14
	if (!ctx.cr6.eq) goto loc_82F6ED14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ed14
	if (ctx.cr6.eq) goto loc_82F6ED14;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6ED14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6ED14:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6ecc4
	if (!ctx.cr0.lt) goto loc_82F6ECC4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6ED38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,3941
	ctx.r30.s64 = 3941;
	// addi r11,r11,-4592
	ctx.r11.s64 = ctx.r11.s64 + -4592;
	// addi r31,r11,15768
	ctx.r31.s64 = ctx.r11.s64 + 15768;
loc_82F6ED5C:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6edac
	if (ctx.cr6.eq) goto loc_82F6EDAC;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6ED6C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6ed6c
	if (!ctx.cr0.eq) goto loc_82F6ED6C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6edac
	if (!ctx.cr6.eq) goto loc_82F6EDAC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6edac
	if (ctx.cr6.eq) goto loc_82F6EDAC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EDAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EDAC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6ed5c
	if (!ctx.cr0.lt) goto loc_82F6ED5C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EDD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,367
	ctx.r30.s64 = 367;
	// addi r11,r11,-6512
	ctx.r11.s64 = ctx.r11.s64 + -6512;
	// addi r31,r11,1472
	ctx.r31.s64 = ctx.r11.s64 + 1472;
loc_82F6EDF4:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ee44
	if (ctx.cr6.eq) goto loc_82F6EE44;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
loc_82F6EE04:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82f6ee04
	if (!ctx.cr0.eq) goto loc_82F6EE04;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82f6ee44
	if (!ctx.cr6.eq) goto loc_82F6EE44;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6ee44
	if (ctx.cr6.eq) goto loc_82F6EE44;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6EE44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6EE44:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6edf4
	if (!ctx.cr0.lt) goto loc_82F6EDF4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EE68) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32205
	ctx.r11.s64 = -2110586880;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,-30684
	ctx.r11.s64 = ctx.r11.s64 + -30684;
	// stw r11,12968(r10)
	REX_STORE_U32(ctx.r10.u32 + 12968, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EE80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32003
	ctx.r11.s64 = -2097348608;
	// addi r3,r11,12992
	ctx.r3.s64 = ctx.r11.s64 + 12992;
	// b 0x8243fd78
	sub_8243FD78(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6EE90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r10,r11,-5808
	ctx.r10.s64 = ctx.r11.s64 + -5808;
	// addis r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 131072;
	// addi r31,r11,-11552
	ctx.r31.s64 = ctx.r11.s64 + -11552;
loc_82F6EEB8:
	// addi r31,r31,-23904
	ctx.r31.s64 = ctx.r31.s64 + -23904;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82db3f68
	ctx.lr = 0x82F6EEC4;
	sub_82DB3F68(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f6eeb8
	if (!ctx.cr0.lt) goto loc_82F6EEB8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EEE8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31996
	ctx.r11.s64 = -2096889856;
	// addi r11,r11,-5984
	ctx.r11.s64 = ctx.r11.s64 + -5984;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// subf r8,r4,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r4.u64;
	// ori r7,r9,49588
	ctx.r7.u64 = ctx.r9.u64 | 49588;
	// srawi r6,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 2;
	// lwz r11,13836(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 13836);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r11,r3,r7
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r3,r11,1632
	ctx.r3.s64 = ctx.r11.s64 + 1632;
	// lwz r11,1632(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1632);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F6EF40) {
	REX_FUNC_PROLOGUE();
	// b 0x82535a00
	sub_82535A00(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6EF48) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,13112(r10)
	REX_STORE_U32(ctx.r10.u32 + 13112, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EF60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,13116(r10)
	REX_STORE_U32(ctx.r10.u32 + 13116, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EF78) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EF80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,13240(r10)
	REX_STORE_U32(ctx.r10.u32 + 13240, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EF98) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,13264(r10)
	REX_STORE_U32(ctx.r10.u32 + 13264, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EFB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,13280(r10)
	REX_STORE_U32(ctx.r10.u32 + 13280, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EFC8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,13284(r10)
	REX_STORE_U32(ctx.r10.u32 + 13284, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EFE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,15368(r10)
	REX_STORE_U32(ctx.r10.u32 + 15368, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6EFF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82f274c8
	ctx.lr = 0x82F6F000;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32003
	ctx.r11.s64 = -2097348608;
	// li r28,36
	ctx.r28.s64 = 36;
	// addi r11,r11,15376
	ctx.r11.s64 = ctx.r11.s64 + 15376;
	// lis r29,-31993
	ctx.r29.s64 = -2096693248;
	// addi r30,r11,1808
	ctx.r30.s64 = ctx.r11.s64 + 1808;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r31,r11,49588
	ctx.r31.u64 = ctx.r11.u64 | 49588;
loc_82F6F020:
	// lwzu r4,-48(r30)
	ea = -48 + ctx.r30.u32;
	ctx.r4.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82f6f05c
	if (ctx.cr6.eq) goto loc_82F6F05C;
	// lwz r11,13836(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 13836);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r9,r4,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r4.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// srawi r7,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// addi r3,r11,3360
	ctx.r3.s64 = ctx.r11.s64 + 3360;
	// lwz r6,3360(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 3360);
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82F6F05C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6F05C:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x82f6f020
	if (!ctx.cr0.lt) goto loc_82F6F020;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82f27518
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F070) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,17200(r10)
	REX_STORE_U32(ctx.r10.u32 + 17200, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r31,r11,-13096
	ctx.r31.s64 = ctx.r11.s64 + -13096;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f6f0b8
	if (ctx.cr6.eq) goto loc_82F6F0B8;
	// bl 0x82b41060
	ctx.lr = 0x82F6F0B0;
	sub_82B41060(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_82F6F0B8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F0D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,-13968
	ctx.r11.s64 = ctx.r11.s64 + -13968;
	// stw r11,17272(r10)
	REX_STORE_U32(ctx.r10.u32 + 17272, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F0E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,17320(r10)
	REX_STORE_U32(ctx.r10.u32 + 17320, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F100) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8920
	ctx.r11.s64 = ctx.r11.s64 + 8920;
	// stw r11,17500(r10)
	REX_STORE_U32(ctx.r10.u32 + 17500, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F118) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8920
	ctx.r11.s64 = ctx.r11.s64 + 8920;
	// stw r11,18044(r10)
	REX_STORE_U32(ctx.r10.u32 + 18044, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F130) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,-11840
	ctx.r3.s64 = ctx.r11.s64 + -11840;
	// b 0x826b5340
	sub_826B5340(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F140) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F148) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32003
	ctx.r10.s64 = -2097348608;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,18592(r10)
	REX_STORE_U32(ctx.r10.u32 + 18592, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F160) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F168) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,-11376
	ctx.r11.s64 = ctx.r11.s64 + -11376;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F6F1A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-11104(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -11104);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82441338
	sub_82441338(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F1BC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F1C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-28420(r10)
	REX_STORE_U32(ctx.r10.u32 + -28420, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F1D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-28416(r10)
	REX_STORE_U32(ctx.r10.u32 + -28416, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F1F0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// addi r3,r10,29280
	ctx.r3.s64 = ctx.r10.s64 + 29280;
	// addi r11,r11,6828
	ctx.r11.s64 = ctx.r11.s64 + 6828;
	// stw r11,29280(r10)
	REX_STORE_U32(ctx.r10.u32 + 29280, ctx.r11.u32);
	// b 0x82962e48
	sub_82962E48(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F208) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F210) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F218) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9792(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9792);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F22C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F230) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9808(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9808);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F244) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F248) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F250) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F258) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F260) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-28232(r10)
	REX_STORE_U32(ctx.r10.u32 + -28232, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F278) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9780(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9780);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F28C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F290) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9828(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9828);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F2A4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F2A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9740(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9740);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F2BC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F2C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9728(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9728);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F2D4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F2D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9724(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9724);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F2EC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F2F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9796);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F304) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F308) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9804(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9804);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F31C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F320) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9832(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9832);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F334) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F338) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9840(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9840);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F34C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F350) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9836(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9836);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F364) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F368) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-712
	ctx.r11.s64 = ctx.r11.s64 + -712;
	// stw r11,-28224(r10)
	REX_STORE_U32(ctx.r10.u32 + -28224, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F380) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9568(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9568);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F394) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F398) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9564(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9564);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F3AC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F3B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9548(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9548);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F3C4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F3C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9220(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9220);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F3DC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F3E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9232(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9232);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F3F4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F3F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9112(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9112);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F40C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F410) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9128(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F424) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F428) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9124(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9124);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F43C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F440) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9224(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9224);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F454) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F458) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-9228(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9228);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F46C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F470) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8840(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8840);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F484) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F488) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8864(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8864);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F49C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F4A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8892(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8892);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F4B4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F4B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8860);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F4CC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F4D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F4E4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F4E8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-32002
	ctx.r9.s64 = -2097283072;
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r8,r9,-28124
	ctx.r8.s64 = ctx.r9.s64 + -28124;
	// addi r11,r11,-712
	ctx.r11.s64 = ctx.r11.s64 + -712;
	// addi r10,r10,8148
	ctx.r10.s64 = ctx.r10.s64 + 8148;
	// stw r10,-28124(r9)
	REX_STORE_U32(ctx.r9.u32 + -28124, ctx.r10.u32);
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F510) {
	REX_FUNC_PROLOGUE();
	// lis r9,-32002
	ctx.r9.s64 = -2097283072;
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r8,r9,-28112
	ctx.r8.s64 = ctx.r9.s64 + -28112;
	// addi r11,r11,-712
	ctx.r11.s64 = ctx.r11.s64 + -712;
	// addi r10,r10,8148
	ctx.r10.s64 = ctx.r10.s64 + 8148;
	// stw r10,-28112(r9)
	REX_STORE_U32(ctx.r9.u32 + -28112, ctx.r10.u32);
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F538) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-28100(r10)
	REX_STORE_U32(ctx.r10.u32 + -28100, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F550) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-28096(r10)
	REX_STORE_U32(ctx.r10.u32 + -28096, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F568) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-3392
	ctx.r11.s64 = ctx.r11.s64 + -3392;
	// stw r11,-28092(r10)
	REX_STORE_U32(ctx.r10.u32 + -28092, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F580) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-3392
	ctx.r11.s64 = ctx.r11.s64 + -3392;
	// stw r11,-28088(r10)
	REX_STORE_U32(ctx.r10.u32 + -28088, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F598) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32205
	ctx.r11.s64 = -2110586880;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-30684
	ctx.r11.s64 = ctx.r11.s64 + -30684;
	// stw r11,-28080(r10)
	REX_STORE_U32(ctx.r10.u32 + -28080, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F5B0) {
	REX_FUNC_PROLOGUE();
	// b 0x827bc038
	sub_827BC038(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F5B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r10,r11,-7936
	ctx.r10.s64 = ctx.r11.s64 + -7936;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x827efe10
	sub_827EFE10(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F5D0) {
	REX_FUNC_PROLOGUE();
	// b 0x827ee578
	sub_827EE578(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F5D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8196(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8196);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F5EC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F5F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-4300(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -4300);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F604) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F608) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F610) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-8200(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -8200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F624) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F628) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r3,-4948(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -4948);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8251b580
	sub_8251B580(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F63C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F640) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-27808(r10)
	REX_STORE_U32(ctx.r10.u32 + -27808, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F658) {
	REX_FUNC_PROLOGUE();
	// b 0x827eb9f8
	sub_827EB9F8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F660) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F668) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// addi r11,r11,-13116
	ctx.r11.s64 = ctx.r11.s64 + -13116;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// subf r8,r4,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r4.u64;
	// ori r7,r9,49588
	ctx.r7.u64 = ctx.r9.u64 | 49588;
	// srawi r6,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 3;
	// lwz r11,13836(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 13836);
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r11,r3,r7
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r3,r11,4980
	ctx.r3.s64 = ctx.r11.s64 + 4980;
	// lwz r11,4980(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4980);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F6F6C0) {
	REX_FUNC_PROLOGUE();
	// b 0x82883de8
	sub_82883DE8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F6C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r31,-2800(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -2800);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82f6f704
	if (ctx.cr6.eq) goto loc_82F6F704;
	// bl 0x82883b10
	ctx.lr = 0x82F6F6EC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6F704;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6F704:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F718) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r31,-2768(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -2768);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82f6f754
	if (ctx.cr6.eq) goto loc_82F6F754;
	// bl 0x82883b10
	ctx.lr = 0x82F6F73C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6F754;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6F754:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F768) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r31,-2752(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -2752);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82f6f7a4
	if (ctx.cr6.eq) goto loc_82F6F7A4;
	// bl 0x82883b10
	ctx.lr = 0x82F6F78C;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6F7A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6F7A4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F7B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// lwz r31,-2784(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -2784);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82f6f7f4
	if (ctx.cr6.eq) goto loc_82F6F7F4;
	// bl 0x82883b10
	ctx.lr = 0x82F6F7DC;
	sub_82883B10(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82F6F7F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F6F7F4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F808) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,-2632
	ctx.r3.s64 = ctx.r11.s64 + -2632;
	// b 0x82c64398
	sub_82C64398(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F818) {
	REX_FUNC_PROLOGUE();
	// b 0x828cc850
	sub_828CC850(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F820) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r31,r11,-2020
	ctx.r31.s64 = ctx.r11.s64 + -2020;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82f6f86c
	if (ctx.cr6.eq) goto loc_82F6F86C;
loc_82F6F848:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x828cdca8
	ctx.lr = 0x82F6F85C;
	sub_828CDCA8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82f6f848
	if (!ctx.cr6.eq) goto loc_82F6F848;
loc_82F6F86C:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82f6f8a4
	if (ctx.cr6.eq) goto loc_82F6F8A4;
loc_82F6F880:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x828cdca8
	ctx.lr = 0x82F6F894;
	sub_828CDCA8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82f6f880
	if (!ctx.cr6.eq) goto loc_82F6F880;
loc_82F6F8A4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F8B8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-26224
	ctx.r11.s64 = ctx.r11.s64 + -26224;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6f8e4
	if (ctx.cr6.eq) goto loc_82F6F8E4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6F8E4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6f8f8
	if (ctx.cr6.eq) goto loc_82F6F8F8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6F8F8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F910) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// addi r3,r11,-13236
	ctx.r3.s64 = ctx.r11.s64 + -13236;
	// b 0x828fecc8
	sub_828FECC8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F6F920) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-26200
	ctx.r11.s64 = ctx.r11.s64 + -26200;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6f948
	if (ctx.cr6.eq) goto loc_82F6F948;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6f948
	if (!ctx.cr6.eq) goto loc_82F6F948;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6F948:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6f95c
	if (ctx.cr6.eq) goto loc_82F6F95C;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6F95C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F970) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-26184
	ctx.r11.s64 = ctx.r11.s64 + -26184;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6f998
	if (ctx.cr6.eq) goto loc_82F6F998;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6f998
	if (!ctx.cr6.eq) goto loc_82F6F998;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6F998:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6f9ac
	if (ctx.cr6.eq) goto loc_82F6F9AC;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6F9AC:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6F9C0) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-26168
	ctx.r11.s64 = ctx.r11.s64 + -26168;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6f9e8
	if (ctx.cr6.eq) goto loc_82F6F9E8;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6f9e8
	if (!ctx.cr6.eq) goto loc_82F6F9E8;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6F9E8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6f9fc
	if (ctx.cr6.eq) goto loc_82F6F9FC;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6F9FC:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FA10) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-26152
	ctx.r11.s64 = ctx.r11.s64 + -26152;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6fa38
	if (ctx.cr6.eq) goto loc_82F6FA38;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6fa38
	if (!ctx.cr6.eq) goto loc_82F6FA38;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6FA38:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fa4c
	if (ctx.cr6.eq) goto loc_82F6FA4C;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6FA4C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FA60) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-26136
	ctx.r11.s64 = ctx.r11.s64 + -26136;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6fa88
	if (ctx.cr6.eq) goto loc_82F6FA88;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6fa88
	if (!ctx.cr6.eq) goto loc_82F6FA88;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6FA88:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fa9c
	if (ctx.cr6.eq) goto loc_82F6FA9C;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6FA9C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FAB0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-25944
	ctx.r11.s64 = ctx.r11.s64 + -25944;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fadc
	if (ctx.cr6.eq) goto loc_82F6FADC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FADC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6faf0
	if (ctx.cr6.eq) goto loc_82F6FAF0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FAF0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FB08) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-25848
	ctx.r11.s64 = ctx.r11.s64 + -25848;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fb34
	if (ctx.cr6.eq) goto loc_82F6FB34;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FB34:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fb48
	if (ctx.cr6.eq) goto loc_82F6FB48;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FB48:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FB60) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-25824
	ctx.r11.s64 = ctx.r11.s64 + -25824;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fb8c
	if (ctx.cr6.eq) goto loc_82F6FB8C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FB8C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fba0
	if (ctx.cr6.eq) goto loc_82F6FBA0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FBA0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FBB8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-25800
	ctx.r11.s64 = ctx.r11.s64 + -25800;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fbe4
	if (ctx.cr6.eq) goto loc_82F6FBE4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FBE4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fbf8
	if (ctx.cr6.eq) goto loc_82F6FBF8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FBF8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FC10) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-25776
	ctx.r11.s64 = ctx.r11.s64 + -25776;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fc3c
	if (ctx.cr6.eq) goto loc_82F6FC3C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FC3C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fc50
	if (ctx.cr6.eq) goto loc_82F6FC50;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FC50:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FC68) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-25752
	ctx.r11.s64 = ctx.r11.s64 + -25752;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6fc90
	if (ctx.cr6.eq) goto loc_82F6FC90;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6fc90
	if (!ctx.cr6.eq) goto loc_82F6FC90;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6FC90:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fca4
	if (ctx.cr6.eq) goto loc_82F6FCA4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6FCA4:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FCB8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-25736
	ctx.r11.s64 = ctx.r11.s64 + -25736;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f6fce0
	if (ctx.cr6.eq) goto loc_82F6FCE0;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f6fce0
	if (!ctx.cr6.eq) goto loc_82F6FCE0;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F6FCE0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fcf4
	if (ctx.cr6.eq) goto loc_82F6FCF4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F6FCF4:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FD08) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-25168
	ctx.r11.s64 = ctx.r11.s64 + -25168;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fd34
	if (ctx.cr6.eq) goto loc_82F6FD34;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FD34:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fd48
	if (ctx.cr6.eq) goto loc_82F6FD48;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FD48:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FD60) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24760
	ctx.r11.s64 = ctx.r11.s64 + -24760;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fd8c
	if (ctx.cr6.eq) goto loc_82F6FD8C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FD8C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fda0
	if (ctx.cr6.eq) goto loc_82F6FDA0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FDA0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FDB8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24736
	ctx.r11.s64 = ctx.r11.s64 + -24736;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fde4
	if (ctx.cr6.eq) goto loc_82F6FDE4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FDE4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fdf8
	if (ctx.cr6.eq) goto loc_82F6FDF8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FDF8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FE10) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24712
	ctx.r11.s64 = ctx.r11.s64 + -24712;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fe3c
	if (ctx.cr6.eq) goto loc_82F6FE3C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FE3C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fe50
	if (ctx.cr6.eq) goto loc_82F6FE50;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FE50:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FE68) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24688
	ctx.r11.s64 = ctx.r11.s64 + -24688;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fe94
	if (ctx.cr6.eq) goto loc_82F6FE94;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FE94:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6fea8
	if (ctx.cr6.eq) goto loc_82F6FEA8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FEA8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FEC0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24664
	ctx.r11.s64 = ctx.r11.s64 + -24664;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6feec
	if (ctx.cr6.eq) goto loc_82F6FEEC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FEEC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6ff00
	if (ctx.cr6.eq) goto loc_82F6FF00;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FF00:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FF18) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24640
	ctx.r11.s64 = ctx.r11.s64 + -24640;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6ff44
	if (ctx.cr6.eq) goto loc_82F6FF44;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FF44:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6ff58
	if (ctx.cr6.eq) goto loc_82F6FF58;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FF58:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FF70) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24616
	ctx.r11.s64 = ctx.r11.s64 + -24616;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6ff9c
	if (ctx.cr6.eq) goto loc_82F6FF9C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FF9C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f6ffb0
	if (ctx.cr6.eq) goto loc_82F6FFB0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F6FFB0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F6FFC8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24592
	ctx.r11.s64 = ctx.r11.s64 + -24592;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f6fff4
	if (ctx.cr6.eq) goto loc_82F6FFF4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F6FFF4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f70008
	if (ctx.cr6.eq) goto loc_82F70008;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F70008:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70020) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24568
	ctx.r11.s64 = ctx.r11.s64 + -24568;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f7004c
	if (ctx.cr6.eq) goto loc_82F7004C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F7004C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f70060
	if (ctx.cr6.eq) goto loc_82F70060;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F70060:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70078) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24544
	ctx.r11.s64 = ctx.r11.s64 + -24544;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f700a4
	if (ctx.cr6.eq) goto loc_82F700A4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F700A4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f700b8
	if (ctx.cr6.eq) goto loc_82F700B8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F700B8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F700D0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24520
	ctx.r11.s64 = ctx.r11.s64 + -24520;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f700fc
	if (ctx.cr6.eq) goto loc_82F700FC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F700FC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f70110
	if (ctx.cr6.eq) goto loc_82F70110;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F70110:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70128) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-24496
	ctx.r11.s64 = ctx.r11.s64 + -24496;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f70154
	if (ctx.cr6.eq) goto loc_82F70154;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F70154:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f70168
	if (ctx.cr6.eq) goto loc_82F70168;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F70168:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70180) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-24368
	ctx.r11.s64 = ctx.r11.s64 + -24368;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f701a8
	if (ctx.cr6.eq) goto loc_82F701A8;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f701a8
	if (!ctx.cr6.eq) goto loc_82F701A8;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F701A8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f701bc
	if (ctx.cr6.eq) goto loc_82F701BC;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F701BC:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F701D0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-23812
	ctx.r11.s64 = ctx.r11.s64 + -23812;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f701fc
	if (ctx.cr6.eq) goto loc_82F701FC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F701FC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f70210
	if (ctx.cr6.eq) goto loc_82F70210;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F70210:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70228) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-23788
	ctx.r11.s64 = ctx.r11.s64 + -23788;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f70254
	if (ctx.cr6.eq) goto loc_82F70254;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F70254:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f70268
	if (ctx.cr6.eq) goto loc_82F70268;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F70268:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70280) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-23588(r10)
	REX_STORE_U32(ctx.r10.u32 + -23588, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70298) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-23584(r10)
	REX_STORE_U32(ctx.r10.u32 + -23584, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F702B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-23580(r10)
	REX_STORE_U32(ctx.r10.u32 + -23580, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F702C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-23576(r10)
	REX_STORE_U32(ctx.r10.u32 + -23576, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F702E0) {
	REX_FUNC_PROLOGUE();
	// b 0x82946308
	sub_82946308(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F702E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82aeb5d8
	ctx.lr = 0x82F702F8;
	sub_82AEB5D8(ctx, base);
	// bl 0x82aeb5d8
	ctx.lr = 0x82F702FC;
	sub_82AEB5D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70310) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,3180
	ctx.r11.s64 = ctx.r11.s64 + 3180;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F70350) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,3080
	ctx.r11.s64 = ctx.r11.s64 + 3080;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F70390) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,3100
	ctx.r11.s64 = ctx.r11.s64 + 3100;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F703D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,3160
	ctx.r11.s64 = ctx.r11.s64 + 3160;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F70410) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,3120
	ctx.r11.s64 = ctx.r11.s64 + 3120;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F70450) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,3140
	ctx.r11.s64 = ctx.r11.s64 + 3140;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r5,r4,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r4.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F70490) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31992
	ctx.r11.s64 = -2096627712;
	// addi r3,r11,-16348
	ctx.r3.s64 = ctx.r11.s64 + -16348;
	// b 0x829d9b10
	sub_829D9B10(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F704A0) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82a172b0
	sub_82A172B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F704A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32004
	ctx.r31.s64 = -2097414144;
	// lwz r3,-30800(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -30800);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82f704d4
	if (ctx.cr6.eq) goto loc_82F704D4;
	// bl 0x82f71f2c
	ctx.lr = 0x82F704CC;
	__imp__KeTlsFree(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,-30800(r31)
	REX_STORE_U32(ctx.r31.u32 + -30800, ctx.r11.u32);
loc_82F704D4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F704E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22704(r10)
	REX_STORE_U32(ctx.r10.u32 + -22704, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70500) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22700(r10)
	REX_STORE_U32(ctx.r10.u32 + -22700, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70518) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22696(r10)
	REX_STORE_U32(ctx.r10.u32 + -22696, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70530) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22692(r10)
	REX_STORE_U32(ctx.r10.u32 + -22692, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70548) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22688(r10)
	REX_STORE_U32(ctx.r10.u32 + -22688, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70560) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22684(r10)
	REX_STORE_U32(ctx.r10.u32 + -22684, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70578) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22680(r10)
	REX_STORE_U32(ctx.r10.u32 + -22680, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70590) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22676(r10)
	REX_STORE_U32(ctx.r10.u32 + -22676, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F705A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22668(r10)
	REX_STORE_U32(ctx.r10.u32 + -22668, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F705C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22664(r10)
	REX_STORE_U32(ctx.r10.u32 + -22664, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F705D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22660(r10)
	REX_STORE_U32(ctx.r10.u32 + -22660, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F705F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22656(r10)
	REX_STORE_U32(ctx.r10.u32 + -22656, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70608) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22652(r10)
	REX_STORE_U32(ctx.r10.u32 + -22652, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70620) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22648(r10)
	REX_STORE_U32(ctx.r10.u32 + -22648, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70638) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22644(r10)
	REX_STORE_U32(ctx.r10.u32 + -22644, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70650) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22640(r10)
	REX_STORE_U32(ctx.r10.u32 + -22640, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70668) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22636(r10)
	REX_STORE_U32(ctx.r10.u32 + -22636, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70680) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22632(r10)
	REX_STORE_U32(ctx.r10.u32 + -22632, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70698) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22628(r10)
	REX_STORE_U32(ctx.r10.u32 + -22628, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F706B0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22624(r10)
	REX_STORE_U32(ctx.r10.u32 + -22624, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F706C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22620(r10)
	REX_STORE_U32(ctx.r10.u32 + -22620, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F706E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22616(r10)
	REX_STORE_U32(ctx.r10.u32 + -22616, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F706F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-22612(r10)
	REX_STORE_U32(ctx.r10.u32 + -22612, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70710) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-21136(r10)
	REX_STORE_U32(ctx.r10.u32 + -21136, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70728) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-21132(r10)
	REX_STORE_U32(ctx.r10.u32 + -21132, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70740) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-21128(r10)
	REX_STORE_U32(ctx.r10.u32 + -21128, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70758) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-21124(r10)
	REX_STORE_U32(ctx.r10.u32 + -21124, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70770) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-21120(r10)
	REX_STORE_U32(ctx.r10.u32 + -21120, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70788) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-4400
	ctx.r11.s64 = ctx.r11.s64 + -4400;
	// stw r11,-20984(r10)
	REX_STORE_U32(ctx.r10.u32 + -20984, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F707A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-13968
	ctx.r11.s64 = ctx.r11.s64 + -13968;
	// stw r11,-20976(r10)
	REX_STORE_U32(ctx.r10.u32 + -20976, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F707B8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,9612
	ctx.r11.s64 = ctx.r11.s64 + 9612;
	// stw r11,-20972(r10)
	REX_STORE_U32(ctx.r10.u32 + -20972, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F707D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r10,r11,19560
	ctx.r10.s64 = ctx.r11.s64 + 19560;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82a58b18
	sub_82A58B18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F707E8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F707F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-21888
	ctx.r11.s64 = ctx.r11.s64 + -21888;
	// stw r11,-20968(r10)
	REX_STORE_U32(ctx.r10.u32 + -20968, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70808) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r11,r11,-3452
	ctx.r11.s64 = ctx.r11.s64 + -3452;
	// stw r11,21044(r10)
	REX_STORE_U32(ctx.r10.u32 + 21044, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70820) {
	REX_FUNC_PROLOGUE();
	// b 0x82a5eb80
	sub_82A5EB80(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70828) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-21888
	ctx.r11.s64 = ctx.r11.s64 + -21888;
	// stw r11,-20820(r10)
	REX_STORE_U32(ctx.r10.u32 + -20820, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70840) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-21888
	ctx.r11.s64 = ctx.r11.s64 + -21888;
	// stw r11,-20792(r10)
	REX_STORE_U32(ctx.r10.u32 + -20792, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70858) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-21888
	ctx.r11.s64 = ctx.r11.s64 + -21888;
	// stw r11,-20764(r10)
	REX_STORE_U32(ctx.r10.u32 + -20764, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70870) {
	REX_FUNC_PROLOGUE();
	// b 0x82ae6de0
	sub_82AE6DE0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70878) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32205
	ctx.r11.s64 = -2110586880;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-30684
	ctx.r11.s64 = ctx.r11.s64 + -30684;
	// stw r11,-20152(r10)
	REX_STORE_U32(ctx.r10.u32 + -20152, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70890) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70898) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F708A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r11,r11,17088
	ctx.r11.s64 = ctx.r11.s64 + 17088;
	// addi r31,r11,32
	ctx.r31.s64 = ctx.r11.s64 + 32;
loc_82F708C4:
	// lwzu r3,-16(r31)
	ea = -16 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f708d4
	if (ctx.cr6.eq) goto loc_82F708D4;
	// bl 0x82b41060
	ctx.lr = 0x82F708D4;
	sub_82B41060(ctx, base);
loc_82F708D4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f708c4
	if (!ctx.cr0.lt) goto loc_82F708C4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F708F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// li r30,19
	ctx.r30.s64 = 19;
	// addi r11,r11,17744
	ctx.r11.s64 = ctx.r11.s64 + 17744;
	// addi r31,r11,320
	ctx.r31.s64 = ctx.r11.s64 + 320;
loc_82F7091C:
	// lwzu r3,-16(r31)
	ea = -16 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f7092c
	if (ctx.cr6.eq) goto loc_82F7092C;
	// bl 0x82b41060
	ctx.lr = 0x82F7092C;
	sub_82B41060(ctx, base);
loc_82F7092C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f7091c
	if (!ctx.cr0.lt) goto loc_82F7091C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70950) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,18752
	ctx.r11.s64 = ctx.r11.s64 + 18752;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// subf r8,r4,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r4.u64;
	// ori r7,r9,49588
	ctx.r7.u64 = ctx.r9.u64 | 49588;
	// srawi r6,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 3;
	// lwz r11,13836(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 13836);
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r11,r3,r7
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r3,r11,1416
	ctx.r3.s64 = ctx.r11.s64 + 1416;
	// lwz r11,1416(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1416);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F709A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r11,r11,18720
	ctx.r11.s64 = ctx.r11.s64 + 18720;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// subf r8,r4,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r4.u64;
	// ori r7,r9,49588
	ctx.r7.u64 = ctx.r9.u64 | 49588;
	// srawi r6,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 2;
	// lwz r11,13836(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 13836);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r11,r3,r7
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r3,r11,1416
	ctx.r3.s64 = ctx.r11.s64 + 1416;
	// lwz r11,1416(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1416);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82F70A00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31991
	ctx.r11.s64 = -2096562176;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-13064
	ctx.r11.s64 = ctx.r11.s64 + -13064;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
loc_82F70A24:
	// lwzu r3,-4(r31)
	ea = -4 + ctx.r31.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f70a34
	if (ctx.cr6.eq) goto loc_82F70A34;
	// bl 0x8251b580
	ctx.lr = 0x82F70A34;
	sub_8251B580(ctx, base);
loc_82F70A34:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82f70a24
	if (!ctx.cr0.lt) goto loc_82F70A24;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70A58) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,19252
	ctx.r3.s64 = ctx.r11.s64 + 19252;
	// b 0x82c64398
	sub_82C64398(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70A68) {
	REX_FUNC_PROLOGUE();
	// b 0x82c62bf0
	sub_82C62BF0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70A70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r31,r11,19240
	ctx.r31.s64 = ctx.r11.s64 + 19240;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82f70abc
	if (ctx.cr6.eq) goto loc_82F70ABC;
loc_82F70A98:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x828cdca8
	ctx.lr = 0x82F70AAC;
	sub_828CDCA8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82f70a98
	if (!ctx.cr6.eq) goto loc_82F70A98;
loc_82F70ABC:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82f70af4
	if (ctx.cr6.eq) goto loc_82F70AF4;
loc_82F70AD0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x828cdca8
	ctx.lr = 0x82F70AE4;
	sub_828CDCA8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82f70ad0
	if (!ctx.cr6.eq) goto loc_82F70AD0;
loc_82F70AF4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70B08) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r3,r11,-18924
	ctx.r3.s64 = ctx.r11.s64 + -18924;
	// b 0x8243fd78
	sub_8243FD78(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B18) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32207
	ctx.r11.s64 = -2110717952;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,8148
	ctx.r11.s64 = ctx.r11.s64 + 8148;
	// stw r11,-18908(r10)
	REX_STORE_U32(ctx.r10.u32 + -18908, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F70B30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-29320
	ctx.r3.s64 = ctx.r11.s64 + -29320;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,27336
	ctx.r3.s64 = ctx.r11.s64 + 27336;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-32352
	ctx.r3.s64 = ctx.r11.s64 + -32352;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,28200
	ctx.r3.s64 = ctx.r11.s64 + 28200;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B70) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,21288
	ctx.r3.s64 = ctx.r11.s64 + 21288;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,22368
	ctx.r3.s64 = ctx.r11.s64 + 22368;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70B90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,31872
	ctx.r3.s64 = ctx.r11.s64 + 31872;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70BA0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,20640
	ctx.r3.s64 = ctx.r11.s64 + 20640;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70BB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,26040
	ctx.r3.s64 = ctx.r11.s64 + 26040;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70BC0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,25392
	ctx.r3.s64 = ctx.r11.s64 + 25392;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70BD0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-28888
	ctx.r3.s64 = ctx.r11.s64 + -28888;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70BE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,30144
	ctx.r3.s64 = ctx.r11.s64 + 30144;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70BF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,25176
	ctx.r3.s64 = ctx.r11.s64 + 25176;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-31704
	ctx.r3.s64 = ctx.r11.s64 + -31704;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-29536
	ctx.r3.s64 = ctx.r11.s64 + -29536;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-29104
	ctx.r3.s64 = ctx.r11.s64 + -29104;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,31224
	ctx.r3.s64 = ctx.r11.s64 + 31224;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,22152
	ctx.r3.s64 = ctx.r11.s64 + 22152;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,32536
	ctx.r3.s64 = ctx.r11.s64 + 32536;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-31488
	ctx.r3.s64 = ctx.r11.s64 + -31488;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C70) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,21936
	ctx.r3.s64 = ctx.r11.s64 + 21936;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,29496
	ctx.r3.s64 = ctx.r11.s64 + 29496;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70C90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-31272
	ctx.r3.s64 = ctx.r11.s64 + -31272;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70CA0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,22584
	ctx.r3.s64 = ctx.r11.s64 + 22584;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70CB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,30576
	ctx.r3.s64 = ctx.r11.s64 + 30576;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70CC0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,22800
	ctx.r3.s64 = ctx.r11.s64 + 22800;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70CD0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-29968
	ctx.r3.s64 = ctx.r11.s64 + -29968;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70CE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-30624
	ctx.r3.s64 = ctx.r11.s64 + -30624;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70CF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,21504
	ctx.r3.s64 = ctx.r11.s64 + 21504;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,28632
	ctx.r3.s64 = ctx.r11.s64 + 28632;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,32088
	ctx.r3.s64 = ctx.r11.s64 + 32088;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,32752
	ctx.r3.s64 = ctx.r11.s64 + 32752;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-28024
	ctx.r3.s64 = ctx.r11.s64 + -28024;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,24960
	ctx.r3.s64 = ctx.r11.s64 + 24960;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-32136
	ctx.r3.s64 = ctx.r11.s64 + -32136;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,23016
	ctx.r3.s64 = ctx.r11.s64 + 23016;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D70) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,27552
	ctx.r3.s64 = ctx.r11.s64 + 27552;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,31440
	ctx.r3.s64 = ctx.r11.s64 + 31440;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70D90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,30792
	ctx.r3.s64 = ctx.r11.s64 + 30792;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70DA0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,23232
	ctx.r3.s64 = ctx.r11.s64 + 23232;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70DB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,25608
	ctx.r3.s64 = ctx.r11.s64 + 25608;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70DC0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,19984
	ctx.r3.s64 = ctx.r11.s64 + 19984;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70DD0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,23664
	ctx.r3.s64 = ctx.r11.s64 + 23664;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70DE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,28848
	ctx.r3.s64 = ctx.r11.s64 + 28848;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70DF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,24528
	ctx.r3.s64 = ctx.r11.s64 + 24528;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,29064
	ctx.r3.s64 = ctx.r11.s64 + 29064;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-30840
	ctx.r3.s64 = ctx.r11.s64 + -30840;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,27120
	ctx.r3.s64 = ctx.r11.s64 + 27120;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,31656
	ctx.r3.s64 = ctx.r11.s64 + 31656;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,29712
	ctx.r3.s64 = ctx.r11.s64 + 29712;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,25824
	ctx.r3.s64 = ctx.r11.s64 + 25824;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-28456
	ctx.r3.s64 = ctx.r11.s64 + -28456;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E70) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,26472
	ctx.r3.s64 = ctx.r11.s64 + 26472;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,26688
	ctx.r3.s64 = ctx.r11.s64 + 26688;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70E90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,21720
	ctx.r3.s64 = ctx.r11.s64 + 21720;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70EA0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,29280
	ctx.r3.s64 = ctx.r11.s64 + 29280;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70EB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,30360
	ctx.r3.s64 = ctx.r11.s64 + 30360;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70EC0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,28416
	ctx.r3.s64 = ctx.r11.s64 + 28416;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70ED0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-27104
	ctx.r3.s64 = ctx.r11.s64 + -27104;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70EE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-32568
	ctx.r3.s64 = ctx.r11.s64 + -32568;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70EF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,23880
	ctx.r3.s64 = ctx.r11.s64 + 23880;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F00) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-31056
	ctx.r3.s64 = ctx.r11.s64 + -31056;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,21072
	ctx.r3.s64 = ctx.r11.s64 + 21072;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,27768
	ctx.r3.s64 = ctx.r11.s64 + 27768;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-27808
	ctx.r3.s64 = ctx.r11.s64 + -27808;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F40) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-28672
	ctx.r3.s64 = ctx.r11.s64 + -28672;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-30192
	ctx.r3.s64 = ctx.r11.s64 + -30192;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-31920
	ctx.r3.s64 = ctx.r11.s64 + -31920;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F70) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,31008
	ctx.r3.s64 = ctx.r11.s64 + 31008;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-28240
	ctx.r3.s64 = ctx.r11.s64 + -28240;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70F90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-30408
	ctx.r3.s64 = ctx.r11.s64 + -30408;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70FA0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-27376
	ctx.r3.s64 = ctx.r11.s64 + -27376;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70FB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,26904
	ctx.r3.s64 = ctx.r11.s64 + 26904;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70FC0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,24744
	ctx.r3.s64 = ctx.r11.s64 + 24744;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70FD0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,24096
	ctx.r3.s64 = ctx.r11.s64 + 24096;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70FE0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-29752
	ctx.r3.s64 = ctx.r11.s64 + -29752;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F70FF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,27984
	ctx.r3.s64 = ctx.r11.s64 + 27984;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71000) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,29928
	ctx.r3.s64 = ctx.r11.s64 + 29928;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71010) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,-27592
	ctx.r3.s64 = ctx.r11.s64 + -27592;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71020) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,26256
	ctx.r3.s64 = ctx.r11.s64 + 26256;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71030) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,32320
	ctx.r3.s64 = ctx.r11.s64 + 32320;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71040) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,23448
	ctx.r3.s64 = ctx.r11.s64 + 23448;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71050) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,20416
	ctx.r3.s64 = ctx.r11.s64 + 20416;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71060) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,20856
	ctx.r3.s64 = ctx.r11.s64 + 20856;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71070) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,24312
	ctx.r3.s64 = ctx.r11.s64 + 24312;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71080) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31994
	ctx.r11.s64 = -2096758784;
	// addi r3,r11,20200
	ctx.r3.s64 = ctx.r11.s64 + 20200;
	// b 0x82c74e60
	sub_82C74E60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71090) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r10,r11,-24776
	ctx.r10.s64 = ctx.r11.s64 + -24776;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x82ce8428
	sub_82CE8428(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F710A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r10,r11,-24384
	ctx.r10.s64 = ctx.r11.s64 + -24384;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x82ce8608
	sub_82CE8608(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F710C0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F710C8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F710D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// lwz r3,-22064(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -22064);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82b41060
	sub_82B41060(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F710E4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F710E8) {
	REX_FUNC_PROLOGUE();
	// b 0x82d85a90
	sub_82D85A90(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F710F0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// addi r3,r11,6488
	ctx.r3.s64 = ctx.r11.s64 + 6488;
	// b 0x82dba378
	sub_82DBA378(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71100) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32005
	ctx.r10.s64 = -2097479680;
	// addi r9,r10,-25728
	ctx.r9.s64 = ctx.r10.s64 + -25728;
	// lwz r4,-18724(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -18724);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lhz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r10.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r10,-31998
	ctx.r10.s64 = -2097020928;
	// lhz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 4);
	// addi r5,r11,9
	ctx.r5.s64 = ctx.r11.s64 + 9;
	// lwz r3,13652(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 13652);
	// b 0x82e5bc48
	sub_82E5BC48(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71148) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71150) {
	REX_FUNC_PROLOGUE();
	// lis r9,-32002
	ctx.r9.s64 = -2097283072;
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// addi r8,r9,-18720
	ctx.r8.s64 = ctx.r9.s64 + -18720;
	// addi r10,r11,-712
	ctx.r10.s64 = ctx.r11.s64 + -712;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r10,-18720(r9)
	REX_STORE_U32(ctx.r9.u32 + -18720, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71170) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82f274c4
	ctx.lr = 0x82F71178;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31993
	ctx.r11.s64 = -2096693248;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,7328
	ctx.r11.s64 = ctx.r11.s64 + 7328;
	// li r27,139
	ctx.r27.s64 = 139;
	// addi r30,r11,560
	ctx.r30.s64 = ctx.r11.s64 + 560;
	// lis r11,-32005
	ctx.r11.s64 = -2097479680;
	// ori r28,r10,65535
	ctx.r28.u64 = ctx.r10.u64 | 65535;
	// lis r31,-31998
	ctx.r31.s64 = -2097020928;
	// addi r29,r11,-25728
	ctx.r29.s64 = ctx.r11.s64 + -25728;
loc_82F711A0:
	// lwzu r4,-4(r30)
	ea = -4 + ctx.r30.u32;
	ctx.r4.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// cmplw cr6,r4,r29
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82f711d4
	if (ctx.cr6.eq) goto loc_82F711D4;
	// lhz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r9,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r9.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82f711d4
	if (!ctx.cr6.eq) goto loc_82F711D4;
	// lhz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 4);
	// lwz r3,13652(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 13652);
	// addi r5,r11,9
	ctx.r5.s64 = ctx.r11.s64 + 9;
	// bl 0x82e5bc48
	ctx.lr = 0x82F711D4;
	sub_82E5BC48(ctx, base);
loc_82F711D4:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bge 0x82f711a0
	if (!ctx.cr0.lt) goto loc_82F711A0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82f27514
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F711E8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F711F0) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F711F8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71200) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32005
	ctx.r10.s64 = -2097479680;
	// addi r9,r10,-25728
	ctx.r9.s64 = ctx.r10.s64 + -25728;
	// lwz r4,-18684(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -18684);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lhz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r10.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r10,-31998
	ctx.r10.s64 = -2097020928;
	// lhz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 4);
	// addi r5,r11,9
	ctx.r5.s64 = ctx.r11.s64 + 9;
	// lwz r3,13652(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 13652);
	// b 0x82e5bc48
	sub_82E5BC48(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71248) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71250) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r31,r11,-18612
	ctx.r31.s64 = ctx.r11.s64 + -18612;
	// lwz r11,-18612(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -18612);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82f712b8
	if (ctx.cr6.eq) goto loc_82F712B8;
	// lis r9,-31998
	ctx.r9.s64 = -2097020928;
	// lwz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r4,r11,-4
	ctx.r4.s64 = ctx.r11.s64 + -4;
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// lwz r3,13652(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 13652);
	// bl 0x82e5bc48
	ctx.lr = 0x82F7128C;
	sub_82E5BC48(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82F712B8:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F712E0) {
	REX_FUNC_PROLOGUE();
	// b 0x82e3c420
	sub_82E3C420(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F712E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// lis r10,-32002
	ctx.r10.s64 = -2097283072;
	// addi r11,r11,-13968
	ctx.r11.s64 = ctx.r11.s64 + -13968;
	// stw r11,-18584(r10)
	REX_STORE_U32(ctx.r10.u32 + -18584, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71300) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71308) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18388
	ctx.r11.s64 = ctx.r11.s64 + -18388;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f71334
	if (ctx.cr6.eq) goto loc_82F71334;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F71334:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71348
	if (ctx.cr6.eq) goto loc_82F71348;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71348:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71360) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18364
	ctx.r11.s64 = ctx.r11.s64 + -18364;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f7138c
	if (ctx.cr6.eq) goto loc_82F7138C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F7138C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f713a0
	if (ctx.cr6.eq) goto loc_82F713A0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F713A0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F713B8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18340
	ctx.r11.s64 = ctx.r11.s64 + -18340;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f713e4
	if (ctx.cr6.eq) goto loc_82F713E4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F713E4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f713f8
	if (ctx.cr6.eq) goto loc_82F713F8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F713F8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71410) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18316
	ctx.r11.s64 = ctx.r11.s64 + -18316;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f7143c
	if (ctx.cr6.eq) goto loc_82F7143C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F7143C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71450
	if (ctx.cr6.eq) goto loc_82F71450;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71450:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71468) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18292
	ctx.r11.s64 = ctx.r11.s64 + -18292;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f71494
	if (ctx.cr6.eq) goto loc_82F71494;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F71494:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f714a8
	if (ctx.cr6.eq) goto loc_82F714A8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F714A8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F714C0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18268
	ctx.r11.s64 = ctx.r11.s64 + -18268;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f714ec
	if (ctx.cr6.eq) goto loc_82F714EC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F714EC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71500
	if (ctx.cr6.eq) goto loc_82F71500;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71500:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71518) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18244
	ctx.r11.s64 = ctx.r11.s64 + -18244;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f71540
	if (ctx.cr6.eq) goto loc_82F71540;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f71540
	if (!ctx.cr6.eq) goto loc_82F71540;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F71540:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71554
	if (ctx.cr6.eq) goto loc_82F71554;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F71554:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71568) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18228
	ctx.r11.s64 = ctx.r11.s64 + -18228;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f71590
	if (ctx.cr6.eq) goto loc_82F71590;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f71590
	if (!ctx.cr6.eq) goto loc_82F71590;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F71590:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f715a4
	if (ctx.cr6.eq) goto loc_82F715A4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F715A4:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F715B8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18212
	ctx.r11.s64 = ctx.r11.s64 + -18212;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f715e0
	if (ctx.cr6.eq) goto loc_82F715E0;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f715e0
	if (!ctx.cr6.eq) goto loc_82F715E0;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F715E0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f715f4
	if (ctx.cr6.eq) goto loc_82F715F4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F715F4:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71608) {
	REX_FUNC_PROLOGUE();
	// lis r8,-31997
	ctx.r8.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// addi r11,r11,-18196
	ctx.r11.s64 = ctx.r11.s64 + -18196;
	// lwz r9,-32112(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -32112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82f71630
	if (ctx.cr6.eq) goto loc_82F71630;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82f71630
	if (!ctx.cr6.eq) goto loc_82F71630;
	// stw r10,-32112(r8)
	REX_STORE_U32(ctx.r8.u32 + -32112, ctx.r10.u32);
loc_82F71630:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71644
	if (ctx.cr6.eq) goto loc_82F71644;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82F71644:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71658) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-18004
	ctx.r11.s64 = ctx.r11.s64 + -18004;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f71684
	if (ctx.cr6.eq) goto loc_82F71684;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F71684:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71698
	if (ctx.cr6.eq) goto loc_82F71698;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71698:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F716B0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17980
	ctx.r11.s64 = ctx.r11.s64 + -17980;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f716dc
	if (ctx.cr6.eq) goto loc_82F716DC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F716DC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f716f0
	if (ctx.cr6.eq) goto loc_82F716F0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F716F0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71708) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17768
	ctx.r11.s64 = ctx.r11.s64 + -17768;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f71734
	if (ctx.cr6.eq) goto loc_82F71734;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F71734:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71748
	if (ctx.cr6.eq) goto loc_82F71748;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71748:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71760) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17744
	ctx.r11.s64 = ctx.r11.s64 + -17744;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f7178c
	if (ctx.cr6.eq) goto loc_82F7178C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F7178C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f717a0
	if (ctx.cr6.eq) goto loc_82F717A0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F717A0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F717B8) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17720
	ctx.r11.s64 = ctx.r11.s64 + -17720;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f717e4
	if (ctx.cr6.eq) goto loc_82F717E4;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F717E4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f717f8
	if (ctx.cr6.eq) goto loc_82F717F8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F717F8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71810) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17696
	ctx.r11.s64 = ctx.r11.s64 + -17696;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f7183c
	if (ctx.cr6.eq) goto loc_82F7183C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F7183C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71850
	if (ctx.cr6.eq) goto loc_82F71850;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71850:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71868) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17672
	ctx.r11.s64 = ctx.r11.s64 + -17672;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f71894
	if (ctx.cr6.eq) goto loc_82F71894;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F71894:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f718a8
	if (ctx.cr6.eq) goto loc_82F718A8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F718A8:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F718C0) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17648
	ctx.r11.s64 = ctx.r11.s64 + -17648;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f718ec
	if (ctx.cr6.eq) goto loc_82F718EC;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F718EC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71900
	if (ctx.cr6.eq) goto loc_82F71900;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71900:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71918) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-17448
	ctx.r11.s64 = ctx.r11.s64 + -17448;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f71944
	if (ctx.cr6.eq) goto loc_82F71944;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F71944:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f71958
	if (ctx.cr6.eq) goto loc_82F71958;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F71958:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71970) {
	REX_FUNC_PROLOGUE();
	// lis r9,-31997
	ctx.r9.s64 = -2096955392;
	// lis r11,-32002
	ctx.r11.s64 = -2097283072;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-16896
	ctx.r11.s64 = ctx.r11.s64 + -16896;
	// addi r7,r10,4212
	ctx.r7.s64 = ctx.r10.s64 + 4212;
	// lwz r8,-32092(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -32092);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82f7199c
	if (ctx.cr6.eq) goto loc_82F7199C;
	// stw r10,-32092(r9)
	REX_STORE_U32(ctx.r9.u32 + -32092, ctx.r10.u32);
loc_82F7199C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82f719b0
	if (ctx.cr6.eq) goto loc_82F719B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82F719B0:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F719C8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32205
	ctx.r11.s64 = -2110586880;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r11,r11,-29972
	ctx.r11.s64 = ctx.r11.s64 + -29972;
	// stw r11,29788(r10)
	REX_STORE_U32(ctx.r10.u32 + 29788, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F719E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32205
	ctx.r11.s64 = -2110586880;
	// lis r10,-31993
	ctx.r10.s64 = -2096693248;
	// addi r11,r11,-29972
	ctx.r11.s64 = ctx.r11.s64 + -29972;
	// stw r11,29796(r10)
	REX_STORE_U32(ctx.r10.u32 + 29796, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F719F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32001
	ctx.r11.s64 = -2097217536;
	// addi r3,r11,-22494
	ctx.r3.s64 = ctx.r11.s64 + -22494;
	// b 0x82e9e4a0
	sub_82E9E4A0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A08) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71A10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32000
	ctx.r11.s64 = -2097152000;
	// addi r3,r11,2168
	ctx.r3.s64 = ctx.r11.s64 + 2168;
	// b 0x82e9ee98
	sub_82E9EE98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32000
	ctx.r11.s64 = -2097152000;
	// lwz r3,2152(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82966848
	sub_82966848(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A34) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71A38) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32000
	ctx.r11.s64 = -2097152000;
	// lwz r3,2136(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82966848
	sub_82966848(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A4C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71A50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32000
	ctx.r11.s64 = -2097152000;
	// lwz r3,2120(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2120);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82966848
	sub_82966848(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A64) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71A68) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// addi r11,r11,-26664
	ctx.r11.s64 = ctx.r11.s64 + -26664;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// lwz r4,32(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x82ea6d88
	sub_82EA6D88(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32007
	ctx.r11.s64 = -2097610752;
	// addi r11,r11,-27304
	ctx.r11.s64 = ctx.r11.s64 + -27304;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// lwz r4,32(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x82ea6d88
	sub_82EA6D88(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71A98) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32007
	ctx.r10.s64 = -2097610752;
	// addi r11,r11,5300
	ctx.r11.s64 = ctx.r11.s64 + 5300;
	// stw r11,19728(r10)
	REX_STORE_U32(ctx.r10.u32 + 19728, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71AB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23480
	ctx.r3.s64 = ctx.r11.s64 + -23480;
	// b 0x82f227b0
	sub_82F227B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71AC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// lwz r3,-23348(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -23348);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82f71afc
	if (ctx.cr6.eq) goto loc_82F71AFC;
	// bl 0x828bee10
	ctx.lr = 0x82F71AE0;
	sub_828BEE10(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82f71afc
	if (ctx.cr0.eq) goto loc_82F71AFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82F71AFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82F71AFC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82F71B10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23224
	ctx.r3.s64 = ctx.r11.s64 + -23224;
	// b 0x82f22a30
	sub_82F22A30(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71B20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23144
	ctx.r3.s64 = ctx.r11.s64 + -23144;
	// b 0x82f22a30
	sub_82F22A30(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82F71B30) {
	REX_FUNC_PROLOGUE();
	// lis r11,-31999
	ctx.r11.s64 = -2097086464;
	// addi r3,r11,-23143
	ctx.r3.s64 = ctx.r11.s64 + -23143;
	// b 0x82f22b28
	sub_82F22B28(ctx, base);
	return;
}

