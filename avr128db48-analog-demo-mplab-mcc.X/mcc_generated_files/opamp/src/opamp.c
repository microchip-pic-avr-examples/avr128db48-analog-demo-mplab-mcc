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

#include "../opamp.h"

void OPAMP_Initialize(void)
{
    OPAMP_DisableSystem();
    
    //TIMEBASE 1; 
    OPAMP.TIMEBASE = OPAMP_TIMEBASE_VALUE << OPAMP_TIMEBASE_gp;
    
    //DBGRUN enabled; 
    OPAMP.DBGCTRL = 0x1;
    
    //IRSEL FULL; 
    OPAMP.PWRCTRL = 0x0;
    
    //OP0 Configuration : Voltage Follower
    //OP0 Gain : 1
    
    //MUXNEG OPn output (unity gain); MUXPOS Positive input pin for OPn; 
    OPAMP.OP0INMUX = 0x20;
    
    //MUXBOT Multiplexer off; MUXTOP Multiplexer off; MUXWIP R1 = 15R, R2 = 1R, R2/R1 = 0.07; 
    OPAMP.OP0RESMUX = 0x0;
    
    //ALWAYSON enabled; EVENTEN disabled; OUTMODE Output Driver in Normal Mode; RUNSTBY enabled; 
    OPAMP.OP0CTRLA = 0x85;
    
    //SETTLE 127; 
    OPAMP.OP0SETTLE = 0x7F;
    
    //OP1 Configuration : Connected Directly to Pins
    
    //MUXNEG Negative input pin for OPn; MUXPOS Positive input pin for OPn; 
    OPAMP.OP1INMUX = 0x0;
    
    //MUXBOT Multiplexer off; MUXTOP Multiplexer off; MUXWIP R1 = 15R, R2 = 1R, R2/R1 = 0.07; 
    OPAMP.OP1RESMUX = 0x0;
    
    //ALWAYSON disabled; EVENTEN enabled; OUTMODE Output Driver Off; RUNSTBY disabled; 
    OPAMP.OP1CTRLA = 0x2;
    
    //SETTLE 127; 
    OPAMP.OP1SETTLE = 0x7F;
    
    //OP2 Configuration : Connected Directly to Pins
    
    //MUXNEG Negative input pin for OPn; MUXPOS Positive input pin for OPn; 
    OPAMP.OP2INMUX = 0x0;
    
    //MUXBOT Multiplexer off; MUXTOP Multiplexer off; MUXWIP R1 = 15R, R2 = 1R, R2/R1 = 0.07; 
    OPAMP.OP2RESMUX = 0x0;
    
    //ALWAYSON disabled; EVENTEN enabled; OUTMODE Output Driver Off; RUNSTBY disabled; 
    OPAMP.OP2CTRLA = 0x2;
    
    //SETTLE 127; 
    OPAMP.OP2SETTLE = 0x7F;
    
    OPAMP_EnableSystem();
}

void OPAMP_EnableSystem(void)
{
    OPAMP.CTRLA |= OPAMP_ENABLE_bm;
}

void OPAMP_DisableSystem(void)
{
    OPAMP.CTRLA &= ~OPAMP_ENABLE_bm;
}

//OP0 Voltage Follower APIs

void OPAMP_SetOP0PositiveInMux(OPAMP_OP0INMUX_MUXPOS_t value)
{
    OPAMP.OP0INMUX = (OPAMP.OP0INMUX & ~OPAMP_MUXPOS_gm) | value;
}

void OPAMP_SetOP0SettleTime(uint8_t settleTime)
{
    if (settleTime > 127) {
        settleTime = 127;
    }
    OPAMP.OP0SETTLE = settleTime;
}

bool OPAMP_IsOP0Settled(void)
{
    return OPAMP.OP0STATUS > 0;
}

void OPAMP_SetOP0OffsetCalibration(uint8_t calValue)
{
    OPAMP.OP0CAL = calValue;
}
