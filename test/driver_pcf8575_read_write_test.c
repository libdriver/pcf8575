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
 * @file      driver_pcf8575_read_write_test.c
 * @brief     driver pcf8575 read write test source file
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

#include "driver_pcf8575_read_write_test.h"

static pcf8575_handle_t gs_handle;        /**< pcf8575 handle */

/**
 * @brief     read write test
 * @param[in] addr iic device address
 * @param[in] times test times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t pcf8575_read_write_test(pcf8575_address_t addr, uint32_t times)
{
    uint8_t res;
    uint32_t i;
    pcf8575_info_t info;
    pcf8575_pin_level_t level;
    
    /* link functions */
    DRIVER_PCF8575_LINK_INIT(&gs_handle, pcf8575_handle_t);
    DRIVER_PCF8575_LINK_IIC_INIT(&gs_handle, pcf8575_interface_iic_init);
    DRIVER_PCF8575_LINK_IIC_DEINIT(&gs_handle, pcf8575_interface_iic_deinit);
    DRIVER_PCF8575_LINK_IIC_READ_COMMAND(&gs_handle, pcf8575_interface_iic_read_cmd);
    DRIVER_PCF8575_LINK_IIC_WRITE_COMMAND(&gs_handle, pcf8575_interface_iic_write_cmd);
    DRIVER_PCF8575_LINK_DELAY_MS(&gs_handle, pcf8575_interface_delay_ms);
    DRIVER_PCF8575_LINK_DEBUG_PRINT(&gs_handle, pcf8575_interface_debug_print);
    
    /* pcf8575 info */
    res = pcf8575_info(&info);
    if (res != 0)
    {
        pcf8575_interface_debug_print("pcf8575: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        pcf8575_interface_debug_print("pcf8575: chip is %s.\n", info.chip_name);
        pcf8575_interface_debug_print("pcf8575: manufacturer is %s.\n", info.manufacturer_name);
        pcf8575_interface_debug_print("pcf8575: interface is %s.\n", info.interface);
        pcf8575_interface_debug_print("pcf8575: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        pcf8575_interface_debug_print("pcf8575: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        pcf8575_interface_debug_print("pcf8575: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        pcf8575_interface_debug_print("pcf8575: max current is %0.2fmA.\n", info.max_current_ma);
        pcf8575_interface_debug_print("pcf8575: max temperature is %0.1fC.\n", info.temperature_max);
        pcf8575_interface_debug_print("pcf8575: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
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
    
    /* start read test */
    pcf8575_interface_debug_print("pcf8575: start read write test.\n");
    
    for (i = 0; i < times; i++)
    {
        /* read pin 00 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_00, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 00 is %d.\n", level);
        
        /* read pin 01 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_01, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 01 is %d.\n", level);
        
        /* read pin 02 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_02, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 02 is %d.\n", level);
        
        /* read pin 03 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_03, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 03 is %d.\n", level);
        
        /* write pin 04 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_04, PCF8575_PIN_LEVEL_LOW);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 04 low.\n");
        
        /* write pin 05 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_05, PCF8575_PIN_LEVEL_HIGH);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 05 high.\n");
        
        /* write pin 06 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_06, PCF8575_PIN_LEVEL_LOW);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 06 low.\n");
        
        /* write pin 07 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_07, PCF8575_PIN_LEVEL_HIGH);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 07 high.\n");
        
        /* read pin 10 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_10, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 10 is %d.\n", level);
        
        /* read pin 11 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_11, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 11 is %d.\n", level);
        
        /* read pin 12 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_12, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 12 is %d.\n", level);
        
        /* read pin 13 */
        res = pcf8575_read(&gs_handle, PCF8575_PIN_13, &level);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: read failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: read PIN 13 is %d.\n", level);
        
        /* write pin 14 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_14, PCF8575_PIN_LEVEL_LOW);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 14 low.\n");
        
        /* write pin 15 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_15, PCF8575_PIN_LEVEL_HIGH);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 15 high.\n");
        
        /* write pin 16 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_16, PCF8575_PIN_LEVEL_LOW);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 16 low.\n");
        
        /* write pin 17 */
        res = pcf8575_write(&gs_handle, PCF8575_PIN_17, PCF8575_PIN_LEVEL_HIGH);
        if (res != 0)
        {
            pcf8575_interface_debug_print("pcf8575: write failed.\n");
            (void)pcf8575_deinit(&gs_handle);
           
            return 1;
        }
        pcf8575_interface_debug_print("pcf8575: write PIN 17 high.\n");
        
        /* delay 1000 ms */
        pcf8575_interface_delay_ms(1000);
    }
    
    /* finish read test */
    pcf8575_interface_debug_print("pcf8575: finish read write test.\n");  
    (void)pcf8575_deinit(&gs_handle);
    
    return 0;
}
