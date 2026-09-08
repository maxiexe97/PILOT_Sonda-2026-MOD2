

#ifndef __HARDWARE_PROFILE_H
    #define __HARDWARE_PROFILE_H

/*********************************************************************
* PIC Device Specific includes
*********************************************************************/
    #include "Compiler.h"

/*********************************************************************
* GetSystemClock() returns system clock frequency.
*
* GetPeripheralClock() returns peripheral clock frequency.
*
* GetInstructionClock() returns instruction clock frequency.
*
********************************************************************/

/*********************************************************************
* Macro: #define   GetSystemClock() 
*
* Overview: This macro returns the system clock frequency in Hertz.
*         * value is 8 MHz x 4 PLL for PIC24
*         * value is 8 MHz/2 x 18 PLL for PIC32
*
********************************************************************/
    #if defined(__PIC24F__)
        #define GetSystemClock()    (32000000ul)
    #elif defined(__PIC32MX__)
        #define GetSystemClock()    (80000000ul)
    #elif defined(__dsPIC33F__) || defined(__PIC24H__)
        #define GetSystemClock()    (80000000ul)
    #elif defined(__dsPIC33E__) || defined(__PIC24E__)
       #define GetSystemClock()    (120000000ul)
    #endif

/*********************************************************************
* Macro: #define   GetPeripheralClock() 
*
* Overview: This macro returns the peripheral clock frequency 
*         used in Hertz.
*         * value for PIC24 is <PRE>(GetSystemClock()/2) </PRE> 
*         * value for PIC32 is <PRE>(GetSystemClock()/(1<<OSCCONbits.PBDIV)) </PRE>
*
********************************************************************/
    #if defined(__PIC24F__) || defined(__PIC24H__) || defined(__dsPIC33F__) || defined(__dsPIC33E__) || defined(__PIC24E__)
        #define GetPeripheralClock()    (GetSystemClock() / 2)
    #elif defined(__PIC32MX__)
        #define GetPeripheralClock()    (GetSystemClock()) //** / (1 << OSCCONbits.PBDIV))
    #endif

/*********************************************************************
* Macro: #define   GetInstructionClock() 
*
* Overview: This macro returns instruction clock frequency 
*         used in Hertz.
*         * value for PIC24 is <PRE>(GetSystemClock()/2) </PRE> 
*         * value for PIC32 is <PRE>(GetSystemClock()) </PRE> 
*
********************************************************************/
    #if defined(__PIC24F__) || defined(__PIC24H__) || defined(__dsPIC33F__) || defined(__dsPIC33E__) || defined(__PIC24E__)
        #define GetInstructionClock()   (GetSystemClock() / 2)
    #elif defined(__PIC32MX__)
        #define GetInstructionClock()   (GetSystemClock())
    #endif

/* ################################################################## */
/*********************************************************************
* START OF GRAPHICS RELATED MACROS
********************************************************************/
/* ################################################################## */
//**
#define ULTIMA_R4_BOARD
//**
/*
**************************************************************************************************   
* PIC32_GP_SK / PIC32_USB_SK / PIC32_ETH_SK / EXPLORER_16 defines what mcu host to use.
* It is possible to stack any of the PIC32 starter kits or just using Explorer 16 as the host.
* This version assumes PIC32MX360F512L on Explorer 16, however, it is not a strict requirement.
* New driver can be developed with different MCU by following the schematic.
**************************************************************************************************   
*/
#define PIC32_ETH_SK
#define USE_16BIT_PMP
#ifdef USE_TY430TFT480272
#define GFX_DISPLAY_BUFFER_START_ADDRESS 0   //To support USE_DOUBLE_BUFFERING in GraphicsConfig.h, only valid for TY430TFT480272
#define GFX_DRV_PAGE_COUNT   4            //480*272*2*4 = 1,044,480 bytes
#define GFX_DISPLAY_BUFFER_LENGTH   GFX_REQUIRED_DISPLAY_BUFFER_SIZE_IN_BYTES 
#endif


