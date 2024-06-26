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
#include "stm32f1xx_hal.h"

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
#define BUTTON_1_Pin GPIO_PIN_13
#define BUTTON_1_GPIO_Port GPIOC
#define BUTTON_2_Pin GPIO_PIN_14
#define BUTTON_2_GPIO_Port GPIOC
#define BUTTON_3_Pin GPIO_PIN_15
#define BUTTON_3_GPIO_Port GPIOC
#define RED_1_Pin GPIO_PIN_1
#define RED_1_GPIO_Port GPIOA
#define RED_2_Pin GPIO_PIN_2
#define RED_2_GPIO_Port GPIOA
#define RED_3_Pin GPIO_PIN_3
#define RED_3_GPIO_Port GPIOA
#define RED_4_Pin GPIO_PIN_4
#define RED_4_GPIO_Port GPIOA
#define AMB_1_Pin GPIO_PIN_5
#define AMB_1_GPIO_Port GPIOA
#define AMB_2_Pin GPIO_PIN_6
#define AMB_2_GPIO_Port GPIOA
#define AMB_3_Pin GPIO_PIN_7
#define AMB_3_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_0
#define A_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_1
#define B_GPIO_Port GPIOB
#define C_Pin GPIO_PIN_2
#define C_GPIO_Port GPIOB
#define DD_Pin GPIO_PIN_11
#define DD_GPIO_Port GPIOB
#define EE_Pin GPIO_PIN_12
#define EE_GPIO_Port GPIOB
#define FF_Pin GPIO_PIN_13
#define FF_GPIO_Port GPIOB
#define GG_Pin GPIO_PIN_14
#define GG_GPIO_Port GPIOB
#define AMB_4_Pin GPIO_PIN_8
#define AMB_4_GPIO_Port GPIOA
#define GREEN_1_Pin GPIO_PIN_9
#define GREEN_1_GPIO_Port GPIOA
#define GREEN_2_Pin GPIO_PIN_10
#define GREEN_2_GPIO_Port GPIOA
#define GREEN_3_Pin GPIO_PIN_11
#define GREEN_3_GPIO_Port GPIOA
#define GREEN_4_Pin GPIO_PIN_12
#define GREEN_4_GPIO_Port GPIOA
#define D_Pin GPIO_PIN_3
#define D_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_4
#define E_GPIO_Port GPIOB
#define F_Pin GPIO_PIN_5
#define F_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_6
#define G_GPIO_Port GPIOB
#define AA_Pin GPIO_PIN_7
#define AA_GPIO_Port GPIOB
#define BB_Pin GPIO_PIN_8
#define BB_GPIO_Port GPIOB
#define CC_Pin GPIO_PIN_9
#define CC_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
