#include "../Inc/dispatcher.h"
#include "../Inc/uartTx.h"
#include "../Inc/pir.h"
#include "../Inc/dataDefinitions.h"
#include "../Inc/dataProc.h"
#include <stdint.h>
#include "stm32c0xx_hal.h"


static uint8_t rawData[BUFFER_SIZE];


void dispatcher(){

    static uint32_t timer = HAL_GetTick();

    if(HAL_GetTick() - timer < 300)
        return;

    timer = HAL_GetTick();


    dataProcProcessData(rawData, pirGetData().pirValue);

    uartTxTransmitText(rawData, BUFFER_SIZE);
}
