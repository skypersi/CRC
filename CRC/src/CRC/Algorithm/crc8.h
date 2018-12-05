/*
 * crc8.h
 *
 *  Created on: 2018Äê12ÔÂ5ÈÕ
 *      Author: lqf
 */

#ifndef CRC_ALGORITHM_CRC8_H_
#define CRC_ALGORITHM_CRC8_H_

#include <stdint.h>
#include "config.h"

void Crc8TableGenerator(uint8_t polynomial, uint8_t crcTable[256]);

uint8_t CalculateCRC8(const uint8_t crcTable[256],
					  const uint8_t *crc_DataPtr,
					  	  	uint32_t crc_Length,
							uint8_t crc_InitialValue,
							uint8_t crc_XorValue,
							bool_t reflectedOutput,
							bool_t reflectedInput);

#endif /* CRC_ALGORITHM_CRC8_H_ */
