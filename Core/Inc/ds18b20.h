#ifndef __DS18B20_H
#define __DS18B20_H

#include <stdint.h>

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414
#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)

#define DS18B20_IO_IN()  {GPIOB->MODER&=~(3<<(12*2));GPIOB->MODER|=0<<12*2;}
#define DS18B20_IO_OUT() {GPIOB->MODER&=~(3<<(12*2));GPIOB->MODER|=1<<12*2;}

#define    DS18B20_DQ_OUT PBout(12) //	PB12
#define    DS18B20_DQ_IN  PBin(12)  //	PB12

uint8_t DS18B20_Init(void);

short DS18B20_Get_Temp(void);

void DS18B20_Start(void);

void DS18B20_Write_Byte(uint8_t dat);

uint8_t DS18B20_Read_Byte(void);

uint8_t DS18B20_Read_Bit(void);

uint8_t DS18B20_Check(void);

void DS18B20_Rst(void);

#endif
