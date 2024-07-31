/*
 * check.h
 *
 *  Created on: Jul 30, 2024
 *      Author: pjb
 */

#ifndef INC_CHECK_H_
#define INC_CHECK_H_

#include "main.h"

#define OUT_COUNT 40
#define IN_COUNT 40

typedef struct {
  GPIO_TypeDef* port;
  uint16_t pin;
} OUT_TypeDef;
typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
} IN_TypeDef;


extern  uint32_t gpio_count;
extern uint32_t blink_count;
extern uint8_t error_count;
extern uint32_t test_state;

void LED_SETTING();
void check_connect();
void start_flag(int cnt);
void result_connect();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_CHECK_H_ */
