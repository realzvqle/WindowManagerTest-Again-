#include "drawText.h"





void ZiDrawText(char* text, int x, int y, int size, Font font, Color color) {
	Vector2 vec = { (float)x, (float)y };
	DrawTextEx(font, text, vec, size, 4, color);
}