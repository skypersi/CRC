/*
 * CRC_test.c
 *
 *  Created on: 2018.11.23
 *      Author: liqingfei
 */

#include <Autosar_CRC.h>
#include <Config.h>
#include "CRC_test.h"


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


uint8_t message1[] = { 0x00, 0x00, 0x00, 0x00 };
uint8_t message2[] = { 0xF2, 0x01, 0x83 };
uint8_t message3[] = { 0x0F, 0xAA, 0x00, 0x55 };
uint8_t message4[] = { 0x00, 0xFF, 0x55, 0x11 };
uint8_t message5[] = { 0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0XFF };
uint8_t message6[] = { 0x92, 0x6B, 0x55 };
uint8_t message7[] = { 0xFF, 0xFF, 0xFF, 0xFF };


#define DEBUG_AUTOSAR TRUE


void CRC_test(void)
{
  #if(DEBUG_ALGORITHM)
  uint8_t crcTable8bit[256];
  uint16_t crcTable16bit[256];
  uint32_t crcTable32bit[256];

  uint8_t polynominal8bit;
  uint8_t initValue;
  uint8_t xorValue;

  #if(0)
  //CRC8 (SAE-J1850)  Specification of CRC Routines page 22
  polynominal8bit = 0x1D;
  initValue = 0xFF;
  xorValue = 0xFF;
  Crc8TableGenerator(polynominal8bit, crcTable8bit);

  TestCRC8(CalculateCRC8(crcTable8bit, message1, sizeof(message1), initValue, xorValue, FALSE, FALSE), 0x59);
  TestCRC8(CalculateCRC8(crcTable8bit, message2, sizeof(message2), initValue, xorValue, FALSE, FALSE), 0x37);
  TestCRC8(CalculateCRC8(crcTable8bit, message3, sizeof(message3), initValue, xorValue, FALSE, FALSE), 0x79);
  TestCRC8(CalculateCRC8(crcTable8bit, message4, sizeof(message4), initValue, xorValue, FALSE, FALSE), 0xB8);
  TestCRC8(CalculateCRC8(crcTable8bit, message5, sizeof(message5), initValue, xorValue, FALSE, FALSE), 0xCB);
  TestCRC8(CalculateCRC8(crcTable8bit, message6, sizeof(message6), initValue, xorValue, FALSE, FALSE), 0x8C);
  TestCRC8(CalculateCRC8(crcTable8bit, message7, sizeof(message7), initValue, xorValue, FALSE, FALSE), 0x74);
  #endif

  #if(0)
  //CRC8H2F           Specification of CRC Routines page 23
  polynominal8bit = 0x2F;
  initValue = 0xFF;
  xorValue = 0xFF;
  Crc8TableGenerator(polynominal8bit, crcTable8bit);

  TestCRC8(CalculateCRC8(crcTable8bit, message1, sizeof(message1), initValue, xorValue, FALSE, FALSE), 0x12);
  TestCRC8(CalculateCRC8(crcTable8bit, message2, sizeof(message2), initValue, xorValue, FALSE, FALSE), 0xC2);
  TestCRC8(CalculateCRC8(crcTable8bit, message3, sizeof(message3), initValue, xorValue, FALSE, FALSE), 0xC6);
  TestCRC8(CalculateCRC8(crcTable8bit, message4, sizeof(message4), initValue, xorValue, FALSE, FALSE), 0x77);
  TestCRC8(CalculateCRC8(crcTable8bit, message5, sizeof(message5), initValue, xorValue, FALSE, FALSE), 0x11);
  TestCRC8(CalculateCRC8(crcTable8bit, message6, sizeof(message6), initValue, xorValue, FALSE, FALSE), 0x33);
  TestCRC8(CalculateCRC8(crcTable8bit, message7, sizeof(message7), initValue, xorValue, FALSE, FALSE), 0x6C);
  #endif

  #if(0)
  //CCITT-FALSE CRC16 Specification of CRC Routines page 23
  uint16_t polynominal16bit = 0x1021;
  uint16_t initValue16bit = 0xFFFF;
  uint16_t xorValue16bit = 0x0000;
  Crc16TableGenerator(polynominal16bit, crcTable16bit);

  TestCRC16(CalculateCRC16(crcTable16bit, message1, sizeof(message1), initValue16bit, xorValue16bit, FALSE, FALSE), 0x84C0);
  TestCRC16(CalculateCRC16(crcTable16bit, message2, sizeof(message2), initValue16bit, xorValue16bit, FALSE, FALSE), 0xD374);
  TestCRC16(CalculateCRC16(crcTable16bit, message3, sizeof(message3), initValue16bit, xorValue16bit, FALSE, FALSE), 0x2023);
  TestCRC16(CalculateCRC16(crcTable16bit, message4, sizeof(message4), initValue16bit, xorValue16bit, FALSE, FALSE), 0xB8F9);
  TestCRC16(CalculateCRC16(crcTable16bit, message5, sizeof(message5), initValue16bit, xorValue16bit, FALSE, FALSE), 0xF53F);
  TestCRC16(CalculateCRC16(crcTable16bit, message6, sizeof(message6), initValue16bit, xorValue16bit, FALSE, FALSE), 0x0745);
  TestCRC16(CalculateCRC16(crcTable16bit, message7, sizeof(message7), initValue16bit, xorValue16bit, FALSE, FALSE), 0x1D0F);
  #endif

  #if(0)
  //Ethernet CRC Calculation - CRC32
  uint32_t polynominal32bit = 0x04C11DB7;
  uint32_t initValue32bit = 0xFFFFFFFF;
  uint32_t xorValue32bit = 0xFFFFFFFF;
  Crc32TableGenerator(polynominal32bit, crcTable32bit);

  TestCRC32(CalculateCRC32(crcTable32bit, message1, sizeof(message1), initValue32bit, xorValue32bit, TRUE, TRUE), 0x2144DF1C);
  TestCRC32(CalculateCRC32(crcTable32bit, message2, sizeof(message2), initValue32bit, xorValue32bit, TRUE, TRUE), 0x24AB9D77);
  TestCRC32(CalculateCRC32(crcTable32bit, message3, sizeof(message3), initValue32bit, xorValue32bit, TRUE, TRUE), 0xB6C9B287);
  TestCRC32(CalculateCRC32(crcTable32bit, message4, sizeof(message4), initValue32bit, xorValue32bit, TRUE, TRUE), 0x32A06212);
  TestCRC32(CalculateCRC32(crcTable32bit, message5, sizeof(message5), initValue32bit, xorValue32bit, TRUE, TRUE), 0xB0AE863D);
  TestCRC32(CalculateCRC32(crcTable32bit, message6, sizeof(message6), initValue32bit, xorValue32bit, TRUE, TRUE), 0x9CDEA29B);
  TestCRC32(CalculateCRC32(crcTable32bit, message7, sizeof(message7), initValue32bit, xorValue32bit, TRUE, TRUE), 0xFFFFFFFF);
  #endif
  #endif /*DEBUG_ALGORITHM*/

  #if(DEBUG_AUTOSAR == TRUE)

  //Autosar_Crc_CalculateCRC8H2F_TableGenerator();

  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message1, sizeof(message1)), 0x12);
  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message2, sizeof(message2)), 0xC2);
  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message3, sizeof(message3)), 0xC6);
  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message4, sizeof(message4)), 0x77);
  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message5, sizeof(message5)), 0x11);
  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message6, sizeof(message6)), 0x33);
  TestCRC8(Autosar_Crc_CalculateCRC8H2F(message7, sizeof(message7)), 0x6C);

  uint8_t data[] = { 0x00, 0x10 };

  TestCRC8(Autosar_Crc_CalculateCRC8H2F(data, sizeof(data)), 0xE9);

  #endif /*DEBUG_AUTOSAR*/
}
