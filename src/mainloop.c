#include "mainloop.h"
#include "tasks.h"



extern pstate state;

static scene StartEditor() {
	scene scene;
	scene.currentScene = 0;
	scene.init = true;
	return scene;
}


bool MainLoop() {
	if (!state.scene.init) {
		state.scene = StartEditor();
		ZiCreateTask(200, 100, "Hi!");
	}
	
	switch (state.scene.currentScene) {
		case 0:
			if(IsKeyPressed(KEY_A)) ZiCreateTask(200, 400, "Automatic WIndow");
			else if(IsKeyPressed(KEY_B)) ZiKillTask(GetRandomValue(0,ZiGetCurrentWindowValue()));
			Schedular();
			break;
		case 1:
		{
			Color tempColor = { 0, 0, 50, 255 };
			state.backgroundColor = tempColor;
			break;
		}
		default:
			state.scene.currentScene = 0;

	}
	return false;
}