/*********************************************************************
* HARDWARE DEVICES SELECTION
*********************************************************************/
#if defined (ULTIMA_R4_BOARD)
      #define   USE_SST25VF016
         #define   USE_BEEPER                        // use the PWM controlled beeper 
#endif

#if defined (USE_TY430TFT480272) || defined (USE_TY500TFT800480) || defined (USE_TY700TFT800480) || defined (USE_TY700TFT800480_R3)
        //**
      #define      USE_TOUCHSCREEN               //USE_TOUCHSCREEN defined in GraphicsConfig.h
        //**
          #define      USE_TOUCHSCREEN_RESISTIVE            // use 4-wire resistive touch screen driver
#endif

#if defined (USE_TY600TFT800480)
       #error TY600TFT not supported yet
#endif


/*********************************************************************
* STARTER KIT SPECIFIC MACROS (NOT USEFUL HERE)
*********************************************************************/

#ifdef PIC_SK
   #if defined (__PIC32MX__)
         #define PIC32_SK 
   #elif defined (__dsPIC33E__) || (__PIC24E__)
         #define dsPIC33E_SK
   #endif
#endif


// -----------------------------------
// For RGB GLASS
// -----------------------------------
#if defined (USE_TY430TFT480272)
   /*
   *********************************************************************
   * TIMING PARAMETERS FOR 4.3" TFT PANEL (480x272):
   * PART# TY430TFT480272
   *********************************************************************
   */
   /*********************************************************************
   * Overview: Horizontal and vertical display resolution
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_RESOLUTION            480
   #define DISP_VER_RESOLUTION            272
   /*********************************************************************
   * Overview: Image orientation (can be 0, 90, 180, 270 degrees).
   *********************************************************************/
   #define DISP_ORIENTATION            0
   /*********************************************************************
   * Overview: Panel Data Width
   *********************************************************************/
   #define DISP_DATA_WIDTH                 24
   /*********************************************************************
   * Overview: LSHIFT Polarity Swap
   * If defined LSHIFT is a falling trigger
   *********************************************************************/
   //#define DISP_INV_LSHIFT
   /*********************************************************************
   * Overview: Horizontal synchronization timing in pixels
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_PULSE_WIDTH      41  
   #define DISP_HOR_BACK_PORCH         2
   #define DISP_HOR_FRONT_PORCH      2   
   /*********************************************************************
   * Overview: Vertical synchronization timing in lines
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_VER_PULSE_WIDTH      10
   #define DISP_VER_BACK_PORCH         2   
   #define DISP_VER_FRONT_PORCH      2


   
   /*********************************************************************
   * Definition for SPI interface for SSD1963 
   * Hardware dependent!
   *********************************************************************/
   #define GPIO3 3
   #define GPIO2 2
   #define GPIO1 1
   #define GPIO0 0
   #define LCD_RESET (1<<GPIO0)      //LCD Reset signal (Reset for display panel, NOT ssd1963)
   #define LCD_SPENA   0
   #define LCD_SPCLK   0
   #define LCD_SPDAT   0
   /* End of definition for TY430TFT480272 */
