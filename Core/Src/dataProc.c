#include "../Inc/dataProc.h"
#include "../Inc/dataDefinitions.h"


uint8_t* dataProcProcessData(uint8_t *rawData, uint16_t pirData){

    rawData[DATA_IDX_STRT] = DATA_STRT;
    rawData[DATA_IDX_DEV_ADDR] = DATA_DEV_ADDR;
    rawData[DATA_IDX_PIR_MS] = (uint8_t)(pirData >> 8);
    rawData[DATA_IDX_PIR_LS] = (uint8_t)pirData;
}
