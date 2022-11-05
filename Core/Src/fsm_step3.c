/*
 * fsm_step3.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "fsm_step3.h"
int flag = init;
void fsm_no_buttons_run(){
	if(isINCPressed() == 1){
		flag = Press_Inc;
	}
	if(isDECPressed() == 1){
			flag = Press_Dec;
		}
	if(isINCPressedLong() == 1){
			flag = Press3s_Inc;
		}
	if(isDECPressedLong() == 1){
			flag = Press3s_Dec;
		}
	if(isResetPressed() == 1){
			flag = Press_Reset;
		}
	switch(flag){
	case init://init
		flag = No_press;
		setTimer1(5);
		break;
	case No_press://normal
		if(timer1_flag == 1){
			num--;
			if(num < 0)
				num = 0;
			display7_seg(num);
			setTimer1(100);
		}
		break;
	case Wait://waiting
		if(timer1_flag == 1){
			display7_seg(num);
			flag = No_press;
			setTimer1(1000);
		}
		break;
	case Press_Inc:
			num++;
			if(num >9)num =0;
			flag = Wait;
			setTimer1(5);
			break;
	case Press_Dec:
		num--;
		if(num < 0)num = 9;
		flag = Wait;
		setTimer1(5);
		break;
	case Press3s_Inc:
		num++;
		if(num >9)num =0;
		display7_seg(num);
		flag = Wait;

		break;
	case Press3s_Dec:
		num--;
		if(num < 0)num = 9;
		flag = Wait;
		display7_seg(num);

		break;
	case Press_Reset:
		num = 0;
		flag = Wait;
		setTimer1(5);
		break;
	}
}
