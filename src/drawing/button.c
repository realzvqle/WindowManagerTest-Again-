#include "button.h"


extern pstate state;


ButtonState ZiDrawButton(char* text, int x, int y, int sizeX, int sizeY, Font font, Color baseColor, Color textColor, Color hoverColor, int textSize) {
    if (!textSize) {
        textSize = sizeY / 2;
    }
    Rectangle recc =  { (float)x, (float)y, (float)sizeX, (float)sizeY };
    bool isMouseOver = CheckCollisionPointRec(GetMousePosition(), recc);
    Color buttonColor = isMouseOver ? hoverColor : baseColor;

    DrawRectangle(x, y, sizeX, sizeY, buttonColor);

    int textWidth = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        textWidth += MeasureText(&text[i], textSize);
    }

    int textX = x + (sizeX - MeasureTextEx(font, text, textSize, 4).x) / 2;
    int textY = y + (sizeY - textSize) / 2;

    ZiDrawText(text, textX, textY, textSize, font, textColor);

    if (isMouseOver && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Rectangle rec =  { (float)x, (float)y, (float)sizeX, (float)sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_DOWN_LEFT;
    }

    if (isMouseOver && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        Rectangle rec =  { (float)x, (float)y, (float)sizeX, (float)sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_DOWN_RIGHT;
    }
    if (isMouseOver && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        Rectangle rec =  { (float)x, (float)y, (float)sizeX, (float)sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_CLICK_LEFT;
    }

    if (isMouseOver && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
        Rectangle rec =  { (float)x, (float)y, (float)sizeX, (float)sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_CLICK_RIGHT;
    }
    
    if (isMouseOver) {
        Rectangle rec =  { (float)x, (float)y, (float)sizeX, (float)sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_HOVER;
    }

    return BUTTON_NOT_INTERACTED;
}



void exitButton(int x, int y, int size, Font font) {
    int sizeX;
    int sizeY;
    if (!size) {
        sizeX = 30;
        sizeY = 30;
    }
    else {
        sizeX = size;
        sizeY = size;
    }
    ButtonState button = ZiDrawButton("X", x, y, sizeX, sizeY, font, GRAY, RED, DARKGRAY, NULL);
    if (button == BUTTON_CLICK_LEFT) state.isExit = true;
}

