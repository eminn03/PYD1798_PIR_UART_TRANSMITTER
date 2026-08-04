#include "../Inc/dispatcher.h"
#include "../Inc/uartTx.h"
#include "../Inc/pir.h"
#include "../Inc/dataDefinitions.h"
#include "../Inc/dataProc.h"
#include <stdint.h>
#include "stm32c0xx_hal.h"


static const uint16_t delay = 15;
static uint8_t rawData[BUFFER_SIZE];


void dispatcher(){

    static uint32_t timer = 0;

    if(HAL_GetTick() - timer < delay)
        return;

    timer = HAL_GetTick();


    dataProcProcessData(rawData, pirGetData().pirValue);

    uartTxTransmitText(rawData, BUFFER_SIZE);
}
