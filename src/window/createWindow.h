#ifndef CREATEWINDOW_H_INCLUDED
#define CREATEWINDOW_H_INCLUDED

#pragma once
#include "../drawing/button.h"




typedef struct zivWindow {
	int x;
	int y;
	int sizeX;
	int sizeY;
	int prevSizeX;
	int prevSizeY;
	int sizeXPast;
	int sizeYPast;
	bool isDragging;
	int dragOffsetX;
	int dragOffsetY;
	double dragStopDelay;
	bool isResizing;
	int resizeOffsetX;
	int resizeOffsetY;
	int resizeButtonHeight;
	int resizeButtonGap;
	double resizeStopDelay;
	bool init;
	char* title;
} zivWindow;

void spawnWindow(zivWindow* window);
void spawnWindowEx(zivWindow* window, Color titleBarColor, Color titleBarColorHover, Color windowColor, Color windowColorHover, Color textColor, char* titleBarTitle, bool isResizeable);

#endif