#include <xc.h>
#include "main.h"
unsigned int count = 0;
unsigned int sec = 60;
void __interrupt() isr(void) {


    if (TMR0IF) {
        
        TMR0 = TMR0 + 8;
        if (count++ == 20000) {
            sec--;
            count = 0;

        }

        TMR0IF = 0;
    }
}

