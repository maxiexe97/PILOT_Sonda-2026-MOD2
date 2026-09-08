
#ifndef    _GDD_SCREENS_H_
#define    _GDD_SCREENS_H_


BYTE UPDate_primitive;    //Para que me actualize los primitives de la ventana_1

extern BYTE update;

//static SHORT estado_Flow = 1;              //Variable utilizada para los estados de ACTUAL FLOW.

static SHORT set_pressure = 14;
static XCHAR buffer_set_pres[3];

WORD adc1;
WORD X,Y;
static SHORT presion_actual = 0;
static SHORT presion_actual_v = 0;
static SHORT flujo_venturi = 0;
static SHORT valor_auxiliar = 0;
static SHORT presion_negativa = 0;
static SHORT prev_presion_actual = 1;
static XCHAR buffer_actual_pres[3];
static XCHAR buffer_actual_pres_v[5];
static XCHAR buffer_velocidad[8];
static XCHAR buffer_temperatura[3];
static XCHAR buffer_presion_negativa[3];
static XCHAR buffer_presion_CO2[8];
WORD cont_pressured;
WORD cont_alarma;
WORD enciendo_calefactor;
long contador_resistencia;

WORD adc2;
//static SHORT alarma de cilindro = 0;
static SHORT presion_Cilindro = 0;

BYTE prevSCREEN;

static SHORT estado_Start;
WORD estado_led;
WORD estado_bajo;
WORD estado_medio;
WORD estado_alto;

static SHORT set_backlight=0;
static SHORT cont_backlight=5;
static SHORT valor, control=1600;

static SHORT state_Electro_valvula;
float  time_activo_electrovalvula;
float  time_inactivo_electrovalvula;

 static WORD SLDVerprevValue;// maintains the previous value of the Slider     //Variables del Slider Vertical custom derecho
//WORD SLDVervalue, posXSLDBarVer=718, posYSLDBarVer=365, widthSLD=80, xver, yver;   //Variables del Slider Vertical custom derecho

static WORD SLDVerprevValue_2;                                                  //Variables del Slider Vertical custom izquierdo
//WORD SLDVervalue_2, posXSLDBarVer_2=0, posYSLDBarVer_2=365, widthSLD_2=80, xver_2, yver_2;  //Variables del Slider Vertical custom izquierdo

SHORT Linea;

GOL_SCHEME* Pilot_off;
GOL_SCHEME* Pilot_off1;
GOL_SCHEME* Pilot_off2;
GOL_SCHEME* Boton_Start_scheme;
GOL_SCHEME* Pilot_scheme;
GOL_SCHEME* Boton_Eco_scheme;

BYTE flag_core_timer;
SHORT estado_alarma_1;

BYTE estado_cilindro;
BYTE desbloqueado;
BYTE DRAW_cilindro_OK;
BYTE DRAW_cilindro_NO;

BYTE DRAW_obstruccion_OK;
BYTE DRAW_obstruccion_NO;

BYTE DRAW_pressure_negativa_OK;
BYTE DRAW_pressure_negativa_NO;

BYTE DRAW_sobre_pressure_OK;
BYTE DRAW_sobre_pressure_NO;

BYTE DRAW_Calefactor_OK;

float tick_x_seg;
float tick_electrovalvula;  //WORD es 16-bit unsigned  = 65536 x 0.1seg = 6553.6seg = 60min = 109.22 horas
WORD time_pest_flotante;

volatile SHORT BEEPER2;
WORD RingTone;
/*
    typedef enum
{
    
    GET_POT,
    RUN_POT
} ADC_STATES;

volatile  ADC_STATES stateADC = RUN_POT;
*/
SHORT stateADC;

/***************************************************
*FUNCTION DECLARATION
***************************************************/

void GDDDemoCreateFirstScreen(void);
void GDDDemoGOLDrawCallback(void);
void GDDDemoNextScreen(void);
void GDDDemoGoToScreen(int screenIndex);
WORD GDDDemoGOLMsgCallback(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);
void UPDatePrimitives_ventana_1(void);
void WordToString(LONG value, XCHAR *buffer);
void Inicializo_prev_Values(void);

void MyFocus(SHORT left,SHORT top, SHORT right, SHORT buttom);
void Get_presion_actual(void);
unsigned int rand1(int lim);
void DrawLine(int x1, int y1, int x2, int y2, int _color);

