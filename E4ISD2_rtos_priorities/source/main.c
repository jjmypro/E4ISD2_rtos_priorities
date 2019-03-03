/**
 * @mainpage Free RTOS - priorities project
 * @image 	html logo.jpg
 * @file    main.c
 * @brief   Application entry point.
 */

#include "FreeRTOS.h"
#include "task.h"

#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "rgbLed.h"



#define DEBUG_PORT		PORTE
#define DEBUG_GPIO		GPIOE
#define DEBUG_PIN1		20	//J10 Pin1
#define DEBUG_PIN2		21	//J10 Pin3
#define DEBUG_PIN3		22	//J10 Pin5
#define DEBUG_PIN4		23	//J10 Pin7



/**
 * @brief Sets up system hardware
 */
static void setupHardware(void)
{
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	init_rgb();
	/* Initial LED0 state is off */
	set_rgb(BLACK);

	/* setup debug pins for profiling */
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	DEBUG_PORT->PCR[DEBUG_PIN1] = (1<<8);
	DEBUG_PORT->PCR[DEBUG_PIN2] = (1<<8);
	DEBUG_PORT->PCR[DEBUG_PIN3] = (1<<8);
	DEBUG_PORT->PCR[DEBUG_PIN4] = (1<<8);

	DEBUG_GPIO->PDDR |= ((1<<DEBUG_PIN1) | (1<<DEBUG_PIN2) | (1<<DEBUG_PIN3) | (1<<DEBUG_PIN4));
}

/**
 * @brief Low priority thread, newer yields
 * @param pvParameters
 */
static void vLowPriTask(void *pvParameters)
{

	while (1)
	{
		/*set debug GPIO before */
		DEBUG_GPIO->PSOR = (1<<DEBUG_PIN1);

		set_rgb(RED);
		set_rgb(BLACK);

		/*clear debug GPIO after */
		DEBUG_GPIO->PCOR = (1<<DEBUG_PIN1);
	}
}

/**
 * @brief High priority thread, yield when finished
 * @param pvParameters
 */
static void vHiPriTask(void *pvParameters)
{

	while (1)
	{
		/*set debug GPIO before */
		DEBUG_GPIO->PSOR = (1<<DEBUG_PIN2);

		set_rgb(GREEN);

		/*clear debug GPIO after */
		DEBUG_GPIO->PCOR = (1<<DEBUG_PIN2);

		/* About a 7Hz on/off toggle rate */
		vTaskDelay(configTICK_RATE_HZ / 7);
	}
}


/**
 * @brief	main routine for FreeRTOS priorities example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	setupHardware();

	PRINTF("FreeRTOS priorities example - Find & Fix the errors \n");

	/* LED1 toggle thread */
	xTaskCreate(vLowPriTask, "vLowPriTask",
	configMINIMAL_STACK_SIZE, NULL, 2,NULL);

	/* LED2 toggle thread */
	xTaskCreate(vHiPriTask, "vHiPriTask",
	configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}
