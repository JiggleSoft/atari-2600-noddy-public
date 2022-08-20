# Binary Coded Decimal (BCD) Math Functions.

## Index

| Filename  | Description |
|-----------|-------------|
| bcdfix.i  | Binary Coded Decimal (BCD) Fixed Point Math Library. |
| bcd-fp.i  | Binary Coded Decimal (BCD) Floating Point Math Library. |


## Binary Coded Decimal (BCD) Fixed Point Math Library.

### Data Types

#### Unsigned

#### Signed


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
| BCDFIX_USBC | | | Unsigned Subtract with Carry (borrow) |
| BCDFIX_SSBC | | | Signed Subtract with Carry (borrow) |
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



## Contact

Justin Lane (atari2600@jigglesoft.co.uk)


## License

Copyright (c) 2022 Justin Lane

Licensed under the MIT license

See the LICENSE file.

