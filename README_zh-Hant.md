[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver PCF8575

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/pcf8575/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

這款面向兩線制雙向匯流排（I2C）的16比特I/O擴展器設計為在2.5V至5.5V VCC下運行。 PCF8575器件通過I2C介面[串列時鐘（SCL）、串列數據（SDA）]為大多數微控制器系列提供通用遠程I/O擴展。 該器件具有一個16比特准雙向輸入/輸出（I/O）埠（P07–P00、P17–P10），其中包括具有高電流驅動能力的鎖存輸出，用於直接驅動LED。 每個准雙向I/O都可以用作輸入或輸出（無需使用數據方向控制訊號）。 在上電時，這些I/O處於高電平。 在該模式下，僅有一個連接到VCC的電流源處於活動狀態。

LibDriver PCF8575是LibDriver推出的PCF8575的全功能驅動，該驅動提供I/O寫入，I/O讀取等功能並且它符合MISRA標準。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver PCF8575的源文件。

/interface目錄包含了LibDriver PCF8575與平台無關的IIC總線模板。

/test目錄包含了LibDriver PCF8575驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver PCF8575編程範例。

/doc目錄包含了LibDriver PCF8575離線文檔。

/datasheet目錄包含了PCF8575數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的IIC總線模板，完成指定平台的IIC總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

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

### 文檔

在線文檔: [https://www.libdriver.com/docs/pcf8575/index.html](https://www.libdriver.com/docs/pcf8575/index.html)。

離線文檔: /doc/html/index.html。

### 貢獻

請參攷CONTRIBUTING.md。

### 版權

版權 (c) 2015 - 現在 LibDriver 版權所有

MIT 許可證（MIT）

特此免費授予任何獲得本軟件副本和相關文檔文件（下稱“軟件”）的人不受限制地處置該軟件的權利，包括不受限制地使用、複製、修改、合併、發布、分發、轉授許可和/或出售該軟件副本，以及再授權被配發了本軟件的人如上的權利，須在下列條件下：

上述版權聲明和本許可聲明應包含在該軟件的所有副本或實質成分中。

本軟件是“如此”提供的，沒有任何形式的明示或暗示的保證，包括但不限於對適銷性、特定用途的適用性和不侵權的保證。在任何情況下，作者或版權持有人都不對任何索賠、損害或其他責任負責，無論這些追責來自合同、侵權或其它行為中，還是產生於、源於或有關於本軟件以及本軟件的使用或其它處置。

### 聯繫我們

請聯繫lishifenging@outlook.com。