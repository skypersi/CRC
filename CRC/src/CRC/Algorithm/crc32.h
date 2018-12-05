/*
 * crc32.h
 *
 *  Created on: 2018Äê12ÔÂ5ÈÕ
 *      Author: lqf
 */

#ifndef CRC_ALGORITHM_CRC32_H_
#define CRC_ALGORITHM_CRC32_H_

#include <stdint.h>
#include "config.h"

void Crc32TableGenerator(uint32_t polynomial, uint32_t crcTable[256]);

uint32_t CalculateCRC32(const uint32_t crcTable[256],
						const uint8_t *crc_DataPtr,
						uint32_t crc_Length,
						uint32_t crc_InitialValue,
						uint32_t crc_XorValue,
						bool_t reflectedOutput,
						bool_t reflectedInput);

#endif /* CRC_ALGORITHM_CRC32_H_ */
