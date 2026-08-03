#ifndef UART_TX_H
#define UART_TX_H

#include <stdint.h>
#include "stm32c0xx_hal.h"


void uartTxInit(UART_HandleTypeDef* huart);
void uartTxTransmitText(uint8_t* text, uint16_t len);


#endif
