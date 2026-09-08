
#include <Graphics/Graphics.h>
//#include "GDD_Screens.h"
#include "Touch_Pilot_7/GDD_Screens.h"
#include "ADS7843.h"
#include "Beep.h"
#include <math.h> 

void Get_venturi(void);
void DRAW_Modo_Eco(void);
void DRAW_Set_Temp(void);
void PWM_venturi(void);
void Dibujar_icono_mute_grande(int x, int y, int r, int g, int b);
float Calcular_Flujo_Venturi(float adc_corregido);

//================================================================//
//          MODO CALIBRACION - PONER EN 0 PARA PRODUCCION        //
//              1 = muestra pantallas de debug y usa              //
//                  los valores de calibracion de abajo          //
//================================================================//
#define MOSTRAR_FLUJO  0
#define MOSTRAR_TEMPERATURA  0
#define MOSTRAR_PRESION  0
//----------------------------------------------------------------//
//   VARIABLES DE CALIBRACION FUJO POR PWM   //
//----------------------------------------------------------------//
    
    #define CAL_CONTROL_INIT   800.0f   // PWM del flujo inicial de arranque para que no arranque desde cero y se demore en llegar a 5 por ejemplo 
    #define CAL_PWM_CERO       500.0f   // PWM cuando electrovalvula OFF esta bueno no ponerle 0 asi no demora en subir de 0 a 5 por ejemplo

	#define CAL_PWM_MIN			500.0f   // el valor minimo que puede tomar = a poco flujo 
	#define CAL_PWM_MAX			1800.0f   // valor maximo que puede tomar = a mucho flujo

    #define CAL_DU_MAX          1.0f   // Que tan rapido encuentra el valor 10 esta bien
    #define CAL_RAMPA          10.0f   // Paso de rampa por llamada

//----------------------------------------------------------------//
//   VARIABLES DEL SENSOR VENTURI   //
//----------------------------------------------------------------//

	#define CAL_OFFSET          30.0f   // Punto cero del sensor Venturi 
	#define CAL_K_VENTURI		3.8f      // constante para calibrar el flujo

//----------------------------------------------------------------//
//   VARIABLES TEMPERATURA  //
//----------------------------------------------------------------//
	
	#define CAL_VAL_MAX  400             // sensor frio valor alto 400 

	#define CAL_TEMP_HIGH  170	          // temperatura maxima ya muy caliente el valor es bajo porque esta caliene
	#define CAL_TEMP_MED  230	          // valor medio 
	#define CAL_TEMP_LOW 280	          // temperatura maxima ya muy caliente

	#define CAL_TEMP_ERROR_SENSOR 450     // si no hay sensor o falla
	#define CAL_TEMP_PRECAL       ((CAL_VAL_MAX + CAL_TEMP_LOW) / 2)  // = 285, punto medio PARA PRECALENTAR CUANDO ESTA APAGADO

//=========================  VOLUMEN =================

#define VAL_SUMO_VOLUMEN 10          // desde que valor de presion comienzo a sumar volumen en litros esta en 10 mmhg
#define VAL_ACUM_VOLUMEN 3000.0f      //  contante para acumular volumen, es inversamente proporcional si subo acumulo menos volumen de litros. 

//------------------------------------------------------------------------

//=============  MODO ECO ===================

#define entra_modo_eco   300    // ticks para entrar a eco si presión 900 son como (˜20s)
#define time_sale_eco    10     // ticks de gracia antes de re-entrar a eco (˜10s)
#define presion_modo_eco  20    // es la presion a la que entra a modo eco. estaba en 20 mmHg

#define PORC_ESTABILIDAD_ECO  10    // Margen de +-10% para considerar "presion estable"
#define TICKS_PARA_ENTRAR_ECO 60    // 2 segundos (asumiendo que tu loop corre a 10Hz)
#define PORC_SALIDA_ECO       110   // 110% (si sube 10% sobre el minimo de eco, sale)
//======================================================================================================================================

int volumen = 0;
static float volumen_acum   = 0.0f;  /* acumulador con decimales */
static SHORT tick_volumen   = 0;
static int   volumen_prev   = -1;    /* para detectar cambio y no redibujar siempre */
char buffer_volumen[10];

int modo_eco = 0;
static int estado_Flow_pre_eco = 3;   // guarda el flujo antes de entrar a eco
static SHORT tick_inicio_start = 0;   // tick cuando se apretó START
static BYTE flag_eco_blink = 0;
static SHORT tick_eco_blink = 0;
static BYTE venturi_nuevo = 0;
static SHORT tick_co2_blink = 0;
static BYTE  flag_co2_blink = 0;
// cambio de pendiente
static int  pres_snap        = 0;    /* snapshot para detectar pendiente */
static SHORT tick_snap       = 0;    /* timer del snapshot               */
static int  delta_anterior   = 0;    /* pendiente del intervalo anterior */
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
GOL_SCHEME* Boton_Stop_scheme;
SHORT temp;
int Estado_electro=0;
int estado_temp = 1;  // valor inicial: MEDIA
int setpoint;    // se usa para la temperatura
/* Aprendizaje de presion por nivel */
static int  pres_min[8]    = {0,0,0,0,0,0,0,0};
static BYTE pres_min_ok[8] = {0,0,0,0,0,0,0,0};
static int  pres_max[8]    = {0,0,0,0,0,0,0,0};
static BYTE pres_max_ok[8] = {0,0,0,0,0,0,0,0};
static BYTE base_aprendida[8] = {0, 0, 0, 0, 0, 0, 0, 0};
static SHORT tick_escalon = 0;   /* timer para cada escalon */
static int  pres_eco_min    = 0;
static BYTE pres_eco_min_ok = 0;
int modo_eco_manual = 0;  // 0 = ECO desactivado (verde), 1 = ECO activado (gris)
static SHORT tick_estable   = 0;
static BYTE  cont_estable   = 0;
int alarma_activa = 0;
int mute_activo = 0;
#define TICKS_ESTABLE  80
#define PORC_SALIDA    110   /* 110% del min_eco = sube 10% = boton */
#define PORC_ECO       90    /* bajo del 90% del min = sin boton = entrar eco */
static int presion_estable_count = 0;
static int presion_base[8] = {0, 0, 0, 0, 0, 0, 0, 0};
/* Para modo eco */
static int  pres_ref_eco   = 0;   /* referencia cuando flujo=1 estabilizado */
static BYTE pres_ref_eco_ok= 0;

/* Timer para aprendizaje */
static SHORT tick_ref      = 0;
static BYTE  tick_ref_cont = 0;

#define TICKS_ESTABLE  80    /* ticks que tiene que estar estable antes de guardar */
#define UMBRAL_PORC    110   /* 110% = subio 10% ? era minimo, salir de eco        */
/* Aprendizaje del minimo en modo eco (flujo=1) */
static int  presion_min_eco  = 0;
static BYTE min_eco_ok       = 0;

static SHORT tick_aprendizaje   = 0;
static BYTE  aprendizaje_count  = 0;

#define TICKS_MIN       60    /* ticks estables para aprender el minimo   */
#define ECO_UMBRAL_BAJO 85    /* % del min — debajo de esto entra eco     */
#define ECO_UMBRAL_ECO  115   /* % del min_eco — arriba de esto sale eco  */

