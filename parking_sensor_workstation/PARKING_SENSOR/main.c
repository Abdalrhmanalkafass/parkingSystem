/*
 * main.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Alkafass
 *
 */

#include "buzzer.h"
#include "lcd.h"
#include "led.h"
#include "ultrasonic.h"
#include "std_types.h"
#include "util/delay.h"
int main(void) {
	buzzer_init();
	LCD_init();
	leds_init();
	Ultrasonic_init();
	uint16 distance = 0;
	while (1) {
		distance = Ultrasonic_readDistance();

		if (distance <= 5) {
			leds_off(red_led);
			leds_off(green_led);
			leds_off(blue_led);
			buzzer_on();
			LCD_moveCursor(0, 0);
			LCD_displayString("     stoooop             ");
	}else if (distance <= 10 && distance>5) {
			leds_on(red_led);
			leds_on(green_led);
			leds_on(blue_led);
			buzzer_off();
			LCD_moveCursor(0, 0);
			LCD_displayString("distance =");
			LCD_moveCursor(0, 14);
			LCD_displayString("cm");
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
		 	if (distance <10 ) LCD_displayStringRowColumn(0,11,"   ");
			if (distance ==10 )   			LCD_displayStringRowColumn(0,12,"  ");

		} else if (distance <= 15 && distance>10) {
			leds_on(red_led);
			leds_on(green_led);
			leds_off(blue_led);
			buzzer_off();
			LCD_moveCursor(0, 0);

			LCD_displayString("distance =");
			LCD_moveCursor(0, 14);
			LCD_displayString("cm");
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
			LCD_displayStringRowColumn(0,12,"  ");
		} else if (distance <= 20 && distance>15) {
			leds_on(red_led);
			leds_off(green_led);
			leds_off(blue_led);
			buzzer_off();
			LCD_moveCursor(0, 0);

			LCD_displayString("distance =");
			LCD_moveCursor(0, 14);
			LCD_displayString("cm");
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
			LCD_displayStringRowColumn(0,12,"  ");
		} else {
			leds_off(red_led);
			leds_off(green_led);
			leds_off(blue_led);
			buzzer_off();
			LCD_moveCursor(0, 0);

			LCD_displayString("distance =");
			LCD_moveCursor(0, 14);
			LCD_displayString("cm");
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
			if (distance <100 )   			LCD_displayStringRowColumn(0,12,"  ");
			LCD_displayStringRowColumn(0,13," ");
	}
	}

	return 0;
}
