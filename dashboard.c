/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include "main.h"
void get_time(void);
void display_time(void);
unsigned short adc_reg = 0;
unsigned char clock_reg[3];
unsigned char time[9];
unsigned char spd[3];

unsigned char str[15];
int bcp = 0;
extern unsigned char main_f;

void dashboard(char key) {
    get_time();
    display_time();
    clcd_print("  TIME   EV  SP ", LINE1(0));
    adc_reg = read_adc(CHANNEL4);
    if (key == MK_SW1) {
        eindex = 8;
    } else if (key == MK_SW2) {
        if (eindex < 7 )
            eindex++;
        else if (eindex == 8)
            eindex = 1;
    } else if (key == MK_SW3) {
        if (eindex > 1 && eindex < 8)
            eindex--;
        else if (eindex == 8)
            eindex = 1;
    } else if (key == MK_SW5) {
        main_f = PASSWORD;
    }
    if (eindex == 2) {
        speed = adc_reg / 40.92;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    } else if (eindex == 1 || eindex == 8) {
        speed = 0;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    } else if (eindex == 3) {
        speed = adc_reg / 34.1;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    } else if (eindex == 4) {
        speed = adc_reg / 25.57;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    } else if (eindex == 5) {
        speed = adc_reg / 17.05;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    } else if (eindex == 6) {
        speed = adc_reg / 12.78;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    } else if (eindex == 7) {
        speed = adc_reg / 10.33;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12));
    }
    else if(eindex == 11)
    {
       speed = 00;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12)); 
    }
    else if(eindex == 0)
    {
       speed = 00;
        sprintf(spd, "%d", speed);
        clcd_putch(speed % 10 + '0', LINE2(13));
        clcd_putch(speed / 10 % 10 + '0', LINE2(12)); 
    }

    sprintf(str, "%s %s %s", time, event[eindex], spd);
    clcd_print(event[eindex], LINE2(9));
    if (main_f == PASSWORD)
        CLEAR_DISP_SCREEN;
    return;
}

void get_time(void) {
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
}

void display_time(void) {
    clcd_print(time, LINE2(0));
}


