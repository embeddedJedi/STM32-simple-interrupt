/*
 * button_driver.c
 *
 *  Created on: Jan 23, 2024
 *      Author: atzml
 */
#include "stm32f4xx_hal.h"

//BUTTON -->  GPIOC - 13. pin
//LED --> GPIOA - 5. pin

void Button_init(void){
	  RCC->AHB1ENR |= (1<<2);// BUTTON BUS

	  // BUTTON
	  GPIOC->MODER &= ~(1<<27);
	  GPIOC->MODER &= ~(1<<26);

	  GPIOC->OSPEEDR |= (1<<27);
	  GPIOC->OSPEEDR &= ~(1<<26);

	  GPIOC->OTYPER &= ~(1<<13);
}

int Button_state(){
	if (!(GPIOC->IDR & (1 << 13))) {
	    return 1;

	} else {
	    return 0;

	}

}

void button_INTERRUP_init()
{
	// Enable GPIOC Clock
	__HAL_RCC_GPIOC_CLK_ENABLE(); // RCC->AHB1ENR |= (1<<2);

	// Enable SYSCFG Clock (EXTI için)
	__HAL_RCC_SYSCFG_CLK_ENABLE();

    // Moder: Input
    GPIOC->MODER   &= ~((3UL << 26));  // Reset  26 ve 27 bit

    // Pull-up pull-down
    GPIOC->PUPDR   &= ~((3UL << 26));  // Reset  26 ve 27 bit

    //  EXTI_13 ==> GPIOC
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC; // 	SYSCFG->EXTICR[3] |= 0x20;

    // EXTI13 Interrupt unmask (diğer bitleri maskelemez)
    EXTI->IMR |= EXTI_IMR_IM13; // EXTI->IMR |= (1<<13);

    // EXTI13 Interrupt falling edge
    EXTI->FTSR |= EXTI_FTSR_TR13; // EXTI->FTSR |= (1<<13);

    // NVIC in EXTI4_14 Priority set
    NVIC_SetPriority(EXTI15_10_IRQn, 1);

    // NVIC in EXTI4_15 Interruptunu aktif et
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR13) {
        EXTI->PR |= EXTI_PR_PR13; // Biti sıfırla
        GPIOA->ODR ^= (1 << 5); // LED'i tersine çevir
    }
}

