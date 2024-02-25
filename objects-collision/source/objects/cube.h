#pragma once

#include <grrlib.h>

class Cube {
    private:
        u32 colour[3] = {0xFFFFFFFF, 0xAAAAAAFF, 0x666666FF};

    public:
        float size;

        f32 x;
        f32 y;
        f32 z;

        float angX = 0;
        float angY = 0;
        float angZ = 0;

        Cube(float size, f32 x, f32 y, f32 z);
        void draw();
        void pitch(float amount);
        void roll(float amount);
        void yaw(float amount);
        int getBottomRectX();
        int getBottomRectY();

};