#ifndef UART_TX_H
#define UART_TX_H

#include <stdint.h>


typedef struct __UART_HandleTypeDef UART_HandleTypeDef;


void uartTxInit(UART_HandleTypeDef* huart);
void uartTxTransmitText(uint8_t* text, uint16_t len);


#endif
