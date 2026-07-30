#include "../Inc/pir.h"
#include "../Inc/delay.h"


PirData_t pirGetData(){

    uint32_t data = 0x0;

    GPIOB->MODER &= ~(3U);
    GPIOB->MODER |= 1U;    // Output Mode

    GPIOB->BSRR = GPIO_PIN_0; // Set Pin
    
    delayUs(120);

    GPIOB->BRR = GPIO_PIN_0; // Reset Pin

    delayUs(1); // tDL

    for(int i = 0; i < 28; i++){

        GPIOB->BSRR = GPIO_PIN_0; // Set Pin

        GPIOB->MODER &= ~(3U); // Input Mode

        delayUs(3); // tDH + tBS

        data <<= 1; 
        data |= (GPIOB->IDR & GPIO_PIN_0); // Write Pin Value to data
        
        GPIOB->MODER &= ~(3U);
        GPIOB->MODER |= 1U; // Output Mode
                            
        GPIOB->BRR = GPIO_PIN_0; // Reset Pin

        delayUs(1);
    }

    GPIOB->BRR = GPIO_PIN_0; // Reset Pin
    
    delayUs(1300);

    GPIOB->MODER &= ~(3U); // Input Mode

    return (PirData_t){((uint16_t)(data >> 14)) & 0x3FFF, ((uint16_t)data) & 0x3FFF};
}
