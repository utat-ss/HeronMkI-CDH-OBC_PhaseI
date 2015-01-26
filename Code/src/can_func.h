/*
    Author: Keenan Burnett

	***********************************************************************
	*	FILE NAME:		can_func.h
	*
	*	PURPOSE:		
	*	This file allows can_test0.c to have it's set of includes and variable
	*	declarations before sysclk_init and board_init are called. This is important
	*	if CAN is to be initialized correctly.
	*	
	*
	*	FILE REFERENCES:	sn65hvd234.h, can.h, stdio.h, string.h, board.h, sysclk.h, exceptions.h
	*						pmc.h, conf_board.h, conf_clock.h, pio.h
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
	*	01/02/2015		Created.
	*
*/

#include <asf/sam/components/can/sn65hvd234.h>
#include <asf/sam/drivers/can/can.h>
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "sysclk.h"
#include "exceptions.h"
#include "pmc.h"
#include "conf_board.h"
#include "conf_clock.h"
#include "pio.h"


/*		CURRENT PRIORITY LEVELS			
	Note: ID and priority are two different things.
		  For the sake of simplicity, I am making them the same.

		COMS TO CDH COMMAND (IMMED)	0
		PAYLOAD COMMAND				1
		COMS TO CDH COMMAND (SCHED) 2
		EPS COMMAND					3
		COMS COMMND					4
		COMS REQUESTING DATA		5
		COMS RECEIVING DATA			6
		RECEIVING PAYLOAD DATA		7
		REQUEST PAYLOAD DATA		8
		REQUEST HOUSEKEEPING		9
		TRANMITTING HOUSEKEEPING	10
		LED TOGGLE (LOWEST + 1) =	11
*/		

#define COMMAND_OUT					0X01010101
#define COMMAND_IN					0x00001111
#define HK_TRANSMIT					0x12345678
#define CAN_MSG_DUMMY_DATA          0x55AAAA55

#define NODE0_ID				10
#define NODE1_ID				9

#define COMMAND_PRIO			11
#define HK_REQUEST_PRIO			9


/** CAN frame max data length */
#define MAX_CAN_FRAME_DATA_LEN      8

/** CAN0 Transceiver */
sn65hvd234_ctrl_t can0_transceiver;

/** CAN1 Transceiver */
sn65hvd234_ctrl_t can1_transceiver;

/** CAN0 Transfer mailbox structure */
can_mb_conf_t can0_mailbox;

/** CAN1 Transfer mailbox structure */
can_mb_conf_t can1_mailbox;

/** Receive status */
//volatile uint32_t g_ul_recv_status = 0;

void CAN1_Handler(void);
void CAN0_Handler(void);
void decode_can_msg(can_mb_conf_t *p_mailbox, Can* controller);
void reset_mailbox_conf(can_mb_conf_t *p_mailbox);
void command_out(void);
void command_in(void);
void can_initialize(void);
/*---------------------------------------------------------*/

