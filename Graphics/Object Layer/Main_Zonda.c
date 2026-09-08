

#include "Main_Zonda.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Touch_Pilot_7/GDD_Screens.h"
#include <dee_emulation_pic32.h>
#include <plib.h>


// Configuration bits
#if defined(__dsPIC33F__) || defined(__PIC24H__)
_FOSCSEL(FNOSC_PRI);
_FOSC(FCKSM_CSECMD &OSCIOFNC_OFF &POSCMD_XT);
_FWDT(FWDTEN_OFF);
#elif defined(__dsPIC33E__) || defined(__PIC24E__)
_FOSCSEL(FNOSC_FRC);			
_FOSC(FCKSM_CSECMD & POSCMD_XT & OSCIOFNC_OFF & IOL1WAY_OFF);
_FWDT(FWDTEN_OFF);
_FPOR(FPWRT_PWR128 & BOREN_ON & ALTI2C1_ON & ALTI2C2_ON);
_FICD(ICS_PGD1 & RSTPRI_PF & JTAGEN_OFF);
#elif defined(__PIC32MX__) 
	#if defined (MMEVK_R1A)|| defined (PIC32_GP_SK) || defined (PIC32_USB_SK) || defined (PIC32_ETH_SK) || defined (EXPLORER_16) || defined (PIC32MX360F512L_EVK_RD5B)
	#pragma config FPLLIDIV = DIV_2		//8MHz ext crystal onboard of PIC32 GP SK
	#elif defined (PIC32_EVK_RD4)	
	#pragma config FPLLIDIV = DIV_3		//12MHz ext crystal onboard of PIC32MX360F512L EVK RD4
	#endif
    #pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FWDTEN = OFF, FCKSM = CSECME, FPBDIV = DIV_1
    #pragma config OSCIOFNC = ON, POSCMOD = XT, FSOSCEN = ON, FNOSC = PRIPLL
    #pragma config CP = OFF, BWP = OFF, PWP = OFF
#else
    #if defined(__PIC24FJ256GB110__)
_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2)
_CONFIG2(0xF7FF & IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRIPLL & PLLDIV_DIV2 & IOL1WAY_OFF)
    #endif
    #if defined(__PIC24FJ256GA110__)
_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2)
_CONFIG2(IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRIPLL & IOL1WAY_OFF)
    #endif
    #if defined(__PIC24FJ128GA010__)
_CONFIG2(FNOSC_PRIPLL & POSCMOD_XT) // Primary XT OSC with PLL
_CONFIG1(JTAGEN_OFF & FWDTEN_OFF)   // JTAG off, watchdog timer off
    #endif
	#if defined (__PIC24FJ256GB210__)
