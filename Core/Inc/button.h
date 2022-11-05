/*
 * button.h
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE 1
#define PRESS_STATE 0
void subKeyProcess(int);
void subKeyProcessLong(int);


void getKeyInput();
int isResetPressed();
int isINCPressed();
int isDECPressed();
int isResetPressedLong();
int isINCPressedLong();
int isDECPressedLong();

extern int reset_flag;
extern int inc_flag;
extern int dec_flag;

extern int reset_flagLong;
extern int inc_flagLong;
extern int dec_flagLong;
#endif /* INC_BUTTON_H_ */
