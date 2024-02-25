#include <grrlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "objects/cube.h"
#include "FreeMonoBold_ttf.h"

int main(int argc, char **argv) {
    u32 type;
    auto cube = Cube(1.0F, -2, 0, 0);
    auto cube2 = Cube(1.0F, 2, 0, 0);

    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    // Initialise the Wiimotes
    WPAD_Init();
    GRRLIB_ttfFont *myFont = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);
    GRRLIB_Settings.antialias = true;

    GRRLIB_SetBackgroundColour(0x00, 0xFF, 0x00, 0xFF);
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

        if(err == WPAD_ERR_NONE) {
            wd1 = WPAD_Data(WPAD_CHAN_0);
            wd2 = WPAD_Data(WPAD_CHAN_1);
            printf("DATA ERR: %d",wd1->err);

            GRRLIB_ObjectView(cube.x,cube.y,cube.z,
                            cube.angX,cube.angY,cube.angZ,
                            1,1,1);
            cube.draw();
            GRRLIB_ObjectView(cube2.x,cube2.y,cube2.z,
                            cube2.angX,cube2.angY,cube2.angZ,
                            1,1,1);
            cube2.draw();
            char yaw[25];
		    char roll[25];
            
            snprintf(roll, sizeof(roll), "ROLL: %.02f",wd2->orient.roll);
            // printf("\n");
            printf("ORIENT:");
            
            // printf("YAW: %.02f",wd->orient.yaw); // frozen at 0.00
            printf("ROLL: %.02f",wd2->orient.roll);
            snprintf(yaw, sizeof(yaw), "PITCH: %.02f",wd1->orient.pitch);
            GRRLIB_2dMode();
            if (wd1->orient.pitch<-cube.angX-1 || wd1->orient.pitch>-cube.angX+1){
                
                GRRLIB_PrintfTTF(100,110, myFont,yaw,12, 0x002134FF);
                cube.pitch(wd1->orient.pitch);
            }
            if (wd2->orient.roll<-cube.angZ-1 || wd2->orient.roll>-cube.angZ+1){
                cube.roll(wd2->orient.roll);
                
                GRRLIB_PrintfTTF(100,120, myFont,roll,12, 0x002134FF);
            }
            //cube.roll(wd2->orient.roll);
            
            
        }


        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}