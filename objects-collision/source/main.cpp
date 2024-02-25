#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "objects/cube.h"

int main(int argc, char **argv) {
    auto cube = Cube(1.0F, 0, 0, 0);
    auto platform = Cube(1.0F, 0, -1, 0);

    f32 a = 0;
    f32 offset = 1.5f;
    f32 rotpas = 60.0f;

    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    // Initialise the Wiimotes
    WPAD_Init();

    GRRLIB_Settings.antialias = true;

    GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);

    // Loop forever
    while(1) {
        GRRLIB_Camera3dSettings(0.0f,10.0f,30.0f, 0,1,0, 0,-5,0);


        GRRLIB_2dMode();
        WPAD_ScanPads();
        if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) exit(0);

        if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN) {
            // cube.pitch(1);
            // platform.pitch(1);
            cube.z--;
        }
        if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP) {
            // cube.pitch(-1);
            // platform.pitch(-1);
            cube.z++;
        }

        if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT) {
            // cube.roll(-1);
            // platform.roll(-1);
            cube.x--;
        }
        if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT) {
            // cube.roll(1);
            // platform.roll(1);
            cube.x++;
        }

        GRRLIB_3dMode(0.1,1000,45,0,0);

        // Draw Cube
        GRRLIB_ObjectView(cube.x,cube.y,cube.z,
                        cube.angX,cube.angY,cube.angZ,
                        1,1,1);
        // GRRLIB_ObjectViewBegin();
        // GRRLIB_ObjectViewRotate(0,a*3,0);
        // GRRLIB_ObjectViewTrans(0,offset,0);
        // GRRLIB_ObjectViewRotate(a,a*3,a*2+0*rotpas);
        // GRRLIB_ObjectViewEnd();
        cube.draw();

        // Draw platform
        GRRLIB_ObjectView(platform.x, platform.y, platform.z,
                        platform.angX, platform.angY, platform.angZ,
                        5, 0.01, 50);
        platform.draw();

        // Gravity
        if(!GRRLIB_RectInRect(cube.getBottomRectX(), cube.getBottomRectY(),
                            cube.size * 2, cube.size * 2,
                            platform.getBottomRectX()*5, platform.getBottomRectY()*50,
                            (platform.size * 2)*5, (platform.size * 2) * 50
        )) {
            cube.y--;
        }

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}