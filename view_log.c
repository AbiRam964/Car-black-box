/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include"main.h"
char addr = 0x05;
char str5[17];
extern int event_count;
extern unsigned char main_f = 0;

void view_log(char key) {    // function for showing the contens stored
   
    static int e_count =0;

    if (event_count != 0) {
    clcd_print("VIEW LOG", LINE1(0));


        if (key == MK_SW6 && e_count < event_count-1) {
            addr = addr + 15;
            e_count++;
        } else if (key == MK_SW5 && e_count > 0) {
            addr = addr - 15;
            e_count--;
        }
        for (int i = 0; i < 15; i++) {
            str5[i] = read_external_eeprom(addr+i);
        }
        str5[14] = '\0';
        clcd_putch(e_count + 48,LINE2(0));
        clcd_print(str5, LINE2(2));

    } 
    else 
    {
        clcd_print(" -NO LOG-", LINE1(0));
    }
    if(key == MK_SW6_L )
    {
         CLEAR_DISP_SCREEN;
        main_f = MENU;
       // key = 0xFF;
    }

    return;
}
