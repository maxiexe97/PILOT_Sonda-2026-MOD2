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
#include "ADS7843.h"
//#include "DRV_SPI.h"

//const DRV_SPI_INIT_DATA SPI_Init_Data = {1, 1, 0, 0, 1, 1, 0};


void vInitADS7843(void){
     /*
      int rData;
	    //Inicializo los pines del SPI canal 1
	    TOUCH_CS_LAT = 1;
		TOUCH_CS_TRIS = PIN_OUTPUT;
        TOUCH_SCK_TRIS  = PIN_OUTPUT;
	    TOUCH_SDO_TRIS = PIN_OUTPUT;
	    TOUCH_SDI_TRIS = PIN_INPUT;

        DRV_SPI_Initialize(1, SPI_Init_Data);
        return;
	*/
	ADS7843_TRIS_CS=PIN_OUTPUT;
	ADS7843_TRIS_IRQ=PIN_INPUT;
	ADS7843_TRIS_CLK=PIN_OUTPUT;
	ADS7843_TRIS_SDO=PIN_INPUT;
	ADS7843_TRIS_SDI=PIN_OUTPUT;
 
	ADS7843_PIN_CS=1;
	ADS7843_PIN_SDI=0;
	ADS7843_PIN_CLK=0;
    
    
	
	return;
    
}
void vPuntosTouch2LCD(TOUCH_DATA *DataTouch, TOUCH_DATA *DataLCD){
    DataLCD->x=DataTouch->x;
    DataLCD->y=DataTouch->y;
}
/*****************************************************************/
/*
void vTestTouchPanel(TOUCH_DATA *Data){

	UINT16 TempX,TempY;
	UINT8 k;
   
	DelayMs(1);
	
	TempX=0;TempY=0;
	for(k=0;k<8;k++){
		TempX+=ADS7843WriteAndReadData(ADS7843_READ_X);
		TempY+=ADS7843WriteAndReadData(ADS7843_READ_Y); 
        
	}
	
 
	Data->x=(TempX>>3);
	Data->y=(TempY>>3);
	
	return;
    
}
*/
/*****************************************************************/
/*
void vTestTouchPanel(TOUCH_DATA *Data){
	UINT16 TempX,TempY, TempX1,TempY1, TempX2,TempY2;
	UINT8 k, data_inicial_final;
	
	//DelayMs(1);
	if(!ADS7843_PIN_IRQ){   //ejecuta este codigo solo cuando se toca la pantalla

    //if(data_inicial_final == 0){
    //   DelayMs(5);
    //   data_inicial_final = 1;
   // }
        //DelayMs(10);
    
ciclo:
	TempX=0;TempY=0;TempX1=0;TempY1=0;TempX2=0;TempY2=0;
	for(k=0;k<8;k++){
      if(!ADS7843_PIN_IRQ){   //ejecuta este codigo solo cuando se toca la pantalla

		TempX1+=ADS7843WriteAndReadData(ADS7843_READ_X);
		TempY1+=ADS7843WriteAndReadData(ADS7843_READ_Y);
       
	}
     else
    {
    Data->x=0;
	Data->y=0;
    return;
    }  
	}
    //DelayMs(50);
    for(k=0;k<8;k++){
      if(!ADS7843_PIN_IRQ){   //ejecuta este codigo solo cuando se toca la pantalla

		TempX2+=ADS7843WriteAndReadData(ADS7843_READ_X);
		TempY2+=ADS7843WriteAndReadData(ADS7843_READ_Y);
       
	}
     else
    {
    Data->x=0;
	Data->y=0;
    return;
    }  
	}
    if((abs(TempY1 = TempY2)<40)  || (abs(TempX1 - TempX2)<40)){   //40 estaba hace mucho
       //	Data->x=(TempX2>>3);
       //	Data->y=(TempY2>>3);
           TempX2 = (TempX2>>3);
           TempY2 = (TempY2>>3);
          if((0 <= TempX2 <= 4040) && (0 <= TempY2 <= 4040)){
	         Data->x = TempX2;
           	 Data->y = TempY2;
	          return;
          } 
         //   else
        //  {
        //    goto ciclo;
        //  }   
    }
     else
    {
    goto ciclo;
    }  
    
    }   
    else
    {
    data_inicial_final = 0;
    Data->x=0;
	Data->y=0;
    return;
    }  
}

*/
/*
void vTestTouchPanel(TOUCH_DATA *Data){
       //static	SHORT TempX = 0;
       //static	SHORT TempY = 0;
	
	//DelayMs(1);

          
                
	       // TempX=0; TempY=0;             
		                
		
                //DelayMs(1);
                
                //DelayMs(1);
                Data->y = (4096 - ADS7843WriteAndReadData(ADS7843_READ_Y));
                Data->x = ADS7843WriteAndReadData(ADS7843_READ_X);          
            
                //TempY = 4096 - TempY;
                            
                        
           	        //Data->y = TempY;
                        //Data->x = TempX;                       
                        return;
                 
     
    }   
    
*/

/*****************************************************************/

/*****************************************************************/

