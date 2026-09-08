/*****************************************************************************
 * FileName:        comm_pkt.c
 * Dependencies:    See Include Section
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30, MPLAB C32
 * Linker:          MPLAB LINK30, MPLAB LINK32
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright © 2010 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).  
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 * Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 09/01/10	   ...
 *****************************************************************************/
/*****************************************************************************
 * Section: Includes
 *****************************************************************************/
#include "GenericTypeDefs.h"
#include "HardwareProfile.h"
#include "comm_pkt.h"
#ifdef USE_COMM_PKT_MEDIA_SERIAL_PORT
#include "UART.h"
#endif
#ifdef USE_COMM_PKT_MEDIA_USB
#include "USB/usb.h"
#include "USB/usb_function_generic.h"
#endif

#ifdef USE_COMM_PKT_MEDIA_USB
extern unsigned char OUTPacket[64];	//User application buffer for receiving and holding OUT packets sent from the host
extern unsigned char INPacket[64];		//User application buffer for sending IN packets to the host
extern USB_HANDLE USBGenericOutHandle;
extern USB_HANDLE USBGenericInHandle;
#endif

/*****************************************************************************
 * COMM_PKT_Update
 *****************************************************************************/
BOOL COMM_PKT_DataAvailable(COMM_PKT_MEDIA media)
{

#ifdef USE_COMM_PKT_MEDIA_SERIAL_PORT
    if(media == COMM_PKT_MEDIA_SERIAL_PORT)
        return UARTIsDA();
#endif

#ifdef USE_COMM_PKT_MEDIA_USB
    if(media == COMM_PKT_MEDIA_USB)
    {
        if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1)) 
            return FALSE;

        return !USBHandleBusy(USBGenericOutHandle);
    }
#endif

    return FALSE;
}
/*****************************************************************************
 * COMM_PKT_Update
 *****************************************************************************/
WORD COMM_PKT_GetData(COMM_PKT_MEDIA media, BYTE *buffer, WORD offset)
{
    if(offset >= (COMM_PKT_RX_MAX_SIZE + sizeof(COMM_PKT_HDR)))
        return offset;

#ifdef USE_COMM_PKT_MEDIA_SERIAL_PORT
    if(media == COMM_PKT_MEDIA_SERIAL_PORT)
    {
        while(UARTIsDA())
        {
            buffer[offset] = UARTGetChar();
            offset++;
        }
    }
#endif

#ifdef USE_COMM_PKT_MEDIA_USB
    if(media == COMM_PKT_MEDIA_USB)
    {
        while(!USBHandleBusy(USBGenericOutHandle))
        {
            WORD len = USBHandleGetLength(USBGenericOutHandle);
    
            if(len > 0)
            {
                memcpy(&buffer[offset], OUTPacket, len);
                offset += len;
            }

            USBGenericOutHandle = USBGenRead(USBGEN_EP_NUM,(BYTE*)&OUTPacket,USBGEN_EP_SIZE);
        }
    }
#endif

    return offset;
}
/*****************************************************************************
 * COMM_PKT_Update
 *****************************************************************************/
void COMM_PKT_SendData(COMM_PKT_MEDIA media, BYTE *data, WORD size)
{
#ifdef USE_COMM_PKT_MEDIA_SERIAL_PORT
    if(media == COMM_PKT_MEDIA_SERIAL_PORT)
    {
        while(size)
        {
            UARTPutChar(*data);
            data++;
            size--;
        }
    }
#endif

#ifdef USE_COMM_PKT_MEDIA_USB
    if(media == COMM_PKT_MEDIA_USB)
    {
        while(size)
        {
            WORD len = size;

            while(USBHandleBusy(USBGenericInHandle))
                ;

            if(len > USBGEN_EP_SIZE)
                len = USBGEN_EP_SIZE;

            memcpy(INPacket, data, len);
            USBGenericInHandle = USBGenWrite(USBGEN_EP_NUM,(BYTE*)&INPacket,len);

            data += len;
            size -= len;
        }
    }
#endif
}
