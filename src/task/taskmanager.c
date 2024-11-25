#include "taskmanager.h"
#include <stdio.h>



extern TASK tasks[512];
extern int currentwindow;
extern pstate state;

void TaskManager(){
    static float scrollOffset = 0.0f; 
    const int taskHeight = 30;       
    const int screenLimit = GetScreenHeight(); 
    const int totalHeight = currentwindow * taskHeight; 

    if (IsKeyDown(KEY_UP)) scrollOffset -= 10.0f; 
    if (IsKeyDown(KEY_DOWN)) scrollOffset += 10.0f; 
    scrollOffset -= GetMouseWheelMove() * 30.0f; 

    if (scrollOffset < 0) scrollOffset = 0;
    if (scrollOffset > totalHeight - screenLimit) 
        scrollOffset = (totalHeight > screenLimit) ? totalHeight - screenLimit : 0;


    for (int i = 0; i < currentwindow; i++) {
        if(tasks[i].running == false) continue;
        float yPosition = i * taskHeight - scrollOffset; 
        if (yPosition + taskHeight < 0 || yPosition > screenLimit) continue;
        Color color = tasks[i].hidden ? RED : GREEN;
        ZiDrawButton(tasks[i].window.title, 1, yPosition, 
                     MeasureTextEx(state.font, tasks[i].window.title, 30, 4).x + 10, 
                     taskHeight, WHITE, color, LIGHTGRAY, (int)30);
        ButtonState button = ZiDrawButton("X", MeasureTextEx(state.font, tasks[i].window.title, 30, 4).x + 10, yPosition, 
                                          30, 30, LIGHTGRAY, RED, DARKGRAY, 30);
        ButtonState sbutton = ZiDrawButton("H", MeasureTextEx(state.font, tasks[i].window.title, 30, 4).x + 40, yPosition, 
                                           30, 30, LIGHTGRAY, BLUE, DARKGRAY, 30);
        if (button == BUTTON_CLICK_LEFT) tasks[i].running = false;

        if (sbutton == BUTTON_CLICK_LEFT) {
            tasks[i].hidden = !tasks[i].hidden;
        }
    }
    ClearBackground(BLACK); 


    if (IsKeyPressed(KEY_Y)) state.scene.currentScene = 0;
}


