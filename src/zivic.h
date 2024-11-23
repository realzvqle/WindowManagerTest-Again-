#ifndef ZIVIC_H_INCLUDED
#define ZIVIC_H_INCLUDED
#include <stdio.h>
#include "../headers/raylib.h"
#include <stdint.h>

#include "startportabledesktop.h"



typedef struct _args {
	int argc;
	char* argv[20];
} args;

typedef struct _scene {
	uint_fast8_t currentScene;
	bool init;
} scene;


typedef struct _pstate {
	raywindow mainWindow;
	Color backgroundColor;
	args arguments;
	scene scene;
	Font font;
	bool isExit;
	bool isWindowSpawned;
} pstate;


#endif