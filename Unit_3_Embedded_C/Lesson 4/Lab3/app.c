
/* 
 *******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman_ElBadawy
 ******************************************************************************
 */

// Comment: This code seems to configure and control an LED connected to Port F, Pin 3 on a microcontroller.

// Comment: Include the necessary header file for fixed-size integer types.
#include <stdint.h>

// Comment: Define a volatile unsigned integer type.
typedef volatile unsigned long vuint32_t;

// Comment: Define the memory-mapped registers for controlling GPIO Port F.
#define SYSCTL_RCG2_R     (*((vuint32_t*)0x400FE108))
#define GPIO_PORTF_DIR_R  (*((vuint32_t*)0x40025400))
#define GPIO_PORTF_DEN_R  (*((vuint32_t*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((vuint32_t*)0x400253FC))

int main(void)
{
    vuint32_t delay_count;
    
    // Comment: Enable clock for GPIO Port F using the SYSCTL_RCG2_R register.
    SYSCTL_RCG2_R = 0x20;
    
    // Comment: Delay loop to ensure that GPIO Port F is up and running.
    for (delay_count = 0; delay_count < 200000; delay_count++);
    
    // Comment: Set Pin 3 of Port F as an output by configuring the GPIO_PORTF_DIR_R register.
    GPIO_PORTF_DIR_R |= 1 << 3;
    
    // Comment: Enable digital functionality for Pin 3 of Port F by configuring the GPIO_PORTF_DEN_R register.
    GPIO_PORTF_DEN_R |= 1 << 3;
    
    while(1)
    {
        // Comment: Turn on the LED connected to Pin 3 of Port F.
        GPIO_PORTF_DATA_R |= 1 << 3;
        
        // Comment: Delay loop to keep the LED on for a while.
        for (delay_count = 0; delay_count < 200000; delay_count++);
        
        // Comment: Turn off the LED connected to Pin 3 of Port F.
        GPIO_PORTF_DATA_R &= ~(1 << 3);
        
        // Comment: Delay loop to keep the LED off for a while.
        for (delay_count = 0; delay_count < 200000; delay_count++);
    }
    
    return 0;
}
