/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCU_LED_Pin GPIO_PIN_13
#define MCU_LED_GPIO_Port GPIOC
#define ERROR_LED_Pin GPIO_PIN_9
#define ERROR_LED_GPIO_Port GPIOI
#define NORMAL_LED_Pin GPIO_PIN_10
#define NORMAL_LED_GPIO_Port GPIOI
#define TEST_LED_Pin GPIO_PIN_11
#define TEST_LED_GPIO_Port GPIOI
#define BTN_10_Pin GPIO_PIN_6
#define BTN_10_GPIO_Port GPIOF
#define BTN_10_EXTI_IRQn EXTI9_5_IRQn
#define BTN_14_Pin GPIO_PIN_7
#define BTN_14_GPIO_Port GPIOF
#define BTN_14_EXTI_IRQn EXTI9_5_IRQn
#define BTN_16_Pin GPIO_PIN_8
#define BTN_16_GPIO_Port GPIOF
#define BTN_16_EXTI_IRQn EXTI9_5_IRQn
#define BTN_20_Pin GPIO_PIN_9
#define BTN_20_GPIO_Port GPIOF
#define BTN_20_EXTI_IRQn EXTI9_5_IRQn
#define BTN_26_Pin GPIO_PIN_10
#define BTN_26_GPIO_Port GPIOF
#define BTN_26_EXTI_IRQn EXTI15_10_IRQn
#define BTN_40_Pin GPIO_PIN_0
#define BTN_40_GPIO_Port GPIOC
#define BTN_40_EXTI_IRQn EXTI0_IRQn
#define IN_40_Pin GPIO_PIN_3
#define IN_40_GPIO_Port GPIOC
#define IN_39_Pin GPIO_PIN_1
#define IN_39_GPIO_Port GPIOA
#define IN_38_Pin GPIO_PIN_2
#define IN_38_GPIO_Port GPIOA
#define IN_37_Pin GPIO_PIN_2
#define IN_37_GPIO_Port GPIOH
#define IN_36_Pin GPIO_PIN_3
#define IN_36_GPIO_Port GPIOH
#define IN_35_Pin GPIO_PIN_4
#define IN_35_GPIO_Port GPIOH
#define IN_34_Pin GPIO_PIN_5
#define IN_34_GPIO_Port GPIOH
#define IN_33_Pin GPIO_PIN_3
#define IN_33_GPIO_Port GPIOA
#define IN_32_Pin GPIO_PIN_4
#define IN_32_GPIO_Port GPIOA
#define IN_31_Pin GPIO_PIN_5
#define IN_31_GPIO_Port GPIOA
#define IN_30_Pin GPIO_PIN_6
#define IN_30_GPIO_Port GPIOA
#define IN_29_Pin GPIO_PIN_7
#define IN_29_GPIO_Port GPIOA
#define IN_28_Pin GPIO_PIN_4
#define IN_28_GPIO_Port GPIOC
#define IN_27_Pin GPIO_PIN_5
#define IN_27_GPIO_Port GPIOC
#define IN_26_Pin GPIO_PIN_0
#define IN_26_GPIO_Port GPIOB
#define IN_25_Pin GPIO_PIN_1
#define IN_25_GPIO_Port GPIOB
#define IN_24_Pin GPIO_PIN_11
#define IN_24_GPIO_Port GPIOF
#define IN_23_Pin GPIO_PIN_12
#define IN_23_GPIO_Port GPIOF
#define IN_22_Pin GPIO_PIN_13
#define IN_22_GPIO_Port GPIOF
#define IN_21_Pin GPIO_PIN_14
#define IN_21_GPIO_Port GPIOF
#define IN_20_Pin GPIO_PIN_15
#define IN_20_GPIO_Port GPIOF
#define IN_19_Pin GPIO_PIN_0
#define IN_19_GPIO_Port GPIOG
#define IN_18_Pin GPIO_PIN_1
#define IN_18_GPIO_Port GPIOG
#define IN_17_Pin GPIO_PIN_7
#define IN_17_GPIO_Port GPIOE
#define IN_16_Pin GPIO_PIN_8
#define IN_16_GPIO_Port GPIOE
#define IN_15_Pin GPIO_PIN_9
#define IN_15_GPIO_Port GPIOE
#define IN_14_Pin GPIO_PIN_10
#define IN_14_GPIO_Port GPIOE
#define IN_13_Pin GPIO_PIN_11
#define IN_13_GPIO_Port GPIOE
#define IN_12_Pin GPIO_PIN_12
#define IN_12_GPIO_Port GPIOE
#define IN_11_Pin GPIO_PIN_13
#define IN_11_GPIO_Port GPIOE
#define IN_10_Pin GPIO_PIN_14
#define IN_10_GPIO_Port GPIOE
#define IN_9_Pin GPIO_PIN_15
#define IN_9_GPIO_Port GPIOE
#define IN_8_Pin GPIO_PIN_10
#define IN_8_GPIO_Port GPIOB
#define IN_7_Pin GPIO_PIN_11
#define IN_7_GPIO_Port GPIOB
#define IN_6_Pin GPIO_PIN_6
#define IN_6_GPIO_Port GPIOH
#define IN_5_Pin GPIO_PIN_7
#define IN_5_GPIO_Port GPIOH
#define IN_4_Pin GPIO_PIN_8
#define IN_4_GPIO_Port GPIOH
#define IN_3_Pin GPIO_PIN_9
#define IN_3_GPIO_Port GPIOH
#define IN_2_Pin GPIO_PIN_10
#define IN_2_GPIO_Port GPIOH
#define IN_1_Pin GPIO_PIN_11
#define IN_1_GPIO_Port GPIOH
#define OUT_1_Pin GPIO_PIN_12
#define OUT_1_GPIO_Port GPIOH
#define OUT_2_Pin GPIO_PIN_12
#define OUT_2_GPIO_Port GPIOB
#define OUT_3_Pin GPIO_PIN_13
#define OUT_3_GPIO_Port GPIOB
#define OUT_4_Pin GPIO_PIN_14
#define OUT_4_GPIO_Port GPIOB
#define OUT_5_Pin GPIO_PIN_15
#define OUT_5_GPIO_Port GPIOB
#define OUT_6_Pin GPIO_PIN_8
#define OUT_6_GPIO_Port GPIOD
#define OUT_7_Pin GPIO_PIN_9
#define OUT_7_GPIO_Port GPIOD
#define OUT_8_Pin GPIO_PIN_10
#define OUT_8_GPIO_Port GPIOD
#define OUT_9_Pin GPIO_PIN_11
#define OUT_9_GPIO_Port GPIOD
#define OUT_10_Pin GPIO_PIN_12
#define OUT_10_GPIO_Port GPIOD
#define OUT_11_Pin GPIO_PIN_13
#define OUT_11_GPIO_Port GPIOD
#define OUT_12_Pin GPIO_PIN_14
#define OUT_12_GPIO_Port GPIOD
#define OUT_13_Pin GPIO_PIN_15
#define OUT_13_GPIO_Port GPIOD
#define OUT_14_Pin GPIO_PIN_2
#define OUT_14_GPIO_Port GPIOG
#define OUT_15_Pin GPIO_PIN_3
#define OUT_15_GPIO_Port GPIOG
#define OUT_16_Pin GPIO_PIN_4
#define OUT_16_GPIO_Port GPIOG
#define OUT_17_Pin GPIO_PIN_5
#define OUT_17_GPIO_Port GPIOG
#define OUT_18_Pin GPIO_PIN_6
#define OUT_18_GPIO_Port GPIOG
#define OUT_19_Pin GPIO_PIN_7
#define OUT_19_GPIO_Port GPIOG
#define OUT_20_Pin GPIO_PIN_8
#define OUT_20_GPIO_Port GPIOG
#define OUT_21_Pin GPIO_PIN_6
#define OUT_21_GPIO_Port GPIOC
#define OUT_22_Pin GPIO_PIN_7
#define OUT_22_GPIO_Port GPIOC
#define OUT_23_Pin GPIO_PIN_8
#define OUT_23_GPIO_Port GPIOC
#define OUT_24_Pin GPIO_PIN_9
#define OUT_24_GPIO_Port GPIOC
#define OUT_25_Pin GPIO_PIN_8
#define OUT_25_GPIO_Port GPIOA
#define OUT_26_Pin GPIO_PIN_9
#define OUT_26_GPIO_Port GPIOA
#define OUT_27_Pin GPIO_PIN_10
#define OUT_27_GPIO_Port GPIOA
#define OUT_28_Pin GPIO_PIN_11
#define OUT_28_GPIO_Port GPIOA
#define OUT_29_Pin GPIO_PIN_12
#define OUT_29_GPIO_Port GPIOA
#define OUT_30_Pin GPIO_PIN_13
#define OUT_30_GPIO_Port GPIOH
#define OUT_31_Pin GPIO_PIN_14
#define OUT_31_GPIO_Port GPIOH
#define OUT_32_Pin GPIO_PIN_15
#define OUT_32_GPIO_Port GPIOH
#define OUT_33_Pin GPIO_PIN_0
#define OUT_33_GPIO_Port GPIOI
#define OUT_34_Pin GPIO_PIN_1
#define OUT_34_GPIO_Port GPIOI
#define OUT_35_Pin GPIO_PIN_2
#define OUT_35_GPIO_Port GPIOI
#define OUT_36_Pin GPIO_PIN_3
#define OUT_36_GPIO_Port GPIOI
#define OUT_37_Pin GPIO_PIN_10
#define OUT_37_GPIO_Port GPIOC
#define OUT_38_Pin GPIO_PIN_11
#define OUT_38_GPIO_Port GPIOC
#define OUT_39_Pin GPIO_PIN_12
#define OUT_39_GPIO_Port GPIOC
#define OUT_40_Pin GPIO_PIN_0
#define OUT_40_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
