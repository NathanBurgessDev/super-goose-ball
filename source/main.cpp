#include <fstream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>

#include <wiiuse/wpad.h>

#include "FreeMonoBold_ttf.h"

#include "obj.hpp"

// static void *xfb = NULL;
// static GXRModeObj *rmode = NULL;

//---------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    GRRLIB_Init();
    WPAD_Init();
    GRRLIB_ttfFont *myFont = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);
    float a = 0;

    //---------------------------------------------------------------------------------

    // // Initialise the video system
    // VIDEO_Init();

    // // This function initialises the attached controllers
    // WPAD_Init();

    // // Obtain the preferred video mode from the system
    // // This will correspon  d to the settings in the Wii menu
    // rmode = VIDEO_GetPreferredMode(NULL);

    // // Allocate memory for the display in the uncached region
    // xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

    // // Initialise the console, required for printf
    // console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);

    // // Set up the video registers with the chosen mode
    // VIDEO_Configure(rmode);

    // // Tell the video hardware where our display memory is
    // VIDEO_SetNextFramebuffer(xfb);

    // // Make the display visible
    // VIDEO_SetBlack(false);

    // // Flush the video register changes to the hardware
    // VIDEO_Flush();

    // // Wait for Video setup to complete
    // VIDEO_WaitVSync();
    // if (rmode->viTVMode & VI_NON_INTERLACE)
    //     VIDEO_WaitVSync();

    // The console understands VT terminal escape codes
    // This positions the cursor on row 2, column 0
    // we can use variables for this with format codes too
    // e.g. printf ("\x1b[%d;%dH", row, column );
    // printf("\x1b[2;0H");

    std::ifstream ifs("sd:/apps/HackSocGame/models/goose-new.obj");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    auto model = ObjModel(content);


    GRRLIB_Settings.antialias = true;

    GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);
    GRRLIB_Camera3dSettings(0.0f,0.0f,13.0f, 0,1,0, 0,0,0);
    // GRRLIB_SetLightAmbient(0x333333FF);

    while (1)
    {
        // GRRLIB_2dMode();

        // GRRLIB_PrintfTTF(100, 100, myFont, "Model parse succeeded!", 24, 0xFFFFFFFF);

        // Call WPAD_ScanPads each loop, this reads the latest controller states
        WPAD_ScanPads();

        // WPAD_ButtonsDown tells us which buttons were pressed in this loop
        // this is a "one shot" state which will not fire again until the button has been released
        u32 pressed = WPAD_ButtonsDown(0);


       
        // int offset = 0;
        // for (auto &vertexIndicie : model.vertexIndices) {
        //     char buffer[128];

        //     sprintf(buffer, "%f / %f / %f", model.verticies[vertexIndicie-1].x,model.verticies[vertexIndicie-1].y,model.verticies[vertexIndicie-1].z);

        //     GRRLIB_PrintfTTF(0, offset, myFont, buffer, 24, 0xFFFFFFFF);
        //     offset += 24;
        // }

        // We return to the launcher application via exit
        if (pressed & WPAD_BUTTON_HOME)
            exit(0);


        GRRLIB_3dMode(0.1,1000,45,0,0);
        // GRRLIB_SetLightAmbient(0x333333FF);
        // GRRLIB_SetLightDiff(0,(guVector){0.0f,2.0f,2.0f},10.0f,1.0f,0xFFFFFFFF);
        GRRLIB_ObjectView(0,0,0, a,a*2,a*3,1,1,1);

        // GX_Begin(GX_QUADS, GX_VTXFMT0, 24);
        //     GX_Position3f32(-1.0f,1.0f,-1.0f);
        //     GX_Color1u32(0xFFFFFFFF);
        //     GX_Position3f32(-1.0f,-1.0f,-1.0f);
        //     GX_Color1u32(0xFFFFFFFF);
        //     GX_Position3f32(1.0f,-1.0f,-1.0f);
        //     GX_Color1u32(0xFFFFFFFF);
        //     GX_Position3f32(1.0f,1.0f,-1.0f);
        //     GX_Color1u32(0xFFFFFFFF);

        //     GX_Position3f32(-1.0f,1.0f,1.0f);
        //     GX_Color1u32(0xFFFFFFFF);
        //     GX_Position3f32(-1.0f,-1.0f,1.0f);
        //     GX_Color1u32(0xFFFFFFFF);
        //     GX_Position3f32(1.0f,-1.0f,1.0f);
        //     GX_Color1u32(0xFFFFFFFF);
        //     GX_Position3f32(1.0f,1.0f,1.0f);
        //     GX_Color1u32(0xFFFFFFFF);

        //     GX_Position3f32(-1.0f,1.0f,1.0f);
        //     GX_Color1u32(0xAAAAAAFF);
        //     GX_Position3f32(1.0f,1.0f,1.0f);
        //     GX_Color1u32(0xAAAAAAFF);
        //     GX_Position3f32(1.0f,1.0f,-1.0f);
        //     GX_Color1u32(0xAAAAAAFF);
        //     GX_Position3f32(-1.0f,1.0f,-1.0f);
        //     GX_Color1u32(0xAAAAAAFF);

        //     GX_Position3f32(-1.0f,-1.0f,1.0f);
        //     GX_Color1u32(0xAAAAAAFF);
        //     GX_Position3f32(1.0f,-1.0f,1.0f);
        //     GX_Color1u32(0xAAAAAAFF);
        //     GX_Position3f32(1.0f,-1.0f,-1.0f);
        //     GX_Color1u32(0xAAAAAAFF);
        //     GX_Position3f32(-1.0f,-1.0f,-1.0f);
        //     GX_Color1u32(0xAAAAAAFF);

        //     GX_Position3f32(-1.0f,1.0f,1.0f);
        //     GX_Color1u32(0x666666FF);
        //     GX_Position3f32(-1.0f,1.0f,-1.0f);
        //     GX_Color1u32(0x666666FF);
        //     GX_Position3f32(-1.0f,-1.0f,-1.0f);
        //     GX_Color1u32(0x666666FF);
        //     GX_Position3f32(-1.0f,-1.0f,1.0f);
        //     GX_Color1u32(0x666666FF);

        //     GX_Position3f32(1.0f,1.0f,1.0f);
        //     GX_Color1u32(0x666666FF);
        //     GX_Position3f32(1.0f,1.0f,-1.0f);
        //     GX_Color1u32(0x666666FF);
        //     GX_Position3f32(1.0f,-1.0f,-1.0f);
        //     GX_Color1u32(0x666666FF);
        //     GX_Position3f32(1.0f,-1.0f,1.0f);
        //     GX_Color1u32(0x666666FF);
        // GX_End();
       

        // GX_Begin(GX_TRIANGLES, GX_VTXFMT0, 3);
        // GX_Position3f32(1.0f,1.0f,-1.0f);
        // GX_Normal3f32(0.0f,0.0f,-1.0f);
        // GX_Color1u32(0xFFFFFFFF);

        // GX_Position3f32(1.0f,-1.0f,-1.0f);
        // GX_Normal3f32(0.0f,0.0f,-1.0f);
        // GX_Color1u32(0xFFFFFFFF);


        // GX_Position3f32(-1.0f,-1.0f,-1.0f);
        // GX_Normal3f32(0.0f,0.0f,-1.0f);
        // GX_Color1u32(0xFFFFFFFF);

        // GX_End();
        a+=0.5f;
        model.drawModel();

        GRRLIB_2dMode();

        GRRLIB_Render();
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0); // Use exit() to exit a program, do not use 'return' from main()
}