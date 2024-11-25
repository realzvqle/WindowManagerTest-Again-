#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED
#include "../drawing/button.h"
#include "../window/createWindow.h"




typedef struct _TASK{
    zivWindow window;
    int pid;
    bool running;
    bool cleared;
    bool hidden;
    int (*taskfunction)(struct _TASK); 
    void* content;
} TASK;


typedef struct _TASKNUM{
    int i;
    bool shouldadd1;
} TASKNUM;

void Schedular();
int ZiGetCurrentWindowValue();
void ZiKillTask(int pid);
void ZiCallTaskManager();
TASK ZiCreateTask(int sizeX, int sizeY, const char* title, int (*taskfunction)(struct _TASK), void* content);

#endif