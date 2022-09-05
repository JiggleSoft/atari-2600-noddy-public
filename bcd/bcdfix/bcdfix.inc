;==============================================================================
; Title:        Binary Coded Decimal (BCD) Fixed Point Math Functions.
; Filename:     bcdfix.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2022-09-04 22:04
; Version:      0.0.4
;------------------------------------------------------------------------------
; Copyright (c) 2022 Justin Lane
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.
;------------------------------------------------------------------------------
; Math registers can be unsigned, signed with length of 2 to 8 bytes unsigned, or 3 to 8 bytes signed.
;
; Configuration (to be set before this file is included):-
;   BCDFIX_REG_SIZE - Size of each BCD math register in bytes (2-8); default=3).
;   BCDFIX_REG_QTY  - Quantity of BCD math registers (2-8; default=2).
;   BCDFIX_NO_REG   - If defined do not automatically create the registers (default=undefined).
;   BCDFIX_REG_SIGN - Default sign for non-suffixed sign supported macros and functions (Undefined/0=Unsigned,1=Signed).
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; CONFIGURATION.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Configuration Defaults.
;------------------------------------------------------------------------------
    ; Default register size if not set.
    .IFNDEF BCDFIX_REG_SIZE
        .WARNING "BCDFIX_REG_SIZE default = 3"
        BCDFIX_REG_SIZE = 3
    .ENDIF

    ; Default register quantity if not set.
    .IFNDEF BCDFIX_REG_QTY
        .WARNING "BCDFIX_REG_QTY default = 2"
        BCDFIX_REG_QTY = 2
    .ENDIF

    ; Default register sign if not set.
    .IFNDEF BCDFIX_REG_SIGN
        .WARNING "BCDFIX_REG_SIGN default = 0 (unsigned)"
        BCDFIX_REG_SIGN = 0
    .ENDIF
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Validate Configuration.
;------------------------------------------------------------------------------
    ; Register size.
    .IF BCDFIX_REG_SIZE < 2
        .ERROR "BCDFIX_REG_SIZE < 2"
    .ENDIF
    .IF BCDFIX_REG_SIZE > 8
        .ERROR "BCDFIX_REG_SIZE > 8"
    .ENDIF

    ; Register quantity.
    .IF BCDFIX_REG_QTY < 2
        .ERROR "BCDFIX_REG_QTY < 2"
    .ENDIF
    .IF BCDFIX_REG_QTY > 8
        .ERROR "BCDFIX_REG_QTY > 8"
    .ENDIF

    ; Register sign.
    .IF BCDFIX_REG_SIGN < 0
        .ERROR "BCDFIX_REG_SIGN < 0"
    .ENDIF
    .IF BCDFIX_REG_SIGN > 1
        .ERROR "BCDFIX_REG_SIGN > 1"
    .ENDIF
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; REGISTERS.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Reserve zero page memory for registers.
;------------------------------------------------------------------------------
    .IFDEF BCDFIX_REG_SIZE
      .IFDEF BCDFIX_REG_QTY
        .IFNDEF BCDFIX_NO_REG
          .IF BCDFIX_REG_SIZE < 2
            .ERROR "BCDFIX_REG_SIZE < 2"
          .ENDIF
          .IF BCDFIX_REG_SIZE > 8
            .ERROR "BCDFIX_REG_SIZE > 8 !"
          .ENDIF
          .PUSHSEG
          .ZEROPAGE
m0:
M0:       .RES        BCDFIX_REG_SIZ
m1:
M1:       .RES        BCDFIX_REG_SIZ
          .IF BCDFIX_REG_QTY > 2
m2:
M2:         .RES        BCDFIX_REG_SIZ
          .ENDIF
          .IF BCDFIX_REG_QTY > 3
m3:
M3:         .RES        BCDFIX_REG_SIZ
          .ENDIF
          .IF BCDFIX_REG_QTY > 4
m4:
M4:         .RES        BCDFIX_REG_SIZ
          .ENDIF
          .IF BCDFIX_REG_QTY > 5
m5:
M5:         .RES        BCDFIX_REG_SIZ
          .ENDIF
          .IF BCDFIX_REG_QTY > 6
m6:
M6:         .RES        BCDFIX_REG_SIZ
          .ENDIF
          .IF BCDFIX_REG_QTY > 7
