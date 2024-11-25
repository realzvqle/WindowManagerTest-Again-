#include "drawText.h"


extern pstate state;


void ZiDrawText(char* text, int x, int y, int size, Color color) {
	Vector2 vec = { (float)x, (float)y };
	DrawTextEx(state.font, text, vec, size, 4, color);
}