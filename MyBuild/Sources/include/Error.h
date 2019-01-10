/**************************************************************************//**
* @file      error.h
* @brief     ADC module header file.
* @details   None.
* @author    LiQingfei
* @version   1.0
* @date      2018/11/19
* @warning   None.
* @copyright 东方久乐汽车电子（上海）股份有限公司 ALL RIGHTS RESERVED.
******************************************************************************/
#ifndef _ERROR_H_
#define _ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
*                  Include
******************************************************************************/
#include "Config.h"

/******************************************************************************
*                  Global Type and Macro define
******************************************************************************/

/**< @brief  no error */
#define ERROR_NO_ERROR                          (0u)

/**< @brief  timer error base */
#define ERROR_TIMER_BASE                        (20u)
#define ERROR_TIMER_SET_PRESCALER               (0u + ERROR_TIMER_BASE)
#define ERROR_TIMER_SET_INPUT_CAPTURE           (1u + ERROR_TIMER_BASE)
#define ERROR_TIMER_SET_COMPARE_OUTPUT          (2u + ERROR_TIMER_BASE)

/******************************************************************************
*                  Global Variable and Constant declare
******************************************************************************/
extern int    g_error_code;     /**< see macros in Error.h */
extern char  *g_error_file;     /**< point to __FILE__ */
extern int    g_error_line;     /**< point to __LINE__ */

/******************************************************************************
*                  Global Function declare
******************************************************************************/




#ifdef __cplusplus
}
#endif

#endif /*_ERROR_H_*/
