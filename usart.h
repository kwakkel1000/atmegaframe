#include "common.h"
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU/ (USART_BAUDRATE * 16UL)) - 1)

void USART_init(void);
void USART_send(char data);
char USART_receive(void);
void USART_putstring(char* StringPtr);
