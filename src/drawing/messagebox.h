#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED









#include "../zivic.h"


typedef enum _MESSAGETYPE{
    MESSAGE_ID_OK,
    MESSAGE_ID_YESNO
} MESSAGETYPE;

void ZiMessageBox(const char* text, const char* title, MESSAGETYPE type);



#endif