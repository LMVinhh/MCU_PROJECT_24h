/*
 * ledStatus.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */


#include "ledStatus.h"
void led_status(int status){
	if(status == 1)	HAL_GPIO_WritePin(GPIOA,LED_RED_Pin,RESET);
	if(status == 0)	HAL_GPIO_WritePin(GPIOA,LED_RED_Pin,SET);
}
void led_blink(){
	if(timer3_flag == 1){
		setTimer3(100);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);}

}
