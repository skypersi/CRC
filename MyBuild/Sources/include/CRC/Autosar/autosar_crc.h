/*
 * autosar_crc.h
 *
 *  Created on: 2018.11.23
 *      Author: liqingfei
 */

#ifndef _AUTOSAR_CRC_H_
#define _AUTOSAR_CRC_H_

#include "Config.h"

// Calculate CRC Table manually
void
Autosar_Crc_CalculateCRC8H2F_TableGenerator();

uint8_t
Autosar_Crc_CalculateCRC8H2F (const uint8_t *crc_DataPtr, uint32_t crc_Length);

#endif /*AUTOSAR_CRC_H_ */

