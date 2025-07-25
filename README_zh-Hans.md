[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver PCF8575

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/pcf8575/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

这款面向两线制双向总线 (I2C) 的 16 位 I/O 扩展器设计为在 2.5V 至 5.5V VCC 下运行。PCF8575 器件通过 I2C 接口 [串行时钟 (SCL)、串行数据 (SDA)] 为大多数微控制器系列提供通用远程 I/O 扩展。该器件具有一个 16 位准双向输入/输出 (I/O) 端口（P07–P00、P17–P10），其中包括具有高电流驱动能力的锁存输出，用于直接驱动 LED。每个准双向 I/O 都可以用作输入或输出（无需使用数据方向控制信号）。在上电时，这些 I/O 处于高电平。在该模式下，仅有一个连接到 VCC 的电流源处于活动状态。

LibDriver PCF8575是LibDriver推出的PCF8575的全功能驱动，该驱动提供I/O写入，I/O读取等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver PCF8575的源文件。

/interface目录包含了LibDriver PCF8575与平台无关的IIC总线模板。

/test目录包含了LibDriver PCF8575驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver PCF8575编程范例。

/doc目录包含了LibDriver PCF8575离线文档。

/datasheet目录包含了PCF8575数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC总线模板，完成指定平台的IIC总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_pcf8575_basic.h"

uint8_t res;
pcf8575_pin_level_t level;

/* basic init */
res = pcf8575_basic_init(PCF8575_ADDRESS_A000);
if (res != 0)
{
    return 1;
}

...

/* read pin */
res = pcf8575_basic_read(PCF8575_PIN_00, (pcf8575_pin_level_t *)&level);
if (res != 0)
{
    (void)pcf8575_basic_deinit();

    return 1;
}

/* write pin */
res = pcf8575_basic_write(PCF8575_PIN_00, PCF8575_PIN_LEVEL_HIGH);
if (res != 0)
{
    (void)pcf8575_basic_deinit();

    return 1;
}

...

(void)pcf8575_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/pcf8575/index.html](https://www.libdriver.com/docs/pcf8575/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。