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
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define OUT_COUNT 40
#define IN_COUNT 40
//IN 핀이랑 OUT 핀이랑 정
typedef struct {
  GPIO_TypeDef* port;
  uint16_t pin;
} OUT_TypeDef;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
} IN_TypeDef;

OUT_TypeDef OUTs[OUT_COUNT] = {
		 {OUT_1_GPIO_Port, OUT_1_Pin}, {OUT_2_GPIO_Port, OUT_2_Pin}, {OUT_3_GPIO_Port, OUT_3_Pin}, {OUT_4_GPIO_Port, OUT_4_Pin},
		 {OUT_5_GPIO_Port, OUT_5_Pin}, {OUT_6_GPIO_Port, OUT_6_Pin}, {OUT_7_GPIO_Port, OUT_7_Pin}, {OUT_8_GPIO_Port, OUT_8_Pin},
		 {OUT_9_GPIO_Port, OUT_9_Pin}, {OUT_10_GPIO_Port, OUT_10_Pin}, {OUT_11_GPIO_Port, OUT_11_Pin}, {OUT_12_GPIO_Port, OUT_12_Pin},
		 {OUT_13_GPIO_Port, OUT_13_Pin}, {OUT_14_GPIO_Port, OUT_14_Pin}, {OUT_15_GPIO_Port, OUT_15_Pin}, {OUT_16_GPIO_Port, OUT_16_Pin},
		 {OUT_17_GPIO_Port, OUT_17_Pin}, {OUT_18_GPIO_Port, OUT_18_Pin}, {OUT_19_GPIO_Port, OUT_19_Pin}, {OUT_20_GPIO_Port, OUT_20_Pin},
		 {OUT_21_GPIO_Port, OUT_21_Pin}, {OUT_22_GPIO_Port, OUT_22_Pin}, {OUT_23_GPIO_Port, OUT_23_Pin}, {OUT_24_GPIO_Port, OUT_24_Pin},
		 {OUT_25_GPIO_Port, OUT_25_Pin}, {OUT_26_GPIO_Port, OUT_26_Pin}, {OUT_27_GPIO_Port, OUT_27_Pin}, {OUT_28_GPIO_Port, OUT_28_Pin},
		 {OUT_29_GPIO_Port, OUT_29_Pin}, {OUT_30_GPIO_Port, OUT_30_Pin}, {OUT_31_GPIO_Port, OUT_31_Pin}, {OUT_32_GPIO_Port, OUT_32_Pin},
		 {OUT_33_GPIO_Port, OUT_33_Pin}, {OUT_34_GPIO_Port, OUT_34_Pin}, {OUT_35_GPIO_Port, OUT_35_Pin}, {OUT_36_GPIO_Port, OUT_36_Pin},
		 {OUT_37_GPIO_Port, OUT_37_Pin}, {OUT_38_GPIO_Port, OUT_38_Pin}, {OUT_39_GPIO_Port, OUT_39_Pin}, {OUT_40_GPIO_Port, OUT_40_Pin},
};

