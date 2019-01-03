/*

    __tamper2_driver.h

----------------------------------------------------------------------------- */

/**
@file   __tamper2_driver.h
@brief    Tamper2 Driver
@mainpage Tamper2 Click
@{

Tamper 2 click holds switch detector SNAP ACT SPDT 100MA 125V D2HW-A221D and library can detect
whether the state of switch is ON or OFF.

@}

@defgroup   TAMPER2
@brief      Tamper2 Click Driver
@{

| Global Library Prefix | **TAMPER2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _TAMPER2_H_
#define _TAMPER2_H_

/** 
 * @macro T_TAMPER2_P
 * @brief Driver Abstract type 
 */
#define T_TAMPER2_P    const uint8_t*

/** @defgroup TAMPER2_COMPILE Compilation Config */              /** @{ */

//  #define   __TAMPER2_DRV_SPI__                            /**<     @macro __TAMPER2_DRV_SPI__  @brief SPI driver selector */
//  #define   __TAMPER2_DRV_I2C__                            /**<     @macro __TAMPER2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __TAMPER2_DRV_UART__                           /**<     @macro __TAMPER2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup TAMPER2_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup TAMPER2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup TAMPER2_INIT Driver Initialization */              /** @{ */

#ifdef   __TAMPER2_DRV_SPI__
void tamper2_spiDriverInit(T_TAMPER2_P gpioObj, T_TAMPER2_P spiObj);
#endif
#ifdef   __TAMPER2_DRV_I2C__
void tamper2_i2cDriverInit(T_TAMPER2_P gpioObj, T_TAMPER2_P i2cObj, uint8_t slave);
#endif
#ifdef   __TAMPER2_DRV_UART__
void tamper2_uartDriverInit(T_TAMPER2_P gpioObj, T_TAMPER2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void tamper2_gpioDriverInit(T_TAMPER2_P gpioObj);
                                                                       /** @} */
/** @defgroup TAMPER2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Switch OFF detect
 *
 *  This function detects if the switch is in OFF state.
 *  Returns 1 the switch is in OFF state.
 */
uint8_t tamper2_getOffState();

/**
 * @brief Switch ON detect
 *
 *  This function detects if the switch is in ON state.
 *  Returns 1 the switch is in ON state.
 */
uint8_t tamper2_getOnState();







                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Tamper2_STM.c
    @example Click_Tamper2_TIVA.c
    @example Click_Tamper2_CEC.c
    @example Click_Tamper2_KINETIS.c
    @example Click_Tamper2_MSP.c
    @example Click_Tamper2_PIC.c
    @example Click_Tamper2_PIC32.c
    @example Click_Tamper2_DSPIC.c
    @example Click_Tamper2_AVR.c
    @example Click_Tamper2_FT90x.c
    @example Click_Tamper2_STM.mbas
    @example Click_Tamper2_TIVA.mbas
    @example Click_Tamper2_CEC.mbas
    @example Click_Tamper2_KINETIS.mbas
    @example Click_Tamper2_MSP.mbas
    @example Click_Tamper2_PIC.mbas
    @example Click_Tamper2_PIC32.mbas
    @example Click_Tamper2_DSPIC.mbas
    @example Click_Tamper2_AVR.mbas
    @example Click_Tamper2_FT90x.mbas
    @example Click_Tamper2_STM.mpas
    @example Click_Tamper2_TIVA.mpas
    @example Click_Tamper2_CEC.mpas
    @example Click_Tamper2_KINETIS.mpas
    @example Click_Tamper2_MSP.mpas
    @example Click_Tamper2_PIC.mpas
    @example Click_Tamper2_PIC32.mpas
    @example Click_Tamper2_DSPIC.mpas
    @example Click_Tamper2_AVR.mpas
    @example Click_Tamper2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __tamper2_driver.h

    This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.

----------------------------------------------------------------------------- */