_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF) 
_CONFIG2( POSCMOD_HS & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
_CONFIG3( WPFP_WPFP255 & SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 
	#endif
	#if defined (__PIC24FJ256DA210__)
_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF) 
_CONFIG2( POSCMOD_HS & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
_CONFIG3( WPFP_WPFP255 & SOSCSEL_EC & WUTSEL_LEG & ALTPMP_ALTPMPEN & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 
	#endif	
#endif
/////////////////////////////////////////////////////////////////////////////
//                            FONTS
/////////////////////////////////////////////////////////////////////////////
#define  USE_FONT_FLASH
extern const FONT_FLASH     Font25;
extern const FONT_FLASH     Font35;
/***************************************************
* String literals used in the project
***************************************************/
//const XCHAR ventana_inicio_BTN_2text[] = {'L','E','D',' ','1',0};
//const XCHAR pantalla_encendido_BTN_1text[ ] = {' ',0};
//const XCHAR pantalla_encendido_STE_3text[ ] = {'P','r','e','s','i','o','n','e',' ','e','l',' ','b','o','t','o','n',' ','p','a','r','a',' ','e','n','c','e','n','d','e','r',0};
/*
const XCHAR ventana_0_BTN_1text[] = {'L','E','D',' ','1',0};
const XCHAR ventana_0_BTN_2text[] = {'L','E','D',' ','2',0};
const XCHAR ventana_0_BTN_42text[ ] = {'+', 0};
const XCHAR ventana_0_BTN_43text[ ] = {'-', 0};
const XCHAR ventana_0_BTN_45text[ ] = {'+', 0};
const XCHAR ventana_0_BTN_46text[ ] = {'-', 0};
const XCHAR ventana_0_GRB_50text[ ] = {'F','l','o','w',0};
const XCHAR ventana_0_GRB_51text[ ] = {'S','e','t','.',' ','P','r','e','s','.',0};
const XCHAR ventana_0_GRB_52text[ ] = {'P','r','e','s','.',' ','R','e','a','l',0};
const XCHAR ventana_0_MTR_54text[ ] = {'P','r','e','s','i','o','n',' ','R','e','a','l',0};

const XCHAR Ventana_0_BTN_2text[ ] = {'L','E','D',' ','1',0};
const XCHAR Ventana_0_BTN_3text[ ] = {'L','E','D',' ','2',0};
const XCHAR Ventana_0_BTN_7text[ ] = {'.'};
const XCHAR Ventana_0_BTN_8text[ ] = {'.'};
const XCHAR Ventana_0_BTN_9text[ ] = {'.'};
const XCHAR Ventana_0_BTN_13text[ ] = {'.'};

const XCHAR Ventana_0_OTE_6text[ ] = {'S','e','t','.',' ','P','r','e','s','.',0};
const XCHAR Ventana_0_OTE_11text[ ] = {'F','l','o','w',0};
const XCHAR Ventana_0_OTE_16text[ ] = {'M','e','d','.',0};
const XCHAR Ventana_0_OTE_18text[ ] = {'P','r','e','s','.',' ','R','e','a','l',0};
*/

/////////////////////////////////////////////////////////////////////////////
//                              OBJECT'S IDs
/////////////////////////////////////////////////////////////////////////////


#define WAIT_UNTIL_FINISH(x)    while(!x)


//#define MI_TRANSPARENT_COLOR   0 //RGBConvert (0xFF,0xFF,0xFF)   //(0x0D,0x0D,0x0D)
//TransparentColorEnable(0);
//-------------------------------------//
/***************************************************
*UNIQUE WIDGET ID'S
***************************************************/
/*
#define BTN_1 1
#define STE_3 2

//#define BTN_1 1
#define BTN_2 2
#define SLD_3 3
#define PRB_7 4
#define PRB_9 5
#define BTN_42 6
#define BTN_43 7
#define BTN_45 8
#define BTN_46 9
#define GRB_50 10
#define GRB_51 11
#define GRB_52 12
#define MTR_54 13
#define DMT_55 14
#define DMT_56 15
#define PCB_57 16

#define SLD_1 1
#define BTN_2 2
#define DMT_3 3
*/

    /////////////////////////////////////////////////////////////////////////////
    //                            LOCAL PROTOTYPES
    /////////////////////////////////////////////////////////////////////////////
void   Execut_msg_Handler();        //Funcion que me ejecuta todos los mensajes del Handler


void                        StartScreen();                                              // draws intro screen
void                        CreatePage(XCHAR *pText);                                   // creates the navigation buttons and window for each screen
void                        CreateButtons(void);                                        // creates buttons demo screen
WORD                        MsgButtons(WORD objMsg, OBJ_HEADER *pObj);                  // processes messages for buttons demo screen
void                        CreateRoundButtons(void);                                   // creates rounded buttons demo screen
WORD                        MsgRoundButtons(WORD objMsg, OBJ_HEADER *pObj);             // processes messages for rounded buttons demo screen
void                        CreateCheckBoxes(void);                                     // creates checkboxes demo screen
WORD                        MsgCheckBoxes(WORD objMsg, OBJ_HEADER *pObj);               // processes messages for checkboxes demo screen
void                        CreateRadioButtons(void);                                   // creates radio buttons demo screen
WORD                        MsgRadioButtons(WORD objMsg, OBJ_HEADER *pObj);             // processes messages for radio buttons demo screen
void                        CreateStaticText(void);                                     // creates static text demo screen
WORD                        MsgStaticText(WORD objMsg, OBJ_HEADER *pObj);               // processes messages for static text demo screen
void                        CreatePicture(void);                                        // creates picture demo screen
WORD                        MsgPicture(WORD objMsg, OBJ_HEADER *pObj);                  // processes messages for picture demo screen
void                        CreateSlider(void);                                         // creates slider demo screen
void                        DrawSliderCursor(WORD color, SHORT x, SHORT y);             // draws cursor for slider demo screen
WORD                        MsgSlider(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);    // processes messages for slider demo screen
void                        CreateProgressBar(void);                                    // creates progress bar demo screen
WORD                        MsgProgressBar(WORD objMsg, OBJ_HEADER *pObj);              //  processes messages for progress bar demo screen
void                        CreateSignature(void);                                      // creates signature demo screen
WORD                        PanelSignature(void);                                       // draws box for the signature
WORD                        MsgSignature(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg); // processes messages for signature demo screen
void                        CreatePotentiometer(void);                                  // scrolling graph demo screen
WORD                        PanelPotentiometer(void);                                   // draws box for the scrolling graph
void                        GraphPotentiometer(void);                                   // draws scrolling graph graph
WORD                        GetPotSamples(WORD number);                                 // adds sample from ADC potentiometer channel into temporary buffer

// returns zero if samples number in the buffer is less than defined by parameter
WORD                        MsgPotentiometer(WORD objMsg, OBJ_HEADER *pObj);            // processes messages for ECG demo screen
void                        CreateECG(void);                                            // creates ECG demo screen
WORD                        PanelECG(void);                                             // draws box for the ECG
void                        GraphECG(void);                                             // draws ECG graph
WORD                        GetECGSamples(WORD number);                                 // adds sample from FLASH (can be any source) into temporary buffer

// returns zero if samples number in the buffer is less than defined by parameter
WORD                        MsgECG(WORD objMsg, OBJ_HEADER *pObj);                      // processes messages for ECG demo screen
void                        CreateCustomControl(void);                                  // creates custom control demo screen
WORD                        MsgCustomControl(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg); // processes messages for custom control demo screen
void                        CreateListBox(void);                                        // creates list box demo screen
WORD                        MsgListBox(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);   // processes messages for list box demo screen
void                        CreateEditBox(void);                                        // creates edit box demo screen
WORD                        MsgEditBox(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);   // processes messages for edit box demo screen
void                        CreateDateTime(void);                                       // creates date time demo screen
WORD                        MsgDateTime(WORD objMsg, OBJ_HEADER *pObj);                 // processes messages for date and time demo screen
//void                        UpdateRTCCDates(LISTBOX *pLb);                              // update the date edit boxes
WORD                        MsgSetDate(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);   // processes messages for setting dates
void                        ShowPullDownMenu(void);                                     // create objects for pull down menu and draw
WORD                        RemovePullDownMenu(void);                                   // removes pop out pull down menu from screen
void                        updateDateTimeEb(void);                                     // update edit boxes with current date and time values
void                        CreateMeter(void);                                          // creates meter demo screen
void                        UpdateMeter(void);
WORD                        MsgMeter(WORD objMsg, OBJ_HEADER *pObj);                    // processes messages for meter demo screen
void                        CreateDial(void);                                           // creates dial demo screen
WORD                        MsgDial(WORD objMsg, OBJ_HEADER *pObj);                     // processes messages for dial demo screen
void                        ErrorTrap(XCHAR *message);                                  // outputs text message on screen and stop execution
void                        TickInit(void);                                             // starts tick counter
void                        CreatePullDown(void);
WORD                        MsgPullDown(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);  // processes screen pull down menu
void                        DisplayPullDown(void);                                      // refresh the screen when switching screen using pulldown menu
void                        InitializeBoard(void);                                      // Initializes the hardware components including the PIC device
void                        slider_1(void);
void                        slider_2(void);
void                        barra_de_estados(void);

/***************************************************
*SCREEN DECLARATION
***************************************************/
void Createpantalla_encendido(void);
void Createventana_0(void);

/////////////////////////////////////////////////////////////////////////////
// SPI Device Initialization Function 
/////////////////////////////////////////////////////////////////////////////
#if defined (USE_SST25VF016)
    // initialize GFX3 SST25 flash SPI
    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)                    
#elif defined (USE_MCHP25LC256)
    // initialize EEPROM on Explorer 16
    #define FlashInit(pInitData) MCHP25LC256Init((DRV_SPI_INIT_DATA*)pInitData)  
#elif defined (USE_M25P80)       
    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)
#endif
  
/////////////////////////////////////////////////////////////////////////////
//                            IMAGES USED
/////////////////////////////////////////////////////////////////////////////
// internal flash image

//extern const IMAGE_FLASH Obstruccion;
//extern const IMAGE_FLASH boton_encendido_2;

/////////////////////////////////////////////////////////////////////////////
//                             FONTS USED
/////////////////////////////////////////////////////////////////////////////
extern const FONT_FLASH     GOLFontDefault;                 // default GOL font
extern const FONT_FLASH     GOLSmallFont;                   // small font
extern const FONT_FLASH     monofont;                       // equal width font
extern const FONT_FLASH     LCD_Bold_72;
extern const FONT_FLASH     Gentium_72;
extern const FONT_FLASH     Gentium_16;
extern const FONT_FLASH     Gentium_200;

	   const FONT_FLASH     *ptrLargeAsianFont = &GOLFontDefault;
	   const FONT_FLASH     *ptrSmallAsianFont = &GOLSmallFont;
      // const FONT_FLASH      *GFX_FONT_SPACE = &Andalus_72;
//extern const GFX_FONT_SPACE  Andalus_72;

/////////////////////////////////////////////////////////////////////////////
//                            COLORS USED
/////////////////////////////////////////////////////////////////////////////
#define GRAY20      RGBConvert(51, 51, 51)
#define GRAY40      RGBConvert(102, 102, 102)
#define RED4        RGBConvert(139, 0, 0)
#define FIREBRICK1  RGBConvert(255, 48, 48)
#define DARKGREEN   RGBConvert(0, 100, 0)
#define PALEGREEN   RGBConvert(152, 251, 152)
#define LIGHTYELLOW RGBConvert(238, 221, 130)
#define GOLD        RGBConvert(255, 215, 0)
#define DARKORANGE  RGBConvert(255, 140, 0)

#define USE_GRADIENT

/////////////////////////////////////////////////////////////////////////////
//                            DEMO STATES
/////////////////////////////////////////////////////////////////////////////
typedef enum
{
    CREATE_BUTTONS          = 0,
    DISPLAY_BUTTONS,    
    CREATE_SLIDER,
    DISPLAY_SLIDER,
    CURSOR_DRAW_SLIDER,
    CREATE_PROGRESSBAR,
    DISPLAY_PROGRESSBAR,    
    CREATE_METER,
    DISPLAY_METER,   
    BOX_DRAW_POT,
    CREATE_PICTURE,
    DISPLAY_PICTURE,
    CREATE_VENTANA_0,
    NADA,
} SCREEN_STATES;

/////////////////////////////////////////////////////////////////////////////
//                       GLOBAL VARIABLES FOR DEMO
/////////////////////////////////////////////////////////////////////////////
SCREEN_STATES   screenState = CREATE_VENTANA_0;//CREATE_BUTTONS;               // current state of main demo state mashine
GOL_SCHEME      *altScheme;                                 // alternative style scheme
GOL_SCHEME      *alt2Scheme;                                // alternative 2 style scheme
GOL_SCHEME      *alt3Scheme;                                // alternative 3 style scheme
GOL_SCHEME      *alt4Scheme;                                // alternative 4 style scheme
GOL_SCHEME      *alt5Scheme;                                // alternative 5 style scheme
GOL_SCHEME      *timeScheme;
GOL_SCHEME      *meterScheme;                               // meter scheme
GOL_SCHEME      *navScheme;                                 // style scheme for the navigation
GOL_SCHEME      *redScheme;                                 // alternative red style scheme
GOL_SCHEME      *greenScheme;                               // alternative green style scheme
GOL_SCHEME      *yellowScheme;                              // alternative yellow style scheme
GOL_SCHEME      *defscheme;
GOL_SCHEME      *Pilot_scheme_inicio;
GOL_SCHEME      *Pilot_scheme;
GOL_SCHEME* Pilot_off;
GOL_SCHEME* Pilot_off1;
GOL_SCHEME* Pilot_off2;

//BYTE app_update = 0;
//static BYTE updateGPL = 0;

/***************************************************
* Scheme Declarations
***************************************************/
GOL_SCHEME      *Pilot_Scheme_6_1;
GOL_SCHEME      *Pilot_Scheme_6_2;
GOL_SCHEME      *Pilot_Scheme_6_numeros;

OBJ_HEADER      *pNavList;                                  // pointer to navigation list
volatile DWORD  tick = 0;                                   // tick counter
char            animate;                                    // switch to control animation for picture demo
OBJ_HEADER      *pGenObj;                                   // pointer to a general purpose object
PICTURE         *pPicture;                                  // pointer to picture object for picture demo
PROGRESSBAR     *pProgressBar;                              // pointer to progress bar object for progress bar demo
SLIDER          *pSlider;                                   // pointer to the slider controlling the animation speed



// DEFINITIONS FOR CUSTOM CONTROL DEMO
#define CC_ORIGIN_X ((GetMaxX() - 180 + 1) / 2)
#define CC_ORIGIN_Y ((40 + GetMaxY() - 175 + 1) / 2)

// GLOBAL DEFINITIONS AND VARIABLES FOR SLIDER DEMO
#define SLD_ORIGIN_X    ((GetMaxX() - 260 + 1) / 2)
#define SLD_ORIGIN_Y    ((40 + GetMaxY() - 180 + 1) / 2)
#define CUR_BAR_SIZE    3                                   // half size of center point for cursor
#define CUR_BRD_LEFT    SLD_ORIGIN_X + 37 + CUR_BAR_SIZE    // cursor area left border
#define CUR_BRD_RIGHT   SLD_ORIGIN_X + 223 - CUR_BAR_SIZE   // cursor area right border
#define CUR_BRD_TOP     SLD_ORIGIN_Y + 2 + CUR_BAR_SIZE     // cursor area top border
#define CUR_BRD_BOTTOM  SLD_ORIGIN_Y + 134 - CUR_BAR_SIZE   // cursor area bottom border
//SHORT           x, prevX;                                   // cursor X position
//SHORT           y, prevY;                                   // cursor Y position
//WORD            cursorUpdate;                               // update the cursor position if set   


// GLOBAL DEFINITIONS AND VARIABLES FOR PLOTTING POTENTIOMETER DEMO
// Graph shift
#define POT_MOVE_DELTA  2

// Potentiometer circular buffer size
#define POT_BUFFER_SIZE 320

// Potentiometer data circular buffer
SHORT           potBuffer[POT_BUFFER_SIZE];

// Temporary buffer for graph demo screens
SHORT           tempBuffer[10];

// Variables for the pulldown menus
SHORT           pDwnLeft, pDwnTop, pDwnRight, pDwnBottom;

// Variables for date and time
SCREEN_STATES   prevState = CREATE_BUTTONS; // used to mark state where time setting was called	
SCREEN_STATES   prevRefreshState = CREATE_BUTTONS; // used to mark the start of the previous screen

OBJ_HEADER      *pListSaved;                // temporary storage for object list
WORD            DateItemID;                 // ID of date item being modified (ID_EB_MONTH(DAY)(YEAR))
XCHAR           dateTimeStr[26];            // string variable for date and time display
SHORT           List2Enable = 0, refreshScreen = 0;

BYTE            PulldownId = 0;
///////////////////////////VARIABLE DEL TOUCH///////////////////////////////
volatile DWORD cont;
volatile DWORD cont1;
volatile DWORD cont2;
volatile SHORT flag_cont;


/////////////////////////////////////////////////////////////////////////////
// SPI Channel settings
/////////////////////////////////////////////////////////////////////////////
#if defined SPI_CHANNEL_2_ENABLE || defined SPI_CHANNEL_1_ENABLE || defined SPI_CHANNEL_3_ENABLE || defined SPI_CHANNEL_4_ENABLE
    #if defined (USE_TOUCH_SPI)
       const DRV_SPI_INIT_DATA  SPI_Init_Data2 = {TOUCH_SPI_CHANNEL, 1, 0, 0, 1, 1, 0};
    #endif     
    #if defined (USE_SST25VF016)
        #ifdef __PIC32MX__
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 1, 0, 0, 1, 1, 0};
        #else    
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
        #endif
    #elif defined (USE_MCHP25LC256)       
        const DRV_SPI_INIT_DATA SPI_Init_Data = {MCHP25LC256_SPI_CHANNEL, 6, 3, 0, 1, 1, 0};    
    #elif defined (USE_M25P80)
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
    #endif    
