/*
    FreeRTOS V8.1.2 - Copyright (C) 2014 Real Time Engineers Ltd.
    All rights reserved

	***********************************************************************
	*	FILE NAME:		my_blink.c
	*
	*	PURPOSE:		
	*	I wrote this file in order to make sure that multitasking is working correctly before 
	*	I begin developing real applications.
	*
	*	FILE REFERENCES:	stdio.h, FreeRTOS.h, task.h, partest.h, asf.h
	*
	*	EXTERNAL VARIABLES:
	*
	*	EXTERNAL REFERENCES:	Same a File References.
	*
	*	ABORNOMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES: None yet.
	*
	*	ASSUMPTIONS, CONSTRAINTS, CONDITIONS:	None
	*
	*	NOTES:	 
	*	
	*	REQUIREMENTS/ FUNCTIONAL SPECIFICATION REFERENCES:			
	*	New tasks should be written to use as much of CMSIS as possible. The ASF and 
	*	FreeRTOS API libraries should also be used whenever possible to make the program
	*	more portable.

	*	DEVELOPMENT HISTORY:		
	*	11/22/2014		Created.
	*
	*	DESCRIPTION:
	*	I create two tasks called prvTurnOnTask and prvTurnOffTask which simply turn LED0 on and off.
	*	I am making them have an equal priority such that they must share processing time.
	*	Essentially, I use a flag such that they only toggle the LED when the flag is in a certain position
	*	After each task has toggled the LED, they will also turn on the flag such that they can run an infinite
	*	loop when they aren't toggling.
 */

/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Atmel library includes. */
#include "asf.h"

/* Common demo includes. */
#include "partest.h"

/* Priorities at which the tasks are created. */
#define TurnOn_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )
#define	TurnOff_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )

/* Values passed to the two tasks just to check the task parameter
functionality. */
#define TurnOn_PARAMETER			( 0x1234 )
#define TurnOff_PARAMETER			( 0x5678 )

#define mainQUEUE_LENGTH					( 1 )

/*-----------------------------------------------------------*/

/*
 * The tasks as described in the comments at the top of this file.
 */
static void prvTurnOnTask( void *pvParameters );
static void prvTurnOffTask( void *pvParameters );

/*
 * Called by main() to create the simply blinky style application if
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 1.
 */
void my_blink( void );

//static QueueHandle_t xQueue1 = NULL;
//static QueueHandle_t xQueue2 = NULL;


void my_blink( void )
{
		//xQueue1 = xQueueCreate( mainQUEUE_LENGTH, sizeof( unsigned long ) );		// Create Queue1
		//xQueue2 = xQueueCreate( mainQUEUE_LENGTH, sizeof( unsigned long ) );		// Create Queue2
		
		/* Start the two tasks as described in the comments at the top of this
		file. */
		xTaskCreate( prvTurnOnTask,					/* The function that implements the task. */
					"ON", 									/* The text name assigned to the task - for debug only as it is not used by the kernel. */
					configMINIMAL_STACK_SIZE, 				/* The size of the stack to allocate to the task. */
					( void * ) TurnOn_PARAMETER, /* The parameter passed to the task - just to check the functionality. */
					TurnOn_TASK_PRIORITY, 		/* The priority assigned to the task. */
					NULL );									/* The task handle is not required, so NULL is passed. */

		xTaskCreate( prvTurnOffTask, 
					 "OFF", 
					 configMINIMAL_STACK_SIZE, 
					 ( void * ) TurnOff_PARAMETER, 
					 TurnOn_TASK_PRIORITY, 
					 NULL );
					 
		/* Start the tasks and timer running. */
		vTaskStartScheduler();

	/* If all is well, the scheduler will now be running, and the following
	line will never be reached.  If the following line does execute, then
	there was insufficient FreeRTOS heap memory available for the idle and/or
	timer tasks	to be created.  See the memory management section on the
	FreeRTOS web site for more details. */
	for( ;; );
}
/*-----------------------------------------------------------*/

static void prvTurnOnTask( void *pvParameters )
{
	//const unsigned long send_int = 100UL;	// Send  = '1'
	//unsigned long led_flag = 100UL;
	//const TickType_t  del = 3;
	
	// Check the task parameter is as expected. 
	configASSERT( ( ( unsigned long ) pvParameters ) == TurnOn_PARAMETER );

	for( ;; )
	{
		//if(led_flag == 100UL)
			//{
				//xQueueSend( xQueue2, &send_int, 0U );
				//led_flag = 0U;
				//vParTestToggleLED( 0 );
				//vTaskDelay(del);
			//}
			//
		//xQueueReceive( xQueue1, &led_flag, portMAX_DELAY );
		vParTestSetLED( 0, 1 );
	}
}
/*-----------------------------------------------------------*/

static void prvTurnOffTask( void *pvParameters )
{
	//const unsigned long send_int = 100UL;	// Send  = '1'
	//unsigned long led_flag = 0UL;
	//const TickType_t  del = 3;
	
	// Check the task parameter is as expected. 
	configASSERT( ( ( unsigned long ) pvParameters ) == TurnOff_PARAMETER );

	for( ;; )
	{
		//if(led_flag == 100UL)
		//{
			//{
				//vTaskDelay(del);
				//xQueueSend( xQueue1, &send_int, 0U );
				//led_flag = 0U;
				//vParTestToggleLED( 0 );
			//}
			//
		//}
		//xQueueReceive( xQueue2, &led_flag, portMAX_DELAY );
		vParTestSetLED( 0, 0 );
	}
}
/*-----------------------------------------------------------*/

