
/***************************************************
*INCLUDE FILES
***************************************************/
#include "Graphics/Graphics.h"
//#include "GDD_Screens.h"
#include "Touch_Pilot_7/GDD_Screens.h"
//#include "Touch_Pilot_7/GDD_X_Event_Handler.h"


/* -----------------------------------------------------------------
 * COLORES DE PALETA  (usados en ambas funciones)
 * ----------------------------------------------------------------- */
#define COL_BG          RGBConvert(  5,   8,  16)   // fondo general
#define COL_PANEL       RGBConvert( 10,  15,  30)   // relleno de paneles
#define COL_BORDER      RGBConvert( 10,  58, 110)   // borde cian oscuro
#define COL_ACCENT      RGBConvert(  0, 200, 255)   // cian brillante
#define COL_ACCENT2     RGBConvert(  0,  85, 204)   // cian medio
#define COL_GREEN       RGBConvert(  0, 220, 120)   // verde (flujo)
#define COL_ORANGE      RGBConvert(255, 140,   0)   // naranja (temp)
#define COL_BLACK_DEEP  RGBConvert(  0,   3,   8)   // receso interno
#define COL_INNER_BRD   RGBConvert( 10,  26,  42)   // borde receso
#define COL_WHITE       RGBConvert(255, 255, 255)
#define COL_DIM         RGBConvert( 58,  90, 122)   // texto apagado
#define COL_HDR_BG      RGBConvert(  2,  10,  24)   // header
/***************************************************
* String literals used in the project
***************************************************/
const XCHAR ventana_inicio_BTN_60text[ ] = ".";

const XCHAR ventana_inicio_OTE_3text[ ] = "Iniciar equipo";

const XCHAR ventana_1_BTN_37text[ ] = "LED 1";
const XCHAR ventana_1_BTN_38text[ ] = "LED 2";
const XCHAR ventana_1_BTN_48text[ ] = ".";
const XCHAR ventana_1_BTN_49text[ ] = ".";
const XCHAR ventana_1_BTN_50text[ ] = ".";
const XCHAR ventana_1_BTN_51text[ ] = ".";
const XCHAR ventana_1_BTN_64text[ ] = ".";
const XCHAR ventana_1_CHB_27text[ ] = "LED 2";
const XCHAR ventana_1_CHB_28text[ ] = "LED 1";
const XCHAR ventana_1_STE_29text[ ] = "Med";
const XCHAR ventana_1_STE_30text[ ] = "27";
const XCHAR ventana_1_BTN_28text[ ] = "Start";
const XCHAR ventana_1_BTN_Stoptext[ ] = "Stop";

/***************************************************
* Scheme Declarations
***************************************************/
GOL_SCHEME* defscheme;
GOL_SCHEME* Pilot_scheme;
GOL_SCHEME* Pilot_scheme_1;
GOL_SCHEME* Check_Box_Scheme;
GOL_SCHEME* Digital_Meter_Scheme;
GOL_SCHEME* Pilot_Gradiente_Scheme;
GOL_SCHEME* Boton_Start_scheme;
GOL_SCHEME* Boton_Stop_scheme;
GOL_SCHEME* Barra_Flot_Scheme;
GOL_SCHEME* Flechas_Pilot_scheme;
GOL_SCHEME* Flechas_Pilot_scheme2;
GOL_SCHEME* Alarma_scheme;
GOL_SCHEME* Pilot_off;
GOL_SCHEME* Pilot_off1;
GOL_SCHEME* Pilot_off2;
GOL_SCHEME* Boton_Eco_scheme;
/***************************************************
* Function and global Declarations
***************************************************/
extern int volumen;
extern void Dibujar_icono_CO2(int cx, int cy, int r, int g, int b);

void (*CreateFunctionArray[NUM_GDD_SCREENS])();
void (*CreatePrimitivesFunctionArray[NUM_GDD_SCREENS])();
//**WORD currentGDDDemoScreenIndex;
BYTE update = 0;
static BYTE updateGPL = 0;

/***************************************************
* Function       : GDDDemoCreateFirstScreen
* Parameters     : none
* Return         : none
* Description    : Creates the first screen
***************************************************/
void GDDDemoCreateFirstScreen(void)
{
    currentGDDDemoScreenIndex = 0;
    update = 1;
    (*CreateFunctionArray[currentGDDDemoScreenIndex])();
}

