#ifndef Z_OCEFF_WIPE_H
#define Z_OCEFF_WIPE_H

#include <global.h>

struct OceffWipe;

typedef struct OceffWipe {
    /* 0x000 */ Actor actor;
    /* 0x144 */ s16 unk_144;
} OceffWipe; // size = 0x148

extern const ActorInit Oceff_Wipe_InitVars;

#endif // Z_OCEFF_WIPE_H
