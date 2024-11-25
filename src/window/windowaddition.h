#ifndef WINDOWADDITION_H_INCLUDED
#define WINDOWADDITION_H_INCLUDED
#include "createWindow.h"

#include "../task/tasks.h"


void resize(zivWindow* window, Color windowColor, Color windowColorHover);
void Exitbutton(zivWindow* window, TASK* task);
void Hidebutton(zivWindow* window, TASK* task);
#endif