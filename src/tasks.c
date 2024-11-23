#include "tasks.h"
#include "zivic.h"


TASK tasks[512];
int currentwindow = 0;

extern pstate state;



void Schedular() {
    for(int i = 0; i < currentwindow; i++){
        spawnWindowEx(&tasks[i].window, DARKGRAY, DARKBLUE, WHITE, LIGHTGRAY, GREEN, tasks[i].window.title, true);
    }
    DrawFPS(10, 10);
}



void ZiCreateTask(int x, int y, int sizeX, int sizeY, char* title){
    tasks[currentwindow].window.x = GetRandomValue(0, GetScreenWidth());
    tasks[currentwindow].window.y = GetRandomValue(0, GetScreenHeight());
    tasks[currentwindow].window.sizeX = sizeX;
    tasks[currentwindow].window.sizeY = sizeY;
    tasks[currentwindow].window.init = true;
    tasks[currentwindow].window.title = title;
    tasks[currentwindow].pid = currentwindow;
    currentwindow++;
}