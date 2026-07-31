#include "../Inc/pir.h"
#include "../Inc/delay.h"
#include "../Inc/GPIO.h"
#include <stdbool.h>


PirData_t pirGetData(){

    uint16_t data[2] = {0, 0};
    uint16_t tempData = 0;
    bool result = false;
    GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0);

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, HIGH);
    
    delayUs(120);

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin

    delayUs(1); // tDL
    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < 14; i++){

        GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin
        GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0); // Output Mode

        delayUs(1);

        GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, HIGH); // Set Pin
        GPIO_PinSetAsInput(GPIOB, GPIO_PIN_0); // Input Mode

        delayUs(20); // tDH + tBS

        tempData <<= 1; 
        result = GPIO_PinGetInputValue(GPIOB, GPIO_PIN_0) & 0x01; // Write Pin Value to data  

        if(result)
            tempData |= 0x01;
    }
        data[j] = tempData;
        tempData = 0;
    }

    	// Stop command send (Tstop)
	GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW);		// set pin state low before the set direction output

	GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0);

	GPIO_PinSetAsInput(GPIOB, GPIO_PIN_0);	// release the pin
    
    delayUs(2000);

    return (PirData_t){((uint16_t)(data[0])), ((uint16_t)data[1])};
}
