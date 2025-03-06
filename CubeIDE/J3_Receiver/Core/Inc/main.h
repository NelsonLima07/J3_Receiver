/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define LED_PLACA_Pin GPIO_PIN_13
#define LED_PLACA_GPIO_Port GPIOC
#define ENT_PWR_Pin GPIO_PIN_0
#define ENT_PWR_GPIO_Port GPIOA
#define ENT_D1_Pin GPIO_PIN_1
#define ENT_D1_GPIO_Port GPIOA
#define ENT_D2_Pin GPIO_PIN_2
#define ENT_D2_GPIO_Port GPIOA
#define ENT_D3_Pin GPIO_PIN_3
#define ENT_D3_GPIO_Port GPIOA
#define BTN_INPUT_Pin GPIO_PIN_1
#define BTN_INPUT_GPIO_Port GPIOB
#define ENCODER_BTN_Pin GPIO_PIN_10
#define ENCODER_BTN_GPIO_Port GPIOA
#define ENCODER_DT_Pin GPIO_PIN_11
#define ENCODER_DT_GPIO_Port GPIOA
#define ENCODER_CLK_Pin GPIO_PIN_12
#define ENCODER_CLK_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
