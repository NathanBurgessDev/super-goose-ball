#pragma once

#include <grrlib.h>

class Cube {
    private:
        float multiplier;
        u32 colour;

    public:
        Cube(float multiplier, u32 colour);
        void draw();
};