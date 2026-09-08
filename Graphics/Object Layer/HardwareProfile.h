/*********************************************************************
 *
 *	Hardware specific definitions
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    None
 * Processor:       PIC24, dsPIC, PIC32
 * Compiler:        Microchip C30 and C32
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (c) 2011 Microchip Technology Inc.  All rights 
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and 
 * distribute: 
 * (i)  the Software when embedded on a Microchip microcontroller or 
 *      digital signal controller product ("Device") which is 
 *      integrated into Licenseeï¿½s product; or
 * (ii) ONLY the Software driver source files ENC28J60.c and 
 *      ENC28J60.h ported to a non-Microchip device used in 
 *      conjunction with a Microchip ethernet controller for the 
 *      sole purpose of interfacing with the ethernet controller. 
 *
 * You should refer to the license agreement accompanying this 
 * Software for additional information regarding your rights and 
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED ï¿½AS ISï¿?WITHOUT 
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL 
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF 
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS 
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE 
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER 
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT 
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Date	                Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 10/03/06             Original, copied from Compiler.h
 * 06/25/09             dsPIC & PIC24H support 
 * 09/15/09             Added PIC24FJ256DA210 Development Board Support
 * 06/02/11             Added MPLAB X Support
 ********************************************************************/

/*
 ********************************************************************
 * Revision
 * Add support for old hardware platform SSD1963 EVK R3B + PIC32 EVK RD4
 * 14th Nov 2012
 * Programmer: John Leung @ www.TechToys.com.hk
 ********************************************************************
*/


//////////////////////////////////////////////////////////////////////////////////////////////////
/*
*************************************** Define the Host ******************************************
**************************************************************************************************	
* Directives PIC32_GP_SK / PIC32_USB_SK / PIC32_ETH_SK / EXPLORER_16 / PIC32MX360F512L_EVK_RD5B / PIC32_EVK_RD4
* defines what mcu host to use.
* It is possible to stack any of the PIC32 starter kits or just using Explorer 16 as the host.
* This version assumes PIC32MX360F512L on Explorer 16, however, it is not a strict requirement.
* New driver can be developed with different MCU by following the schematic.
**************************************************************************************************	
*/

//**#define PIC32_GP_SK					//PIC32 GP STARTER KIT
//#define PIC32_USB_SK					//PIC32 USB STARTER KIT
#define PIC32_ETH_SK					//PIC32 ETHERNET STARTER KIT
//#define EXPLORER_16					//Explorer 16 connected
//#define PIC32MX360F512L_EVK_RD5B		//PIC24/32 EVK RD5B with PIC32MX360F512L onboard
//#define PIC32_EVK_RD4					//MCU host as PIC24/32 EVK RD4

/*
******************************** Define the display controller ***********************************
**************************************************************************************************	
*/
#define ULTIMA_R4_BOARD							//Display controller SSD1963 EVK Ultima R4.1
//#define USE_DISPLAY_CONTROLLER_SSD1963_R3B			//Display controller is Solomon SSD1963 EVK R3B
/*
**************************************** Define TFT model ****************************************
**************************************************************************************************	
*/
//#define USE_TY430TFT480272				//TFT panel is 4.3" 480x272 display panel
#define USE_TY500TFT800480				//5" TFT 800x480
//#define USE_TY600TFT800480				//6" TFT 800x480
//#define USE_TY700TFT800480				//7" TFT 800x480
//#define USE_TY700TFT800480_R3				//7" TFT 800480 Rev3.0

#if defined (EXPLORER_16) && (defined (PIC32_GP_SK) || defined (PIC32_USB_SK) || defined (PIC32_ETH_SK))
	#error "It is not possible to define both an Explorer 16 and a PIC32 SK at the same time"
#endif

#if defined (PIC32MX360F512L_EVK_RD5B) && (defined (PIC32_GP_SK) || defined (PIC32_USB_SK) || defined (PIC32_ETH_SK))
	#error "It is not possible to define both a PIC24/32 EVK RD5B and a PIC32 SK at the same time"
#endif

#if defined (__PIC32MX__) 

    /*********************************************************************
     * Hardware Configuration for 
     * Option 1: PIC32MX360F512L on Explorer 16 connected to Ultima R4 board (SSD1963)
	 * Option 2: PIC32_GP_SK stacked on Ultima R4 board (SSD1963)
	 * Option 3: PIC24/32 EVK RD5B with PIC32MX360F512L onboard connected to Ultima R4 board (SSD1963) 
     * Graphics controller SSD1963 is connected to PIC32MX360F512L in 16-bit PMP
     * Display 4.3" - 7" TFT
     ********************************************************************/
	#if defined (__32MX360F512L__)
		#if defined (PIC32_GP_SK) 
			#include "Configs/HWP_PIC32_GP_SK_SSD1963_ULTIMA_R4_16PMP.h"
		#elif defined (EXPLORER_16)
	 		#include "Configs/HWP_PIC32MX360F512L_EX16_SSD1963_ULTIMA_R4_16PMP.h"
		#elif defined (PIC32MX360F512L_EVK_RD5B)
			#include "Configs/HWP_PIC32MX360F512L_EVK_RD5B_SSD1963_ULTIMA_R4_16PMP.h"
		#elif defined (PIC32_EVK_RD4)
			#include "Configs/HWP_PIC32MX360F512L_EVK_RD4.h"
		#endif
	#endif

    /*********************************************************************
     * Hardware Configuration for 
     * Option 1: PIC32MX460F512L on Explorer 16 connected to Ultima R4 board (SSD1963)
	 * Graphics controller SSD1963 is connected to PIC32MX795F512L in 8-bit PMP for Explorer 16
	 * Option 2: PIC32_ETH_SK stacked on Ultima R4 board (SSD1963)
     * Graphics Controller SSD1963 connected to PIC32MX795F512L with 16-bit PMP for PIC_ETH_SK
     * Display 4.3" - 7" TFT
     ********************************************************************/
	#if defined (__32MX460F512L__)
		#if defined (PIC32_USB_SK)
		  	#include "Configs/HWP_PIC32_USB_SK_SSD1963_ULTIMA_R4_16PMP.h"
		#elif defined (EXPLORER_16)
	 		#include "Configs/HWP_PIC32MX460F512L_EX16_SSD1963_ULTIMA_R4_8PMP.h"
		#endif
	#endif

    /*********************************************************************
     * Hardware Configuration for 
     * Option 1: PIC32MX795F512L on Explorer 16 connected to Ultima R4 board (SSD1963)
	 * Graphics controller SSD1963 is connected to PIC32MX795F512L in 8-bit PMP for Explorer 16
	 * Option 2: PIC32_ETH_SK stacked on Ultima R4 board (SSD1963)
     * Graphics Controller SSD1963 connected to PIC32MX795F512L with 16-bit PMP for PIC_ETH_SK
     * Display 4.3" - 7" TFT
     ********************************************************************/
	#if defined (__32MX795F512L__)
		#if defined (PIC32_ETH_SK)
	  		#include "Configs/HWP_PIC32_ETH_SK_SSD1963_ULTIMA_R4_16PMP.h"
		#elif defined (EXPLORER_16)
	 		#include "Configs/HWP_PIC32MX795F512L_EX16_SSD1963_ULTIMA_R4_8PMP.h"
		#endif
	#endif
#else
	 #error "Only PIC32MX MCU series is supported yet"
#endif