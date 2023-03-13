/* ###################################################################
**     Filename    : main.c
**     Project     : MPWS
**     Processor   : MKL05Z32VLF4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-12-13, 14:56, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "RED_LED.h"
#include "TU1.h"
#include "GREEN_LED.h"
#include "BLUE_LED.h"
#include "TSS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <stdlib.h>
/*** Function Prototype ***/
void MAGENTA(){
	RED_LED_SetRatio16(RED_LED_DeviceData,0x0 + 43690);
	GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);
	BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0 + 21845);
}

void LIGHT(){
	RED_LED_SetRatio16(RED_LED_DeviceData,0xffff);
	GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0xffff);
	BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0xffff);
}

void DARK(){
	RED_LED_SetRatio16(RED_LED_DeviceData,0x0);
	GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);
	BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);
}

void delayMS(unsigned int dtime){
	 unsigned int i, j;
	 for(i=0;i<dtime;i++){
		 for(j=0;j<785;j++){
			 __asm("nop");
		 }
	 }
}

void bonjour(){
	int x, y, z;
	unsigned int alpha, beta, gamma;
	x = 1;y = 1;z = 1;
	alpha = 0;beta = 21845;gamma = 43690;
	for(;;){
		alpha = alpha + 1 * x;
		beta = beta + 1 * y;
		gamma = gamma + 1 * z;
		if (alpha == 65535 ){x = -1;}
		else if(alpha == 0){x = 1;}
		if (beta == 65535 ){y = -1;}
		else if(beta == 0){y = 1;}
		if (gamma == 65535 ){z = -1;}
		else if(gamma == 0){z = 1;}
		RED_LED_SetRatio16(RED_LED_DeviceData,0x0 + alpha);
		GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0 + beta);
		BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0 + gamma);
		if(alpha == 0 && beta == 21845 && gamma == 43690){
			break;
		}
	}
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

int ispressed = 0;

int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  TSS1_Configure();
  /*** End of Processor Expert internal initialization.                    ***/
  unsigned int i, j, rad, sol, TCP;
  int clum[50];
  int upstream;
  /* Write your code here */
  /* For example: for(;;) { } */
  for(;;){
	  /** The Initial **/
	  DARK();
	  ispressed = 0;
	  rad = 0;
	  for(;;){
		  bonjour();
		  while(ispressed < 4){
			  TSS_Task();
		  }
		  break;
	  }
	  /** Game start **/
	  LIGHT();
	  delayMS(1000);
	  DARK();
	  delayMS(1000);
	  TCP = TSS1_cKey0.Position;
	  srand(TCP);
	  for(i = 1; i < 51; i++){
		  for(j = i - 1;j < i; j++){
			  clum[j] = rand()%100;
			  clum[j] = clum[j] % 10;
			  if(clum[j] == 1 || clum[j] == 4 || clum[j] == 7){ clum[j] = 0; }
			  if(clum[j] == 2 || clum[j] == 5 || clum[j] == 8){ clum[j] = 1; }
			  if(clum[j] == 3 || clum[j] == 6 || clum[j] == 9){ clum[j] = 2; }
			  if(clum[j] == 0){clum[j] = rand()%3;}
		  }																		//Random number generation.
		  for(j = 0; j < i; j++){
			  upstream = clum[j];
			  switch(upstream){
			  case 0: GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);RED_LED_SetRatio16(RED_LED_DeviceData,0xffff);
			  delayMS(1000);RED_LED_SetRatio16(RED_LED_DeviceData,0x0);break;
			  case 1: RED_LED_SetRatio16(RED_LED_DeviceData,0x0);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0xffff);
			  delayMS(1000);GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);break;
			  case 2: RED_LED_SetRatio16(RED_LED_DeviceData,0x0);GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0xffff);
			  delayMS(1000);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);break;
			  }
			  delayMS(1000);
		  }																		//Display the colour being judged.
		  for(j = 0; j < i; j++){
			  for(;;){
				  DARK();
				  ispressed = 0;
				  sol = 3;
				  while(ispressed < 7){
					  TSS_Task();
				  }
				  if (TSS1_cKey0.Position < 13) {sol = 0;break;}
				  if (TSS1_cKey0.Position > 13 && TSS1_cKey0.Position < 40) {sol = 1;break;}
				  if (TSS1_cKey0.Position > 40) {sol = 2;break;}
			  }
			  upstream = sol;
			  if(upstream == 0){GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);RED_LED_SetRatio16(RED_LED_DeviceData,0xffff);
			  delayMS(1000);RED_LED_SetRatio16(RED_LED_DeviceData,0x0);}
			  if(upstream == 1){RED_LED_SetRatio16(RED_LED_DeviceData,0x0);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0xffff);
			  delayMS(1000);GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);}
			  if(upstream == 2){RED_LED_SetRatio16(RED_LED_DeviceData,0x0);GREEN_LED_SetRatio16(GREEN_LED_DeviceData,0x0);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0xffff);
			  delayMS(1000);BLUE_LED_SetRatio16(BLUE_LED_DeviceData,0x0);}
			  if(sol != clum[j]) {rad = 1;break;}
		  }																		//Accept touch input, assign a value, then judge.
		  if (rad == 0){
			  DARK();
			  delayMS(1000);
			  MAGENTA();
			  delayMS(1000);
			  DARK();
			  delayMS(1000);
		  }																		//The prompt is entered without error when the round is over.

		  if (rad == 1) {break;}
	  }
	  /** End of game **/
	  for(;;){
		  bonjour();
	  }
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