#endif



int main(void)
{
    



    GOL_MSG msg;                        // GOL message structure to interact with GOL
    InitializeBoard();
    navScheme = GOLCreateScheme();      // alternative scheme for the navigate buttons
    altScheme = GOLCreateScheme();      // create alternative 1 style scheme
    alt2Scheme = GOLCreateScheme();     // create alternative 2 style scheme
    alt3Scheme = GOLCreateScheme();     // create alternative 3 style scheme
    alt4Scheme = GOLCreateScheme();     // create alternative 4 style scheme
    alt5Scheme = GOLCreateScheme();     // create alternative 5 style scheme
    timeScheme = GOLCreateScheme();
    meterScheme = GOLCreateScheme();    // create meter scheme
    redScheme = GOLCreateScheme();      // create red style scheme
    greenScheme = GOLCreateScheme();    // create green style scheme
    yellowScheme = GOLCreateScheme();   // create yellow style scheme
    #ifdef USE_EEPROM_PIC32
    while(DataEEInit());
    #endif
    altScheme->Color0 = RGBConvert(0x4C, 0x8E, 0xFF);
    altScheme->Color1 = RGBConvert(255, 102, 0);
    altScheme->EmbossDkColor = RGBConvert(0x1E, 0x00, 0xE5);
    altScheme->EmbossLtColor = RGBConvert(0xA9, 0xDB, 0xEF);
    altScheme->ColorDisabled = RGBConvert(0xD4, 0xE1, 0xF7);
    altScheme->TextColor1 = BRIGHTBLUE;
    altScheme->TextColor0 = RGBConvert(255, 102, 0);
    altScheme->TextColorDisabled = RGBConvert(0xB8, 0xB9, 0xBC);

    altScheme->pFont = (void *)ptrLargeAsianFont;
    navScheme->pFont = (void *)ptrLargeAsianFont;

    alt2Scheme->TextColor1 = BRIGHTRED;
    alt2Scheme->TextColor0 = BRIGHTBLUE;
    alt2Scheme->pFont = (void *)ptrSmallAsianFont;

    alt3Scheme->Color0 = LIGHTBLUE;
    alt3Scheme->Color1 = BRIGHTGREEN;
    alt3Scheme->TextColor0 = BLACK;
    alt3Scheme->TextColor1 = WHITE;
    alt3Scheme->pFont = (void *)ptrSmallAsianFont;

    alt4Scheme->Color0 = LIGHTBLUE;
    alt4Scheme->Color1 = BRIGHTGREEN;
    alt4Scheme->TextColor0 = BLACK;
    alt4Scheme->TextColor1 = WHITE;
    alt4Scheme->pFont = (void *)ptrSmallAsianFont;

    alt5Scheme->Color0 = LIGHTBLUE;
    alt5Scheme->Color1 = BRIGHTRED;
    alt5Scheme->TextColor0 = BLACK;
    alt5Scheme->TextColor1 = WHITE;
    alt5Scheme->pFont = (void *) &monofont; //monofont is equal width font, required for digitalmeter widget

    redScheme->Color0 = RGBConvert(0xCC, 0x00, 0x00);
    redScheme->Color1 = BRIGHTRED;
    redScheme->EmbossDkColor = RED4;
    redScheme->EmbossLtColor = FIREBRICK1;
    redScheme->TextColor0 = RGBConvert(0xC8, 0xD5, 0x85);
    redScheme->TextColor1 = BLACK;
    redScheme->pFont = (void *)ptrLargeAsianFont;

    greenScheme->Color0 = RGBConvert(0x23, 0x9E, 0x0A);
    greenScheme->Color1 = BRIGHTGREEN;
    greenScheme->EmbossDkColor = DARKGREEN;
    greenScheme->EmbossLtColor = PALEGREEN;
    greenScheme->TextColor0 = RGBConvert(0xDF, 0xAC, 0x83);
    greenScheme->TextColor1 = BLACK;
    greenScheme->pFont = (void *)ptrLargeAsianFont;

    yellowScheme->Color0 = BRIGHTYELLOW;
    yellowScheme->Color1 = YELLOW;
    yellowScheme->EmbossDkColor = RGBConvert(0xFF, 0x94, 0x4C);
    yellowScheme->EmbossLtColor = RGBConvert(0xFD, 0xFF, 0xB2);
    yellowScheme->TextColor0 = RGBConvert(0xAF, 0x34, 0xF3);
    yellowScheme->TextColor1 = RED;
    yellowScheme->pFont = (void *)ptrLargeAsianFont;

    timeScheme->Color0 = BLACK;
    timeScheme->Color1 = WHITE;
    timeScheme->TextColor0 = BRIGHTBLUE;
    timeScheme->TextColor1 = WHITE;
    timeScheme->EmbossDkColor = GRAY20;
    timeScheme->EmbossLtColor = GRAY80;
    timeScheme->pFont = (void *) &GOLSmallFont;

    meterScheme->Color0 = BLACK;
    meterScheme->Color1 = WHITE;
    meterScheme->TextColor0 = BRIGHTBLUE;
    meterScheme->TextColor1 = WHITE;
    meterScheme->EmbossDkColor = GRAY20;
    meterScheme->EmbossLtColor = GRAY80;
    meterScheme->pFont = (void *)ptrSmallAsianFont; 
    GDDDemoCreateFirstScreen();
    


    while(1)
    {
     
        if(GOLDraw())
        {   
           
           TouchDetectPosition(); 
          
               TouchGetMsg(&msg);
          
                    GOLMsg(&msg); 
                                           
                           Execut_msg_Handler();

                                 
 
        }
           
    }

}