m7:
M7:         .RES        BCDFIX_REG_SIZ
          .ENDIF
          .POPSEG
        .ENDIF
      .ENDIF
    .ENDIF
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; LIBRARY INITIALISATION.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Initialise the library.
;
; Push current arithmetic mode on to the stack.
; Set arithmetic mode to decimal.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_MODE_INIT
            BCDFIX_MODE_PUSH
            BCDFIX_MODE_DEC
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Uninitialise the library.
;
; Pop a previously saved arithmetic mode off of the stack
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MODE_DONE
            BCDFIX_MODE_POP
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ARITHMETIC MODE.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Set arithmetic mode to binary.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_MODE_BIN
        CLD
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Set arithmetic mode to decimal.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_MODE_DEC
        SED
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Push the current decimal mode on to the stack.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_MODE_PUSH
        PHP
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Pop a previously saved arithmetic mode off of the stack.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_MODE_PUSH
        PLP
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; VARIABLE MEMORY RESERVATION.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; VARiable memory reservation at any address available (BSS).
;
; Parameters:-
;   name    Label name (optional),
;   qty     Quantity of variables,
;   size    Size of each variable in bytes (optional; default=BCDFIX_REG_SIZE).
;------------------------------------------------------------------------------
    .MACRO  VAR  name,qty,size
        .PUSHSEG
        .BSS
        .IFNBLANK name
name:
        .ENDIF
        .REPEAT qty
            .IFBLANK size
                .RES    BCDFIX_REG_SIZE
            .ELSE
                .RES    size
            .ENDIF
        .ENDREPEAT
        .POPSEG
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; VARiable memory reservation within zero page (BSS).
;
; Parameters:-
;   name    Label name (optional),
;   qty     Quantity of variables,
;   size    Size of each variable in bytes (optional; default=BCDFIX_REG_SIZE).
;------------------------------------------------------------------------------
    .MACRO  VAR_ZP  name,qty,size
        .PUSHSEG
        .ZEROPAGE
        .IFNBLANK name
name:
        .ENDIF
        .REPEAT qty
            .IFBLANK size
                .RES    BCDFIX_REG_SIZE
            .ELSE
                .RES    size
            .ENDIF
        .ENDREPEAT
        .POPSEG
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DATA CONSTANT DEFINITION.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; DATA Unsigned storage set with a constant value.
;
; Parameters:-
;   name    Label name (optional),
;   val     BCD value as a string e.g. '9876543210' (unsigned).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DATAU    name,val
        .ERROR "TODO: BCDFIX_DATAU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DATA Signed storage set with a constant value.
;
; Parameters:-
;   name    Label name (optional),
;   val     BCD value as a string e.g. '9876543210' or '-76543210' (signed).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DATAS    name,val
        .ERROR "TODO: BCDFIX_DATAS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DATA storage set with a constant value.
;
; Parameters:-
;   name    Label name (optional),
;   val     BCD value as a string e.g. '9876543210' (signed/unsigned)
;           or '-76543210' (signed).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DATA name,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_DATAU    name,val
        .ELSE
            BCDFIX_DATAS    name,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLEAR A MATH REGISTER.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; CLeaR Unsigned math register (fast).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLRU_FAST    mreg
        .ERROR "TODO: BCDFIX_CLRU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR Unsigned math register (inline).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLRU_INLINE  mreg
        .ERROR "TODO: BCDFIX_CLRU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR Unsigned math register (function).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLRU mreg
        .ERROR "TODO: BCDFIX_CLRU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR Signed math register (fast).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLRS_FAST    mreg
        .ERROR "TODO: BCDFIX_CLRS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR Signed math register (inline).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLRS_INLINE  mreg
        .ERROR "TODO: BCDFIX_CLRS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR Signed math register (function).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLRS mreg
        .ERROR "TODO: BCDFIX_CLRS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR math register (fast).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLR_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_CLRU_FAST    mreg
        .ELSE
            BCDFIX_CLRS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR math register (inline).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLR_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_CLRU_INLINE  mreg
        .ELSE
            BCDFIX_CLRS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR math register (function).
