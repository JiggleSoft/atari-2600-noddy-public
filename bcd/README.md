# Binary Coded Decimal (BCD) Math Functions.

## Index

| Filename  | Description |
|-----------|-------------|
| bcdfix.i  | Binary Coded Decimal (BCD) Fixed Point Math Library. |
| bcdfp.i   | Binary Coded Decimal (BCD) Floating Point Math Library. |


## Binary Coded Decimal (BCD) Fixed Point Math Library.

### Data Types

#### Unsigned

```
Endian = Little Endian

Length is pre-configured between 2 to 8 bytes.

Example with configured length of 5 bytes.

              Lower Memory <----------------> Higher Memory
Byte              0        1        2        3        4
Nybble Order    1   0    3   2    5   4    7   6    9   8
BCD Hex Value   1   0    3   2    5   4    7   6    9   8

Decimal Value   9876543210
```


#### Signed

```
Endian = Little Endian

Length is pre-configured between 2 to 8 bytes.

One byte is reserved for the sign:-
    $FF = -1 = Negative
    $00 =  0 = Zero
    $01 =  1 = Positive

Example with configured length of 5 bytes.

              Lower Memory <----------------> Higher Memory
Byte              0        1        2        3        4
Nybble Order    1   0    3   2    5   4    7   6    S1  S
BCD Hex Value   1   0    3   2    5   4    7   6    F   F

Decimal Value   -76543210
```


### Example 

; Configure 2 registers (m0 and m1), with byte size of 4, unsigned (8 BCD digits).

```
BCDFIX_REG_NUM = 2  ; (m0, m1)
BCDFIX_REG_SIZ = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFIX_NO_REG ; Let the include define the types.
BCDFIX_REG_SIG = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfix.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be created.


### Macros

| Name | Input | Output | Description | Status |
|------|-------|--------|-------------|--------|
| BCDFIX_LDMN | | | Decimal mode on off save restore...|
| ||||
| BCDFIX_LDMN | | | |
| ||||
| BCDFIX_LDMN | | | |
| ||||
| BCDFIX_UADC | | | Unsigned ADd with Carry | Completed |
| BCDFIX_SADC | | | Signed ADd with Carry |
| BCDFIX_USBC | | | Unsigned SuBtract with Carry (borrow) |
| BCDFIX_SSBC | | | Signed SuBtract with Carry (borrow) |
| BCDFIX_UMUL | | | Unsigned MULtiply |
| BCDFIX_SMUL | | | Signed MULtiply |
| BCDFIX_UMUL | | | |
| BCDFIX_SMUL | | | |
| BCDFIX_UMUL | | | |
| BCDFIX_SMUL | | | |
| BCDFIX_UDIV | | | Unsigned DIVision |
| BCDFIX_SDIV | | | Signed DIVision |
| BCDFIX_UMOD | | | |
| BCDFIX_SMOD | | | |
| BCDFIX_UDIV | | | |
| BCDFIX_SDIV | | | |



### Functions










## Binary Coded Decimal (BCD) Floating Point Math Library.

### Data Types

```
Endian = Little Endian

Length is pre-configured between 4 to 8 bytes.

Example with configured length of 5 bytes.

FIXME !!!!!!!!!!!!!!!!!!!!!!1

              Lower Memory <----------------> Higher Memory
Byte              0        1        2        3        4
Nybble Order    1   0    3   2    5   4    7   6    9   8
BCD Hex Value   1   0    3   2    5   4    7   6    9   8

Decimal Value   9876543210
```


### Example

FIXME

; Configure 2 registers (m0 and m1), with byte size of 4, unsigned (8 BCD digits).

```
BCDFIX_REG_NUM = 2  ; (m0, m1)
BCDFIX_REG_SIZ = 4  ; (4 bytes each m(n) register).
;.DEFINE BCDFIX_NO_REG ; Let the includeinclude define the types.
BCDFIX_REG_SIG = 0 ; 0 = Unsigned, 1 = Signed.

.INCLUDE    "bcd/bcdfp.inc"
```

Registers m0 and m1 (actually ZEROPAGE memory) will be created.


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

