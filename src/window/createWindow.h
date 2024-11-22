#pragma once
#include "../drawing/button.h"
#include "windowaddition.h"





void spawnWindow(zivWindow* window, state* state);
void spawnWindowEx(zivWindow* window, state* state, Color titleBarColor, Color titleBarColorHover, Color windowColor, Color windowColorHover, Color textColor, char* titleBarTitle, bool isResizeable);