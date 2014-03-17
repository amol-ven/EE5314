#include <p33FJ128MC802.h>



void serial_init(int baud_rate)
{
  U1BRG = baud_rate;              // set baud rate
  U1MODE = 0x8000;                // enable uarts, 8N1, low speed brg
  U1STA = 0x0400;                 // enable tx and rx
}

void serial_putc(char c)
{
    while(U1STAbits.UTXBF);
    U1TXREG = c;
}

void serial_puts(char *str)
{
  while(*str)
  {
      serial_putc(*(str++));
  }
}

char serial_getc()
{
  // clear out any overflow error condition
  if(U1STAbits.OERR == 1)
  {
    U1STAbits.OERR = 0;
  }
  while(!U1STAbits.URXDA);         // wait until character is ready
  return U1RXREG;
}
