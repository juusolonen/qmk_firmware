// Copyright 2024 Juuso Solonen (@Juuso Solonen)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 10000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_TX_PIN      GP2
#define SERIAL_USART_RX_PIN      GP3

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS { GP9 }
// For split keyboards, you can separately define the right side pins
#define DIP_SWITCH_PINS_RIGHT { GP27 }

#define PERMISSIVE_HOLD

