
#ifndef _SSD1963_H
#define _SSD1963_H

#ifdef __PIC32MX
	#include <plib.h>
	#define PMDIN1   PMDIN
#elif defined __dsPIC33F__
	#include <p33Fxxxx.h>
#elif defined __PIC24H__
	#include <p24Hxxxx.h>
#elif defined __PIC24F__
	#include <p24Fxxxx.h>
#else
	#error CONTROLLER IS NOT SUPPORTED
#endif

//include the command table for SSD1963
#include "SSD1963_CMD.h"
#include "Graphics\DisplayDriver.h"



/*********************************************************************
* PARAMETERS VALIDATION
*********************************************************************/
#if COLOR_DEPTH != 16
#error This driver supports 16 BPP only.
#endif

#if (DISP_HOR_RESOLUTION % 8) != 0
#error Horizontal resolution must be divisible by 8.
#endif

#if (DISP_ORIENTATION != 0) && (DISP_ORIENTATION != 180) && (DISP_ORIENTATION != 90) && (DISP_ORIENTATION != 270)
#error The display orientation selected is not supported. It can be only 0,90,180 or 270.
#endif

/*********************************************************************
* ADD SUPPORT FOR DOUBLE BUFFERING
*********************************************************************/
// Calculate Display Buffer Size required in bytes
#define GFX_DISPLAY_PIXEL_COUNT ((DWORD)DISP_HOR_RESOLUTION*DISP_VER_RESOLUTION)

#if (COLOR_DEPTH == 16)
    #define GFX_REQUIRED_DISPLAY_BUFFER_SIZE_IN_BYTES       (GFX_DISPLAY_PIXEL_COUNT*2)
#elif (COLOR_DEPTH == 8)
    #define GFX_REQUIRED_DISPLAY_BUFFER_SIZE_IN_BYTES       (GFX_DISPLAY_PIXEL_COUNT)
#elif (COLOR_DEPTH == 4)
    #define GFX_REQUIRED_DISPLAY_BUFFER_SIZE_IN_BYTES       (GFX_DISPLAY_PIXEL_COUNT/2)
#elif (COLOR_DEPTH == 1)
    #define GFX_REQUIRED_DISPLAY_BUFFER_SIZE_IN_BYTES       (GFX_DISPLAY_PIXEL_COUNT/8)
#endif


typedef struct
{
    WORD X;
    WORD Y;
    WORD W;
    WORD H;
} RectangleArea;

#if defined (USE_DOUBLE_BUFFERING)
	#define GFX_MAX_INVALIDATE_AREAS 5
    #define GFX_BUFFER1 (GFX_DISPLAY_BUFFER_START_ADDRESS)
    #define GFX_BUFFER2 (GFX_DISPLAY_BUFFER_START_ADDRESS + GFX_REQUIRED_DISPLAY_BUFFER_SIZE_IN_BYTES)
#endif

/*********************************************************************
* Macros: SetPalette(colorNum, color)
*
* Overview:  Sets palette register.
*
* PreCondition: none
*
* Input: colorNum - Register number.
*        color - Color.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetPalette(colorNum, color)


/*********************************************************************
* Function:  SetScrollArea(SHORT top, SHORT scroll, SHORT bottom)
*
* PreCondition: none
*
* Input: top - Top Fixed Area in number of lines from the top
*				of the frame buffer
*		 scroll - Vertical scrolling area in number of lines
*		 bottom - Bottom Fixed Area in number of lines
*
* Output: none
*
* Side Effects: none
*
* Overview:
*
* Note: Reference: section 9.22 Set Scroll Area, SSD1963 datasheet Rev0.20
*
********************************************************************/
void SetScrollArea(SHORT top, SHORT scroll, SHORT bottom);