/* Porcentajes configurables */
#define ECO_UMBRAL_BAJO   85   /* % — si presion cae por debajo del 85% de base ? eco */
#define ECO_UMBRAL_ALTO   115  /* % — si presion sube por encima del 115% de base ? boton */
#define TICKS_APRENDIZAJE 50   /* ticks estables antes de guardar la base */

void Inicializo_prev_Values(){
      if(prevSCREEN){
             

      if(estado_Start){

                BtnSetText(((BUTTON*)(GOLFindObject(BTN_START))) , (XCHAR*)"OFF");                                          
                Boton_Start_scheme->gradientScheme.gradientType=GRAD_DOWN;
                Boton_Start_scheme->gradientScheme.gradientStartColor = RGBConvert(120, 120, 120);
                Boton_Start_scheme->gradientScheme.gradientEndColor = RGBConvert(0, 0, 0);
                Boton_Start_scheme->gradientScheme.gradientLength=50; 
                Boton_Start_scheme->TextColor0 = RGBConvert(255,255,255);
                estado_Start = 1;
			
			
               }else{
                  BtnSetText(((BUTTON*)(GOLFindObject(BTN_START))) , (XCHAR*)"ON"); 
                 Boton_Start_scheme->gradientScheme.gradientType=GRAD_DOUBLE_HOR; //GRAD_DOUBLE_HOR;
 			     Boton_Start_scheme->gradientScheme.gradientStartColor=RGBConvert(255, 255, 255); // Color [R=0, G=0, B=255]
			     Boton_Start_scheme->gradientScheme.gradientEndColor=RGBConvert(255, 255, 255); // Color [R=255, G=255, B=0]
  				 Boton_Start_scheme->gradientScheme.gradientLength=50;  
	      		 Boton_Start_scheme->TextColor0 = RGBConvert(0,0,0);     
                estado_Start = 0;				
		
                  }

          
          set_pressure = 14;
       
          estado_Flow = 3;
          DRAW_Modo();      //Para inicializar el valor de modo


          DRAW_cilindro_OK = 0;
          DRAW_cilindro_NO = 0;

          DRAW_obstruccion_OK = 0;
          DRAW_obstruccion_NO = 0;

          DRAW_pressure_negativa_OK = 0;
          DRAW_pressure_negativa_NO = 0;

          DRAW_sobre_pressure_OK = 0;
          DRAW_sobre_pressure_NO = 0;

        
          prev_presion_actual = -1;
		  
          state_secuencia = COMPARE_PRESION;   //Para que inicialize la secuencia del Neumo insuflador

          

 prevSCREEN=0;

}
}

/******************************************************************************************************
* Function        : GDDDemoGOLMsgCallback
* Description    : Event handling code is written as separate if statements
* param1         : 
* param2         : 
* param3         : 
 *****************************************************************************************************/

WORD GDDDemoGOLMsgCallback(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
{

//**************************************< FIN  BUTTON DE LA VENTANA DE INICIO >***********************************************//



if(currentGDDDemoScreenIndex == 1){ 


//====   reseteo el volumen total
if ((objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_RESET_VOL) ))
{
    BUZZER_LAT_BIT = 1;
    DelayMs(40);
    BUZZER_LAT_BIT = 0;

    /* Reset del volumen */
    volumen      = 0;
    volumen_acum = 0.0f;
    volumen_prev = -1;   /* fuerza redibujo inmediato */

    /* Limpia el número en pantalla */
    SetColor(RGBConvert(10, 15, 30));
    FillBevel(165, 295, 300, 375, 1);
    SetColor(RGBConvert(255, 255, 255));
    SetFont((void*)&Gentium_72);
    OutTextXY(180, 290, (XCHAR*)"000");

    return (1);
}
//****************************************** < BUTTONS DE SUBE O BAJA PRESION>*************************************************//

if((objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_50)) ||
   (objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_51)))
{
    BUZZER_LAT_BIT = 1;
    DelayMs(40);
    BUZZER_LAT_BIT = 0;

    if(objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_50)) {
        estado_temp++;
        if(estado_temp > 2) estado_temp = 2;  // tope en ALTA
    }
    if(objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_51)) {
        estado_temp--;
        if(estado_temp < 0) estado_temp = 0;  // tope en BAJA
    }

    DRAW_Set_Temp();
    return (1);
}
               
                
//-------------------------------BOTON DE SUBE O BAJA MODO

if((objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_48) ) || (objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_49) ) )
{
				BUZZER_LAT_BIT=1;
 				DelayMs(40);
 				BUZZER_LAT_BIT=0;

	if((objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_48) ) || (objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_49) ))
	{ 
               if(objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_48)){ 
                       estado_Flow += 1;
                       if(estado_Flow > 7){estado_Flow = 7;}  	estado_Flow_pre_eco=estado_Flow;		  DRAW_Modo(); return(1);}              
	 }

		 	  if(objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_49)){ 
			{  estado_Flow -= 1; if(estado_Flow < 0){estado_Flow = 0; }   estado_Flow_pre_eco = estado_Flow; DRAW_Modo(); return(1);} 
		               
		                

         return (1);
        
	}  

}

//**************************************************< BUTTON START >********************************************************//


          	if((objMsg == BTN_MSG_PRESSED && pObj->ID == (BTN_START) ))
			{
			 
				BUZZER_LAT_BIT=1;
 				DelayMs(40);
 				BUZZER_LAT_BIT=0;
               if(!estado_Start){

               BtnSetText(((BUTTON*)(GOLFindObject(BTN_START))) , (XCHAR*)"OFF");                                          
                Boton_Start_scheme->gradientScheme.gradientType=GRAD_DOWN;
                Boton_Start_scheme->gradientScheme.gradientStartColor = RGBConvert(120, 120, 120);
                Boton_Start_scheme->gradientScheme.gradientEndColor = RGBConvert(0, 0, 0);
                Boton_Start_scheme->gradientScheme.gradientLength=50; 
                Boton_Start_scheme->TextColor0 = RGBConvert(255,255,255);       
                estado_Start = 1;
				enciendo_calefactor=1;
				Electro_valvula_LAT_BIT = 1;
				tick_volumen = tick_x_seg - 2;
				tick_co2_blink = tick_x_seg - 10;   /* ? fuerza primer ciclo inmediato */
                flag_co2_blink = 0;
			
               }else{
                BtnSetText(((BUTTON*)(GOLFindObject(BTN_START))) , (XCHAR*)"ON"); 
                 Boton_Start_scheme->gradientScheme.gradientType=GRAD_DOUBLE_HOR; //GRAD_DOUBLE_HOR;
 			     Boton_Start_scheme->gradientScheme.gradientStartColor=RGBConvert(255, 255, 255); // Color [R=0, G=0, B=255]
			     Boton_Start_scheme->gradientScheme.gradientEndColor=RGBConvert(255, 255, 255); // Color [R=255, G=255, B=0]
  				 Boton_Start_scheme->gradientScheme.gradientLength=50;  
	      		 Boton_Start_scheme->TextColor0 = RGBConvert(0,0,0);                            
                estado_Start = 0;
				enciendo_calefactor=0;	
				Electro_valvula_LAT_BIT = 0;			
				modo_eco = 0;
                tick_inicio_start = 0;
                flag_eco_blink = 0;
				estado_Flow = estado_Flow_pre_eco;
				DRAW_Modo(); 
				
                DRAW_Modo_Eco();   // apaga cartel
               }  

  		       return (1); 
        
			}        
	

