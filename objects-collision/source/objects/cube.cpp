#include "cube.h"
#include <math.h>

Cube::Cube(float size, f32 x, f32 y, f32 z) {
    this->size = size;
    this->x = x;
    this->y = y;
    this->z = z;
}

void Cube::pitch(float amount) {
    // DEBUG
    // this->angX += amount;

    if(amount <= 30.0F && amount >= -30.0F) {
        this->angX = -amount;
    }
    
}

void Cube::roll(float amount) {
    // DEBUG
    // this->angZ += amount;

    if(amount <= 60.0f && amount >= -60.0f) {
        this->angZ = -amount;
    }
}

void Cube::yaw(float amount) {
    // DEBUG
    // this->angY += amount;

    if(amount <= 60.0F && amount >= -60.0F) {
        this->angY = -amount;
    }
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
    return floor(this->x - this->size);
}

int Cube::getBottomRectY() {
    return floor(this->z - this->size);
}