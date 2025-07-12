### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(pcf8575 REQUIRED)
```

### 3. PCF8575

#### 3.1 Command Instruction

1. Show pcf8575 chip and driver information.

   ```shell
   pcf8575 (-i | --information)
   ```

2. Show pcf8575 help.

   ```shell
   pcf8575 (-h | --help)
   ```

3. Show pcf8575 pin connections of the current board.

   ```shell
   pcf8575 (-p | --port)
   ```

4. Run pcf8575 read write test, num means test times.

   ```shell
   pcf8575 (-t readwrite | --test=readwrite) [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--times=<num>]
   ```

5. Run pcf8575 read function.

   ```shell
   pcf8575 (-e input | --example=input) [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--pin=<00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17>]
   ```

6. Run pcf8575 write function.

   ```shell
   pcf8575 (-e output | --example=output) [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--pin=<00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17>] [--level=<low | high>]
   ```

#### 3.2 Command Example

```shell
./pcf8575 -i

pcf8575: chip is Texas Instruments PCF8575.
pcf8575: manufacturer is Texas Instruments.
pcf8575: interface is IIC.
pcf8575: driver version is 1.0.
pcf8575: min supply voltage is 2.5V.
pcf8575: max supply voltage is 5.5V.
pcf8575: max current is 100.00mA.
pcf8575: max temperature is 85.0C.
pcf8575: min temperature is -40.0C.
```

```shell
./pcf8575 -p

pcf8575: SCL connected to GPIO3(BCM).
pcf8575: SDA connected to GPIO2(BCM).
```

```shell
./pcf8575 -t readwrite --addr=0 --times=3

pcf8575: chip is Texas Instruments PCF8575.
pcf8575: manufacturer is Texas Instruments.
pcf8575: interface is IIC.
pcf8575: driver version is 1.0.
pcf8575: min supply voltage is 2.5V.
pcf8575: max supply voltage is 5.5V.
pcf8575: max current is 100.00mA.
pcf8575: max temperature is 85.0C.
pcf8575: min temperature is -40.0C.
pcf8575: start read write test.
pcf8575: read PIN 00 is 1.
pcf8575: read PIN 01 is 1.
pcf8575: read PIN 02 is 1.
pcf8575: read PIN 03 is 1.
pcf8575: write PIN 04 low.
pcf8575: write PIN 05 high.
pcf8575: write PIN 06 low.
pcf8575: write PIN 07 high.
pcf8575: read PIN 10 is 1.
pcf8575: read PIN 11 is 1.
pcf8575: read PIN 12 is 1.
pcf8575: read PIN 13 is 1.
pcf8575: write PIN 14 low.
pcf8575: write PIN 15 high.
pcf8575: write PIN 16 low.
pcf8575: write PIN 17 high.
pcf8575: read PIN 00 is 1.
pcf8575: read PIN 01 is 1.
pcf8575: read PIN 02 is 1.
pcf8575: read PIN 03 is 1.
pcf8575: write PIN 04 low.
pcf8575: write PIN 05 high.
pcf8575: write PIN 06 low.
pcf8575: write PIN 07 high.
pcf8575: read PIN 10 is 1.
pcf8575: read PIN 11 is 1.
pcf8575: read PIN 12 is 1.
pcf8575: read PIN 13 is 1.
pcf8575: write PIN 14 low.
pcf8575: write PIN 15 high.
pcf8575: write PIN 16 low.
pcf8575: write PIN 17 high.
pcf8575: read PIN 00 is 1.
pcf8575: read PIN 01 is 1.
pcf8575: read PIN 02 is 1.
pcf8575: read PIN 03 is 1.
pcf8575: write PIN 04 low.
pcf8575: write PIN 05 high.
pcf8575: write PIN 06 low.
pcf8575: write PIN 07 high.
pcf8575: read PIN 10 is 1.
pcf8575: read PIN 11 is 1.
pcf8575: read PIN 12 is 1.
pcf8575: read PIN 13 is 1.
pcf8575: write PIN 14 low.
pcf8575: write PIN 15 high.
pcf8575: write PIN 16 low.
pcf8575: write PIN 17 high.
pcf8575: finish read write test.
```

```shell
./pcf8575 -e input --addr=0 --pin=01

pcf8575: read pin is 1.
```

```shell
./pcf8575 -e output --addr=0 --pin=17 --level=LOW

pcf8575: write pin level 0.
```

```shell
./pcf8575 -h

Usage:
  pcf8575 (-i | --information)
  pcf8575 (-h | --help)
  pcf8575 (-p | --port)
  pcf8575 (-t readwrite | --test=readwrite) [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--times=<num>]
  pcf8575 (-e input | --example=input) [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>]
          [--pin=<00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17>]
  pcf8575 (-e output | --example=output) [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>]
          [--pin=<00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17>]
          [--level=<LOW | HIGH>]

Options:
      --addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>
                              Set the addr pin.([default: 0])
  -e <input | output>, --example=<input | output>
                              Run the driver example.
  -h, --help                  Show the help.
  -i, --information           Show the chip information.
  -p, --port                  Display the pin connections of the current board.
      --pin=<00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17>
                              Set the used pin.([default: 00])
      --level=<LOW | HIGH>    Set the output level.([default: LOW])
  -t <readwrite>, --test=<readwrite>
                              Run the driver test.
      --times=<num>           Set the running times.([default: 3])
```

