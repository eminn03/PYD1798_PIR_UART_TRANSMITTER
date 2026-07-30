#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>
#include "stm32c0xx_hal.h"


void delayInit(TIM_HandleTypeDef* htim);
void delayUs(uint32_t us);


#endif
