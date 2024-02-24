#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "cube.h"

int main(int argc, char **argv) {
    float a = 0;
    const u32 col[3] = {0xFFFFFFFF, 0xAAAAAAFF, 0x666666FF};
    int cubeZ = 0;
    auto cube = Cube(1.0F, col[0]);

    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    // Initialise the Wiimotes
    WPAD_Init();

    GRRLIB_Settings.antialias = true;

    GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);
    GRRLIB_Camera3dSettings(0.0f,0.0f,13.0f, 0,1,0, 0,0,0);


    // Loop forever
    while(1) {

        GRRLIB_2dMode();
        WPAD_ScanPads();
        if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) exit(0);
        if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_A) cubeZ++;
        if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_B) cubeZ--;

        GRRLIB_3dMode(0.1,1000,45,0,0);
        GRRLIB_ObjectView(0,0,cubeZ, a,a*2,a*3,1,1,1);
        cube.draw();
        a+=0.5f;

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}