/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
#include "Button.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
const int digitConfig[][7] = {
    // A, B, C, D, E, F, G, DP
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};
const int DOT_COUNTER = 100, LED_SWITCH_COUNTER = 25, CLOCK_COUNTER = 100;
int hour = 15, minute = 12, second = 37;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //* INITIAL SETUP *//
  int count_StateButton1 = 0;
  int count_up = 0;
  int time_LEDRED = 5;
  int time_LEDAMB = 3;
  // int time_LEDAWB = 300;
  // int time_LEDGREEN = 200;
  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
  HAL_GPIO_WritePin(RED_3_GPIO_Port, RED_3_Pin, RESET);
  HAL_GPIO_WritePin(RED_4_GPIO_Port, RED_4_Pin, RESET);
  HAL_GPIO_WritePin(AMB_1_GPIO_Port, AMB_1_Pin, RESET);
  HAL_GPIO_WritePin(AMB_2_GPIO_Port, AMB_2_Pin, RESET);
  HAL_GPIO_WritePin(AMB_3_GPIO_Port, AMB_3_Pin, RESET);
  HAL_GPIO_WritePin(AMB_4_GPIO_Port, AMB_4_Pin, RESET);
  HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
  HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);
  HAL_GPIO_WritePin(GREEN_3_GPIO_Port, GREEN_3_Pin, RESET);
  HAL_GPIO_WritePin(GREEN_4_GPIO_Port, GREEN_4_Pin, RESET);
  display7SEG2(0);
  display7SEG1(0);
  setTimer0(50);

  while (1)
  {
    /* USER CODE END WHILE */
    if (button1_flag == 1)
    {
      if (count_StateButton1 > 4)
      {
        count_StateButton1 = 0;
      }
      if (button1_flag != button1_flagRelease && button1_flagRelease == 0)
      {
        count_StateButton1++;
      }
      button1_flagRelease = button1_flag;
      button1_flag = 0;
    }
    if (count_StateButton1 == 1)
    {
      HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
      HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
      HAL_GPIO_WritePin(RED_3_GPIO_Port, RED_3_Pin, SET);
      HAL_GPIO_WritePin(RED_4_GPIO_Port, RED_4_Pin, SET);
      HAL_GPIO_WritePin(AMB_1_GPIO_Port, AMB_1_Pin, SET);
      HAL_GPIO_WritePin(AMB_2_GPIO_Port, AMB_2_Pin, SET);
      HAL_GPIO_WritePin(AMB_3_GPIO_Port, AMB_3_Pin, SET);
      HAL_GPIO_WritePin(AMB_4_GPIO_Port, AMB_4_Pin, SET);
      HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
      HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);
      HAL_GPIO_WritePin(GREEN_3_GPIO_Port, GREEN_3_Pin, SET);
      HAL_GPIO_WritePin(GREEN_4_GPIO_Port, GREEN_4_Pin, SET);
    }
    if (count_StateButton1 == 2)
    {
      if (timer0_flag == 1)
      {
        HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
        HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
        HAL_GPIO_TogglePin(RED_3_GPIO_Port, RED_3_Pin);
        HAL_GPIO_TogglePin(RED_4_GPIO_Port, RED_4_Pin);
        setTimer0(50);
      }
      display7SEG1(count_StateButton1);
      if (button2_flag == 1)
      {
        button2_flag = 0;
        count_up += 1;
        if (count_up > 4)
        {
          display7SEG2(9);
        }
        display7SEG2(time_LEDRED + count_up);
      }

      if (button3_flag == 1)
      {
        if (button3_flag != button3_flagRelease && button3_flagRelease == 0)
        {
          time_LEDRED = time_LEDRED * 100 + count_up * 100;
          count_up = 0;
        }
        button3_flagRelease = button3_flag;
        button3_flag = 0;
      }
    }
    if (count_StateButton1 == 3)
    {
      if (timer1_flag == 1)
      {
        HAL_GPIO_TogglePin(AMB_1_GPIO_Port, AMB_1_Pin);
        HAL_GPIO_TogglePin(AMB_2_GPIO_Port, AMB_2_Pin);
        HAL_GPIO_TogglePin(AMB_3_GPIO_Port, AMB_3_Pin);
        HAL_GPIO_TogglePin(AMB_4_GPIO_Port, AMB_4_Pin);
        setTimer1(50);
      }
      display7SEG1(count_StateButton1);
      if (button2_flag == 1)
      {
        button2_flag = 0;
        count_up += 1;
        if (count_up > 4)
        {
          display7SEG2(9);
        }
        display7SEG2(time_LEDAMB + count_up);
      }
      if (button3_flag == 1)
      {
        if (button3_flag != button3_flagRelease && button3_flagRelease == 0)
        {
          time_LEDRED = time_LEDAMB * 100 + count_up * 100;
          count_up = 0;
        }
        button3_flagRelease = button3_flag;
        button3_flag = 0;
      }
    }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED_1_Pin | RED_2_Pin | RED_3_Pin | RED_4_Pin | AMB_1_Pin | AMB_2_Pin | AMB_3_Pin | AMB_4_Pin | GREEN_1_Pin | GREEN_2_Pin | GREEN_3_Pin | GREEN_4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | DD_Pin | EE_Pin | FF_Pin | GG_Pin | D_Pin | E_Pin | F_Pin | G_Pin | AA_Pin | BB_Pin | CC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BUTTON_1_Pin BUTTON_2_Pin BUTTON_3_Pin */
  GPIO_InitStruct.Pin = BUTTON_1_Pin | BUTTON_2_Pin | BUTTON_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RED_1_Pin RED_2_Pin RED_3_Pin RED_4_Pin
                           AMB_1_Pin AMB_2_Pin AMB_3_Pin AMB_4_Pin
                           GREEN_1_Pin GREEN_2_Pin GREEN_3_Pin GREEN_4_Pin */
  GPIO_InitStruct.Pin = RED_1_Pin | RED_2_Pin | RED_3_Pin | RED_4_Pin | AMB_1_Pin | AMB_2_Pin | AMB_3_Pin | AMB_4_Pin | GREEN_1_Pin | GREEN_2_Pin | GREEN_3_Pin | GREEN_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin DD_Pin
                           EE_Pin FF_Pin GG_Pin D_Pin
                           E_Pin F_Pin G_Pin AA_Pin
                           BB_Pin CC_Pin */
  GPIO_InitStruct.Pin = A_Pin | B_Pin | C_Pin | DD_Pin | EE_Pin | FF_Pin | GG_Pin | D_Pin | E_Pin | F_Pin | G_Pin | AA_Pin | BB_Pin | CC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void display7SEG1(int num)
{
  if (num < 0 || num > 9)
  {
    return;
  }
  const int *config = digitConfig[num];

  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, config[0] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, config[1] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, config[2] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, config[3] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, config[4] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, config[5] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, config[6] ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEG2(int num)
{
  if (num < 0 || num > 9)
  {
    return;
  }
  const int *config = digitConfig[num];

  HAL_GPIO_WritePin(AA_GPIO_Port, AA_Pin, config[0] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(BB_GPIO_Port, BB_Pin, config[1] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(CC_GPIO_Port, CC_Pin, config[2] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(DD_GPIO_Port, DD_Pin, config[3] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(EE_GPIO_Port, EE_Pin, config[4] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(FF_GPIO_Port, FF_Pin, config[5] ? GPIO_PIN_RESET : GPIO_PIN_SET);
  HAL_GPIO_WritePin(GG_GPIO_Port, GG_Pin, config[6] ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  timerRun();
  getKeyInput();
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
