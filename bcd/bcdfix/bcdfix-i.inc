;==============================================================================
; Title:        Binary Coded Decimal (BCD) Fixed Point Math Functions.
; Sub-Title:    FIXME.
; Filename:     bcdfix-i.inc
; Platform:     65XX CPU
; Language:     65XX Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (cpu65xx@jigglesoft.co.uk)
; Date:         2022-09-07 21:00
; Version:      0.0.6
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
 .DEFINE  BCDFIX_INC_CFG "config-file-to-include.inc"

.IFNDEF BCDFIX_INC_CFG
.DEFINE  BCDFIX_INC_CFG "config-file-to-include-default.inc"
.ENDIF

        .IFNDEF  BCDFIX_NO_INC_CFG
        .IFBLANK BCDFIX_INC_CFG
        .INCLUDE    "bcdfix-cfg.inc"
        .ELSE
        .INCLUDE    BCDFIX_INC_CFG
        .ENDIF
        .ENDIF

 .END
            .INCLUDE    "bcdfix-i-core.inc"

            ; Value.
            .INCLUDE    "bcdfix-i-val.inc"
            ; Variable.
            .INCLUDE    "bcdfix-i-var.inc"
            ; Limits.
            .INCLUDE    "bcdfix-i-limit.inc"
            ; Constants.
            .INCLUDE    "bcdfix-i-const.inc"
            ; Clear.
            .INCLUDE    "bcdfix-i-clr.inc"
            ; Load, and Store.
            .INCLUDE    "bcdfix-i-ldmstm.inc"
            ; Comparison.
            .INCLUDE    "bcdfix-i-tstcmp.inc"
            ; Minimum and Maximum.
            .INCLUDE    "bcdfix-i-minmax.inc"
            ; Absolute and Negation.
            .INCLUDE    "bcdfix-i-absneg.inc"
            ; Rounding.
            .INCLUDE    "bcdfix-i-round.inc"
            ; Increment and Decrement.
            .INCLUDE    "bcdfix-i-incdec.inc"
            ; Addition and Subtraction.
            .INCLUDE    "bcdfix-i-adcsbc.inc"
            ; Shifting.
            .INCLUDE    "bcdfix-i-shift.inc"
            ; Multiplication and Division.
            .INCLUDE    "bcdfix-i-muldiv.inc"
            ; Pseudo Random Number Generation.
            .INCLUDE    "bcdfix-i-random.inc"
            ; Conversion to and from a String.
            .INCLUDE    "bcdfix-i-convstr.inc"
            ; Conversion to and from Binary including Fixed Point.
            .INCLUDE    "bcdfix-i-convbin.inc"
            ; Powers.
            .INCLUDE    "bcdfix-i-power.inc"
            ; Roots.
            .INCLUDE    "bcdfix-i-root.inc"
            ; Logarithm.
            .INCLUDE    "bcdfix-i-log.inc"
            ; Exp and Hypotenuse.
            .INCLUDE    "bcdfix-i-exphypot.inc"
            ; Trigonometry.
            .INCLUDE    "bcdfix-i-trig.inc"



;------------------------------------------------------------------------------


