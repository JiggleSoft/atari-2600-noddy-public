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
BCDFIX_REG_QTY = 2  ; (m0, m1)
BCDFIX_REG_SIZ = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFIX_NO_REG ; Let the include define the types.
BCDFIX_REG_SIG = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfix.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be defined.


### Macros

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| MODE_INIT | None | SR->STACK | D=1 | Save current decimal mode on the stack and enable decimal mode (inline). | COMPLETED |
| MODE_DONE | None | STACK->SR | SR=Restored SR | Restore previously saved decimal mode from the stack (inline). | COMPLETED |
| | | | | | |
| VAR | name=label name (optional),<br />qty=quantity of variables,<br />siz=size of each variable in bytes (default=BCDFIX_REG_SIZ) | NA | BSS memory reserved. | Reserve variable memory at any address available. | COMPLETED |
| VAR_ZP | name=label name (optional),<br />qty=quantity of variables,<br />siz=size of each variable in bytes (default=BCDFIX_REG_SIZ) | NA | BSS memory reserved. | Reserve variable memory within zero page. | COMPLETED |
| | | | | | |
| DATA | name=label name (optional),<br />val=BCD value in a string e.g. '9876543210' | NA | DATA memory allocated with value. | Set constant data. | IN DEVELOPMENT |
| | | | | | |
| CLR_FAST  | m0-m7 | A, Z, N, SR | ?A=0, Z=0, N=0 | CLeaR math register | IN TESTING |
| CLR_INLINE  | m0-m7 | A, X, Y, Z, N, SR | ?Z=0,N=0 | CLeaR math register | TODO |
| CLR  | m0-m7 | | A=0, X= or Y=0, Z=0,N=0 | ACLeaR math register. Calls clr_x or clr_y | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| LDM | | | | LoaD Math register | TODO |
| STM | | | | STore Math register | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| CONV_TO_ASCII | | | | Convert to ASCII | TODO |
| CONV_TO_BYTES | | | | Convert to BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*') | TODO |
| CONV_FROM_ASCII | | | | Convert from ASCII | TODO |
| CONV_FROM_BYTES | | | | Convert from BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*') | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| TST | m0-m7 | | NZ | TeST math register against zero | TODO |
| CMP | m0-m7,m0-m7 | | Z=?,N=?,V=? | CoMPare math register | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| INCU | | | | INCrement Unsigned | TODO |
| INCS | | | | INCrement Signed | TODO |
| DECU | | | | DECrement Unsigned | TODO |
| DECS | | | | DECrement Signed | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| ADCU | | | | ADd with Carry Unsigned | TODO |
| ADCS | | | | ADd with Carry Signed | TODO |
| SBCU | | | | SuBtract with Carry (borrow) Unsigned | TODO |
| SBCS | | | | SuBtract with Carry (borrow) Signed | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| MULU | | | | | TODO |
| MULS | | | | | TODO |
| MULU2 | | | | | TODO |
| MULS2 | | | | | TODO |
| DIVU | | | | | TODO |
| DIVS | | | | | TODO |
| DIVMODU | | | | | TODO |
| DIVMODS | | | | | TODO |
| MOD | | | | | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| LSRU | | | | | TODO |
| LSRS | | | | | TODO |
| ASRU | | | | | TODO |
| ASRS | | | | | TODO |
| LSLU | | | | | TODO |
| LSLS | | | | | TODO |
| ASLU | | | | | TODO |
| ASLS | | | | | TODO |
| LSRU2 | | | | | TODO |
| LSRS2 | | | | | TODO |
| ASRU2 | | | | | TODO |
| ASRS2 | | | | | TODO |
| LSLU2 | | | | | TODO |
| LSLS2 | | | | | TODO |
| ASLU2 | | | | | TODO |
| ASLS2 | | | | | TODO |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| ABS | | | | | TODO |
| CEIL | | | | | TODO |
| FLOOR | | | | | TODO |
| MIN | | | | | TODO |
| MAX | | | | | TODO |
| NEG | | | | | TODO |
| RANDOM | | | | | FUTURE CANDIDATE |
| TRUNC  | | | | | TODO |
| ROUND | | | | | TODO |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| GET EXPONENT | | | | | NOT APPLICABLE? |
| POW | | | | | TODO |
| SQR | | | | | TODO |
| SQRT | | | | | FUTURE CANDIDATE |
| CBRT | | | | | FUTURE CANDIDATE |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| LOG | | | | | FUTURE CANDIDATE |
| LOG10 | | | | | FUTURE CANDIDATE |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| HYPOT | | | | | FUTURE CANDIDATE |
| | | | | | |

| Name | Input | Working | Output | Description | Status |
|------|-------|---------|--------|-------------|--------|
| ACOS | | | | | FUTURE CANDIDATE |
| ASIN | | | | | FUTURE CANDIDATE |
| ATAN | | | | | FUTURE CANDIDATE |
| ATAN2 | | | | | FUTURE CANDIDATE |
| COS | | | | | FUTURE CANDIDATE |
| COSH | | | | | FUTURE CANDIDATE |
| SIN | | | | | FUTURE CANDIDATE |
| SINH | | | | | FUTURE CANDIDATE |
| TAN | | | | | FUTURE CANDIDATE |
| TANH | | | | | FUTURE CANDIDATE |
| | | | | | |

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