/*********************************************************************
* Function:  void  SetScrollStart(SHORT line)
*
* Overview: First, we need to define the scrolling area by SetScrollArea()
*			before using this function. 
*
* PreCondition: SetScrollArea(SHORT top, SHORT scroll, SHORT bottom)
*
* Input: line - Vertical scrolling pointer (in number of lines) as 
*		 the first display line from the Top Fixed Area defined in SetScrollArea()
*
* Output: none
*
* Note: Example -
*
*		SHORT line=0;
*		SetScrollArea(0,272,272);
*		for(line=0;line<272;line++) {SetScrollStart(line);DelayMs(100);}
*		
*		Code above scrolls the whole page upwards in 100ms interval 
*		with page 2 replacing the first page in scrolling
********************************************************************/
void SetScrollStart(SHORT line);

/*********************************************************************
* Function:  void EnterSleepMode (void)
* PreCondition: none
* Input:  none
* Output: none
* Side Effects: none
* Overview: SSD1963 enters sleep mode
* Note: Host must wait 5mS after sending before sending next command
********************************************************************/
void EnterSleepMode (void);

/*********************************************************************
* Function:  void ExitSleepMode (void)
* PreCondition: none
* Input:  none
* Output: none
* Side Effects: none
* Overview: SSD1963 exits sleep mode
* Note:   cannot be called sooner than 15ms
********************************************************************/
void ExitSleepMode (void);

/*********************************************************************
* Function		: void DisplayOff(void)
* PreCondition	: none
* Input			: none
* Output		: none
* Side Effects	: none
* Overview		: SSD1963 changes the display state to OFF state
* Note			: none
********************************************************************/
void DisplayOff(void);

/*********************************************************************
* Function		: void DisplayOn(void)
* PreCondition	: none
* Input			: none
* Output		: none
* Side Effects	: none
* Overview		: SSD1963 changes the display state to ON state
* Note			: none
********************************************************************/
void DisplayOn(void);

/*********************************************************************
* Function		: void EnterDeepSleep(void)
* PreCondition	: none
* Input			: none
* Output		: none
* Side Effects	: none
* Overview		: SSD1963 enters deep sleep state with PLL stopped
* Note			: none
********************************************************************/
void EnterDeepSleep(void);

/*********************************************************************
* Function:  void  SetBacklight(BYTE intensity)
*
* Overview: This function makes use of PWM feature of ssd1963 to adjust
*			the backlight intensity. 
*
* PreCondition: Backlight circuit with shutdown pin connected to PWM output of ssd1963.
*
* Input: 	(BYTE) intensity from 
*			0x00 (total backlight shutdown, PWM pin pull-down to VSS)
*			0xff (99% pull-up, 255/256 pull-up to VDD)
*
* Output: none
*
* Note: The base frequency of PWM set to around 300Hz with PLL set to 120MHz.
*		This parameter is hardware dependent
********************************************************************/
void SetBacklight(BYTE intensity);

/*********************************************************************
* Function:  void  SetTearingCfg(BOOL state, BOOL mode)
*
* Overview: This function enable/disable tearing effect
*
* PreCondition: none
*
* Input: 	BOOL state -	1 to enable
*							0 to disable
*			BOOL mode -		0:  the tearing effect output line consists
*								of V-blanking information only
*							1:	the tearing effect output line consists
*								of both V-blanking and H-blanking info.
* Output: none
*
* Note:
********************************************************************/
void SetTearingCfg(BOOL state, BOOL mode);


/************************************************************************
* Macro: Lo                                                             *
* Preconditions: None                                                   *
* Overview: This macro extracts a low byte from a 2 byte word.          *
* Input: None.                                                          *
* Output: None.                                                         *
************************************************************************/
#define Lo(X)   (BYTE)(X&0x00ff)

/************************************************************************
* Macro: Hi                                                             *
* Preconditions: None                                                   *
* Overview: This macro extracts a high byte from a 2 byte word.         *
* Input: None.                                                          *
* Output: None.                                                         *
************************************************************************/
#define Hi(X)   (BYTE)((X>>8)&0x00ff)


#endif // _SSD1963_H