// Manejo del botón ECO (MODO ECO)
if ((objMsg == BTN_MSG_PRESSED && pObj->ID == BTN_CONFIG))
{
    BUZZER_LAT_BIT = 1;
    DelayMs(40);
    BUZZER_LAT_BIT = 0;
    
    if(!modo_eco_manual) {
        // ECO DESHABILITADO - Botón se pone GRIS
        modo_eco_manual = 1;
        GOLSetScheme(pObj, Pilot_off);  // Gris (ECO deshabilitado)
        
        // IMPORTANTE: Si está en modo ECO, salir inmediatamente y restaurar flujo
        if(modo_eco) {
            modo_eco = 0;
            estado_Flow = estado_Flow_pre_eco;  // Restaurar flujo anterior
            DRAW_Modo();
            DRAW_Modo_Eco();
            
            // Resetear variables de estabilidad
         //   esperando_estabilidad = 0;
            tick_inicio_start = tick_x_seg;
//            presion_foto_inicial = 0;
            pres_eco_min_ok = 0;
        }
    } else {
        // ECO HABILITADO - Botón se pone VERDE
        modo_eco_manual = 0;
        GOLSetScheme(pObj, Boton_Eco_scheme);  // Verde (ECO habilitado)
    }
    
    SetState(pObj, BTN_DRAW);
    return (1);
}
  


if ((objMsg == BTN_MSG_PRESSED && pObj->ID == BTN_MUTE))
{
    mute_activo = 1;
    BUZZER_LAT_BIT = 0;
    return 1;
}

      
}
//***********************************************< FIN  BUTTON START >********************************************************//


return (1);
}


///////////////////////////////////////////////////////////////////////
//                     MUESTRO el valor de Modo                      //
///////////////////////////////////////////////////////////////////////
void DRAW_Modo(void)
{
    int flow_mostrar;   /* C89 — declaracion al inicio */

    SetColor(RGBConvert(10, 15, 30));
    FillBevel(130, 80, 255, 205, 8);

        SetColor(COL_WHITE);

    SetFont((void*)&Gentium_72);
    OutTextXY(180, 120, ",");
    SetFont((void*)&Gentium_150);

    /* En modo eco mostrar el flujo original, no el 1.0 del eco */
    flow_mostrar = modo_eco ? estado_Flow_pre_eco : estado_Flow;

    switch(flow_mostrar)
    {
        case 0: OutTextXY(120, 50, "0.5"); break;
        case 1: OutTextXY(120, 50, "1.0"); break;
        case 2: OutTextXY(120, 50, "1.5"); break;
        case 3: OutTextXY(120, 50, "2.0"); break;
        case 4: OutTextXY(120, 50, "2.5"); break;
        case 5: OutTextXY(120, 50, "3.0"); break;
        case 6: OutTextXY(120, 50, "3.5"); break;
        case 7: OutTextXY(120, 50, "4.0"); break;
    }
}


void Execut_msg_Handler(void)
{
    int idx;
    int diff_flujo;
    
    // VARIABLES ESTÁTICAS
    static int presion_foto_inicial = 0;
    static BYTE esperando_estabilidad = 0;

    // Procesos de lectura y graficado
    Alarma_sonora();
    Graficar_presion_negativa();
    Graficar_cilindro_CO2();
    Graficar_calefactor();
    Get_Sensor_1();
    Get_Calefactor();
    DRAW_Bottom_Stop();
    Get_venturi();
    PWM_venturi();

    if(estado_Start)
    {
        Electro_valvula_LAT_BIT = 1;
        Estado_electro          = 1;
        Get_presion_actual();

        // 1. Asignación de flujo según el nivel (estado_Flow)
        switch(estado_Flow) {
            case 0: flujo_venturi =  5; break;
            case 1: flujo_venturi = 10; break;
            case 2: flujo_venturi = 15; break;
            case 3: flujo_venturi = 20; break;
            case 4: flujo_venturi = 25; break;
            case 5: flujo_venturi = 30; break;
            case 6: flujo_venturi = 35; break;
            case 7: flujo_venturi = 40; break;
        }

        /* ================================================================
         * MODO NORMAL: Lógica de Reseteo de Contador
         * ================================================================ */
/* ================================================================
 * MODO NORMAL: Lógica de Reseteo de Contador
 * ================================================================ */
if (!modo_eco)
{
    diff_flujo = presion_actual_v - flujo_venturi;
    if (diff_flujo < 0) diff_flujo = -diff_flujo;

    // A. Primero: ¿El flujo es el correcto? (Margen de 0.3 L/min)
    if (diff_flujo <= 3) 
    {
        // B. Si es el primer ciclo de estabilidad, capturamos la "Foto"
        if (esperando_estabilidad == 0) {
            presion_foto_inicial = presion_actual;
            tick_inicio_start = tick_x_seg;
            esperando_estabilidad = 1;
        }

        // C. Definimos la ventana de tolerancia (10% de la foto inicial)
        int margen = (presion_foto_inicial * 10) / 100;
        if (margen < 3) margen = 3;

        // D. PRUEBA DE ESTABILIDAD
        if (presion_actual > (presion_foto_inicial + margen) || 
            presion_actual < (presion_foto_inicial - margen)) 
        {
            presion_foto_inicial = presion_actual;
            tick_inicio_start = tick_x_seg;
        }
        else 
        {
            // E. Verificar si el MODO ECO está HABILITADO (botón en VERDE)
            // Solo entra a ECO si modo_eco_manual == 0 (VERDE = ECO habilitado)
            if (modo_eco_manual == 0) {  // <--- CAMBIO IMPORTANTE
                // Presión DENTRO del margen por 4 segundos? ENTRAR A ECO
                if ((SHORT)(tick_x_seg - tick_inicio_start) > entra_modo_eco) 
                {
                    modo_eco = 1;
                    estado_Flow_pre_eco = estado_Flow;
                    estado_Flow = 1;
                    pres_eco_min_ok = 0;
                    esperando_estabilidad = 0;
                    
                    DRAW_Modo();
                    DRAW_Modo_Eco();
                }
            } else {
                // ECO deshabilitado - resetear el timer para que nunca entre
                tick_inicio_start = tick_x_seg;
            }
        }
    }
    else 
    {
        esperando_estabilidad = 0;
        tick_inicio_start = tick_x_seg;
    }
}

/* ================================================================
 * MODO ECO: Salida por incremento de presión
 * ================================================================ */
else 
{
    if (pres_eco_min_ok == 0) {
        pres_eco_min = presion_actual;
        pres_eco_min_ok = 1;
    }

    if (presion_actual < pres_eco_min) {
        pres_eco_min = presion_actual;
    }

    // Salida si la presión sube un 10%
    if (presion_actual > (pres_eco_min * 110) / 100) 
    {
        modo_eco = 0;
        estado_Flow = estado_Flow_pre_eco;
        
        esperando_estabilidad = 0;
        tick_inicio_start = tick_x_seg;
        presion_foto_inicial = 0;
        
        DRAW_Modo();
        DRAW_Modo_Eco();
    }
}
        state_Stop = 0;
    }
    else // Equipo apagado (estado_Start == 0)
    {
        esperando_estabilidad = 0;
        switch(state_Stop)
        {
            case 0:
                Electro_valvula_LAT_BIT    = 0;
                Estado_electro             = 0;
                time_activo_electrovalvula = tick_x_seg;
                estado_Flow                = estado_Flow_pre_eco;
                state_Stop                 = 1;
                break;
            case 1:
                if((tick_x_seg - time_activo_electrovalvula) >= 2)
                {
                    Get_presion_actual();
                    state_Stop = 2;
                }
                break;
            case 2:
                Get_presion_actual();
                break;
        }
    }

    /* -- Acumulador de volumen -- */
    if (estado_Start && !modo_eco && presion_actual > VAL_SUMO_VOLUMEN)
    {
        if ((SHORT)(tick_x_seg - tick_volumen) >= 1)
        {
            tick_volumen = tick_x_seg;
            volumen_acum += (float)presion_actual_v / 10.0f / VAL_ACUM_VOLUMEN;
            volumen = (int)volumen_acum;
        }
    }

    /* -- Dibujado de volumen -- */
    if (volumen != volumen_prev && currentGDDDemoScreenIndex == 1)
    {
        volumen_prev = volumen;
        SetColor(RGBConvert(10, 15, 30));
        FillBevel(165, 295, 300, 375, 1);
        sprintf(buffer_volumen, "%03d", volumen);
        SetColor(RGBConvert(255, 255, 255));
        SetFont((void*)&Gentium_72);
        OutTextXY(180, 290, (XCHAR*)buffer_volumen);
    }
}
//--------------------------------------------------------------sensores-------------------------------
void PotUpdate(int val) {
    if (potSamplesIndex >= POT_SAMPLES_NUMBER) {
        potSamplesIndex = 0;
    }

    potSamples[potSamplesIndex++] = val;

    
}

