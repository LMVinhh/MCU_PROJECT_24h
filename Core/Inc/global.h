/*
 * global.h
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "ledStatus.h"
#include "SEVEN_SEGMENT.h"
#include "fsm_step1.h"
#include "fsm_step2.h"
#include "fsm_step3.h"

//#include "process.h"
extern int num ;
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#define Buttons 3

#define INIT 1
#define RED_GREEN  2
#define RED_YELLOW  3
#define GREEN_RED  4
#define YELLOW_RED 5


#define MAN_RED 10
#define MAN_GREEN 11
#define MAN_YELLOW 12


extern int status;

#endif /* INC_GLOBAL_H_ */
