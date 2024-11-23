#include "createWindow.h"
#include "windowaddition.h"
extern pstate state;

void spawnWindow(zivWindow* window) {
    printf("Before Dragging - X: %d, Y: %d\n", window->x, window->y);
    Color basecolor = { 0, 0, 100, 255 };
    Color scolor = { 0, 0, 200, 255 };
    drawButton("", window->x, window->y, window->sizeX, window->sizeY, state.font, basecolor, WHITE, scolor, NULL);
    ButtonState bar = drawButton("", window->x, window->y - 10, window->sizeX, 10, state.font, basecolor, WHITE, scolor, NULL);

    if (bar == BUTTON_DOWN_LEFT || window->isDragging) {
        if (!window->isDragging) {
            window->isDragging = true;
            window->dragOffsetX = GetMouseX() - window->x;
            window->dragOffsetY = GetMouseY() - window->y;
        }

        if (window->isDragging && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            window->x = GetMouseX() - window->dragOffsetX;
            window->y = GetMouseY() - window->dragOffsetY;
            printf("After Dragging - X: %d, Y: %d\n", window->x, window->y);
            window->dragStopDelay -= GetFrameTime();
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || (window->isDragging && window->dragStopDelay <= 0)) {
        window->isDragging = false;
        window->dragStopDelay = 0.5;
    }
}


void spawnWindowEx(zivWindow* window, Color titleBarColor, Color titleBarColorHover, Color windowColor, Color windowColorHover, Color textColor, char* titleBarTitle, bool isResizeable) {
    if (!window->init) {
        window->prevSizeX = window->sizeX;
        window->prevSizeY = window->sizeY;
        window->init = true;
    }
    window->sizeXPast = window->sizeX;
    window->sizeYPast = window->sizeY;

    if(isResizeable) resize(window, windowColor, windowColorHover);
    printf("Before Dragging - X: %d, Y: %d\n", window->x, window->y);
    drawButton("", window->x, window->y, window->sizeX, window->sizeY, state.font, windowColor, WHITE, windowColorHover, NULL);
    ButtonState bar = drawButton(titleBarTitle, window->x, window->y - 30, window->sizeX, 30, state.font, titleBarColor, WHITE, titleBarColorHover, NULL);
    
    if (bar == BUTTON_DOWN_LEFT || window->isDragging) {
        if (!window->isDragging) {
            window->isDragging = true;
            window->dragOffsetX = GetMouseX() - window->x;
            window->dragOffsetY = GetMouseY() - window->y;
        }

        if (window->isDragging && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            window->x = GetMouseX() - window->dragOffsetX;
            window->y = GetMouseY() - window->dragOffsetY;
            printf("After Dragging - X: %d, Y: %d\n", window->x, window->y);
            window->dragStopDelay -= GetFrameTime();
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || (window->isDragging && window->dragStopDelay <= 0)) {
        window->isDragging = false;
        window->dragStopDelay = 0.5;
    }
}
