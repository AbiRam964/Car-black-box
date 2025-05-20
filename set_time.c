/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */

#include <xc.h>
#include"main.h"

extern unsigned char h=0, m=0, s=0;
int st_flag = 1;
int s_flag = 0;
char strt[17];
extern unsigned char main_f;

char strt10[17],strt20[17],strt30[17];
//unsigned long int delay10 = 0;
unsigned long int delay5 = 0;

void settime(char key)   //function to set the time
{
    if(key == MK_SW6 )   
    {
        s_flag=1;
        st_flag++;
      if(st_flag == 4)
            st_flag = 1;
    }
    clcd_putch(st_flag+48, LINE2(5));
    //while(1);
    //clcd_putch(s_flag+48, LINE2(7));
    if (++delay5 < 1000) {
        sprintf(strt," %.2d : %.2d : %.2d    ",h,m,s);
        clcd_print(strt, LINE1(1));
        } else if (delay5 < 2000) {
            if(st_flag == 3)
            {
                sprintf(strt10,"    : %.2d : %.2d ",m,s);
                clcd_print(strt10, LINE1(1));
            }
            else if(st_flag == 2)
            {
               sprintf(strt20," %.2d :    : %.2d ",h,s);
               clcd_print(strt20, LINE1(1)); 
            }
             else if(st_flag == 1)
            {
               sprintf(strt30," %.2d : %.2d :      ",h,m);
               clcd_print(strt30, LINE1(1)); 
            }
            
        } else {
            delay5 = 0;
        }
    
       if (key == 5) 
        { 
           s_flag=1;
            if (st_flag == 1)
                s++;
            else if(st_flag == 2)
                m++;
            else if(st_flag == 3)
                h++;
        }
   
        if (s > 59) {
            s = 0;
        }
        if (m > 59) {
            m = 0;
        }
        if (h > 23) {
            h = 0;
        }
    if(s_flag == 1)
    {
    if (key == MK_SW5_L) { 
        write_ds1307(HOUR_ADDR, ((h / 10) << 4) | h % 10); 
        write_ds1307(MIN_ADDR, ((m / 10) << 4) | m % 10);
        write_ds1307(SEC_ADDR, ((s / 10) << 4) | s % 10);
        s_flag=0;
        main_f=DASHBOARD;
        CLEAR_DISP_SCREEN;
       /* unsigned int delay10;
        if(delay10++ <1000)
        clcd_print("TIME SET DONE  ", LINE1(0)); */
        eindex = 11;
    }
    
        if(key == MK_SW6_L)
        {
            s_flag=0;
            key = 0xFF;
            CLEAR_DISP_SCREEN;
            main_f = DASHBOARD;
        }
    }
     
}
