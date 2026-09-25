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

RISC-V cores can be configured in hundreds of ways, but the datasheet
doesn't say much about the RISC-V core. This is an attempt to demystify
how the processor is implemented.

### Unaligned Memory Access and Basic Arithmetics

Sampling Programs:

  - [catch-trap.c](eval-progs/catch-trap.c)
  - [benchmark-mstrict-align.c](eval-progs/benchmark-mstrict-align.c)

As you'd expect, the chip processor is not capable of unaligned memory
access and if the memory being accessed is not aligned to the word size
boundary(4 bytes), the processor traps.

It's important to note that, if GCC statically detects at compile time
that the code would result in unaligned memory access, it automatically
generates code to avoid this with byte loads and shift operators.
There's no warning with the usual warning options(`-Wall` and `-Wextra`)
and the specific warning option `-Wcast-align` can be used to detect
this. Be aware that the code generated in this way performs poorly and
bloats the size of the binary. The programmer should take extra care to
make sure the compiler doesn't generate subpar code trying to avoid
unaligned memory access. Currently, there's no option to control this
behaviour. This seems to be a bug in both GCC and the RISC-V specs
itself.

The following benchmark shows performance penalty from GCC's strict
memory alignment fallback.

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

According to the datasheet, the processor features a branch predictor.
That could explain the extra few cycles in the initial loop.

The number of cycles consumed grows by a factor of 4. As you'd expect
with microcontrollers, all the basic integer arithmetic operations(`+`,
`-`, `*`, `/`, `%`) appear to take the same number of cycles to
complete.

### On "Programmable Fast Interrupt Controller"(PFIC)

Link: https://www.reddit.com/r/RISCV/comments/126262j/notes_on_wch_fast_interrupts/

The PFIC implementation is similar to(but not identical to) "shadow
registers" or "bank switching" seen in Intel 8051. Unlike the
traditional implementation where the set of registers is set aside or
bank-switched, the WCH's FPIC relies on the hardware's ability to make a
stack frame to save general purpose registers before entering an
ISR(interrupt service routine) in just a few cycles. This is done much
faster than the standard RISC-V ISR where the general purpose registers
used the ISR are saved and restored explicitly one by one in the
prologue and epilogue of the ISR, respectively.

Sample program: [./eval-progs/benchmark-interrupt.c](./eval-progs/benchmark-interrupt.c)

With the standard RISC-V machine ISR function
attribute(`__attribute__((interrupt))`), the GCC produces `sw` in the
prologue.

```
00000410 <TMR0_IRQHandler>:
     410:       715d                    addi    sp,sp,-80
     412:       de22                    sw      s0,60(sp)
     414:       dc2a                    sw      a0,56(sp)
     416:       da2e                    sw      a1,52(sp)
     418:       d832                    sw      a2,48(sp)
     41a:       d43a                    sw      a4,40(sp)
     41c:       c686                    sw      ra,76(sp)
     41e:       c496                    sw      t0,72(sp)
     420:       c29a                    sw      t1,68(sp)
     422:       c09e                    sw      t2,64(sp)
     424:       d636                    sw      a3,44(sp)
     426:       d23e                    sw      a5,36(sp)
     428:       d042                    sw      a6,32(sp)
     42a:       ce46                    sw      a7,28(sp)
     42c:       cc72                    sw      t3,24(sp)
     42e:       ca76                    sw      t4,20(sp)
     430:       c87a                    sw      t5,16(sp)
     432:       c67e                    sw      t6,12(sp)
     434:       e000f437                lui     s0,0xe000f
     438:       00042023                sw      zero,0(s0)
     43c:       4050                    lw      a2,4(s0)
     43e:       000025b7                lui     a1,0x2
     442:       441c                    lw      a5,8(s0)
     444:       00002537                lui     a0,0x2
     448:       fff64613                not     a2,a2
     44c:       b8858593                addi    a1,a1,-1144
     450:       b7c50513                addi    a0,a0,-1156
     454:       0fa010ef                jal     154e <iprintf>
     458:       4705                    li      a4,1
     45a:       80e18c23                sb      a4,-2024(gp)
     45e:       400027b7                lui     a5,0x40002
     462:       00078123                sb      zero,2(a5)
     466:       4709                    li      a4,2
     468:       00e78023                sb      a4,0(a5)
     46c:       57fd                    li      a5,-1
     46e:       c45c                    sw      a5,12(s0)
     470:       c81c                    sw      a5,16(s0)
     472:       10500793                li      a5,261
     476:       c01c                    sw      a5,0(s0)
     478:       5472                    lw      s0,60(sp)
     47a:       40b6                    lw      ra,76(sp)
     47c:       42a6                    lw      t0,72(sp)
     47e:       4316                    lw      t1,68(sp)
     480:       4386                    lw      t2,64(sp)
     482:       5562                    lw      a0,56(sp)
     484:       55d2                    lw      a1,52(sp)
     486:       5642                    lw      a2,48(sp)
     488:       56b2                    lw      a3,44(sp)
     48a:       5722                    lw      a4,40(sp)
     48c:       5792                    lw      a5,36(sp)
     48e:       5802                    lw      a6,32(sp)
     490:       48f2                    lw      a7,28(sp)
     492:       4e62                    lw      t3,24(sp)
     494:       4ed2                    lw      t4,20(sp)
     496:       4f42                    lw      t5,16(sp)
     498:       4fb2                    lw      t6,12(sp)
     49a:       6161                    addi    sp,sp,80
     49c:       30200073                mret
```