/////////////////////////////////////////////////////////////////////////////
// Function: WORD GOLDrawCallback()
// Output: if the function returns non-zero the draw control will be passed to GOL
// Overview: this function must be implemented by user. GOLDraw() function calls it each
//           time when GOL objects drawing is completed. User drawing should be done here.
//           GOL will not change color, line type and clipping region settings while

//           this function returns zero.
/////////////////////////////////////////////////////////////////////////////

WORD GOLDrawCallback(void)
{
    
    GDDDemoGOLDrawCallback();
    return(1);

}


//********************************************************************
// Output text message on screen and stop execution
void ErrorTrap(XCHAR *message)
{
    SetColor(WHITE);
    ClearDevice();
    SetFont((void *) &FONTDEFAULT);
    SetColor(BLACK);
    while(!OutTextXY(200, 200, "APLICACION DETENIDA - ERROR INESPERADO"));
    while(1);
}

/*********************************************************************
* Function: Timer4 ISR
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: increments tick counter. Tick is approx. 1 ms.
*
* Note: none
*
********************************************************************/

#ifdef __PIC32MX__
    #define __T3_ISR    __ISR(_TIMER_3_VECTOR, ipl1)
#else
    #define __T3_ISR    __attribute__((interrupt, shadow, auto_psv))
