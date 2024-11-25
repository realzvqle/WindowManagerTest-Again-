#include "createWindow.h"
#include "windowaddition.h"

extern pstate state;


static void handleResizeButton(zivWindow* window, Color windowColor, Color windowColorHover) {
    window->resizeButtonHeight = 30;
    window->resizeButtonGap = 0;

    ButtonState underResize = ZiDrawButton("", window->x, window->y + window->sizeY + window->resizeButtonGap, window->sizeX, window->resizeButtonHeight, windowColor, WHITE, windowColorHover, (int)NULL);

    if (underResize == BUTTON_DOWN_LEFT || window->isResizing) {
        if (!window->isResizing) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                window->isResizing = true;
                window->resizeOffsetX = GetMouseX() - window->sizeX;
                window->resizeOffsetY = GetMouseY() - window->sizeY;
            }
        }

        if (window->isResizing && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            window->sizeX = GetMouseX() - window->resizeOffsetX;
            window->sizeY = GetMouseY() - window->resizeOffsetY;
        }

        if (window->prevSizeX > window->sizeX) window->sizeX = window->prevSizeX;
        if (window->prevSizeY > window->sizeY) window->sizeY = window->prevSizeY;
    }
}

static void handleResizeStop(zivWindow* window) {
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || (window->isResizing && window->resizeStopDelay <= 0)) {
        window->isResizing = false;
        window->resizeStopDelay = 0.5;
    }
}

void resize(zivWindow* window, Color windowColor, Color windowColorHover) {

    if (window->prevSizeX <= window->sizeX && window->prevSizeY <= window->sizeY) {
        handleResizeButton(window, windowColor, windowColorHover);
    }

    handleResizeStop(window);
}

void Exitbutton(zivWindow* window, TASK* task){
    int sizeX = 30;
    int sizeY = 30;
    
    ButtonState button = ZiDrawButton("X", window->x + window->sizeX, window->y - 30, sizeX, sizeY, GRAY, RED, DARKGRAY, (int)30);
    if (button == BUTTON_CLICK_LEFT) task->running = false;
}

void Hidebutton(zivWindow* window, TASK* task){
    int sizeX = 30;
    int sizeY = 30;
    
    ButtonState button = ZiDrawButton("H", window->x + window->sizeX, window->y, sizeX, sizeY, GRAY, BLUE, DARKGRAY, (int)30);
    if (button == BUTTON_CLICK_LEFT){
        if(task->hidden == true) task->hidden = false;
        else task->hidden = true;
    } 
}