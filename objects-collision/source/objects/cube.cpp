#include "cube.h"

Cube::Cube(float size, int x, int y, int z) {
    this->size = size;
    this->x = x;
    this->y = y;
    this->z = z;
}

void Cube::pitch(float amount) {
    // DEBUG
    // this->angX += amount;

    this->angX = -amount;
}

void Cube::roll(float amount) {
    // DEBUG
    // this->angZ += amount;

    this->angZ = -amount;
}

void Cube::yaw(float amount) {
    // DEBUG
    // this->angY += amount;

    this->angY = -amount;
}

void Cube::draw() {
    GX_Begin(GX_QUADS, GX_VTXFMT0, 24);
            GX_Position3f32(-size,size,-size);
            GX_Color1u32(colour[0]);
            GX_Position3f32(-size,-size,-size);
            GX_Color1u32(colour[0]);
            GX_Position3f32(size,-size,-size);
            GX_Color1u32(colour[0]);
            GX_Position3f32(size,size,-size);
            GX_Color1u32(colour[0]);

            GX_Position3f32(-size,size,size);
            GX_Color1u32(colour[0]);
            GX_Position3f32(-size,-size,size);
            GX_Color1u32(colour[0]);
            GX_Position3f32(size,-size,size);
            GX_Color1u32(colour[0]);
            GX_Position3f32(size,size,size);
            GX_Color1u32(colour[0]);

            GX_Position3f32(-size,size,size);
            GX_Color1u32(colour[1]);
            GX_Position3f32(size,size,size);
            GX_Color1u32(colour[1]);
            GX_Position3f32(size,size,-size);
            GX_Color1u32(colour[1]);
            GX_Position3f32(-size,size,-size);
            GX_Color1u32(colour[1]);

            GX_Position3f32(-size,-size,size);
            GX_Color1u32(colour[1]);
            GX_Position3f32(size,-size,size);
            GX_Color1u32(colour[1]);
            GX_Position3f32(size,-size,-size);
            GX_Color1u32(colour[1]);
            GX_Position3f32(-size,-size,-size);
            GX_Color1u32(colour[1]);

            GX_Position3f32(-size,size,size);
            GX_Color1u32(colour[2]);
            GX_Position3f32(-size,size,-size);
            GX_Color1u32(colour[2]);
            GX_Position3f32(-size,-size,-size);
            GX_Color1u32(colour[2]);
            GX_Position3f32(-size,-size,size);
            GX_Color1u32(colour[2]);

            GX_Position3f32(size,size,size);
            GX_Color1u32(colour[2]);
            GX_Position3f32(size,size,-size);
            GX_Color1u32(colour[2]);
            GX_Position3f32(size,-size,-size);
            GX_Color1u32(colour[2]);
            GX_Position3f32(size,-size,size);
            GX_Color1u32(colour[2]);
        GX_End();
}

int Cube::getBottomRectX() {
    return this->x - this->size;
}

int Cube::getBottomRectY() {
    return this->z - this->size;
}