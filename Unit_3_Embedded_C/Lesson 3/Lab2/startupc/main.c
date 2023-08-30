/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

#include <stdint.h>

typedef volatile unsigned int vuint32_t;

#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH   *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32_t *)(GPIOA_BASE + 0x0C)

// Define GPIO pin configurations
#define LED_PIN     5 // Assuming the LED is connected to pin 5 of GPIOA

typedef union{
	vuint32_t all_fields;
	struct {
		vuint32_t reserved:13 ;
		vuint32_t p_13:1;
	} Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C) ;

// Function to initialize the LED pin as output
void LED_Init(void) {
    RCC_APB2ENR |= (1 << 2); // Enable GPIOA clock

    // Configure GPIOA pin 5 as output (push-pull mode, max speed 50 MHz)
    GPIOA_CRH &= ~(0xF << ((LED_PIN - 8) * 4)); // Clear the 4 bits for the pin
    GPIOA_CRH |= (0x3 << ((LED_PIN - 8) * 4));  // Set pin to output mode
}

int main(void) {
    LED_Init();

    while (1) {
//        GPIOA_ODR ^= (1 << LED_PIN); // Toggle LED state
        R_ODR->Pin.p_13 = 1;
    	for (volatile int i = 0; i < 10000; i++) {} // Delay loop
    	R_ODR->Pin.p_13 = 0;
    	for (volatile int i = 0; i < 10000; i++) {} // Delay loop
    }
}
