#ifndef __OLED_H
#define __OLED_H

#include "main.h"

#define OLED_MODE    0

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14


#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)



#define OLED_CS     PDout(12)
#define OLED_RST    PDout(11)
#define OLED_DC     PDout(10)

#define OLED_SCK   PDout(9)
#define OLED_SDA   PDout(8)

#define OLED_CMD    0
#define OLED_DATA    1

void OLED_WR_Byte(u8 dat, u8 cmd);

void OLED_Display_On(void);

void OLED_Display_Off(void);

void OLED_Refresh_Gram(void);

void OLED_Init(void);

void OLED_Clear(void);

void OLED_DrawPoint(u8 x, u8 y, u8 t);

void OLED_Fill(u8 x1, u8 y1, u8 x2, u8 y2, u8 dot);

void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 size, u8 mode);

void OLED_ShowNum(u8 x, u8 y, u32 num, u8 len, u8 size);

void OLED_ShowString(u8 x, u8 y, const u8 *p, u8 size);

#endif
