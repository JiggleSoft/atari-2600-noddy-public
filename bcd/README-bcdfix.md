# Fixed Point Binary Coded Decimal (BCD) Math Library.

## Introduction

This directory contains a library of Fixed Point Binary Coded Decimal (BCD) routines for the 6502 family of CPU's.
Initially developed for the Atari 2600 video games console but applicable to any 65XX (with BCD / Decimal Flag support) powered console or computer.
The library developed here but will become part of JiggleSofts Atari 2600 extra libraries.
Intitial required for an Atari 2600 video game that is in development.


## Fixed Point Math Library.

### Data Types

#### Unsigned

```
Endian = Little Endian

Length is pre-configured between 2 to 8 bytes.

Example with configured length of 5 bytes.

              Lower Memory <----------------> Higher Memory
Byte              0        1        2        3        4
BCD Hex Value   1   0    3   2    5   4    7   6    9   8

Decimal Value   9876543210
```


#### Signed

```
Endian = Little Endian

Length is pre-configured between 2 to 8 bytes.

One (binary not BCD) byte is reserved for the sign:-
    $FF = -1 = Negative
    $00 =  0 = Zero
    $01 =  1 = Positive

Example with configured length of 5 bytes.

              Lower Memory <----------------> Higher Memory
Byte              0        1        2        3        4
BCD/Hex Value   1   0    3   2    5   4    7   6    F   F

Decimal Value   -76543210
```


### Configuration

; Configure 2 registers (m0 and m1), with byte size of 4, unsigned (8 BCD digits).

```
BCDFIX_REG_NUM = 2  ; (m0, m1)
BCDFIX_REG_SIZ = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFIX_NO_REG ; Let the include define the types.
BCDFIX_REG_SIG = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfix.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be defined.


### Macros

| Name | Input | Output | Description | Status |
|------|-------|--------|-------------|--------|
| CLR_FAST  | m0-m7 | A=0, Z=0, N=0 | CLeaR math register | COMPLETE |
| CLR_INLINE  | m0-m7, X or Y | Z=0,N=0 | CLeaR math register | TODO |
| CLR  | m0-m7, X or Y | A=0, X or Y=0, Z=0,N=0 | CLeaR math register. Calls clr_x or clr_y | TODO |
| | | | | |
| LDM | | | LoaD Math register | TODO |
| | | | | |
| TST | m0-m7 | NZ | TeST math register against zero | TODO |
| CMP | m0-m7,m0-m7 | Z=?,N=?,V=? | CoMPare math register | TODO |
| | | | | |
| BCDFIX_MODE_DECIMAL | | | Decimal mode on off save restore...|
| BCDFIX_MODE_RESTORE | | | |
| ||||
| INCU | | | INCrement Unsigned | TODO |
| INCS | | | INCrement Signed | TODO |
| DECU | | | DECrement Unsigned | TODO |
| DECS | | | DECrement Signed | TODO |
| ||||
| ADCU | | | ADd with Carry Unsigned | TODO |
| ADCS | | | ADd with Carry Signed | TODO |
| SBCU | | | SuBtract with Carry (borrow) Unsigned | TODO |
| SBCS | | | SuBtract with Carry (borrow) Signed | TODO |
| | | | | |
| MULU | | | |
| MULS | | | |
| MULU2 | | | |
| MULS2 | | | |
| DIVU | | | |
| DIVS | | | |
| DIVMODU | | | |
| DIVMODS | | | |
| MOD | | | |
| ||||
| LSRU | | | | |
| LSRS | | | | |
| ASRU | | | | |
| ASRS | | | | |
| LSLU | | | | |
| LSLS | | | | |
| ASLU | | | | |
| ASLS | | | | |
| LSRU2 | | | | |
| LSRS2 | | | | |
| ASRU2 | | | | |
| ASRS2 | | | | |
| LSLU2 | | | | |
| LSLS2 | | | | |
| ASLU2 | | | | |
| ASLS2 | | | | |
| ||||
| ABS ||||
| CEIL ||||
| FLOOR | | | | |
| MIN | | | | |
| MAX | | | | |
| NEG | | | | |
| RANDOM | | | | |
| TRUNC  | | | | |
| ROUND | | | | |
| GET EXPONENT | | | | |
| POW | | | | |
| SQR | | | | |
| SQRT | | | | |
| CBRT | | | | |
| ||||
| LOG ||||
| LOG10 ||||
| ||||
| HYPOT||||
| ||||
| ACOS ||||
| ASIN ||||
| ATAN ||||
| ATAN2||||
| COS ||||
| COSH ||||
| SIN||||
| SINH ||||
| TAN||||
| TANH||||
| ||||

TODO: add limits + data funcs

*Note: All macros are prefixed 'BCDFIX_'.*

All functons with D flag as input will require the Decimal mode flag pre-set.

Suffix:-\
_FAST = Sacrificing code for performance (inline with loops unrolled).\
_INLINE = Middle ground (inline).\
NONE = Sacrifices performance for code (calls off to shared library routine).

TODO: add limits.



### Functions

It is expected that the relevant macros will be used to call the functions.


#### Arithmetic

| Name | Input | Output | Description | Status |
|------|-------|--------|-------------|--------|
| bcdfix_uadc | | | Unsigned ADd with Carry | TODO |
| bcdfix_sadc | | | Signed ADd with Carry | TODO |
| bcdfix_usbc | | | Unsigned SuBtract with Carry | TODO |
bcdfix_ssbc

abs

acos
asin
atan
atan2
cbrt
ceil
cos
cosh
floor
getexponent
hypot
log
log10
max
min
neg
pow
random
truncate
round
sin
sinh
sqrt
tan
tanh


load
copy
converstion
toascii
toindex bytes 0-9 A=-



### Example Usage



## Contact

Justin Lane (atari2600@jigglesoft.co.uk)


## License

Copyright (c) 2022 Justin Lane

Licensed under the MIT license

See the LICENSE file.
