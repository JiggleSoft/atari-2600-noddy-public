# Fixed Point Binary Coded Decimal (BCD) Math Library.

## Introduction

This directory contains a library of Fixed Point Binary Coded Decimal (BCD) routines for the 6502 family of CPU's.
Initially developed for the Atari 2600 video games console but applicable to any 65XX (with BCD / Decimal Flag support) powered console or computer.
The library developed here but will become part of JiggleSofts Atari 2600 extra libraries.
Intitial required for an Atari 2600 video game that is in development.


### Planned Releases

| Version | Description | Status |
|---------|-------------|--------|
| 1.0     | Basic core functionality: configuration, registers, mode, variables, data, clear, load, store, test, compare, increment, decrement, addition, subtraction. | DEV | 
| 1.1     | Additional core functionality: conversion to bytes and ascii, shifting, abs, ceil, floor, min, max, neg, trunc, round. | TODO |
| 1.2     | Additional core functionality: multiplication, division, modulo. | TODO |
| 1.3     | constants. | TODO |
| 1.4     | powers, square, cube, exp. | TODO |
| 1.5     | random. | TODO |
| 1.6     | Conversion of BCD to and from binary integer. | TODO |
| 1.7     | Conversion of BCD to and from fixed-point binary | TODO |
| 2.0     | Conversion from bytes and ascii. | TODO |
| 3.0     | square root. | TODO |
| 3.1     | cube root. | TODO |
| 4.0     | logarithms | TODO |
| 5.0     | angle conversions | TODO |
| 5.1     | sine, cosine, tangent | TODO |
| 5.2     | acos, asin, atan, atan2, cosh, sinh, tanh | TODO |
| 5.3+    | Other transcendental functions. | TODO |

*Note: Version 1.5 would provide enough functionality for the planned game.*


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
BCDFIX_REG_QTY = 2  ; (m0, m1)
BCDFIX_REG_SIZ = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFIX_NO_REG ; Let the include define the types.
BCDFIX_REG_SIG = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfix.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be defined.


### Macros Summary

