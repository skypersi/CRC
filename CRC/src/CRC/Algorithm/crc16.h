/*
 * crc16.h
 *
 *  Created on: 2018Äê12ÔÂ5ÈÕ
 *      Author: lqf
 */

#ifndef CRC_ALGORITHM_CRC16_H_
#define CRC_ALGORITHM_CRC16_H_

#include <stdint.h>
#include "config.h"

void Crc16TableGenerator(uint16_t polynomial, uint16_t crcTable[256]);

uint16_t CalculateCRC16(const uint16_t crcTable[256],
						const uint8_t *crc_DataPtr,
						uint32_t crc_Length,
						uint16_t crc_InitialValue,
						uint16_t crc_XorValue,
						bool_t reflectedOutput,
						bool_t reflectedInput);

#endif /* CRC_ALGORITHM_CRC16_H_ */
