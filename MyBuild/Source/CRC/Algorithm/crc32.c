
#include <Config.h>
#include "crc32.h"
#include "reflect.h"

//This source code is helper for implementing CRC by AutoSar documentation: Specification of CRC Routines.
// https://www.autosar.org/fileadmin/files/standards/classic/

// Good page for checking your CRC:
// http://www.sunshine2k.de/coding/javascript/crc/crc_js.html

void
Crc32TableGenerator (uint32_t polynomial, uint32_t crcTable[256])
{
  uint32_t remainder;

  uint32_t topBit = 0x80000000;
  uint32_t ui32Dividend;

  for (ui32Dividend = 0; ui32Dividend < 256; ui32Dividend++)
    {
      remainder = ui32Dividend << 24;

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
       printf("0x%08xU, ", remainder);

       */

    }
}

uint32_t
CalculateCRC32 (const uint32_t crcTable[256], const uint8_t *crc_DataPtr, uint32_t crc_Length, uint32_t crc_InitialValue, uint32_t crc_XorValue, bool reflectedOutput, bool reflectedInput)
{
  uint32_t ui32Counter;
  uint8_t temp;
  uint32_t crc = crc_InitialValue;

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

      crc = (crc << 8) ^ crcTable[(uint8_t) ((crc >> 24) ^ temp)];
      crc_DataPtr++;

    }

  crc ^= crc_XorValue;
  if (reflectedOutput)
    {
      crc = reflect (crc, sizeof(uint32_t) * 8);
    }
  return crc;
}

