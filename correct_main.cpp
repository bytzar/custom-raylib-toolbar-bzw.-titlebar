#include "raylib.h"                             //right click on toolbar "Always on Top (can only be turned on)", right cliick = pause game, snipit all lines,blue 
#include <string>
#include <fstream>
#define stop std::cin.get()
using namespace std;
using std::ifstream;
struct taskbar
{
    bool img1 = false;
    bool img2 = true;
    int fps = 0;
};

ifstream my_file1("screencapcounter.txt");

bool Cc = true;
bool uncc = true;
bool realCc;
bool showfps = false;
bool showmenu = false;
bool check;

bool mousydontmovey = true;
int mousyx;
int mouseyy;
Vector2 pos;
int windowpositionx;
int windowpositiony;

bool judas = false;
string screenfilename;
int value = 0;

bool sussyscreenie = false;

bool takescreenshot = false;
bool doublecheck = false;

int positionfmenux;
int positionfmenuy;

taskbar cross;
taskbar toggle;
taskbar curser;
taskbar cursericon;
taskbar minimizing;
taskbar camera;
taskbar fpsd;
taskbar aot;
taskbar pausus;

int timerforscreenshot = 0;

int mousemovement[2];
int timer;
bool checkmouse = true;
bool showmouse = false;

bool pause = false;
bool playus = true;

int g = 0;

const int screenWidth = 1024;
const int screenHeight = 768;

void Ccurser(Texture2D a, Texture2D b)
{
    HideCursor();
    if (curser.img2)
    {
    DrawTexture(a, GetMouseX(), GetMouseY(), SKYBLUE);
    }
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        curser.img2 = false;
    }
    if (curser.img2 == false)
    {
        DrawTexture(b, GetMouseX(), GetMouseY(), SKYBLUE);
    }
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        curser.img2 = true;
    }
}

void loadcross(Texture2D a, Texture2D b, Texture2D c)
{
    if (cross.img2) { DrawTexture(a, screenWidth - 19, 0, SKYBLUE); }
    if (GetMouseX() <= screenWidth && GetMouseX() >= screenWidth - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth - 19, 0, SKYBLUE);
        cross.fps = cross.fps + GetFPS();
        if (cross.fps >= 200)
        {
            DrawTexture(c, screenWidth - 19, 0, SKYBLUE);
            cross.img1 = true;
        }
    }
    else if (cross.fps != 0)
    {
        cross.img2 = false;
        if (cross.img1)
        {
            cross.fps = 0;
            cross.img1 = false;
        }
        cross.fps = cross.fps + GetFPS();
        if (cross.fps >= 59)
        {
            DrawTexture(b, screenWidth - 19, 0, SKYBLUE);

            if (cross.fps >= 200) { cross.img2 = true; cross.fps = 0;}
        }
    }
}

void loadcursericon(Texture2D a, Texture2D b, Texture2D c)
{
    if (cursericon.img2) { DrawTexture(a, screenWidth - 19 - 19 - 19 - 19, 0, SKYBLUE); }
    if (GetMouseX() <= screenWidth - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth - 19 - 19 - 19 - 19, 0, SKYBLUE);
        cursericon.fps = cursericon.fps + GetFPS();
        if (cursericon.fps >= 200)
        {
            DrawTexture(c, screenWidth - 19 - 19 - 19 - 19, 0, SKYBLUE);
            cursericon.img1 = true;
        }
    }
    else if (cursericon.fps != 0)
    {
        cursericon.img2 = false;
        if (cursericon.img1)
        {
            cursericon.fps = 0;
            cursericon.img1 = false;
        }
        cursericon.fps = cursericon.fps + GetFPS();
        if (cursericon.fps >= 59)
        {
            DrawTexture(b, screenWidth - 19 - 19 - 19 - 19, 0, SKYBLUE);

            if (cursericon.fps >= 200) { cursericon.img2 = true; cursericon.fps = 0;
            }
        }
    }
}

