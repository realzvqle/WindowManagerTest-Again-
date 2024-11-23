#include "mainloop.h"
#include "tasks.h"



extern pstate state;

static scene startEditor() {
	scene scene;
	scene.currentScene = 0;
	scene.init = true;
	return scene;
}


bool mainLoop() {
	if (!state.scene.init) {
		state.scene = startEditor();
		ZiCreateTask(30, 30, 200, 100, "Hi!");
	}
	
	switch (state.scene.currentScene) {
		case 0:
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