void print_value_led();
void Get_Sensor_1();
void Get_Venturi();
void Get_presion_negativa();
void Get_Calefactor();
void PWM_venturi();
void Alarma_sonora();
void Graficar_sobre_presion();
void Graficar_calefactor();
void Graficar_presion_negativa();
void Graficar_obstruccion();
void Graficar_cilindro_CO2();
void DRAW_Bottom_Stop();

extern const IMAGE_EXTERNAL LOGO_1;
extern const IMAGE_FLASH   Flecha_11;
extern const IMAGE_FLASH   Flecha_22;

/***************************************************
*FONT DECLARATION
***************************************************/
extern const FONT_FLASH Gentium_72;
extern const FONT_FLASH Gentium_16;
extern const FONT_FLASH Gentium_200;
extern const FONT_FLASH Gentium_150;
extern const FONT_FLASH GOLSmallFont;
extern const FONT_FLASH GOLFontDefault;
extern const FONT_FLASH Font35;
extern const FONT_FLASH CALIST_36;


/***************************************************
*SCREEN DECLARATION
***************************************************/
void Createventana_inicio(void);
void CreatePrimitivesForventana_inicio(void);
void Createventana_1(void);
void CreatePrimitivesForventana_1(void);
void Createventana_2(void);
void CreatePrimitivesForventana_2(void);
void DRAW_Set_Pressure();
void DRAW_Modo();
/***************************************************
* Function and global Declarations
***************************************************/
#define	NUM_GDD_SCREENS 3


WORD currentGDDDemoScreenIndex;

/***************************************************
*UNIQUE WIDGET ID'S
***************************************************/
#define BTN_60 1
#define BTN_37 2
#define BTN_38 3
#define SLD_39 4
#define PRB_40 5
#define PRB_41 6
#define BTN_48 7
#define BTN_49 8
#define BTN_50 9
#define BTN_51 10
#define DMT_57 11
#define PCB_58 12
#define BTN_64 13
#define CHB_27 14
#define CHB_28 15
#define STE_29 16
#define STE_30 17
#define BTN_28 18          //Bottom de Start
#define BTN_Stop 19          //Bottom de Stop
#define BTN_65 20
#define BTN_66 21
#define SLD_40 22
#define STE_31 23
#define BTN_START 24
#define BTN_LED 25
#define BTN_MEDIO 26
#define BTN_ALTO 27
#define BTN_BAJO 28
#define BTN_RESET_VOL 29
#define BTN_CONFIG 30
#define BTN_MUTE 31
//----< Definiciones para los valores de la bomba de vacio >------//
#define Beep()  T3CONbits.TON = 1
#define Ultra_High     200
#define High           150
#define Medio          100
#define Low            50

// VACIO 
#define factor_de_correccion_vacio_cero  4    //era 4   con menor q 4 marca algo en presion actual PARA BRUJA ROBERTO

// SI EL EQUIPO ESTA SIN AIRE EN VACIO DEBE MARCAR 0 EN CASO DE QUE MARQUE 1 O MAS DEBO SUBIR EL VALOR DE factor_de_correccion_vacio_cero


//  PRESION NEGATIVA SI MARCA VACIO DE LA NADA
#define set_presion_negativa -1             // aca calibro vacio estaba en 1 EN CASO DE QUE NO MARQUE VACIO CUANDO SUCCIONAS PONER 2 O 3




//  VALOR DESDE DONDE MARCA OBSTRUCCION
#define presion_de_obstruccion 40


//  VALOR DESDE DONDE MARCA SOBREPRESION
#define medida_de_sobrepresion 25


// VALOR DESDE DONDE MARCA TANQUE DESCONECTADO
#define value_de_NO_cilindro_CO2  70 //200



// CILINDRO VALOR DE ALARMA
#define factor_de_correccion_CO2_cero 10





#define color_fondo_1   RGBConvert(0,0,0)    //Color del fondo de la ventana principal
                                                /*********************************************************************
                                                * (64, 0, 0) color bordo muy bueno
                                                * (0, 60, 0) color verde muy bueno
                                                * (0, 64, 128) color azul fachero
                                                * (64, 0, 64) color violeta fachero
                                                **********************************************************************/



#define POT_SAMPLES_NUMBER 600    //4 con este valor funciono siempre
static int potSamples[POT_SAMPLES_NUMBER];
static int potSamplesIndex;
static int histeresis;

#define Sensor_1_SAMPLES_NUMBER 4
static int Sensor_1_Samples[Sensor_1_SAMPLES_NUMBER];
static int Sensor_1_SamplesIndex;
volatile SHORT      adc_sensor_1;
static UINT16 Sensor_1_New, Sensor_1_Old, Channel0, Channel1, Channel2, Channel3, i;
static SHORT presion_CO2 = 0;

