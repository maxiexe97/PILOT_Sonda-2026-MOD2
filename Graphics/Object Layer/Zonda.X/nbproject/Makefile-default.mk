#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED="../../../Board Support Package/drv_spi.c" ../../../Microchip/Graphics/GOLSchemeDefault.c "../../../Board Support Package/MCHP25LC256.c" "../../../Board Support Package/TouchScreen.c" "../../../Board Support Package/Beep.c" "../../../Board Support Package/SST25VF016.c" ../Font25PixelsHeight.c ../Font35PixelsHeight.c ../FontCALIST_36.c "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLFontDefault.c" "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLSmallFont.c" ../../../Microchip/Common/TimeDelay.c ../../../Microchip/Graphics/Drivers/SSD1963.c ../../../Microchip/Graphics/Window.c ../../../Microchip/Graphics/Button.c ../../../Microchip/Graphics/CheckBox.c ../../../Microchip/Graphics/EditBox.c ../../../Microchip/Graphics/GOL.c ../../../Microchip/Graphics/Grid.c ../../../Microchip/Graphics/GroupBox.c ../../../Microchip/Graphics/ListBox.c ../../../Microchip/Graphics/Meter.c ../../../Microchip/Graphics/Picture.c ../../../Microchip/Graphics/Primitive.c ../../../Microchip/Graphics/ProgressBar.c ../../../Microchip/Graphics/RadioButton.c ../../../Microchip/Graphics/RoundDial.c ../../../Microchip/Graphics/Slider.c ../../../Microchip/Graphics/StaticText.c ../../../Microchip/Graphics/DigitalMeter.c "../../../Board Support Package/TouchScreenResistive.c" ../Monofont.c ../Gentium_72.c ../Gentium_16.c ../Gentium_200.c "../Pictures C32.c" ../Gentium_150.c ../dee_emulation_pic32.c ../Touch_Pilot_7/GDD_Screens.c ../Touch_Pilot_7/GDD_X_Event_Handler.c ../Main_Zonda.c "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/ADS7843.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1687970324/drv_spi.o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o ${OBJECTDIR}/_ext/1687970324/Beep.o ${OBJECTDIR}/_ext/1687970324/SST25VF016.o ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o ${OBJECTDIR}/_ext/1472/FontCALIST_36.o ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o ${OBJECTDIR}/_ext/1860783399/TimeDelay.o ${OBJECTDIR}/_ext/1919882987/SSD1963.o ${OBJECTDIR}/_ext/803622919/Window.o ${OBJECTDIR}/_ext/803622919/Button.o ${OBJECTDIR}/_ext/803622919/CheckBox.o ${OBJECTDIR}/_ext/803622919/EditBox.o ${OBJECTDIR}/_ext/803622919/GOL.o ${OBJECTDIR}/_ext/803622919/Grid.o ${OBJECTDIR}/_ext/803622919/GroupBox.o ${OBJECTDIR}/_ext/803622919/ListBox.o ${OBJECTDIR}/_ext/803622919/Meter.o ${OBJECTDIR}/_ext/803622919/Picture.o ${OBJECTDIR}/_ext/803622919/Primitive.o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ${OBJECTDIR}/_ext/803622919/RadioButton.o ${OBJECTDIR}/_ext/803622919/RoundDial.o ${OBJECTDIR}/_ext/803622919/Slider.o ${OBJECTDIR}/_ext/803622919/StaticText.o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o ${OBJECTDIR}/_ext/1472/Monofont.o ${OBJECTDIR}/_ext/1472/Gentium_72.o ${OBJECTDIR}/_ext/1472/Gentium_16.o ${OBJECTDIR}/_ext/1472/Gentium_200.o "${OBJECTDIR}/_ext/1472/Pictures C32.o" ${OBJECTDIR}/_ext/1472/Gentium_150.o ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o ${OBJECTDIR}/_ext/1472/Main_Zonda.o ${OBJECTDIR}/_ext/2050749925/ADS7843.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1687970324/drv_spi.o.d ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d ${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d ${OBJECTDIR}/_ext/1687970324/Beep.o.d ${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d ${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d ${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d ${OBJECTDIR}/_ext/1919882987/SSD1963.o.d ${OBJECTDIR}/_ext/803622919/Window.o.d ${OBJECTDIR}/_ext/803622919/Button.o.d ${OBJECTDIR}/_ext/803622919/CheckBox.o.d ${OBJECTDIR}/_ext/803622919/EditBox.o.d ${OBJECTDIR}/_ext/803622919/GOL.o.d ${OBJECTDIR}/_ext/803622919/Grid.o.d ${OBJECTDIR}/_ext/803622919/GroupBox.o.d ${OBJECTDIR}/_ext/803622919/ListBox.o.d ${OBJECTDIR}/_ext/803622919/Meter.o.d ${OBJECTDIR}/_ext/803622919/Picture.o.d ${OBJECTDIR}/_ext/803622919/Primitive.o.d ${OBJECTDIR}/_ext/803622919/ProgressBar.o.d ${OBJECTDIR}/_ext/803622919/RadioButton.o.d ${OBJECTDIR}/_ext/803622919/RoundDial.o.d ${OBJECTDIR}/_ext/803622919/Slider.o.d ${OBJECTDIR}/_ext/803622919/StaticText.o.d ${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d ${OBJECTDIR}/_ext/1472/Monofont.o.d ${OBJECTDIR}/_ext/1472/Gentium_72.o.d ${OBJECTDIR}/_ext/1472/Gentium_16.o.d ${OBJECTDIR}/_ext/1472/Gentium_200.o.d "${OBJECTDIR}/_ext/1472/Pictures C32.o.d" ${OBJECTDIR}/_ext/1472/Gentium_150.o.d ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d ${OBJECTDIR}/_ext/1472/Main_Zonda.o.d ${OBJECTDIR}/_ext/2050749925/ADS7843.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1687970324/drv_spi.o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o ${OBJECTDIR}/_ext/1687970324/Beep.o ${OBJECTDIR}/_ext/1687970324/SST25VF016.o ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o ${OBJECTDIR}/_ext/1472/FontCALIST_36.o ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o ${OBJECTDIR}/_ext/1860783399/TimeDelay.o ${OBJECTDIR}/_ext/1919882987/SSD1963.o ${OBJECTDIR}/_ext/803622919/Window.o ${OBJECTDIR}/_ext/803622919/Button.o ${OBJECTDIR}/_ext/803622919/CheckBox.o ${OBJECTDIR}/_ext/803622919/EditBox.o ${OBJECTDIR}/_ext/803622919/GOL.o ${OBJECTDIR}/_ext/803622919/Grid.o ${OBJECTDIR}/_ext/803622919/GroupBox.o ${OBJECTDIR}/_ext/803622919/ListBox.o ${OBJECTDIR}/_ext/803622919/Meter.o ${OBJECTDIR}/_ext/803622919/Picture.o ${OBJECTDIR}/_ext/803622919/Primitive.o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ${OBJECTDIR}/_ext/803622919/RadioButton.o ${OBJECTDIR}/_ext/803622919/RoundDial.o ${OBJECTDIR}/_ext/803622919/Slider.o ${OBJECTDIR}/_ext/803622919/StaticText.o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o ${OBJECTDIR}/_ext/1472/Monofont.o ${OBJECTDIR}/_ext/1472/Gentium_72.o ${OBJECTDIR}/_ext/1472/Gentium_16.o ${OBJECTDIR}/_ext/1472/Gentium_200.o ${OBJECTDIR}/_ext/1472/Pictures\ C32.o ${OBJECTDIR}/_ext/1472/Gentium_150.o ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o ${OBJECTDIR}/_ext/1472/Main_Zonda.o ${OBJECTDIR}/_ext/2050749925/ADS7843.o

