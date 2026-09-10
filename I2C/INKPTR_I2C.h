#ifndef INKPTR_I2C_H
#define INKPTR_I2C_H

#include "ch32v00x.h"

#define INKPTR_I2C_RCC_APB2Periph  (RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD)

#define INKPTR_I2C_SCL_Port        GPIOC
#define INKPTR_I2C_SCL_Pin         GPIO_Pin_0

#define INKPTR_I2C_SDA_Port        GPIOD
#define INKPTR_I2C_SDA_Pin         GPIO_Pin_0

#define INKPTR_I2C_GPIO_Speed      GPIO_Speed_50MHz

void    INKPTR_I2C_Init(void);
void    INKPTR_I2C_Start(void);
void    INKPTR_I2C_Stop(void);
void    INKPTR_I2C_SendByte(uint8_t SendByte);
uint8_t INKPTR_I2C_ReceiveACK(void);
uint8_t INKPTR_I2C_ReceiveByte(void);
void    INKPTR_I2C_SendACK(uint8_t SendACK);

#endif