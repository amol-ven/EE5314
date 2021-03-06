/*
 * File:   newmainXC16.c
 * Author: amol
 *
 * Created on March 16, 2014, 3:52 PM
 */


#include <p33FJ128MC802.h>
#include "config.h"
#include "inc/serial/serial.h"
#include "inc/string_utilities/string_utilities.h"

extern void _delay_ms(unsigned int);

extern char * buffer;
extern char * element;

void init_hw(void)
{
    LATBbits.LATB4 = 0;
    TRISBbits.TRISB4 = 0;

    RPINR18bits.U1RXR = 11;                    // assign U1RX to RP11
    RPOR5bits.RP10R = 3;                       // assign U1TX to RP10
}

void pll_config()
{
    PLLFBD = 38;
    CLKDIV = 0x3000;
}

void startup_flash(void)
{
     LATBbits.LATB4 = 1;
     _delay_ms(500);
     LATBbits.LATB4 = 0;
}

int main(void)
{
    pll_config();
    init_hw();
    startup_flash();
    serial_init(BAUD_19200);

    int buffer_index=0;
    int command_rcvd=0;
    int element_present = -1;

    while(1)
    {

        buffer[buffer_index] = serial_getc();
        serial_putc(buffer[buffer_index]);
        if(buffer[buffer_index] == '\b')                 //check for backspace character
        {
            serial_putc(' ');
            serial_putc('\b');
            buffer_index-=2;
            if(buffer_index < 0)
            {
                buffer_index = -1;
            }
        }
        if(buffer[buffer_index] == '\r')             //check for enter key pressed
        {
            buffer[buffer_index] = '\0';
            command_rcvd = 1;
        }

        if(command_rcvd == 1)
        {
            replace_non_alphanumeric(buffer, BUFF_LENGTH, '\0');

            serial_puts("\n\rCommand Received: ");
            serial_puts(buffer);
            serial_puts("\n\r");
            element_present = getElement(buffer, element, RESET);
            if(element_present == 0)
            {
                serial_puts("\n\rELEMENT1: ");
                serial_puts(element);
                serial_puts("\n\r");

            }
            element_present = getElement(buffer, element, NEXT);
            if(element_present == 0)
            {
                serial_puts("\n\rELEMENT2: ");
                serial_puts(element);
                serial_puts("\n\r");
            }


            while(buffer_index>=0)          //erase current command
            {
                buffer[buffer_index--]='\0';
            }
            command_rcvd = 0;
            buffer_index = -1;
        }


        buffer_index++;
        if(buffer_index >= BUFF_LENGTH)
        {
            buffer_index = BUFF_LENGTH-1;
        }

    }

    return 0;
}