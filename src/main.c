#include "window/window.h"





int main(int argc, char* argv[]) {
	state state;
	state.arguments.argc = argc;
	for (int i = 0; i < argc; i++) {
		state.arguments.argv[i] = argv[i];
	}
	return createWindow(&state);
}