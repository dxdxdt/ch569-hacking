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

|# | NAME   |HSPI |BUS8| MMC | SPI | COM | MOD     | ETH | ISP |
|--|--------|-----|----|-----|-----|-----|---------|-----|-----|
| 0|GND     |     |    |     |     |     |         |     |     |
| 1|DP      |     |    |     |     |     |         |     |     |
| 2|DN      |     |    |     |     |     |         |     |     |
| 3|V3.3USB |     |    |     |     |     |         |     |     |
| 4|SSTXA   |     |    |     |     |     |         |     |     |
| 5|SSTXB   |     |    |     |     |     |         |     |     |
| 6|V1.2USB |     |    |     |     |     |         |     |     |
| 7|SSRXA   |     |    |     |     |     |         |     |     |
| 8|SSRXB   |     |    |     |     |     |         |     |     |
| 9|V1.2CORE|     |    |     |     |     |         |     |     |
|10|PA19    |HRCLK|    |     |     |     |         |     |     |
|11|PA18    |HRACT|    |     |     |     |         |     |     |
|12|PA8     |     |BRD#|     |     |TXD1 |         |     |     |
|13|PA7     |     |BD7 |     |     |RXD1 |         |     |     |
|14|PA6     |HRVLD|BD6 |     |     |TXD0_|         |     |     |
|15|PA5     |HD0  |BD5 |     |     |RXD0_|         |     |     |
|16|VDDIO   |     |    |     |     |     |         |     |     |
|17|PA4     |HD1  |BD4 |     |     |     |TMR2/PWM1|     |     |
|18|PA23    |HTRDY|    |     |     |     |         |     |     |
|19|PA3     |HD3  |BD3 |     |     |TXD2 |         |     |     |
|20|PA2     |HD4  |BD2 |MD7  |     |RXD2 |         |     |     |
|21|PA1     |HD5  |BD1 |MD6  |     |     |         |     |     |
|22|PA0     |HD6  |BD0 |MD5  |     |     |         |     |     |
|23|PB21    |HD7  |    |MD4  |     |     |         |     |     |
|24|PB20    |HD8  |    |MD3  |     |     |         |     |     |
|25|PB19    |HD9  |    |MD2  |     |     |         |     |     |
|26|PB18    |HD10 |    |MD1  |     |     |         |     |     |
|27|PB17    |HD11 |    |MD0  |     |     |         |     |     |
|28|PA17    |HD12 |    |     |     |     |         |     |     |
|29|PB16    |HD13 |    |MCMD |     |     |         |     |     |
|30|PB15    |HD14 |    |     |     |     |TMR1/PWM0|     |RST# |
|31|PB14    |HD15 |BA14|MSDCK|MISO1|     |         |     |     |
|32|PB0     |HD16 |BA0 |     |     |     |TMR1_    |EMDIO|     |
|33|PB1     |HD17 |BA1 |     |     |     |PWM2     |EMDCK|     |
|34|PB2     |HD18 |BA2 |     |     |     |PWM3     |ETXD3|     |
|35|PA20    |HD19 |    |     |     |     |         |EMCO |     |
|36|PB3     |HD20 |BA3 |     |     |RXD3 |TMR2_    |ETXD2|     |
|37|PB4     |HD21 |BA4 |     |     |TXD3 |         |ETXD1|     |
|38|PB5     |HD22 |BA5 |     |     |RXD0 |         |ETXD0|     |
|39|PB6     |HD23 |BA6 |     |     |TXD0 |         |ETXEN|     |
|40|PA16    |HD24 |    |     |     |     |         |ETCKI|     |
|41|PB7     |HD25 |BA7 |     |     |DSR  |         |ETXC |     |
|42|VDDIO   |     |    |     |     |     |         |     |     |
|43|PB8     |HD26 |BA8 |     |     |RI   |         |ERXC |     |
|44|PB9     |HD27 |BA9 |     |     |DCD  |         |ERXD3|     |
|45|PB22    |     |    |     |     |     |         |     |     |
|46|PB10    |HD28 |BA10|     |     |DTR  |         |ERXD2|     |
|47|PB23    |     |    |     |     |     |         |     |     |
|48|PB11    |HD29 |BA11|     |SCS1 |CTS  |         |ERXD1|     |
|49|PB24    |     |    |     |     |     |         |     |     |
|50|PB12    |HD30 |BA12|     |SCK1 |RTS  |         |ERXD0|     |
|51|PB13    |HD31 |BA13|     |MOSI1|     |         |ERXDV|     |
|52|PA21    |HTVLD|    |     |     |     |         |     |     |
|53|PA22    |HD2  |    |     |     |     |         |     |     |
|54|PA9     |HTREQ|BWR#|     |     |     |TMR0     |     |     |
|55|PA10    |HTACK|    |     |     |     |         |     |TCK  |
|56|PA11    |HTCLK|    |     |     |     |         |     |TIO  |
|57|PA12    |     |    |     |SCS  |     |         |     |SCS* |
|58|PA13    |     |    |     |SCK  |     |         |     |SCK* |
|59|PA14    |     |    |     |MOSI |     |         |     |MOSI*|
|60|PA15    |     |    |     |MISO |     |         |     |MISO*|
|61|VDDIO   |     |    |     |     |     |         |     |     |
|62|V3.3LDO |     |    |     |     |     |         |     |     |
|63|V1.2CORE|     |    |     |     |     |         |     |     |
|64|V3.3GX  |     |    |     |     |     |         |     |     |
|65|GXM     |     |    |     |     |     |         |     |     |
|66|GXP     |     |    |     |     |     |         |     |     |
|67|XO      |     |    |     |     |     |         |     |     |
|68|XI      |     |    |     |     |     |         |     |     |

