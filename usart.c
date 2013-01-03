#include "usart.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void USART_init(void)
{
    // Set baud rate //
    UBRR0H = (BAUD_PRESCALE >> 8);
    UBRR0L = BAUD_PRESCALE;
    // Enable receiver and transmitter //
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    // Set frame format: 8data, 2stop bit //
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_send(char data)
{
    // Wait for empty transmit buffer //
    while ((UCSR0A & (1<<UDRE0)) == 0) {};
    // Put data into buffer, sends the data //
    UDR0 = data;
}

char USART_receive(void)
{
    // Wait for data to be received //
    while ((UCSR0A & (1<<RXC0)) == 0) {};
    // Get and return received data from buffer //
    return UDR0;
}

void USART_putstring(char* StringPtr)
{
    while(*StringPtr != 0x00)
    {
        USART_send(*StringPtr);
        StringPtr++;
    }
}
