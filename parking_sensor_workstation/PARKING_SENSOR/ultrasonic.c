/*
 * ultrasonic.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Alkafass
 */
#include "icu.h"
#include "ultrasonic.h"
#include "gpio.h"
#include "std_types.h"
#include "util/delay.h"
#include "avr/io.h"
static volatile uint16 g_pulseTime = 0;
uint8 edge_count = 0;

void Ultrasonic_edgeProcessing (void){


	    if (edge_count == 0) {
	        // First edge: Rising edge detected, start timing
	        ICU_clearTimerValue();              // Clear Timer value
	        ICU_setEdgeDetectionType(FALLING);  // Detect falling edge next
	        edge_count++;
	    }
	    else if (edge_count == 1) {
	        // Second edge: Falling edge detected, stop timing
	        g_pulseTime = ICU_getInputCaptureValue();  // Store the pulse duration
	        ICU_setEdgeDetectionType(RAISING);         // Reset to detect rising edge next time
	        edge_count = 0;  // Reset edge count for the next measurement

	    }
}

void Ultrasonic_init(void){
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	SREG |= (1<<7);
	ICU_init(&ICU_Configurations);
    ICU_setCallBack(Ultrasonic_edgeProcessing);
    GPIO_setupPinDirection(TRIGGER_PORT,TRIGGER_PIN,PIN_OUTPUT);
}
void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);
	_delay_us(2);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void){
uint16 result=0 ;

	Ultrasonic_Trigger();
	// Wait until the pulse is measured by the ICU
	   _delay_ms(50);  // Wait for the echo (can adjust based on sensor and distance)
result = (((float32)g_pulseTime) / 117.6)+1 ;
	return result;
}



