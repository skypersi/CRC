
#include "Config.h"
#include "CRC/Algorithm/crc8.h"
#include "CRC/Algorithm/crc16.h"
#include "CRC/Algorithm/crc32.h"
#include "CRC/Autosar/autosar_crc.h"

#include "CRC/CRC_test.h"


#define  DEBUG_ALGORITHM	0
#define  DEBUG_AUTOSAR    1


int main()
{
    uint8_t message1[] = { 0x00, 0x00, 0x00, 0x00 };
    uint8_t message2[] = { 0xF2, 0x01, 0x83 };
    uint8_t message3[] = { 0x0F, 0xAA, 0x00, 0x55 };
    uint8_t message4[] = { 0x00, 0xFF, 0x55, 0x11 };
    uint8_t message5[] = { 0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0XFF };
    uint8_t message6[] = { 0x92, 0x6B, 0x55 };
    uint8_t message7[] = { 0xFF, 0xFF, 0xFF, 0xFF };

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

#if(DEBUG_AUTOSAR)

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

    return 0;
}