#endif


void __T3_ISR _T3Interrupt(void)
{
#define     RingTone_0      3000
#define     RingTone_1      6000
#define     RingTone_2      4000
#define     RingTone_3      2000
#define     RingTone_4      10000
RingTone = 4000;

if(cont2 <= RingTone){
   cont2++;
  if(flag_cont==0){
    cont = (cont + 4);
    
    cont1 = cont;
    if(cont >=12000 ){ 
             
    cont=1000;
    flag_cont=1;
     } 
    }
    if(flag_cont==1){
    cont = (cont + 16);
    cont1 = cont;
            if(cont >=12000 ){
            cont=1000;
            flag_cont=2;
            }
    }
    if(flag_cont==2){
    cont = (cont + 16);
    cont1 = cont;
            if(cont >=60000 ){
            flag_cont=3;
            }
    }
    if(flag_cont==3){
         cont = (cont - 1000);
         cont1 = cont;
         if(cont <=1000 ){   //100
             
    cont=5000;
    flag_cont=4;
    }
    }

    if(flag_cont==4){
         cont = (cont - 100);
         cont1 = cont;
         if(cont <=1000 ){
             
    cont=0;
    flag_cont=0;
    
    }

    }

    BEEP_LAT_BIT =!(cont&0x40);
    
}else{

       BEEP_LAT_BIT = 0;
       cont=0; cont1=0; cont2=0; flag_cont=0;
       T3CONbits.TON = 0;
       RingTone = 3000;
}
    #ifdef __PIC32MX__    
    mT3ClearIntFlag();
    #else
    IFS1bits.T3IF = 0;
    #endif
}

