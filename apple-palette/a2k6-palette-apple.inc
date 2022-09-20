;==============================================================================
; Title:        Atari 2600 Palette - Apple.
; Filename:     a2k6-palette-apple.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2022-09-20 23:10
; Version:      1.0.0
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
; Atari colours manually visually determined via data from:-
;   http://www.mrob.com/pub/xapple2/colors.html
;   and
;   https://www.randomterrain.com/atari-2600-memories-tia-color-charts.html)
;------------------------------------------------------------------------------

                .IFNDEF     __A2K6_PALETTE_APPLE__INC__
                            __A2K6_PALETTE_APPLE__INC__ = 1

;==============================================================================
; Atari 2600 Palette - Apple.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Apple Computer Colour Values
;------------------------------------------------------------------------------

    .IF VID_STD = VID_STD_NTSC

APPLE_COLOUR_00     =   $00
APPLE_COLOUR_01     =   $46
APPLE_COLOUR_02     =   $76
APPLE_COLOUR_03     =   $5A
APPLE_COLOUR_04     =   $B6
APPLE_COLOUR_05     =   $06
APPLE_COLOUR_06     =   $AA
APPLE_COLOUR_07     =   $7E
APPLE_COLOUR_08     =   $E4
APPLE_COLOUR_09     =   $38
APPLE_COLOUR_10     =   $06
APPLE_COLOUR_11     =   $5E
APPLE_COLOUR_12     =   $CA
APPLE_COLOUR_13     =   $EC
APPLE_COLOUR_14     =   $BC
APPLE_COLOUR_15     =   $0E

APPLE_HCOLOUR_01    =   $CA
APPLE_HCOLOUR_02    =   $5A
APPLE_HCOLOUR_05    =   $38
APPLE_HCOLOUR_06    =   $AA

    .ELSEIF VID_STD = VID_STD_PAL

APPLE_COLOUR_00     =   $00
APPLE_COLOUR_01     =   $68
APPLE_COLOUR_02     =   $D6
APPLE_COLOUR_03     =   $8C
APPLE_COLOUR_04     =   $54
APPLE_COLOUR_05     =   $07
APPLE_COLOUR_06     =   $9A
APPLE_COLOUR_07     =   $CE
APPLE_COLOUR_08     =   $32
APPLE_COLOUR_09     =   $48
APPLE_COLOUR_10     =   $07
APPLE_COLOUR_11     =   $6E
APPLE_COLOUR_12     =   $5A
APPLE_COLOUR_13     =   $3C
APPLE_COLOUR_14     =   $7C
APPLE_COLOUR_15     =   $0E

APPLE_HCOLOUR_01    =   $5A
APPLE_HCOLOUR_02    =   $8C
APPLE_HCOLOUR_05    =   $58
APPLE_HCOLOUR_06    =   $9A

    .ELSEIF VID_STD = VID_STD_SECAM

        .WARNING "Choose Apple palette colours carefully on SECAM video to prevent two colours being mapped to a single colour."

APPLE_COLOUR_00     =   $00
APPLE_COLOUR_01     =   $64
APPLE_COLOUR_02     =   $B2
APPLE_COLOUR_03     =   $B6
APPLE_COLOUR_04     =   $58
APPLE_COLOUR_05     =   $1E
APPLE_COLOUR_06     =   $B2
APPLE_COLOUR_07     =   $B2
APPLE_COLOUR_08     =   $4C
APPLE_COLOUR_09     =   $2C
APPLE_COLOUR_10     =   $1E
APPLE_COLOUR_11     =   $B6
APPLE_COLOUR_12     =   $58
APPLE_COLOUR_13     =   $1C
APPLE_COLOUR_14     =   $9A
APPLE_COLOUR_15     =   $0E

APPLE_HCOLOUR_01    =   $58
APPLE_HCOLOUR_02    =   $A6
APPLE_HCOLOUR_05    =   $4C
APPLE_HCOLOUR_06    =   $B2

    .ELSE

        .ERROR "Unexpected video standard (VID_STD)!"

    .ENDIF



;------------------------------------------------------------------------------
; Apple Computer Colour Names
;------------------------------------------------------------------------------

APPLE_COLOUR_BLACK      =   APPLE_COLOUR_00
APPLE_COLOUR_RED        =   APPLE_COLOUR_01
APPLE_COLOUR_DKBLUE     =   APPLE_COLOUR_02
APPLE_COLOUR_PURPLE     =   APPLE_COLOUR_03
APPLE_COLOUR_DKGREEN    =   APPLE_COLOUR_04
APPLE_COLOUR_GREY       =   APPLE_COLOUR_05
APPLE_COLOUR_MEDBLUE    =   APPLE_COLOUR_06
APPLE_COLOUR_LTBLUE     =   APPLE_COLOUR_07
APPLE_COLOUR_BROWN      =   APPLE_COLOUR_08
APPLE_COLOUR_ORANGE     =   APPLE_COLOUR_09
APPLE_COLOUR_GREY2      =   APPLE_COLOUR_10
APPLE_COLOUR_PINK       =   APPLE_COLOUR_11
APPLE_COLOUR_LTGREEN    =   APPLE_COLOUR_12
APPLE_COLOUR_YELLOW     =   APPLE_COLOUR_13
APPLE_COLOUR_AQUA       =   APPLE_COLOUR_14
APPLE_COLOUR_WHITE      =   APPLE_COLOUR_15

APPLE_HCOLOUR_GREEN     =   APPLE_HCOLOUR_01
APPLE_HCOLOUR_PURPLE    =   APPLE_HCOLOUR_02
APPLE_HCOLOUR_ORANGE    =   APPLE_HCOLOUR_05
APPLE_HCOLOUR_BLUE      =   APPLE_HCOLOUR_06



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


