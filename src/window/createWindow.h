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
	const char* title;
} zivWindow;


void SpawnWindow(zivWindow* window, void* task, Color titleBarColor, Color titleBarColorHover, Color windowColor, Color windowColorHover, Color textColor, const char* titleBarTitle, bool isResizeable);
#endif