; Binary Coded Decimal (BCD) Fixed Point Math Functions.

; Math registers can be unsigned, signed with length of 4 to 8 bytes.

; CONFIGURATION:-
;   BCDFIX_REG_SIZ  - Size of each BCD math register in bytes (2-8; default=3).
;   BCDFIX_REG_NUM  - Number of BCD math registers (2-8; default=2).
;   BCDFIX_NO_REG   - If defined do not automatically create the registers (default=undefined).


; Default
.IFNDEF BCDFIX_REG_SIZ
    .WARNING "BCDFIX_REG_SIZ default = 3"
BCDFIX_REG_SIZ = 3
.ENDIF

.IFNDEF BCDFIX_REG_NUM
    .WARNING "BCDFIX_REG_NUM default = 2"
BCDFIX_REG_NUM = 2
.ENDIF



;
.IFDEF BCDFIX_REG_SIZ
 .IFDEF BCDFIX_REG_NUM
  .IFNDEF BCDFIX_NO_REG
    .IF BCDFIX_REG_SIZ < 2
        .ERROR "BCDFIX_REG_SIZ < 2"
    .ENDIF
    .IF BCDFIX_REG_SIZ > 8
        .ERROR "BCDFIX_REG_SIZ > 8 !"
    .ENDIF
        .PUSHSEG
        .ZEROPAGE
m0:         .RES        BCDFIX_REG_SIZ
m1:         .RES        BCDFIX_REG_SIZ
        .IF BCDFIX_REG_NUM > 2
m2:         .RES        BCDFIX_REG_SIZ
        .ENDIF
        .IF BCDFIX_REG_NUM > 3
m3:         .RES        BCDFIX_REG_SIZ
        .ENDIF
        .IF BCDFIX_REG_NUM > 4
m4:         .RES        BCDFIX_REG_SIZ
        .ENDIF
        .IF BCDFIX_REG_NUM > 5
m5:         .RES        BCDFIX_REG_SIZ
        .ENDIF
        .IF BCDFIX_REG_NUM > 6
m6:         .RES        BCDFIX_REG_SIZ
        .ENDIF
        .IF BCDFIX_REG_NUM > 7
m7:         .RES        BCDFIX_REG_SIZ
        .ENDIF
        .POPSEG
    .ENDIF
  .ENDIF
.ENDIF



.MACRO  BCDFIX_DATA_FIXME b0,b1,b2,b3,b4,b5,b6,b7
.IF .PARAMCOUNT > BCDFIX_REG_SIZ
.ERROR "CONSTANT DATA IS TOO LARGE"
.ENDIF
    .PUSHSEG
    .DATA
;    .BYTE $b0
;    .BYTE $b1
;    .BYTE $b2
;    .BYTE $b3
;    .BYTE $b4
;    .BYTE $b5
;    .BYTE $b6
;    .BYTE $b7
; .BYTE $99
    .POPSEG
.ENDMACRO

;set constant data vars.
;.DATA

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
; Save current decimal mode. Enable decimal mode (inline).
;
; Input:    None
; Working:  SP-=1 (saved SR)
; Output:   D=1
; Statistics:-
;   Code: 2
;   Data: 0
;   RAM: 0
;   ZP: 0
;   Stack: 1
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MODE_INIT
            PHP
            SED
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Restore previously saved decimal mode (inline).
;
; Input:    None
; Working:  SP+=1 (saved SR)
; Output:   SR=Restored SR.
;------------------------------------------------------------------------------
.MACRO      BCDFIX_MODE_DONE
            PLP
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Reserve variable memory any address available.
;
; Input:-
;   name    Label name for this variable allocation (optional).
;   qty     Quantity of size allocations.
;   siz     Size of allocation in bytes (optional; default=1).
; Working:
; Output:
; Statistics:-
;   Code: 2
;   Data: 0
;   RAM: 0
;   ZP: 0
;   Stack: 1
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
.MACRO      BCDFIX_VAR  name,qty,siz
        .PUSHSEG
        .BSS
        .IFNBLANK name
name:
        .ENDIF
        .REPEAT qty
            .IFBLANK siz
                .RES    1
            .ELSE
                .RES    siz
            .ENDIF
        .ENDREPEAT
        .POPSEG
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Reserve variable memory within zero page.
;
; Input:-
;   name    Label name for this variable allocation (optional).
;   qty     Quantity of size allocations.
;   siz     Size of allocation in bytes (optional; default=1).
; Working:
; Output:
; Statistics:-
;   Code: 2
;   Data: 0
;   RAM: 0
;   ZP: 0
;   Stack: 1
;   Cycles: 5 (3+2)
;       Min:
;       Avg:
;       Max:
;------------------------------------------------------------------------------
.MACRO      BCDFIX_VAR_ZP  name,qty,siz
        .PUSHSEG
        .ZEROPAGE
        .IFNBLANK name