/***************************************************
* Function      : GDDDemoNextScreen
* Parameters    : none
* Return        : none
* Description   : Updates counter to show next screen
***************************************************/
void GDDDemoNextScreen(void)
{
    currentGDDDemoScreenIndex++;
    if(currentGDDDemoScreenIndex >= NUM_GDD_SCREENS)
    {
        currentGDDDemoScreenIndex = 0;
    }
    update = 1;
}



/***************************************************
* Function      : GDDDemoGoToScreen
* Parameters    : int screenIndex
* Return        : none
* Description   : Show the screen referred by the index
***************************************************/
void GDDDemoGoToScreen(int screenIndex)
{
    currentGDDDemoScreenIndex = screenIndex;
    if(currentGDDDemoScreenIndex >= NUM_GDD_SCREENS)
    {
        currentGDDDemoScreenIndex = 0;
    }
    update = 1;
}

/***************************************************
* Function       : GDDDemoGOLDrawCallback
* Parameters     : none
* Return         : none
* Description    : Callback to do the actual drawing of widgets
***************************************************/
void GDDDemoGOLDrawCallback(void)
{
    if(updateGPL)
    {
        (*CreatePrimitivesFunctionArray[currentGDDDemoScreenIndex])();
        updateGPL = 0;
    }

    if(update)
    {
         
        (*CreateFunctionArray[currentGDDDemoScreenIndex])();
        if(CreatePrimitivesFunctionArray[currentGDDDemoScreenIndex] != NULL)
        {
            updateGPL = 1;
        }
        update = 0;
    }
    //return (1);
    
}

/***************************************************
* Function       : CreateError
* Parameters     : none
* Return         : none
* Description    : Creates a Error screen 
***************************************************/
void CreateError(char* string)
{
    // Blue Screen Error
    //SetColor(119);
    SetColor(BLUE);
    ClearDevice();
    //SetColor(-1);
    SetColor(WHITE);
    // Flash Error Message
    if(string == NULL)
        {OutTextXY(0, 0, "Runtime Error.");
        while(1);
    }
    else
        {OutTextXY(0,0, "Error inesperado");
    while(1);
}
}

