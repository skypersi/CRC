/**************************************************************************//**
* @file      Config.h
* @brief     Configure header file.
* @details   None.
* @author    LiQingfei
* @version   1.0
* @date      2018/11/19
* @warning   None.
* @copyright 东方久乐汽车电子（上海）股份有限公司 ALL RIGHTS RESERVED.
******************************************************************************/
#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************
**                 Includes
**********************************************************/
#include "MyTypedef.h"
#include <mc9s12g128.h>
#include "Error.h"

/******************************************************************************
*                  Global Type and Macro define
******************************************************************************/
#define DEBUG TRUE
#define ERROR TRUE

#if(ERROR == TRUE)
    #define Run(fun)             \
    {                            \
        fun;                     \
        if(g_error_code)         \
        {                        \
            while(g_error_code); \
        }                        \
    }
#else
    #define Run(fun) {fun;}
#endif /* ERROR */

/******************************************************************************
*                  Global Variable and Constant declare
******************************************************************************/



/******************************************************************************
*                  Global Function declare
******************************************************************************/
void Delay1Us(void);
void Delay10Us(void);
void Delay100Us(void);
void DelayMs( S16 ms );



#ifdef __cplusplus
}
#endif

#endif //_CONFIG_H_
