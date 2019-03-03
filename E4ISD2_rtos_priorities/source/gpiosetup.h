/*
 * gpiosetup.h
 *
 *  Created on: Mar 1, 2019
 *      Author: Jesper
 */
#include <MKL25Z4.H>

#ifndef GPIOSETUP_H_
#define GPIOSETUP_H_


/* Define symbolic names for the 4 output PINS */
#define PORTE_PIN_2 	2	//Port E PIN 2
#define PORTE_PIN_5 	5	//Port E PIN 5
#define PORTE_PIN_21 	21	//Port E PIN 21
#define PORTE_PIN_23 	23	//Port E PIN 23
#define MASK(x) (1UL << (x)) // shifts a 1 to the left by x bit positions

// PSOR = Port Set Output Register and PCOR = Port Clear Output Register
/* FPTE instead of PTE:
 * The CMSIS-CORE hardware abstraction layer in MKL25Z4.h provides C-language names and data structures for the GPIO control registers.
 * Note that they are named PTA through PTE (rather than GPIOA through GPIOE).
 * Communication between the CPU and GPIO controller is delayed because the information must pass through several stages,
 * including a crossbar switch and a peripheral bridge.
 * The Kinetis KL25Z MCU includes a second path between the CPU and the GPIO controller which bypasses these stages.
 * To use this faster path, we need to access the GPIO controller and the port data registers through a different set of addresses.
 * The CMSIS-CORE hardware abstraction layer provides the names FPTA for PTA, FPTB for PTB, and so forth.
 */

#define PORTE_PIN_2_HIGH PTE->PSOR = (1 << PORTE_PIN_2)
#define PORTE_PIN_2_LOW PTE->PCOR = (1 << PORTE_PIN_2)
#define PORTE_PIN_5_HIGH PTE->PSOR = (1 << PORTE_PIN_5)
#define PORTE_PIN_5_LOW PTE->PCOR = (1 << PORTE_PIN_5)
#define PORTE_PIN_21_HIGH PTE->PSOR = (1 << PORTE_PIN_21)
#define PORTE_PIN_21_LOW PTE->PCOR = (1 << PORTE_PIN_21)
#define PORTE_PIN_23_HIGH PTE->PSOR = (1 << PORTE_PIN_23)
#define PORTE_PIN_23_LOW PTE->PCOR = (1 << PORTE_PIN_23)



typedef enum
{
	PIN2ON,
	PIN2OFF,
	PIN5ON,
	PIN5OFF,
	PIN21ON,
	PIN21OFF,
	PIN23ON,
	PIN23OFF
}pin_status_t;


// init_gpio function declaration
void init_gpio(void);

void set_pin(pin_status_t pin);


#endif /* GPIOSETUP_H_ */
