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
 * @file      driver_pcf8575_basic.c
 * @brief     driver pcf8575 basic source file
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

#include "driver_pcf8575_basic.h"

static pcf8575_handle_t gs_handle;        /**< pcf8575 handle */

/**
 * @brief     basic example init
 * @param[in] addr iic device address
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t pcf8575_basic_init(pcf8575_address_t addr)
{
    uint8_t res;
    
    /* link functions */
    DRIVER_PCF8575_LINK_INIT(&gs_handle, pcf8575_handle_t);
    DRIVER_PCF8575_LINK_IIC_INIT(&gs_handle, pcf8575_interface_iic_init);
    DRIVER_PCF8575_LINK_IIC_DEINIT(&gs_handle, pcf8575_interface_iic_deinit);
    DRIVER_PCF8575_LINK_IIC_READ_COMMAND(&gs_handle, pcf8575_interface_iic_read_cmd);
    DRIVER_PCF8575_LINK_IIC_WRITE_COMMAND(&gs_handle, pcf8575_interface_iic_write_cmd);
    DRIVER_PCF8575_LINK_DELAY_MS(&gs_handle, pcf8575_interface_delay_ms);
    DRIVER_PCF8575_LINK_DEBUG_PRINT(&gs_handle, pcf8575_interface_debug_print);
    
    /* set addr pin */
    res = pcf8575_set_addr_pin(&gs_handle, addr);
    if (res != 0)
    {
        pcf8575_interface_debug_print("pcf8575: set addr pin failed.\n");
       
        return 1;
    }
    
    /* pcf8575 init */
    res = pcf8575_init(&gs_handle);
    if (res != 0)
    {
        pcf8575_interface_debug_print("pcf8575: init failed.\n");
       
        return 1;
    }
    
    return 0;
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t pcf8575_basic_deinit(void)
{
    if (pcf8575_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief      basic example read
 * @param[in]  pin read pin
 * @param[out] *level pointer to a pin level buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t pcf8575_basic_read(pcf8575_pin_t pin, pcf8575_pin_level_t *level)
{
    if (pcf8575_read(&gs_handle, pin, level) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief     basic example write
 * @param[in] pin written pin
 * @param[in] level pin level
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t pcf8575_basic_write(pcf8575_pin_t pin, pcf8575_pin_level_t level)
{
    if (pcf8575_write(&gs_handle, pin, level) != 0)
    {
        return 1;
    }
    
    return 0;
}
