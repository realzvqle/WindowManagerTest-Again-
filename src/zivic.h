#pragma once
#include <stdio.h>
#include "../headers/raylib.h"
#include <stdint.h>



typedef struct window {
	int sizeX;
	int sizeY;
	char* name;
} window;

typedef struct args {
	int argc;
	char* argv[20];
} args;

typedef struct currentScene {
	uint_fast8_t currentScene;
	bool init;
} scene;


typedef struct state {
	window mainWindow;
	Color backgroundColor;
	args arguments;
	scene scene;
	Font font;
	bool isExit;
	bool isWindowSpawned;
} state;

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
} zivWindow;