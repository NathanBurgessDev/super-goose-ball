#include "cube.h"


Cube::Cube(float multiplier, u32 colour) {
    this->multiplier = multiplier;
    this->colour = colour;
}

void Cube::draw() {
    GX_Begin(GX_QUADS, GX_VTXFMT0, 24);
            GX_Position3f32(-multiplier,multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,-multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,-multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,multiplier,-multiplier);
            GX_Color1u32(colour);

            GX_Position3f32(-multiplier,multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,-multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,-multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,multiplier,multiplier);
            GX_Color1u32(colour);

            GX_Position3f32(-multiplier,multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,multiplier,-multiplier);
            GX_Color1u32(colour);

            GX_Position3f32(-multiplier,-multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,-multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,-multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,-multiplier,-multiplier);
            GX_Color1u32(colour);

            GX_Position3f32(-multiplier,multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,-multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(-multiplier,-multiplier,multiplier);
            GX_Color1u32(colour);

            GX_Position3f32(multiplier,multiplier,multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,-multiplier,-multiplier);
            GX_Color1u32(colour);
            GX_Position3f32(multiplier,-multiplier,multiplier);
            GX_Color1u32(colour);
        GX_End();
}