IN_TypeDef INs[IN_COUNT] = {
		 {IN_1_GPIO_Port, IN_1_Pin}, {IN_2_GPIO_Port, IN_2_Pin}, {IN_3_GPIO_Port, IN_3_Pin}, {IN_4_GPIO_Port, IN_4_Pin},
		 {IN_5_GPIO_Port, IN_5_Pin}, {IN_6_GPIO_Port, IN_6_Pin}, {IN_7_GPIO_Port, IN_7_Pin}, {IN_8_GPIO_Port, IN_8_Pin},
		 {IN_9_GPIO_Port, IN_9_Pin}, {IN_10_GPIO_Port, IN_10_Pin}, {IN_11_GPIO_Port, IN_11_Pin}, {IN_12_GPIO_Port, IN_12_Pin},
		 {IN_13_GPIO_Port, IN_13_Pin}, {IN_14_GPIO_Port, IN_14_Pin}, {IN_15_GPIO_Port, IN_15_Pin}, {IN_16_GPIO_Port, IN_16_Pin},
		 {IN_17_GPIO_Port, IN_17_Pin}, {IN_18_GPIO_Port, IN_18_Pin}, {IN_19_GPIO_Port, IN_19_Pin}, {IN_20_GPIO_Port, IN_20_Pin},
		 {IN_21_GPIO_Port, IN_21_Pin}, {IN_22_GPIO_Port, IN_22_Pin}, {IN_23_GPIO_Port, IN_23_Pin}, {IN_24_GPIO_Port, IN_24_Pin},
		 {IN_25_GPIO_Port, IN_25_Pin}, {IN_26_GPIO_Port, IN_26_Pin}, {IN_27_GPIO_Port, IN_27_Pin}, {IN_28_GPIO_Port, IN_28_Pin},
		 {IN_29_GPIO_Port, IN_29_Pin}, {IN_30_GPIO_Port, IN_30_Pin}, {IN_31_GPIO_Port, IN_31_Pin}, {IN_32_GPIO_Port, IN_32_Pin},
		 {IN_33_GPIO_Port, IN_33_Pin}, {IN_34_GPIO_Port, IN_34_Pin}, {IN_35_GPIO_Port, IN_35_Pin}, {IN_36_GPIO_Port, IN_36_Pin},
		 {IN_37_GPIO_Port, IN_37_Pin}, {IN_38_GPIO_Port, IN_38_Pin}, {IN_39_GPIO_Port, IN_39_Pin}, {IN_40_GPIO_Port, IN_40_Pin},
};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void LED_SETTING();
void check_connect();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
volatile uint32_t test_state = 0;
volatile uint32_t gpio_count = 0;
volatile uint32_t blink_count = 0;
volatile uint8_t error_count = 0;

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
  LED_SETTING();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  	if(error_count > 0)
		{
			HAL_TIM_Base_Stop(&htim2);
  		HAL_GPIO_WritePin(ERROR_LED_GPIO_Port,ERROR_LED_Pin,0);
			HAL_GPIO_WritePin(NORMAL_LED_GPIO_Port, NORMAL_LED_Pin, 1);
			error_count=0;

		}
		else if (test_state ==1)
		{
			HAL_GPIO_WritePin(ERROR_LED_GPIO_Port,ERROR_LED_Pin,1);
			HAL_GPIO_WritePin(NORMAL_LED_GPIO_Port,NORMAL_LED_Pin,0);
			test_state=0;
		}
    /* USER CODE END WHILE */

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	LED_SETTING();
	if(GPIO_Pin == BTN_10_Pin)
	{
		gpio_count = 10;
		blink_count = 10*2;
		HAL_TIM_Base_Start_IT(&htim2);
		check_connect();
	}
	else if(GPIO_Pin == BTN_14_Pin)
	{
		gpio_count = 14;
		blink_count = 14*2;
		HAL_TIM_Base_Start_IT(&htim2);
		check_connect();
	}
	else if(GPIO_Pin == BTN_16_Pin)
	{
		gpio_count = 16;
		blink_count = 16*2;
		HAL_TIM_Base_Start_IT(&htim2);
		check_connect();
	}
	else if(GPIO_Pin == BTN_20_Pin)
	{
		gpio_count = 20;
		blink_count = 20*2;
		HAL_TIM_Base_Start_IT(&htim2);
		check_connect();
	}
	else if(GPIO_Pin == BTN_26_Pin)
	{
		gpio_count = 26;
		blink_count = 26*2;
		HAL_TIM_Base_Start_IT(&htim2);
		check_connect();
	}
	else if(GPIO_Pin == BTN_40_Pin)
	{
		gpio_count = 40;
		blink_count = 40*2;
		HAL_TIM_Base_Start_IT(&htim2);
		check_connect();
	}


}
void LED_SETTING()
{
	HAL_GPIO_WritePin(TEST_LED_GPIO_Port,TEST_LED_Pin,1);
	HAL_GPIO_WritePin(ERROR_LED_GPIO_Port,ERROR_LED_Pin,1);
	HAL_GPIO_WritePin(NORMAL_LED_GPIO_Port,NORMAL_LED_Pin,1);
	HAL_GPIO_WritePin(MCU_LED_GPIO_Port,MCU_LED_Pin,0);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{

		if(blink_count >0)
		{
			HAL_GPIO_TogglePin(TEST_LED_GPIO_Port, TEST_LED_Pin);
			blink_count--;
			if(blink_count == 0)
			{
				HAL_TIM_Base_Stop(htim);
				test_state =1;
			}
		}


	}
}

void check_connect()
{
	for (int i = 0; i < gpio_count; i++) {
		// 모든 출력 핀을 LOW
		for (int j = 0; j < gpio_count; j++) {
			HAL_GPIO_WritePin(OUTs[j].port, OUTs[j].pin, 0);
		}
		// 현재 출력 핀을 HIGH
		HAL_GPIO_WritePin(OUTs[i].port, OUTs[i].pin, GPIO_PIN_SET);
		GPIO_PinState input_state = HAL_GPIO_ReadPin(INs[i].port, INs[i].pin);
		//단선 검
		if (input_state != GPIO_PIN_SET) {
			error_count++;
		}
		// 출력 핀을 LOW로 재설정
		HAL_GPIO_WritePin(OUTs[i].port, OUTs[i].pin, GPIO_PIN_RESET);

		//쇼트 검사
		for(int k = 0; k < gpio_count; k++) {
			if (i != k)
			{
				input_state = HAL_GPIO_ReadPin(INs[k].port, INs[k].pin);
				if (input_state == GPIO_PIN_SET)
				{
					error_count++;
				}
			}
		}
	}
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

#ifdef  USE_FULL_ASSERT
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
