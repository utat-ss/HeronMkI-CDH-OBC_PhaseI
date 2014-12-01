/*
FreeRTOS V8.1.2 - Copyright (C) 2014 Real Time Engineers Ltd.
All rights reserved
***********************************************************************
*	FILE NAME:		conf_board.h
*
*	PURPOSE:
*	Board configuration File.
*
*	FILE REFERENCES:	None.
*
*	EXTERNAL VARIABLES:		None.
*
*	EXTERNAL REFERENCES:	Many, see dependencies diagram on dropbox.
*
*	ABORNOMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES: None yet.
*
*	ASSUMPTIONS, CONSTRAINTS, CONDITIONS:	None.
*
*	NOTES:
*	The generic board support module includes board-specific definitions
*	and function prototypes, such as the board initialization function.
*
*	Uncommenting different 'defines' will enabled certain parts of the board
*	to be configured upon the next compilation.
*
*
*	REQUIREMENTS/ FUNCTIONAL SPECIFICATION REFERENCES:
*	None.
*
*	DESCRIPTION:	Not Required.
*
*	DEVELOPMENT HISTORY:
*	11/29/2014			
*
*	Header Changed.
*
*	Line 85: Removed the commenting such that CONF_BOARD_KEEP_WATCHDOG_AT_INIT
*	was defined. (This allows the watchdog to be initialized in init.c)
*
*/

/**
 * \file
 *
 * \brief Board configuration.
 *
 * Copyright (c) 2011 - 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

/* Enabled Watchdog */
#define CONF_BOARD_KEEP_WATCHDOG_AT_INIT

/* Configure UART pins */
//#define CONF_BOARD_UART_CONSOLE

/* Configure ADC example pins */
//#define CONF_BOARD_ADC

/* Enable USB interface (USB) for host mode */
//#define CONF_BOARD_USB_PORT

/*
 * LED pins are not configured for PWM function here.
 * Because those LED pins are enabled for PIO function by default.
 * You can enable them according to application.
 */
/* Configure PWM LED0 pin */
//#define CONF_BOARD_PWM_LED0

/* Configure PWM LED1 pin */
//#define CONF_BOARD_PWM_LED1

/* Configure PWM LED2 pin */
//#define CONF_BOARD_PWM_LED2

/* Configure SPI0 pins */
//#define CONF_BOARD_SPI0
//#define CONF_BOARD_SPI0_NPCS0
//#define CONF_BOARD_SPI0_NPCS1
//#define CONF_BOARD_SPI0_NPCS2
//#define CONF_BOARD_SPI0_NPCS3

/* Configure SPI1 pins */
//#define CONF_BOARD_SPI1
//#define CONF_BOARD_SPI1_NPCS0
//#define CONF_BOARD_SPI1_NPCS1
//#define CONF_BOARD_SPI1_NPCS2
//#define CONF_BOARD_SPI1_NPCS3

//#define CONF_BOARD_TWI0

//#define CONF_BOARD_TWI1

/*
 * USART pins are configured as basic serial port by default.
 * You can enable other pins according application.
 */
/* Configure USART RXD pin */
#define CONF_BOARD_USART_RXD

/* Configure USART TXD pin */
#define CONF_BOARD_USART_TXD

/* Configure USART CTS pin */
//#define CONF_BOARD_USART_CTS

/* Configure USART RTS pin */
//#define CONF_BOARD_USART_RTS

/* Configure USART synchronous communication SCK pin */
//#define CONF_BOARD_USART_SCK

/* Configure ADM3312 enable pin */
#define CONF_BOARD_ADM3312_EN

/* Configure IrDA transceiver shutdown pin */
//#define CONF_BOARD_TFDU4300_SD

/* Configure RS485 transceiver ADM3485 RE pin */
//#define CONF_BOARD_ADM3485_RE

//#define CONF_BOARD_SMC_PSRAM

/* Configure LCD EBI pins */
//#define CONF_BOARD_HX8347A

/* Configure Backlight control pin */
//#define CONF_BOARD_AAT3194

#endif /* CONF_BOARD_H_INCLUDED */
