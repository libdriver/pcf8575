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
 * @file      driver_pcf8575.c
 * @brief     driver pcf8575 source file
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

#include "driver_pcf8575.h"

/**
 * @brief chip information definition
 */
#define CHIP_NAME                 "Texas Instruments PCF8575"        /**< chip name */
#define MANUFACTURER_NAME         "Texas Instruments"                /**< manufacturer name */
#define SUPPLY_VOLTAGE_MIN        2.5f                               /**< chip min supply voltage */
#define SUPPLY_VOLTAGE_MAX        5.5f                               /**< chip max supply voltage */
#define MAX_CURRENT               100.0f                             /**< chip max current */
#define TEMPERATURE_MIN           -40.0f                             /**< chip min operating temperature */
#define TEMPERATURE_MAX           85.0f                              /**< chip max operating temperature */
#define DRIVER_VERSION            1000                               /**< driver version */

/**
 * @brief     set the address pin
 * @param[in] *handle pointer to a pcf8575 handle structure
 * @param[in] addr_pin chip address pins
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t pcf8575_set_addr_pin(pcf8575_handle_t *handle, pcf8575_address_t addr_pin)
{
    if (handle == NULL)                                  /* check handle */
    {
        return 2;                                        /* return error */
    }

    handle->iic_addr = 0x40;                             /* set iic addr */
    handle->iic_addr |= (uint8_t)(addr_pin << 1);        /* set iic address */
    
    return 0;                                            /* success return 0 */
}

