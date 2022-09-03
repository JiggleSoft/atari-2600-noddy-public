# Fixed Point Binary Coded Decimal (BCD) Math Library.

## Introduction

This directory contains a library of Fixed Point Binary Coded Decimal (BCD) routines for the 6502 family of CPU's.
Initially developed for the Atari 2600 video games console but applicable to any 65XX (with BCD / Decimal Flag support) powered console or computer.
The library developed here but will become part of JiggleSofts Atari 2600 extra libraries.
Intitial required for an Atari 2600 video game that is in development.


## Planned Releases

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
BCDFIX_REG_SIZE = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFIX_NO_REG ; Let the include define the types.
BCDFIX_REG_SIGN = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfix.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be defined.


### Macros Summary

| Name             | Parameters                      | Description                                                              | Version | Status |
|------------------|---------------------------------|--------------------------------------------------------------------------|---------|--------|
| LIB_INIT         | None.                           | Initialise the library. Save current arithmetic mode on the stack. Set arithmetic mode to decimal. | 1.0 | TODO |
| LIB_DONE         | None.                           | Uninitialise the library. Restore previously saved arithmetic mode from the stack.                 | 1.0 | TODO |
|                  |                                 |                                                                          |                       |         |        |
| MODE_BIN         | None.                           | Set arithmetic mode to binary.                                           | 1.0     | TODO   |
| MODE_DEC         | None.                           | Set arithmetic mode to decimal.                                          | 1.0     | TODO   |
| MODE_SAVE        | None.                           | Save current decimal mode on the stack.                                  | 1.0     | TODO   |
| MODE_REST        | None.                           | Restore decimal mode from the stack.                                     | 1.0     | TODO   |
|                  |                                 |                                                                          |         |        |
| VAR              | name = label name (optional),<br />qty = quantity of variables,<br />siz = size of each variable in bytes (optional; default = BCDFIX_REG_SIZ). | Reserve variable memory at any address available (BSS). | 1.0 | TODO |
| VAR_ZP           | name = label name (optional),<br />qty = quantity of variables,<br />siz = size of each variable in bytes (optional; default = BCDFIX_REG_SIZ). | Reserve variable memory within zero page (BSS).         | 1.0 | TODO |
|                  |                                 |                                                                          |         |        |
| DATA[U&#124;S]   | name = label name (optional),<br />val = BCD value as a string e.g. '9876543210' (signed/unsigned) or '-76543210' (signed). | DATA storage set wih constant value. | 1.0 | DEV |
|                  |                                 |                                                                          |         |        |
| CLR[U&#124;S]    | mreg = math register (m0 - m7). | CLeaR math register.                                                     | 1.0     | DEV    |
| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
| STM[U&#124;S]    | REVIEW                          | STore Math register                                                      | 1.0     | TODO   |
|                  |                                 |                                                                          |         |        |
| TO_ASC[U&#124;S] | mreg = math register (m0-m7),<br />sptr = address of buffer to receive the ASCII string. | Convert math register to ASCII string. | FIXME | 1.1 | TODO |
| TO_BYT[U&#124;S] | mreg = math register (m0-m7),<br />sptr = address of buffer to receive the byte array. | Convert math register to byte array (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*'). | FIXME | 1.1 | TODO |
| FR_ASC[U&#124;S] | mreg = math register (m0-m7),<br />sptr = address of buffer to parse the ASCII string from. | Convert to math register from ASCII string. | FIXME | 2.0 | TODO |
| FR_BYT[U&#124;S] | mreg = math register (m0-m7),<br />sptr = address of buffer to parse the byte array from. | Convert to math register from byte array (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*'). | FIXME | 2.0 | TODO |
|                  |                                 |                                                                          |         |        |
| TST              | mreg = math register (m0 - m7). | TeST math register against zero.                                         | 1.0     | TODO   |
| CMP[U&#124;S]    | mreg1 = math register (m0 - m7),<br />&lt;mreg2 = math register (m0 - m7) &#124;<br />bcd = BCD string&gt; | CoMPare math register Unsigned.    | 1.0     | TODO   |
|                  |                                 |                                                                          |         |        |
| INC[U&#124;S]    | mreg = math register (m0 - m7). | INCrement.                                                               | 1.0     | TODO   |
| DEC[U&#124;S]    | mreg = math register (m0 - m7). | DECrement.                                                               | 1.0     | TODO   |
|                  |                                 |                                                                          |         |        |
| ADC[U&#124;S]    | mreg1 = math register (m0 - m7) addend 1,<br />mreg2 = math register (m0 - m7) addend 2,<br />mregs = math register (m0 - m7) sum.         | ADd with Carry.     | 1.0 | TODO |
| SBC[U&#124;S]    | mregm = math register (m0 - m7) minuend,<br />mregs = math register (m0 - m7) subtrahend,<br />mregd = math register (m0 - m7) difference. | SuBtract with Carry | 1.0 | TODO |
|                  |                                 |                                                                          |         |        |
| MUL[U&#124;S]    | mreg1 = math register (m0 - m7) multiplicand,<br />mreg2 = math register (m0 - m7) multiplier,<br />mregp = math register (m0 - m7) product. | MULtipy Unsigned. | FAST,INLINE,FUNC | 1.2 | TODO |
| MULS[U&#124;S]   | mreg1 = math register (m0 - m7) multiplicand,<br />mreg2 = math register (m0 - m7) multiplier,<br />mregp = math register (m0 - m7) product. | MULtipy Signed.   | FAST,INLINE,FUNC | 1.2 | TODO |
| MULS2[U&#124;S]  | mreg1 = math register (m0 - m7) multiplicand,<br />mreg2 = math register (m0 - m7) multiplier,<br />mregph = math register (m0 - m7) product (high),<br />mregpl = math register (m0 - m7) product (low). | MULtipy Signed with high and low result.   | FAST,INLINE,FUNC | 1.2 | TODO |
| DIV[U&#124;S]    | mreg1 = math register (m0 - m7) dividend,<br />mreg2 = math register (m0 - m7) divisor,<br />mregq = math register (m0 - m7) quotient. | DIVide Unsigned. | FAST,INLINE,FUNC | 1.2 | TODO |
| DIVMOD[U&#124;S] | mreg1 = math register (m0 - m7) dividend,<br />mreg2 = math register (m0 - m7) divisor,<br />mregq = math register (m0 - m7) quotient,<br />mregr = math register (m0 - m7) remainder. | DIVide with MODulo Unsigned. | FAST,INLINE,FUNC | 1.2 | TODO |
| MODU[U&#124;S]   | mreg1 = math register (m0 - m7) dividend,<br />mreg2 = math register (m0 - m7) divisor,<br />mregr = math register (m0 - m7) remainder. | MODulo Unsigned. | FAST,INLINE,FUNC | 1.2 | TODO |
|                  |                                 |                                                                          |         |        |
| LSRU            | mreg = math register (m0 - m7). | Logical Shift Right Unsigned.                                            | 1.1     | TODO   |
| ASRU            | mreg = math register (m0 - m7). | Arithmetic Shift Right Unsigned.                                         | 1.1     | TODO   |
| LSLU            | mreg = math register (m0 - m7). | Logical Shift Left Unsigned.                                             | 1.1     | TODO   |
| ASLU            | mreg = math register (m0 - m7). | Arithmetic Shift Left Unsigned.                                          | 1.1     | TODO   |
| LSRU2           | mregh = math register (m0 - m7) (high),<br />mregl = math register (m0 - m7) (low). | Logical Shift Right Unsigned high and low.   | 1.1     | TODO   |
| ASRU2           | mregh = math register (m0 - m7) (high),<br />mregl = math register (m0 - m7) (low). | Arithmetic Shift Right Unsigned high and low. | 1.1     | TODO   |
| LSLU2           | mregh = math register (m0 - m7) (high),<br />mregl = math register (m0 - m7) (low). | Logical Shift Left Unsigned high and low.    | 1.1     | TODO   |
| ASLU2           | mregh = math register (m0 - m7) (high),<br />mregl = math register (m0 - m7) (low). | Arithmetic Shift Left Unsigned high and low. | 1.1     | TODO   |
|                  |                                 |                                                                          |         |        |
| ABS             | mreg = math register (m0 - m7). | ABSolute signed.                                                         | FAST,FUNC             | 1.1     | TODO   |
| CEILU           | mreg = math register (m0 - m7). |                                                                          | 1.1     | TODO   |
| CEILS           | mreg = math register (m0 - m7). |                                                                          | 1.1     | TODO   |
| FLOORU          | mreg = math register (m0 - m7). |                                                                          | 1.1     | TODO   |
| FLOORS          | mreg = math register (m0 - m7). |                                                                          | 1.1     | TODO   |
| MINU            | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7). | MINimum value Unsigned. | FAST,FUNC | 1.1 | TODO |
| MINS            | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7). | MINimum value Signed.   | FAST,FUNC | 1.1 | TODO |
| MAXU            | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7). | MAXimum value Unsigned. | FAST,FUNC | 1.1 | TODO |
| MAXS            | mreg1 = math register (m0 - m7),<br />mreg2 = math register (m0 - m7). | MAXimum value Signed.   | FAST,FUNC | 1.1 | TODO |
| NEG             | mreg = math register (m0 - m7). | NEGate signed.                                                           | 1.1     | TODO   |
| RANDOM          | REVIEW | | 1.5 | TODO |
| TRUNCU          | mreg = math register (m0 - m7). | review TRUNCate to integer (fast). | | 1.1 | TODO |
| TRUNCS          | mreg = math register (m0 - m7). | review TRUNCate to integer (fast). | | 1.1 | TODO |
| ROUNDU          | mreg = math register (m0 - m7). | review | | 1.1 | TODO |
| ROUNDS          | mreg = math register (m0 - m7). | review | | 1.1 | TODO |
|                  |                                 |                                                                          |         |        |
| GET EXPONENT | | | ?.? | NA?? |
| POW  | | | 1.4 | TODO |
| SQR  | | | 1.4 | TODO |
| CUB  | | | 1.4 | TODO |
| EXP  | | | 1.4 | TODO |
| SQRT | | | 3.0 | TODO |
| CBRT | | | 3.1 | TODO |
|                  |                                 |                                                                          |         |        |
| BCD_TO_BINU | | | 1.6 | TODO |
| BIN_TO_BCDU | | | 1.6 | TODO |
| BCD_TO_BINS | | | 1.6 | TODO |
| BIN_TO_BCDS | | | 1.6 | TODO |
|                  |                                 |                                                                          |         |        |
| BCD_TO_BINU | | | 1.7 | TODO |
| BIN_TO_BCDU | | | 1.7 | TODO |
| BCD_TO_BINS | | | 1.7 | TODO |
| BIN_TO_BCDS | | | 1.7 | TODO |
|                  |                                 |                                                                          |         |        |
| LOG   | | | 4.0 | TODO |
| LOG10 | | | 4.0 | TODO |
|                  |                                 |                                                                          |         |        |
| HYPOT | | | | ?.? | REVIEW |
|                  |                                 |                                                                          |         |        |
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
|                  |                                 |                                                                          |         |        |
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
|                  |                                 |                                                                          |         |        |
| CONSTANTS | | TO BE DEFINED | 1.3 | TODO |
|                 |                                 |                                                                          |         |        |

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

