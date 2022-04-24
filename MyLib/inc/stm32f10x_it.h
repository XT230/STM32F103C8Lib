/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.h 
  * @author  MCD Application Team
  * @version V3.6.0
  * @date    20-September-2021
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2011 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_IT_H
#define __STM32F10x_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "tools.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
	
//   #define START_USART1
//   #define START_USART2
	// #define START_TIM4
	// #define START_TIM3
	// #define START_EXTI1
	// #define START_EXTI9_5

/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#ifdef START_TIM4
void TIM4_IRQHandler(void);
#endif

#ifdef START_TIM3
void TIM3_IRQHandler(void);
#endif

#ifdef START_EXTI1
void EXTI1_IRQHandler();
#endif

#ifdef START_EXTI9_5
void EXTI9_5_IRQHandler();
#endif

#ifdef START_USART1
void USART1_IRQHandler(void);
#endif

#ifdef START_USART2
void USART2_IRQHandler(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_IT_H */

