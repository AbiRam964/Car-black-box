/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include "main.h"

extern unsigned char time[9];
unsigned char main_f = 0, menu_f = 0, key,bckp;
extern unsigned char str[15];
unsigned char spd[3];

void init_config(void) {
    /* Initial configurations */
    init_adc();
    init_clcd();
    init_matrix_keypad();
    init_i2c();
    init_ds1307();

    PEIE = 1;
    ADCON1 = 0x0F;
    GIE = 1;
    for(int i=0;i<4;i++)
    {
        write_external_eeprom(0x00+i,'5');
    }
            
    /* Updating password in EEPROM */
    
}

void main(void) {
    //main_f = MENU;
    init_config();
sprintf(str,"00:00:00 ON 00");
        store_event(str);
    while (1) {
        /*
         * get the time 
         * based on switch press change the event
         */ 
        bckp = eindex;
        /* Reading key */
        key = read_switches(LEVEL_CHANGE);
        if (main_f == DASHBOARD) {
            dashboard(key);
            /*if (key == MK_SW5) {
                main_f = 1;
            }*/
        } else if (main_f == PASSWORD) {
            password(key);
        } else if (main_f == MENU) {
            menu(key);
        } else if (main_f == MENU_ENTER) {
            if (menu_f == VIEWLOG) {
                
                view_log(key);
            } else if (menu_f == DOWNLOADLOG) {
                download_log();
                main_f=2;
            } else if (menu_f == CLEARLOG) {
                 
               clear_log(key);
            } else if (menu_f == SETTIME) {
                settime(key);
            } else if (menu_f == CHANGEPASS) {
                change_pass(key);
            }
        }
        if(bckp != eindex )
        {
                sprintf(str, "%s %s %s", time, event[eindex], spd);
          store_event(str);  
        }
    }
    return;
}