void camicon(Texture2D a, Texture2D b, Texture2D c)
{
    if (camera.img2) { DrawTexture(a, screenWidth - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE); }
    if (GetMouseX() <= screenWidth - 19 - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE);
        camera.fps = camera.fps + GetFPS();
        if (camera.fps >= 200)
        {
            DrawTexture(c, screenWidth - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE);
            camera.img1 = true;
        }
    }
    else if (camera.fps != 0)
    {
        camera.img2 = false;
        if (camera.img1)
        {
            camera.fps = 0;
            camera.img1 = false;
        }
        camera.fps = camera.fps + GetFPS();
        if (camera.fps >= 59)
        {
            DrawTexture(b, screenWidth - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE);

            if (camera.fps >= 200) 
            {
                camera.img2 = true; camera.fps = 0;
            }
        }
    }
}

void PauseIcon(Texture2D a, Texture2D b, Texture2D c)
{
    if (pausus.img2) { DrawTexture(a, screenWidth - 19 - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE); }
    if (GetMouseX() <= screenWidth - 19 - 19 - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth - 19 - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE);
        pausus.fps = pausus.fps + GetFPS();
        if (pausus.fps >= 200)
        {
            DrawTexture(c, screenWidth - 19 - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE);
            pausus.img1 = true;
        }
    }
    else if (pausus.fps != 0)
    {
        pausus.img2 = false;
        if (pausus.img1)
        {
            pausus.fps = 0;
            pausus.img1 = false;
        }
        pausus.fps = pausus.fps + GetFPS();
        if (pausus.fps >= 59)
        {
            DrawTexture(b, screenWidth - 19 - 19 - 19 - 19 - 19 - 19, 0, SKYBLUE);

            if (pausus.fps >= 200)
            {
                pausus.img2 = true; pausus.fps = 0;
            }
        }
    }
}

void fpsico(Texture2D a, Texture2D b, Texture2D c)
{
    if (fpsd.img2) { DrawTexture(a, 0, 0, SKYBLUE); }
    if (GetMouseX() <= 19 && GetMouseX() >= 0 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, 0, 0, SKYBLUE);
        fpsd.fps = fpsd.fps + GetFPS();
        if (fpsd.fps >= 200)
        {
            DrawTexture(c, 0, 0, SKYBLUE);
            fpsd.img1 = true;
        }
    }
    else if (fpsd.fps != 0)
    {
        fpsd.img2 = false;
        if (fpsd.img1)
        {
            fpsd.fps = 0;
            fpsd.img1 = false;
        }
        fpsd.fps = fpsd.fps + GetFPS();
        if (fpsd.fps >= 59)
        {
            DrawTexture(b, 0, 0, SKYBLUE);

            if (fpsd.fps >= 200)
            {
                fpsd.img2 = true; fpsd.fps = 0;
            }
        }
    }
}

void minimizeicon(Texture2D a, Texture2D b, Texture2D c)
{
    if (minimizing.img2) { DrawTexture(a, screenWidth - 19 - 19 - 19, 0, SKYBLUE); }
    else
    {
        DrawTexture(a, screenWidth - 19 - 19 - 1900, 0, SKYBLUE);
    }
    if (GetMouseX() <= screenWidth - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth - 19 - 19 - 19, 0, SKYBLUE);
        minimizing.fps = minimizing.fps + GetFPS();
        if (minimizing.fps >= 200)
        {
            DrawTexture(c, screenWidth - 19 - 19 - 19, 0, SKYBLUE);
            minimizing.img1 = true;
        }
    }
    else if (minimizing.fps != 0)
    {
        minimizing.img2 = false;
        if (minimizing.img1)
        {
            minimizing.fps = 0;
            minimizing.img1 = false;
        }
        minimizing.fps = minimizing.fps + GetFPS();
        if (minimizing.fps >= 59)
        {
            DrawTexture(b, screenWidth - 19 - 19 - 19, 0, SKYBLUE);

            if (minimizing.fps >= 200) {
                minimizing.img2 = true; minimizing.fps = 0;
            }
        }
    }
}

