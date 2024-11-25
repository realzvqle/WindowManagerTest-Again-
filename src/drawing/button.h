#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "drawText.h"




typedef enum ButtonState{
    BUTTON_NOT_INTERACTED,
    BUTTON_HOVER,
    BUTTON_CLICK_LEFT,
    BUTTON_CLICK_RIGHT,
    BUTTON_DOWN_LEFT,
    BUTTON_DOWN_RIGHT
} ButtonState;



ButtonState ZiDrawButton(const char* text, int x, int y, int sizeX, int sizeY, Color baseColor, Color textColor, Color hoverColor, int textSize) ;

#endif