#elif defined (USE_TY500TFT800480)
   /*
   *********************************************************************
   * TIMING PARAMETERS FOR 5" TFT PANEL (800x480):
   * PART# TY500TFT800480
   *********************************************************************
   */
   /*********************************************************************
   * Overview: Horizontal and vertical display resolution
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_RESOLUTION            800
   #define DISP_VER_RESOLUTION            480
   /*********************************************************************
   * Overview: Image orientation (can be 0, 90, 180, 270 degrees).
   *********************************************************************/
   #define DISP_ORIENTATION            0
   /*********************************************************************
   * Overview: Panel Data Width
   *********************************************************************/
   #define DISP_DATA_WIDTH                 24
   /*********************************************************************
   * Overview: LSHIFT Polarity Swap
   * If defined LSHIFT is a falling trigger
   *********************************************************************/
   //#define DISP_INV_LSHIFT
   /*********************************************************************
   * Overview: Horizontal synchronization timing in pixels
   *                  (from the glass datasheet).
   *********************************************************************/

   #define DISP_HOR_PULSE_WIDTH      128  
   #define DISP_HOR_BACK_PORCH         88
   #define DISP_HOR_FRONT_PORCH      40   

   /*********************************************************************
   * Overview: Vertical synchronization timing in lines
   *                  (from the glass datasheet).
   *********************************************************************/

   #define DISP_VER_PULSE_WIDTH      2
   #define DISP_VER_BACK_PORCH         25   
   #define DISP_VER_FRONT_PORCH      18


   /*********************************************************************
   * Definition for SPI interface for SSD1963 
   * Hardware dependent!
   *********************************************************************/
   #define GPIO3 3
   #define GPIO2 2
   #define GPIO1 1
   #define GPIO0 0
   #define LCD_RESET (1<<GPIO0)      //LCD Reset signal (Reset for display panel, NOT ssd1963)
   #define LCD_SPENA   0
   #define LCD_SPCLK   0
   #define LCD_SPDAT   0
   /* End of definition for DISPLAY_PANEL == TY500TFT800480 */
#elif defined (USE_TY700TFT800480)
   /*
   *********************************************************************
   * TIMING PARAMETERS FOR 7" TFT PANEL (800x480):
   * PART# TY700TFT800480
   * Reamrks:    By accident, a QA procedure for TY700TFT800480 discovered!
   *         Set all parameters as follows for a built-in display 
   *         R,G,B, and B&W spare pattern
   *      #define DISP_VER_PULSE_WIDTH      0
   *      #define DISP_VER_BACK_PORCH         0   
   *      #define DISP_VER_FRONT_PORCH      0
   *
   *      Normal operating values 
   *      #define DISP_VER_PULSE_WIDTH      1
   *      #define DISP_VER_BACK_PORCH         34   
   *      #define DISP_VER_FRONT_PORCH      10
   *********************************************************************
   */
   /*********************************************************************
   * Overview: Image orientation (can be 0, 90, 180, 270 degrees).
   *********************************************************************/   
     #define DISP_ORIENTATION    0
   /*********************************************************************
   * Overview: Panel Data Width (R,G,B) in (6,6,6)
   *********************************************************************/
   #define DISP_DATA_WIDTH                 18
   /*********************************************************************
   * Overview: Horizontal and vertical display resolution
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_RESOLUTION 800
   #define DISP_VER_RESOLUTION 480
   /*********************************************************************
   * Overview: Horizontal synchronization timing in pixels
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_PULSE_WIDTH      1
   #define DISP_HOR_BACK_PORCH         210
   #define DISP_HOR_FRONT_PORCH      45   
   /*********************************************************************
   * Overview: Vertical synchronization timing in lines
   *                  (from the glass datasheet).
   *********************************************************************/
   #if defined (TY700TFT_USE_QA_PATTERN)
      #define DISP_VER_PULSE_WIDTH      0
      #define DISP_VER_BACK_PORCH         0   
      #define DISP_VER_FRONT_PORCH      0
   #else
      #define DISP_VER_PULSE_WIDTH      1
      #define DISP_VER_BACK_PORCH         34   
      #define DISP_VER_FRONT_PORCH      10
   #endif

   /*********************************************************************
   * Definition for SPI interface for SSD1963 
   * Hardware dependent!
   *********************************************************************/
   #define GPIO3 3
   #define GPIO2 2
   #define GPIO1 1
   #define GPIO0 0
   #define LCD_RESET    0
   #define LCD_SPENA   0
   #define LCD_SPCLK   0
   #define LCD_SPDAT   0
   /* End of definition for TY700TFT800480 */
