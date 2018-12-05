/*
 * autosar_crc.h
 *
 *  Created on: 2018Äê11ÔÂ23ÈÕ
 *      Author: lqf
 */

#ifndef AUTOSAR_AUTOSAR_CRC_H_
#define AUTOSAR_AUTOSAR_CRC_H_


/* Calculate CRC Table manually
extern void Autosar_Crc_CalculateCRC8H2F_TableGenerator();
*/

extern uint8_t Autosar_Crc_CalculateCRC8H2F(const uint8_t *crc_DataPtr, uint32_t crc_Length);


#endif /* AUTOSAR_AUTOSAR_CRC_H_ */


