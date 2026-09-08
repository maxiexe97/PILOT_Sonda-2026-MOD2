/*****************************************************************************
 * FileName:        comm_pkt.h
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
#ifndef COMM_PKT_HEADER_FILE
#define COMM_PKT_HEADER_FILE

/*****************************************************************************
 * Section: Includes
 *****************************************************************************/
#include "GenericTypeDefs.h"

/*****************************************************************************
 * Section: Command Defines
 *****************************************************************************/
#define COMM_PKT_ECHO                        (0x3F)
#define COMM_PKT_MEMORY_ERASE                (0x01)
#define COMM_PKT_MEMORY_SECTOR_ERASE         (0x02)
#define COMM_PKT_MEMORY_WRITE                (0x03)
#define COMM_PKT_MEMORY_READ                 (0x04)
#define COMM_PKT_MAX_PAYLOAD_SIZE            (0x05)
#define COMM_PKT_MEMORY_VERIFY               (0x06)
#define COMM_PKT_MEMORY_DONE                 (0x07)

#define COMM_PKT_REPLY                      1
#define COMM_PKT_ACK                        1
#define COMM_PKT_NACK                       0
/*****************************************************************************
 * Section: Structures
 *****************************************************************************/
typedef struct
{
    BYTE cmd:   6;
    BYTE reply: 1;
    BYTE ack:   1;
    BYTE check_sum;
    WORD length;
}COMM_PKT_HDR;

typedef enum
{
    COMM_PKT_MEDIA_SERIAL_PORT,
    COMM_PKT_MEDIA_USB
}COMM_PKT_MEDIA;

/*****************************************************************************
 * Section: Function Prototypes
 *****************************************************************************/
/*****************************************************************************
 * COMM_PKT_Init
 *****************************************************************************/
void COMM_PKT_Init(void);
/*****************************************************************************
 * COMM_PKT_Update
 *****************************************************************************/
void COMM_PKT_Update(COMM_PKT_MEDIA media);
/*****************************************************************************
 * COMM_PKT_RxPacketAvailable
 *****************************************************************************/
BOOL COMM_PKT_RxPacketAvailable(void);
/*****************************************************************************
 * COMM_PKT_GetRxPacket
 *****************************************************************************/
BYTE *COMM_PKT_GetRxPacket(void);
/*****************************************************************************
 * COMM_PKT_IsPacketValid
 *****************************************************************************/
BOOL COMM_PKT_IsPacketValid(BYTE *packet);
/*****************************************************************************
 * COMM_PKT_SendCommand
 *****************************************************************************/
void COMM_PKT_SendCommand(COMM_PKT_MEDIA media, BYTE cmd, BYTE *payload, WORD payloadSize);
/*****************************************************************************
 * COMM_PKT_SendReply
 *****************************************************************************/
void COMM_PKT_SendReply(COMM_PKT_MEDIA media, BYTE cmd, BYTE ack, BYTE *payload, WORD payloadSize);
#endif