void loadfstoggle(Texture2D a, Texture2D b, Texture2D c)
{
    if (toggle.img2) { DrawTexture(a, screenWidth - 19 - 19, 0, SKYBLUE); }
    if (GetMouseX() <= screenWidth - 19 && GetMouseX() >= screenWidth - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth - 19 - 19, 0, SKYBLUE);
        toggle.fps = toggle.fps + GetFPS();
        if (toggle.fps >= 200)
        {
            DrawTexture(c, screenWidth - 19 - 19, 0, SKYBLUE);
            toggle.img1 = true;
        }
    }
    else if (toggle.fps != 0)
    {
        toggle.img2 = false;
        if (toggle.img1)
        {
            toggle.fps = 0;
            toggle.img1 = false;
        }
        toggle.fps = toggle.fps + GetFPS();
        if (toggle.fps >= 59)
        {
            DrawTexture(b, screenWidth - 19 - 19, 0, SKYBLUE);

            if (toggle.fps >= 200) { toggle.img2 = true; toggle.fps = 0; }
        }
    }
}

void alwaysontop(Texture2D a, Texture2D b, Texture2D c)
{
    if (aot.img2) { DrawTexture(a, screenWidth / 2 - 9.5, 0, SKYBLUE); }
    if (GetMouseX() <= screenWidth / 2 + 9.5 && GetMouseX() >= screenWidth / 2 - 9.5 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        DrawTexture(b, screenWidth / 2 - 9.5, 0, SKYBLUE);
        aot.fps = aot.fps + GetFPS();
        if (aot.fps >= 200)
        {
            DrawTexture(c, screenWidth / 2 - 9.5, 0, SKYBLUE);
            aot.img1 = true;
        }
    }
    else if (aot.fps != 0)
    {
        aot.img2 = false;
        if (aot.img1)
        {
            aot.fps = 0;
            aot.img1 = false;
        }
        aot.fps = aot.fps + GetFPS();
        if (aot.fps >= 59)
        {
            DrawTexture(b, screenWidth / 2 - 9.5, 0, SKYBLUE);

            if (aot.fps >= 200) { aot.img2 = true; aot.fps = 0; }
        }
    }
}

void loading()
{
    while (GetFPS() > 60)
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawText("LOADING", screenWidth / 2 - 400, screenHeight / 2 - 50, 100, BLACK);
        g++;
        if (g >= 20) { DrawText(".", screenWidth / 2 + 70, screenHeight / 2 - 210, 300, BLACK); }
        if (g >= 32) { DrawText(".", screenWidth / 2 + 140, screenHeight / 2 - 210, 300, BLACK); }
        if (g >= 44) { DrawText(".", screenWidth / 2 + 210, screenHeight / 2 - 210, 300, BLACK); g = 0; }
        EndDrawing();
    }
}

void cursershow(Texture2D a, Texture2D b)
{
    if (Cc)
    {
        if (!showmouse)
        {
             Ccurser(a, b);
        }
    }
    else
    {
        if (!showmouse)
        {
            ShowCursor();
        }
    }
}

void toolbarfunctionality()
{
    if (GetMouseX() <= screenWidth - 19 && GetMouseX() >= screenWidth - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { ToggleFullscreen(); }
    }
    if (GetMouseX() <= screenWidth - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (uncc)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { Cc = false; uncc = false; }
        }
        else
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { Cc = true; uncc = true; }
        }
    }
    if (GetMouseX() <= screenWidth - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            SetWindowState(0x00000200);
        }
    }
    if (GetMouseX() <= screenWidth - 19 - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { takescreenshot = true; doublecheck = true; showmenu = false; } //where .exe is, there will be a screenshopts folder where screenshotws will be dropped in
    }
    if (GetMouseX() <= 19 && GetMouseX() >= 0 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (showfps)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { showfps = false; }
        }
        else
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { showfps = true; }
        }
    }
    if (GetMouseX() <= screenWidth / 2 + 9.5 && GetMouseX() >= screenWidth / 2 - 9.5 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { SetWindowState(0x00001000); }
    }
    if (showfps)
    {
        int fpsdisplay = GetFPS();
        DrawText(TextFormat("%02i", fpsdisplay), 20, 2, 17, ANUSGRAY);
    }
    if (!showmouse)
    {
        if (checkmouse)
        {
            mousemovement[0] = GetMouseX();
            mousemovement[1] = GetMouseY();
            timer = 0;
            checkmouse = false;
        }
        if (mousemovement[0] == GetMouseX() && mousemovement[1] == GetMouseY())
        {
            timer++;
        }
        else
        {
            timer = 0;
            checkmouse = true;
        }
        if (timer == 60 || timer == 61)
        {
            if (mousemovement[0] == GetMouseX() && mousemovement[1] == GetMouseY() && !IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                HideCursor();
                showmouse = true;
            }
        }
    }
    else if (showmouse)
    {
        if (mousemovement[0] != GetMouseX() || mousemovement[1] != GetMouseY() || IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            ShowCursor();
            showmouse = false;
            checkmouse = true;
            timer = 0;
        }
    }
    if (GetMouseX() <= screenWidth - 19 - 19 - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
    {
        if (playus)
        {
             if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { pause = true; }
        }
    }
}

