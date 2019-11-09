/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       mcu.h
 * \brief      Implements the functions that manage the microcontroller
 *
 * \version    1.0
 * \date       Jan 1 2011
 * \author     Miguel Luis
 */
#ifndef __MCU_H__
#define __MCU_H__


// Comment the following line when not working with the HID Bootloader
#define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER

#define CLOCK_FREQ 48000000
#define GetSystemClock( ) CLOCK_FREQ

#define INPUT_PIN		1
#define OUTPUT_PIN		0


#include "Compiler.h"
#include "sx1243-Hal.h"

#if __18CXX
#define STRING_CAST                                    const far rom char *
#else
#define STRING_CAST
#endif


/*!
 * \brief Initializes the microcontroller
 */
void McuInit( void );


/** @name rand
 * The {\bf rand} function generates a sequence of pseudo-random integer
 * values in the range [0,RAND_MAX].
 *
 * The implementation shall behave as if no library function calls {\bf rand}.
 */
int randl( void );

/** @name srand
 * The {\bf srand} function sets the starting seed for the pseudo-random
 * number sequence generated by the {\bf rand} function. If {\bf srand} is
 * called again with the same seed value, the same sequence of value shall
 * be returned by {\bf rand}. If {\bf rand} is called without {\bf srand}
 * having first been called, the pseudo-random sequence of numbers generated
 * shall be the same as if {\bf srand} had been called with a seed value
 * of 1.
 *
 * The implementation shall behave as if no library function calls {\bf srand}.
 */
void srandl( auto unsigned int seed );

/*!
 * \brief Computes a random number between min and max
 *
 * \param [IN] min range minimum value
 * \param [IN] max range maximum value
 * \retval random random value in range min..max
 */
U32 randr( U32 min, U32 max );

#endif // __MCU_H__