/**
   \version: 1.0

   
   \author Suky
   \web www.micros-designs.com.ar
   \date 19/11/11


///////////////////////////////////////////////////////////////////////////
////                                                                   ////
////                                                                   ////
////        (C) Copyright 2011 www.micros-designs.com.ar               ////
//// Este código puede ser usado, modificado y distribuido libremente  ////
//// sin eliminar esta cabecera y  sin garantía de ningún tipo.        ////
////                                                                   ////
////                                                                   ////
/////////////////////////////////////////////////////////////////////////// 
   
 *- Version Log --------------------------------------------------------------*
 *   Fecha       Autor                Comentarios                             *
 *----------------------------------------------------------------------------*
 * 19/11/11      Suky               Original (Rev 1.0)                        *
 *----------------------------------------------------------------------------* */
#ifndef _ADS7843_H_
	#define _ADS7843_H_
/*
#include <p32xxxx.h>
#include <plib.h>
#include "GenericTypeDefs.h"
#include "TimeDelay.h"

#define ADS7843_PIN_CS		LATCbits.LATC2 	// Salida
#define ADS7843_PIN_IRQ		PORTAbits.RA14	// Entrada
#define ADS7843_PIN_CLK		LATCbits.LATC1	// Salida
#define ADS7843_PIN_SDO		PORTCbits.RC4	// Entrada
#define ADS7843_PIN_SDI		LATCbits.LATC3	// Salida
 
#define ADS7843_TRIS_CS		TRISCbits.TRISC2
#define ADS7843_TRIS_IRQ	TRISAbits.TRISA14
#define ADS7843_TRIS_CLK	TRISCbits.TRISC1
#define ADS7843_TRIS_SDO	TRISCbits.TRISC4
#define ADS7843_TRIS_SDI	TRISCbits.TRISC3
 
#define __delay_CLK_ADS7843()	{Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();} // 1uS -> 80 MHz


//#define __delay_CLK_ADS7843()	{Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();}
                                


#define ADS7843_USE_12BITS

#if defined(ADS7843_USE_12BITS)
	#define ADS7843_READ_X		0b11010000 // IRQ Enable, realiza una sola conversion y 
	#define ADS7843_READ_Y      0b10010000//  espera hasta que se le manda de nuevo este dato


	

    #define ADS7843_READ_X_IRQ_OFF		0b11010011 // IRQ Disable, realiza conversion continua
	#define ADS7843_READ_Y_IRQ_OFF		0b10010011

    typedef	WORD				UINT_COORDxy;

#else
	#define ADS7843_READ_X		0b10011000 // IRQ Enable	 
	#define ADS7843_READ_Y		0b11011000
    typedef	UINT8				UINT_COORDxy;
#endif
 
#define PIN_INPUT	1
#define PIN_OUTPUT	0
 
typedef struct{
	UINT_COORDxy	x;
	UINT_COORDxy	y;
}TOUCH_DATA;

 


void vInitADS7843(void);
UINT_COORDxy ADS7843WriteAndReadData(UINT8);
void vTestTouchPanel(TOUCH_DATA *Data);
void vPuntosTouch2LCD(TOUCH_DATA *DataTouch, TOUCH_DATA *DataLCD);
*/

#include <p32xxxx.h>
#include <plib.h>
#include "GenericTypeDefs.h"
#include "TimeDelay.h"

#define ADS7843_PIN_CS		LATCbits.LATC2 	// Salida
#define ADS7843_PIN_IRQ		PORTAbits.RA14	// Entrada
#define ADS7843_PIN_CLK		LATCbits.LATC1 //C1 ->Placa  //C1 -> Starter Kit	// Salida
#define ADS7843_PIN_SDO		PORTCbits.RC4  //C4 ->Placa  //C4 -> Starter Kit	// Entrada
#define ADS7843_PIN_SDI		LATCbits.LATC3 //C3 ->Placa  //C3 -> Starter Kit	// Salida
 
#define ADS7843_TRIS_CS		TRISCbits.TRISC2
#define ADS7843_TRIS_IRQ	TRISAbits.TRISA14
#define ADS7843_TRIS_CLK	TRISCbits.TRISC1 //C1  //C1
#define ADS7843_TRIS_SDO	TRISCbits.TRISC4 //C4  //C4
#define ADS7843_TRIS_SDI	TRISCbits.TRISC3 //C3  //C3
 
#define __delay_CLK_ADS7843()	{Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
								Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();} // 1uS -> 80 MHz, cada NOP = 12.5nS.

//#define __delay_CLK_ADS7843()	{Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();}

#define _delay_CLK_XPT2046_200nS()	{Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();\
                                     Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();} //200nS, cada NOP = 12.5nS si el micro trabaja a 80MHz.

#define _delay_CLK_XPT2046_50nS()	{Nop();Nop();Nop();Nop();}//50nS, cada NOP = 84nS si el micro trabaja a 80MHz.
                                


#define ADS7843_USE_12BITS

#if defined(ADS7843_USE_12BITS)
	#define ADS7843_READ_X		0b11010100 // IRQ Enable
	#define ADS7843_READ_Y		0b10010100

    //#define ADS7843_READ_X_IRQ_OFF		0b11010011 // IRQ Disable
//	#define ADS7843_READ_Y_IRQ_OFF		0b10010011
		
    typedef	WORD				UINT_COORDxy;
#else
	//#define ADS7843_READ_X		0b10011000 // IRQ Enable	 
	//#define ADS7843_READ_Y		0b11011000
    //typedef	UINT8				UINT_COORDxy;
#endif
 
#define PIN_INPUT	1
#define PIN_OUTPUT	0
 
typedef struct{
	UINT_COORDxy	x;
	UINT_COORDxy	y;
}TOUCH_DATA;

//volatile BOOL kbhit_tratament=0;
 
void vInitADS7843(void);
UINT_COORDxy ADS7843WriteAndReadData(UINT8);
void vTestTouchPanel(TOUCH_DATA *Data);

#endif
