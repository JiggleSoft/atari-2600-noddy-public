ht//mega65.org/


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
; LIMITS.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; FIXME MIN,MAX, SIGNED / UNSIGNED .
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_MAX
    .ENDMACRO



;------------------------------------------------------------------------------
; ABSOLUTE AND NEGATION.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ABS_FAST mreg
        .ERROR "BCDFIX_ABSS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ABS_INLINE   mreg
        .ERROR "BCDFIX_ABSS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ABSS  mreg
        .ERROR "BCDFIX_ABSS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ABS_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            .WARNING "BCDFIX_ABSU_FAST does not exist as already positive."
        .ELSE
            BCDFIX_ABSS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ABS_INLINE mreg
        .IF BCDFIX_REG_SIGN = 0
            .WARNING "BCDFIX_ABSU_INLINE does not exist as already positive."
        .ELSE
            BCDFIX_ABSS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_ABS  mreg
        .IF BCDFIX_REG_SIGN = 0
            .WARNING "BCDFIX_ABSU does not exist as already positive."
        .ELSE
            BCDFIX_ABSS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_NEG_FAST mreg
        .ERROR "BCDFIX_NEGS_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_NEG_INLINE   mreg
        .ERROR "BCDFIX_NEGS_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_NEGS  mreg
        .ERROR "BCDFIX_NEGS IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_NEG_FAST mreg
        .IF BCDFIX_REG_SIGN = 0
            .WARNING "BCDFIX_NEGU_FAST does not exist as already positive."
        .ELSE
            BCDFIX_NEGS mreg,val
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_NEG_INLINE mreg
        .IF BCDFIX_REG_SIGN = 0
            .WARNING "BCDFIX_NEGU_INLINE does not exist as already positive."
        .ELSE
            BCDFIX_NEGS_INLINE  mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_NEG  mreg
        .IF BCDFIX_REG_SIGN = 0
            .WARNING "BCDFIX_NEGU does not exist as already positive."
        .ELSE
            BCDFIX_NEGS mreg
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; MIN, MAX.
;------------------------------------------------------------------------------






;------------------------------------------------------------------------------
; CEIL, FLOOR,  TRUNC, ROUND
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
            BCDFIX_ASL2U_FAST   mregh,mregl
        .ELSE
            BCDFIX_ASL2S_FAST   mregh,mregl
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
            BCDFIX_ASL2U_INLINE mregh,mregl
        .ELSE
            BCDFIX_ASL2S_INLINE mregh,mregl
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
            BCDFIX_ASL2U    mregh,mregl
        .ELSE
            BCDFIX_ASL2S    mregh,mregl
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
        .ERROR "BCDFIX_ASR2U_FAST IS NOT YET IMPLEMENTED!"
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
            BCDFIX_ASR2U_FAST   mregh,mregl
        .ELSE
            BCDFIX_ASR2S_FAST   mregh,mregl
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
            BCDFIX_ASR2U_INLINE mregh,mregl
        .ELSE
            BCDFIX_ASR2S_INLINE mregh,mregl
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
            BCDFIX_ASR2U    mregh,mregl
        .ELSE
            BCDFIX_ASR2S    mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2U_FAST   mregh,mregl
        .ERROR "BCDFIX_LSL2U_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2U_INLINE mregh,mregl
        .ERROR "BCDFIX_LSL2U_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Unsigned high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2U    mregh,mregl
        .ERROR "BCDFIX_LSL2U IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2S_FAST   mregh,mregl
        .ERROR "BCDFIX_LSL2S_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2S_INLINE mregh,mregl
        .ERROR "BCDFIX_LSL2S_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left Signed high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2S    mregh,mregl
        .ERROR "BCDFIX_LSL2S IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2_FAST    mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSL2U_FAST   mregh,mregl
        .ELSE
            BCDFIX_LSL2S_FAST   mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2_INLINE  mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSL2U_INLINE mregh,mregl
        .ELSE
            BCDFIX_LSL2S_INLINE mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Left high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSL2 mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSL2U    mregh,mregl
        .ELSE
            BCDFIX_LSL2S    mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2U_FAST   mregh,mregl
        .ERROR "BCDFIX_LSR2U_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2U_INLINE mregh,mregl
        .ERROR "BCDFIX_LSR2U_INLINE IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Unsigned high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2U    mregh,mregl
        .ERROR "BCDFIX_LSR2U IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2S_FAST   mregh,mregl
        .ERROR "BCDFIX_LSR2S_FAST IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right Signed high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2S_INLINE mregh,mregl
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
    .MACRO  BCDFIX_LSR2S    mregh,mregl
        .ERROR "BCDFIX_LSR2S IS NOT YET IMPLEMENTED!"
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right high and low (fast).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2_FAST    mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSR2U_FAST   mregh,mregl
        .ELSE
            BCDFIX_LSR2S_FAST   mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right high and low (inline).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2_INLINE  mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSR2U_INLINE mregh,mregl
        .ELSE
            BCDFIX_LSR2S_INLINE mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Logical Shift Right high and low (function).
;
; Parameters:-
;   mregh   Math register high (m0 - m7).
;   mregl   Math register low (m0 - m7).
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_LSR2 mregh,mregl
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_LSR2U    mregh,mregl
        .ELSE
            BCDFIX_LSR2S    mregh,mregl
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONSTANTS
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; PI.      REVIEW: DATA, CONSTANTS, DEFINES.
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_CONST_PI
        .PUSHSEG
        .DATA
        .BYTES  '3141592654'
        .POPBYTE
    .ENDMACRO
;------------------------------------------------------------------------------






;------------------------------------------------------------------------------
; CONVERSION TO BYTES / ASCII.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Convert math register value to array of bytes.
; FIXME: CONVert TO BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TOBYTU   mreg,fixme

    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Convert math register value to array of bytes.
; FIXME: CONVert TO BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TOBYTS   mreg,fixme

    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Convert math register value to array of bytes.
; FIXME: CONVert TO BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TOBYT   mreg,fixme
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_TOBYTU   mreg,fixme
        .ELSE
            BCDFIX_TOBYTS   mreg,fixme
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Convert math register value to ASCII string of bytes.
;
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TOASCU   mreg,fixme

    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Convert math register value to ASCII string of bytes.
; FIXME: CONVert TO BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TOASCS   mreg,fixme

    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Convert math register value to ASCII string of bytes.
; FIXME: CONVert TO BYTE String (0-9='0'..'9', A='.' B='-' C='+'  D='£' E='$' F='*')
;------------------------------------------------------------------------------
    .MACRO  BCDFIX_TOASC    mreg,fixme
        .IF BCDFIX_REG_SIGN = 0
            BCDFIX_TOASCU   mreg,fixme
        .ELSE
            BCDFIX_TOASCS   mreg,fixme
        .ENDIF
    .ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; PSEUDO RANDOM NUMBER GENERATION
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;FIXME: set seed
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;FIXME: get random number
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; MULTIPLICATION, DIVISION, OR MODULO OF MATH REGISTERS
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;FIXME
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; POW, SQR, CUB, EXP
;------------------------------------------------------------------------------





;------------------------------------------------------------------------------
; CONVERSION FROM BYTES / ASCII.
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
;  SINE, ARCCOSINE. AND ARCTANGENT
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
;  COTANGENT, SECANT, AND COSECANT
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
