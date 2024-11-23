#ifndef ZIVIC_H_INCLUDED
#define ZIVIC_H_INCLUDED
#include <stdio.h>
#include "../headers/raylib.h"
#include <stdint.h>

#include "startportabledesktop.h"

#define fail(message, ...) printf("[-] " message, ##__VA_ARGS__)
#define pass(message, ...) printf("[+] " message, ##__VA_ARGS__)
#define info(message, ...) printf("[!] " message, ##__VA_ARGS__)

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