#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>

bool InitI2C(int adapter_nr);
bool CloseI2C();

bool SetI2CAddr(uint8_t addr);

bool WriteReg(uint8_t reg, uint8_t value);
uint8_t ReadReg(uint8_t reg);
int32_t ReadBytesFromAddr(uint8_t reg, uint8_t* dest, uint8_t len);
bool WriteBytesToAddr(uint8_t reg, uint8_t* values, uint8_t len);

#endif /* __I2C_H__ */

