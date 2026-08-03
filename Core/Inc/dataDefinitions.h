#ifndef DATA_DEFINITIONS_H
#define DATA_DEFINITIONS_H


#define BUFFER_SIZE 7

#define DATA_STRT 0x02
#define DATA_END 0x03
#define DATA_DEV_ADDR 0x10


typedef enum{

    DATA_IDX_STRT = 0,
    DATA_IDX_DEV_ADDR = 1,
    DATA_IDX_PIR_MS = 2,
    DATA_IDX_PIR_LS = 3,
    DATA_IDX_CRC_MS = 4,
    DATA_IDX_CRC_LS = 5,
    DATA_IDX_END = 6

}DataIndex_t;


#endif
