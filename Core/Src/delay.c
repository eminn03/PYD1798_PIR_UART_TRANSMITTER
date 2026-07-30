#include "../Inc/delay.h"


static TIM_HandleTypeDef* p_htim;


void delayInit(TIM_HandleTypeDef* htim){

    p_htim = htim;
    HAL_TIM_Base_Start(p_htim);
}

void delayUs(uint32_t us){

    __HAL_TIM_SET_COUNTER(p_htim, 0);

    while(__HAL_TIM_GET_COUNTER(p_htim) < us);
}

