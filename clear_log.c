/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include"main.h"
extern unsigned char main_f = 0;
extern int event_count = 0;
void clear_log(char key)
{
   
    event_count = 0;
    int c =0;
    if(c++ < 1000)
    {
        clcd_print("LOG CLEARED", LINE1(1));
         eindex = 12;
    }
    if(key == MK_SW6_L )
    {
        main_f = MENU;
        CLEAR_DISP_SCREEN;
    }    
    return;
}
