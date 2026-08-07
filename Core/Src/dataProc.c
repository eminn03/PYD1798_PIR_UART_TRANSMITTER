#include "../Inc/dataProc.h"
#include "../Inc/dataDefinitions.h"
#include "../Inc/crc.h"


void dataProcProcessData(uint8_t *rawData, uint16_t pirData){

    rawData[DATA_IDX_STRT] = DATA_STRT;
    rawData[DATA_IDX_LEN] = DATA_LEN;
    rawData[DATA_IDX_DEV_ADDR] = DATA_DEV_ADDR;
    rawData[DATA_IDX_PIR_MS] = (uint8_t)(pirData >> 8);
    rawData[DATA_IDX_PIR_LS] = (uint8_t)pirData;

    uint16_t crc = CCITT_16(rawData, DATA_LEN - 3);

    rawData[DATA_IDX_CRC_MS] = (uint8_t)(crc >> 8);
    rawData[DATA_IDX_CRC_LS] = (uint8_t)crc;
    rawData[DATA_IDX_END] = DATA_END;
}
