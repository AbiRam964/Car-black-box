/*
 * FILE:   ABIRAM VALIYAVALAPPIL
 * BATCH : 23039F
 * ID 23036_535
 * TITLE : CAR BLACK BOX
 */


#include <xc.h>

#include "main.h"

char d_store[15];
char c_store[15];
char d_addr = 0x05;
extern int event_count;
//char i_store[3];
void download_log()  //function to download the content stored  
{
    d_addr = 0x05;
    init_uart();
    
        clcd_print("Downloading..",LINE1(0));
        for (unsigned long int j = 1000000; j--;);
        for(int j=0;j<event_count;j++)
        {
            if(j == 0)
            {
                sprintf(c_store,"           TIME     E SPD");
                puts(c_store);
                puts("\n\r");  
            }
            sprintf(d_store,"EVENT %d -> ",j+1);
            puts(d_store);
                    
            for(int k=0;k<15;k++)
            {
            d_store[k] = read_external_eeprom(d_addr+k);
            }
            d_store[15] = '\0';
            d_addr+=15;
            puts(d_store);
            puts("\n\r");          
        }
         eindex = 10;
    
   
}
