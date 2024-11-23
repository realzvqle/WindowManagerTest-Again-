#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED
#include "drawing/button.h"
#include "window/createWindow.h"


void Schedular();
void ZiCreateTask(int x, int y, int sizeX, int sizeY, char* title);



typedef struct _TASK{
    zivWindow window;
    int pid;
} TASK;

#endif