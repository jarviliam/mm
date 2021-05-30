/*
 * File: z_oceff_wipe.c
 * Overlay: ovl_Oceff_Wipe
 * Description: Zelda's Lullaby and Song of Time Ocarina Effect
 */

#include "z_oceff_wipe.h"

#define FLAGS 0x02000010

#define THIS ((OceffWipe*)thisx)

void OceffWipe_Init(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe_Destroy(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe_Update(Actor* thisx, GlobalContext* globalCtx);
void OceffWipe_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Oceff_Wipe_InitVars = {
    ACTOR_OCEFF_WIPE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(OceffWipe),
    (ActorFunc)OceffWipe_Init,
    (ActorFunc)OceffWipe_Destroy,
    (ActorFunc)OceffWipe_Update,
    (ActorFunc)OceffWipe_Draw,
};
*/

void OceffWipe_Init(Actor* thisx, GlobalContext* globalCtx) {
    OceffWipe* this = THIS;

    Actor_SetScale(&this->actor, 0.1f);
    this->unk_144 = 0;
    this->actor.world.pos = ACTIVE_CAM->eye;
}

#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_Oceff_Wipe_0x809764B0/OceffWipe_Destroy.asm")
/*void OceffWipe_Destroy(Actor *thisx, GlobalContext *globalCtx) {
    OceffWipe* this = THIS;

    func_80115D5C(globalCtx);
    globalCtx->unk169B8 = (u8)0;
}*/

void OceffWipe_Update(Actor* thisx, GlobalContext* globalCtx) {
    OceffWipe* this = THIS;

    this->actor.world.pos = ACTIVE_CAM->eye;

    if (this->unk_144 < 100) {
        this->unk_144++;
    } else {
        Actor_MarkForDeath(&this->actor);
    }
}

#pragma GLOBAL_ASM("./asm/non_matchings/overlays/ovl_Oceff_Wipe_0x809764B0/OceffWipe_Draw.asm")
/*void OceffWipe_Draw(Actor *this, GlobalContext *globalCtx) {
    OceffWipe* this = THIS;

    s32 spA4;
    f32 sp9C;
    s8 sp96;
    s8 sp95;
    u8 sp94;
    f32 sp84;
    f32 sp74;
    Gfx *sp68;
    Gfx *sp50;
    Camera *temp_t5;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    Gfx *temp_v0_4;
    Gfx *temp_v0_5;
    Gfx *temp_v0_6;
    Gfx *temp_v0_7;
    Gfx *temp_v0_8;
    GraphicsContext *temp_s0;
    s16 temp_v1;
    s32 temp_a2_2;
    u32 temp_a3_2;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_a3;
    u8 temp_t0;
    void *temp_a0;
    void *temp_v1_2;
    s32 phi_v1;
    void *phi_a0;
    void *phi_v1_2;

    spA4 = globalCtx->state.frames & 0xFF;
    temp_t5 = globalCtx->cameraPtrs[globalCtx->activeCamera];
    sp84.unk0 = (bitwise s32) temp_t5->eye.x;
    sp84.unk4 = (bitwise s32) temp_t5->eye.y;
    sp84.unk8 = (bitwise s32) temp_t5->eye.z;
    func_800E01B8(&sp74, globalCtx->cameraPtrs[globalCtx->activeCamera]);
    temp_v1 = (s16) this->unk_144;
    temp_s0 = globalCtx->state.gfxCtx;
    if ((s32) temp_v1 < 0x20) {
        sp9C = Math_SinS((s16) ((s32) (temp_v1 << 0x19) >> 0x10)) * 1360.0f;
        phi_v1 = (s32) (s16) this->unk_144;
    } else {
        sp9C = 1360.0f;
        phi_v1 = (s32) temp_v1;
    }
    if (phi_v1 >= 0x50) {
        sp94 = 0;
        sp95 = (0x64 - this->unk_144) * 8;
        sp96 = (0x64 - this->unk_144) * 0xC;
    } else {
        sp94 = 0;
        sp95 = 0xA0;
        sp96 = 0xFF;
    }
    phi_a0 = &D_80977160;
    phi_v1_2 = &D_80976DA0;
loop_7:
    temp_a1 = phi_a0->unk0;
    temp_a2 = phi_a0->unk1;
    temp_a3 = phi_a0->unk2;
    phi_v1_2->unkF = (u8) (&sp94)[(s32) (temp_a1 & 0xF0) >> 4];
    phi_v1_2->unk1F = (u8) (&sp94)[temp_a1 & 0xF];
    temp_t0 = phi_a0->unk3;
    phi_v1_2->unk2F = (u8) (&sp94)[(s32) (temp_a2 & 0xF0) >> 4];
    phi_v1_2->unk3F = (u8) (&sp94)[temp_a2 & 0xF];
    phi_v1_2->unk4F = (u8) (&sp94)[(s32) (temp_a3 & 0xF0) >> 4];
    phi_v1_2->unk5F = (u8) (&sp94)[temp_a3 & 0xF];
    temp_a0 = phi_a0 + 4;
    temp_v1_2 = phi_v1_2 + 0x80;
    temp_v1_2->unk-1 = (u8) (&sp94)[temp_t0 & 0xF];
    temp_v1_2->unk-11 = (u8) (&sp94)[(s32) (temp_t0 & 0xF0) >> 4];
    phi_a0 = temp_a0;
    phi_v1_2 = temp_v1_2;
    if (temp_a0 != &D_80977174) {
        goto loop_7;
    }
    func_8012C2DC(globalCtx->state.gfxCtx);
    SysMatrix_InsertTranslation(sp84 + sp74, sp88 + sp78, sp8C + sp7C, 0);
    Matrix_Scale(0.1f, 0.1f, 0.1f, (u8)1U);
    SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);
    SysMatrix_InsertXRotation_s((u16)0x708, 1);
    SysMatrix_InsertTranslation(0.0f, 0.0f, -sp9C, 1);
    temp_v0 = temp_s0->polyXlu.p;
    temp_s0->polyXlu.p = temp_v0 + 8;
    temp_v0->words.w0 = 0xDA380003;
    sp68 = temp_v0;
    sp68->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx);
    if (this->actor.params != 0) {
        temp_v0_2 = temp_s0->polyXlu.p;
        temp_s0->polyXlu.p = temp_v0_2 + 8;
        temp_v0_2->words.w1 = 0xAAFFFFFF;
        temp_v0_2->words.w0 = 0xFA000000;
        temp_v0_3 = temp_s0->polyXlu.p;
        temp_s0->polyXlu.p = temp_v0_3 + 8;
        temp_v0_3->words.w0 = 0xFB000000;
        temp_v0_3->words.w1 = 0x96FF80;
    } else {
        temp_v0_4 = temp_s0->polyXlu.p;
        temp_s0->polyXlu.p = temp_v0_4 + 8;
        temp_v0_4->words.w1 = -0x3701;
        temp_v0_4->words.w0 = 0xFA000000;
        temp_v0_5 = temp_s0->polyXlu.p;
        temp_s0->polyXlu.p = temp_v0_5 + 8;
        temp_v0_5->words.w1 = 0x6400FF80;
        temp_v0_5->words.w0 = 0xFB000000;
    }
    temp_v0_6 = temp_s0->polyXlu.p;
    temp_s0->polyXlu.p = temp_v0_6 + 8;
    temp_v0_6->words.w1 = (u32) &D_80977020;
    temp_v0_6->words.w0 = 0xDE000000;
    temp_v0_7 = temp_s0->polyXlu.p;
    temp_a3_2 = -spA4 * 2;
    temp_s0->polyXlu.p = temp_v0_7 + 8;
    temp_v0_7->words.w0 = 0xDE000000;
    temp_a2_2 = -spA4;
    sp50 = temp_v0_7;
    sp50->words.w1 = Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (u32) temp_a2_2, temp_a3_2, 0x20, 0x20, 1, temp_a2_2,
temp_a3_2, 0x20, 0x20); temp_v0_8 = temp_s0->polyXlu.p; temp_s0->polyXlu.p = temp_v0_8 + 8; temp_v0_8->words.w1 = (u32)
&D_809770A8; temp_v0_8->words.w0 = 0xDE000000; }a*/
