/***************************************************************************************************
 * filename     : GPIO.c
 * description  :
 * author       : �lhan �ZG�R
 * copyright    : EAE
 * datetime     :
 *
 * Version History:  +,-,/,*: add, remove, change, fix
 *  v1.0:   First release.
 *
 *
 **************************************************************************************************/

/***************************************************************************************************
 * DECLARATIONS
 **************************************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Includes */
#include "GPIO.h"
#include "stm32c0xx_hal.h"

static inline uint32_t pin_pos(uint16_t pin)
{
    uint32_t pos = 0U;
    uint32_t p   = (uint32_t)pin;
    while ((p & 0x1U) == 0U) { p >>= 1U; pos++; }
    return pos;
}

void GPIO_PinSetAsOutput(GPIO_TypeDef *port, uint16_t pin)
{
    uint32_t pos  = pin_pos(pin);
    uint32_t mask = 0x3UL << (pos * 2U);
    uint32_t val  = 0x1UL << (pos * 2U);   /* MODER = 01 → output */
    port->MODER   = (port->MODER & ~mask) | val;
}

void GPIO_PinSetAsInput(GPIO_TypeDef *port, uint16_t pin)
{
    uint32_t pos  = pin_pos(pin);
    uint32_t mask = 0x3UL << (pos * 2U);
    port->MODER  &= ~mask;                  /* MODER = 00 → input  */
}

void GPIO_PinSetOutputValue(GPIO_TypeDef *port, uint16_t pin, BYTE value)
{
    if (value) port->BSRR = (uint32_t)pin;
    else       port->BRR  = (uint32_t)pin;
}

BYTE GPIO_PinGetInputValue(GPIO_TypeDef *port, uint16_t pin)
{
    return (port->IDR & (uint32_t)pin) ? TRUE : FALSE;
}

void GPIO_InterruptEnable(GPIO_TypeDef *port, uint16_t pin)
{
    __HAL_GPIO_EXTI_CLEAR_IT(pin);
    HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
}

void GPIO_InterruptDisable(GPIO_TypeDef *port, uint16_t pin)
{
    HAL_NVIC_DisableIRQ(EXTI0_1_IRQn);
}

