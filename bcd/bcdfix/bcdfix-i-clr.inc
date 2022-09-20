;==============================================================================
; Title:        Binary Coded Decimal (BCD) Fixed Point Math Functions.
; Sub-Title:    Clear.
; Filename:     bcdfix-i-clr.inc
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


------------------------------------------------------------------------------
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


