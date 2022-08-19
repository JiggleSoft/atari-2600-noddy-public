; Binary Coded Decimal (BCD) Fixed Point Math Functions.

; Math registers can be unsigned, signed with length of 4 to 8 bytes.



BCDFIX_REGISTERS    MACRO
m0
m1
m2
m3
            ENDM


; Load a math register with value or contents of another register.
SBCDFIX_LDM  MACRO   ; reg,value|reg


            ENDM


; Add to a math register a value or contents of another register.
BCDFIX_ADD  MACRO
            ENDM


; Subtract from a math register a value or contents of another register.
BCDFIX_SUB  MACRO
            ENDM


;
BCDFIX_MUL  MACRO
            ENDM


;
BCDFIX_DIV  MACRO
                      ENDM



;
BCDFIX_MOD  MACRO
                      ENDM



;
BCDFIX_DIVMOD  MACRO
                         ENDM



;
BCDFIX_TOINT  MACRO
                        ENDM



;
BCDFIX_FROMINT  MACRO
                          ENDM









BCD_FIX_REGISTER    MACRO   ; name,size
bcd_reg_\1            DS.B
            ENDM


BCD_MODE_ON MACRO
    SED
    ENDM


BCD_MODE_OFF MACRO
    CLD
    ENDM


BCD_ADD     MACRO   ; a+b->c,l

    ENDM



bcd_add:
    php
    clc
    sed
    lda (
    adc
    rts
