/*
 * fsm_step1.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "fsm_step1.h"
void fsm_simple_buttons_run(){
	if(isResetPressed() == 1){num = 0;}
	if(isINCPressed() == 1)num++;
	if(isDECPressed() == 1)num--;
	if(num > 9)num = 0;
	if(num < 0)num = 9;
	display7_seg(num);
}