// *-------------------------------------------------------------------------*

void __ISR(_EXTERNAL_3_VECTOR, ipl2) Int3Handler(void){

    //TouchDetectPosition();
    mINT3ClearIntFlag();
}

// *-------------------------------------------------------------------------*
void Core_Timer(){
    #define CORE_TICK 0x00061A80
    OpenCoreTimer(CORE_TICK);
    IPC0bits.CTIP = 4;
    IPC0bits.CTIS = 1;
    IFS0bits.CTIF = 0;
    IEC0bits.CTIE = 1;
}

void __ISR(_CORE_TIMER_VECTOR, ipl4) CoreTimerHandler(void){

 

              tick_x_seg = tick_x_seg + 0.5;
              tick_electrovalvula = tick_electrovalvula + 0.01;

    UpdateCoreTimer(CORE_TICK);
    IFS0bits.CTIF = 0;
   
}
/////////////////////////////////////////////////////////////////////////////
// Function: void TickInit(void)
// Input: none
// Output: none
// Overview: Initilizes the tick timer.
/////////////////////////////////////////////////////////////////////////////
#define SAMPLE_PERIOD       500
#define TICK_PERIOD			(GetPeripheralClock() * SAMPLE_PERIOD) / 4000000

#define TICK_FRECUENCIA                 (GetPeripheralClock()/FRECUENCIA)-1
#define FRECUENCIA            1000

