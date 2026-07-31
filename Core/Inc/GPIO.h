#ifndef GPIO_H
#define GPIO_H

#include "stm32c0xx_hal.h"
#include <stdint.h>

typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef uint8_t  BOOL;

#ifndef TRUE
#define TRUE  1
#define FALSE 0
#endif
#ifndef HIGH
#define HIGH 1
#endif
#ifndef LOW
#define LOW  0
#endif

typedef enum {
    GPIO_LOW_TO_HIGH_TRANSITION = 0,
    GPIO_HIGH_TO_LOW_TRANSITION = 1
} EInterruptEdgeType;

void  GPIO_PinSetAsOutput(GPIO_TypeDef *port, uint16_t pin);
void  GPIO_PinSetAsInput(GPIO_TypeDef *port, uint16_t pin);
void  GPIO_PinSetOutputValue(GPIO_TypeDef *port, uint16_t pin, BYTE value);
BYTE  GPIO_PinGetInputValue(GPIO_TypeDef *port, uint16_t pin);
void  GPIO_InterruptEnable(GPIO_TypeDef *port, uint16_t pin);
void  GPIO_InterruptDisable(GPIO_TypeDef *port, uint16_t pin);


#endif /* GPIO_H */
