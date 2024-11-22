#pragma once
#include "drawText.h"




typedef enum ButtonState{
    BUTTON_NOT_INTERACTED,
    BUTTON_HOVER,
    BUTTON_CLICK_LEFT,
    BUTTON_CLICK_RIGHT,
    BUTTON_DOWN_LEFT,
    BUTTON_DOWN_RIGHT
} ButtonState;



ButtonState drawButton(char* text, int x, int y, int sizeX, int sizeY, Font font, Color baseColor, Color textColor, Color hoverColor, int textSize);
void exitButton(int x, int y, int size, Font font, state* state);
