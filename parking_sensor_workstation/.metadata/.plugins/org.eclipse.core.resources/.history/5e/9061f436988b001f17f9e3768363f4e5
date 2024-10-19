/*
 * buzzer.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Alkafass
 */
#include "buzzer.h"
#include "gpio.h"
#include "std_types.h"


void buzzer_init (void) {
	GPIO_setupPinDirection(buzzer_port,buzzer_pin,PIN_OUTPUT);
    GPIO_writePin(buzzer_port,buzzer_pin,LOGIC_LOW);

}
void buzzer_on (void) {

	GPIO_writePin(buzzer_port,buzzer_pin,LOGIC_HIGH);

}
void buzzer_off(void) {

	GPIO_writePin(buzzer_port,buzzer_pin,LOGIC_LOW);

}