#define Calefactor_SAMPLES_NUMBER 600
static int Calefactor_Samples[Calefactor_SAMPLES_NUMBER];
static int Calefactor_SamplesIndex;
volatile SHORT      adc_Calefactor;
static UINT16 Calefactor_New, Calefactor_Old;
static SHORT value_Calefactor = 0;

#define VENTURI_SAMPLES_NUMBER 600
static int venturi_Samples[VENTURI_SAMPLES_NUMBER];
static int venturi_SamplesIndex;
volatile SHORT      adc_venturi;
static UINT16 venturi_New, venturi_Old;
static SHORT value_venturi = 0;


unsigned int offSet; // points to the base of the idle buffer

static float potTick, potTick_v,potTick_1, potTick_2, potTick_3, potTick_4, potTick_5, negative_Tick, potTick_6, potTick_7, potTick_8, potTick_9, potTick_10, time_sobre_presion, potTick_11, potTick_12, potTick_13, potTick_14,potTick_15,potTick_16, pre_time_Handler, Tick_touch;
static UINT16 PotNew,PotNew_v,PotNew_1,PotNew_1_v, PotOld,PotOld_v, actual_vacuum, Set_vacuum = 150, Old_Set_vacuum, Set_vacuum_2 = 150, val_seteado, value_obstruccion;
static float PotNew_2, PotNew_2_v;

extern volatile SHORT adcPot;
static XCHAR buffer_actual_vacuum[8];

BYTE estado_bomba;
BYTE Alarma_sonora_pres_negative;
BYTE Alarma_sonora_de_sobre_presion;

static XCHAR buffer_set_vacuum[8];
WORD time_fuga;
WORD time_alarma_fuga;
BYTE flag_alarma_fuga;
BYTE flag_tanque_lleno;
BYTE flag_tanque_desconectado;
BYTE flag_pres_negative;
BYTE flag_presion_negativa;
WORD flag_sobre_presion1;
BYTE flag_sobre_presion;
BYTE flag_obstruccion;
BYTE flag_cilindro_CO2;
BYTE flag_Calefactor;
BYTE DRAW_Tanque_2;
BYTE DRAW_Bateri_2;
BYTE DRAW_Bateri_3;
BYTE DRAW_Fuga;
BYTE DRAW_Tanque_LLeno;
BYTE DRAW_Tanque_desconectado;
BYTE DRAW_Calefa_0_OK;
BYTE DRAW_Calefa_1_OK;
BYTE DRAW_Calefa_2_OK;
BYTE DRAW_Calefa_3_OK;
BYTE DRAW_Calefa_4_OK;
BYTE DRAW_Calefa_5_OK;
SHORT flag_bateri_cargando;
SHORT sonido;
WORD Tiempo_de_carga_de_bateria;
WORD alarma_cilindro;
BYTE estado_de_alarma_visual;
BYTE estado_de_alarma_sonora;
SHORT state_sobre_presion;
SHORT state_pres_negative;
SHORT state_obstruccion;
SHORT state_cilindro_CO2;
SHORT state_Calefactor;
SHORT cont_bar;
//----< Fin de Definiciones para los valores de la bomba de vacio >------//




typedef enum
{	
    ACTIVO_VALVULA,
    DESACTIVO_VALVULA,
    READ_PRESION,
    COMPARE_PRESION
} NEUMO;

volatile NEUMO state_secuencia;

static SHORT estado_Flow = 1;              //Variable utilizada para los estados de ACTUAL FLOW.
static SHORT estado_Flow_Old;              //Variable utilizada para los estados de ACTUAL FLOW.
static SHORT state_Stop = 0;
float TAE, TDE, TPE;
//*********************Variables para los sonidos*****************************//

BYTE flag_sonido;
BYTE Frec_tone;

#define WAIT_UNTIL_FINISH(x)    while(!x)

SHORT value_led1;
SHORT value_led2;

//********************< Variables para capturar la pantalla y guardarla en memoria SD >***************//
/*
#define USE_GET_PANTALLA

#ifdef USE_GET_PANTALLA

static WORD buffer_get_pixel_coordenada[768000];
static WORD buffer_get_pixel_coordenada_y[384000];
static DWORD index_get_pixel_coordenada;
static WORD buffer_get_pixel_color[384000];
static DWORD index_get_pixel_color;

#endif
*/
#endif
