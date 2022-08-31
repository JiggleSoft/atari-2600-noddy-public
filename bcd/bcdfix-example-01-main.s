;==============================================================================
; Title:        Atari 2600 - BCD - fixed point example 01 main file.
; Filename:     bcdfix-example-01-main.s
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2022-08-20 23:44
; Version:      2.0.0
;------------------------------------------------------------------------------
; Copyright (c) 2020 Justin Lane
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

; Config

;------------------------------------------------------------------------------

                .INCLUDE        "atari2k6.inc"

;------------------------------------------------------------------------------

                CPU_CONFIG_VECTOR       cold_start

;------------------------------------------------------------------------------

                .CODE

    BCDFIX_REG_SIZ  = 6

                .INCLUDE        "bcdfix/bcdfix.inc"

.WARNING "---000---"
    BCDFIX_DATAU constdata0
.WARNING "---001---"
    BCDFIX_DATAU constdata1,""
.WARNING "---002---"
    BCDFIX_DATAU constdata2,"0"
.WARNING "---003---"
    BCDFIX_DATAU constdata3,"1"
.WARNING "---004---"
    BCDFIX_DATAU constdata4,"12"
.WARNING "---005---"
    BCDFIX_DATAU constdata5,"123"
.WARNING "---006---"
    BCDFIX_DATAU constdata6,"1234"
.WARNING "---007---"
    BCDFIX_DATAU constdata7,"12345"
.WARNING "---008---"
    BCDFIX_DATAU constdata8,"123456"
.WARNING "---009---"
    BCDFIX_DATAU constdata9,"1234567"
.WARNING "---00A---"
    BCDFIX_DATAU constdataA,"12345678"
.WARNING "---00B---"

    BCDFIX_DECU_FAST m0
        BCDFIX_DECU_FAST m0
            BCDFIX_DECU_FAST m0

cold_start:
                A2K6_TINY_INIT_COLD
main:
; END OF OVERSCAN
                LDA         #VSYNC_ON
                STA         WSYNC
; START OF VBLANK + VSYNC
                STA         VSYNC
                STA         WSYNC
                STA         WSYNC
                LDA         #VSYNC_OFF
                STA         WSYNC
; VBLANK + END OF VSYNC
                STA         VSYNC

                LDA #$2E
                STA COLUBK

.REPEAT 36
                STA         WSYNC
.ENDREP
                LDA #$14
                STA COLUBK
                TAX
                STA         WSYNC

               ; LDA         #VBLANKF_DUMP|VBLANKF_LATCH
                ;STA         VBLANK

                LDA #$1E
                STA COLUPF
                STA         WSYNC

.REPEAT 192
                LDA #$4E
                STX COLUBK
                 STA         WSYNC
.ENDREP

.REPEAT 39
                LDA #$C6
                STX COLUBK

                STA         WSYNC
.ENDREP
                JMP main



                ;KERN_PF0_INIT

 LDA #$C8
 STA COLUBK
 LDA #$FE
 STA COLUPF

 			STA         WSYNC
 			LDA			#VSYNC_ON
 			STA			VSYNC
 			STA         WSYNC
 			STA         WSYNC
 			STA         WSYNC
			LDA			#VSYNC_OFF
			STA			VSYNC
			LDX         #40-3
top:		STA         WSYNC
			DEX
			BNE         top


            LDX         #242
mid:		STA         WSYNC
            TXA
            STA         PF1
   			DEX
  			BNE         bot


			LDX         #30
bot:		STA         WSYNC
			DEX
			BNE         bot



main_loop:
                ;KERN_PF0_START_FRAME    0,1,1,01,01

;;;;;                PF0_LR_
                ;KERN_PF0_RENDER_FRAME   playfield_data,colour_data
                ;KERN_PF0_END_FRAME
 ;ldx #$40
 ;ldy #120
;colloop:
; STX COLUBK
; INX
; INX
; STA WSYNC
; STA WSYNC
; dey
; bne colloop
                JMP             main_loop

                ;KERN_PF0_DONE

endless_loop:
                NOP

zzzzz:
    BCDFIX_DECU_FAST m0


                JMP             endless_loop





 .CODE

;    BCDFIX_MODE_INIT
;
;    BCDFIX_VAR_ZP   ,2
;    BCDFIX_VAR_ZP   ,2,3
;    BCDFIX_VAR_ZP   zp001,2
;    BCDFIX_VAR_ZP   zp002,2,3
;
;    BCDFIX_VAR  ,2
;    BCDFIX_VAR  ,2,3
;    BCDFIX_VAR  mem01,2
;    BCDFIX_VAR  mem02,2,3
;
;
;    BCDFIX_MODE_DONE
;
;    BCDFIX_CLR_FAST     m0
;
;    BCDFIX_CLR_INLINE     m0,X
;
;   ; BCDFIX_CLR     M0,X
;    .CODE
;    BCDFIX_DECU_FAST m0
;    BCDFIX_DECU_FAST m0
;    BCDFIX_DECU_FAST m1
;


;;mc0:   BCDFIX_DATA 12,34,56,78,90,87,65,43
;mc1:    BCDFIX_DATA 12,34,56,78,90,87,65,43

    .CODE

;    BCDFIX_UADD m0,m1,m0,3

    JMP endless_loop