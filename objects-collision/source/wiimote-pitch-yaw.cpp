#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "objects/cube.h"

int main(int argc, char **argv) {
    u32 type;
    auto cube = Cube(1.0F, 0, 0, 0);
    auto platform = Cube(1.0F, 0, -1, 0);

    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    // Initialise the Wiimotes
    WPAD_Init();

    GRRLIB_Settings.antialias = true;

    GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);
    GRRLIB_Camera3dSettings(0.0f,0.0f,13.0f, 0,1,0, 0,0,0);

    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
    
    WPAD_SetDataFormat(WPAD_CHAN_1, WPAD_FMT_BTNS_ACC_IR);
    

	printf("set motion plus on all wiimotes : %d\n", WPAD_SetMotionPlus(-1, 1));
	WPADData* wd1;
	WPADData* wd2;

    // Loop forever
    while(1) {
        GRRLIB_2dMode();
        WPAD_ScanPads();
        if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) exit(0);
        // if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_A) cubeY++;
        // if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_B) cubeY--;

        int err = WPAD_Probe(WPAD_CHAN_0, &type);
        int err2 = WPAD_Probe(WPAD_CHAN_1, &type);
        switch(err) {
            case WPAD_ERR_NO_CONTROLLER:
                printf("WIIMOTE NOT CONNECTED\n");
                break;
            case WPAD_ERR_NOT_READY:
                printf("WIIMOTE NOT READY\n");
                break;
            case WPAD_ERR_NONE:
                printf("WIIMOTE READY\n");
                break;
            default:
                printf("UNK WIIMOTE STATE %d\n", err);
        }
        switch(err2) {
            case WPAD_ERR_NO_CONTROLLER:
                printf("WIIMOTE NOT CONNECTED\n");
                break;
            case WPAD_ERR_NOT_READY:
                printf("WIIMOTE NOT READY\n");
                break;
            case WPAD_ERR_NONE:
                printf("WIIMOTE READY\n");
                break;
            default:
                printf("UNK WIIMOTE STATE %d\n", err);
        }

        GRRLIB_3dMode(0.1,1000,45,0,0);
        GRRLIB_Camera3dSettings(0.0f,10.0f,30.0f, 0,1,0, 0,-5,0);

        if(err == WPAD_ERR_NONE) {
            wd1 = WPAD_Data(WPAD_CHAN_0);
            wd2 = WPAD_Data(WPAD_CHAN_1);
            printf("DATA ERR: %d",wd1->err);

            GRRLIB_ObjectView(cube.x,cube.y,cube.z,
                            cube.angX,cube.angY,cube.angZ,
                            1,1,1);
            cube.draw();
            // Draw platform
            GRRLIB_ObjectView(platform.x, platform.y, platform.z,
                            platform.angX, platform.angY, platform.angZ,
                            5, 0.01, 50);
            platform.draw();

            // Gravity
            // if(!GRRLIB_RectInRect(cube.getBottomRectX(), cube.getBottomRectY(),
            //                     cube.size * 2, cube.size * 2,
            //                     platform.getBottomRectX()*5, platform.getBottomRectY()*50,
            //                     (platform.size * 2)*5, (platform.size * 2) * 50
            // )) {
            //     cube.y--;
            // }

            platform.pitch(wd1->orient.pitch);
            // cube.z += 1 * platform.angX;
            platform.roll(wd2->orient.roll);
        }


        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}