### \*: ISP(in-system programmer) Flash Memory Access

The SPI0 pins(`SCS`, `SCK`, `MOSI`, `MISO`) can be configured to allow
the in-system programmer(debugger) to access the flash memory in the
chip. This is not explain in the datasheet but can be inferred from how
the evaluation board is wired up.

See `DEBUG_EN`, `CODE_READ_EN` and `RB_ROM_EXT_RE` in the datasheet.

## Characteristics of the RISC-V Processor

RISC-V cores can be configured in hundreds of ways, but the datasheet doesn't
say much about the RISC-V core. This is an attempt to demystify how the
processor is implemented.

### Unaligned Memory Access and Basic Arithmetics

Sampling Programs:

  - [catch-trap.c](eval-progs/catch-trap.c)
  - [benchmark-mstrict-align.c](eval-progs/benchmark-mstrict-align.c)

As you'd expect, the chip processor is not capable of unaligned memory access
and if the memory being accessed is not aligned to the word size boundary(4
bytes), the processor traps.

It's important to note that, if GCC statically detects at compile time that the
code would result in unaligned memory access, it automatically generates code to
avoid this with byte loads and shift operators. There's no warning with the
usual warning options(`-Wall` and `-Wextra`) and the specific warning option
`-Wcast-align` can be used to detect this. Be aware that the code generated in
this way performs poorly and bloats the size of the binary. The programmer
should take extra care to make sure the compiler doesn't generate subpar code
trying to avoid unaligned memory access. Currently, there's no option to control
this behaviour. This seems to be a bug in both GCC and the RISC-V specs itself.

The following benchmark shows performance penalty from GCC's strict memory
alignment fallback.

  - 80 MHz System clock
  - 512 iterations (2KB stack memory accessed in 4-byte words)
  - numbers in cycles

```
Aligned access:   cnt                  512
Aligned access:   add                 5134
Aligned access:   sub                 5131
Aligned access:   mul                 5131
Aligned access:   div                 5131
Aligned access:   mod                 5131
Unaligned access: cnt                  512
Unaligned access: add                20490
Unaligned access: sub                21003
Unaligned access: mul                21514
Unaligned access: div                21514
Unaligned access: mod                21002
```

According to the datasheet, the processor features a branch predictor. That
could explain the extra few cycles in the initial loop.

The number of cycles consumed grows by a factor of 4. As you'd expect with
microcontrollers, all the basic integer arithmetic operations(`+`, `-`, `*`,
`/`, `%`) appear to take the same number of cycles to complete.

## Errors: datasheet
### EMMC peripheral data line 4

In page 4 of the datasheet version V1.2, it says:

> MD4: EMMC peripheral data line 5

It should say:

> MD4: EMMC peripheral data line 4
