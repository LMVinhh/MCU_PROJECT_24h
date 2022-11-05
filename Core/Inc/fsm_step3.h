/*
 * fsm_step3.h
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#ifndef INC_FSM_STEP3_H_
#define INC_FSM_STEP3_H_
extern int num3;
#define init 0
#define Wait 2
#define Press_Reset 7
#define Press_Inc 3
#define Press_Dec 4
#define Press3s_Inc 5
#define Press3s_Dec 6
#define No_press 1
#include "global.h"
void fsm_no_buttons_run();
extern int flag;
#endif /* INC_FSM_STEP3_H_ */
