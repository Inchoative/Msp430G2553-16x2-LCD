#include <msp430.h> 
#include "lcd.h"
#include <stdlib.h>

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	lcd_init(); // calling lcd function
   int x=10;

   cursor_off;
    send_line(1,3); //first row and 3 space - 16bits

    send_string("Lcd  Write");

    send_line(2,6);  // second row and 6 space - 16 bits
    send_string("TEST");

    delay(100);


    lcd_clear;

    send_line(1,0);
    send_string("Count ");
               send_int(x);
               send_string(" back");

    for(x;x>=0;x--)
    {
    send_line(2,7);
    send_int(x);
    delay(10);
    send_line(2,7);
    send_string("  ");
    delay(1);   //delay for refreshing lcd
    }

}
