/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.0.0
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set IO_PB0 aliases
#define IO_PB0_SetHigh() do { PORTB_OUTSET = 0x1; } while(0)
#define IO_PB0_SetLow() do { PORTB_OUTCLR = 0x1; } while(0)
#define IO_PB0_Toggle() do { PORTB_OUTTGL = 0x1; } while(0)
#define IO_PB0_GetValue() (VPORTB.IN & (0x1 << 0))
#define IO_PB0_SetDigitalInput() do { PORTB_DIRCLR = 0x1; } while(0)
#define IO_PB0_SetDigitalOutput() do { PORTB_DIRSET = 0x1; } while(0)
#define IO_PB0_SetPullUp() do { PORTB_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PB0_ResetPullUp() do { PORTB_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PB0_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PB0_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PB0_DisableInterruptOnChange() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PB0_EnableInterruptForBothEdges() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PB0_EnableInterruptForRisingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PB0_EnableInterruptForFallingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PB0_DisableDigitalInputBuffer() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PB0_EnableInterruptForLowLevelSensing() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SW0 aliases
#define SW0_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define SW0_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define SW0_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define SW0_GetValue() (VPORTB.IN & (0x1 << 2))
#define SW0_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define SW0_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define SW0_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SW0_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SW0_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define SW0_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SW0_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SW0_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SW0_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SW0_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SW0_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SW0_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PD1 aliases
#define IO_PD1_SetHigh() do { PORTD_OUTSET = 0x2; } while(0)
#define IO_PD1_SetLow() do { PORTD_OUTCLR = 0x2; } while(0)
#define IO_PD1_Toggle() do { PORTD_OUTTGL = 0x2; } while(0)
#define IO_PD1_GetValue() (VPORTD.IN & (0x1 << 1))
#define IO_PD1_SetDigitalInput() do { PORTD_DIRCLR = 0x2; } while(0)
#define IO_PD1_SetDigitalOutput() do { PORTD_DIRSET = 0x2; } while(0)
#define IO_PD1_SetPullUp() do { PORTD_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD1_ResetPullUp() do { PORTD_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD1_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD1_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD1_DisableInterruptOnChange() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD1_EnableInterruptForBothEdges() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD1_EnableInterruptForRisingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD1_EnableInterruptForFallingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD1_DisableDigitalInputBuffer() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD1_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set Output_OPAMP aliases
#define Output_OPAMP_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define Output_OPAMP_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define Output_OPAMP_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define Output_OPAMP_GetValue() (VPORTD.IN & (0x1 << 2))
#define Output_OPAMP_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define Output_OPAMP_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define Output_OPAMP_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Output_OPAMP_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Output_OPAMP_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define Output_OPAMP_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Output_OPAMP_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Output_OPAMP_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Output_OPAMP_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Output_OPAMP_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Output_OPAMP_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Output_OPAMP_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LED0 aliases
#define LED0_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define LED0_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define LED0_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define LED0_GetValue() (VPORTB.IN & (0x1 << 3))
#define LED0_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define LED0_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define LED0_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED0_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED0_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LED0_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED0_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED0_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED0_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED0_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED0_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED0_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB0 pin. 
 *        This is a predefined interrupt handler to be used together with the PB0_SetInterruptHandler() method.
 *        This handler is called every time the PB0 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB0_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB0 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB0 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB0_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB2 pin. 
 *        This is a predefined interrupt handler to be used together with the PB2_SetInterruptHandler() method.
 *        This handler is called every time the PB2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PD1 pin. 
 *        This is a predefined interrupt handler to be used together with the PD1_SetInterruptHandler() method.
 *        This handler is called every time the PD1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PD1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PD1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PD1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PD1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PD2 pin. 
 *        This is a predefined interrupt handler to be used together with the PD2_SetInterruptHandler() method.
 *        This handler is called every time the PD2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PD2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PD2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PD2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PD2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB3 pin. 
 *        This is a predefined interrupt handler to be used together with the PB3_SetInterruptHandler() method.
 *        This handler is called every time the PB3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB3_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
