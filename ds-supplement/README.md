# CH569 Hacking: Unofficial Supplementary Datasheet

As the datasheet by the manufacturer(WCH) is not so human-friendly, this
documentation has been made to provide some supplementary information
about the chip to help improve your development experience.

In addition, blatant errors found in the datasheet and other
manufacturer's materials such as example programs and schematics will be
documented here.

## Disclaimer

I do not work for WCH nor do I have any association with the company. To
avoid confusion in the event of WCH updating the materials after seeing
this document, version will be specified where appropriate.

Your contributions are welcome.

## Human-friendlier Pin Function Table

The pin definitions in the datasheet is not formatted in a way that's
not easy for devs to read when choosing the combination of the functions
to use. The following tables are created for convenience. The
spreadsheet([ch569-pins.fods](ch569-pins.fods)) was authored first by
copying-and-pasting text from the datasheet to generate the markdown
table using the handcrafted python
script([collapse-pinouts.py](collapse-pinouts.py)).

The table is only for navigating the combinations of functions the chip
has to offer. There might be some errors made during the transfer
process so please cross-check with the manufacturer's datasheet before
commencing actual work.

Based on datasheet version V1.2.

### Legend

| Function Group | Description |
|-|-|
| HSPI | High Speed Parallel Interface |
| BUS8 | Active Parallel Port |
| MMC | eMMC/SDIO |
| SPI | Serial Peripheral Interface |
| COM | UART ports and RS232 modem pins |
| MOD | timers and PWMs ("modulators") |
| ETH | Ethernet MII |
| ISP | In-system Programming |

### Table

|# | NAME   |HSPI |BUS8| MMC | SPI | COM | MOD     | ETH |ISP |
|--|--------|-----|----|-----|-----|-----|---------|-----|----|
| 0|GND     |     |    |     |     |     |         |     |    |
| 1|DP      |     |    |     |     |     |         |     |    |
| 2|DN      |     |    |     |     |     |         |     |    |
| 3|V3.3USB |     |    |     |     |     |         |     |    |
| 4|SSTXA   |     |    |     |     |     |         |     |    |
| 5|SSTXB   |     |    |     |     |     |         |     |    |
| 6|V1.2USB |     |    |     |     |     |         |     |    |
| 7|SSRXA   |     |    |     |     |     |         |     |    |
| 8|SSRXB   |     |    |     |     |     |         |     |    |
| 9|V1.2CORE|     |    |     |     |     |         |     |    |
|10|PA19    |HRCLK|    |     |     |     |         |     |    |
|11|PA18    |HRACT|    |     |     |     |         |     |    |
|12|PA8     |     |BRD#|     |     |TXD1 |         |     |    |
|13|PA7     |     |BD7 |     |     |RXD1 |         |     |    |
|14|PA6     |HRVLD|BD6 |     |     |TXD0_|         |     |    |
|15|PA5     |HD0  |BD5 |     |     |RXD0_|         |     |    |
|16|VDDIO   |     |    |     |     |     |         |     |    |
|17|PA4     |HD1  |BD4 |     |     |     |TMR2/PWM1|     |    |
|18|PA23    |HTRDY|    |     |     |     |         |     |    |
|19|PA3     |HD3  |BD3 |     |     |TXD2 |         |     |    |
|20|PA2     |HD4  |BD2 |MD7  |     |RXD2 |         |     |    |
|21|PA1     |HD5  |BD1 |MD6  |     |     |         |     |    |
|22|PA0     |HD6  |BD0 |MD5  |     |     |         |     |    |
|23|PB21    |HD7  |    |MD4  |     |     |         |     |    |
|24|PB20    |HD8  |    |MD3  |     |     |         |     |    |
|25|PB19    |HD9  |    |MD2  |     |     |         |     |    |
|26|PB18    |HD10 |    |MD1  |     |     |         |     |    |
|27|PB17    |HD11 |    |MD0  |     |     |         |     |    |
|28|PA17    |HD12 |    |     |     |     |         |     |    |
|29|PB16    |HD13 |    |MCMD |     |     |         |     |    |
|30|PB15    |HD14 |    |     |     |     |TMR1/PWM0|     |RST#|
|31|PB14    |HD15 |BA14|MSDCK|MISO1|     |         |     |    |
|32|PB0     |HD16 |BA0 |     |     |     |TMR1_    |EMDIO|    |
|33|PB1     |HD17 |BA1 |     |     |     |PWM2     |EMDCK|    |
|34|PB2     |HD18 |BA2 |     |     |     |PWM3     |ETXD3|    |
|35|PA20    |HD19 |    |     |     |     |         |EMCO |    |
|36|PB3     |HD20 |BA3 |     |     |RXD3 |TMR2_    |ETXD2|    |
|37|PB4     |HD21 |BA4 |     |     |TXD3 |         |ETXD1|    |
|38|PB5     |HD22 |BA5 |     |     |RXD0 |         |ETXD0|    |
|39|PB6     |HD23 |BA6 |     |     |TXD0 |         |ETXEN|    |
|40|PA16    |HD24 |    |     |     |     |         |ETCKI|    |
|41|PB7     |HD25 |BA7 |     |     |DSR  |         |ETXC |    |
|42|VDDIO   |     |    |     |     |     |         |     |    |
|43|PB8     |HD26 |BA8 |     |     |RI   |         |ERXC |    |
|44|PB9     |HD27 |BA9 |     |     |DCD  |         |ERXD3|    |
|45|PB22    |     |    |     |     |     |         |     |    |
|46|PB10    |HD28 |BA10|     |     |DTR  |         |ERXD2|    |
|47|PB23    |     |    |     |     |     |         |     |    |
|48|PB11    |HD29 |BA11|     |SCS1 |CTS  |         |ERXD1|    |
|49|PB24    |     |    |     |     |     |         |     |    |
|50|PB12    |HD30 |BA12|     |SCK1 |RTS  |         |ERXD0|    |
|51|PB13    |HD31 |BA13|     |MOSI1|     |         |ERXDV|    |
|52|PA21    |HTVLD|    |     |     |     |         |     |    |
|53|PA22    |HD2  |    |     |     |     |         |     |    |
|54|PA9     |HTREQ|BWR#|     |     |     |TMR0     |     |    |
|55|PA10    |HTACK|    |     |     |     |         |     |TCK |
|56|PA11    |HTCLK|    |     |     |     |         |     |TIO |
|57|PA12    |     |    |     |SCS  |     |         |     |    |
|58|PA13    |     |    |     |SCK  |     |         |     |    |
|59|PA14    |     |    |     |MOSI |     |         |     |    |
|60|PA15    |     |    |     |MISO |     |         |     |    |
|61|VDDIO   |     |    |     |     |     |         |     |    |
|62|V3.3LDO |     |    |     |     |     |         |     |    |
|63|V1.2CORE|     |    |     |     |     |         |     |    |
|64|V3.3GX  |     |    |     |     |     |         |     |    |
|65|GXM     |     |    |     |     |     |         |     |    |
|66|GXP     |     |    |     |     |     |         |     |    |
|67|XO      |     |    |     |     |     |         |     |    |
|68|XI      |     |    |     |     |     |         |     |    |

## Errors: datasheet
### EMMC peripheral data line 4

In page 4 of the datasheet version V1.2, it says:

> MD4: EMMC peripheral data line 5

It should say:

> MD4: EMMC peripheral data line 4
