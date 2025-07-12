[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver PCF8575

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/pcf8575/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

この16ビットI/Oエクスパンダは、2線式双方向バス（I2C）用で、2.5V～5.5VのVCC動作向けに設計されています。PCF8575デバイスは、I2Cインターフェース（シリアルクロック（SCL）、シリアルデータ（SDA））を介して、ほとんどのマイクロコントローラファミリに汎用リモートI/O拡張を提供します。このデバイスは、LEDを直接駆動するための高電流駆動能力を備えたラッチ出力を含む、16ビットの準双方向入出力（I/O）ポート（P07～P00、P17～P10）を備えています。各準双方向I/Oは、データ方向制御信号を使用せずに入力または出力として使用できます。電源投入時、I/Oはハイレベルです。このモードでは、VCCへの電流源のみがアクティブになります。

LibDriver PCF8575は、LibDriverによって起動されたPCF8575の全機能ドライバーであり、I / O書き込み、I/O読み取りおよびその他の機能を提供します。 LibDriverはMISRAに準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver PCF8575のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver PCF8575用のプラットフォームに依存しないIICバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver PCF8575ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver PCF8575プログラミング例が含まれています。

/ docディレクトリには、LibDriver PCF8575オフラインドキュメントが含まれています。

/ datasheetディレクトリには、PCF8575データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIICバステンプレートを参照して、指定したプラットフォームのIICバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

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

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/pcf8575/index.html](https://www.libdriver.com/docs/pcf8575/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。