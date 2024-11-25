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
} TASK;


typedef struct _TASKNUM{
    int i;
    bool shouldadd1;
} TASKNUM;

void Schedular();
void ZiCreateTask(int sizeX, int sizeY, char* title);
int ZiGetCurrentWindowValue();
void ZiKillTask(int pid);
void ZiCallTaskManager();


// Lua Wrapper Functiosn
int LuaCreateTask(lua_State *L);
#endif