#include "common.h"
#include "usart.h"
#include <avr/io.h>
#include <string.h>

#define LED_MASK   ((1 << 7) | (1 << 6) | (1 << 5))

// main
int main(void)
{
    USART_init();
    DDRD = LED_MASK;
    char buf;
    char tmp[] = "blubjes\r\n";
    unsigned int l1 = 0;
    unsigned int l2 = 0;
    unsigned int l3 = 0;
    for (;;) {
        buf = USART_receive();
        l1++;
        l2++;
        l3++;
        if (l1 >= 20)
        {
            PORTD ^= (1 << 5);
            l1 = 0;
        }
        if (l2 >= 10)
        {
            PORTD ^= (1 << 6);
            l2 = 0;
        }
        if (l3 >= 5)
        {
            PORTD ^= (1 << 7);
            l3 = 0;
        }
        USART_putstring(tmp);
    }
    return 0;
}
