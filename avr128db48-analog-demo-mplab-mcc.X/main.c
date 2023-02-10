/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2021] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "ADCPrint.h"

#define ENABLE_ADC_EVENT_START() { ADC0.CTRLA &= ~ADC_ENABLE_bm; ADC0.EVCTRL = 0x01; ADC0.CTRLA |= ADC_ENABLE_bm; } while (0)
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

void onButtonPress(void)
{
    //Stop the RTC
    RTC_Stop();
    
    //Indicate that the OPAMP gain needs to be changed
    setGainFlag();
}

void enableRTCStandby(void)
{
     while (RTC.STATUS & RTC_CTRLABUSY_bm);
     RTC.CTRLA |= RTC_RUNSTDBY_bm | RTC_RTCEN_bm;
}

void waitForUART(void)
{
    while (!UART3_IsTxDone());
    USART3.STATUS = USART_TXCIF_bm;
}

int main(void)
{
    SYSTEM_Initialize();
    
    //Attach Callback Function to ADC for Result Ready
    ADC0_RegisterResrdyCallback(&setResultFlag);
    
    //Attach Callback Function to CCL for Button Press Events
    LUT4_OUT_SetInterruptHandler(&onButtonPress);
    
    //Enable Event Start for ADC
    ENABLE_ADC_EVENT_START();
    
    //Start the RTC
    enableRTCStandby();
    
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
            
            //FIXED VERSION
            printf("Measured: ");
            
            //Wait for the last string to finish, since the next line is very slow
            waitForUART();
            
            printf("%1.3fV\n\r\n\r", result);
        }
        
        //Wait for UART to finish
        waitForUART();
        
        //If the button was pressed while printing
        if (getGainFlag())
            continue;
        
        //Go to Sleep
        asm ("SLEEP");
        asm ("NOP");
    }    
}