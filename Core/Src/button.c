/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */


#include "main.h"
#include "button.h"
#include "global.h"
#include"software_timer.h"
 // we aim to work with more than one buttons

int dec_flag = 0;
int inc_flag = 0;
int reset_flag = 0;

int dec_flagLong = 0;
int	inc_flagLong = 0;
int reset_flagLong = 0;
int KeyReg0[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[Buttons]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
//extern int flag_hold = 0;
int TimeforKeyPress = 900;

void subKeyProcess(int i){
	if(i == 0){
		reset_flag = 1;
	}
	if(i == 1){
		inc_flag = 1;
		}
	if(i == 2){
		dec_flag = 1;
		}
}
void subKeyProcessLong(int i){
	if(i == 0){
		reset_flagLong = 1;
		}
		if(i == 1){
			inc_flagLong = 1;
			}
		if(i == 2){
			dec_flagLong = 1;
			}
}

void getKeyInput(){
	for (int i = 0 ;i < 3 ;i++){
	KeyReg0[i] = KeyReg1[i];
	KeyReg1[i]= KeyReg2[i];
	if(i == 0){KeyReg2[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port,RESET_Pin);}
	else if(i == 1) {KeyReg2[i] = HAL_GPIO_ReadPin(INC_GPIO_Port,INC_Pin);}
	else if(i == 2) {KeyReg2[i]= HAL_GPIO_ReadPin(DEC_GPIO_Port,DEC_Pin);}
	if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
		if(KeyReg3[i] != KeyReg2[i]){
			KeyReg3[i] = KeyReg2[i];
			if(KeyReg2[i] == PRESS_STATE){
				subKeyProcess(i);
				//Do mảng duyệt vòng lặp for 3 nút , mỗi nút tương ứng 100ms để chờ 1s
				//=> chờ 3s thì chương trình mất 900ms để hiện thực
				TimeforKeyPress = 900;
			}
		}
		else {

			TimeforKeyPress--;
			if(TimeforKeyPress == 0){
				if(KeyReg2[i] == PRESS_STATE){
					subKeyProcessLong(i);

					}
				TimeforKeyPress = 300;

			}


		}
	}
}
}
int isResetPressed(){
	if(reset_flag == 1){
		reset_flag = 0;

		setTimer3(5);

		return 1;

	}
	return 0;
}
int isINCPressed(){
	if(inc_flag == 1){
		inc_flag = 0;
		setTimer3(5);

		return 1;
	}
	return 0;
}
int isDECPressed(){
	if(dec_flag == 1){
		dec_flag = 0;
		setTimer3(5);

		return 1;
	}
	return 0;
}
int isResetPressedLong(){
	if(reset_flagLong == 1){
		reset_flagLong = 0;

		setTimer3(5);

		return 1;
	}
	return 0;
}
int isINCPressedLong(){
	if(inc_flagLong == 1){
		inc_flagLong = 0;

		setTimer3(5);

		return 1;
	}
	return 0;
}
int isDECPressedLong(){
	if(dec_flagLong == 1){
		dec_flagLong = 0;
		setTimer3(5);

		return 1;
	}
	return 0;
}
