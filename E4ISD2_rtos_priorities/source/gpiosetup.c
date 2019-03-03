/*
 * gpiosetup.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Jesper
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "gpiosetup.h"

void init_gpio(void) {
	/* Setup GPIO pins */
	/* enable clocks for relevant ports*/
	//SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK
	//SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK
	//SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK
	//SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	/* setup PINS to GPIO through port multiplexing */
	PORTE->PCR[PORTE_PIN_2] &= PORT_PCR_MUX_MASK;
	PORTE->PCR[PORTE_PIN_2] |= PORT_PCR_MUX(1);
	PORTE->PCR[PORTE_PIN_5] &= PORT_PCR_MUX_MASK;
	PORTE->PCR[PORTE_PIN_5] |= PORT_PCR_MUX(1);
	PORTE->PCR[PORTE_PIN_21] &= PORT_PCR_MUX_MASK;
	PORTE->PCR[PORTE_PIN_21] |= PORT_PCR_MUX(1);
	PORTE->PCR[PORTE_PIN_23] &= PORT_PCR_MUX_MASK;
	PORTE->PCR[PORTE_PIN_23] |= PORT_PCR_MUX(1);

	/* set PINS as outputs*/
	PTE->PDDR |=
			MASK(
					PORTE_PIN_2) | MASK(PORTE_PIN_5) | MASK(PORTE_PIN_21) | MASK(PORTE_PIN_23);

}

void set_pin(pin_status_t pin)
{
	switch (pin) {
		case PIN2ON:
			PORTE_PIN_2_HIGH;
			break;
		case PIN2OFF:
			PORTE_PIN_2_LOW;
			break;
		case PIN5ON:
			PORTE_PIN_5_HIGH;
			break;
		case PIN5OFF:
			PORTE_PIN_5_LOW;
			break;
		case PIN21ON:
			PORTE_PIN_21_HIGH;
			break;
		case PIN21OFF:
			PORTE_PIN_21_LOW;
			break;
		case PIN23ON:
			PORTE_PIN_23_HIGH;
			break;
		case PIN23OFF:
			PORTE_PIN_23_LOW;
			break;

	}

}

