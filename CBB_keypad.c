#include <xc.h>
#include "matrix_keypad.h"
#include "BBC_clcd.h"

void init_matrix_keypad(void) {
    /* Config PORTB as digital */
    ADCON1 = 0x0F;

    /* Set Rows (RB7 - RB5) as Outputs and Columns (RB4 - RB1) as Inputs */
    TRISB = 0x1E;

    /* Set PORTB input as pull up for columns */
    RBPU = 0;

    MATRIX_KEYPAD_PORT = MATRIX_KEYPAD_PORT | 0xE0;
}

unsigned char scan_key(void) {
    ROW1 = LO;
    ROW2 = HI;
    ROW3 = HI;

    if (COL1 == LO) {
        return 1;
    } else if (COL2 == LO) {
        return 4;
    } else if (COL3 == LO) {
        return 7;
    } else if (COL4 == LO) {
        return 10;
    }

    ROW1 = HI;
    ROW2 = LO;
    ROW3 = HI;

    if (COL1 == LO) {
        return 2;
    } else if (COL2 == LO) {
        return 5;
    } else if (COL3 == LO) {
        return 8;
    } else if (COL4 == LO) {
        return 11;
    }

    ROW1 = HI;
    ROW2 = HI;
    ROW3 = LO;
    /* TODO: Why more than 2 times? */
    ROW3 = LO;

    if (COL1 == LO) {
        return 3;
    } else if (COL2 == LO) {
        return 6;
    } else if (COL3 == LO) {
        return 9;
    } else if (COL4 == LO) {
        return 12;
    }

    return 0xFF;
}

unsigned char read_switches(unsigned char detection_type) {
    static unsigned char once = 1, key;
    static unsigned int delay_press = 0;
    static unsigned int backup_key;

    /*if (detection_type == STATE_CHANGE)
    {
    key = scan_key();
    if(key != 0xFF && once  )
    {
        once = 0;
        return key;
    }
    else if(key == 0xFF)
    {
        once = 1;
    }
    }*/
    if (detection_type == LEVEL_CHANGE) {
        key = scan_key();
        if (key != ALL_RELEASED) {
            backup_key = scan_key();
            delay_press++;
            if (delay_press > 300) {
               // delay_press = 0;
               // clcd_print("-------", LINE1(0));
                //for(unsigned long int wait = 10000;wait--;);
                // delay_press = 0; 
                return key + 10;
            }
        } else if ((delay_press > 0 && delay_press < 300) && (key == ALL_RELEASED)) {
            delay_press = 0;
            return backup_key;
        } else
            delay_press = 0;
    }
    return ALL_RELEASED;
}