name:
        .ENDIF
        .REPEAT qty
            .IFBLANK siz
                .RES    1
            .ELSE
                .RES    siz
            .ENDIF
        .ENDREPEAT
        .POPSEG
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; Set constant data.
; Input:    Constant address label name,
;           Constant data value.
; Output:   ???
;------------------------------------------------------------------------------
.MACRO      BCDFIX_DATA
;FIXME: !!!!!!!!!!!!!
            .BYTE   $12
            .BYTE   $12
            .BYTE   $12
            .BYTE   $12
            .BYTE   $12
            .BYTE   $12
            .BYTE   $12
            .BYTE   $12
.ENDMACRO
;------------------------------------------------------------------------------



;| CLR_FAST  | m0-m7 | A=0, Z=0, N=0 | CLeaR math register | IN TESTING |
;| CLR_INLINE  | m0-m7, X or Y | Z=0,N=0 | CLeaR math register | TODO |
;| CLR  | m0-m7, X or Y | A=0, X or Y=0, Z=0,N=0 | CLeaR math register. Calls clr_x or clr_y | TODO |
;------------------------------------------------------------------------------
; CLeaR math register (fast)
; Input:    M0-M7
; Output:   A=0, Z=0, N=0
;------------------------------------------------------------------------------
.MACRO  BCDFIX_CLR_FAST     mreg
            LDA     #$00
            STA     mreg
            STA     mreg+1
        .IF BCDFIX_REG_SIZ > 2
            STA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZ > 3
            STA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZ > 4
            STA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZ > 5
            STA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZ > 6
            STA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZ > 7
            STA     mreg+7
        .ENDIF
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CLeaR math register (inline)
; Input:    FUTURE
; Output:   FUTURE
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
; CLeaR math register (inline)
; Input:    FUTURE
; Output:   FUTURE
;------------------------------------------------------------------------------
.MACRO      BCDFIX_CLR      mreg,ireg
            .IF ireg = 'X' or 'x'
            LDX     #>>mreg
            JSR     bcdfix_clr_x
            .ELSE IF Y y
            LDY     #>>mreg
            JSR     bcdfix_clr_y
            .ELSE
            .ERROR
            .ENDIF
.ENDMACRO



bcdfix_clr_x:
        .SCOPE
            LDA     #$00
            LDX     #BCDFIX_REG_SIZ-1
            ;FIXME: or Y
loop:       ;STA     mreg,ireg
            DEX
            ;FIXME: or Y
            BNE     loop
    .ENDSCOPE
            RTS




bcdfix_clr_y:
            RTS




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
; Input:    m0-m7 REVIEW
; Output:   NZ REVIEW
;------------------------------------------------------------------------------
.MACRO      BCDFIX_TST_FAST mreg
            LDA     #$00
            ORA     mreg
            ORA     mreg+1
        .IF BCDFIX_REG_SIZ > 2
            ORA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZ > 3
            ORA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZ > 4
            ORA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZ > 5
            ORA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZ > 6
            ORA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZ > 7
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
        .IF BCDFIX_REG_SIZ > 2
            ORA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZ > 3
            ORA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZ > 4
            ORA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZ > 5
            ORA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZ > 6
            ORA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZ > 7
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
            JSR     bcdfix_tst
.ENDMACRO
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
bcdfix_tst:
    .SCOPE
            ;LDX     #mreg
            LDY     #BCDFIX_REG_SIZ-1
loop:       ORA     $00,X
            INX
            DEY
            BPL     loop
            CMP     #$00
    .ENDSCOPE
            RTS
;------------------------------------------------------------------------------



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

        .IF BCDFIX_REG_SIZ > 2
            STA     mreg+2
        .ENDIF
        .IF BCDFIX_REG_SIZ > 3
            STA     mreg+3
        .ENDIF
        .IF BCDFIX_REG_SIZ > 4
            STA     mreg+4
        .ENDIF
        .IF BCDFIX_REG_SIZ > 5
            STA     mreg+5
        .ENDIF
        .IF BCDFIX_REG_SIZ > 6
            STA     mreg+6
        .ENDIF
        .IF BCDFIX_REG_SIZ > 7
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
; DECrement Unsigned
; Input:    FUTURE
; Output:   FUTURE
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

