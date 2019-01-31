/*
 * crc8.h
 *
 *  Created on: 2018.12.5
 *      Author: liqingfei
 */

#ifndef _CRC8_H_
#define _CRC8_H_

#include <Config.h>

void
Crc8TableGenerator (uint8_t polynomial, uint8_t crcTable[256]);

uint8_t
CalculateCRC8 (const uint8_t crcTable[256], const uint8_t *crc_DataPtr, uint32_t crc_Length, uint8_t crc_InitialValue, uint8_t crc_XorValue, bool reflectedOutput, bool reflectedInput);

#endif /* _CRC8_H_ */