#elif defined (USE_TY700TFT800480_R3)
   /*
   *********************************************************************
   * TIMING PARAMETERS FOR 7" TFT PANEL (800x480) version 2 high lumin
   * PART# TY700TFT800480_R3
   *********************************************************************
   */
   /*********************************************************************
   * Overview: Horizontal and vertical display resolution
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_RESOLUTION            800
   #define DISP_VER_RESOLUTION            480
   /*********************************************************************
   * Overview: Image orientation (can be 0, 90, 180, 270 degrees).
   *********************************************************************/
   #define DISP_ORIENTATION            0
   /*********************************************************************
   * Overview: Panel Data Width
   *********************************************************************/
   #define DISP_DATA_WIDTH                 24
   /*********************************************************************
   * Overview: LSHIFT Polarity Swap
   * If defined LSHIFT is a falling trigger
   *********************************************************************/
   //#define DISP_INV_LSHIFT
   /*********************************************************************
   * Overview: Horizontal synchronization timing in pixels
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_HOR_PULSE_WIDTH      3 
   #define DISP_HOR_BACK_PORCH         88
   #define DISP_HOR_FRONT_PORCH      37   


   /*********************************************************************
   * Overview: Vertical synchronization timing in lines
   *                  (from the glass datasheet).
   *********************************************************************/
   #define DISP_VER_PULSE_WIDTH      3
   #define DISP_VER_BACK_PORCH         32   
   #define DISP_VER_FRONT_PORCH      10


   /*********************************************************************
   * Definition for SPI interface for SSD1963 
   * Hardware dependent!
   *********************************************************************/
   #define GPIO3 3
   #define GPIO2 2
   #define GPIO1 1
   #define GPIO0 0
   #define LCD_RESET (1<<GPIO0)      //LCD Reset signal (Reset for display panel, NOT ssd1963)
   #define LCD_SPENA   0
   #define LCD_SPCLK   0
   #define LCD_SPDAT   0
   /* End of definition for DISPLAY_PANEL == TY700TFT800480_R3 */

#endif   //end of definition of RGB glasses

/*********************************************************************
* HARDWARE PROFILE FOR DISPLAY CONTROLLER INTERFACE
*********************************************************************/
/*
*********************************************************************
* IO port definitions.
* Two board combinations: 
* (1) PIC32 starter kit on ULTIMA_R4       -or-  
* (2) Explorer 16 connected to ULTIMA_R4
* (3) PIC32MX360F512L EVK RD5B connected to SSD1963 Ultima EVK Rev4.1
*
* Function      mcu pins               SSD1963
* ==========   ========               ========
* TE         INT2/RE9               TE
* DATA LINES   PMD[15:0]               D[15:0] in 16-bit addressing
* RESET         RD1                     /RESET
* CHIP SELECT   PMPA0/RB15               /CS
* COMMAND/DATA   RD3                     RS 
* WR STROBE      RD4/PMPWR(1/3) or RD0(2)   /WR
* RD STROBE      RD5/PMPRD               /RD
*
*********************************************************************
*/

#if defined (ULTIMA_R4_BOARD)
   //Definitions for TE pin of SSD1963
   #define TE_TRIS_BIT         TRISEbits.TRISE9
   #define TE_PORT_BIT         PORTEbits.RE9
   #define RST_TRIS_BIT       TRISAbits.TRISA15
   #define RST_LAT_BIT        LATAbits.LATA15
   // Definitions for CS pin
   #define CS_TRIS_BIT        TRISDbits.TRISD10  //B14   //D10 ->Placa   //set digital under ResetDevice req.
   #define CS_LAT_BIT         LATDbits.LATD10    //B14     //D10        //it is AN15
   //Definition for RS pin
   #define RS_TRIS_BIT         TRISGbits.TRISG15   
   #define RS_LAT_BIT         LATGbits.LATG15    //G15      //G3    
   // Definition for RD pin
   #define RD_TRIS_BIT         TRISDbits.TRISD5
   #define RD_LAT_BIT         LATDbits.LATD5

   #if defined (EXPLORER_16)
   //   #define WR_TRIS_BIT         TRISDbits.TRISD0   //RD4 in Explorer 16 using for LCD2's E pin
   //   #define WR_LAT_BIT         LATDbits.LATD0
   #elif defined (PIC32_GP_SK) || defined (PIC32_USB_SK) || defined (PIC32_ETH_SK)   || defined (PIC32MX360F512L_EVK_RD5B)
      #define WR_TRIS_BIT         TRISDbits.TRISD4 
      #define WR_LAT_BIT         LATDbits.LATD4    //D4      //D11
   #endif

