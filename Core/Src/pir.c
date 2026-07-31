#include "../Inc/pir.h"
#include "../Inc/delay.h"
#include "../Inc/GPIO.h"


PirData_t pirGetData(){

    uint32_t data = 0x0;

    GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0);

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, HIGH);

    GPIO_PinSetOutputValue(GPIOA, GPIO_PIN_5, HIGH);
    
    delayUs(120);

    GPIO_PinSetOutputValue(GPIOA, GPIO_PIN_5, LOW); // Led Off

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin

    delayUs(1); // tDL

    for(int i = 0; i < 28; i++){

        GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, HIGH); // Set Pin

        GPIO_PinSetAsInput(GPIOB, GPIO_PIN_0); // Input Mode

        delayUs(20); // tDH + tBS

        data <<= 1; 
        data |= GPIO_PinGetInputValue(GPIOB, GPIO_PIN_0); // Write Pin Value to data
        
        GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0); // Output Mode
                            
        GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin

        delayUs(1);
    }

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin
    
    delayUs(1300);

    GPIO_PinSetAsInput(GPIOB, GPIO_PIN_0); // Input Mode

    return (PirData_t){((uint16_t)(data >> 14)) & 0x3FFF, ((uint16_t)data) & 0x3FFF};
}