int PotentiometerGet(void) {
    DWORD tmp = 0;
    WORD i;

    for (i = 0; i < POT_SAMPLES_NUMBER; i++) {
        tmp += potSamples[i];
    }

    tmp /= POT_SAMPLES_NUMBER;

    return tmp;
}

void Venturi_Update(int val) {
    if (venturi_SamplesIndex >= VENTURI_SAMPLES_NUMBER) {
        venturi_SamplesIndex = 0;
    }

    venturi_Samples[venturi_SamplesIndex++] = val;    
}

int VenturiGet(void) {
    DWORD tmp = 0;
    WORD i;

    for (i = 0; i < VENTURI_SAMPLES_NUMBER; i++) {
        tmp += venturi_Samples[i];
    }

    tmp /= VENTURI_SAMPLES_NUMBER;

    return tmp;
}



void Sensor_1_Update(int val) {
    if (Sensor_1_SamplesIndex >= Sensor_1_SAMPLES_NUMBER) {
        Sensor_1_SamplesIndex = 0;
    }

    Sensor_1_Samples[Sensor_1_SamplesIndex++] = val;
}

int Sensor_1_Get(void) {
    DWORD tmp = 0;
    WORD i;

    for (i = 0; i < Sensor_1_SAMPLES_NUMBER; i++) {
        tmp += Sensor_1_Samples[i];
    }

    tmp /= Sensor_1_SAMPLES_NUMBER;

    return tmp;
}

void Calefactor_Update(int val) {
    if (Calefactor_SamplesIndex >= Calefactor_SAMPLES_NUMBER) {
        Calefactor_SamplesIndex = 0;
    }

    Calefactor_Samples[Calefactor_SamplesIndex++] = val;
}

int Calefactor_Get(void) {
    DWORD tmp = 0;
    WORD i;

    for (i = 0; i < Calefactor_SAMPLES_NUMBER; i++) {
        tmp += Calefactor_Samples[i];
    }

    tmp /= Calefactor_SAMPLES_NUMBER;

    return tmp;
}

void Get_presion_actual(void)
{
    WORD result, result_1, result_2;
    BYTE pos;

    if (tick_x_seg - potTick > 3) {
        potTick = tick_x_seg;

        PotUpdate(adcPot >> 4);
        PotNew   = (PotNew + PotentiometerGet()) >> 1;
        PotNew_2 = PotNew;
        PotNew_1 = PotNew_2 * 0.55f;
        presion_actual = PotNew_1;

        if (currentGDDDemoScreenIndex == 1) {
            if (PotNew_1 != PotOld) {
                PotOld = PotNew_1;

                pos = 0;

                /* Clamp para no desbordar */
                if (presion_actual < 0)    presion_actual = 0;
                if (presion_actual > 9999) presion_actual = 9999;

                result = presion_actual / 1000;
                buffer_actual_pres[pos++] = result + '0';

                result_1 = presion_actual - (1000 * result);
                result   = result_1 / 100;
                buffer_actual_pres[pos++] = result + '0';

                result_2 = result_1 - (100 * result);
                result   = result_2 / 10;
                buffer_actual_pres[pos++] = result + '0';

                result = result_2 - (10 * result);
                buffer_actual_pres[pos++] = result + '0';

                buffer_actual_pres[pos++] = 0;


			#if MOSTRAR_PRESION == 1
                SetColor(RGBConvert(0, 0, 0));
                FillBevel(420, 395, 610, 465, 1);
                SetColor(RGBConvert(255, 140, 0));
                SetFont((void*)&Gentium_72);
                OutTextXY(425, 400, (XCHAR*)buffer_actual_pres);
			#endif
            }
        }
    }
}




//--------------------------VENTURI SENSOR----------------------------------------

void Mostrar_PWM_Pantalla(int pwm_val)
{
    WORD result, result_1, result_2;
    BYTE pos = 0;

    // Limitar por seguridad
    if (pwm_val < 0)    pwm_val = 0;
    if (pwm_val > 9999) pwm_val = 9999;

    result = pwm_val / 1000;
    buffer_velocidad[pos++] = result + '0';

    result_1 = pwm_val - (1000 * result);

    result = result_1 / 100;
    buffer_velocidad[pos++] = result + '0';

    result_2 = result_1 - (100 * result);

    result = result_2 / 10;
    buffer_velocidad[pos++] = result + '0';

    result = result_2 - (10 * result);
    buffer_velocidad[pos++] = result + '0';

    buffer_velocidad[pos++] = 0;

    // Dibujar fondo
    SetColor(RGBConvert(0, 0, 0));
    FillBevel(210, 400, 600, 500, 1);
	
    // Dibujar texto
    SetColor(WHITE);
    SetFont((void*)&Gentium_72);
    OutTextXY(220, 400, (XCHAR*)buffer_velocidad);
}

void Mostrar_flujo_Pantalla(int pwm_val)
{
    WORD result, result_1, result_2;
    BYTE pos = 0;

    // Limitar por seguridad
    if (pwm_val < 0)    pwm_val = 0;
    if (pwm_val > 9999) pwm_val = 9999;

    result = pwm_val / 1000;
    buffer_velocidad[pos++] = result + '0';

    result_1 = pwm_val - (1000 * result);

    result = result_1 / 100;
    buffer_velocidad[pos++] = result + '0';

    result_2 = result_1 - (100 * result);

    result = result_2 / 10;
    buffer_velocidad[pos++] = result + '0';

    result = result_2 - (10 * result);
    buffer_velocidad[pos++] = result + '0';

    buffer_velocidad[pos++] = 0;

    // Dibujar fondo
    SetColor(RGBConvert(0, 0, 0));
    FillBevel(1, 400, 180, 500, 1);

    // Dibujar texto
    SetColor(WHITE);
    SetFont((void*)&Gentium_72);
    OutTextXY(10, 400, (XCHAR*)buffer_velocidad);
}


