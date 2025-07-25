[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver PCF8575
[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/pcf8575/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Dieser 16-Bit-E/A-Expander für den bidirektionalen Zweileitungsbus (I²C) ist für den VCC-Betrieb von 2,5 V bis 5,5 V ausgelegt. Der PCF8575 bietet eine universelle Remote-E/A-Erweiterung für die meisten Mikrocontrollerfamilien über die I²C-Schnittstelle (Serieller Takt (SCL), Serielle Daten (SDA)). Der Baustein verfügt über einen 16-Bit-quasi-bidirektionalen Ein-/Ausgang (I/O)-Port (P07–P00, P17–P10) mit gelatchten Ausgängen und Hochstrom-Ansteuerung zur direkten Ansteuerung von LEDs. Jeder quasi-bidirektionale I/O kann ohne Datenrichtungs-Steuersignal als Ein- oder Ausgang verwendet werden. Beim Einschalten sind die I/Os hochpegelig. In diesem Modus ist nur eine Stromquelle für VCC aktiv.

LibDriver PCF8575 ist ein Treiber mit vollem Funktionsumfang von PCF8575, der von LibDriver gestartet wurde. Er bietet E/A-Schreiben, E/A-Lesen und andere Funktionen. LibDriver ist MISRA-konform.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver PCF8575-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver PCF8575 IIC.

/test enthält den Testcode des LibDriver PCF8575-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver PCF8575-Beispielcode.

/doc enthält das LibDriver PCF8575-Offlinedokument.

/Datenblatt enthält PCF8575-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

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

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/pcf8575/index.html](https://www.libdriver.com/docs/pcf8575/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.