Whereas with `__attribute__((interrupt("WCH-Interrupt-fast")))`, only
the long-lived registers are saved.

```
000003cc <TMR0_IRQHandler>:
     3cc:       1141                    addi    sp,sp,-16
     3ce:       c622                    sw      s0,12(sp)
     3d0:       e000f437                lui     s0,0xe000f
     3d4:       00042023                sw      zero,0(s0)
     3d8:       4050                    lw      a2,4(s0)
     3da:       000025b7                lui     a1,0x2
     3de:       441c                    lw      a5,8(s0)
     3e0:       00002537                lui     a0,0x2
     3e4:       fff64613                not     a2,a2
     3e8:       a8458593                addi    a1,a1,-1404
     3ec:       a7850513                addi    a0,a0,-1416
     3f0:       05a010ef                jal     144a <iprintf>
     3f4:       4705                    li      a4,1
     3f6:       80e18c23                sb      a4,-2024(gp)
     3fa:       400027b7                lui     a5,0x40002
     3fe:       00078123                sb      zero,2(a5)
     402:       4709                    li      a4,2
     404:       00e78023                sb      a4,0(a5)
     408:       57fd                    li      a5,-1
     40a:       c45c                    sw      a5,12(s0)
     40c:       c81c                    sw      a5,16(s0)
     40e:       10500793                li      a5,261
     412:       c01c                    sw      a5,0(s0)
     414:       4432                    lw      s0,12(sp)
     416:       0141                    addi    sp,sp,16
     418:       30200073                mret
```

and the following is the overhead measured in cycles. The system
frequency has no effect on the cycles measured.

```
USE_WCH_FPIC_HACK: 0
Interrupt benchmark @120000000Hz:
SW  :         52         50
TMR0:        152         50
TMR1:        252         50
TMR2:        352         50
```

```
USE_WCH_FPIC_HACK: 2
Interrupt benchmark @120000000Hz:
SW  :         20         18
TMR0:        120         18
TMR1:        220         18
TMR2:        320         18
```

We can see that, for this ISR, 16 registers are saved and restored. As
the delta measured is 32 cycles, we can infer that `sw` instruction
probably takes 2 cycles to complete.

#### The *Naked* Function Hack

Also included in the sample program is the "naked function hack" for
eliminating unnecessary `sw` instructions in ISRs with the mainline GCC.
This can be enabled by defining `USE_WCH_FPIC_HACK` as an integer value
of 1. The following is the first instructions generated with the hack
and the benchmark data.

```
000003d4 <TMR0_IRQHandler>:
     3d4:       2019                    jal     3da <TMR0_IRQHandler_inner>
     3d6:       30200073                mret

000003da <TMR0_IRQHandler_inner>:
     3da:       1141                    addi    sp,sp,-16
     3dc:       c422                    sw      s0,8(sp)
     3de:       c606                    sw      ra,12(sp)
...
```

```
USE_WCH_FPIC_HACK: 1
Interrupt benchmark @120000000Hz:
SW  :         24         23
TMR0:        124         24
TMR1:        224         24
TMR2:        324         24
```

The hack involves unnecessarily using `jal` and `ret` to structure the
inner function. Also, `ra` is saved and restores in and out of the stack
although it seems that the PFIC takes care of the register already. The
hack costs 4 and 5 cycles more than the ISR with the attribute
`"WCH-Interrupt-fast"`. This is still better than the standard ISR
generation with the *bloat* complexity of O(N).

This could be a good enough substitute when you use the mainline GCC.
**However**, I'd recommend against using it on prod because WCH's PFIC
implementation is not well documented. We can never be sure that we can
expect the same behaviour from the PFIC across all of WCH's chips unless
there's a authoritative and defining datasheet or PFIC architecture
spec. The major issue off the bat would be that we don't know which
registers are taken care of by the PFIC.

Another problem is the use of `"naked"` attribute, for which there
aren't many use cases and therefore could potentially be deprecated and
removed in the future.

## Errors: datasheet
### EMMC peripheral data line 4

In page 4 of the datasheet version V1.2, it says:

> MD4: EMMC peripheral data line 5

It should say:

> MD4: EMMC peripheral data line 4
