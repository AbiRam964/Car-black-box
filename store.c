/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>
#include"main.h"
unsigned char Address = 0x05;
//unsigned char addr = 0x00;
char addr1 = 0x05;
int event_count = 0;
int count1 = 0;
unsigned char str3[15];
char read;

void store_event(char *str1) {   //function to store the event
    if (event_count < 10) {
        for (int i = 0; i < 15; i++) {
            write_external_eeprom(Address, str1[i]);
            Address++;
        }
        event_count++;
        /*CLEAR_DISP_SCREEN;
         for (int i = 0; i <= 14; i++) {
                 str3[i] = read_external_eeprom(addr1);
                 addr1++;
             }
             str3[15] = '\0';
             clcd_print(str3, LINE1(0));
             for(unsigned long int j = 500000;j--;);
         */

    } else {
        Address = 0x05;
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0  ; j < 15 ; j++)
            {
                read = read_external_eeprom(Address + 15 + j);
            
                write_external_eeprom(Address + j, read);
            }
            Address = Address + 15;
            
        }
        for(int j = 0  ; j < 15 ; j++)
        {
           write_external_eeprom(Address+j, str1[j]); 
        }
        /*while (count1 < 9) {

            for (int i = 0; i <= 14; i++) {
                str1[i] = read_external_eeprom(Address + 15);
                Address++;
            }
            //str1[15] = '\0';
            for (int i = 0; i < 15; i++) {
                write_external_eeprom(addr, str1[i]);
                addr++;
            }

            count1++;
        }
        for (int i = 0; i < 15; i++) {
            write_external_eeprom(0x87, str1[i]);
            addr++;
        }
        count1 = 0;*/
        
    }
    return;
    
}

