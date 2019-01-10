/*
 * MyTypedef.h
 *
 *  Created on: 2019年1月10日
 *      Author: lqf
 */

#ifndef _MYTYPEDEF_H_
#define _MYTYPEDEF_H_

#ifdef _BUILD_IN_ECLIPSE_

  #include <stdio.h>
  #include <stdint.h>
  // defined in  _H_HIDEF_
  //---------------------------
  #define HALT                  {} //{__asm CLRB; __asm SWI;}
  #define HALTX(x)              {} //{/*lint -e522 */ __asm LDAB x; __asm SWI; /*lint +e522 */}
  #define HALT_AND_QUIT         {} //HALTX(#32)
  #define EnableInterrupts      {} //{__asm CLI;}
  #define DisableInterrupts     {} //{__asm SEI;}

  // defined in  _H_STDTYPES_
  //---------------------------
  typedef  void (*PROC)(void);

  typedef  uint8_t      Byte;
  typedef  int8_t      sByte;
  typedef  uint16_t     Word;
  typedef  int16_t     sWord;
  typedef  uint32_t     LWord;
  typedef  int32_t     sLWord;

  typedef  uint8_t     uchar;
  typedef  int8_t      schar;
  typedef  uint16_t    uint;
  typedef  int16_t     sint;
  typedef  uint32_t    ulong;
  typedef  int32_t     slong;

  typedef int   bool;
  typedef bool  Bool;

  #ifndef TRUE
  #define TRUE  1u
  #endif
  #ifndef FALSE
  #define FALSE 0u
  #endif

  // defined in _H_STDDEF_
  //---------------------------
  typedef unsigned int   size_t;
  typedef signed   int   ptrdiff_t;
  typedef unsigned int   clock_t;

  #define offsetof(type, member) ((size_t) &(((type *) 0)->member))
  #define NULL           ((void *)0)

  //my define
  //---------------------------
  #define EnterCritical()       {}
  #define ExitCritical()        {}

  typedef  uint8_t     U08;
  typedef  int8_t      S08;
  typedef  uint16_t    U16;
  typedef  int16_t     S16;
  typedef  uint32_t    U32;
  typedef  int32_t     S32;

#else
  #include "hidef.h"
  #include "derivative.h"

  typedef unsigned char   uint8_t;
  typedef unsigned int    uint16_t;
  typedef unsigned long   uint32_t;
  typedef signed   char   int8_t;
  typedef signed   int    int16_t;
  typedef signed   long   int32_t;

  typedef  uint8_t     U08;
  typedef  int8_t      S08;
  typedef  uint16_t    U16;
  typedef  int16_t     S16;
  typedef  uint32_t    U32;
  typedef  int32_t     S32;

  typedef int  bool;

  #define EnterCritical()       { __asm tpa;__asm staa CCRSave;__asm sei; }
  #define ExitCritical()        { __asm ldaa CCRSave;__asm tap; }
#endif //_ECLIPSE_BUILD_



/******************************************************************************
*                  Global Type and Macro define
******************************************************************************/
#define BIT(x) (1u << x)

/******************************************************************************
*                  Global Variable and Constant declare
******************************************************************************/


/******************************************************************************
*                  Global Function declare
******************************************************************************/

#endif /* _MYTYPEDEF_H_ */
