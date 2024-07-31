/*
 * check.c
 *
 *  Created on: Jul 30, 2024
 *      Author: pjb
 */

#include "check.h"
#include "tim.h"
#include "gpio.h"

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

// 버튼 눌렸을때
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	LED_SETTING();
	if(GPIO_Pin == BTN_10_Pin)
	{
		start_flag(10);
	}
	else if(GPIO_Pin == BTN_14_Pin)
	{
		start_flag(14);
	}
	else if(GPIO_Pin == BTN_16_Pin)
	{
		start_flag(16);
	}
	else if(GPIO_Pin == BTN_20_Pin)
	{
		start_flag(20);
	}
	else if(GPIO_Pin == BTN_26_Pin)
	{
		start_flag(26);
	}
	else if(GPIO_Pin == BTN_40_Pin)
	{
		start_flag(40);
	}

}

// 동작 시
void start_flag(int cnt)
{
	gpio_count = cnt;
	blink_count = cnt * 2;
	HAL_TIM_Base_Start_IT(&htim2);
	check_connect();
}

// LED 초기화
void LED_SETTING()
{
	HAL_GPIO_WritePin(TEST_LED_GPIO_Port,TEST_LED_Pin,1);
	HAL_GPIO_WritePin(ERROR_LED_GPIO_Port,ERROR_LED_Pin,1);
	HAL_GPIO_WritePin(NORMAL_LED_GPIO_Port,NORMAL_LED_Pin,1);
	HAL_GPIO_WritePin(MCU_LED_GPIO_Port,MCU_LED_Pin,0);
}

//타이머 작동시 진행
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

// 플렛 커넥터 체크
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
		//단선 검사
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

// 실행 결과
void result_connect()
{
	if(error_count > 0)
	{
		HAL_TIM_Base_Stop(&htim2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(ERROR_LED_GPIO_Port,ERROR_LED_Pin,0);
		HAL_GPIO_WritePin(NORMAL_LED_GPIO_Port, NORMAL_LED_Pin, 1);
		HAL_GPIO_WritePin(TEST_LED_GPIO_Port,TEST_LED_Pin,1);
		error_count=0;

	}
	else if (test_state ==1)
	{
		HAL_GPIO_WritePin(ERROR_LED_GPIO_Port,ERROR_LED_Pin,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(NORMAL_LED_GPIO_Port,NORMAL_LED_Pin,0);
		HAL_GPIO_WritePin(TEST_LED_GPIO_Port,TEST_LED_Pin,1);
		test_state=0;
	}
}