#endif

/*********************************************************************
* HARDWARE PROFILE FOR THE RESISTIVE TOUCHSCREEN 
*********************************************************************/
/*
   These are the hardware settings for the 4-wire resistive
   touch screen. There are two analog inputs and two digital I/Os
   needed. 
   
   This portion is divided into 3 components
   1. IO and ADC channels settings - sets up the IO pins used and the
      ADC channel selected to evaluate the screen touch. 
   2. Touch Screen X and Y orientation settings - sets up the
      x and y directions. This is dependent on how the resistive
      touch signals (X-, Y-, X+, and Y+) are wired up to the 
      IOs and ADC signals with respect to the orientation of the
      screen. Based on these factors, we can control the calculation
      of the touch by swapping x and/or y and flipping the x and/or y 
      directions.
   3. Touch Screen Non-Volatile Memory Storage Macros - this defines
      the non-volatile memory read, write and sector erase functions
      to be used when reading or storing calibration values.    
   
   The resistive touch screen driver assumes the following: 
   1. X+ and Y+ are mapped to the A/D inputs
   2. X- and Y- are mapped to the pure digital I/Os
*/


// ********************************************************************
// * HARDWARE PROFILE FOR THE POTENTIOMETER
// ********************************************************************
#define ADC_POT        ADC_CH0_POS_SAMPLEA_AN4
#define ADC_POT_PCFG   AD1PCFGbits.PCFG4
/*****************************************************************
*  ADC para las entradas de los sensores de presion
******************************************************************/
#define ADC_SENSOR_1        ADC_CH0_POS_SAMPLEA_AN1 
#define ADC_SENSOR_1_PCFG   AD1PCFGbits.PCFG1  
//****************************************************************/

/*****************************************************************
*  Salidas Digitales para la electrovalvula
******************************************************************/
       #define Electro_valvula_TRIS_BIT   TRISBbits.TRISB14     //B14 si es la electrovalvula
       #define Electro_valvula_LAT_BIT    LATBbits.LATB14         //B14
//***************************************************************//

/*****************************************************************
*  Salidas Digital para el calefactor
******************************************************************/
       #define Calefactor_TRIS_BIT   TRISDbits.TRISD14      //D14 vieja
       #define Calefactor_LAT_BIT    LATDbits.LATD14        //D14

//***************************************************************//
       #define Electro_IN_TRIS_BIT   TRISBbits.TRISB15      //
       #define Electro_IN_LAT_BIT    LATBbits.LATB15        //  
	   
//***************************************************************//
       #define BUZZER_TRIS_BIT   TRISBbits.TRISB12   // era b8   
       #define BUZZER_LAT_BIT    LATBbits.LATB12  

   	   #define DATO_TRIS_BIT   TRISFbits.TRISF5      //b11
       #define DATO_port       PORTFbits.RF5

  	   #define DATO2_TRIS_BIT   TRISFbits.TRISF4      //b11
       #define DATO2_port       PORTFbits.RF4

   /*********************************************************************
   * Touch Screen X and Y orientation
   *********************************************************************/
   /*********************************************************************
   Description:
      The usage of the resistive touch screen will be affected 
      by the way the hardware is mapped to the A/D channels that
      samples the touch. Since resistive touch is basically a 
      measurement of X and Y coordinates the following are macros
      that can modify the touch algorithm when sampling the 
      touch.
      TOUCHSCREEN_RESISTIVE_FLIP_X - will flip the x direction.    
      TOUCHSCREEN_RESISTIVE_FLIP_Y - will flip the y direction.
      TOUCHSCREEN_RESISTIVE_SWAP_XY - will swap the x and y sampling.
      
      As long as the (X-,Y-) and (X+,Y+) are used consistently,
      and connected properly in hardware, the macros above
      can provide options to the user to align the touch screen
      to the screen orientation.

        Another macro that may affect the way the x and y measurement 
        are the following:
        TOUCHSCREEN_RESISTIVE_PRESS_THRESHOLD - determines how light the 
            touch on the screen. The smaller the  value the lighter the 
            touch. Valid range of values: 0-0x03ff
        TOUCHSCREEN_RESISTIVE_CALIBRATION_SCALE_FACTOR - this is the scale
            factor used to calculate the touch coefficients. The equation 
            to calculate the scale factor is:
               (1 << TOUCHSCREEN_RESISTIVE_CALIBRATION_SCALE_FACTOR).
            Valid values: 0 - 15 (most resistive touch screens will work 
                                  in the range of 5 - 7)

   *********************************************************************/

