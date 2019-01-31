/*
 * crc32.h
 *
 *  Created on: 2018.12.5
 *      Author: liqingfei
 */

#ifndef _CRC32_H_
#define _CRC32_H_

#include <Config.h>

void
Crc32TableGenerator (uint32_t polynomial, uint32_t crcTable[256]);

uint32_t
CalculateCRC32 (const uint32_t crcTable[256], const uint8_t *crc_DataPtr, uint32_t crc_Length, uint32_t crc_InitialValue, uint32_t crc_XorValue, bool reflectedOutput, bool reflectedInput);

#endif /* _CRC32_H_ */
