#include "mainloop.h"




static scene startEditor() {
	scene scene;
	scene.currentScene = 0;
	scene.init = true;
	return scene;
}


bool mainLoop(state* state) {
	if (!state->scene.init) {
		state->scene = startEditor();
	}
	
	switch (state->scene.currentScene) {
		case 0:
			scene0(state);
			break;
		case 1:
		{
			Color tempColor = { 0, 0, 50, 255 };
			state->backgroundColor = tempColor;
			break;
		}
		default:
			state->scene.currentScene = 0;

	}
	return false;
}