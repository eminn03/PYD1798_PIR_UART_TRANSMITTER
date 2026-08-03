#ifndef PIR_H
#define PIR_H

#include <stdint.h>
#include "stm32c0xx.h"


typedef struct{

    uint16_t pirValue;
    uint16_t tempValue;

}PirData_t;


void pirInit();
PirData_t pirGetData();


#endif
