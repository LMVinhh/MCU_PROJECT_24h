/*
 * fsm_step1.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */
#include "global.h"
#include "fsm_step2.h"
void fsm_3s_buttons_run(){
		if(isINCPressed() == 1){
			num++;
		}
		if(isDECPressed() == 1)num--;
		if(isINCPressedLong() == 1){
			num++;
		}
		if(isDECPressedLong() == 1)num--;
		if(num > 9)num = 0;
		if(num < 0)num = 9;
		display7_seg(num);
}