void TickInit(void)
{
    #ifdef __PIC32MX__
    OpenTimer4(T4_ON | T4_PS_1_1, TICK_PERIOD);
    ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_1);
    T4CONbits.TON = 0;
    #else
    TMR4 = 0;
    PR4 = TICK_PERIOD;
    IFS1bits.T4IF = 0;
    IEC1bits.T4IE = 1;
    T4CONbits.TON = 1;     
    #endif
    OpenTimer3(T3_ON | T3_PS_1_8, TICK_PERIOD);
    ConfigIntTimer3(T3_INT_ON | T3_INT_PRIOR_1);
    T3CONbits.TON = 0;    
}

void PWM_1_3(void)
{   OpenOC2( OC_ON | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, 0, 0);    
    OpenOC1( OC_ON | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, 0, 0);    
    OpenTimer2(T2_ON | T2_PS_1_64 |  T2_SOURCE_INT, 9100); 
   
}

void ADCStartSampling(void) {
                
      mPORTBSetPinsAnalogIn(BIT_0);
      mPORTBSetPinsAnalogIn(BIT_1); 
      mPORTBSetPinsAnalogIn(BIT_2);
      mPORTBSetPinsAnalogIn(BIT_3);
      mPORTBSetPinsAnalogIn(BIT_4);           
      CloseADC10();        
      #define PARAM1  ADC_MODULE_ON | ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON        
      #define PARAM2  ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_ON | ADC_SAMPLES_PER_INT_4 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_OFF         
      #define PARAM3  ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_15          
      #define PARAM4    ENABLE_AN0_ANA | ENABLE_AN1_ANA | ENABLE_AN2_ANA  | ENABLE_AN3_ANA | ENABLE_AN4_ANA      
      #define PARAM5  SKIP_SCAN_AN5 |SKIP_SCAN_AN6 |SKIP_SCAN_AN7 | SKIP_SCAN_AN8 |SKIP_SCAN_AN9 |SKIP_SCAN_AN10 | SKIP_SCAN_AN11 | SKIP_SCAN_AN12 |SKIP_SCAN_AN13 |SKIP_SCAN_AN14 |SKIP_SCAN_AN15                   
SetChanADC10( ADC_CH0_NEG_SAMPLEA_NVREF );              
OpenADC10( PARAM1, PARAM2, PARAM3, PARAM4, PARAM5 );          
ConfigIntADC10(ADC_INT_PRI_2 | ADC_INT_SUB_PRI_2 | ADC_INT_ON);      
}