| Name            | Parameters                      | Description                                                              | Version | Status |
|-----------------|---------------------------------|--------------------------------------------------------------------------|---------|--------|
| MODE_INIT       | None.                           | Save current decimal mode on the stack and enable decimal mode (inline). | 1.0     | DONE   |
| MODE_DONE       | None.                           | Restore previously saved decimal mode from the stack (inline).           | 1.0     | DONE   |
|                 |                                 |                                                                          |         |        |
| VAR             | name = label name (optional),<br />qty = quantity of variables,<br />siz = size of each variable in bytes (optional; default = BCDFIX_REG_SIZ). | Reserve variable memory at any address available (BSS). | 1.0 | DONE |
| VAR_ZP          | name = label name (optional),<br />qty = quantity of variables,<br />siz = size of each variable in bytes (optional; default = BCDFIX_REG_SIZ). | Reserve variable memory within zero page (BSS).         | 1.0 | DONE |
|                 |                                 |                                                                          |         |        |
| DATAU           | name = label name (optional),<br />val = BCD value as a string e.g. '9876543210'. | DATA storage set wih Unsigned constant value. | 1.0 | DEV |
| DATAS           | name = label name (optional),<br />val = BCD value as a string e.g. '-76543210'.  | DATA storage set with Signed constant value.  | 1.0 | DEV |
|                 |                                 |                                                                          |         |        |
| CLR_FAST        | mreg = math register (m0 - m7). | CLeaR math register (fast).                                              | 1.0     | TEST   |
| CLR_INLINE      | mreg = math register (m0 - m7). | CLeaR math register (inline).                                            | 1.0     | TODO   |
| CLR             | mreg = math register (m0 - m7). | CLeaR math register (function).                                          | 1.0     | TODO   |
|                 |                                 |                                                                          |         |        |
| LDM             | | LoaD Math register | 1.0 | TODO |
| STM             | | STore Math register | 1.0 | TODO |
|                 |                                 |                                                                          |         |        |
| CONV_TO_ASCII   | | Convert to ASCII | 1.1 | TODO |
| CONV_TO_BYTES   | | Convert to BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*') | 1.1 | TODO |
| CONV_FROM_ASCII | | Convert from ASCII | 2.0 | TODO |
| CONV_FROM_BYTES | | Convert from BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*') | 2.0 | TODO |
|                 |                                 |                                                                          |         |        |
| TST_FAST        | mreg = math register (m0 - m7). | TeST math register against zero (fast).                                  | 1.0     | TODO   |
| TST_INLINE      | mreg = math register (m0 - m7). | TeST math register against zero (inline).                                | 1.0     | TODO   |
| TST             | mreg = math register (m0 - m7). | TeST math register against zero (function).                              | 1.0     | TODO   |
| CMP_FAST        | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7) | CoMPare math register (fast).      | 1.0     | TODO   |
| CMP_INLINE      | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7) | CoMPare math register (inline).    | 1.0     | TODO   |
| CMP             | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7) | CoMPare math register (function).  | 1.0     | TODO   |
|                 |                                 |                                                                          |         |        |
| INCU_FAST       | mreg = math register (m0 - m7). | INCrement Unsigned (fast).                                               | 1.0     | TODO   |
| INCU_INLINE     | mreg = math register (m0 - m7). | INCrement Unsigned (inline).                                             | 1.0     | TODO   |
| INCU            | mreg = math register (m0 - m7). | INCrement Unsigned (function).                                           | 1.0     | TODO   |
| INCS_FAST       | mreg = math register (m0 - m7). | INCrement Signed (fast).                                                 | 1.0     | TODO   |
| INCS_INLINE     | mreg = math register (m0 - m7). | INCrement Signed (inline).                                               | 1.0     | TODO   |
| INCS            | mreg = math register (m0 - m7). | INCrement Signed (function).                                             | 1.0     | TODO   |
| DECU_FAST       | mreg = math register (m0 - m7). | DECrement Unsigned (fast).                                               | 1.0     | TODO   |
| DECU_INLINE     | mreg = math register (m0 - m7). | DECrement Unsigned (inline).                                             | 1.0     | TODO   |
| DECU            | mreg = math register (m0 - m7). | DECrement Unsigned (function).                                           | 1.0     | TODO   |
| DECS_FAST       | mreg = math register (m0 - m7). | DECrement Signed (fast).                                                 | 1.0     | TODO   |
| DECS_INLINE     | mreg = math register (m0 - m7). | DECrement Signed (inline).                                               | 1.0     | TODO   |
| DECS            | mreg = math register (m0 - m7). | DECrement Signed (function).                                             | 1.0     | TODO   |
|                 |                                 |                                                                          |         |        |
| ADCU_FAST       | | ADd with Carry Unsigned (fast) | 1.0 | TODO |
| ADCU            | | ADd with Carry Unsigned | 1.0 | TODO |
| ADCS_FAST | | ADd with Carry Signed (fast) | 1.0 | TODO |
| ADCS      | | ADd with Carry Signed | 1.0 | TODO |
| SBCU_FAST | | SuBtract with Carry (borrow) Unsigned (fast) | 1.0 | TODO |
| SBCU      | | SuBtract with Carry (borrow) Unsigned | 1.0 | TODO |
| SBCS_FAST | | SuBtract with Carry (borrow) Signed (fast) | 1.0 | TODO |
| SBCS      | | SuBtract with Carry (borrow) Signed | 1.0 | TODO |
|                 |                                |                                                                          |         |        |
| MULU    | | | 1.2 | TODO |
| MULS    | | | 1.2 | TODO |
| MULU2   | | | 1.2 | TODO |
| MULS2   | | | 1.2 | TODO |
| DIVU    | | | 1.2 | TODO |
| DIVS    | | | 1.2 | TODO |
| DIVMODU | | | 1.2 | TODO |
| DIVMODS | | | 1.2 | TODO |
| MOD     | | | 1.2 | TODO |
|                 |                                |                                                                          |         |        |
| LSRU  | | | 1.1 | TODO |
| LSRS  | | | 1.1 | TODO |
| ASRU  | | | 1.1 | TODO |
| ASRS  | | | 1.1 | TODO |
| LSLU  | | | 1.1 | TODO |
| LSLS  | | | 1.1 | TODO |
| ASLU  | | | 1.1 | TODO |
| ASLS  | | | 1.1 | TODO |
| LSRU2 | | | 1.1 | TODO |
| LSRS2 | | | 1.1 | TODO |
| ASRU2 | | | 1.1 | TODO |
| ASRS2 | | | 1.1 | TODO |
| LSLU2 | | | 1.1 | TODO |
| LSLS2 | | | 1.1 | TODO |
| ASLU2 | | | 1.1 | TODO |
| ASLS2 | | | 1.1 | TODO |
|                 |                                |                                                                          |         |        |
| ABS    | | | 1.1 | TODO |
| CEIL   | | | 1.1 | TODO |
| FLOOR  | | | 1.1 | TODO |
| MIN    | | | 1.1 | TODO |
| MAX    | | | 1.1 | TODO |
| NEG    | | | 1.1 | TODO |
| RANDOM | | | 1.5 | TODO |
| TRUNC  | | | 1.1 | TODO |
| ROUND  | | | 1.1 | TODO |
|                 |                                |                                                                          |         |        |
| GET EXPONENT | | | ?.? | NA?? |
| POW  | | | 1.4 | TODO |
| SQR  | | | 1.4 | TODO |
| CUB  | | | 1.4 | TODO |
| EXP  | | | 1.4 | TODO |
| SQRT | | | 3.0 | TODO |
| CBRT | | | 3.1 | TODO |
|                 |                                |                                                                          |         |        |
| BCD_TO_BINU | | | 1.6 | TODO |
| BIN_TO_BCDU | | | 1.6 | TODO |
| BCD_TO_BINS | | | 1.6 | TODO |
| BIN_TO_BCDS | | | 1.6 | TODO |
|                 |                                |                                                                          |         |        |
| BCD_TO_BINU | | | 1.7 | TODO |
| BIN_TO_BCDU | | | 1.7 | TODO |
| BCD_TO_BINS | | | 1.7 | TODO |
| BIN_TO_BCDS | | | 1.7 | TODO |
|                 |                                |                                                                          |         |        |
| LOG   | | | 4.0 | TODO |
| LOG10 | | | 4.0 | TODO |
|                 |                                |                                                                          |         |        |
| HYPOT | | | | ?.? | REVIEW |
|                 |                                |                                                                          |         |        |
| ACOS  | | | 5.2  | TODO |
| ASIN  | | | 5.2  | TODO |
| ATAN  | | | 5.2  | TODO |
| ATAN2 | | | 5.2  | TODO |
| COS   | | | 5.1  | TODO|
| COSH  | | | 5.2  | TODO |
| SIN   | | | 5.1  | TODO|
| SINH  | | | 5.2  | TODO |
| TAN   | | | 5.1  | TODO |
| TANH  | | | 5.2  | TODO |
|                 |                                |                                                                          |         |        |
| RAD_TO_DEG  | | | 5.0 | TODO |
| RAD_TO_BYTE | | | 5.0 | TODO |
| RAD_TO_1K   | | | 5.0 | TODO |
| DEG_TO_RAD  | | | 5.0 | TODO |
| DEG_TO_BYTE | | | 5.0 | TODO |
| DEG_TO_1K   | | | 5.0 | TODO |
| BYTE_TO_RAD | | | 5.0 | TODO |
| BYTE_TO_DEG | | | 5.0 | TODO |
| BYTE_TO_1K  | | | 5.0 | TODO |
| 1K_TO_RAD   | | | 5.0 | TODO |
| 1K_TO_DEG   | | | 5.0 | TODO |
| 1K_TO_BYTE  | | | 5.0 | TODO |
|                 |                                |                                                                          |         |        |
| CONSTANTS | | TO BE DEFINED | 1.3 | TODO |
|                 |                                |                                                                          |         |        |

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



