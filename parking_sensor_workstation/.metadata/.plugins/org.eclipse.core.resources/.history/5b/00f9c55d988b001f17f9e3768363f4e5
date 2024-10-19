/*
 * led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Alkafass
 */
#include "led.h"
#include "gpio.h"
#include "std_types.h"
void leds_init(void) {
	GPIO_setupPinDirection(red_port, red_pin, PIN_OUTPUT);
	GPIO_setupPinDirection(green_port, green_pin, PIN_OUTPUT);
	GPIO_setupPinDirection(blue_port, blue_pin, PIN_OUTPUT);
	if (connection_led == 1) {
		GPIO_writePin(red_port, red_pin, LOGIC_LOW);
		GPIO_writePin(green_port, green_pin, LOGIC_LOW);
		GPIO_writePin(blue_port, blue_pin, LOGIC_LOW);
	} else {
		GPIO_writePin(red_port, red_pin, LOGIC_HIGH);
		GPIO_writePin(green_port, green_pin, LOGIC_HIGH);
		GPIO_writePin(blue_port, blue_pin, LOGIC_HIGH);

	}

}

void leds_on( led_id) {
	if (connection_led == 1) {

		switch (led_id) {
		case red_led:
			GPIO_writePin(red_port, red_pin, LOGIC_HIGH);
			break;
		case green_led:
			GPIO_writePin(green_port, green_pin, LOGIC_HIGH);
			break;
		case blue_led:
			GPIO_writePin(blue_port, blue_pin, LOGIC_HIGH);
			break;
		}
	} else {
		switch (led_id) {
		case red_led:
			GPIO_writePin(red_port, red_pin, LOGIC_LOW);
			break;
		case green_led:
			GPIO_writePin(green_port, green_pin, LOGIC_LOW);
			break;
		case blue_led:
			GPIO_writePin(blue_port, blue_pin, LOGIC_LOW);
			break;
		}
	}

}
void leds_off( led_id) {
	if (connection_led == 1) {
		switch (led_id) {
		case red_led:
			GPIO_writePin(red_port, red_pin, LOGIC_LOW);
			break;
		case green_led:
			GPIO_writePin(green_port, green_pin, LOGIC_LOW);
			break;
		case blue_led:
			GPIO_writePin(blue_port, blue_pin, LOGIC_LOW);
			break;
		}
	} else {

		switch (led_id) {
		case red_led:
			GPIO_writePin(red_port, red_pin, LOGIC_HIGH);
			break;
		case green_led:
			GPIO_writePin(green_port, green_pin, LOGIC_HIGH);
			break;
		case blue_led:
			GPIO_writePin(blue_port, blue_pin, LOGIC_HIGH);
			break;
		}
	}
}

