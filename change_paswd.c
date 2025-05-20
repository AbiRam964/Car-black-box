/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include "main.h"
static int k = 0;
char paswd[5];
static int j = 0;
char Npaswd[5];
extern char opswd[5];
static unsigned long int delay1 = 0;
static unsigned long int delay2 = 0;
unsigned long int delay5 = 0;
unsigned char main_f;
unsigned char Addr = 0x00;
            
void change_pass(char key) {  //funtion for changing password

    //clcd_print("Enter new password", LINE1(1));
    if (k < 4) {
        clcd_print("Enter password", LINE1(1));
        if (++delay1 < 1000) {
            clcd_putch('_', LINE2(k + 5));
        } else if (delay1 >= 1000 && delay1 < 2000) {
            clcd_putch(' ', LINE2(k + 5));
        } else if (delay1 == 2000) {
            delay1 = 0;
        }

        //key = read_switches(STATE_CHANGE);
        if (key == MK_SW5) {
            //clcd_print("key 5 pressed", LINE2(5));
            clcd_putch('*', LINE2(k + 5));
            paswd[k++] = '5';
        } else if (key == MK_SW6) {
            clcd_putch('*', LINE2(k + 5));
            paswd[k++] = '6';
        }
    }
    if(k == 4)
    {
        k++;
        paswd[4] = '\0';
        CLEAR_DISP_SCREEN;
        key = 0xFF;
    }
  
    if (k == 5 && j < 4) {   //program to enter the password again
       // CLEAR_DISP_SCREEN;
        //if(delay5++ < 200000)
        clcd_print("Renter password", LINE1(0));
        //for (unsigned long int j = 20000; j--;);
        if (++delay2 < 1000) {
            clcd_putch('_', LINE2(j + 5));
        } else if (delay2 >= 1000 && delay2 < 2000) {
            clcd_putch(' ', LINE2(j + 5));
        } else if (delay2 == 2000) {
            delay2 = 0;
        }
        if (key == MK_SW5) {
            clcd_putch('*', LINE2(j + 5));
            Npaswd[j++] = '5';
        } else if (key == MK_SW6) {
            clcd_putch('*', LINE2(j + 5));
            Npaswd[j++] = '6';
        }
    } else if (j == 4){
        Npaswd[4] = '\0';
    }
    if (k == 5 && j == 4) {  //program to compare the two password
        if (strcmp(Npaswd, paswd) == 0) {
            clcd_print("Password changed", LINE2(0));
            for (unsigned long int j = 100000; j--;);
            //strcpy(opswd, paswd);
             eindex =9;
            for (int i = 0; i < 4; i++) {
                write_external_eeprom(Addr+i, paswd[i]);
                //Addr++;
            }
            main_f = MENU;
            k = 0;
            j = 0;
            // clcd_print("Logout", LINE2(0));
            CLEAR_DISP_SCREEN;
        } else {
            clcd_print("Paswd Not Match", LINE2(0));
            for (unsigned long int j = 100000; j--;);
            main_f = MENU;
            k = 0;
            j = 0;
            //clcd_print("Logout", LINE2(0));
            CLEAR_DISP_SCREEN;
        }
    }
    if(key == MK_SW6_L)
    {
        main_f = MENU;
        //key = 0xFF;
        k = 0;
        j = 0;
    }
}

