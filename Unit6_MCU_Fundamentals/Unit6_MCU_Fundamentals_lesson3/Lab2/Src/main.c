/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define RCC_BASE 0x40021000
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR *(volatile uint32_t *)(RCC_BASE + 0x00)

void clockInit(){

		// PLL selected as system clock
		RCC_CFGR |=(0b10<<0);
		// HCLK divided by 4 for APB2
		RCC_CFGR |=(0b101<<11);
		// HCLK divided by 2 for APB1
		RCC_CFGR |=(0b100<<8);
		// PLL input clock x8
		RCC_CFGR |=(0b0110<<18);
		// PLL enable
		RCC_CR |= (1<<24);
}
int main(void) {
	clockInit();

	while (1) {

	}
}

