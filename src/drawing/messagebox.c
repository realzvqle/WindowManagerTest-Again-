#include "messagebox.h"

#include "../task/tasks.h"
#include "button.h"
#include "drawText.h"




extern pstate state;

static const char* text;

int idk(struct _TASK task){
    ZiDrawText((const char*)task.content, task.window.x, task.window.y, 30, RED);

    return 0;
}

void ZiMessageBox(const char* text, const char* title, MESSAGETYPE type){
    TASK task = ZiCreateTask(MeasureTextEx(state.font, text, 30, 4).x + 10, MeasureTextEx(state.font, text, 30, 4).y + 40, title, idk, "Hi!");
    //task.taskfunction = idk;
}







