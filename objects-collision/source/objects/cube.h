#pragma once

#include <grrlib.h>

class Cube {
    private:
        float size;
        u32 colour[3] = {0xFFFFFFFF, 0xAAAAAAFF, 0x666666FF};

    public:
        int x;
        int y;
        int z;

        float angX = 0;
        float angY = 0;
        float angZ = 0;

        Cube(float size, int x, int y, int z);
        void draw();
        void pitch(float amount);
        void roll(float amount);

};