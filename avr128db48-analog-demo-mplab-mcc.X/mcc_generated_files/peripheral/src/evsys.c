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

#include <xc.h>

// Set the EVSYS module to the options selected in the user interface.

int8_t EVSYS_Initialize(void) {
    // CHANNEL0 RTC_PIT_DIV1024; 
    EVSYS.CHANNEL0 = 0xB;
    // CHANNEL1 ADC0_RESRDY; 
    EVSYS.CHANNEL1 = 0x24;
    // CHANNEL2 OFF; 
    EVSYS.CHANNEL2 = 0x0;
    // CHANNEL3 OFF; 
    EVSYS.CHANNEL3 = 0x0;
    // CHANNEL4 OFF; 
    EVSYS.CHANNEL4 = 0x0;
    // CHANNEL5 OFF; 
    EVSYS.CHANNEL5 = 0x0;
    // CHANNEL6 OFF; 
    EVSYS.CHANNEL6 = 0x0;
    // CHANNEL7 OFF; 
    EVSYS.CHANNEL7 = 0x0;
    // CHANNEL8 OFF; 
    EVSYS.CHANNEL8 = 0x0;
    // CHANNEL9 OFF; 
    EVSYS.CHANNEL9 = 0x0;
    // SWEVENTA CH0; 
    EVSYS.SWEVENTA = 0x1;
    // SWEVENTB CH8; 
    EVSYS.SWEVENTB = 0x0;
    // USER CHANNEL0; 
    EVSYS.USERADC0START = 0x1;
    // USER OFF; 
    EVSYS.USERCCLLUT0A = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT0B = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT1A = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT1B = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT2A = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT2B = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT3A = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT3B = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT4A = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT4B = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT5A = 0x0;
    // USER OFF; 
    EVSYS.USERCCLLUT5B = 0x0;
    // USER OFF; 
    EVSYS.USEREVSYSEVOUTA = 0x0;
    // USER OFF; 
    EVSYS.USEREVSYSEVOUTB = 0x0;
    // USER OFF; 
    EVSYS.USEREVSYSEVOUTC = 0x0;
    // USER OFF; 
    EVSYS.USEREVSYSEVOUTD = 0x0;
    // USER OFF; 
    EVSYS.USEREVSYSEVOUTE = 0x0;
    // USER OFF; 
    EVSYS.USEREVSYSEVOUTF = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP0DISABLE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP0DRIVE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP0DUMP = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP0ENABLE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP1DISABLE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP1DRIVE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP1DUMP = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP1ENABLE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP2DISABLE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP2DRIVE = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP2DUMP = 0x0;
    // USER OFF; 
    EVSYS.USEROPAMP2ENABLE = 0x0;
    // USER OFF; 
    EVSYS.USERTCA0CNTA = 0x0;
    // USER OFF; 
    EVSYS.USERTCA0CNTB = 0x0;
    // USER OFF; 
    EVSYS.USERTCA1CNTA = 0x0;
    // USER OFF; 
    EVSYS.USERTCA1CNTB = 0x0;
    // USER OFF; 
    EVSYS.USERTCB0CAPT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB0COUNT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB1CAPT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB1COUNT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB2CAPT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB2COUNT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB3CAPT = 0x0;
    // USER OFF; 
    EVSYS.USERTCB3COUNT = 0x0;
    // USER OFF; 
    EVSYS.USERTCD0INPUTA = 0x0;
    // USER OFF; 
    EVSYS.USERTCD0INPUTB = 0x0;
    // USER OFF; 
    EVSYS.USERUSART0IRDA = 0x0;
    // USER OFF; 
    EVSYS.USERUSART1IRDA = 0x0;
    // USER OFF; 
    EVSYS.USERUSART2IRDA = 0x0;
    // USER OFF; 
    EVSYS.USERUSART3IRDA = 0x0;
    // USER OFF; 
    EVSYS.USERUSART4IRDA = 0x0;
    return 0;
}
