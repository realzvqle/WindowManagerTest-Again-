#include "window.h"


static window setupWindow() {
	window window;
	window.sizeX = 1600;
	window.sizeY = 900;
	window.name = "Zivic Editor";

	return window;
}



int createWindow(state* state) {
	state->isExit = false;
	state->isWindowSpawned = false;
	state->mainWindow = setupWindow();
	state->backgroundColor = BLACK;
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(state->mainWindow.sizeX, state->mainWindow.sizeY, state->mainWindow.name);
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	state->font = LoadFontEx("resources\\fonts\\Mukta-ExtraBold.ttf", 400, NULL, 0);
	while (!WindowShouldClose() && !state->isExit) {
		if (IsKeyPressed(KEY_F)) ToggleFullscreen();
		BeginDrawing();
		ClearBackground(state->backgroundColor);
		mainLoop(state);
		EndDrawing();
	}
	UnloadFont(state->font);
	return 0;
}