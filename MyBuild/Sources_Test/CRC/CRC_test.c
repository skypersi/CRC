/*
 * CRC_test.c
 *
 *  Created on: 2018.11.23
 *      Author: liqingfei
 */

#include "Config.h"
#include "Sources_Test/CRC/CRC_test.h"


void TestCRC8(uint8_t calculatedCrc, uint8_t expectedCrc)
{
  if (expectedCrc != calculatedCrc)
  {
      printf("CRC8 Fault, the result is 0x%x \n", calculatedCrc);
  }
  else
  {
      printf("CRC8 Ok, the result is 0x%02x \n", calculatedCrc);
  }
}


void TestCRC16(uint16_t calculatedCrc, uint16_t expectedCrc)
{
  if (expectedCrc != calculatedCrc)
  {
      printf("CRC16 Fault, the result is 0x%x \n", calculatedCrc);
  }
  else
  {
      printf("CRC16 Ok, the result is 0x%02x \n", calculatedCrc);
  }
}


void TestCRC32(uint32_t calculatedCrc, uint32_t expectedCrc)
{
  if (expectedCrc != calculatedCrc)
  {
      printf("CR32 Fault, the result is 0x%x \n", calculatedCrc);
  }
  else
  {
      printf("CRC32 Ok, the result is 0x%02x \n", calculatedCrc);
  }
}
