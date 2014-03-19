#ifndef _SERIAL_H_
#define _SERIAL_H

void serial_init(int baud_rate);

void serial_putc(char c);
void serial_puts(char *str);




char serial_getc();

void serial_putint(int x);







#define BAUD_19200 129                       // brg for low-speed, 40 MHz clock
                                             // round((40000000/16/19200)-1)





#endif