// Variables globales que necesitas declarar (si no las tienes)


//------------------------------------------------------------------ 
// Función para calcular flujo con ecuación de Venturi
// Q = K * sqrt(?P)
//------------------------------------------------------------------ 
float Calcular_Flujo_Venturi(float adc_corregido)
{
    // Constantes a calibrar
    const float K = CAL_K_VENTURI;           // Constante de flujo (CALIBRAR)
    const float OFFSET = CAL_OFFSET;     // Punto cero del sensor (CALIBRAR)
    
    // Si está por debajo del offset, flujo = 0
    if(adc_corregido <= OFFSET)
        return 0.0f;
    
    // Ecuación de Venturi: Q = K * sqrt(?P)
    float delta_p = adc_corregido - OFFSET;
    float flujo = K * sqrtf(delta_p);
    
    // Limitar rango
    if(flujo < 0.0f) flujo = 0.0f;
    if(flujo > 65.0f) flujo = 65.0f;
    
    return flujo;
}

//------------------------------------------------------------------ 
// Lectura del sensor Venturi
//------------------------------------------------------------------ 
void Get_venturi(void)
{
    float flujo_calculado;
    int   flujo_display;
    int   diff;

    /* Rate limiting — igual que Get_presion_actual()          */
    /* Ajustar el 3 según velocidad deseada (ticks entre lecturas) */
    if ((SHORT)(tick_x_seg - potTick_v) < 3)
        return;
    potTick_v = tick_x_seg;

    Venturi_Update(adc_venturi >> 4);
    PotNew_v   = (PotNew_v + VenturiGet()) >> 1;
    PotNew_2_v = PotNew_v * 0.55f;

    flujo_calculado = Calcular_Flujo_Venturi((float)PotNew_2_v);

    PotNew_1_v    = (int)(flujo_calculado + 0.5f);
    presion_actual_v = PotNew_1_v;

#if MOSTRAR_FLUJO == 1
    Mostrar_flujo_Pantalla(PotNew_2_v);
#endif

    /* SNAP para visualización */
    flujo_display = presion_actual_v;
    if (estado_Start && flujo_venturi > 0) {
        diff = flujo_display - (int)flujo_venturi;
        if (diff < 0) diff = -diff;
        if (diff <= 3)
            flujo_display = (int)flujo_venturi;
    }
venturi_nuevo = 1;
    if (currentGDDDemoScreenIndex == 1) {
        if (PotNew_1_v != PotOld_v || Estado_electro == 0) {
            PotOld_v = PotNew_1_v;
            Mostrar_barra_flujo(presion_actual_v);
        }
    }
}

/* -- Dibuja un dígito 0..4 con bloques de píxeles --------------
 * x, y = esquina superior izquierda
 * sz   = tamaño de cada pixel (2 = bloque 2x2, 3 = bloque 3x3)
 * -------------------------------------------------------------- */
static void Dibujar_digito(int d, int x, int y, int sz)
{
    /* Bitmap 3 columnas x 5 filas — 1=encendido, 0=apagado */
    static const BYTE digits[5][5][3] = {
        { {1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1} },  /* 0 */
        { {0,1,0}, {1,1,0}, {0,1,0}, {0,1,0}, {1,1,1} },  /* 1 */
        { {1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1} },  /* 2 */
        { {1,1,1}, {0,0,1}, {0,1,1}, {0,0,1}, {1,1,1} },  /* 3 */
        { {1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1} },  /* 4 */
    };
    int row, col;

    if (d < 0 || d > 4) return;

    for (row = 0; row < 5; row++) {
        for (col = 0; col < 3; col++) {
            if (digits[d][row][col]) {
                Bar(x + col * (sz + 1),
                    y + row * (sz + 1),
                    x + col * (sz + 1) + sz - 1,
                    y + row * (sz + 1) + sz - 1);
            }
        }
    }
}

/* ================================================================
 * Mostrar_barra_flujo() — horizontal
 * Zona: x1=540, y1=325, x2=770, y2=355
 * Escala: presion_actual_v  0..40  ?  0.0..4.0 L/min
 * ================================================================ */

/* Suavizado del display — independiente del control */
static float flujo_display_smooth = 0.0f;

/* Alpha: 0.05 = muy suave/lento, 0.2 = más rápido
 * Subir si tarda mucho en seguir el valor real          */
#define BARRA_ALPHA   0.08f

#define BAR_X1    540
#define BAR_X2    770
#define BAR_Y1    305
#define BAR_Y2    335
#define BAR_ANCHO (BAR_X2 - BAR_X1)   /* 230 px */
#define BAR_ALTO  (BAR_Y2 - BAR_Y1)   /* 30  px */

void Mostrar_barra_flujo(int pv)
{
    static int relleno_anterior = -1;  /* -1 fuerza el primer dibujo */
    static int marcas_dibujadas = 0;   /* las marcas solo se dibujan una vez */

    int relleno;
    int x_fill;
    int i;
    int x_mark;
    int pv_suave;

    /* Clamp */
    if (pv < 0)  pv = 0;
    if (pv > 40) pv = 40;

    /* Filtro */
    flujo_display_smooth = flujo_display_smooth * (1.0f - BARRA_ALPHA)
                         + (float)pv * BARRA_ALPHA;
    pv_suave = (int)(flujo_display_smooth + 0.5f);

    /* Píxeles de relleno proporcionales */
    relleno = (pv_suave * BAR_ANCHO) / 40;

    /* Si el relleno no cambió, no redibujar */
    if (relleno == relleno_anterior && marcas_dibujadas)
        return;

    relleno_anterior = relleno;
    x_fill = BAR_X1 + relleno;

    /* -- 1. Fondo vacío -- */
    SetColor(RGBConvert(10, 20, 45));
    Bar(BAR_X1, BAR_Y1, BAR_X2, BAR_Y2);

    /* -- 2. Relleno -- */
    if (relleno > 0) {
        if (pv_suave <= 10)
            SetColor(RGBConvert(0, 210, 100));
        else if (pv_suave <= 25)
SetColor(RGBConvert(0, 160, 255));
            
        else
            SetColor(RGBConvert(255, 130, 0));
        Bar(BAR_X1, BAR_Y1, x_fill, BAR_Y2);
    }

    /* -- 3. Borde exterior -- */
    SetColor(RGBConvert(0, 180, 220));
    Bar(BAR_X1,     BAR_Y1,     BAR_X2,     BAR_Y1 + 1);
    Bar(BAR_X1,     BAR_Y2 - 1, BAR_X2,     BAR_Y2);
    Bar(BAR_X1,     BAR_Y1,     BAR_X1 + 1, BAR_Y2);
    Bar(BAR_X2 - 1, BAR_Y1,     BAR_X2,     BAR_Y2);

    /* -- 4. Marcas — solo la primera vez, no cambian nunca -- */
    if (!marcas_dibujadas) {
        for (i = 0; i <= 4; i++) {
            x_mark = BAR_X1 + (i * BAR_ANCHO) / 4;
            SetColor(RGBConvert(80, 120, 160));
            Bar(x_mark, BAR_Y2 + 1, x_mark + 1, BAR_Y2 + 6);
            SetColor(RGBConvert(160, 200, 230));
            Dibujar_digito(i, x_mark - 4, BAR_Y2 + 11, 2);
        }
        marcas_dibujadas = 1;
    }
}
//------------------------------------------------------------------ PWM venturi