### Macro Detailed

#### MODE_INIT

#### MODE_DONE

#### VAR

#### VAR_ZP

#### DATAU

#### DATAS

#### CLR_FAST

#### CLR_INLINE

#### CLR

#### CLR_SLOW



| Name            | Parameters | Action | Description | Version | Status |
|-----------------|------------|--------|-------------|---------|--------|

| MODE_INIT       | None       | SR -> STACK,<br />D = 1 | Save current decimal mode on the stack and enable decimal mode (inline).  | 1.0 | DONE |
| MODE_DONE       | None       | STACK -> SR,<br />SR = Restored SR | Restore previously saved decimal mode from the stack (inline). | 1.0 | DONE |
| | | | | | |
| VAR             | name = label name (optional),<br />qty = quantity of variables,<br />siz = size of each variable in bytes (optional; default = BCDFIX_REG_SIZ) | BSS memory reserved. | Reserve variable memory at any address available. | 1.0 | DONE |
| VAR_ZP          | name = label name (optional),<br />qty = quantity of variables,<br />siz = size of each variable in bytes (optional; default = BCDFIX_REG_SIZ) | BSS memory reserved. | Reserve variable memory within zero page. | 1.0 | DONE |
| | | | | | |
| DATAU           | name = label name (optional),<br />val = BCD value as a string e.g. '9876543210'.  | Read-only data storage set with constant value. | DATA storage set wih Unsigned constant value. | 1.0 | DEV |
| DATAS           | name = label name (optional),<br />val = BCD value as a string e.g. '-76543210'. | Read-only data storage set with constant value. | DATA storage set with Signed constant value. | 1.0 | DEV |
| | | | | | |
| CLR_FAST        | mreg = math register (m0 - m7) | A, Z, N, SR, ?A=0, Z=0, N=0 | CLeaR math register (fast). | 1.0 | TEST |
| CLR_INLINE      | mreg = math register (m0 - m7) | A, X, Y, Z, N, SR, ?Z=0,N=0 | CLeaR math register (inline). | 1.0 | TODO |
| CLR             | mreg = math register (m0 - m7) | A=0, X= or Y=0, Z=0,N=0, CLeaR math register. Calls clr_x or clr_y | CLeaR math register (func).  | 1.0 | TODO |
| | | | | | |
| LDM             | | | LoaD Math register | 1.0 | TODO |
| STM             | | | STore Math register | 1.0 | TODO |
| | | | | | |
| CONV_TO_ASCII   | | | Convert to ASCII | 1.1 | TODO |
| CONV_TO_BYTES   | | | Convert to BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*') | 1.1 | TODO |
| CONV_FROM_ASCII | | | Convert from ASCII | 2.0 | TODO |
| CONV_FROM_BYTES | | | Convert from BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*') | 2.0 | TODO |
| | | | | | |
| TST             | mreg = math register (m0 - m7) | NZ | TeST math register against zero | 1.0 | TODO |
| CMP             | mreg = math register (m0 - m7)m0-m7,<br />mreg = math register (m0 - m7) | Z=?,N=?,V=? | CoMPare math register | 1.0 | TODO |
| | | | | | |
| INCU_FAST | mreg = math register (m0 - m7) | | INCrement Unsigned (fast) | 1.0 | TODO |
| INCU      | mreg = math register (m0 - m7) | | INCrement Unsigned        | 1.0 | TODO |
| INCS_FAST | mreg = math register (m0 - m7) | | INCrement Signed (fast)   | 1.0 | TODO |
| INCS      | mreg = math register (m0 - m7) | | INCrement Signed          | 1.0 | TODO |
| DECU_FAST | mreg = math register (m0 - m7) | | DECrement Unsigned (fast) | 1.0 | TODO |
| DECU      | mreg = math register (m0 - m7) | | DECrement Unsigned        | 1.0 | TODO |
| DECS_FAST | mreg = math register (m0 - m7) | | DECrement Signed (fast)   | 1.0 | TODO |
| DECS      | mreg = math register (m0 - m7) | | DECrement Signed          | 1.0 | TODO |
| | | | | | |
| ADCU_FAST | | | ADd with Carry Unsigned (fast) | 1.0 | TODO |
| ADCU      | | | ADd with Carry Unsigned | 1.0 | TODO |
| ADCS_FAST | | | ADd with Carry Signed (fast) | 1.0 | TODO |
| ADCS      | | | ADd with Carry Signed | 1.0 | TODO |
| SBCU_FAST | | | SuBtract with Carry (borrow) Unsigned (fast) | 1.0 | TODO |
| SBCU      | | | SuBtract with Carry (borrow) Unsigned | 1.0 | TODO |
| SBCS_FAST | | | SuBtract with Carry (borrow) Signed (fast) | 1.0 | TODO |
| SBCS      | | | SuBtract with Carry (borrow) Signed | 1.0 | TODO |
| | | | | | |
| MULU    | | | | 1.2 | TODO |
| MULS    | | | | 1.2 | TODO |
| MULU2   | | | | 1.2 | TODO |
| MULS2   | | | | 1.2 | TODO |
| DIVU    | | | | 1.2 | TODO |
| DIVS    | | | | 1.2 | TODO |
| DIVMODU | | | | 1.2 | TODO |
| DIVMODS | | | | 1.2 | TODO |
| MOD     | | | | 1.2 | TODO |
| | | | | | |
| LSRU  | | | | 1.1 | TODO |
| LSRS  | | | | 1.1 | TODO |
| ASRU  | | | | 1.1 | TODO |
| ASRS  | | | | 1.1 | TODO |
| LSLU  | | | | 1.1 | TODO |
| LSLS  | | | | 1.1 | TODO |
| ASLU  | | | | 1.1 | TODO |
| ASLS  | | | | 1.1 | TODO |
| LSRU2 | | | | 1.1 | TODO |
| LSRS2 | | | | 1.1 | TODO |
| ASRU2 | | | | 1.1 | TODO |
| ASRS2 | | | | 1.1 | TODO |
| LSLU2 | | | | 1.1 | TODO |
| LSLS2 | | | | 1.1 | TODO |
| ASLU2 | | | | 1.1 | TODO |
| ASLS2 | | | | 1.1 | TODO |
| | | | | | |
| ABS    | | | | 1.1 | TODO |
| CEIL   | | | | 1.1 | TODO |
| FLOOR  | | | | 1.1 | TODO |
| MIN    | | | | 1.1 | TODO |
| MAX    | | | | 1.1 | TODO |
| NEG    | | | | 1.1 | TODO |
| RANDOM | | | | 1.5 | TODO |
| TRUNC  | | | | 1.1 | TODO |
| ROUND  | | | | 1.1 | TODO |
| | | | | | |
| GET EXPONENT | | | | ?.? | NA?? |
| POW  | | | | 1.4 | TODO |
| SQR  | | | | 1.4 | TODO |
| CUB  | | | | 1.4 | TODO |
| EXP  | | | | 1.4 | TODO |
| SQRT | | | | 3.0 | TODO |
| CBRT | | | | 3.1 | TODO |
| | | | | | |
| BCD_TO_BINU | | | | 1.6 | TODO |
| BIN_TO_BCDU | | | | 1.6 | TODO |
| BCD_TO_BINS | | | | 1.6 | TODO |
| BIN_TO_BCDS | | | | 1.6 | TODO |
| | | | | | |
| BCD_TO_BINU | | | | 1.7 | TODO |
| BIN_TO_BCDU | | | | 1.7 | TODO |
| BCD_TO_BINS | | | | 1.7 | TODO |
| BIN_TO_BCDS | | | | 1.7 | TODO |
| | | | | | |
| LOG   | | | | 4.0 | TODO |
| LOG10 | | | | 4.0 | TODO |
| | | | | | |
| HYPOT | | | | ?.? | REVIEW |
| | | | | | |
| ACOS  | | | | 5.2  | TODO |
| ASIN  | | | | 5.2  | TODO |
| ATAN  | | | | 5.2  | TODO |
| ATAN2 | | | | 5.2  | TODO |
| COS   | | | | 5.1  | TODO|
| COSH  | | | | 5.2  | TODO |
| SIN   | | | | 5.1  | TODO|
| SINH  | | | | 5.2  | TODO |
| TAN   | | | | 5.1  | TODO |
| TANH  | | | | 5.2  | TODO |
| | | | | | |
| RAD_TO_DEG  | | | | 5.0 | TODO |
| RAD_TO_BYTE | | | | 5.0 | TODO |
| RAD_TO_1K   | | | | 5.0 | TODO |
| DEG_TO_RAD  | | | | 5.0 | TODO |
| DEG_TO_BYTE | | | | 5.0 | TODO |
| DEG_TO_1K   | | | | 5.0 | TODO |
| BYTE_TO_RAD | | | | 5.0 | TODO |
| BYTE_TO_DEG | | | | 5.0 | TODO |
| BYTE_TO_1K  | | | | 5.0 | TODO |
| 1K_TO_RAD   | | | | 5.0 | TODO |
| 1K_TO_DEG   | | | | 5.0 | TODO |
| 1K_TO_BYTE  | | | | 5.0 | TODO |
| | | | | | |
| CONSTANTS | | | TO BE DEFINED | 1.3 | TODO |
| | | | | | |




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

