#include "../task/tasks.h"
#include "../zivic.h"


TASK tasks[512];
int currentwindow = 0;

extern pstate state;

static TASKNUM ZiGetFreeTaskNumber(){
    for(int i = 0; i < currentwindow; i++){
        if(tasks[i].cleared == true){
            TASKNUM num = {i, false};
            return num;
        }   
    }
    TASKNUM num = {currentwindow, true};
    return num;
}

void Schedular() {
    for(int i = 0; i < currentwindow; i++){
        if(tasks[i].running == false){
            tasks[i].cleared = true;
            tasks[i].hidden = false;
            continue;
        } 
        if(tasks[i].hidden == true){
            continue;
        }
        SpawnWindow(&tasks[i].window, &tasks[i], DARKGRAY, DARKBLUE, WHITE, LIGHTGRAY, GREEN, tasks[i].window.title, true);
    }
    DrawFPS(10, 10);
}



void ZiCreateTask(int sizeX, int sizeY, char* title){
    TASKNUM num = ZiGetFreeTaskNumber();
    int z = num.i;
    tasks[z].window.x = GetRandomValue(0, GetScreenWidth());
    tasks[z].window.y = GetRandomValue(0, GetScreenHeight());
    tasks[z].window.sizeX = sizeX;
    tasks[z].window.sizeY = sizeY;
    tasks[z].running = true;
    tasks[z].cleared = false;
    tasks[z].window.title = title;
    tasks[z].pid = z;
    if(num.shouldadd1) currentwindow++;
    info("Created a task with PID %d, Current Window is %d\n", tasks[z].pid, currentwindow);
}

int ZiGetCurrentWindowValue(){
    return currentwindow;
}

void ZiKillTask(int pid){
    if(pid > currentwindow) return;
    tasks[pid].running = false;
}

void ZiCallTaskManager(){
    state.scene.currentScene = 2;
}

