#include "../Inc/uartTx.h"
#include "../Inc/dataDefinitions.h"
#include "stm32c0xx_hal.h"
#include <string.h>


static UART_HandleTypeDef* p_huart;
static uint8_t txBuff[BUFFER_SIZE];


void uartTxInit(UART_HandleTypeDef* huart){

    p_huart = huart;
}

void uartTxTransmitText(uint8_t *text, uint16_t len){

    memcpy(txBuff, text, len);
    HAL_UART_Transmit_IT(p_huart, txBuff, len);
}

