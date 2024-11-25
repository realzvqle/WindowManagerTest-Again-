#include "createWindow.h"
#include "windowaddition.h"
extern pstate state;
#include "../task/tasks.h"



void SpawnWindow(zivWindow* window, void* task, Color titleBarColor, Color titleBarColorHover, Color windowColor, Color windowColorHover, Color textColor, const char* titleBarTitle, bool isResizeable) {
    //TASK* tasks = task;
    if (!window->init) {
        window->prevSizeX = window->sizeX;
        window->prevSizeY = window->sizeY;
        window->init = true;
    }
    window->sizeXPast = window->sizeX;
    window->sizeYPast = window->sizeY;

    if(isResizeable) resize(window, windowColor, windowColorHover);
    ZiDrawButton("", window->x, window->y, window->sizeX, window->sizeY, windowColor, WHITE, windowColorHover, (int)NULL);
    ButtonState bar = ZiDrawButton(titleBarTitle, window->x, window->y - 30, window->sizeX, 30, titleBarColor, WHITE, titleBarColorHover, (int)NULL);
    Exitbutton(window, (TASK*)task);
    Hidebutton(window, (TASK*)task);
    if (bar == BUTTON_DOWN_LEFT || window->isDragging) {
        if (!window->isDragging) {
            window->isDragging = true;
            window->dragOffsetX = GetMouseX() - window->x;
            window->dragOffsetY = GetMouseY() - window->y;
        }

        if (window->isDragging && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            window->x = GetMouseX() - window->dragOffsetX;
            window->y = GetMouseY() - window->dragOffsetY;
            window->dragStopDelay -= GetFrameTime();
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || (window->isDragging && window->dragStopDelay <= 0)) {
        window->isDragging = false;
        window->dragStopDelay = 0.5;
    }
}
