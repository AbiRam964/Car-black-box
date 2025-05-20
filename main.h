#ifndef MAIN_H
#define MAIN_H

/* Inclusion of header files */
#include <xc.h> 

#include "CBB_adc.h"
#include "BBC_clcd.h"
#include "eeprom.h"
#include "matrix_keypad.h"
#include "ds1307.h"
#include "i2c.h"
#include "timer0.h"
//#include "uart.h"
#include<string.h>
#include<stdio.h>



#define DASHBOARD               0
#define PASSWORD                1
#define MENU                    2
#define MENU_ENTER              3
#define VIEWLOG                 0
#define DOWNLOADLOG             1
#define CLEARLOG                2
#define SETTIME                 3
#define CHANGEPASS              4

void dashboard(char key);
void store_event(); /* Pass required parameters */
void password(char key);
void menu(char key);
void view_log(char key);
void download_log();
void clear_log(char key);
void settime(char key);
void change_pass(char key);
char *event[] = {"ON", "GN", "GR", "G1", "G2", "G3", "G4", "G5", "C ","CP","DL","ST","CL"};
int eindex = 0;
int speed;
void init_ds1307(void);
static unsigned char menu_s[][17] = { "view log      ","download log  ","clear log     ","set time      ","change_ passwd"};
void store_event(char *str1);
void init_uart(void);
//void display_menu(void);



#endif