static float control_guardado = CAL_CONTROL_INIT;
static float control_temporal = 0.0f;
static float iT0              = 0.0f;
static float last_flujo_f     = 0.0f;

#define FF_GAIN  1.1f

void PWM_venturi(void)
{
    const float Kp           = 0.35f;
    const float Ki           = 0.015f;
    const float DEADBAND     = 0.5f;
    const float DU_MAX       = 5.0f;
    const float INTEGRAL_MAX = 30.0f;
    const float RAMPA        = 2.0f;

    float pwm_min  = CAL_PWM_MIN;
    float pwm_max  = CAL_PWM_MAX;
    float pwm_cero = CAL_PWM_CERO;

    float eT, iT, uT;
    float sp_actual;
    float delta_sp;
    static unsigned char prev_estado = 0;

#if MOSTRAR_FLUJO == 1
    Mostrar_PWM_Pantalla((int)control_temporal);
#endif

    if (Estado_electro == 1)
    {
        if (venturi_nuevo == 0) {
            SetDCOC1PWM((unsigned int)control_temporal);
            return;
        }
        venturi_nuevo = 0;

        sp_actual = (float)flujo_venturi;

        // ===== ARRANQUE =====
        if (prev_estado == 0) {
            control          = control_guardado;
            control_temporal = control;
            iT0              = 0.0f;
            last_flujo_f     = sp_actual;
        }
        prev_estado = 1;

        // ===== CAMBIO SETPOINT =====
        if (last_flujo_f != sp_actual) {
            delta_sp = sp_actual - last_flujo_f;
            control += delta_sp * FF_GAIN;

            if (control > pwm_max) control = pwm_max;
            if (control < pwm_min) control = pwm_min;

            control_temporal = control;
            iT0 = 0.0f;
            last_flujo_f = sp_actual;
        }

        // ===== RAMPA =====
        if (control_temporal < control - 1.0f) {
            control_temporal += RAMPA;
            if (control_temporal > control) control_temporal = control;
            SetDCOC1PWM((unsigned int)control_temporal);
            return;
        }
        if (control_temporal > control + 1.0f) {
            control_temporal -= RAMPA;
            if (control_temporal < control) control_temporal = control;
            SetDCOC1PWM((unsigned int)control_temporal);
            return;
        }
        control_temporal = control;

        // ================= PI =================
        eT = sp_actual - (float)presion_actual_v;

        // ?? BLOQUE ANTI-WINDUP POR ALARMA CO2
        if(alarma_activa)
        {
            iT = 0.0f;

            // limitar error para que no se dispare
            if(eT > 5.0f) eT = 5.0f;

            uT = Kp * eT;

            if (uT >  DU_MAX) uT =  DU_MAX;
            if (uT < -DU_MAX) uT = -DU_MAX;
        }
        // ===== SENSOR BAJO =====
        else if (presion_actual_v < 3)
        {
            iT = 0.0f;

            uT = Kp * eT;

            if (uT >  DU_MAX) uT =  DU_MAX;
            if (uT < -DU_MAX) uT = -DU_MAX;
        }
        // ===== DEADBAND =====
        else if (eT > -DEADBAND && eT < DEADBAND)
        {
            iT = iT0 * 0.97f;
            uT = 0.0f;
        }
        // ===== PI NORMAL =====
        else
        {
            iT = iT0 + (Ki * eT);

            if (iT >  INTEGRAL_MAX) iT =  INTEGRAL_MAX;
            if (iT < -INTEGRAL_MAX) iT = -INTEGRAL_MAX;

            uT = (Kp * eT) + iT;

            if (uT >  DU_MAX) uT =  DU_MAX;
            if (uT < -DU_MAX) uT = -DU_MAX;
        }

        control += uT;

        if (control > pwm_max) { control = pwm_max; iT = iT0 * 0.5f; }
        if (control < pwm_min) { control = pwm_min; iT = iT0 * 0.5f; }

        SetDCOC1PWM((unsigned int)control);

        control_guardado = control;
        control_temporal = control;
        iT0 = iT;
    }
    else
    {
        venturi_nuevo = 0;
        prev_estado   = 0;
        last_flujo_f  = 0.0f;

        if (control_temporal > pwm_cero) {
            control_temporal -= RAMPA * 2.0f;
            if (control_temporal < pwm_cero) control_temporal = pwm_cero;
        } else {
            control_temporal = pwm_cero;
        }

        SetDCOC1PWM((unsigned int)control_temporal);
        iT0 = 0.0f;
    }
}

void Get_Sensor_1(){
//------------------- TOMO SENSOR 1 QUE ES TANQUE DE CO2----------------//

       

       if (tick_x_seg - potTick_11 > 40) {     //16 y 40 queda muy bien
                potTick_11 = tick_x_seg;
                Sensor_1_Update(adc_sensor_1 >> 2);
                Sensor_1_New = (Sensor_1_New + Sensor_1_Get()) >> 1;
                //----------constante del sensor de presion--------//
                //PotNew = ((PotNew/2)+(PotNew/5));
                //-------------------------------------------------//
                if(Sensor_1_New < factor_de_correccion_CO2_cero){                  
                   Sensor_1_New = factor_de_correccion_CO2_cero;
                }

                Sensor_1_New = Sensor_1_New - factor_de_correccion_CO2_cero;

                if(Sensor_1_New < value_de_NO_cilindro_CO2){                
                   state_cilindro_CO2 = 1;
				alarma_cilindro=1;

                }else{state_cilindro_CO2 = 0; alarma_cilindro=0;}

                   presion_CO2 = Sensor_1_New;
                
      
     

}
        //------------------- FIN IMPRESION LA PRESION DEL PACIENTE ----------------//
}

void Get_Calefactor(void)
{
    int setpoint;   /* C89 — declaracion al inicio */

    if ((SHORT)(tick_x_seg - potTick_13) <= 10)
        return;
    potTick_13 = tick_x_seg;

    Calefactor_Update(adc_Calefactor >> 2);
    Calefactor_New   = (Calefactor_New + Calefactor_Get()) >> 1;
    value_Calefactor = Calefactor_New / 2;

#if MOSTRAR_TEMPERATURA == 1
    SetColor(RGBConvert(0, 0, 0));
    FillBevel(330, 420, 480, 464, 1);
    sprintf(buffer_temperatura, " %03d ", value_Calefactor);
    SetColor(WHITE);
    SetFont((void*)&Gentium_72);
    OutTextXY(360, 400, (XCHAR*)buffer_temperatura);
#endif

    /* -- Sin sensor: apagar siempre -- */
    if (value_Calefactor >= CAL_TEMP_ERROR_SENSOR) {
        Calefactor_LAT_BIT = 0;
        return;
    }

    /* -- Setpoint según modo y estado -- */
    if (enciendo_calefactor == 0)
    {
        /* PRECALENTAMIENTO — llegar a CAL_TEMP_PRECAL y quedarse */
        setpoint = CAL_TEMP_PRECAL;   /* = (400+280)/2 = 340 */
        Calefactor_LAT_BIT = (value_Calefactor > setpoint) ? 1 : 0;
    }
    else
    {
        /* START — mantener según nivel elegido por el usuario */
        switch (estado_temp)
        {
            case 0:  setpoint = CAL_TEMP_LOW;  break;  /* BAJA  ? 280 */
            case 1:  setpoint = CAL_TEMP_MED;  break;  /* MEDIA ? 230 */
            case 2:  setpoint = CAL_TEMP_HIGH; break;  /* ALTA  ? 170 */
            default: setpoint = CAL_TEMP_MED;  break;
        }
        Calefactor_LAT_BIT = (value_Calefactor > setpoint) ? 1 : 0;
    }
}
void Get_presion_negativa(){

         if(presion_negativa <= set_presion_negativa){
            Alarma_sonora_pres_negative = 1;
            state_pres_negative = 1;
         } 
}


