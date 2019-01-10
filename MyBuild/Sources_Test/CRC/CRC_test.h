/*
 * CRC_test.h
 *
 *  Created on: 2018.11.23
 *      Author: liqingfei
 */

#ifndef CRC_TEST_H_
#define CRC_TEST_H_

#include "Config.h"

void TestCRC8(uint8_t calculatedCrc, uint8_t expectedCrc);
void TestCRC16(uint16_t calculatedCrc, uint16_t expectedCrc);
void TestCRC32(uint32_t calculatedCrc, uint32_t expectedCrc);

#endif /* CRC_TEST_H_ */
