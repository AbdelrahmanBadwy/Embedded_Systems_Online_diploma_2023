#include <uart.h>

unsigned char str[100] = "learn-in-depth : Badawy";

void main(void)
{
	Uart_Send_string(str);
	
}