void Alarma_sonora(){

    //------------------sonido de la alrma de presion negativa-----------------//
     if(Alarma_sonora_pres_negative){

     switch(sonido){
            case 0:
                  if(!T3CONbits.TON){
                     //sonido
                  }
            break;

            case 1:
                  if(!T3CONbits.TON){
                   //sonido
                  }
            break;

            case 2:
                  if(!T3CONbits.TON){
                    //sonido 
                     
                  }
            break;
     } 

  }

 //------------------ FIN sonido de la alrma de presion negativa-----------------//  

 //------------------sonido de la alrma de sobre presion-------------------------// 
  if(Alarma_sonora_de_sobre_presion){

     switch(sonido){
            case 0:
                  if(!T3CONbits.TON){
                     
                  }
            break;

            case 2:
                  if(!T3CONbits.TON){
                   
                     
                  }
            break;
     } 

  }
//------------------FIN sonido de la alrma de sobre presion-------------------------//
}

//========================= GRAFICO MODO ECO =================
void Dibujar_MODO_ECO(int x0, int y0, int sz)
{
    int x = x0;
    int s = sz + 1;   /* paso entre bloques */

    /* Macro: dibuja un bloque en columna c, fila r */
    #define P(c,r) Bar(x+(c)*s, y0+(r)*s, x+(c)*s+sz-1, y0+(r)*s+sz-1)

    /* -- M (5 cols) -- */
    P(0,0);P(4,0);
    P(0,1);P(1,1);P(3,1);P(4,1);
    P(0,2);P(2,2);P(4,2);
    P(0,3);P(4,3);
    P(0,4);P(4,4);
    x += 5*s+3;

    /* -- O -- */
    P(1,0);P(2,0);
    P(0,1);P(3,1);
    P(0,2);P(3,2);
    P(0,3);P(3,3);
    P(1,4);P(2,4);
    x += 4*s+3;

    /* -- D -- */
    P(0,0);P(1,0);P(2,0);
    P(0,1);P(3,1);
    P(0,2);P(3,2);
    P(0,3);P(3,3);
    P(0,4);P(1,4);P(2,4);
    x += 4*s+3;

    /* -- O -- */
    P(1,0);P(2,0);
    P(0,1);P(3,1);
    P(0,2);P(3,2);
    P(0,3);P(3,3);
    P(1,4);P(2,4);
    x += 4*s+3;

    /* -- ESPACIO -- */
    x += 2*s;

    /* -- E -- */
    P(0,0);P(1,0);P(2,0);P(3,0);
    P(0,1);
    P(0,2);P(1,2);P(2,2);
    P(0,3);
    P(0,4);P(1,4);P(2,4);P(3,4);
    x += 4*s+3;

    /* -- C -- */
    P(1,0);P(2,0);P(3,0);
    P(0,1);
    P(0,2);
    P(0,3);
    P(1,4);P(2,4);P(3,4);
    x += 4*s+3;

    /* -- O -- */
    P(1,0);P(2,0);
    P(0,1);P(3,1);
    P(0,2);P(3,2);
    P(0,3);P(3,3);
    P(1,4);P(2,4);

    #undef P
}

void DRAW_Modo_Eco(void)
{
    static BYTE eco_dibujado = 0;

    if(!modo_eco)
    {
        if(eco_dibujado) {
            SetColor(RGBConvert(10, 15, 30));
            SetLineType(SOLID_LINE);
            SetLineThickness(NORMAL_LINE);
            Bar(295, 22, 505, 77);
            eco_dibujado = 0;
        }
        return;
    }

    if(!eco_dibujado) {
        SetColor(RGBConvert(0, 180, 60));
        Bar(295, 25, 505, 75);
        SetColor(WHITE);
        Dibujar_MODO_ECO(320, 40, 3);
        eco_dibujado = 1;
    }
}


void DRAW_Set_Temp(void)
{
    // limpia el receso DER negro
      SetColor(RGBConvert(10, 15, 30));
    FillBevel(547, 85, 670, 228, 8);
    SetFont((void*)&CALIST_36);
    switch(estado_temp)
    {
        case 0:  // BAJA – azul frío
            SetColor(RGBConvert(0, 180, 255));
            OutTextXY(556, 100, "BAJA");
            SetColor(RGBConvert(0, 180, 255));
            FillBevel(560, 210, 660, 235, 4);
            SetColor(RGBConvert(20, 30, 50));
            FillBevel(560, 175, 660, 200, 4);
            FillBevel(560, 140, 660, 165, 4);
			setpoint = CAL_TEMP_LOW;
            break;

        case 1:  // MEDIA – amarillo
            SetColor(RGBConvert(255, 200, 0));
            OutTextXY(548, 100, "MEDIA");
            SetColor(RGBConvert(255, 200, 0));
            FillBevel(560, 210, 660, 235, 4);
            FillBevel(560, 175, 660, 200, 4);
            SetColor(RGBConvert(20, 30, 50));
            FillBevel(560, 140, 660, 165, 4);
			setpoint = CAL_TEMP_MED;
            break;

        case 2:  // ALTA – rojo/naranja
            SetColor(RGBConvert(255, 80, 0));
            OutTextXY(556, 100, "ALTA");
            SetColor(RGBConvert(255, 80, 0));
            FillBevel(560, 210, 660, 235, 4);
            FillBevel(560, 175, 660, 200, 4);
            FillBevel(560, 140, 660, 165, 4);
			setpoint = CAL_TEMP_HIGH;
            break;
    }
}


void Graficar_presion_negativa(){

        if(state_pres_negative){
               
           if(currentGDDDemoScreenIndex == 1){        
         
                  if (tick_x_seg - potTick_5 > 2*8) {    //Para 2 segundos

                   
                   Tiempo_de_carga_de_bateria ++;
                   if(Tiempo_de_carga_de_bateria > 3){   //Tiempo que se carga la bateria
                       Tiempo_de_carga_de_bateria = 0;
                       state_pres_negative = 0;
                       flag_pres_negative = 0;
            SetColor(RGBConvert(0, 0, 0));
			SetLineType(SOLID_LINE);
			SetLineThickness(THICK_LINE);
			Bar(405,400,790,479);
    		SetColor(BLACK);
            SetFont((void*)&CALIST_36);
            OutTextXY(530, 420, "VACIO");
			BUZZER_LAT_BIT=0;
                       
                   }
                   switch(flag_pres_negative){

                        case 0:
                               flag_pres_negative = 1;
                               potTick_5 = tick_x_seg;
                              

			SetColor(RGBConvert(0, 0, 0));
			SetLineType(SOLID_LINE);
			SetLineThickness(THICK_LINE);
			Bar(405,400,790,479);
    		SetColor(BLACK);
            SetFont((void*)&CALIST_36);
            OutTextXY(530, 420, "VACIO");
			BUZZER_LAT_BIT=1;

        
                               
                               break;
                        case 1:
                               flag_pres_negative = 0;
                               potTick_5 = tick_x_seg;  
                              
			SetColor(RGBConvert(0, 255, 0));
			SetLineType(SOLID_LINE);
			SetLineThickness(THICK_LINE);
			Bar(405,400,790,479);
    		SetColor(BLACK);
            SetFont((void*)&CALIST_36);
            OutTextXY(530, 420, "VACIO");
			BUZZER_LAT_BIT=1;
	                               
                               break;
                       
                   }

                 }

   }
}

}
/*************************************************************************
 * Function Name: Graficar_sobre_presion(..)
 *************************************************************************/
