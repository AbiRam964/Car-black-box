/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */

#include <xc.h>
#include "main.h"
/*#include"BBC_clcd.h"
#include"matrix_keypad.h"
#include "timer0.h"
#include<string.h>*/

static int i = 0, try = 3;
    unsigned long int delay = 0;
unsigned char main_f;
//char opswd[] = "5555";
char opswd[5];
char pswd[5];
extern unsigned int sec;
static unsigned int count;
unsigned char ptr = 0x00;
int flag3=0, j = 0;

//extern char key;

void password(char key) {
    
    if (try != 0) {

        clcd_print("Enter password", LINE1(1));
        if (i < 4) {
            if (++delay < 1000) {
                clcd_putch('_', LINE2(i + 5));
            } else if (delay >= 1000 && delay < 2000) {
                clcd_putch(' ', LINE2(i + 5));
            } else if (delay == 2000) {
                delay = 0;
            }

            //key = read_switches(STATE_CHANGE);
            if (key == MK_SW5) {
                clcd_putch('*', LINE2(i + 5));
                opswd[i] = read_external_eeprom(ptr++);

                pswd[i++] = '5';
            } else if (key == MK_SW6) {
                clcd_putch('*', LINE2(i + 5));
                opswd[i] = read_external_eeprom(ptr++);

                pswd[i++] = '6';
            }
        } else if (i == 4){
            ptr = 0x00;
            opswd[4] = '\0';
            pswd[4] = '\0';
            
            if (strcmp(opswd, pswd) == 0) {
                clcd_print(opswd,LINE2(10));
                //while(1);
                clcd_print("Password Match", LINE2(0));
                for (unsigned long int j = 1000000; j--;);
                i=0;
                main_f = MENU;
                CLEAR_DISP_SCREEN;
            } else
            {
                i = 0;
                 clcd_print(opswd,LINE2(10));
                 
                clcd_print("Invalid Password", LINE2(0));
                try--;
                for (unsigned long int j = 1000000; j--;);
                CLEAR_DISP_SCREEN;
               
                clcd_putch((48+try), LINE1(5));
                clcd_print(" Attempts left ", LINE2(0));
                for (unsigned long int j = 1000000; j--;);
                //while(1);
                CLEAR_DISP_SCREEN;
                if (try == 0) {
                    init_timer0();
                }
            }
        }
    } else {

        clcd_print("USER BLOCK!", LINE1(2));
        clcd_print("Seconds left", LINE2(0));
        clcd_putch((sec % 10) + 48, LINE2(15));
        clcd_putch(((sec / 10)) + 48, LINE2(14));
        if (sec == 0) {
            try = 3;
            count = 0;
            sec = 60;
            main_f = PASSWORD;
            TMR0ON = 0;
            CLEAR_DISP_SCREEN;
        }
    }
}
