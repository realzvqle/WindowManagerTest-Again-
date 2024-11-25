#include "startportabledesktop.h"
#include "extern/lua/lauxlib.h"
#include "extern/lua/lua.h"
#include "zivic.h"
#include "mainloop.h"
#include "luaapi/luaapi.h"
#include "drawing/messagebox.h"
extern pstate state;
static raywindow SetupPortableDesktop() {
	raywindow window;
	window.sizeX = 1600;
	window.sizeY = 900;
	window.name = "Zivic Editor";

	return window;
}



int StartPortableDesktop() {
	
	state.isExit = false;
	state.isWindowSpawned = false;
	state.mainWindow = SetupPortableDesktop();
	state.backgroundColor = BLACK;
	
	state.L = luaL_newstate();
	luaL_openlibs(state.L);
	lua_register(state.L, "CreateTask", LuaCreateTask);
	lua_register(state.L, "DrawButton", LuaDrawButton);
	lua_register(state.L, "CreateColor", LuaCreateColor);
	//lua_load
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(state.mainWindow.sizeX, state.mainWindow.sizeY, state.mainWindow.name);
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	state.font = LoadFontEx("resources/fonts/Mukta-ExtraBold.ttf", 400, NULL, 0);
	while (!WindowShouldClose() && !state.isExit) {
		int result = luaL_dofile(state.L, "test.lua");
		if (result != 0) {
			const char *error_message = lua_tostring(state.L, -1); // Get error message from the stack
			fail("%s\n", error_message);

			lua_pop(state.L, 1);
		}
		if (IsKeyPressed(KEY_F)) ToggleFullscreen();
		BeginDrawing();
		ClearBackground(state.backgroundColor);
		MainLoop();
		EndDrawing();
	}
	UnloadFont(state.font);
	return 0;
}