/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_pcf8575_basic.h
 * @brief     driver pcf8575 basic header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2025-07-29
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2025/07/29  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_PCF8575_BASIC_H
#define DRIVER_PCF8575_BASIC_H

#include "driver_pcf8575_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup pcf8575_example_driver pcf8575 example driver function
 * @brief    pcf8575 example driver modules
 * @ingroup  pcf8575_driver
 * @{
 */

/**
 * @brief     basic example init
 * @param[in] addr iic device address
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t pcf8575_basic_init(pcf8575_address_t addr);

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t pcf8575_basic_deinit(void);

/**
 * @brief      basic example read
 * @param[in]  pin read pin
 * @param[out] *level pointer to a pin level buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t pcf8575_basic_read(pcf8575_pin_t pin, pcf8575_pin_level_t *level);

/**
 * @brief     basic example write
 * @param[in] pin written pin
 * @param[in] level pin level
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t pcf8575_basic_write(pcf8575_pin_t pin, pcf8575_pin_level_t level);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
