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



.MACRO  BCDFIX_DATA b0,b1,b2,b3,b4,b5,b6,b7
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