/***************************************************
* Function 	      :    Createventana_inicio
* Parameters      :    none
* Return          :    none
* Description     :    Creates GOL widgets used in screen - ventana_inicio
***************************************************/
void Createventana_inicio(void)
{
    GOLFree();
    //SetColor(RGBConvert(0, 0, 255));
    //ClearDevice();

    #ifdef USE_TRANSPARENT_COLOR
    TransparentColorEnable(RGBConvert(0x82, 0x7F, 0x00)); // Color [R=130, G=127, B=0]
    #endif

    #ifdef USE_GRADIENT
    // Gradient Screen7_Gradient5
    //while(!BevelGradient(0, 0, 800, 480, 0,(0, 0, 0),(0, 0, 255), 100, 6));
    #endif


     if(Pilot_scheme != NULL) free(Pilot_scheme);
        Pilot_scheme = GOLCreateScheme();

    Pilot_scheme->Color0 = RGBConvert(0, 48, 248);
    Pilot_scheme->Color1 = RGBConvert(248, 0, 48);
    Pilot_scheme->TextColor0 = RGBConvert(248, 252, 248);
    Pilot_scheme->TextColor1 = RGBConvert(248, 252, 248);
    Pilot_scheme->EmbossDkColor = RGBConvert(200, 204, 248);
    Pilot_scheme->EmbossLtColor = RGBConvert(24, 116, 184);
    Pilot_scheme->TextColorDisabled = RGBConvert(128, 128, 128);
    Pilot_scheme->ColorDisabled = RGBConvert(208, 224, 240);
    Pilot_scheme->CommonBkColor = RGBConvert(96, 100, 248);
    Pilot_scheme->pFont = (void*)&Gentium_16;
    
    #ifdef USE_GRADIENT
    Pilot_scheme->gradientScheme.gradientType=GRAD_DOUBLE_HOR; //GRAD_DOUBLE_HOR;
    Pilot_scheme->gradientScheme.gradientStartColor=10; // Color [R=0, G=0, B=255]
    Pilot_scheme->gradientScheme.gradientEndColor=800; // Color [R=255, G=255, B=0]
    Pilot_scheme->gradientScheme.gradientLength=90;
    #endif



}
/***************************************************
* Function 	      :    Createventana_1
* Parameters      :    none
* Return          :    none
* Description     :    Creates GOL widgets used in screen - ventana_1
***************************************************/
void Createventana_1(void)
{

flag_sobre_presion==0;
  
X = GetMaxX()-GetImageWidth((void*)&LOGO_1);
Y = GetMaxY()-GetImageHeight((void*)&LOGO_1);
//put bitmap in the center
char stretch = IMAGE_NORMAL;

SetColor(RGBConvert(5, 5, 5));
   FillBevel(0, 0, 799, 480, 1);
PutImage((X >>1),(Y >> 1), &LOGO_1, stretch);

	  DelayMs(2000);  

    GOLFree();
    //SetColor(RGBConvert(0, 0, 248));
    //ClearDevice();

    #ifdef USE_TRANSPARENT_COLOR
    TransparentColorEnable(RGBConvert(0x82, 0x7F, 0x00)); // Color [R=130, G=127, B=0]
    #endif

    #ifdef USE_GRADIENT
    // Gradient Screen7_Gradient5
    while(!BevelGradient(0, 0, 800, 480, 0,(0, 0, 0),(0, 0, 0), 100, 6));
    #endif

  if(Boton_Start_scheme != NULL) free(Boton_Start_scheme);
        Boton_Start_scheme = GOLCreateScheme();

 	Boton_Start_scheme->Color0 = RGBConvert(0, 255, 255);
    Boton_Start_scheme->Color1 = RGBConvert(0, 255, 255);
    Boton_Start_scheme->TextColor0 = RGBConvert(0, 0, 0);
    Boton_Start_scheme->TextColor1 = RGBConvert(10, 10, 10);
    Boton_Start_scheme->EmbossDkColor = RGBConvert(100, 100, 100);
    Boton_Start_scheme->EmbossLtColor = RGBConvert(255, 255, 255);
    Boton_Start_scheme->TextColorDisabled = RGBConvert(128, 128, 128);
    Boton_Start_scheme->ColorDisabled = RGBConvert(208, 224, 240);
    Boton_Start_scheme->CommonBkColor = TAN;
    Boton_Start_scheme->pFont = (void*)&Gentium_72;

    #ifdef USE_GRADIENT
    Boton_Start_scheme->gradientScheme.gradientType=GRAD_DOUBLE_HOR; //GRAD_DOUBLE_HOR;
    Boton_Start_scheme->gradientScheme.gradientStartColor=RGBConvert(255, 255, 255); // Color [R=0, G=0, B=255]
    Boton_Start_scheme->gradientScheme.gradientEndColor=RGBConvert(255, 255, 255);; // Color [R=255, G=255, B=0]
    Boton_Start_scheme->gradientScheme.gradientLength=50;
    #endif	  


      if(Pilot_scheme != NULL) free(Pilot_scheme);
        Pilot_scheme = GOLCreateScheme();


    Pilot_scheme->Color0 = RGBConvert(0, 255, 255);
    Pilot_scheme->Color1 = RGBConvert(0, 255, 255);
    Pilot_scheme->TextColor0 = RGBConvert(0, 0, 0);
    Pilot_scheme->TextColor1 = RGBConvert(10, 10, 10);
    Pilot_scheme->EmbossDkColor = RGBConvert(100, 100, 100);
    Pilot_scheme->EmbossLtColor = RGBConvert(255, 255, 255);
    Pilot_scheme->TextColorDisabled = RGBConvert(128, 128, 128);
    Pilot_scheme->ColorDisabled = RGBConvert(208, 224, 240);
    Pilot_scheme->CommonBkColor = TAN;
    Pilot_scheme->pFont = (void*)&CALIST_36;

    
    #ifdef USE_GRADIENT
    Pilot_scheme->gradientScheme.gradientType=GRAD_DOUBLE_HOR; //GRAD_DOUBLE_HOR;
    Pilot_scheme->gradientScheme.gradientStartColor=RGBConvert(255, 255, 255); // Color [R=0, G=0, B=255]
    Pilot_scheme->gradientScheme.gradientEndColor=RGBConvert(255, 255, 255); // Color [R=255, G=255, B=0]
    Pilot_scheme->gradientScheme.gradientLength=50;
    #endif

      if(Pilot_off != NULL) free(Pilot_off);
        Pilot_off = GOLCreateScheme();


    Pilot_off->Color0 = RGBConvert(0, 255, 255);
    Pilot_off->Color1 = RGBConvert(0, 255, 255);
    Pilot_off->TextColor0 = RGBConvert(0, 0, 0);
    Pilot_off->TextColor1 = RGBConvert(10, 10, 10);
    Pilot_off->EmbossDkColor = RGBConvert(100, 100, 100);
    Pilot_off->EmbossLtColor = RGBConvert(255, 255, 255);
    Pilot_off->TextColorDisabled = RGBConvert(128, 128, 128);
    Pilot_off->ColorDisabled = RGBConvert(208, 224, 240);
    Pilot_off->CommonBkColor = TAN;
    Pilot_off->pFont = (void*)&CALIST_36;

    
    #ifdef USE_GRADIENT
    
				Pilot_off->gradientScheme.gradientType=GRAD_DOWN;                    //BOTON PRESIONADO
                Pilot_off->gradientScheme.gradientStartColor = RGBConvert(50, 50, 50);
                Pilot_off->gradientScheme.gradientEndColor = RGBConvert(0, 0, 0);
                Pilot_off->gradientScheme.gradientLength=50; 
                Pilot_off->TextColor0 = RGBConvert(10,10,10); 

    #endif	

      if(Pilot_off1 != NULL) free(Pilot_off1);
        Pilot_off1 = GOLCreateScheme();


    Pilot_off1->Color0 = RGBConvert(0, 255, 255);
    Pilot_off1->Color1 = RGBConvert(0, 255, 255);
    Pilot_off1->TextColor0 = RGBConvert(0, 0, 0);
    Pilot_off1->TextColor1 = RGBConvert(10, 10, 10);
    Pilot_off1->EmbossDkColor = RGBConvert(100, 100, 100);
    Pilot_off1->EmbossLtColor = RGBConvert(255, 255, 255);
    Pilot_off1->TextColorDisabled = RGBConvert(128, 128, 128);
    Pilot_off1->ColorDisabled = RGBConvert(208, 224, 240);
    Pilot_off1->CommonBkColor = TAN;
    Pilot_off1->pFont = (void*)&CALIST_36;

    
    #ifdef USE_GRADIENT
    
 				Pilot_off1->gradientScheme.gradientType=GRAD_DOWN;
                Pilot_off1->gradientScheme.gradientStartColor = RGBConvert(50, 50, 50);
                Pilot_off1->gradientScheme.gradientEndColor = RGBConvert(0, 0, 0);
                Pilot_off1->gradientScheme.gradientLength=50; 
                Pilot_off1->TextColor0 = RGBConvert(10,10,10);
    #endif	         		

      if(Pilot_off2 != NULL) free(Pilot_off2);
        Pilot_off2 = GOLCreateScheme();


    Pilot_off2->Color0 = RGBConvert(0, 255, 255);
    Pilot_off2->Color1 = RGBConvert(0, 255, 255);
    Pilot_off2->TextColor0 = RGBConvert(0, 0, 0);
    Pilot_off2->TextColor1 = RGBConvert(10, 10, 10);
    Pilot_off2->EmbossDkColor = RGBConvert(100, 100, 100);
    Pilot_off2->EmbossLtColor = RGBConvert(255, 255, 255);
    Pilot_off2->TextColorDisabled = RGBConvert(128, 128, 128);
    Pilot_off2->ColorDisabled = RGBConvert(208, 224, 240);
    Pilot_off2->CommonBkColor = TAN;
    Pilot_off2->pFont = (void*)&CALIST_36;

    
    #ifdef USE_GRADIENT
    
 				Pilot_off2->gradientScheme.gradientType=GRAD_DOWN;
                Pilot_off2->gradientScheme.gradientStartColor = RGBConvert(50, 50, 50);
                Pilot_off2->gradientScheme.gradientEndColor = RGBConvert(0, 0, 0);
                Pilot_off2->gradientScheme.gradientLength=50; 
                Pilot_off2->TextColor0 = RGBConvert(10,10,10);
    #endif	

// Después de la inicialización de Boton_Start_scheme, agrega esto:

if(Boton_Eco_scheme != NULL) free(Boton_Eco_scheme);
Boton_Eco_scheme = GOLCreateScheme();

Boton_Eco_scheme->Color0 = RGBConvert(0, 255, 255);
Boton_Eco_scheme->Color1 = RGBConvert(0, 255, 255);
Boton_Eco_scheme->TextColor0 = RGBConvert(255, 255, 255);  // Texto blanco
Boton_Eco_scheme->TextColor1 = RGBConvert(255, 255, 255);
Boton_Eco_scheme->EmbossDkColor = RGBConvert(100, 100, 100);
Boton_Eco_scheme->EmbossLtColor = RGBConvert(255, 255, 255);
Boton_Eco_scheme->TextColorDisabled = RGBConvert(128, 128, 128);
Boton_Eco_scheme->ColorDisabled = RGBConvert(208, 224, 240);
Boton_Eco_scheme->CommonBkColor = TAN;
Boton_Eco_scheme->pFont = (void*)&CALIST_36; 

#ifdef USE_GRADIENT
// Estado normal (ECO desactivado) - VERDE
Boton_Eco_scheme->gradientScheme.gradientType = GRAD_DOUBLE_HOR;
Boton_Eco_scheme->gradientScheme.gradientStartColor = RGBConvert(0, 180, 60);   // Verde oscuro
Boton_Eco_scheme->gradientScheme.gradientEndColor = RGBConvert(0, 220, 80);     // Verde claro
Boton_Eco_scheme->gradientScheme.gradientLength = 50;
Boton_Eco_scheme->TextColor0 = RGBConvert(255, 255, 255);  // Texto blanco
#endif 


  ClearDevice();

    // -- Fondo general --
    SetColor(RGBConvert(5, 8, 16));
    FillBevel(0, 0, 799, 480, 1);

    // -- Header bar --
    SetColor(RGBConvert(255, 255, 255));
    FillBevel(0, 0, 799, 38, 0);
    SetColor(RGBConvert(10, 58, 110));
    SetLineType(SOLID_LINE);
    SetLineThickness(NORMAL_LINE);
    Line(0, 38, 799, 38);

    // -- Relleno paneles (azul oscuro) --
    SetColor(RGBConvert(10, 15, 30));
    FillBevel( 14,  27, 259, 274, 10);   // IZQ
    FillBevel(294,  27, 504, 274, 10);   // CENTRAL
    FillBevel(540,  27, 784, 274, 10);   // DER
    FillBevel( 14, 285, 370, 372, 10);   // inferior izq
    FillBevel(398, 285, 784, 372, 10);   // inferior der



    // -- Recesos negros interiores (donde van los números grandes) --
    SetColor(RGBConvert(0, 3, 8));
    FillBevel(130,  20, 255, 270, 10);   // IZQ negro
   // FillBevel(300,  20, 500, 270, 10);   // CENTRAL negro
   // FillBevel(545,  20, 672, 270, 10);   // DER negro  ClearDevice();

    // -- Fondo general --
    SetColor(RGBConvert(5, 8, 16));
    FillBevel(0, 0, 799, 480, 1);

    // -- Header bar --
    SetColor(RGBConvert(2, 10, 24));
    FillBevel(0, 0, 799, 38, 0);
    SetColor(RGBConvert(10, 58, 110));
    SetLineType(SOLID_LINE);
    SetLineThickness(NORMAL_LINE);
    Line(0, 38, 799, 38);

    // -- Relleno paneles (azul oscuro) --
    SetColor(RGBConvert(10, 15, 30));
    FillBevel( 14,  27, 259, 274, 10);   // IZQ
    FillBevel(294,  27, 504, 274, 10);   // CENTRAL
    FillBevel(540,  27, 784, 274, 10);   // DER
    FillBevel( 14, 285, 370, 372, 10);   // inferior izq
    FillBevel(398, 285, 784, 372, 10);   // inferior der

    // -- Borde exterior cian --
    SetColor(RGBConvert(10, 255, 0));
    SetLineThickness(NORMAL_LINE);
    Bevel( 14,  25, 259, 260, 10);
    Bevel(294,  25, 504, 260, 10);
    Bevel(540,  25, 784, 260, 10);
    Bevel( 14, 290, 370, 372, 10);
    Bevel(398, 290, 784, 372, 10);

    // -- Recesos negros interiores (donde van los números grandes) --
    SetColor(RGBConvert(0, 0, 0));
    FillBevel(130,  95, 255, 200, 10);   // IZQ negro
  //  FillBevel(300,  95, 500, 200, 10);   // CENTRAL negro
  //  FillBevel(545,  95, 672, 200, 10);   // DER negro
 
//************************************BOTONES DE LAS FLECHAS*********************************//


    BUTTON *pBTN_48;                          //BUTTON LEFT SUPERIOR
    pBTN_48 = BtnCreate(  BTN_48, //name
                       10, //left
                       10, //53, //top
                       110, //right
                       140, //153, //bottom
                       50, //radius
                       BTN_NOPANEL | BTN_DRAW, //state
                       (void*)&Flecha_11, //bitmap
                       NULL, //(XCHAR*)ventana_1_BTN_48text, //text
                      Pilot_scheme //scheme
                    );

    if(pBTN_48==NULL)
    {
      CreateError(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }



    BUTTON *pBTN_49;                         //BUTTON LEFT INFERIOR
    pBTN_49 = BtnCreate(  BTN_49, //name
                       10, //left
                       150, //top
                       110, //right
                       280, //bottom
                       50, //radius
                       BTN_NOPANEL | BTN_DRAW, //state
                       (void*)&Flecha_22, //bitmap
                       NULL, //(XCHAR*)ventana_1_BTN_49text, //text
                      Pilot_scheme //scheme
                    );

    if(pBTN_49==NULL)
    {
      CreateError(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }

    BUTTON *pBTN_50;                         //BUTTON RIGHT SUPERIOR
    pBTN_50 = BtnCreate(  BTN_50, //name
                       693, //left
                       10, //53, //top
                       793, //right
                       140, //153, //bottom
                       50, //radius
                       BTN_NOPANEL | BTN_DRAW, //state
                       (void*)&Flecha_11, //bitmap
                       NULL,  //(XCHAR*)ventana_1_BTN_50text, //text
                      Pilot_scheme //scheme
                    );

    if(pBTN_50==NULL)
    {
      CreateError(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }

    BUTTON *pBTN_51;                          //BUTTON RIGHT INFERIOR
    pBTN_51 = BtnCreate(  BTN_51, //name
                       693, //left
                       150, //top
                       793, //right
                       280, //bottom
                       50, //radius
                       BTN_NOPANEL | BTN_DRAW, //state
                       (void*)&Flecha_22, //bitmap
                       NULL, //(XCHAR*)SOLAPA1_BTN_1text, //text
                       Pilot_scheme //scheme
                    );

    if(pBTN_51==NULL)
    {
      CreateError(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }

   

//**********************************BUTTON DE START*************************//

    BUTTON *pBTN_START;
    pBTN_START = BtnCreate(  BTN_START, //name
                       295, //left
                       170, //top
                       505, //right
                       265, //bottom
                       20, //radius
                       BTN_DRAW, // | BTN_TOGGLE , //state
                       NULL, //bitmap
                       "ON", //(XCHAR*)ventana_1_BTN_28text, //text
                       Boton_Start_scheme //scheme
                    );

    if(pBTN_START==NULL)
    {
      CreateError(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }


    BUTTON *pBTN_RESET_VOL;
    pBTN_RESET_VOL = BtnCreate(  BTN_RESET_VOL, //name
                20, 295, 155, 370,      /* x1, y1, x2, y2              */
			    6,                      /* radio de esquinas           */
			    BTN_DRAW,               /* estado inicial              */
			    NULL,                   /* sin bitmap                  */
			    (XCHAR*)"VOLUMEN\nTOTAL", /* texto                     */
			    Boton_Stop_scheme       /* esquema visual — mismo que tenes */
                    );

    if(pBTN_RESET_VOL==NULL)
    {
      CreateError(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }
  

BUTTON *pBTN_CONFIG;
pBTN_CONFIG = BtnCreate( BTN_CONFIG,
            660, 400, 790, 475,     /* x1, y1, x2, y2 */
            6,                      /* radio de esquinas */
            BTN_DRAW,               /* modo de dibujo */
            NULL,                   /* sin bitmap */
            (XCHAR*)"ECO",          /* texto visible */
            Boton_Eco_scheme        /* usar el scheme ECO */
            );

if(pBTN_CONFIG == NULL)
{
    CreateError(0);
    while(1);
}





//*****************************FIN  BUTTON DE STOP*************************//

      prevSCREEN=1;



          //Para que me inicialize todos los valores del NEUMO

}
/***************************************************
* Function 	      :    Createventana_2
* Parameters      :    none
* Return          :    none
* Description     :    Creates GOL widgets used in screen - ventana_2
***************************************************/
void Createventana_2(void)
{



}


/***************************************************
* Function 	      :    Createventana_inicio
* Parameters      :    none
* Return          :    none
* Description     :    Creates GPL widgets used in screen - ventana_inicio
***************************************************/


void CreatePrimitivesForventana_inicio(void)
{

X = GetMaxX()-GetImageWidth((void*)&LOGO_1);
Y = GetMaxY()-GetImageHeight((void*)&LOGO_1);
//put bitmap in the center
char stretch = IMAGE_NORMAL;

SetColor(RGBConvert(5, 5, 5));
   FillBevel(0, 0, 799, 480, 1);
PutImage((X >>1),(Y >> 1), &LOGO_1, stretch);

	  DelayMs(500);  
      
 	ClearDevice();

// para bloquear equipo borrar esto
	GDDDemoGoToScreen(1);

		
}



/***************************************************
* Function 	      :    Createventana_1
* Parameters      :    none
* Return          :    none
* Description     :    Creates GPL widgets used in screen - ventana_1
***************************************************/
void CreatePrimitivesForventana_1(void)
{

  ////     if(prevSCREEN){                    //PARA QUE LIMPIE DONDE SE DESPLEGO LA PESTAÑA FLOTANTE
    //   SetColor(color_fondo_1);
    //   Bar(93, 0, 708, 45);}
		//	Dibujar_icono_mute_grande(558, 406, 255, 255, 255);
			SetFont((void*)&CALIST_36);
			SetColor(RGBConvert(255, 200, 0));
            OutTextXY(548, 100, "MEDIA");
            SetColor(RGBConvert(255, 200, 0));
            FillBevel(560, 210, 660, 235, 4);
            FillBevel(560, 175, 660, 200, 4);
            SetColor(RGBConvert(20, 30, 50));
            FillBevel(560, 140, 660, 165, 4);

	SetColor(RGBConvert(255, 200, 0));
	SetFont((void*)&CALIST_36);
	OutTextXY(575, 35, "TEMP");
    Dibujar_termometro(550, 33, 240, 35, 30);
	SetColor(WHITE);
	SetFont((void*)&Gentium_16);
	OutTextXY(574, 230, "°C");

    SetColor(RGBConvert(255, 140,   0));
    SetFont((void*)&Gentium_150);

    OutTextXY(535,50,(XCHAR*)buffer_set_pres);
	SetColor(COL_ORANGE);
	SetFont((void*)&CALIST_36);
	OutTextXY(135, 35, "FLUJO");
	SetColor(COL_ORANGE);
	SetFont((void*)&Gentium_16);
	OutTextXY(150, 230, "L/min(P)");

    SetColor(RGBConvert(10, 15, 30));
    FillBevel(120, 80, 265, 215, 1);   
    SetColor(WHITE);
    SetFont((void*)&Gentium_72);    
	OutTextXY(180, 120, ",");  
    SetFont((void*)&Gentium_150);
    OutTextXY(120, 50, "20");            


	SetColor(COL_GREEN);
    SetFont((void*)&Gentium_16);
    OutTextXY(320, 325, "L");

    SetColor(COL_ACCENT);
    SetFont((void*)&Gentium_16);
    OutTextXY(420, 305, "FLUJO");
    OutTextXY(420, 335, "L/min");


 //   SetColor(RGBConvert(0, 0, 0));
 //   FillBevel(320, 50, 466, 154, 1);    


  						WORD    result;
                     BYTE    pos;
                     pos = 0;
                         
                         result = presion_actual / 10;        
                         if(result)
                         buffer_actual_pres[pos++] = result + '0';
                         result = presion_actual - 10 * result;    

                         buffer_actual_pres[pos++] = result + '0';
                        // buffer[pos++] = '%';
                         buffer_actual_pres[pos++] = 0;

              //           SetColor(RGBConvert(255, 255, 255));                                 
              //           SetFont((void*)&Gentium_72);                                        
              //            OutTextXY(520, 400,(XCHAR*)buffer_actual_pres);                        


//     SetColor(color_fondo_1);      
//    FillBevel(540, 295, 640, 375, 1);   // Limpia el área del número  



    int entero_v = presion_actual_v / 10;   // Si es 15, entero es 1
    int decimal_v = presion_actual_v % 10;  // Si es 15, decimal es 5

    // Creamos el texto manualmente "1.5"
    // Si prefieres coma, cambia el "." por ","
 //   sprintf(buffer_actual_pres_v, "%d.%d", entero_v, decimal_v);

    SetColor(RGBConvert(255, 255, 255));                                  
    SetFont((void*)&Gentium_72); 
    OutTextXY(550, 290, (XCHAR*)buffer_actual_pres_v);
    
     SetColor(RGBConvert(10, 15, 30));      
    FillBevel(165, 295, 300, 375, 1);   // Limpia el área del número
char buffer_volumen2[10];

sprintf(buffer_volumen2, "%03d", volumen);

    SetColor(RGBConvert(255, 255, 255));                                  
    SetFont((void*)&Gentium_72); 
    OutTextXY(180, 290, (XCHAR*)buffer_volumen2);


}

/***************************************************
* Function 	      :    Createventana_2
* Parameters      :    none
* Return          :    none
* Description     :    Creates GPL widgets used in screen - ventana_2
***************************************************/
void CreatePrimitivesForventana_2(void)
{


}




/***************************************************
* Function       : CreateFunctionArray
* Parameters     : none
* Return         : none
* Description    : Creates a array of GOL function pointers
***************************************************/
void (*CreateFunctionArray[NUM_GDD_SCREENS])(void)=
    
{
    &Createventana_inicio,
    &Createventana_1,
    &Createventana_2,
};

void Dibujar_termometro(int x0, int y0, int color_r, int color_g, int color_b)
{
    /* Tubo vertical — gris claro (fondo) */
    SetColor(RGBConvert(180, 180, 180));
    Bar(x0 + 4, y0,      x0 + 10, y0 + 28);   /* tubo interior */

    /* Relleno rojo del tubo */
    SetColor(RGBConvert(color_r, color_g, color_b));
    Bar(x0 + 5, y0 + 14, x0 + 9,  y0 + 28);   /* columna roja  */

    /* Bulbo inferior rojo */
    SetColor(RGBConvert(color_r, color_g, color_b));
    Bar(x0 + 2, y0 + 28, x0 + 12, y0 + 38);   /* bulbo cuadrado */
    Bar(x0 + 1, y0 + 30, x0 + 13, y0 + 36);   /* ensanche lateral */

    /* Borde negro del tubo */
    SetColor(RGBConvert(30, 30, 30));
    Bar(x0 + 3,  y0,      x0 + 4,  y0 + 30);  /* borde izq tubo */
    Bar(x0 + 10, y0,      x0 + 11, y0 + 30);  /* borde der tubo */
    Bar(x0 + 3,  y0,      x0 + 11, y0 + 1);   /* tope superior  */

    /* Borde negro del bulbo */
    Bar(x0 + 1,  y0 + 28, x0 + 2,  y0 + 38);
    Bar(x0 + 12, y0 + 28, x0 + 13, y0 + 38);
    Bar(x0 + 1,  y0 + 37, x0 + 13, y0 + 38);

    /* Marcas laterales */
    SetColor(RGBConvert(30, 30, 30));
    Bar(x0 + 11, y0 + 5,  x0 + 15, y0 + 6);   /* marca 1 */
    Bar(x0 + 11, y0 + 11, x0 + 14, y0 + 12);  /* marca 2 */
    Bar(x0 + 11, y0 + 17, x0 + 15, y0 + 18);  /* marca 3 */
    Bar(x0 + 11, y0 + 23, x0 + 14, y0 + 24);  /* marca 4 */
}

/***************************************************
* Function       : CreatePrimitivesFunctionArray
* Parameters     : none
* Return         : none
* Description    : Creates a array of GPL function pointers
***************************************************/
void (*CreatePrimitivesFunctionArray[NUM_GDD_SCREENS])(void)=
    
{
    &CreatePrimitivesForventana_inicio,
    &CreatePrimitivesForventana_1,
    &CreatePrimitivesForventana_2,
};

/**********************************************************************************************************
* A random generator from 
* http://www.daniweb.com/software-development/c/code/216329/construct-your-own-random-number-generator
**********************************************************************************************************
*/
unsigned int rand1(int lim)
{
	static long a = 100001;
	a = (a * 125) % 2796203;

    return ((a % lim) + 1);
}

/*
**********************************************************************************************************
* Line draw function from Programming The Nintendo Game Boy Advance: The Unofficial Guide
* Copyright (c)2003 by Jonathan S. Harbour -- http://www.jharbour.com
**********************************************************************************************************
*/