void __ISR(_ADC_VECTOR, ipl6) AdcHandler(void)   {              
            
      mAD1ClearIntFlag();              
      offSet = 8 * ((~ReadActiveBufferADC10() &0x01));      
      Channel0 = ReadADC10(offSet);   
	  Venturi_Update(ReadADC10(offSet + 0));	  
      Calefactor_Update(ReadADC10(offSet + 1));
      Channel1 = ReadADC10(offSet + 4);    
      Sensor_1_Update(ReadADC10(offSet + 2));   // CO2
      PotUpdate(ReadADC10(offSet + 3));
}


/////////////////////////////////////////////////////////////////////////////
// Function: InitializeBoard()
// Input: none
// Output: none
// Overview: Initializes the hardware components including the PIC device
//           used.
/////////////////////////////////////////////////////////////////////////////
void InitializeBoard(void)
{
   #if defined(__PIC32MX__)
        INTEnableSystemMultiVectoredInt();
        SYSTEMConfigPerformance(GetSystemClock());
	mOSCSetPBDIV(OSC_PB_DIV_1);
    #endif
    GOLInit();
    SetBacklight(255);
 
	#if defined (MMEVK_R1A) || defined (PIC32_EVK_RD4)
        MCHP25LC256_CS_LAT = 1;
        MCHP25LC256_CS_TRIS = 0;
        MCHP25LC256_SCK_TRIS  = 0;
	MCHP25LC256_SDO_TRIS = 0;
	MCHP25LC256_SDI_TRIS = 1;

	#elif defined (ULTIMA_R4_BOARD) && defined (USE_MCHP25LC256) && defined (EXPLORER_16)
        MCHP25LC256_CS_LAT = 1;
        MCHP25LC256_CS_TRIS = 0;
        MCHP25LC256_SCK_TRIS  = 0;
	MCHP25LC256_SDO_TRIS = 0;
	MCHP25LC256_SDI_TRIS = 1;

	#elif defined (ULTIMA_R4_BOARD) && defined (USE_SST25VF016)
            SST25_CS_LAT = 1;
	    SST25_CS_TRIS = 0;
            SST25_SCK_TRIS  = 0;
	    SST25_SDO_TRIS = 0;
	    SST25_SDI_TRIS = 1;
	#endif

    TickInit(); 
    vInitADS7843();
    TouchInit(NVMWrite, NVMRead, NVMSectorErase, NULL);

    ConfigINT3(EXT_INT_PRI_2 | FALLING_EDGE_INT | EXT_INT_ENABLE);  // Interrupcion externa
 

    
    PWM_1_3();
    Core_Timer();
    RingTone = 6000;   
    ADCStartSampling();
	SetDCOC1PWM(0);
          Electro_valvula_TRIS_BIT = 0;     
          Electro_valvula_LAT_BIT = 0;      

			Electro_IN_TRIS_BIT = 0;     
          Electro_IN_LAT_BIT = 0;      

          Calefactor_TRIS_BIT = 0;
          Calefactor_LAT_BIT  = 0;

          BEEP_LAT_BIT = 0;
          BEEP_TRIS_BIT = 0;

		 BUZZER_LAT_BIT   =0 ;
        BUZZER_TRIS_BIT = 0;    
        

    INTEnableInterrupts();   //Habilito las interrupciones 


}    