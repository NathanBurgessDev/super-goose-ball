/*===========================================
	Wiimote Demo
	by shdwcoder
	v1.5 - Using the latest libOGC with Wiimote support
	08/06/2008
	
	Using the great GRRLIB by NoNameNo
===========================================*/
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <grrlib.h>


#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ogcsys.h>

#include "../gfx/impact.h"
#include "../gfx/cursor.h"
#include "FreeMonoBold_ttf.h"

extern u16 *GRRLIB_buffer;


int main(){
	
	//Vars for pointer
	u32 type;
	VIDEO_Init();
	PAD_Init();
	WPAGRRLIB_ttfFont *myFont = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);D_Init();
	GRRLIB_Init();
	GRRLIB_ttfFont *myFont = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);
	GRRLIB_Settings.antialias = true;
	GRRLIB_SetBackgroundColour(0xFF, 0x00, 0x00, 0xFF);
	

	
	while(1)
{
	GRRLIB_2dMode();
    WPAD_ScanPads();
    u32 gcPressed = WPAD_ButtonsDown(0);
    if (gcPressed & WPAD_BUTTON_A) break;

    printf("Scanning pads... %i", gcPressed);
    

    
}
	
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
    
    WPAD_SetDataFormat(WPAD_CHAN_1, WPAD_FMT_BTNS_ACC_IR);
    

	printf("set motion plus on all wiimotes : %d\n", WPAD_SetMotionPlus(-1, 1));
	WPADData* wd1;
	WPADData* wd2;

while(1) {

    // Call WPAD_ScanPads each loop, this reads the latest controller states
    WPAD_ScanPads();

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

    if(err == WPAD_ERR_NONE) {
        wd1 = WPAD_Data(WPAD_CHAN_0);
		wd2= WPAD_Data(WPAD_CHAN_1);
        printf("DATA ERR: %d",wd1->err);
		char text[1000];
		char text1[1000];
		char text2[1000];
		char text3[1000];
		char text4[1000];
		char text5[1000];

		char text6[1000];
		char text7[1000];
		char text8[1000];
		char text9[1000];
		char text10[1000];
		char text11[1000];
		char text12[1000];
		char text13[1000];
		char text14[1000];
		char text15[1000];
		char text16[1000];
		char text17[1000];
		char text18[1000];
		char text19[1000];
		char text20[1000];
		
		char yaw[25];
		char roll[25];
		snprintf(text, sizeof(text), "                            ___");
        snprintf(text1, sizeof(text),"                      ,-\"\"   `.");
        snprintf(text2, sizeof(text),"                      ,'  _   e )`-._");
        snprintf(text3, sizeof(text), "                    /  ,' `-._<.===-'");
        snprintf(text4, sizeof(text), "                      /  /");
		snprintf(text5, sizeof(text), "                           /  ;");
      	snprintf(text6, sizeof(text), "         _          /   ;");
  		snprintf(text7, sizeof(text), "(`._    _.-\"\" \"\"--..__,'    |");
	    snprintf(text8, sizeof(text), "<_  `-\"\"                     \\");
		snprintf(text9, sizeof(text), " <`-                          :");
	    snprintf(text10, sizeof(text), "(__   <__.                  ;");
	    snprintf(text11, sizeof(text), "`-.   '-.__.      _.'    /");
        snprintf(text12, sizeof(text), "   \\      `-.__,-'    _,'");
		snprintf(text13, sizeof(text), "          `._    ,    /__,-'");
        snprintf(text14, sizeof(text), "       \"\"._\\__,'< <____");
        snprintf(text15, sizeof(text), "            | |  `----.`.");
		snprintf(text16, sizeof(text), "                  | |        \\ `.");
		snprintf(text17, sizeof(text), "                  ; |___      \\-``");
		snprintf(text18, sizeof(text), "                  \\   --<");
		snprintf(text19, sizeof(text), "                   `.`.<");
		snprintf(text20, sizeof(text), "              hjw    `-'");
		
    GRRLIB_PrintfTTF(100,200, myFont,text,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,210, myFont,text1,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,220, myFont,text2,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,230, myFont,text3,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,240, myFont,text4,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,250, myFont,text5,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,260, myFont,text6,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,270, myFont,text7,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,280, myFont,text8,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,290, myFont,text9,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,300, myFont,text10,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,310, myFont,text11,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,320, myFont,text12,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,330, myFont,text13,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,340, myFont,text14,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,350, myFont,text15,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,360, myFont,text16,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,370, myFont,text17,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,380, myFont,text18,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,390, myFont,text19,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,400, myFont,text20,12, 0x002134FF);

    // printf("\n");
    // printf("ACCEL:");
    // printf("X: %3d", wd->accel.x);
    // printf("Y: %3d", wd->accel.y);
    // printf("Z: %3d", wd->accel.z);
	snprintf(yaw, sizeof(yaw), "PITCH: %.02f",wd1->orient.pitch);
	snprintf(roll, sizeof(roll), "ROLL: %.02f",wd2->orient.roll);
    // printf("\n");
    printf("ORIENT:");
    printf("PITCH: %.02f",wd1->orient.pitch);
    // printf("YAW: %.02f",wd->orient.yaw); // frozen at 0.00
    printf("ROLL: %.02f",wd2->orient.roll);
	GRRLIB_PrintfTTF(100,410, myFont,yaw,12, 0x002134FF);
	GRRLIB_PrintfTTF(100,420, myFont,roll,12, 0x002134FF);

    // print("\n");
    // print("MP:");
    // print("PITCH: %.02f",wd->exp.mp.rx); // frozen at 0.00
    // print("YAW: %.02f",wd->exp.mp.ry); // frozen at 0.00
    // print("ROLL: %.02f",wd->exp.mp.rz); // frozen at 0.00

    // print("\n");
    // print("GFORCE:");
    // print("X: %.02f",wd->gforce.x);
    // print("Y: %.02f",wd->gforce.y);
    // print("Z: %.02f",wd->gforce.z);
    }

    // Wait for the next frame
    GRRLIB_Render();
}
GRRLIB_Exit();
}
