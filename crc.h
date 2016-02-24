#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>

void InitCRC();
void ProcessCRC(const uint8_t *data, int len);
uint8_t GetCRC();

#endif /* __CRC_H__ */