# Source Files
SOURCEFILES=../../../Board Support Package/drv_spi.c ../../../Microchip/Graphics/GOLSchemeDefault.c ../../../Board Support Package/MCHP25LC256.c ../../../Board Support Package/TouchScreen.c ../../../Board Support Package/Beep.c ../../../Board Support Package/SST25VF016.c ../Font25PixelsHeight.c ../Font35PixelsHeight.c ../FontCALIST_36.c ../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLFontDefault.c ../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLSmallFont.c ../../../Microchip/Common/TimeDelay.c ../../../Microchip/Graphics/Drivers/SSD1963.c ../../../Microchip/Graphics/Window.c ../../../Microchip/Graphics/Button.c ../../../Microchip/Graphics/CheckBox.c ../../../Microchip/Graphics/EditBox.c ../../../Microchip/Graphics/GOL.c ../../../Microchip/Graphics/Grid.c ../../../Microchip/Graphics/GroupBox.c ../../../Microchip/Graphics/ListBox.c ../../../Microchip/Graphics/Meter.c ../../../Microchip/Graphics/Picture.c ../../../Microchip/Graphics/Primitive.c ../../../Microchip/Graphics/ProgressBar.c ../../../Microchip/Graphics/RadioButton.c ../../../Microchip/Graphics/RoundDial.c ../../../Microchip/Graphics/Slider.c ../../../Microchip/Graphics/StaticText.c ../../../Microchip/Graphics/DigitalMeter.c ../../../Board Support Package/TouchScreenResistive.c ../Monofont.c ../Gentium_72.c ../Gentium_16.c ../Gentium_200.c ../Pictures C32.c ../Gentium_150.c ../dee_emulation_pic32.c ../Touch_Pilot_7/GDD_Screens.c ../Touch_Pilot_7/GDD_X_Event_Handler.c ../Main_Zonda.c ../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/ADS7843.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1687970324/drv_spi.o: ../../../Board\ Support\ Package/drv_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/drv_spi.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" -o ${OBJECTDIR}/_ext/1687970324/drv_spi.o "../../../Board Support Package/drv_spi.c"  
	
