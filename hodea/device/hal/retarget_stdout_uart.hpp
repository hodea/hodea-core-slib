// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * Retarget printf() and other functions writing to stdout to an UART.
 *
 * \author f.hollerer@gmx.net
 */
#if !defined _HODEA_HAL_RETARGET_STDOUT_UART_HPP_
#define _HODEA_HAL_RETARGET_STDOUT_UART_HPP_

#include <hodea/device/hal/device_properties.hpp>

#if defined HODEA_DERIVED_CONFIG_BRAND_STM32
#include <hodea/device/stm32/retarget_stdout_uart.hpp>
#elif defined HODEA_DERIVED_CONFIG_BRAND_IMX_M4
#error "imx_m4 not yet supported"
#else
#error "Unsupported device."
#endif

#endif /*!_HODEA_HAL_RETARGET_STDOUT_UART_HPP_ */
