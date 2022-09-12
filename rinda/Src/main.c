#include "stdint.h"
#include <stdint.h>
#include "main.h"
#include <stm32f4xx.h>

volatile uint8_t pressed = 0;

/*estimated delay (time shouldn' t exceed 32bit max value)*/
void Delay(volatile uint32_t time)
{
    for (; time > 0; time--);
}
/*interrupt handler*/
void EXTI0_IRQHandler(void) {
	pressed ^= 1;
	Delay((uint32_t)MS/2);	//for button debouncing
}
int main()
{

    /*enable RCC for GPIO A and B*/
    RCC->AHB1ENR |= GPIOAEN;
    RCC->AHB1ENR |= GPIOBEN;

    /*clear GPIO A and B mode registers*/
    uint32_t *reg = (uint32_t *)0x40020400;
    *reg |= 0xffffffff;
    *reg ^= 0xffffffff;
    reg = (uint32_t *)0x40020000;
    *reg |= 0xffffffff;
    *reg ^= 0xffffffff;

    /*set GPIO A1-7 and B0-1 mode as output*/
    GPIOA->MODER |= GPIO_PIN_1_OUT;
    GPIOA->MODER |= GPIO_PIN_2_OUT;
    GPIOA->MODER |= GPIO_PIN_3_OUT;
    GPIOA->MODER |= GPIO_PIN_4_OUT;
    GPIOA->MODER |= GPIO_PIN_5_OUT;
    GPIOA->MODER |= GPIO_PIN_6_OUT;
    GPIOA->MODER |= GPIO_PIN_7_OUT;
    GPIOB->MODER |= GPIO_PIN_0_OUT;
    GPIOB->MODER |= GPIO_PIN_1_OUT;

    /*set user button(PA 0) as input*/
    GPIOB->MODER |= GPIO_PIN_0_IN;
    /*enable SYSCFG clock*/
    RCC->APB2ENR |= SYSCFG_EN;
    /*set PA0 as source input for EXTI0) */
    reg = (uint32_t *)((uint32_t)0x40013800 + SYSCFG_EXTICR1);
    *reg |= 0xf;
    *reg ^= 0xf; // first 4 LSB set to 0000

    /*enable rising edge trigger for exti0*/
    EXTI->RTSR |= RT0;
    /*set exti0 as not masked*/
    EXTI->IMR |= EXTI0_NOTMASKED;

    /*set interrupt priority to highest and enable the Interrupt */
    NVIC_SetPriority(EXTI0_IRQn, 0);
    NVIC_EnableIRQ(EXTI0_IRQn);

    while (1)
    {
    	/*running LED lane code*/
        if (pressed)
        {
            GPIOA->ODR ^= GPIO_PIN_1;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_1;
            GPIOA->ODR ^= GPIO_PIN_2;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_2;
            GPIOA->ODR ^= GPIO_PIN_3;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_3;
            GPIOA->ODR ^= GPIO_PIN_4;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_4;
            GPIOA->ODR ^= GPIO_PIN_5;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_5;
            GPIOA->ODR ^= GPIO_PIN_6;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_6;
            GPIOA->ODR ^= GPIO_PIN_7;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_7;
            GPIOB->ODR ^= GPIO_PIN_0;
            Delay(150 * MS);
            GPIOB->ODR ^= GPIO_PIN_0;
            GPIOB->ODR ^= GPIO_PIN_1;
            Delay(150 * MS);
            GPIOB->ODR ^= GPIO_PIN_1;
        }
        else
        {
            GPIOB->ODR ^= GPIO_PIN_1;
            Delay(150 * MS);
            GPIOB->ODR ^= GPIO_PIN_1;
            GPIOB->ODR ^= GPIO_PIN_0;
            Delay(150 * MS);
            GPIOB->ODR ^= GPIO_PIN_0;
            GPIOA->ODR ^= GPIO_PIN_7;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_7;
            GPIOA->ODR ^= GPIO_PIN_6;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_6;
            GPIOA->ODR ^= GPIO_PIN_5;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_5;
            GPIOA->ODR ^= GPIO_PIN_4;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_4;
            GPIOA->ODR ^= GPIO_PIN_3;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_3;
            GPIOA->ODR ^= GPIO_PIN_2;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_2;
            GPIOA->ODR ^= GPIO_PIN_1;
            Delay(150 * MS);
            GPIOA->ODR ^= GPIO_PIN_1;
        }
    }
}
