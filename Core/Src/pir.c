#include "../Inc/pir.h"
#include "../Inc/delay.h"


PirData_t pirGetData(){

    uint32_t data = 0x0;

    GPIOB->MODER &= ~(3U);
    GPIOB->MODER |= 1U;

    GPIOB->BSRR = GPIO_PIN_0;
    
    delayUs(120);

    GPIOB->BRR = GPIO_PIN_0;
    delayUs(1);

    for(int i = 0; i < 28; i++){

        GPIOB->BSRR = GPIO_PIN_0;
        delayUs(1);
        GPIOB->BRR = GPIO_PIN_0;

        GPIOB->MODER &= ~(3U);

        delayUs(1);

        data <<= 1;
        data |= (GPIOB->IDR & GPIO_PIN_0);
        
        GPIOB->MODER &= ~(3U);
        GPIOB->MODER |= 1U;
    }

    GPIOB->BRR = GPIO_PIN_0;
    delayUs(1300);

    return (PirData_t){((uint16_t)(data >> 14)) & 0x3FFF, ((uint16_t)data) & 0x3FFF};
}
