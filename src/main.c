#include "startportabledesktop.h"
#include "zivic.h"

pstate state;


int main(int argc, char* argv[]) {
	printf("Hi!");
	state.arguments.argc = argc;
	for (int i = 0; i < argc; i++) {
		state.arguments.argv[i] = argv[i];
	}
	return StartPortableDesktop();
}