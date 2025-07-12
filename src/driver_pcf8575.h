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
 * @file      driver_pcf8575.h
 * @brief     driver pcf8575 header file
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

#ifndef DRIVER_PCF8575_H
#define DRIVER_PCF8575_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup pcf8575_driver pcf8575 driver function
 * @brief    pcf8575 driver modules
 * @{
 */

/**
 * @addtogroup pcf8575_base_driver
 * @{
 */

/**
 * @brief pcf8575 address enumeration definition
 */
typedef enum
{
    PCF8575_ADDRESS_A000 = 0,        /**< A2A1A0 000 */
    PCF8575_ADDRESS_A001 = 1,        /**< A2A1A0 001 */
    PCF8575_ADDRESS_A010 = 2,        /**< A2A1A0 010 */
    PCF8575_ADDRESS_A011 = 3,        /**< A2A1A0 011 */
    PCF8575_ADDRESS_A100 = 4,        /**< A2A1A0 100 */
    PCF8575_ADDRESS_A101 = 5,        /**< A2A1A0 101 */
    PCF8575_ADDRESS_A110 = 6,        /**< A2A1A0 110 */
    PCF8575_ADDRESS_A111 = 7,        /**< A2A1A0 111 */
} pcf8575_address_t;

/**
 * @brief pcf8575 pin enumeration definition
 */
typedef enum
{
    PCF8575_PIN_00 = 0x08,        /**< pin 00 */
    PCF8575_PIN_01 = 0x09,        /**< pin 01 */
    PCF8575_PIN_02 = 0x0A,        /**< pin 02 */
    PCF8575_PIN_03 = 0x0B,        /**< pin 03 */
    PCF8575_PIN_04 = 0x0C,        /**< pin 04 */
    PCF8575_PIN_05 = 0x0D,        /**< pin 05 */
    PCF8575_PIN_06 = 0x0E,        /**< pin 06 */
    PCF8575_PIN_07 = 0x0F,        /**< pin 07 */
    PCF8575_PIN_10 = 0x00,        /**< pin 10 */
    PCF8575_PIN_11 = 0x01,        /**< pin 11 */
    PCF8575_PIN_12 = 0x02,        /**< pin 12 */
    PCF8575_PIN_13 = 0x03,        /**< pin 13 */
    PCF8575_PIN_14 = 0x04,        /**< pin 14 */
    PCF8575_PIN_15 = 0x05,        /**< pin 15 */
    PCF8575_PIN_16 = 0x06,        /**< pin 16 */
    PCF8575_PIN_17 = 0x07,        /**< pin 17 */
} pcf8575_pin_t;

/**
 * @brief pcf8575 pin enumeration definition
 */
typedef enum
{
    PCF8575_PIN_LEVEL_LOW  = 0x00,        /**< low level */
    PCF8575_PIN_LEVEL_HIGH = 0x01,        /**< high level */
} pcf8575_pin_level_t;

/**
 * @brief pcf8575 handle structure definition
 */
typedef struct pcf8575_handle_s
{
    uint8_t iic_addr;                                                          /**< iic device address */
    uint8_t (*iic_init)(void);                                                 /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                               /**< point to an iic_deinit function address */
    uint8_t (*iic_read_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);         /**< point to an iic_read_cmd function address */
    uint8_t (*iic_write_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);        /**< point to an iic_write_cmd function address */
    void (*delay_ms)(uint32_t ms);                                             /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                           /**< point to a debug_print function address */
    uint8_t inited;                                                            /**< inited flag */
} pcf8575_handle_t;

/**
 * @brief pcf8575 information structure definition
 */
typedef struct pcf8575_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} pcf8575_info_t;

/**
 * @}
 */

/**
 * @defgroup pcf8575_link_driver pcf8575 link driver function
 * @brief    pcf8575 link driver modules
 * @ingroup  pcf8575_driver
 * @{
 */

/**
 * @brief     initialize pcf8575_handle_t structure
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] STRUCTURE pcf8575_handle_t
 * @note      none
 */
#define DRIVER_PCF8575_LINK_INIT(HANDLE, STRUCTURE)           memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_PCF8575_LINK_IIC_INIT(HANDLE, FUC)            (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_PCF8575_LINK_IIC_DEINIT(HANDLE, FUC)          (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read_cmd function
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] FUC pointer to an iic_read_cmd function address
 * @note      none
 */
#define DRIVER_PCF8575_LINK_IIC_READ_COMMAND(HANDLE, FUC)    (HANDLE)->iic_read_cmd = FUC

/**
 * @brief     link iic_write_cmd function
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] FUC pointer to an iic_write_cmd function address
 * @note      none
 */
#define DRIVER_PCF8575_LINK_IIC_WRITE_COMMAND(HANDLE, FUC)   (HANDLE)->iic_write_cmd = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_PCF8575_LINK_DELAY_MS(HANDLE, FUC)            (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to a pcf8575 handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_PCF8575_LINK_DEBUG_PRINT(HANDLE, FUC)         (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup pcf8575_base_driver pcf8575 base driver function
 * @brief    pcf8575 base driver modules
 * @ingroup  pcf8575_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to a pcf8575 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t pcf8575_info(pcf8575_info_t *info);

/**
 * @brief     set the address pin
 * @param[in] *handle pointer to a pcf8575 handle structure
 * @param[in] addr_pin chip address pins
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t pcf8575_set_addr_pin(pcf8575_handle_t *handle, pcf8575_address_t addr_pin);

/**
 * @brief      get the address pin
 * @param[in]  *handle pointer to a pcf8575 handle structure
 * @param[out] *addr_pin pointer to a chip address pins buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t pcf8575_get_addr_pin(pcf8575_handle_t *handle, pcf8575_address_t *addr_pin);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to a pcf8575 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 iic write failed
 * @note      none
 */
uint8_t pcf8575_init(pcf8575_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to a pcf8575 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t pcf8575_deinit(pcf8575_handle_t *handle);

/**
 * @brief      read the pin
 * @param[in]  *handle pointer to a pcf8575 handle structure
 * @param[in]  pin read pin
 * @param[out] *level pointer to a level buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t pcf8575_read(pcf8575_handle_t *handle, pcf8575_pin_t pin, pcf8575_pin_level_t *level);

/**
 * @brief     write the pin
 * @param[in] *handle pointer to a pcf8575 handle structure
 * @param[in] pin written pin
 * @param[in] level pin level
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t pcf8575_write(pcf8575_handle_t *handle, pcf8575_pin_t pin, pcf8575_pin_level_t level);

/**
 * @brief     set the chip register
 * @param[in] *handle pointer to a pcf8575 handle structure
 * @param[in] *buf pointer to a data buffer.
 * @param[in] len data buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t pcf8575_set_reg(pcf8575_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @brief      get the chip register
 * @param[in]  *handle pointer to a pcf8575 handle structure
 * @param[out] *buf pointer to a data buffer.
 * @param[in]  len data buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t pcf8575_get_reg(pcf8575_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