;
; Parameters:-
;   mreg    Math register to be cleared.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLR  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_CLRU mreg
        .ELSE
            BCDFIX_CLRS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; LOAD, COPY, OR STORE A MATH REGISTER.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| LDM[U&#124;S]    | mreg = math register (m0 - m7),<br />BCD value as a string e.g. '987654321' FIXME                         | LoaD Math register                                                       | 1.0     | TODO   |
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| CPM[U&#124;S]    | REVIEW                          | CoPy Math register to math register.                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;| STM[U&#124;S]    | REVIEW                          | STore Math register.                                                     | 1.0     | TODO   |
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; COMPARE MATH REGISTER.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; TeST Unsigned math register against zero (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TSTU_FAST    mreg
        .ERROR "BCDFIX_TSTU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Unsigned math register against zero (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TSTU_INLINE  mreg
        .ERROR "BCDFIX_TSTU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Unsigned math register against zero (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TSTU mreg
        .ERROR "BCDFIX_TSTU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Signed math register against zero (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TSTS_FAST    mreg
        .ERROR "BCDFIX_TST_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Signed math register against zero (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TSTS_INLINE  mreg
        .ERROR "BCDFIX_TSTS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Signed math register against zero (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TSTS mreg
        .ERROR "BCDFIX_TSTS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST math register against zero (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TST_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_TSTU_FAST    mreg
        .ELSE
            BCDFIX_TSTS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Signed math register against zero (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TST_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_TSTU_INLINE  mreg
        .ELSE
            BCDFIX_TSTS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST Signed math register against zero (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TST  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_TSTU mreg
        .ELSE
            BCDFIX_TSTS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare Unsigned math register against value (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMPU_FAST    mreg,val
        .ERROR "BCDFIX_CMPU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare Unsigned math register against value  (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMPU_INLINE  mreg,val
        .ERROR "BCDFIX_CMPU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare Unsigned math register against value  (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMPU mreg,val
        .ERROR "BCDFIX_CMPU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare Signed math register against value  (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMPS_FAST    mreg,val
        .ERROR "BCDFIX_CMPS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare Signed math register against value  (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMPS_INLINE  mreg,val
        .ERROR "BCDFIX_CMPS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare Signed math register against value  (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMPS mreg,val
        .ERROR "BCDFIX_CMPS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare math register against value  (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMP_FAST mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_CMPU_FAST    mreg,val
        .ELSE
            BCDFIX_CMPS_FAST    mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare math register against value  (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMP_INLINE   mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_CMPU_INLINE  mreg,oper
        .ELSE
            BCDFIX_CMPS_INLINE  mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare math register against value  (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CMP  mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_CMPU mreg,val
        .ELSE
            BCDFIX_CMPS mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCREMENT OR DECREMENT A MATH REGISTER.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; INCrement Unsigned math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INCU_FAST    mreg
        .ERROR "BCDFIX_INCU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Unsigned math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INCU_INLINE  mreg
        .ERROR "BCDFIX_INCU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Unsigned math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INCU mreg
        .ERROR "BCDFIX_INCU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Signed math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INCS_FAST    mreg
        .ERROR "BCDFIX_INCS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Signed math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INCS_INLINE  mreg
        .ERROR "BCDFIX_INCS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Signed math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INCS mreg
        .ERROR "BCDFIX_INCS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INC_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_INCU_FAST    mreg
        .ELSE
            BCDFIX_INCS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INC_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_INCU_INLINE  mreg
        .ELSE
            BCDFIX_INCS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).

;------------------------------------------------------------------------------
    .MACRO  BCDFIX_INC  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_INCU mreg
        .ELSE
            BCDFIX_INCS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Unsigned math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECU_FAST    mreg
        .ERROR "BCDFIX_DECU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Unsigned math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECU_INLINE  mreg
        .ERROR "BCDFIX_DECU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Unsigned math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECU mreg
        .ERROR "BCDFIX_DECU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Signed math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECS_FAST    mreg
        .ERROR "BCDFIX_DECS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Signed math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECS_INLINE  mreg
        .ERROR "BCDFIX_DECS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Signed math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECS mreg
        .ERROR "BCDFIX_DECS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DEC_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_DECU_FAST    mreg
        .ELSE
            BCDFIX_DECS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DEC_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_DECU_INLINE  mreg
        .ELSE
            BCDFIX_DECS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).

;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DEC  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_DECU mreg
        .ELSE
            BCDFIX_DECS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADDITION OR SUBTRACTION OF A MATH REGISTER.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; ADd with Carry Unsigned math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADCU_FAST    mreg,val
        .ERROR "BCDFIX_ADCU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry Unsigned math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADCU_INLINE  mreg,val
        .ERROR "BCDFIX_ADCU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry Unsigned math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADCU mreg,val
        .ERROR "BCDFIX_ADCU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry Signed math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADCS_FAST    mreg,val
        .ERROR "BCDFIX_ADCS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry Signed math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADCS_INLINE  mreg,val
        .ERROR "BCDFIX_ADCS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry Signed math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADCS mreg,val
        .ERROR "BCDFIX_ADCS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADC_FAST mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ADCU_FAST    mreg,val
        .ELSE
            BCDFIX_ADCS_FAST    mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADC_INLINE   mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ADCU_INLINE  mreg,val
        .ELSE
            BCDFIX_ADCS_INLINE  mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; ADd with Carry math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ADC  mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ADCU mreg,val
        .ELSE
            BCDFIX_ADCS mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry Unsigned math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBCU_FAST    mreg,val
        .ERROR "BCDFIX_SBCU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry Unsigned math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBCU_INLINE  mreg,val
        .ERROR "BCDFIX_SBCU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry Unsigned math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBCU mreg,val
        .ERROR "BCDFIX_SBCU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry Signed math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBCS_FAST    mreg,val
        .ERROR "BCDFIX_SBCS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry Signed math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBCS_INLINE  mreg,val
        .ERROR "BCDFIX_SBCS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry Signed math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBCS mreg,val
        .ERROR "BCDFIX_SBCS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry math register (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBC_FAST mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_SBCU_FAST    mreg,val
        .ELSE
            BCDFIX_SBCS_FAST    mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry math register (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBC_INLINE   mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_SBCU_INLINE  mreg,val
        .ELSE
            BCDFIX_SBCS_INLINE  mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SuBtract with Carry math register (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;   val     Math register (m0 - m7), BCD string, or address.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SBC  mreg,val
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_SBCU mreg,val
        .ELSE
            BCDFIX_SBCS mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SHIFT MATH REGISTER: MULTIPLICATION AND DIVISION BY 10.
;------------------------------------------------------------------------------





;------------------------------------------------------------------------------
; Arithmetic Shift Left Unsigned (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASLU_FAST    mreg
        .ERROR "BCDFIX_ASLU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Unsigned (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASLU_INLINE  mreg
        .ERROR "BCDFIX_ASLU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Unsigned (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASLU mreg
        .ERROR "BCDFIX_ASLU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Signed (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASLS_FAST    mreg
        .ERROR "BCDFIX_ASLS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Signed (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASLS_INLINE  mreg
        .ERROR "BCDFIX_ASLS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Signed (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASLS mreg
        .ERROR "BCDFIX_ASLS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASLU_FAST    mreg
        .ELSE
            BCDFIX_ASLS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASLU_INLINE  mreg
        .ELSE
            BCDFIX_ASLS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASLU mreg
        .ELSE
            BCDFIX_ASLS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Unsigned (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASRU_FAST    mreg
        .ERROR "BCDFIX_ASRU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Unsigned (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASRU_INLINE  mreg
        .ERROR "BCDFIX_ASRU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Unsigned (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASRU mreg
        .ERROR "BCDFIX_ASRU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Signed (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASRS_FAST    mreg
        .ERROR "BCDFIX_ASRS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Signed (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASRS_INLINE  mreg
        .ERROR "BCDFIX_ASRS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Signed (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASRS mreg
        .ERROR "BCDFIX_ASRS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASRU_FAST    mreg
        .ELSE
            BCDFIX_ASRS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASRU_INLINE  mreg
        .ELSE
            BCDFIX_ASRS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASRU mreg
        .ELSE
            BCDFIX_ASRS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSLU_FAST    mreg
        .ERROR "BCDFIX_LSLU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSLU_INLINE  mreg
        .ERROR "BCDFIX_LSLU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSLU mreg
        .ERROR "BCDFIX_LSLU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSLS_FAST    mreg
        .ERROR "BCDFIX_LSLS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSLS_INLINE  mreg
        .ERROR "BCDFIX_LSLS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSLS mreg
        .ERROR "BCDFIX_LSLS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSLU_FAST    mreg
        .ELSE
            BCDFIX_LSLS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSLU_INLINE  mreg
        .ELSE
            BCDFIX_LSLS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSLU mreg
        .ELSE
            BCDFIX_LSLS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSRU_FAST    mreg
        .ERROR "BCDFIX_LSRU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSRU_INLINE  mreg
        .ERROR "BCDFIX_LSRU_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSRU mreg
        .ERROR "BCDFIX_LSRU IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSRS_FAST    mreg
        .ERROR "BCDFIX_LSRS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSRS_INLINE  mreg
        .ERROR "BCDFIX_LSRS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSRS mreg
        .ERROR "BCDFIX_LSRS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right (fast).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSRU_FAST    mreg
        .ELSE
            BCDFIX_LSRS_FAST    mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right (inline).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR_INLINE   mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSRU_INLINE  mreg
        .ELSE
            BCDFIX_LSRS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right (function).
;
; Parameters:-
;   mreg    Math register (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR  mreg
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSRU mreg
        .ELSE
            BCDFIX_LSRS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Unsigned high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2U_FAST   mregh,mregl
        .ERROR "BCDFIX_ASL2U_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Unsigned high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2U_INLINE mregh,mregl
        .ERROR "BCDFIX_ASL2U_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Unsigned high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2U    mregh,mregl
        .ERROR "BCDFIX_ASL2U IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Signed high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2S_FAST   mregh,mregl
        .ERROR "BCDFIX_ASL2S_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Signed high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2S_INLINE mregh,mregl
        .ERROR "BCDFIX_ASL2S_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left Signed high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2S    mregh,mregl
        .ERROR "BCDFIX_ASL2S IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2_FAST    mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASL2U_FAST   mreg,mregl
        .ELSE
            BCDFIX_ASL2S_FAST   mreg,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2_INLINE  mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASL2U_INLINE mreg,mregl
        .ELSE
            BCDFIX_ASL2S_INLINE mreg,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Left high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASL2 mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASL2U    mreg,mregl
        .ELSE
            BCDFIX_ASL2S    mreg,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Unsigned high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2U_FAST   mregh,mregl
        .ERROR "BCDFIX_ASRU_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Unsigned high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2U_INLINE mregh,mregl
        .ERROR "BCDFIX_ASR2U_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Unsigned high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2U    mregh,mregl
        .ERROR "BCDFIX_ASR2U IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Signed high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2S_FAST   mregh,mregl
        .ERROR "BCDFIX_ASR2S_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Signed high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2S_INLINE mregh,mregl
        .ERROR "BCDFIX_ASR2S_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right Signed high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2S mregh,mregl
        .ERROR "BCDFIX_ASR2S IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2_FAST    mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASR2U_FAST   mreg,mregl
        .ELSE
            BCDFIX_ASR2S_FAST   mreg,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2_INLINE  mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASR2U_INLINE mreg,mregl
        .ELSE
            BCDFIX_ASR2S_INLINE mreg,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Arithmetic Shift Right high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ASR2 mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_ASR2U    mreg,mregl
        .ELSE
            BCDFIX_ASR2S    mreg,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------







zzzzzzz







;------------------------------------------------------------------------------
; Logical Shift Left Unsigned high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_FAST    mreg
        .ERROR "BCDFIX_SSSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_INLINE  mreg
        .ERROR "BCDFIX_SSSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS mregh,mregl
        .ERROR "BCDFIX_SSSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_FAST    mreg
        .ERROR "BCDFIX_SSSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_INLINE  mreg
        .ERROR "BCDFIX_SSSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS mregh,mregl
        .ERROR "BCDFIX_SSSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_FAST    mreg
        .ERROR "BCDFIX_SSSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_INLINE  mreg
        .ERROR "BCDFIX_SSSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS mregh,mregl
        .ERROR "BCDFIX_SSSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------





;------------------------------------------------------------------------------
; Logical Shift Right Unsigned high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_FAST    mreg
        .ERROR "BCDFIX_SSSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_INLINE  mreg
        .ERROR "BCDFIX_SSSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS mregh,mregl
        .ERROR "BCDFIX_SSSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_FAST    mreg
        .ERROR "BCDFIX_SSSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_INLINE  mreg
        .ERROR "BCDFIX_SSSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS mregh,mregl
        .ERROR "BCDFIX_SSSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_FAST    mreg
        .ERROR "BCDFIX_SSSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS_INLINE  mreg
        .ERROR "BCDFIX_SSSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SSSS mregh,mregl
        .ERROR "BCDFIX_SSSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------











zzzzzzzzzzzzzzzzzzzzzzzzzzzzz











;------------------------------------------------------------------------------
; ABS, CEIL, FLOOR, MIN, MAX, NEG, TRUNC, ROUND
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONVERSION TO BYTES / ASCII.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SHIFT MATH REGISTERS (MULTIPLY AND DIVIDE BY 10)
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; MULTIPLICATION, DIVISION, OR MODULO OF MATH REGISTERS
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONSTANTS
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; POW, SQR, CUB, EXP
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; PSEUDO RANDOM NUMBER GENERATION
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONVERSION FROM BYTES / ASCII.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_XXX mreg_in,mreg_out
        .ERROR "BCDFIX_XXX IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; SQUARE ROOT
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CUBE ROOT
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;  LOGARITHMS
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;  ANGLE CONVERSION
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;  SINE, COSINE, AND TANGENT
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SIN mreg_in,mreg_out
        .ERROR "BCDFIX_SIN IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_COS mreg_in,mreg_out
        .ERROR "BCDFIX_COS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TAN mreg_in,mreg_out
        .ERROR "BCDFIX_TAN IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;  SINE, ARCCOSINE. AND ARCTANGENT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
;  COTANGENT, SECANT, AND COSECANT
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_COT mreg_in,mreg_out
        .ERROR "BCDFIX_COT IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_SEC mreg_in,mreg_out
        .ERROR "BCDFIX_SEC IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CSC mreg_in,mreg_out
        .ERROR "BCDFIX_CSC IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;  ARCCOTANGENT, ARCSECANT, AND ARC COSECANT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
; HYPERBOLIC SINE, HYPERBOLIC COSINE, AND HYPERBOLIC TANGENT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
; AREA HYPERBOLIC SINE, AREA HYPERBOLIC COSINE, AND AREA HYPERBOLIC TANGENT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
; HYPERBOLIC COSECANT, HYPERBOLIC SECANT, AND HYPERBOLIC COTANGENT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
; AREA HYPERBOLIC COSECANT, AREA HYPERBOLIC SECANT, AND AREA HYPERBOLIC COTANGENT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
; ATAN2
;------------------------------------------------------------------------------

; TODO










;load constant

;load from mem
;load from reg


; Add to a math register a value or contents of another register.
.MACRO  BCDFIX_UADD  aaa,bbb,ccc,sssiz
            CLC
 cnt .SET 0
            .REPEAT  sssiz
            LDA     aaa+sssiz-cnt
            ADC     bbb+sssiz-cnt
            STA     ccc+sssiz-cnt
            .ENDREPEAT
            .ENDMACRO



;; Subtract from a math register a value or contents of another register.
;BCDFIX_SUB  MACRO
;            SEC
;            REPEAT  siz
;            LDA     \1+siz-cnt
;            SBC     \2+siz-cnt
;            STA     \3+siz-cnt
;            ENDREPEAT
;            ENDM





;TEMPLATE
; Input:
; Working:
; Output:
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:













;------------------------------------------------------------------------------
; LoaD Math register
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LDM
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; STore Math register
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_STM
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONVert TO ASCII
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CONV_TO_ASCII
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONVert TO BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CONV_TO_BYTES
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONVert FROM ASCII
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO  BCDFIX_CONV_FROM_ASCII
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONVert FROM BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CONV_FROM_BYTES
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST math register against zero
; Input:    reg = math register (m0 - m7) REVIEW
; Output:   NZ REVIEW
;------------------------------------------------------------------------------
.MACRO      BCDFIX_TST_FAST mreg
            LDA     #$00
            ORA     mreg
            ORA     mreg+1
        .IF BCDFIX_REG_SIZE > 2
            ORA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZE > 3
            ORA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZE > 4
            ORA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZE > 5
            ORA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZE > 6
            ORA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZE > 7
            ORA     mreg+7
        .ENDIF
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST math register against zero
; Input:    m0-m7 REVIEW
; Output:   NZ REVIEW
;------------------------------------------------------------------------------
.MACRO  BCDFIX_TST_INLINE      mreg
            LDA     #$00
            LDX     #$00    ; or Y
            ORA     (mreg),x
            DEY
            ORA     mreg+1
        .IF BCDFIX_REG_SIZE > 2
            ORA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZE > 3
            ORA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZE > 4
            ORA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZE > 5
            ORA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZE > 6
            ORA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZE > 7
            ORA     mreg+7
        .ENDIF
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; TeST math register against zero
; Input:    m0-m7 REVIEW
; Output:   NZ REVIEW
;------------------------------------------------------------------------------
.MACRO  BCDFIX_TST      mreg
            LDX     #mreg
            ;JSR     bcdfix_tst
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;bcdfix_tst:
;    .SCOPE
;            ;LDX     #mreg
;            LDY     #BCDFIX_REG_SIZ-1
;loop:       ORA     $00,X
;            INX
;            DEY
;            BPL     loop
;            CMP     #$00
;    .ENDSCOPE
;            RTS
;;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CoMPare math register
; Input:    m0-m7,m0-m7 REVIEW
; Output:   Z=?,N=?,V=? REVIEW
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CMP
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Unsigned (unrolled, inline)
; Input:    m0-m7
; Output:   m0-m7
;------------------------------------------------------------------------------
.MACRO      BCDFIX_INCU_FAST
            CLC ; REVIEW: should this be inc with carry? if so remove CLC.
            LDA     m0+0
            ADC     #$01
            STA     m1+0
            LDA     m0+1
            ADC     $00
            STA     m1+1
            LDA     m0+1
            ADC     $00
            STA     m1+1
            LDA     m0+1
            ADC     $00
            STA     m1+1
            LDA     m0+1
            ADC     $00
            STA     m1+1

        .IF BCDFIX_REG_SIZE > 2
            STA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZE > 3
            STA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZE > 4
            STA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZE > 5
            STA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZE > 6
            STA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZE > 7
            STA     mreg+7
        .ENDIF
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Unsigned
; Input:    m0-m7
; Output:   m0-m7
;------------------------------------------------------------------------------
.MACRO      BCDFIX_INCU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; INCrement Signed
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_INCS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Unsigned (unrolled; inline)
;
; Input:    mreg = Math register to decrement.
; Working:
; Output:
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DECU_FAST    mreg
        CLC
        .REPEAT BCDFIX_REG_SIZ,counter
            LDA     mreg+BCDFIX_REG_SIZ-counter-1
            SBC     #$00
            STA     mreg+BCDFIX_REG_SIZ-counter-1
        .ENDREPEAT
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DECrement Unsigned
; Input:    FUTURE
; Output:   FUTURE
;TEMPLATE
; Input:
; Working:
; Output:
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DECU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; DECrement Signed
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DECS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; ADd with Carry Unsigned
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ADCU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; ADd with Carry Signed
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ADCS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; SuBtract with Carry (borrow) Unsigned
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_SBCU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; SuBtract with Carry (borrow) Signed
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_SBCS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MULU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MULS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MULU2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MULS2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DIVU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DIVS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DIVMODU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DIVMODS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MOD
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSRU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSRS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASRU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASRS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSLU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSLS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASLU
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASLS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSRU2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSRS2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASRU2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASRS2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSLU2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LSLS2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASLU2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASLS2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ABS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CEIL
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; FLOOR
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_FLOOR
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; MINimum
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MIN
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; MAXimum
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MAX
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; NEGate
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_NEG
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; RANDOM number generator. ALSO ADD SEED AND SET SEED?
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_RANDOM
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; TRUNCate
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_TRUNC
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; ROUND
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ROUND
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; REVIEW
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_GET_EXPONENT
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Raise to the POWer
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_POW
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; SQuaRe
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_SQR
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; SQuare RooT
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_SQRT
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; CuBe RooT
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CBRT
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LOG
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_LOG10
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_HYPOT
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ACOS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ASIN
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ATAN
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_ATAN2
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Cosine (cos)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_COS
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Hyperbolic Cosine (cosh)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_COSH
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Sine (sin)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_SIN
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Hyperbolic Sine (sinh)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_SINH
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Tangent (tan)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_TAN
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Hyperbolic Tangent (tanh)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_TANH
            .ERROR  "FUTURE: NOT IMPLEMENTED!"
.ENDMACRO
;------------------------------------------------------------------------------











;------------------------------------------------------------------------------
; DATA storage set wih Unsigned constant value.
; Input:-
;   name    Label name for this constant data (optional).
;   val     BCD value as a string e.g. '9876543210'.
; Working:  NA
; Output:   Read-only data storage set with constant value.
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: ? (?+?)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DATAU    name,val
  .WARNING "BCDFIX_DATAU: NOT YET FULLY IMPLEMENTED!
        .PUSHSEG
        .DATA
        .IFNBLANK name
name:
        .ENDIF
        .IF .BLANK(val)
            .ERROR "BCDFIX_DATU val is empty!"
        .ELSEIF .STRLEN(val) > BCDFIX_REG_SIZ
            .ERROR "BCDFIX_DATU val is too long!"
        .ELSE

        ;XXXX = .STRAT(val, 1)
        ;.WARNING .STRING(XXXX)
        ;.WARNING "33333"
        ;.WARNING .STRING(.STRAT(val, 0)) .STRAT(val, 1)
        ;.BYTE   ZZZZ
        ;.BYTE XXXX
        ;.WARNING .CONCAT(.STRING(.STRAT(val, 0)), .STRING(.STRAT(val, 1)))
        ;.BYTE .CONCAT(.STRING(.STRAT(val, 0)), .STRING(.STRAT(val, 1)))
        ;.WARNING .CONCAT(.STRING(.STRAT(val, 2)), .STRING(.STRAT(val, 3)))
        ;.WARNING .CONCAT(.STRING(.STRAT(val, 4)), .STRING(.STRAT(val, 5)))
        ;.WARNING "--------------"
        ;ZZZZZZ = .CONCAT(.STRING(ZZZZ), .STRING(XXXX))
        ;;.BYTE ZZZZZZ
        ;.WARNING "--------------"
        ;.WARNING .CONCAT(.STRING(.STRAT(val, 0)), .STRING(.STRAT(val, 1)))
        ;.WARNING "--------------"  + .STRAT(val, 1)
.BYTE $88
        .BYTE ((.STRAT(val, 0)-48)*16)+(.STRAT(val, 1)-48)
        .BYTE ((.STRAT(val, 2)-48)*16)+(.STRAT(val, 3)-48)
        .BYTE ((.STRAT(val, 4)-48)*16)+(.STRAT(val, 5)-48)
.BYTE $FF
        ;;;.BYTE .CONCAT(ZZZZ,XXXX)
        ;.BYTE   .STRAT(val, 2).STRAT(val, 3)
        ;.POPCHARMAP
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; DATA storage set wih Signed constant value.
; Input:-
;   name    Label name for this constant data (optional).
;   val     BCD value as a string e.g. '-76543210'.
; Working:  NA
; Output:   Read-only data storage set with constant value.
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: ? (?+?)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_DATAS    name,val
        .ERROR "TODO: BCDFIX_DATAS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------












;------------------------------------------------------------------------------
; CLeaR math register (fast).
;
; Input:    mreg = math register (m0 - m7)
; Output:   A=$00, SR=?
;
; Statistics:-
;   Code:   BCDFIX_REG_SIZE * 2 + 2 (2*2+2=6, 3*2+2=8, 4*2+2=10, 5*2+2=12,
;                                   6*2+2=14, 7*2+2=16, 8*2+2=18)
;   Cycles: BCDFIX_REG_SIZE * 3 + 2 (2*3+2=8, 3*3+2=11, 4*3+2=14, 5*3+2=17,
;                                   6*3+2=20, 7*3+2=23, 8*3+2=26)
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLR_FAST mreg
            LDA     #$00
        .REPEAT BCDFIX_REG_SIZ,index
            STA     mreg+index
        .ENDREPEAT
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR math register (inline).
;
; Input:    mreg = math register (m0 - m7)
; Output:   A=$00, X=$FF, SR=?
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CLR_FAST mreg
        .LOCAL  loop
            LDA     #$00
            LDX     #BCDFIX_REG_SIZ-1
loop:
            STA     mreg,X
            DEX
            BPL     loop
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR math register (inline).
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------


| CLR_INLINE      | mreg = math register (m0 - m7) | REVIEW: A, X, Y, Z, N, SR, ?Z=0,N=0 |  | 1.0 | TODO |
; CLeaR math register (inline)
; Input:    FUTURE
; Output:   FUTURE
; Input:
; Working:
; Output:
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:

;------------------------------------------------------------------------------
.MACRO  BCDFIX_CLR_INLINE   mreg,ireg
        .LOCAL      loop
            LDA     #$00
            LDX     #BCDFIX_REG_SIZ-1
            ;FIXME: or Y
loop:       STA     mreg,ireg
            DEX
            ;FIXME: or Y
            BNE     loop
.ENDMACRO



;------------------------------------------------------------------------------
| CLR             | mreg = math register (m0 - m7) | REVIEW: A=0, X= or Y=0, Z=0,N=0, CLeaR math register. Calls clr_x or clr_y | CLeaR math register (func).  | 1.0 | TODO |

; CLeaR math register (inline)
; Input:    FUTURE
; Output:   FUTURE
; Input:
; Working:
; Output:
; Statistics:-
;   Code:
;   Data:
;   RAM:
;   ZP:
;   Stack:
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CLR      mreg,ireg
            .IF ireg = 'X' or 'x'
            LDX     #>>mreg
  ;          JSR     bcdfix_clr_x
            .ELSE IF Y y
            LDY     #>>mreg
 ;           JSR     bcdfix_clr_y
            .ELSE
            .ERROR
            .ENDIF
.ENDMACRO



;    .PUSHSEG
;    .CODE
;
;bcdfix_clr_x:
;        .SCOPE
;            LDA     #$00
;            LDX     #BCDFIX_REG_SIZ-1
;            ;FIXME: or Y
;loop:       ;STA     mreg,ireg
;            DEX
;            ;FIXME: or Y
;            BNE     loop
;    .ENDSCOPE
;            RTS
;
;
;
;
;bcdfix_clr_y:
;            RTS
;
;
;    .POPSEG




