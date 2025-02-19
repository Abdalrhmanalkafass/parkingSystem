/*
 * ultrasonic.h
 *
 *  Created on: Oct 15, 2024
 *      Author: ALKAFASS
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "gpio.h"

#define TRIGGER_PORT PORTD_ID
#define TRIGGER_PIN PIN7_ID

void Ultrasonic_edgeProcessing (void);

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
