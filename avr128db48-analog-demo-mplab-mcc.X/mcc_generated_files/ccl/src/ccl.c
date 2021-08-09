/**
  CCL Generated Driver File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    ccl.c
 
  @Summary
    This is the generated driver implementation file for the CCL driver
 
  @Description
    This source file provides APIs for driver for CCL.
    Generation Information :
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLABX v5.40
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

#include "../ccl.h"
#include "../../system/system.h"
#include "../../../ADCPrint.h"

int8_t CCL_Initialize(void)
{
    //INTMODE0 INTDISABLE; INTMODE1 INTDISABLE; INTMODE2 INTDISABLE; INTMODE3 INTDISABLE; 
    CCL.INTCTRL0 = 0x0;
    
    //INTMODE4 RISING; INTMODE5 INTDISABLE; 
    CCL.INTCTRL1 = 0x1;
    
    //INT 0x0; 
    CCL.INTFLAGS = 0x0;
        
    //INSEL0 MASK; INSEL1 MASK; 
    CCL.LUT0CTRLB = 0x0;
    
    //INSEL2 MASK; 
    CCL.LUT0CTRLC = 0x0;
    
    //INSEL0 MASK; INSEL1 MASK; 
    CCL.LUT1CTRLB = 0x0;
    
    //INSEL2 MASK; 
    CCL.LUT1CTRLC = 0x0;
    
    //INSEL0 MASK; INSEL1 MASK; 
    CCL.LUT2CTRLB = 0x0;
    
    //INSEL2 MASK; 
    CCL.LUT2CTRLC = 0x0;
    
    //INSEL0 MASK; INSEL1 MASK; 
    CCL.LUT3CTRLB = 0x0;
    
    //INSEL2 MASK; 
    CCL.LUT3CTRLC = 0x0;
    
    //INSEL0 MASK; INSEL1 MASK; 
    CCL.LUT4CTRLB = 0x0;
    
    //INSEL2 IN2; 
    CCL.LUT4CTRLC = 0x5;
    
    //INSEL0 MASK; INSEL1 MASK; 
    CCL.LUT5CTRLB = 0x0;
    
    //INSEL2 MASK; 
    CCL.LUT5CTRLC = 0x0;
    
    //SEQSEL DISABLE; 
    CCL.SEQCTRL0 = 0x0;
    
    //SEQSEL DISABLE; 
    CCL.SEQCTRL1 = 0x0;
    
    //SEQSEL DISABLE; 
    CCL.SEQCTRL2 = 0x0;
    
    //TRUTH 0; 
    CCL.TRUTH0 = 0x0;
    
    //TRUTH 0; 
    CCL.TRUTH1 = 0x0;
    
    //TRUTH 0; 
    CCL.TRUTH2 = 0x0;
    
    //TRUTH 0; 
    CCL.TRUTH3 = 0x0;
    
    //TRUTH 16; 
    CCL.TRUTH4 = 0x10;
    
    //TRUTH 0; 
    CCL.TRUTH5 = 0x0;
    
    //CLKSRC CLKPER; EDGEDET DIS; ENABLE disabled; FILTSEL DISABLE; OUTEN disabled; 
    CCL.LUT0CTRLA = 0x0;

    //CLKSRC CLKPER; EDGEDET DIS; ENABLE disabled; FILTSEL DISABLE; OUTEN disabled; 
    CCL.LUT1CTRLA = 0x0;

    //CLKSRC CLKPER; EDGEDET DIS; ENABLE disabled; FILTSEL DISABLE; OUTEN disabled; 
    CCL.LUT2CTRLA = 0x0;

    //CLKSRC CLKPER; EDGEDET DIS; ENABLE disabled; FILTSEL DISABLE; OUTEN disabled; 
    CCL.LUT3CTRLA = 0x0;

    //CLKSRC OSC1K; EDGEDET EN; ENABLE enabled; FILTSEL FILTER; OUTEN disabled; 
    CCL.LUT4CTRLA = 0xAD;

    //CLKSRC CLKPER; EDGEDET DIS; ENABLE disabled; FILTSEL DISABLE; OUTEN disabled; 
    CCL.LUT5CTRLA = 0x0;

    //ENABLE enabled; RUNSTDBY enabled; 
    CCL.CTRLA = 0x41;

    return 0;
}

ISR(CCL_CCL_vect)
{   
    //Stop the RTC
    RTC_Stop();
    
    //Set Gain Flag
    setGainFlag();
    
    CCL.INTFLAGS = CCL_INT4_bm;
}
