/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include "main.h"

void gett_time(void);
static int count = 0;
unsigned int index = 0, flag = 0;
extern char menu_f, main_f;
unsigned char h=0, m=0, s=0;
extern unsigned char clock_reg[3];
extern unsigned char time[9];
char stt[17];
char f;

//function to scroll the menuscreen
void menu(char key) {
   
    if (key == MK_SW6 && count != 4) {
        
        count++;
        if (flag == 1)
            index++;
        flag = 1;
    } else if (key == MK_SW5 && count != 0) {
        
        count--;
        if (flag == 2)
            index--;
        flag = 2;
    }
    if (count == 0 || flag == 2){
        clcd_print("->", LINE1(0));
    clcd_print("  ", LINE2(0));}
    else{
        clcd_print("->", LINE2(0));
    clcd_print("  ", LINE1(0));}
    clcd_print(menu_s[index], LINE1(2));
    clcd_print(menu_s[index + 1], LINE2(2));
   
   //CLEAR_DISP_SCREEN;

    if (key == MK_SW5_L) {
        main_f = MENU_ENTER;
//        index = 0;
//        count=0;
        //CLEAR_DISP_SCREEN;
        switch (count) {
            case 0:
                menu_f = VIEWLOG;
                CLEAR_DISP_SCREEN;
                break;
                case 1:
                   menu_f = DOWNLOADLOG;
                   CLEAR_DISP_SCREEN;
                   break;
               case 2:
                   menu_f = CLEARLOG;
                   CLEAR_DISP_SCREEN;
                   break;
               case 3:
               {
                   CLEAR_DISP_SCREEN;
//                   clcd_putch(index+48,LINE1(0));
                   //while(1);
                   /*index = 0;
                   count = 0;
                   flag = 0;
                    * */
                   menu_f = SETTIME;
                   gett_time();
                   CLEAR_DISP_SCREEN;
               }
                   break;
            case 4:
                menu_f = CHANGEPASS;
                CLEAR_DISP_SCREEN;
                break;
        }
                          // f = 0;
        index=0;
        count=0;
        flag =0;
        //CLEAR_DISP_SCREEN;
        
    }
    if(key == MK_SW6_L )    //log press to go the dashboard
    {
         CLEAR_DISP_SCREEN;
        main_f = DASHBOARD;
        
    }

}
void gett_time(void) {    //to get the RTC time
    clock_reg[0] = read_ds1307(HOUR_ADDR);
    clock_reg[1] = read_ds1307(MIN_ADDR);
    clock_reg[2] = read_ds1307(SEC_ADDR);

    if (clock_reg[0] & 0x40) {
        time[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
        time[1] = '0' + (clock_reg[0] & 0x0F);
    } else {
        time[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
        time[1] = '0' + (clock_reg[0] & 0x0F);
    }
    time[2] = ':';
    time[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
    time[4] = '0' + (clock_reg[1] & 0x0F);
    time[5] = ':';
    time[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
    time[7] = '0' + (clock_reg[2] & 0x0F);
    time[8] = '\0';
    
    h = (10 * (time[0]-48))+time[1]-48; 
    m = (10 * (time[3]-48))+time[4]-48;
    s = (10 * (time[6]-48))+time[7]-48;    
}



