/**
 * @mainpage Free RTOS - first project
 * @image 	html logo.jpg
 * @file    E4ISD2_rtos_hello.c
 * @brief   Application entry point.
 */

/* this is my main file from the E4ISD2_rtos_blinky project for comparison */

#include "FreeRTOS.h"
#include "task.h"

#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "rgbLed.h"
#include "gpiosetup.h"

/**
 * @brief Sets up system hardware
 */
static void setupHardware(void) {
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	init_rgb();
	/* Initial LED0 state is off */
	set_rgb(BLACK);

	// setting gpios to use with analog discovery
	init_gpio();
}

/**
 * @brief LED1 toggle thread
 * @param pvParameters
 */
static void vLEDTask1(void *pvParameters) {

	while (1) {
		// set debug GPIO pin before
		set_pin(PIN5ON);

		set_rgb(RED);

		// clear debug GPIO pin after
		set_pin(PIN5OFF);

		/* About a 3Hz on/off toggle rate */
		vTaskDelay(configTICK_RATE_HZ / 3);
		/* alternative delay function is: vTaskDelayUntil()
		 this function sets delay time including the time it takes to carry
		 out the instructions before vTaskDelayUntil() is called. */
	}
}

/**
 * @brief LED2 toggle thread
 * @param pvParameters
 */
static void vLEDTask2(void *pvParameters) {

	while (1) {
		// set debug GPIO pin before
		set_pin(PIN21ON);

		set_rgb(GREEN);

		// clear debug GPIO pin after
		set_pin(PIN21OFF);

		/* About a 7Hz on/off toggle rate */
		vTaskDelay(configTICK_RATE_HZ / 7);
	}
}

/**
 * @brief UART (or output) thread
 * @param pvParameters
 */
static void vUARTTask(void *pvParameters) {
	int tickCnt = 0;

	while (1) {

		// set debug GPIO pin before
		set_pin(PIN23ON);

		/*print message*/
		PRINTF("Tick: %d\r\n", tickCnt);
		tickCnt++;

		// clear debug GPIO pin after
		set_pin(PIN23OFF);

		/* About a 1s delay here */
		vTaskDelay(configTICK_RATE_HZ);

	}
}

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void) {
	setupHardware();

	PRINTF("FreeRTOS example \n");

	/* LED1 toggle thread */
	xTaskCreate(vLEDTask1, "vTaskLed1",
	configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL), NULL);

	/* LED2 toggle thread */
	xTaskCreate(vLEDTask2, "vTaskLed2",
	configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL), NULL);

	/* UART output thread, simply counts seconds */
	xTaskCreate(vUARTTask, "vTaskUart", configMINIMAL_STACK_SIZE + 80, NULL,
			(tskIDLE_PRIORITY + 1UL), NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

