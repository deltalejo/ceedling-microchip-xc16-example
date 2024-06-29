#include <stdbool.h>

#include <xc.h>

#include "uart.h"

void uart_end(void);

void uart_start(void)
{
	CLKDIVbits.RCDIV = 0;
	
	U1MODEbits.BRGH = 1;
	U1BRG = 34;
	
	U1MODEbits.UARTEN = 1;
	U1STAbits.UTXEN = 1;
}

void uart_stop(void)
{
	while (!U1STAbits.TRMT);
	
	U1STAbits.UTXEN = 0;
	U1MODEbits.UARTEN = 0;
	
	uart_end();
}

void uart_end(void)
{
	while (true);
}

int uart_putchar(int c)
{
	while (!IFS0bits.U1TXIF);
	IFS0bits.U1TXIF = 0;
	U1TXREG = c;
	return c;
}