/*****************************************************************/
/*****************************************************************/
/*
UINT_COORDxy ADS7843WriteAndReadData(UINT8 Data){
UINT8 k;
UINT_COORDxy Temp;
ADS7843_PIN_CS=0;
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
// En cada flanco ascendente se toma el dato:43.
  for(k=0;k<8;k++){
  ADS7843_PIN_SDI=!!(Data&0x80);
//	__delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
	ADS7843_PIN_CLK=1;
//	__delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
	Data<<=1;
	ADS7843_PIN_CLK=0;
//    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
}
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
ADS7843_PIN_CLK=1;
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
ADS7843_PIN_CLK=0;
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
ADS7843_PIN_CLK=1;
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();

// En flanco descendente leemos data desde el ADS7843:
	Temp=0;

	for(k=0;k<12;k++){
	
		Temp<<=1;
		ADS7843_PIN_CLK=0;
		Temp+=ADS7843_PIN_SDO;
		__delay_CLK_ADS7843();
        __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
		ADS7843_PIN_CLK=1;
       __delay_CLK_ADS7843();
       __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
	}
	//__delay_CLK_ADS7843();
   // __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
	ADS7843_PIN_CLK=0;
    //__delay_CLK_ADS7843();
    //__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
	ADS7843_PIN_CS=1;
    __delay_CLK_ADS7843();
//    __delay_CLK_ADS7843();
//    __delay_CLK_ADS7843();
//    __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
	return(Temp);
}
*/


/*****************************************************************/

/*****************************************************************/
/*
void vTestTouchPanel(TOUCH_DATA *Data){
	UINT16 TempX,TempY, TempX1,TempY1, TempX2,TempY2;
	UINT8 k, data_inicial_final;
	
	//DelayMs(1);
	if(!ADS7843_PIN_IRQ){   //ejecuta este codigo solo cuando se toca la pantalla

    //if(data_inicial_final == 0){
    //   DelayMs(5);
    //   data_inicial_final = 1;
   // }
    
ciclo:
	TempX=0;TempY=0;TempX1=0;TempY1=0;TempX2=0;TempY2=0;
	for(k=0;k<8;k++){
      if(!ADS7843_PIN_IRQ){   //ejecuta este codigo solo cuando se toca la pantalla

		TempX1+=ADS7843WriteAndReadData(ADS7843_READ_X);
		TempY1+=ADS7843WriteAndReadData(ADS7843_READ_Y);
       
	}
     else
    {
    Data->x=0;
	Data->y=0;
    return;
    }  
	}
    //DelayMs(50);
    for(k=0;k<8;k++){
      if(!ADS7843_PIN_IRQ){   //ejecuta este codigo solo cuando se toca la pantalla

		TempX2+=ADS7843WriteAndReadData(ADS7843_READ_X);
		TempY2+=ADS7843WriteAndReadData(ADS7843_READ_Y);
       
	}
     else
    {
    Data->x=0;
	Data->y=0;
    return;
    }  
	}
    if((abs(TempY1 = TempY2)<10)  || (abs(TempX1 - TempX2)<10)){
	Data->x=(TempX2>>3);
	Data->y=(TempY2>>3);
	
	return;
    }
     else
    {
    goto ciclo;
    }  
    
    }   
    else
    {
    data_inicial_final = 0;
    Data->x=0;
	Data->y=0;
    return;
    }  
}
*/
/*****************************************************************/
/*****************************************************************/

UINT_COORDxy ADS7843WriteAndReadData(UINT8 Data){
UINT8 k;
UINT_COORDxy Temp;
ADS7843_PIN_CS=0;
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
// En cada flanco ascendente se toma el dato:43.
  for(k=0;k<8;k++){
  ADS7843_PIN_SDI=!!(Data&0x80);
//	__delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
	ADS7843_PIN_CLK=1;
//	__delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
	Data<<=1;
	ADS7843_PIN_CLK=0;
//    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
}
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
//__delay_CLK_ADS7843(); // Esperamos busy:
__delay_CLK_ADS7843(); // Esperamos busy:
ADS7843_PIN_CLK=1;
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
ADS7843_PIN_CLK=0;
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
ADS7843_PIN_CLK=1;
//__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
__delay_CLK_ADS7843();

// En flanco descendente leemos data desde el ADS7843:
	Temp=0;

	for(k=0;k<12;k++){
	
		Temp<<=1;
		ADS7843_PIN_CLK=0;
		Temp+=ADS7843_PIN_SDO;
		__delay_CLK_ADS7843();
        __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
		ADS7843_PIN_CLK=1;
       __delay_CLK_ADS7843();
       __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
	}
	//__delay_CLK_ADS7843();
    __delay_CLK_ADS7843();
__delay_CLK_ADS7843();
	ADS7843_PIN_CLK=0;
    //__delay_CLK_ADS7843();
    //__delay_CLK_ADS7843();
__delay_CLK_ADS7843();
	ADS7843_PIN_CS=1;
//    __delay_CLK_ADS7843();
//    __delay_CLK_ADS7843();
//    __delay_CLK_ADS7843();
//    __delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
//__delay_CLK_ADS7843();
	return(Temp);
}

/*****************************************************************/
/*****************************************************************/