#if defined (USE_TY430TFT480272) || defined (USE_TY500TFT800480) || defined (USE_TY700TFT800480) || defined (USE_TY700TFT800480_R3)
         #if (DISP_ORIENTATION == 0)
         #elif (DISP_ORIENTATION == 180)   
            #error DISP_ORIENTATION 180 DEG not supported yet
         #elif (DISP_ORIENTATION == 270)   
            #error DISP_ORIENTATION 270 DEG not supported yet
         #endif
#endif

   /*********************************************************************
   * Touch Screen Non-Volatile Memory Storage Macros
   *********************************************************************/
   /* ----------------------------------------- */
   #if defined (USE_MCHP25LC256)  
   /* ----------------------------------------- */
      // for  MCHP25LC256 serial EEPROM or AT25256 serial EEPROM
      // Addresses for calibration and version values in EEPROM on MMEVK R1A / ULTIMA
        #define ADDRESS_RESISTIVE_TOUCH_VERSION (unsigned)0x7FFE
        #define ADDRESS_RESISTIVE_TOUCH_COEFA   (unsigned)0x7FFC
        #define ADDRESS_RESISTIVE_TOUCH_COEFB   (unsigned)0x7FFA
        #define ADDRESS_RESISTIVE_TOUCH_COEFC   (unsigned)0x7FF8
        #define ADDRESS_RESISTIVE_TOUCH_COEFD   (unsigned)0x7FF6

        // define the functions to call for the non-volatile memory
        // check out touch screen module for definitions of the following function pointers
        // used: NVM_READ_FUNC, NVM_WRITE_FUNC & NVM_SECTORERASE_FUNC
      #define NVMSectorErase               ((NVM_SECTORERASE_FUNC)0)
       #define NVMWrite                   ((NVM_WRITE_FUNC)&MCHP25LC256WriteWord)
       #define NVMRead                   ((NVM_READ_FUNC)&MCHP25LC256ReadWord)

   #elif defined (USE_SST25VF016) || defined (USE_M25P80)
      // Addresses for calibration and version values in SPI Flash on ULTIMA_R4 board
        #define ADDRESS_RESISTIVE_TOUCH_VERSION   (unsigned long)0xFFFFFFFE
        #define ADDRESS_RESISTIVE_TOUCH_COEFA   (unsigned long)0xFFFFFFFC
        #define ADDRESS_RESISTIVE_TOUCH_COEFB   (unsigned long)0xFFFFFFFA
        #define ADDRESS_RESISTIVE_TOUCH_COEFC   (unsigned long)0xFFFFFFF8
        #define ADDRESS_RESISTIVE_TOUCH_COEFD   (unsigned long)0xFFFFFFF6

        // define the functions to call for the non-volatile memory
        // check out touch screen module for definitions of the following function pointers
        // used: NVM_READ_FUNC, NVM_WRITE_FUNC & NVM_SECTORERASE_FUNC
   #define NVMSectorErase               ((NVM_SECTORERASE_FUNC)&SST25SectorErase)
       #define NVMWrite                   ((NVM_WRITE_FUNC)&SST25WriteWord)
       #define NVMRead                   ((NVM_READ_FUNC)&SST25ReadWord)

   #endif

