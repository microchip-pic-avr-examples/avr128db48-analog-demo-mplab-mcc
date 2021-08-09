/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

#ifndef OPAMP_H_INCLUDED
#define OPAMP_H_INCLUDED

#include "../system/utils/compiler.h"
#include <stdbool.h>

#define OPAMP_TIMEBASE_VALUE (1)

/**
  @Summary
    Initializes the OPAMP_Initialize.

  @Description
    This routine initializes the OPAMP_Initialize.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None
    
   @Example
    <code>
    OPAMP_Initialize();
    </code>
*/
void OPAMP_Initialize(void);

/**
 * @brief Enables the OPAMP System
 * @return None 
 * @param None
 */
void OPAMP_EnableSystem(void);

/**
 * @brief Disables the OPAMP System
 * @return None 
 * @param None
 */
void OPAMP_DisableSystem(void);
        
//OP0 Voltage Follower APIs

/**
 * @brief Sets OP0's positive input as per user selection
 * @return None 
 * @param [in] Desired positive input
          For the available positive inputs, refer to OPAMP_MUXPOS_t enum from the device header file
 */
void OPAMP_SetOP0PositiveInMux(OPAMP_OP0INMUX_MUXPOS_t value);

/**
 * @brief Sets OP0's settle time
 * @return None 
 * @param [in] Desired settle time of 0 to 127 in us
 */
void OPAMP_SetOP0SettleTime(uint8_t settleTime);

/**
 * @brief Checks if OP0's settling time is finished
 * @return boolean 
 * @param None
 */
bool OPAMP_IsOP0Settled(void);

/**
 * @brief Sets OP0's offset calibration
 * @return None 
 * @param [in] Desired offset
 */
void OPAMP_SetOP0OffsetCalibration(uint8_t calValue);
        
#endif /* OPAMP_H_INCLUDED */
