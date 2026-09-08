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

#if defined (__PIC32MX__) 

    /*********************************************************************
     * Hardware Configuration for 
     * PIC32 GP SK stack on TechToy's MMEVK R1A
     * Graphics SSD1963 EVK R3B
     * Display 4.3" - 7" TFT
     ********************************************************************/	
	
	//#if defined (PIC32_GP_SK) && defined (MMEVK_R1A)
	      //#include "Configs/HWP_PIC32_GP_SK_ON_MMEVK_16PMP.h"
	//#endif
	
    /*********************************************************************
     * Hardware Configuration for 
     * PIC32MX360F512L on PIC32_EVK_RD4 evaluation board
     * Graphics SSD1963 EVK R3B
     * Display 4.3" - 7" TFT
     ********************************************************************/
	
	//#if defined (PIC32_EVK_RD4) && defined (USE_DISPLAY_CONTROLLER_SSD1963_R3B)
	      //#include "Configs/HWP_PIC32MX360F512L_EVK_RD4.h"
	//#endif
	
    /*********************************************************************
     * Hardware Configuration for 
     * PIC32MX360F512L on Explorer 16 connected to Ultima R4 board (SSD1963)
     * Graphics Controller is SSD1963
     * Display 4.3" - 7" TFT
     ********************************************************************/
	
	//#if defined (ULTIMA_R4_BOARD) && defined (EXPLORER_16)
	      //#include "Configs/HWP_PIC32MX360F512L_ON_EX16_ULTIMA_R4_16PMP.h"
	//#endif
	
    /*********************************************************************
     * Hardware Configuration for 
     * PIC32_XXX_SK stacked on Ultima R4 board (SSD1963)
     * Graphics Controller is SSD1963
     * Display 4.3" - 7" TFT
     ********************************************************************/
	
	//#if defined (PIC32_GP_SK) || defined (PIC32_USB_SK) || defined (PIC32_ETH_SK)
		//#if defined (ULTIMA_R4_BOARD)
	      #include "Configs/HWP_PIC32_XXX_SK_ULTIMA_R4_16PMP.h"
		//#endif
	//#endif

#endif