int main()
{
    InitWindow(screenWidth, screenHeight, "you cant see this");
    SetWindowState(8);
    HideCursor();
    ifstream myfile("screencapcount.txt");
    myfile >> value;
    myfile.close();
    /*Texture2D exitcross1 = LoadTexture("assets/cross.png");*/
    Texture2D  exitcross1 = LoadTexture                   ("assets/textures/cross.png");
    Texture2D  exitcross2 = LoadTexture                  ("assets/textures/cross2.png");
    Texture2D  exitcross3 = LoadTexture                  ("assets/textures/cross3.png");
    Texture2D   fstoggle1 = LoadTexture              ("assets/textures/fullscreen.png");
    Texture2D   fstoggle2 = LoadTexture             ("assets/textures/fullscreen2.png");
    Texture2D   fstoggle3 = LoadTexture             ("assets/textures/fullscreen3.png");
    Texture2D     curserN = LoadTexture          ("assets/textures/curser.neutral.png");
    Texture2D     curserA = LoadTexture           ("assets/textures/curser.active.png");
    Texture2D cursericon3 = LoadTexture ("assets/textures/cursericonbetterneutral.png");
    Texture2D cursericon2 = LoadTexture("assets/textures/cursericonbetterneutral1.png");
    Texture2D cursericon1 = LoadTexture("assets/textures/cursericonbetterneutral2.png");
    Texture2D    minimize = LoadTexture                ("assets/textures/minimize.png");
    Texture2D   minimize2 = LoadTexture               ("assets/textures/minimize2.png");
    Texture2D   minimize3 = LoadTexture               ("assets/textures/minimize3.png");
    Texture2D      camera = LoadTexture                  ("assets/textures/camera.png");
    Texture2D     camera2 = LoadTexture                 ("assets/textures/camera2.png");
    Texture2D     camera3 = LoadTexture                 ("assets/textures/camera3.png");
    Texture2D         fps = LoadTexture                     ("assets/textures/fps.png");
    Texture2D        fps2 = LoadTexture                    ("assets/textures/fps2.png");
    Texture2D        fps3 = LoadTexture                    ("assets/textures/fps3.png");
    Texture2D      aotico = LoadTexture                     ("assets/textures/aot.png");
    Texture2D     aotico2 = LoadTexture                    ("assets/textures/aot2.png");
    Texture2D     aotico3 = LoadTexture                    ("assets/textures/aot3.png");
    Texture2D      pause1 = LoadTexture                   ("assets/textures/pause.png");
    Texture2D      pause2 = LoadTexture                  ("assets/textures/pause2.png");
    Texture2D      pause3 = LoadTexture                  ("assets/textures/pause3.png");
    Texture2D        play = LoadTexture                    ("assets/textures/play.png");
    Texture2D       play2 = LoadTexture                   ("assets/textures/play2.png");
    Texture2D       play3 = LoadTexture                   ("assets/textures/play3.png");
    
    Texture2D  aotmen = LoadTexture("assets/textures/menu/aot.png");
    Texture2D  aotmenS = LoadTexture("assets/textures/menu/aotselect.png");
    Texture2D  customcursusmen = LoadTexture("assets/textures/menu/customcurser.png");
    Texture2D  customcursusmenS = LoadTexture("assets/textures/menu/customcurserselect.png");
    Texture2D  escmen = LoadTexture("assets/textures/menu/esc.png");
    Texture2D  escmenS = LoadTexture("assets/textures/menu/escselect.png");
    Texture2D  fpsmen = LoadTexture("assets/textures/menu/fps.png");
    Texture2D  fpsmenS = LoadTexture("assets/textures/menu/fpsselect.png");
    Texture2D  fullscreenmen = LoadTexture("assets/textures/menu/fullscreen.png");
    Texture2D  fullscreenmenS = LoadTexture("assets/textures/menu/fullscreenselect.png");
    Texture2D  minimizemen = LoadTexture("assets/textures/menu/minimize.png");
    Texture2D  minimizemenS = LoadTexture("assets/textures/menu/minimizezelect.png");
    Texture2D  pausemen = LoadTexture("assets/textures/menu/pause.png");
    Texture2D  pausemenS = LoadTexture("assets/textures/menu/pauseselect.png");
    Texture2D  screenshotmen = LoadTexture("assets/textures/menu/screenshot.png");
    Texture2D  screenshotmenS = LoadTexture("assets/textures/menu/screenshotselect.png");

    Texture2D  checkmark = LoadTexture("assets/textures/menu/checkmark.png");
    Texture2D  redmark = LoadTexture("assets/textures/menu/redmark.png");


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        loading();
        while (pause || showmenu)
        {
            BeginDrawing();
            ClearBackground(SKYBLUE);
            loadcross(exitcross1, exitcross2, exitcross3);
            loadfstoggle(fstoggle1, fstoggle2, fstoggle3);
            loadcursericon(cursericon1, cursericon2, cursericon3);
            minimizeicon(minimize, minimize2, minimize3);
            camicon(camera, camera2, camera3);
            fpsico(fps, fps2, fps3);
            PauseIcon(play, play2, play3);
            alwaysontop(aotico, aotico2, aotico3);

            cursershow(curserN, curserA);
            toolbarfunctionality();
            EndDrawing();
            check = GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 159 && GetMouseY() >= positionfmenuy;
            if (!check)
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    showmenu = false;
                }
            }
            if (GetMouseX() <= screenWidth && GetMouseX() >= screenWidth - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { CloseWindow(); return 0; }
            }
            if (GetMouseX() <= screenWidth - 19 - 19 - 19 - 19 - 19 && GetMouseX() >= screenWidth - 19 - 19 - 19 - 19 - 19 - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
            {
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                {
                    playus = false; break;
                }
            }
            if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
            {
                showmenu = true;
                positionfmenux = GetMouseX();
                positionfmenuy = GetMouseY();

            }
            if (showmenu)
            {
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 20 && GetMouseY() >= positionfmenuy)
                {
                    DrawTexture(fullscreenmenS, positionfmenux, positionfmenuy, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { ToggleFullscreen(); showmenu = false; }
                }
                else
                {
                    DrawTexture(fullscreenmen, positionfmenux, positionfmenuy, WHITE);
                }
                if (IsWindowFullscreen())
                {
                    DrawTexture(checkmark, positionfmenux + 170, positionfmenuy + 6, WHITE);
                }
                ///////////////////////////////////
                ///////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 40 && GetMouseY() >= positionfmenuy + 20)
                {
                    DrawTexture(customcursusmenS, positionfmenux, positionfmenuy + 20, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        if (uncc)
                        {
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { Cc = false; uncc = false; }
                        }
                        else
                        {
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { Cc = true; uncc = true; }
                        }
                        showmenu = false;
                    }
                }
                else
                {
                    DrawTexture(customcursusmen, positionfmenux, positionfmenuy + 20, WHITE);
                }
                if (Cc)
                {
                    DrawTexture(checkmark, positionfmenux + 170, positionfmenuy + 26, WHITE);
                }
                ////////////////////////////////////////
                ////////////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 60 && GetMouseY() >= positionfmenuy + 40)
                {
                    DrawTexture(fpsmenS, positionfmenux, positionfmenuy + 40, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        if (showfps)
                        {
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { showfps = false; }
                        }
                        else
                        {
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { showfps = true; }
                        }
                        showmenu = false;
                    }
                }
                else
                {
                    DrawTexture(fpsmen, positionfmenux, positionfmenuy + 40, WHITE);
                }
                if (showfps)
                {
                    DrawTexture(checkmark, positionfmenux + 170, positionfmenuy + 46, WHITE);
                }
                //////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 80 && GetMouseY() >= positionfmenuy + 60)
                {
                    DrawTexture(aotmenS, positionfmenux, positionfmenuy + 60, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { SetWindowState(0x00001000);  showmenu = false; }
                }
                else
                {
                    DrawTexture(aotmen, positionfmenux, positionfmenuy + 60, WHITE);
                }
                if (IsWindowState(0x00001000))
                {
                    DrawTexture(redmark, positionfmenux + 170, positionfmenuy + 66, WHITE);
                }
                ////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 100 && GetMouseY() >= positionfmenuy + 80)
                {
                    DrawTexture(screenshotmenS, positionfmenux, positionfmenuy + 80, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { showmenu = false; takescreenshot = true; doublecheck = true; goto offmenu; }
                }
                else
                {
                    DrawTexture(screenshotmen, positionfmenux, positionfmenuy + 80, WHITE);
                }
                ///////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 120 && GetMouseY() >= positionfmenuy + 100)
                {
                    DrawTexture(pausemenS, positionfmenux, positionfmenuy + 100, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
                    {
                        if (!pause)
                        {
                            pause = true; showmenu = false; goto endus;
                        }
                        else
                        {
                            pause = false; showmenu = false;
                        } 
                    }
                }
                else
                {
                    DrawTexture(pausemen, positionfmenux, positionfmenuy + 100, WHITE);
                }
                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 140 && GetMouseY() >= positionfmenuy + 120)
                {
                    DrawTexture(minimizemenS, positionfmenux, positionfmenuy + 120, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        SetWindowState(0x00000200);
                    }
                }
                else
                {
                    DrawTexture(minimizemen, positionfmenux, positionfmenuy + 120, WHITE);
                }
                ///////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////
                if (GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 160 && GetMouseY() >= positionfmenuy + 140)
                {
                    DrawTexture(escmenS, positionfmenux, positionfmenuy + 140, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        CloseWindow();
                        return 0;
                    }
                }
                else
                {
                    DrawTexture(escmen, positionfmenux, positionfmenuy + 140, WHITE);
                }
            }
        }
        if (takescreenshot)
        {
            if (doublecheck)
            {
                EndDrawing();
                BeginDrawing();
                ClearBackground(WHITE);
                EndDrawing();
                timerforscreenshot = 0;
                doublecheck = false;
                judas = true;
            }
            if (timerforscreenshot == 5)
            {
                if (Cc)
                {
                    Cc = false;
                    realCc = true;
                }
                else
                {
                    HideCursor();
                    realCc = false;
                }
                goto end;
            }
            if (timerforscreenshot == 10)
            {
                if (!my_file1.is_open())
                {
                    my_file1.open("screencapcount.txt");
                    my_file1.close();
                    ofstream mafile("screencapcount.txt");
                    mafile << 0;
                }
                value++;
                screenfilename = "";
                screenfilename.push_back((char)('s'));
                screenfilename.push_back((char)('c'));
                screenfilename.push_back((char)('r'));
                screenfilename.push_back((char)('e'));
                screenfilename.push_back((char)('e'));
                screenfilename.push_back((char)('n'));
                screenfilename.push_back((char)('s'));
                screenfilename.push_back((char)('h'));
                screenfilename.push_back((char)('o'));
                screenfilename.push_back((char)('t'));
                screenfilename.push_back((char)('s'));
                screenfilename.push_back((char)('/'));
                screenfilename.push_back((char)('s'));
                screenfilename.push_back((char)('c'));
                screenfilename.push_back((char)('r'));
                screenfilename.push_back((char)('e'));
                screenfilename.push_back((char)('e'));
                screenfilename.push_back((char)('n'));
                screenfilename.push_back((char)('s'));
                screenfilename.push_back((char)('h'));
                screenfilename.push_back((char)('o'));
                screenfilename.push_back((char)('t'));
                screenfilename.push_back((char)(' '));
                screenfilename.push_back((char)('('));
                screenfilename.push_back((char)('0' + value));                                      //i love myself
                screenfilename.push_back((char)(')'));
                screenfilename.push_back((char)('.'));                                          //but what i love more
                screenfilename.push_back((char)('p'));                                          //is the fact that this works
                screenfilename.push_back((char)('n'));                                          //unlike everything else
                screenfilename.push_back((char)('g'));                                          //ive tried so far
                const char* sussy = screenfilename.c_str();                                     //adding the .png extension has proven to be a pain whilst having altering screenshot names everey screenshot
                TakeScreenshot(sussy);
                takescreenshot = false;
                doublecheck = false;
                ofstream my_file("screencapcount.txt");
                    my_file << value;
                    my_file.close();
            }
        }
        if (timerforscreenshot == 14)
        {
            if (realCc)
            {
                Cc = true;
                realCc = false;
            }
            else
            {
                ShowCursor();
            }
            timerforscreenshot = 0;
            judas = false;
        }
        if (judas)
        {
            timerforscreenshot++;
        }
        pause = false;
        toolbarfunctionality();
        if (GetMouseX() <= screenWidth && GetMouseX() >= screenWidth - 19 && GetMouseY() >= 0 && GetMouseY() <= 19)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { CloseWindow(); return 0; }
        }
        check = GetMouseX() <= positionfmenux + 181 && GetMouseX() >= positionfmenux && GetMouseY() <= positionfmenuy + 159 && GetMouseY() >= positionfmenuy;
        if (!check)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                showmenu = false;
            }
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
        {
            showmenu = true;
            positionfmenux = GetMouseX();
            positionfmenuy = GetMouseY();
        }
    offmenu:
        BeginDrawing();

        ClearBackground(SKYBLUE);

        loadcross(exitcross1, exitcross2, exitcross3);
        loadfstoggle(fstoggle1, fstoggle2, fstoggle3);
        loadcursericon(cursericon1, cursericon2, cursericon3);
        minimizeicon(minimize, minimize2, minimize3);
        camicon(camera, camera2, camera3);
        fpsico(fps, fps2, fps3);
        alwaysontop(aotico, aotico2, aotico3);
        PauseIcon(pause1, pause2, pause3);

        if (GetMouseY() <= 19)
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                if (mousydontmovey)
                {
                    mousyx = GetMouseX();
                    mouseyy = GetMouseY();
                    mousydontmovey = false;
                    pos = GetWindowPosition();
                    windowpositionx = pos.x;
                    windowpositiony = pos.y;
                }
                if (GetMouseX() > mousyx)
                {
                    windowpositionx = windowpositionx + GetMouseX() - mousyx;
                    SetWindowPosition(windowpositionx, windowpositiony);
                }
                if (GetMouseX() < mousyx)
                {
                    windowpositionx = windowpositionx + GetMouseX() - mousyx;
                    SetWindowPosition(windowpositionx, windowpositiony);
                }
                if (GetMouseY() > mouseyy)
                {
                    windowpositiony = windowpositiony + GetMouseY() - mouseyy;
                    SetWindowPosition(windowpositionx, windowpositiony);
                }
                if (GetMouseY() < mouseyy)
                {
                    windowpositiony = windowpositiony + GetMouseY() - mouseyy;
                    SetWindowPosition(windowpositionx, windowpositiony);
                }
                if (GetMouseX() > mousyx && GetMouseY() > mouseyy)
                {
                    windowpositionx = windowpositionx + GetMouseX() - mousyx;
                    windowpositiony = windowpositiony + GetMouseY() - mouseyy;
                    SetWindowPosition(windowpositionx, windowpositiony);
                }
                if (GetMouseX() > mousyx && GetMouseY() < mouseyy)
                {
                    windowpositionx = windowpositionx + GetMouseX() - mousyx;
                    windowpositiony = windowpositiony + GetMouseY() - mouseyy;
                    SetWindowPosition(windowpositionx, windowpositiony);
                }
                else
                {
                    SetMousePosition(mousyx, mouseyy);
                }
            }
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                mousydontmovey = true;
            }
        }
        if (!mousydontmovey && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && GetMouseY() >= 19)
        {
            SetMousePosition(mousyx, mouseyy);
        }


        if (!realCc)
        {
            cursershow(curserN, curserA);
        }

        EndDrawing();

        if (sussyscreenie)
        {
        end:
            HideCursor();
            timerforscreenshot++;
        }
        playus = true;
        if (sussyscreenie)
        {
        endus:
            pause = true;
            playus = false;
        }
    }

    CloseWindow();
    return 0;
}
