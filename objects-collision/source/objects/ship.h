#pragma once

#include <grrlib.h>

class Ship {
    private:
        float size;
        u32 colour[3] = {0xFFFFFFFF, 0xAAAAAAFF, 0x666666FF};

    public:
        Ship(float size);
        void draw();
};