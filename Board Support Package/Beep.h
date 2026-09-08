/*****************************************************************************
 *
 * Beeper.
 *
 *****************************************************************************
 * FileName:        Beep.h
 * Dependencies:    Graphics.h
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30, MPLAB C32
 * Linker:          MPLAB LINK30, MPLAB LINK32
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright ?2008 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).  
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS?WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 * Date        	Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 07/10/07		...
 * 02/07/08    	PIC32 support
 *****************************************************************************/

/*
 *****************************************************************************
 * Revision
 * Change for TechToys hardware PIC32 SSD1963 MMEVK R1A
 * Now, #if defined (MMEVK_R1A) in place...
 * John Leung @ www.TechToys.com.hk
 * Date: 19th Aug 2011
 *****************************************************************************
*/

/*
 *****************************************************************************
 * Revision
 * Add support for (ULTIMA_R4_BOARD)
 * John Leung @ www.TechToys.com.hk
 * Date: 13th Feb 2012
 *****************************************************************************
*/
#ifndef _BEEP_H
    #define _BEEP_H

    #include "Graphics/Graphics.h"

    #if defined(__dsPIC33F__) || defined(__PIC24H__)
        #define BEEP_TIME   10
    #else
		#if defined (MMEVK_R1A) || defined (PIC32_EVK_RD4)|| defined (ULTIMA_R4_BOARD)
			#define BEEP_TIME	400
		#else
        	#define BEEP_TIME   100 
		#endif
    #endif
    #ifdef __PIC32MX
		#if defined (MMEVK_R1A) || defined (PIC32_EVK_RD4)||defined (ULTIMA_R4_BOARD)	
        	#define TIMER_BASE  8000
		#else
			#define TIMER_BASE	2200
		#endif
    #else
        #define TIMER_BASE  500
    #endif

/*********************************************************************
* Function:  void BeepInit(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: initializes beeper
*
* Note: none
*
********************************************************************/
/*
#if defined (MMEVK_R1A) || defined (PIC32_EVK_RD4) || defined (ULTIMA_R4_BOARD)
void    BeepInit(void);
#else
#define BeepInit()
#endif
*/
/*********************************************************************
* Macro:  Beep()
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: starts beeper
*
* Note: none
*
********************************************************************/
/*
    #if defined (MMEVK_R1A) || defined (PIC32_EVK_RD4) || defined (ULTIMA_R4_BOARD)
        #define Beep()  T3CONbits.TON = 1
    #else
        #define Beep()  T3CONbits.TON = 1
    #endif
*/
#endif // _BEEP_H
