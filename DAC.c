// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Last Modified: 5/4/2016
// Hardware connections

#include <stdint.h>
#include "tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none

void DAC_Init(void){
	uint8_t wait1;
	SYSCTL_RCGC2_R |= 0x02;			//Turn on Port B
	wait1++;
	wait1++;
  		
	
	GPIO_PORTB_DIR_R |= 0x1F;		//PB 0-4 outputs;  PB 4 is debugger for ISR
	GPIO_PORTB_AFSEL_R &= 0xF0;	
	GPIO_PORTB_DEN_R |= 0x0F;

}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(uint32_t data){
	uint32_t holder1;
	uint32_t holder2;
	
	holder1 = data;
	
	holder2 = GPIO_PORTB_DATA_R;
	holder2 &= 0xF0;
	holder1 |= holder2;
		
	GPIO_PORTB_DATA_R = holder1;
}
