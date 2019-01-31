/*
 * crc16.h
 *
 *  Created on: 2018.12.5
 *      Author: liqingfei
 */

#ifndef _CRC16_H_
#define _CRC16_H_

#include <Config.h>

void
Crc16TableGenerator (uint16_t polynomial, uint16_t crcTable[256]);

uint16_t
CalculateCRC16 (const uint16_t crcTable[256], const uint8_t *crc_DataPtr, uint32_t crc_Length, uint16_t crc_InitialValue, uint16_t crc_XorValue, bool reflectedOutput, bool reflectedInput);

#endif /* _CRC16_H_ */
