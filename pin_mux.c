/*
 * Copyright 2019 ,2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 9.0.0
board: LPCXpresso55S69
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: GPIO, signal: 'PIO1, 4', pin_signal: PIO1_4/FC0_SCK/SD0_D0/CTIMER2_MAT1/SCT0_OUT0/FREQME_GPIO_CLK_A, direction: OUTPUT, mode: pullUp,
    slew_rate: standard, invert: disabled, open_drain: disabled}
  - {pin_num: '21', peripheral: SWD, signal: SWO, pin_signal: PIO0_10/FC6_SCK/CT_INP10/CTIMER2_MAT0/FC1_TXD_SCL_MISO_WS/SCT0_OUT2/SWO/SECURE_GPIO0_10/ADC0_1, mode: inactive,
    slew_rate: standard, invert: disabled, open_drain: disabled, asw: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M33 (Core #0) */
void BOARD_InitPins(void)
{
    /* Enables the clock for the I/O controller.: Enable Clock. */
    CLOCK_EnableClock(kCLOCK_Iocon);

    /* Enables the clock for the GPIO1 module */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    gpio_pin_config_t LED_BULE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_4 (pin 1)  */
    GPIO_PinInit(BOARD_LED_BULE_GPIO, BOARD_LED_BULE_PORT, BOARD_LED_BULE_PIN, &LED_BULE_config);

    const uint32_t port0_pin10_config = (/* Pin is configured as SWO */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI |
                                         /* Analog switch is open (disabled) */
                                         IOCON_PIO_ASW_DI);
    /* PORT0 PIN10 (coords: 21) is configured as SWO */
    IOCON_PinMuxSet(IOCON, 0U, 10U, port0_pin10_config);

    const uint32_t LED_BULE = (/* Pin is configured as PIO1_4 */
                               IOCON_PIO_FUNC0 |
                               /* Selects pull-up function */
                               IOCON_PIO_MODE_PULLUP |
                               /* Standard mode, output slew rate control is enabled */
                               IOCON_PIO_SLEW_STANDARD |
                               /* Input function is not inverted */
                               IOCON_PIO_INV_DI |
                               /* Enables digital function */
                               IOCON_PIO_DIGITAL_EN |
                               /* Open drain is disabled */
                               IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN4 (coords: 1) is configured as PIO1_4 */
    IOCON_PinMuxSet(IOCON, BOARD_LED_BULE_PORT, BOARD_LED_BULE_PIN, LED_BULE);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
