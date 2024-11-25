#include "mainloop.h"
#include "task/tasks.h"
#include "task/taskmanager.h"

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
			if(IsKeyPressed(KEY_A)) ZiCreateTask(300, 400, "Automatic WIndow");
			else if(IsKeyPressed(KEY_B)) ZiKillTask(GetRandomValue(0,ZiGetCurrentWindowValue()));
			if(IsKeyPressed(KEY_Y)) ZiCallTaskManager();
			Schedular();
			break;
		case 1:
		{
			Color tempColor = { 0, 0, 50, 255 };
			state.backgroundColor = tempColor;
			break;
		}
		case 2:
		{
			TaskManager();
			break;
		}
		default:
			state.scene.currentScene = 0;

	}
	return false;
}