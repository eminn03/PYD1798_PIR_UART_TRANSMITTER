#include "../Inc/pir.h"
#include "../Inc/delay.h"
#include "../Inc/GPIO.h"


PirData_t pirGetData(){

    uint32_t data = 0x0;
    static uint32_t timer = 0;
    static bool isReady = TRUE;

    if(isReady == FALSE)
        return;

    timer =
    GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0);

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, HIGH);
    
    delayUs(120);

    GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin

    delayUs(1); // tDL

    for(int i = 0; i < 28; i++){

        GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW); // Reset Pin
        GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0); // Output Mode

        delayUs(1);

        GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, HIGH); // Set Pin
        GPIO_PinSetAsInput(GPIOB, GPIO_PIN_0); // Input Mode

        GPIO_PinSetOutputValue(GPIOA, GPIO_PIN_6, HIGH);
        delayUs(20); // tDH + tBS
        GPIO_PinSetOutputValue(GPIOA, GPIO_PIN_6, LOW);

        data <<= 1; 
        data |= GPIO_PinGetInputValue(GPIOB, GPIO_PIN_0) & 0x01; // Write Pin Value to data  
    }

    	// Stop command send (Tstop)
	GPIO_PinSetOutputValue(GPIOB, GPIO_PIN_0, LOW);		// set pin state low before the set direction output

	GPIO_PinSetAsOutput(GPIOB, GPIO_PIN_0);

	GPIO_PinSetAsInput(GPIOB, GPIO_PIN_0);	// release the pin
    
    delayUs(1300);

    return (PirData_t){((uint16_t)(data >> 14)) & 0x3FFF, ((uint16_t)data) & 0x3FFF};
}
