# Floating Point Binary Coded Decimal (BCD) Math Library.

## Introduction

This directory contains a library of Floating Point Binary Coded Decimal (BCD) routines for the 6502 family of CPU's.
Initially developed for the Atari 2600 video games console but applicable to any 65XX (with BCD / Decimal Flag support) powered console or computer.
The library developed here but will become part of JiggleSofts Atari 2600 extra libraries.
Intitial required for an Atari 2600 video game that is in development.


## Floating Point Math Library.

### Data Types

```
Endian = Little Endian

Length is configurable between 4 to 8 bytes.

One (binary not BCD) byte is reserved for the exponent and another for the sign.

Example with configured length of 5 bytes.

                          Lower Memory <----------------> Higher Memory
Byte                          0        1        2        3        4
Nybble Order                1   0    3   2    5   4    7   6    9   8
Mantissa / Exponent / Sign  M   M    M   M    M   M    E   E    S   S
BCD / Hex Value             5   9    4   1    3   1    8   0    0   0

Decimal Value   3.14159

TODO: check exponent value with decimal value above.
```


### Example

FIXME

; Configure 2 registers (m0 and m1) with byte size of 4.

```
BCDFP_REG_NUM = 2  ; (m0, m1)
BCDFP_REG_SIZ = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFP_NO_REG ; Let the includeinclude define the types.
BCDFP_REG_SIG = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfp.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be defined.


### Macros

| Name | Input | Output | Description | Status |
|------|-------|--------|-------------|--------|
| BCDFP_LDMN | | | Decimal mode on off save restore...|
| ||||
| BCDFP_LDMN | | | |
| ||||
| BCDFP_LDMN | | | |
| ||||
| BCDFP_ADC | | | ADd with Carry | Completed |
| BCDFIX_SBC | | | SuBtract with Carry (borrow) |
| BCDFIX_MUL | | | MULtiply |
| BCDFIX_MUL | | | MULtiply |
| BCDFIX_MUL | | | |
| BCDFIX_MUL | | | |
| BCDFIX_MUL | | | |
| BCDFIX_MUL | | | |
| BCDFIX_DIV | | | DIVision |
| BCDFIX_DIV | | | DIVision |
| BCDFIX_MOD | | | |
| BCDFIX_MOD | | | |
| BCDFIX_DIV | | | |
| BCDFIX_DIV | | | |



### Functions





## Contact

Justin Lane (atari2600@jigglesoft.co.uk)


## License

Copyright (c) 2022 Justin Lane

Licensed under the MIT license

See the LICENSE file.

