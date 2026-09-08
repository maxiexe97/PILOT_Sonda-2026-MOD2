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
#include "comm_pkt.h"
#include "comm_pkt_callback.h"
#include "HardwareProfile.h"

BYTE rxPacket[COMM_PKT_RX_MAX_SIZE + sizeof(COMM_PKT_HDR) + 64] __attribute__((aligned(4)));
WORD rxPacketIdx;

BYTE COMM_PKT_GenerateCheckSum(BYTE *payload, WORD payloadLength);

/*****************************************************************************
 * COMM_PKT_Init
 *****************************************************************************/
void COMM_PKT_Init(void)
{
    rxPacketIdx = 0;
}
/*****************************************************************************
 * COMM_PKT_Update
 *****************************************************************************/
void COMM_PKT_Update(COMM_PKT_MEDIA media)
{
    if(COMM_PKT_DataAvailable(media))
    {
        rxPacketIdx = COMM_PKT_GetData(media, rxPacket, rxPacketIdx);
    }
}
/*****************************************************************************
 * COMM_PKT_RxPacketAvailable
 *****************************************************************************/
BOOL COMM_PKT_RxPacketAvailable(void)
{
    COMM_PKT_HDR *hdr;

    if(rxPacketIdx < sizeof(COMM_PKT_HDR))
        return FALSE;

    hdr = (COMM_PKT_HDR *)rxPacket;

    if(rxPacketIdx < (sizeof(COMM_PKT_HDR) + hdr->length))
        return FALSE;

    if(rxPacketIdx > (sizeof(COMM_PKT_HDR) + hdr->length))
        return FALSE;

    return TRUE;
}
/*****************************************************************************
 * COMM_PKT_GetRxPacket
 *****************************************************************************/
BYTE *COMM_PKT_GetRxPacket(void)
{
    rxPacketIdx = 0;

    return rxPacket;
}
/*****************************************************************************
 * COMM_PKT_IsPacketValid
 *****************************************************************************/
BOOL COMM_PKT_IsPacketValid(BYTE *packet)
{
    COMM_PKT_HDR *hdr;

    hdr = (COMM_PKT_HDR *)packet;

    if(hdr->length > (COMM_PKT_RX_MAX_SIZE))
        return FALSE;

    if(hdr->check_sum != COMM_PKT_GenerateCheckSum(packet + sizeof(COMM_PKT_HDR), hdr->length))
        return FALSE;

    return TRUE;
}
/*****************************************************************************
 * COMM_PKT_SendCommand
 *****************************************************************************/
void COMM_PKT_SendCommand(COMM_PKT_MEDIA media, BYTE cmd, BYTE *payload, WORD payloadSize)
{
    COMM_PKT_HDR hdr;

    hdr.cmd = cmd;
    hdr.reply = 0;
    hdr.ack = 0;
    hdr.length = payloadSize;
    hdr.check_sum = COMM_PKT_GenerateCheckSum(payload, payloadSize);

    COMM_PKT_SendData(media, (BYTE *)&hdr, sizeof(hdr));
    COMM_PKT_SendData(media, payload, payloadSize);
}
/*****************************************************************************
 * COMM_PKT_SendCommand
 *****************************************************************************/
void COMM_PKT_SendReply(COMM_PKT_MEDIA media, BYTE cmd, BYTE ack, BYTE *payload, WORD payloadSize)
{
    COMM_PKT_HDR hdr;

    hdr.cmd = cmd;
    hdr.reply = COMM_PKT_REPLY;
    hdr.ack = ack;
    hdr.length = payloadSize;
    hdr.check_sum = COMM_PKT_GenerateCheckSum(payload, payloadSize);

    COMM_PKT_SendData(media, (BYTE *)&hdr, sizeof(hdr));
    COMM_PKT_SendData(media, payload, payloadSize);
}
/*****************************************************************************
 * COMM_PKT_Update
 *****************************************************************************/
BYTE COMM_PKT_GenerateCheckSum(BYTE *payload, WORD payloadLength)
{
    WORD i;
    BYTE check_sum = 0xFF;

    for(i = 0; i < payloadLength; i++)
    {
        check_sum += payload[i];    
    }

    check_sum *= -1;

    return check_sum;
}
