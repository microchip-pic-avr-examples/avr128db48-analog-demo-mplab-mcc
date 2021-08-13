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
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "ADCPrint.h"

#define ENABLE_ADC_EVENT_START() { ADC0.CTRLA = 0x00; ADC0.EVCTRL = 0x01; ADC0.CTRLA = 0x81; } while (0)
const char* gains[] = {"1", "1.07", "1.14", "1.33", "2", "2.67", "4", "8", "16"};

const char* getCurrentGain(void)
{
    uint8_t index = 0;
    
    if (((OPAMP.OP0INMUX & OPAMP_MUXNEG_gm) >> OPAMP_MUXNEG_gp) == 0x02)
    {
        //Unity Gain, no action
    }
    else
    {
        //Start at an offset of 1
        index += 1;
        
        //Add the resistor ladder position
        index += (OPAMP.OP0RESMUX & OPAMP_MUXWIP_gm) >> OPAMP_MUXWIP_gp;
    }
    
    return gains[index];
}

void adjustGain(void)
{
    if (((OPAMP.OP0INMUX & OPAMP_MUXNEG_gm) >> OPAMP_MUXNEG_gp) == 0x02)
    {
        //Unity Gain -> Gain Step 0
        OPAMP.OP0INMUX = (OPAMP.OP0INMUX & ~OPAMP_MUXNEG_gm) | (0x01 << OPAMP_MUXNEG_gp);
        OPAMP.OP0RESMUX = 0x15;
    }
    else
    {
        //Gain Ladder Active
        
        //Offset by 1
        uint8_t index = 1;
        
        //Add the Current Gain Ladder Position
        index += (OPAMP.OP0RESMUX & OPAMP_MUXWIP_gm) >> OPAMP_MUXWIP_gp;
        
        if (index == 8)
        {
            //Roll over to Unity Gain
            index = 0;
            
            //Set for Unity Gain
            OPAMP.OP0INMUX = (OPAMP.OP0INMUX & ~OPAMP_MUXNEG_gm) | (0x02 << OPAMP_MUXNEG_gp);            
        }
        
        //Update Gain Ladder
        OPAMP.OP0RESMUX = (OPAMP.OP0RESMUX & ~OPAMP_MUXWIP_gm) | (index << OPAMP_MUXWIP_gp);
    }
    
    //Wait for the OPAMP to Settle
    while (!OPAMP_IsOP0Settled());
}

int main(void)
{
    SYSTEM_Initialize();
    
    //Enable Event Start for ADC
    ENABLE_ADC_EVENT_START();
    
    //Start the RTC
    RTC_Start();
    
    //Write an empty byte to set the USART TXCIF flags
    USART3_Write(0x00);
    
    float result = 0.0;
    
    //Assumes 3.3V operation, 12-bit single-ended results
    const float bitsPerVolt = 3.3 / 4096;
    
    while(1)
    { 
        if (getGainFlag())
        {
            //Gain Changed
            clearGainFlag();
            
            //Increase gain of the OPAMPs
            adjustGain();
            
            //Print Results
            printf("New Gain: %s\n\r\n\r", getCurrentGain());
            
            //Restart the RTC
            RTC_Start();
        }
        else if (getResultFlag())
        {
            //Result Changed
            clearResultFlag();
            
            //Convert result to floating point
            result = ADC0_GetConversionResult() * bitsPerVolt;        
            
            //Blink LED
            LED0_Toggle();
            
            //Print Results
            printf("Current Gain: %s\n\r", getCurrentGain());
            printf("Measured: %1.3fV\n\r\n\r", result);
        }
        
        //Wait for UART to finish
        while (USART3_IsTxBusy());
        USART3.STATUS = USART_TXCIF_bm;

        //If the button was pressed while printing
        if (getGainFlag())
            continue;
        
        //Go to Sleep
        asm ("SLEEP");
        asm ("NOP");
    }    
}