void Graficar_sobre_presion(){

 if((value_obstruccion >= medida_de_sobrepresion) && (value_obstruccion <= 39)){       //Para activar las alarma de sobre presion

            state_sobre_presion = 1;
		        
    									if(flag_sobre_presion==0)
											{	
                                                SetColor(RGBConvert(255, 0, 0));
												SetLineType(SOLID_LINE);
												SetLineThickness(THICK_LINE);
												Bar(10,400,395,479);
												SetColor(WHITE);
												SetFont((void*)&CALIST_36);
												OutTextXY(57, 420, "SOBRE-PRESION");  									  			
												flag_sobre_presion=1;
												}
          BUZZER_LAT_BIT=1; 
     
    }else{   
          state_sobre_presion = 0;    
		  flag_sobre_presion=1;
 if(flag_sobre_presion==1 && state_cilindro_CO2 == 0)
											{
											
											
												SetColor(RGBConvert(0, 0, 0));
												SetLineType(SOLID_LINE);
												SetLineThickness(THICK_LINE);
												Bar(10,400,395,479);
												SetColor(BLACK);
												SetFont((void*)&CALIST_36);
												OutTextXY(57, 420, "SOBRE-PRESION");  
												BUZZER_LAT_BIT=0;
												flag_sobre_presion=0;
											
											}


         }


  


}
/*************************************************************************
 * Function Name: Graficar_obstruccion(..)
 * Parameters: none

                                                SetColor(RGBConvert(255, 0, 0));
												SetLineType(SOLID_LINE);
												SetLineThickness(THICK_LINE);
												Bar(10,400,395,479);
												SetColor(WHITE);
												SetFont((void*)&CALIST_36);
												OutTextXY(57, 420, "SOBRE-PRESION");



 *
 *************************************************************************/
void Graficar_obstruccion(){

	   if(value_obstruccion >= presion_de_obstruccion){
        
               SetColor(color_fondo_1);      
               FillBevel(320, 50, 466, 154, 1);         
               state_obstruccion = 1;	


   if(state_obstruccion){         
         									if(flag_obstruccion==0)
											{	
                                                 SetColor(RGBConvert(255, 255, 0));
												SetLineType(SOLID_LINE);
												SetLineThickness(THICK_LINE);
												Bar(405,400,790,479);
												SetColor(BLACK);
												SetFont((void*)&CALIST_36);
												OutTextXY(465, 420, "OBSTRUCCION");  									  			
												flag_obstruccion=1;
												}
   												                        
  BUZZER_LAT_BIT=1; 
       
}
					
}else{
          //Alarma_sonora_de_sobre_presion = 0;
          state_obstruccion = 0;
		  flag_obstruccion=0;
         }


		if(flag_obstruccion==0 && state_obstruccion==0 && state_pres_negative==0)
							{
											
											
								SetColor(RGBConvert(0, 0, 0));
								SetLineType(SOLID_LINE);
								SetLineThickness(THICK_LINE);
								Bar(405,400,790,479);
								SetColor(BLACK);
								SetFont((void*)&CALIST_36);
								OutTextXY(465, 420, "OBSTRUCCION"); 
								BUZZER_LAT_BIT=0;
								flag_obstruccion=0;
											
							}


}



static int boton_mute_creado = 0;
static int estado_anterior = -1;

void Graficar_cilindro_CO2()
{
    if(currentGDDDemoScreenIndex != 1) return;

    if(state_cilindro_CO2)
    {
        alarma_activa = 1;

        // ? MÁS LENTO
        if (tick_x_seg - potTick_5 > 30)   // ? más lento
        {
            potTick_5 = tick_x_seg;
            flag_pres_negative = !flag_pres_negative;
        }

        // ?? SOLO REDIBUJA SI CAMBIA EL ESTADO
        if(flag_pres_negative != estado_anterior)
        {
            estado_anterior = flag_pres_negative;

            if(flag_pres_negative)
            {
                // ?? PRENDIDO
                SetColor(RGBConvert(255, 0, 0));
                Bar(10,400,395,479);

                SetColor(WHITE);
                SetFont((void*)&CALIST_36);
                OutTextXY(12, 420, "BAJA PRESION CO2");

                SetFont((void*)&Font35);
                OutTextXY(358, 424, "2");
            }
            else
            {
                // ? APAGADO TOTAL
                SetColor(RGBConvert(5,8,16));
                Bar(10,400,395,479);
            }
        }

        // ?? SONIDO (sin parpadeo raro)
        if(flag_pres_negative && !mute_activo)
            BUZZER_LAT_BIT = 1;
        else
            BUZZER_LAT_BIT = 0;

        // ===== BOTON =====
        if(!boton_mute_creado)
        {
            BUTTON *pBTN_MUTE;

            pBTN_MUTE = BtnCreate( BTN_MUTE,
                        540, 400, 650, 475,
                        6,
                        BTN_DRAW,
                        NULL,
                        NULL,
                        Pilot_off
            );

            if(pBTN_MUTE == NULL)
            {
                CreateError(0);
                while(1);
            }

            boton_mute_creado = 1;
        }

        Dibujar_icono_mute_grande(558, 406, 255,255,255);
    }
    else
    {
        alarma_activa = 0;
        mute_activo = 0;
        flag_pres_negative = 0;
        estado_anterior = -1;

        BUZZER_LAT_BIT = 0;

        // limpiar cartel
        SetColor(RGBConvert(5,8,16));
        Bar(10,400,395,479);

        // borrar botón
        if(boton_mute_creado)
        {
            GOLDeleteObjectByID(BTN_MUTE);
            boton_mute_creado = 0;

            SetColor(RGBConvert(5,8,16));
            Bar(540,400,650,475);
        }
    }
}

/*************************************************************************
 * Function Name: Graficar_calefactor(..)
 * Parameters: none
 *
*************************************************************************/
void Graficar_calefactor(){        
}
/*******************************************************************
*        Animacion del boton de Stop
*******************************************************************/
void DRAW_Bottom_Stop(){
}


void Dibujar_icono_mute_grande(int x, int y, int r, int g, int b)
{
    WORD color = RGBConvert(r, g, b);

    // ===== PARLANTE =====
    SetColor(WHITE);

    // caja (más grande)
    Bar(x,     y+15,  x+18,  y+45);

    // cono
    Line(x+18, y+15, x+42, y+5);
    Line(x+18, y+45, x+42, y+55);
    Line(x+42, y+5,  x+42, y+55);

    // relleno
    Bar(x+20, y+20, x+36, y+40);

    // ===== CRUZ MUTE =====
    SetColor(RGBConvert(255, 0, 0));

    // cruz grande
    Line(x+55, y+15, x+80, y+45);
    Line(x+55, y+45, x+80, y+15);

    // grosor extra
    Line(x+56, y+15, x+81, y+45);
    Line(x+56, y+45, x+81, y+15);
}