/*
 * led_driver.c
 *
 *  Created on: Jan 23, 2024
 *      Author: atzml
 */
#include "stm32f4xx_hal.h"

//BUTTON -->  GPIOC - 13. pin
//LED --> GPIOA - 5. pin

void Led_init(void){
	RCC->AHB1ENR |= (1<<0);// LED BUS

	// LED
	  GPIOA->MODER |= (1<<10);
	  GPIOA->MODER &= ~(1<<11);

	  GPIOA->OSPEEDR |= (1<<10);
	  GPIOA->OSPEEDR &= ~(1<<11);

	  GPIOA->OTYPER &= ~(1<<5);

}

void Led_ON(void){
	GPIOA->ODR |= (1<<5);
}

void Led_OFF(void){
	GPIOA->ODR &= ~(1<<5);
}