${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o: ../../../Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" -o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ../../../Microchip/Graphics/GOLSchemeDefault.c  
	
${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o: ../../../Board\ Support\ Package/MCHP25LC256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d" -o ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o "../../../Board Support Package/MCHP25LC256.c"  
	
${OBJECTDIR}/_ext/1687970324/TouchScreen.o: ../../../Board\ Support\ Package/TouchScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o "../../../Board Support Package/TouchScreen.c"  
	
${OBJECTDIR}/_ext/1687970324/Beep.o: ../../../Board\ Support\ Package/Beep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/Beep.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/Beep.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/Beep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/Beep.o.d" -o ${OBJECTDIR}/_ext/1687970324/Beep.o "../../../Board Support Package/Beep.c"  
	
${OBJECTDIR}/_ext/1687970324/SST25VF016.o: ../../../Board\ Support\ Package/SST25VF016.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/SST25VF016.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d" -o ${OBJECTDIR}/_ext/1687970324/SST25VF016.o "../../../Board Support Package/SST25VF016.c"  
	
${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o: ../Font25PixelsHeight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d" -o ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o ../Font25PixelsHeight.c  
	
${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o: ../Font35PixelsHeight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d" -o ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o ../Font35PixelsHeight.c  
	
${OBJECTDIR}/_ext/1472/FontCALIST_36.o: ../FontCALIST_36.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/FontCALIST_36.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d" -o ${OBJECTDIR}/_ext/1472/FontCALIST_36.o ../FontCALIST_36.c  
	
${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o: ../../../../../ARTRHO&GO/ARTRHO&GO\ 2019/Microchip/Graphics/GOLFontDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2050749925" 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d" -o ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLFontDefault.c"  
	
${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o: ../../../../../ARTRHO&GO/ARTRHO&GO\ 2019/Microchip/Graphics/GOLSmallFont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2050749925" 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d" -o ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLSmallFont.c"  
	
${OBJECTDIR}/_ext/1860783399/TimeDelay.o: ../../../Microchip/Common/TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1860783399" 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mno-float -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -MMD -MF "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d" -o ${OBJECTDIR}/_ext/1860783399/TimeDelay.o ../../../Microchip/Common/TimeDelay.c  
	
${OBJECTDIR}/_ext/1919882987/SSD1963.o: ../../../Microchip/Graphics/Drivers/SSD1963.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1919882987" 
	@${RM} ${OBJECTDIR}/_ext/1919882987/SSD1963.o.d 
	@${RM} ${OBJECTDIR}/_ext/1919882987/SSD1963.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1919882987/SSD1963.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1919882987/SSD1963.o.d" -o ${OBJECTDIR}/_ext/1919882987/SSD1963.o ../../../Microchip/Graphics/Drivers/SSD1963.c  
	
${OBJECTDIR}/_ext/803622919/Window.o: ../../../Microchip/Graphics/Window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Window.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Window.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Window.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Window.o.d" -o ${OBJECTDIR}/_ext/803622919/Window.o ../../../Microchip/Graphics/Window.c  
	
${OBJECTDIR}/_ext/803622919/Button.o: ../../../Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Button.o.d" -o ${OBJECTDIR}/_ext/803622919/Button.o ../../../Microchip/Graphics/Button.c  
	
${OBJECTDIR}/_ext/803622919/CheckBox.o: ../../../Microchip/Graphics/CheckBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/CheckBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/CheckBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" -o ${OBJECTDIR}/_ext/803622919/CheckBox.o ../../../Microchip/Graphics/CheckBox.c  
	
${OBJECTDIR}/_ext/803622919/EditBox.o: ../../../Microchip/Graphics/EditBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/EditBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/EditBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/EditBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/EditBox.o.d" -o ${OBJECTDIR}/_ext/803622919/EditBox.o ../../../Microchip/Graphics/EditBox.c  
	
${OBJECTDIR}/_ext/803622919/GOL.o: ../../../Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/GOL.o.d" -o ${OBJECTDIR}/_ext/803622919/GOL.o ../../../Microchip/Graphics/GOL.c  
	
${OBJECTDIR}/_ext/803622919/Grid.o: ../../../Microchip/Graphics/Grid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Grid.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Grid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Grid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Grid.o.d" -o ${OBJECTDIR}/_ext/803622919/Grid.o ../../../Microchip/Graphics/Grid.c  
	
${OBJECTDIR}/_ext/803622919/GroupBox.o: ../../../Microchip/Graphics/GroupBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/GroupBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GroupBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" -o ${OBJECTDIR}/_ext/803622919/GroupBox.o ../../../Microchip/Graphics/GroupBox.c  
	
${OBJECTDIR}/_ext/803622919/ListBox.o: ../../../Microchip/Graphics/ListBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/ListBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/ListBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ListBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/ListBox.o.d" -o ${OBJECTDIR}/_ext/803622919/ListBox.o ../../../Microchip/Graphics/ListBox.c  
	
${OBJECTDIR}/_ext/803622919/Meter.o: ../../../Microchip/Graphics/Meter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Meter.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Meter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Meter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Meter.o.d" -o ${OBJECTDIR}/_ext/803622919/Meter.o ../../../Microchip/Graphics/Meter.c  
	
${OBJECTDIR}/_ext/803622919/Picture.o: ../../../Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Picture.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Picture.o.d" -o ${OBJECTDIR}/_ext/803622919/Picture.o ../../../Microchip/Graphics/Picture.c  
	
${OBJECTDIR}/_ext/803622919/Primitive.o: ../../../Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Primitive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Primitive.o.d" -o ${OBJECTDIR}/_ext/803622919/Primitive.o ../../../Microchip/Graphics/Primitive.c  
	
${OBJECTDIR}/_ext/803622919/ProgressBar.o: ../../../Microchip/Graphics/ProgressBar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/ProgressBar.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/ProgressBar.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" -o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ../../../Microchip/Graphics/ProgressBar.c  
	
${OBJECTDIR}/_ext/803622919/RadioButton.o: ../../../Microchip/Graphics/RadioButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/RadioButton.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/RadioButton.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" -o ${OBJECTDIR}/_ext/803622919/RadioButton.o ../../../Microchip/Graphics/RadioButton.c  
	
${OBJECTDIR}/_ext/803622919/RoundDial.o: ../../../Microchip/Graphics/RoundDial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/RoundDial.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/RoundDial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" -o ${OBJECTDIR}/_ext/803622919/RoundDial.o ../../../Microchip/Graphics/RoundDial.c  
	
${OBJECTDIR}/_ext/803622919/Slider.o: ../../../Microchip/Graphics/Slider.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Slider.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Slider.o.d" -o ${OBJECTDIR}/_ext/803622919/Slider.o ../../../Microchip/Graphics/Slider.c  
	
${OBJECTDIR}/_ext/803622919/StaticText.o: ../../../Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/StaticText.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/StaticText.o.d" -o ${OBJECTDIR}/_ext/803622919/StaticText.o ../../../Microchip/Graphics/StaticText.c  
	
${OBJECTDIR}/_ext/803622919/DigitalMeter.o: ../../../Microchip/Graphics/DigitalMeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/DigitalMeter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" -o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ../../../Microchip/Graphics/DigitalMeter.c  
	
${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o: ../../../Board\ Support\ Package/TouchScreenResistive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o "../../../Board Support Package/TouchScreenResistive.c"  
	
${OBJECTDIR}/_ext/1472/Monofont.o: ../Monofont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Monofont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Monofont.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Monofont.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Monofont.o.d" -o ${OBJECTDIR}/_ext/1472/Monofont.o ../Monofont.c  
	
${OBJECTDIR}/_ext/1472/Gentium_72.o: ../Gentium_72.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_72.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_72.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_72.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_72.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_72.o ../Gentium_72.c  
	
${OBJECTDIR}/_ext/1472/Gentium_16.o: ../Gentium_16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_16.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_16.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_16.o ../Gentium_16.c  
	
${OBJECTDIR}/_ext/1472/Gentium_200.o: ../Gentium_200.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_200.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_200.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_200.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_200.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_200.o ../Gentium_200.c  
	
${OBJECTDIR}/_ext/1472/Pictures\ C32.o: ../Pictures\ C32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} "${OBJECTDIR}/_ext/1472/Pictures C32.o".d 
	@${RM} "${OBJECTDIR}/_ext/1472/Pictures C32.o" 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Pictures C32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Pictures C32.o.d" -o "${OBJECTDIR}/_ext/1472/Pictures C32.o" "../Pictures C32.c"  
	
${OBJECTDIR}/_ext/1472/Gentium_150.o: ../Gentium_150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_150.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_150.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_150.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_150.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_150.o ../Gentium_150.c  
	
${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o: ../dee_emulation_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d" -o ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o ../dee_emulation_pic32.c  
	
${OBJECTDIR}/_ext/1290698017/GDD_Screens.o: ../Touch_Pilot_7/GDD_Screens.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1290698017" 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d" -o ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o ../Touch_Pilot_7/GDD_Screens.c  
	
${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o: ../Touch_Pilot_7/GDD_X_Event_Handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1290698017" 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d" -o ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o ../Touch_Pilot_7/GDD_X_Event_Handler.c  
	
${OBJECTDIR}/_ext/1472/Main_Zonda.o: ../Main_Zonda.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_Zonda.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_Zonda.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main_Zonda.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Main_Zonda.o.d" -o ${OBJECTDIR}/_ext/1472/Main_Zonda.o ../Main_Zonda.c  
	
${OBJECTDIR}/_ext/2050749925/ADS7843.o: ../../../../../ARTRHO&GO/ARTRHO&GO\ 2019/Microchip/Graphics/ADS7843.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2050749925" 
	@${RM} ${OBJECTDIR}/_ext/2050749925/ADS7843.o.d 
	@${RM} ${OBJECTDIR}/_ext/2050749925/ADS7843.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2050749925/ADS7843.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/2050749925/ADS7843.o.d" -o ${OBJECTDIR}/_ext/2050749925/ADS7843.o "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/ADS7843.c"  
	
else
${OBJECTDIR}/_ext/1687970324/drv_spi.o: ../../../Board\ Support\ Package/drv_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/drv_spi.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" -o ${OBJECTDIR}/_ext/1687970324/drv_spi.o "../../../Board Support Package/drv_spi.c"  
	
${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o: ../../../Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" -o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ../../../Microchip/Graphics/GOLSchemeDefault.c  
	
${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o: ../../../Board\ Support\ Package/MCHP25LC256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o.d" -o ${OBJECTDIR}/_ext/1687970324/MCHP25LC256.o "../../../Board Support Package/MCHP25LC256.c"  
	
${OBJECTDIR}/_ext/1687970324/TouchScreen.o: ../../../Board\ Support\ Package/TouchScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o "../../../Board Support Package/TouchScreen.c"  
	
${OBJECTDIR}/_ext/1687970324/Beep.o: ../../../Board\ Support\ Package/Beep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/Beep.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/Beep.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/Beep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/Beep.o.d" -o ${OBJECTDIR}/_ext/1687970324/Beep.o "../../../Board Support Package/Beep.c"  
	
${OBJECTDIR}/_ext/1687970324/SST25VF016.o: ../../../Board\ Support\ Package/SST25VF016.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/SST25VF016.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/SST25VF016.o.d" -o ${OBJECTDIR}/_ext/1687970324/SST25VF016.o "../../../Board Support Package/SST25VF016.c"  
	
${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o: ../Font25PixelsHeight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o.d" -o ${OBJECTDIR}/_ext/1472/Font25PixelsHeight.o ../Font25PixelsHeight.c  
	
${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o: ../Font35PixelsHeight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o.d" -o ${OBJECTDIR}/_ext/1472/Font35PixelsHeight.o ../Font35PixelsHeight.c  
	
${OBJECTDIR}/_ext/1472/FontCALIST_36.o: ../FontCALIST_36.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/FontCALIST_36.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/FontCALIST_36.o.d" -o ${OBJECTDIR}/_ext/1472/FontCALIST_36.o ../FontCALIST_36.c  
	
${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o: ../../../../../ARTRHO&GO/ARTRHO&GO\ 2019/Microchip/Graphics/GOLFontDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2050749925" 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o.d" -o ${OBJECTDIR}/_ext/2050749925/GOLFontDefault.o "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLFontDefault.c"  
	
${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o: ../../../../../ARTRHO&GO/ARTRHO&GO\ 2019/Microchip/Graphics/GOLSmallFont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2050749925" 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d 
	@${RM} ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o.d" -o ${OBJECTDIR}/_ext/2050749925/GOLSmallFont.o "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/GOLSmallFont.c"  
	
${OBJECTDIR}/_ext/1860783399/TimeDelay.o: ../../../Microchip/Common/TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1860783399" 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mno-float -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -MMD -MF "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d" -o ${OBJECTDIR}/_ext/1860783399/TimeDelay.o ../../../Microchip/Common/TimeDelay.c  
	
${OBJECTDIR}/_ext/1919882987/SSD1963.o: ../../../Microchip/Graphics/Drivers/SSD1963.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1919882987" 
	@${RM} ${OBJECTDIR}/_ext/1919882987/SSD1963.o.d 
	@${RM} ${OBJECTDIR}/_ext/1919882987/SSD1963.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1919882987/SSD1963.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1919882987/SSD1963.o.d" -o ${OBJECTDIR}/_ext/1919882987/SSD1963.o ../../../Microchip/Graphics/Drivers/SSD1963.c  
	
${OBJECTDIR}/_ext/803622919/Window.o: ../../../Microchip/Graphics/Window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Window.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Window.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Window.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Window.o.d" -o ${OBJECTDIR}/_ext/803622919/Window.o ../../../Microchip/Graphics/Window.c  
	
${OBJECTDIR}/_ext/803622919/Button.o: ../../../Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Button.o.d" -o ${OBJECTDIR}/_ext/803622919/Button.o ../../../Microchip/Graphics/Button.c  
	
${OBJECTDIR}/_ext/803622919/CheckBox.o: ../../../Microchip/Graphics/CheckBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/CheckBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/CheckBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" -o ${OBJECTDIR}/_ext/803622919/CheckBox.o ../../../Microchip/Graphics/CheckBox.c  
	
${OBJECTDIR}/_ext/803622919/EditBox.o: ../../../Microchip/Graphics/EditBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/EditBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/EditBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/EditBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/EditBox.o.d" -o ${OBJECTDIR}/_ext/803622919/EditBox.o ../../../Microchip/Graphics/EditBox.c  
	
${OBJECTDIR}/_ext/803622919/GOL.o: ../../../Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/GOL.o.d" -o ${OBJECTDIR}/_ext/803622919/GOL.o ../../../Microchip/Graphics/GOL.c  
	
${OBJECTDIR}/_ext/803622919/Grid.o: ../../../Microchip/Graphics/Grid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Grid.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Grid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Grid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Grid.o.d" -o ${OBJECTDIR}/_ext/803622919/Grid.o ../../../Microchip/Graphics/Grid.c  
	
${OBJECTDIR}/_ext/803622919/GroupBox.o: ../../../Microchip/Graphics/GroupBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/GroupBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GroupBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" -o ${OBJECTDIR}/_ext/803622919/GroupBox.o ../../../Microchip/Graphics/GroupBox.c  
	
${OBJECTDIR}/_ext/803622919/ListBox.o: ../../../Microchip/Graphics/ListBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/ListBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/ListBox.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ListBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/ListBox.o.d" -o ${OBJECTDIR}/_ext/803622919/ListBox.o ../../../Microchip/Graphics/ListBox.c  
	
${OBJECTDIR}/_ext/803622919/Meter.o: ../../../Microchip/Graphics/Meter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Meter.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Meter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Meter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Meter.o.d" -o ${OBJECTDIR}/_ext/803622919/Meter.o ../../../Microchip/Graphics/Meter.c  
	
${OBJECTDIR}/_ext/803622919/Picture.o: ../../../Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Picture.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Picture.o.d" -o ${OBJECTDIR}/_ext/803622919/Picture.o ../../../Microchip/Graphics/Picture.c  
	
${OBJECTDIR}/_ext/803622919/Primitive.o: ../../../Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Primitive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Primitive.o.d" -o ${OBJECTDIR}/_ext/803622919/Primitive.o ../../../Microchip/Graphics/Primitive.c  
	
${OBJECTDIR}/_ext/803622919/ProgressBar.o: ../../../Microchip/Graphics/ProgressBar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/ProgressBar.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/ProgressBar.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" -o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ../../../Microchip/Graphics/ProgressBar.c  
	
${OBJECTDIR}/_ext/803622919/RadioButton.o: ../../../Microchip/Graphics/RadioButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/RadioButton.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/RadioButton.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" -o ${OBJECTDIR}/_ext/803622919/RadioButton.o ../../../Microchip/Graphics/RadioButton.c  
	
${OBJECTDIR}/_ext/803622919/RoundDial.o: ../../../Microchip/Graphics/RoundDial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/RoundDial.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/RoundDial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" -o ${OBJECTDIR}/_ext/803622919/RoundDial.o ../../../Microchip/Graphics/RoundDial.c  
	
${OBJECTDIR}/_ext/803622919/Slider.o: ../../../Microchip/Graphics/Slider.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Slider.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/Slider.o.d" -o ${OBJECTDIR}/_ext/803622919/Slider.o ../../../Microchip/Graphics/Slider.c  
	
${OBJECTDIR}/_ext/803622919/StaticText.o: ../../../Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/StaticText.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/StaticText.o.d" -o ${OBJECTDIR}/_ext/803622919/StaticText.o ../../../Microchip/Graphics/StaticText.c  
	
${OBJECTDIR}/_ext/803622919/DigitalMeter.o: ../../../Microchip/Graphics/DigitalMeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/803622919" 
	@${RM} ${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/DigitalMeter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" -o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ../../../Microchip/Graphics/DigitalMeter.c  
	
${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o: ../../../Board\ Support\ Package/TouchScreenResistive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1687970324" 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o "../../../Board Support Package/TouchScreenResistive.c"  
	
${OBJECTDIR}/_ext/1472/Monofont.o: ../Monofont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Monofont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Monofont.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Monofont.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Monofont.o.d" -o ${OBJECTDIR}/_ext/1472/Monofont.o ../Monofont.c  
	
${OBJECTDIR}/_ext/1472/Gentium_72.o: ../Gentium_72.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_72.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_72.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_72.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_72.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_72.o ../Gentium_72.c  
	
${OBJECTDIR}/_ext/1472/Gentium_16.o: ../Gentium_16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_16.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_16.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_16.o ../Gentium_16.c  
	
${OBJECTDIR}/_ext/1472/Gentium_200.o: ../Gentium_200.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_200.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_200.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_200.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_200.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_200.o ../Gentium_200.c  
	
${OBJECTDIR}/_ext/1472/Pictures\ C32.o: ../Pictures\ C32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} "${OBJECTDIR}/_ext/1472/Pictures C32.o".d 
	@${RM} "${OBJECTDIR}/_ext/1472/Pictures C32.o" 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Pictures C32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Pictures C32.o.d" -o "${OBJECTDIR}/_ext/1472/Pictures C32.o" "../Pictures C32.c"  
	
${OBJECTDIR}/_ext/1472/Gentium_150.o: ../Gentium_150.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_150.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Gentium_150.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Gentium_150.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Gentium_150.o.d" -o ${OBJECTDIR}/_ext/1472/Gentium_150.o ../Gentium_150.c  
	
${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o: ../dee_emulation_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o.d" -o ${OBJECTDIR}/_ext/1472/dee_emulation_pic32.o ../dee_emulation_pic32.c  
	
${OBJECTDIR}/_ext/1290698017/GDD_Screens.o: ../Touch_Pilot_7/GDD_Screens.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1290698017" 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1290698017/GDD_Screens.o.d" -o ${OBJECTDIR}/_ext/1290698017/GDD_Screens.o ../Touch_Pilot_7/GDD_Screens.c  
	
${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o: ../Touch_Pilot_7/GDD_X_Event_Handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1290698017" 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o.d" -o ${OBJECTDIR}/_ext/1290698017/GDD_X_Event_Handler.o ../Touch_Pilot_7/GDD_X_Event_Handler.c  
	
${OBJECTDIR}/_ext/1472/Main_Zonda.o: ../Main_Zonda.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_Zonda.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_Zonda.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main_Zonda.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/1472/Main_Zonda.o.d" -o ${OBJECTDIR}/_ext/1472/Main_Zonda.o ../Main_Zonda.c  
	
${OBJECTDIR}/_ext/2050749925/ADS7843.o: ../../../../../ARTRHO&GO/ARTRHO&GO\ 2019/Microchip/Graphics/ADS7843.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2050749925" 
	@${RM} ${OBJECTDIR}/_ext/2050749925/ADS7843.o.d 
	@${RM} ${OBJECTDIR}/_ext/2050749925/ADS7843.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2050749925/ADS7843.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/Graphics" -I"../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Include/MDD File System" -I"../../../Board Support Package" -I"../../../Microchip/Include" -I"../../../Microchip/Include/Graphics" -I"../Configs" -I"../Touch_Pilot_7" -I"." -Os -MMD -MF "${OBJECTDIR}/_ext/2050749925/ADS7843.o.d" -o ${OBJECTDIR}/_ext/2050749925/ADS7843.o "../../../../../ARTRHO&GO/ARTRHO&GO 2019/Microchip/Graphics/ADS7843.c"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -Os -o dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}       -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=3000,--defsym=_min_stack_size=2000,-L"..",-L".",-Map="${DISTDIR}/Zonda.X.${IMAGE_TYPE}.map" 
else
dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -Os -o dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}       -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=3000,--defsym=_min_stack_size=2000,-L"..",-L".",-Map="${DISTDIR}/Zonda.X.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\pic32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Zonda.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
