#include "scene0.h"
#include "zivic.h"

static zivWindow window2 = { 90, 90, 300, 400, false, 0, 0, 0, 0 };



void scene0(state* state) {
    static char* Buffer = "HIII";
    static zivWindow window = { 30, 30, 200, 400 ,false, 0, 0, 0,0 };

    if (IsKeyPressed(KEY_J)) {
        zivWindow window23 = { 90, 90, 300, 400, false, 0, 0, 0,0 };
        window2 = window23;

        spawnWindowEx(&window2, state, BLUE, SKYBLUE, GRAY, DARKGRAY, SKYBLUE, "Hello", false);

    }

    spawnWindowEx(&window, state, BLUE, SKYBLUE, RED, LIGHTGRAY, GREEN, "No Hello", true);
    drawText(Buffer, window.x, window.y, 50, state->font, BLACK);
    ButtonState button = drawButton("Click Me", window.x + 40, window.y + 90, 110, 70, state->font, GRAY, WHITE, DARKGRAY, 30);
    if (button == BUTTON_CLICK_LEFT) {
        if (Buffer == "HIII") {
            Buffer = "BYEEE";
            Color color = { 100, 0, 0, 255 };
            state->backgroundColor = color;
        }
        else {
            Buffer = "HIII";
            Color color = { 100, 0, 0, 255 };
            state->backgroundColor = color;
        }
        
    }
}