/**
 * @brief      get the address pin
 * @param[in]  *handle pointer to a pcf8575 handle structure
 * @param[out] *addr_pin pointer to a chip address pins buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t pcf8575_get_addr_pin(pcf8575_handle_t *handle, pcf8575_address_t *addr_pin)
{
    if (handle == NULL)                                                        /* check handle */
    {
        return 2;                                                              /* return error */
    }

    *addr_pin = (pcf8575_address_t)((handle->iic_addr & (~0x40)) >> 1);        /*get iic address */
    
    return 0;                                                                  /* success return 0 */
}

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
uint8_t pcf8575_init(pcf8575_handle_t *handle)
{
    uint8_t buf[2];
    
    if (handle == NULL)                                                  /* check handle */
    {
        return 2;                                                        /* return error */
    }
    if (handle->debug_print == NULL)                                     /* check debug_print */
    {
        return 3;                                                        /* return error */
    }
    if (handle->iic_init == NULL)                                        /* check iic_init */
    {
        handle->debug_print("pcf8575: iic_init is null.\n");             /* iic_init is null */
       
        return 3;                                                        /* return error */
    }
    if (handle->iic_deinit == NULL)                                      /* check iic_deinit */
    {
        handle->debug_print("pcf8575: iic_deinit is null.\n");           /* iic_deinit is null */
       
        return 3;                                                        /* return error */
    }
    if (handle->iic_read_cmd == NULL)                                    /* check iic_read_cmd */
    {
        handle->debug_print("pcf8575: iic_read_cmd is null.\n");         /* iic_read_cmd is null */
       
        return 3;                                                        /* return error */
    }
    if (handle->iic_write_cmd == NULL)                                   /* check iic_write_cmd */
    {
        handle->debug_print("pcf8575: iic_write_cmd is null.\n");        /* iic_write_cmd is null */
       
        return 3;                                                        /* return error */
    }
    if (handle->delay_ms == NULL)                                        /* check delay_ms */
    {
        handle->debug_print("pcf8575: delay_ms is null.\n");             /* delay_ms is null */
       
        return 3;                                                        /* return error */
    }
    
    if (handle->iic_init() != 0)                                         /* iic init */
    {
        handle->debug_print("pcf8575: iic init failed.\n");              /* iic init failed */
       
        return 1;                                                        /* return error */
    }
    buf[0] = 0xFF;                                                       /* set 0xFF */
    buf[1] = 0xFF;                                                       /* set 0xFF */
    if (handle->iic_write_cmd(handle->iic_addr, 
                             (uint8_t *)buf, 2) != 0)                    /* write all pin high level */
    {
        handle->debug_print("pcf8575: iic write failed.\n");             /* iic write failed */
        (void)handle->iic_deinit();                                      /* iic deinit */
        
        return 4;                                                        /* return error */
    }
    handle->inited = 1;                                                  /* flag finish initialization */
    
    return 0;                                                            /* success return 0 */
}

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
uint8_t pcf8575_deinit(pcf8575_handle_t *handle)
{
    uint8_t res;
    
    if (handle == NULL)                                              /* check handle */
    {
        return 2;                                                    /* return error */
    }
    if (handle->inited != 1)                                         /* check handle initialization */
    {
        return 3;                                                    /* return error */
    }
    
    res = handle->iic_deinit();                                      /* iic deinit */
    if (res != 0)                                                    /* check error */
    {
        handle->debug_print("pcf8575: iic deinit failed.\n");        /* iic deinit failed */
       
        return 1;                                                    /* return error */
    }
    handle->inited = 0;                                              /* flag closed */
    
    return 0;                                                        /* success return 0 */
}

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
uint8_t pcf8575_read(pcf8575_handle_t *handle, pcf8575_pin_t pin, pcf8575_pin_level_t *level)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    
    if (handle == NULL)                                                     /* check handle */
    {
        return 2;                                                           /* return error */
    }
    if (handle->inited != 1)                                                /* check handle initialization */
    {
        return 3;                                                           /* return error */
    }
    
    res = handle->iic_read_cmd(handle->iic_addr, (uint8_t *)buf, 2);        /* read data */
    if (res != 0)                                                           /* check error */
    {
        handle->debug_print("pcf8575: iic read failed.\n");                 /* iic read failed */
       
        return 1;                                                           /* return error */
    }
    prev = (((uint16_t)buf[0]) << 8) | buf[1];                              /* set buffer */
    *level = (pcf8575_pin_level_t)((prev >> pin) & 0x01);                   /* get level */
    
    return 0;                                                               /* success return 0 */
}

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
uint8_t pcf8575_write(pcf8575_handle_t *handle, pcf8575_pin_t pin, pcf8575_pin_level_t level)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    
    if (handle == NULL)                                                       /* check handle */
    {
        return 2;                                                             /* return error */
    }
    if (handle->inited != 1)                                                  /* check handle initialization */
    {
        return 3;                                                             /* return error */
    }
    
    res = handle->iic_read_cmd(handle->iic_addr, (uint8_t *)buf, 2);          /* read data */
    if (res != 0)                                                             /* check error */
    {
        handle->debug_print("pcf8575: iic read failed.\n");                   /* iic read failed */
       
        return 1;                                                             /* return error */
    }
    prev = (((uint16_t)buf[0]) << 8) | buf[1];                                /* set buffer */
    prev &= ~(1 << pin);                                                      /* clear 0 */
    prev |= level << pin;                                                     /* set data */
    buf[0] = (prev >> 8) & 0xFF;                                              /* set buffer 0 */
    buf[1] = (prev >> 0) & 0xFF;                                              /* set buffer 1 */
    res = handle->iic_write_cmd(handle->iic_addr, (uint8_t *)buf, 2);         /* write data */
    if (res != 0)                                                             /* check error */
    {
        handle->debug_print("pcf8575: iic write failed.\n");                  /* iic write failed */
       
        return 1;                                                             /* return error */
    }
    
    return 0;                                                                 /* success return 0 */
}

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
uint8_t pcf8575_set_reg(pcf8575_handle_t *handle, uint8_t *buf, uint16_t len)
{
    if (handle == NULL)                                                /* check handle */
    {
        return 2;                                                      /* return error */
    }
    if (handle->inited != 1)                                           /* check handle initialization */
    {
        return 3;                                                      /* return error */
    }
    
    if (handle->iic_write_cmd(handle->iic_addr, buf, len) != 0)        /* write command */
    {
        return 1;                                                      /* return error */
    }
    else
    {
        return 0;                                                      /* success return 0 */
    }
}

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
uint8_t pcf8575_get_reg(pcf8575_handle_t *handle, uint8_t *buf, uint16_t len)
{
    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    
    if (handle->iic_read_cmd(handle->iic_addr, buf, len) != 0)        /* read command */
    {
        return 1;                                                     /* return error */
    }
    else
    {
        return 0;                                                     /* success return 0 */
    }
}

/**
 * @brief      get chip's information
 * @param[out] *info pointer to a pcf8575 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t pcf8575_info(pcf8575_info_t *info)
{
    if (info == NULL)                                               /* check handle */
    {
        return 2;                                                   /* return error */
    }
    
    memset(info, 0, sizeof(pcf8575_info_t));                        /* initialize pcf8575 info structure */
    strncpy(info->chip_name, CHIP_NAME, 32);                        /* copy chip name */
    strncpy(info->manufacturer_name, MANUFACTURER_NAME, 32);        /* copy manufacturer name */
    strncpy(info->interface, "IIC", 8);                             /* copy interface name */
    info->supply_voltage_min_v = SUPPLY_VOLTAGE_MIN;                /* set minimal supply voltage */
    info->supply_voltage_max_v = SUPPLY_VOLTAGE_MAX;                /* set maximum supply voltage */
    info->max_current_ma = MAX_CURRENT;                             /* set maximum current */
    info->temperature_max = TEMPERATURE_MAX;                        /* set minimal temperature */
    info->temperature_min = TEMPERATURE_MIN;                        /* set maximum temperature */
    info->driver_version = DRIVER_VERSION;                          /* set driver version */
    
    return 0;                                                       /* success return 0 */
}
