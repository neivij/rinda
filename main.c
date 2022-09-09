#include <stdint.h>
#include <stdio.h>
#include "main.h"

uint32_t x = 0;
uint8_t pressed = 0;
/*sets register value without clearing it*/
void SetRegister(uint32_t *reg, uint32_t offset, uint32_t value)
{
    reg = (uint32_t *)((uint32_t)reg + offset);
    *reg |= value;
    // printf("%x", *reg);
}

void TogglePin(uint32_t *reg, uint32_t offset, uint32_t value)
{
    reg = (uint32_t *)((uint32_t)reg + offset);
    *reg ^= value;
    // printf("%x", *reg);
}

void Delay(uint32_t time){
    for(;time>0;time--);
}
int main()
{

    /*enable RCC for GPIO A and B*/
    SetRegister(RCC_REG, RCC_AHB1ENR, GPIOAEN);
    SetRegister(RCC_REG, RCC_AHB1ENR, GPIOBEN);
    printf("%X", x);

    /*clear GPIO A and B mode registers*/
    uint32_t* gpio_a = GPIOA;
    *gpio_a |= 0xffffffff;
    *gpio_a ^= 0xffffffff;
    uint32_t *gpio_b = GPIOB;
    *gpio_b |= 0xffffffff;
    *gpio_b ^= 0xffffffff;

    /*set GPIO A1-7 and B0-1 mode as output*/
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_1_OUT);
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_2_OUT);
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_3_OUT);
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_4_OUT);
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_5_OUT);
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_6_OUT);
    SetRegister(GPIOA, GPIO_MODE, GPIO_PIN_7_OUT);
    SetRegister(GPIOB, GPIO_MODE, GPIO_PIN_0_OUT);
    SetRegister(GPIOB, GPIO_MODE, GPIO_PIN_1_OUT);

    while(1){
        if(pressed){
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_0);
            Delay(150*MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_0);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_1);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_1);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_2);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_2);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_3);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_3);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_4);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_4);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_5);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_5);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_6);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_6);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_7);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_7);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_0);
            Delay(150 * MS);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_0);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_1);
            Delay(150 * MS);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_1);
        }else{
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_1);
            Delay(150 * MS);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_1);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_0);
            Delay(150 * MS);
            TogglePin(GPIOB, GPIO_ODR, GPIO_PIN_0);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_7);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_7);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_6);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_6);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_5);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_5);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_4);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_4);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_3);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_3);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_2);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_2);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_1);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_1);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_0);
            Delay(150 * MS);
            TogglePin(GPIOA, GPIO_ODR, GPIO_PIN_0);
        }
    }
}

