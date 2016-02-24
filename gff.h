#ifndef __GFF_H__
#define __GFF_H__

#include <stdint.h>

uint32_t ComputeGffDecodedSize(uint8_t* data_ptr, uint32_t data_len);
bool DecodeGff(uint8_t* data_ptr, uint32_t data_len, uint8_t* dest);

#endif /* __GFF_H__ */

