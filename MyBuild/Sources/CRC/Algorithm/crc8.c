
#include "Config.h"
#include "CRC/Algorithm/crc8.h"
#include "CRC/Algorithm/reflect.h"

//This source code is helper for implementing CRC by AutoSar documentation: Specification of CRC Routines.
// https://www.autosar.org/fileadmin/files/standards/classic/

// Good page for checking your CRC:
// http://www.sunshine2k.de/coding/javascript/crc/crc_js.html

void
Crc8TableGenerator (uint8_t polynomial, uint8_t crcTable[256])
{
  uint8_t remainder;

  uint8_t topBit = 0x80;
  uint32_t ui32Dividend;

  for (ui32Dividend = 0; ui32Dividend < 256; ui32Dividend++)
    {
      remainder = ui32Dividend;

      for (uint8_t bit = 0; bit < 8; bit++)
        {
          if (0 == (remainder & topBit))
            {
              remainder <<= 1;
            }
          else
            {
              remainder = (remainder << 1) ^ polynomial;
            }
        }

      crcTable[ui32Dividend] = remainder;

      //remove comments if you want print CRC 256 lookup table 
      /*
       if (0 == ui32Dividend % 16)
       {
       printf("\n");
       }
       printf("0x%02xU, ", remainder);
       */
    }
}

uint8_t
CalculateCRC8 (const uint8_t crcTable[256], const uint8_t *crc_DataPtr, uint32_t crc_Length, uint8_t crc_InitialValue, uint8_t crc_XorValue, bool reflectedOutput, bool reflectedInput)
{
  uint32_t ui32Counter;
  uint8_t temp;
  uint8_t crc = crc_InitialValue;

  for (ui32Counter = 0U; ui32Counter < crc_Length; ui32Counter++)
    {
      if (reflectedInput)
        {
          temp = (uint8_t) reflect (*crc_DataPtr, 8);
        }
      else
        {
          temp = *crc_DataPtr;
        }

      crc = crc ^ temp;
      crc = crcTable[crc];
      crc_DataPtr++;
    }

  crc ^= crc_XorValue;
  if (reflectedOutput)
    {
      crc = (uint8_t) reflect (crc, 8);
    }
  return crc;
}