/*********************************************************************
* HARDWARE PROFILE FOR THE SPI FLASH MEMORY
*********************************************************************/
/*
   These are the hardware settings for the SPI peripherals used.
*/
#if defined (USE_MCHP25LC256) 

    /*********************************************************************
   * Serial Bus SPI EEPROM (MCHP 25LC256) On MMEVK R1A / ULTIMA
   *********************************************************************/
    /* Define all the SPI channels that will be used here.
       These will be used to determine how the SPI Driver (drv_spi)
       will be compiled.
    */
/*
   #define MCHP25LC256_SPI_CHANNEL 1
   #define SPI_CHANNEL_1_ENABLE
   // CS signal definition
   #define MCHP25LC256_CS_TRIS       TRISDbits.TRISD9
    #define MCHP25LC256_CS_LAT        LATDbits.LATD9
    // Clock, SDO and SDI signals
   #if defined (__32MX360F512L__)
   #define MCHP25LC256_SCK_TRIS      TRISFbits.TRISF6
   #define MCHP25LC256_SDO_TRIS      TRISFbits.TRISF8
   #define MCHP25LC256_SDI_TRIS      TRISFbits.TRISF7
   #elif defined (__32MX795F512L__) || defined (__32MX460F512L__)
   #define MCHP25LC256_SCK_TRIS      TRISDbits.TRISD10
   #define MCHP25LC256_SDO_TRIS      TRISDbits.TRISD0
   #define MCHP25LC256_SDI_TRIS      TRISCbits.TRISC4
   #endif
*/
#elif defined (USE_SST25VF016) || defined (USE_M25P80)
    /*********************************************************************
   * Serial Bus SPI Flash (SST25VF016 or compatible M25P80) On ULTIMA_R4
   *********************************************************************/
    /* Define all the SPI channels that will be used here.
       These will be used to determine how the SPI Driver (drv_spi)
       will be compiled.
    */
   #define SST25_SPI_CHANNEL   1

    #if (SST25_SPI_CHANNEL == 1)
        #define SPI_CHANNEL_1_ENABLE
    #elif (SST25_SPI_CHANNEL == 2)
        #define SPI_CHANNEL_2_ENABLE
    #elif (SST25_SPI_CHANNEL == 3)
        #define SPI_CHANNEL_3_ENABLE
    #elif (SST25_SPI_CHANNEL == 4)
        #define SPI_CHANNEL_4_ENABLE
    #endif

   
   #define SST25_CS_TRIS        TRISDbits.TRISD9
    #define SST25_CS_LAT         LATDbits.LATD9

   #if defined (__32MX360F512L__)
   #define SST25_SCK_TRIS      TRISFbits.TRISF6
   #define SST25_SDO_TRIS      TRISFbits.TRISF8
   #define SST25_SDI_TRIS      TRISFbits.TRISF7
   #elif defined (__32MX795F512L__) || defined (__32MX460F512L__)
   #define SST25_SCK_TRIS      TRISDbits.TRISD10
   #define SST25_SDO_TRIS      TRISDbits.TRISD14    //D0
   #define SST25_SDI_TRIS      TRISCbits.TRISC4
   #endif
#endif

/*********************************************************************
* IO FOR THE BEEPER
*********************************************************************/
#if defined (USE_BEEPER)
        #define BEEP_TRIS_BIT   TRISDbits.TRISD0 
        #define BEEP_LAT_BIT    LATDbits.LATD0

 //      #define BEEP_TRIS_BIT   TRISBbits.TRISB8   // PARA QUE SUENE BUZZER
  //     #define BEEP_LAT_BIT    LATBbits.LATB8  


        #define SALIDA_BEEPER_TRIS_BIT                 TRISDbits.TRISD0     //F12
        #define SALIDA_BEEPER_pin                      LATDbits.LATD0        //F12
#endif



#endif
