#------------------------------------------------------------------------------
# Makefile for bcdfix-example-01-main.s.
# Makefile for bcdfix-example-01-main.s.
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# CONFIGURATION
#------------------------------------------------------------------------------

APP_NAME=bcdfix-example-01
ASM_COMMON_DIR=../../atari-2600-asm-common/build/atari-2600-asm-common-2.0.0-beta-0
STELLA="stella"
BUILD_DIR=build


#------------------------------------------------------------------------------
# INCLUDE RULES
#------------------------------------------------------------------------------

include ${ASM_COMMON_DIR}/make/cc65.rules
include ${ASM_COMMON_DIR}/make/a2k6.rules


#------------------------------------------------------------------------------
# BUILD
#------------------------------------------------------------------------------

default:
	@echo "Please make with known target e.g. clean, build, build-ntsc, run, run-pal"


#------------------------------------------------------------------------------
# BUILD
#------------------------------------------------------------------------------

build: build-lib build-test
	@

build-ntsc: ${BUILD_DIR}/ntsc/${APP_NAME}-ntsc.4k
	@

build-pal60: ${BUILD_DIR}/pal60/${APP_NAME}-pal60.4k
	@

build-pal: ${BUILD_DIR}/pal/${APP_NAME}-pal.4k
	@

build-secam: ${BUILD_DIR}/secam/${APP_NAME}-secam.4k
	@

build-palx: ${BUILD_DIR}/palx/${APP_NAME}-palx.4k
	@

build-secamx: ${BUILD_DIR}/secamx/${APP_NAME}-secamx.4k
	@


build-init:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${BUILD_DIR}/ntsc
	mkdir -p ${BUILD_DIR}/pal60
	mkdir -p ${BUILD_DIR}/pal
	mkdir -p ${BUILD_DIR}/secam
	mkdir -p ${BUILD_DIR}/palx
	mkdir -p ${BUILD_DIR}/secamx


${BUILD_DIR}/ntsc/${APP_NAME}-ntsc.4k: build-init ${BUILD_DIR}/ntsc/${APP_NAME}-main-ntsc.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/ntsc/${APP_NAME}-ntsc.map -Ln ${BUILD_DIR}/ntsc/${APP_NAME}-ntsc.labels -vm ${BUILD_DIR}/ntsc/${APP_NAME}-main-ntsc.o -o ${BUILD_DIR}/ntsc/${APP_NAME}-ntsc.4k

${BUILD_DIR}/pal60/${APP_NAME}-pal60.4k: build-init ${BUILD_DIR}/pal60/${APP_NAME}-main-pal60.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/pal60/${APP_NAME}-pal60.map -Ln ${BUILD_DIR}/pal60/${APP_NAME}-pal60.labels -vm ${BUILD_DIR}/pal60/${APP_NAME}-main-pal60.o -o ${BUILD_DIR}/pal60/${APP_NAME}-pal60.4k

${BUILD_DIR}/pal/${APP_NAME}-pal.4k: build-init ${BUILD_DIR}/pal/${APP_NAME}-main-pal.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/pal/${APP_NAME}-pal.map -Ln ${BUILD_DIR}/pal/${APP_NAME}-pal.labels -vm ${BUILD_DIR}/pal/${APP_NAME}-main-pal.o -o ${BUILD_DIR}/pal/${APP_NAME}-pal.4k

${BUILD_DIR}/secam/${APP_NAME}-secam.4k: build-init ${BUILD_DIR}/secam/${APP_NAME}-main-secam.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/secam/${APP_NAME}-secam.map -Ln ${BUILD_DIR}/secam/${APP_NAME}-secam.labels -vm ${BUILD_DIR}/secam/${APP_NAME}-main-secam.o -o ${BUILD_DIR}/secam/${APP_NAME}-secam.4k

${BUILD_DIR}/palx/${APP_NAME}-palx.4k: build-init ${BUILD_DIR}/palx/${APP_NAME}-main-palx.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/palx/${APP_NAME}-palx.map -Ln ${BUILD_DIR}/palx/${APP_NAME}-palx.labels -vm ${BUILD_DIR}/palx/${APP_NAME}-main-palx.o -o ${BUILD_DIR}/palx/${APP_NAME}-palx.4k

${BUILD_DIR}/secamx/${APP_NAME}-secamx.4k: build-init ${BUILD_DIR}/secamx/${APP_NAME}-main-secamx.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/secamx/${APP_NAME}-secamx.map -Ln ${BUILD_DIR}/secamx/${APP_NAME}-secamx.labels -vm ${BUILD_DIR}/secamx/${APP_NAME}-main-secamx.o -o ${BUILD_DIR}/secamx/${APP_NAME}-secamx.4k



${BUILD_DIR}/ntsc/${APP_NAME}-main-ntsc.o: ${APP_NAME}-main.s bcdfix
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_NTSC -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/ntsc/${APP_NAME}-main-ntsc.lst --list-bytes 255 ${APP_NAME}-main.s -o ${BUILD_DIR}/ntsc/${APP_NAME}-main-ntsc.o

${BUILD_DIR}/pal60/${APP_NAME}-main-pal60.o: ${APP_NAME}-main.s bcdfix
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_PAL60 -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/pal60/${APP_NAME}-main-pal60.lst ${APP_NAME}-main.s -o ${BUILD_DIR}/pal60/${APP_NAME}-main-pal60.o

${BUILD_DIR}/pal/${APP_NAME}-main-pal.o: ${APP_NAME}-main.s bcdfix
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_PAL -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/pal/${APP_NAME}-main-pal.lst ${APP_NAME}-main.s -o ${BUILD_DIR}/pal/${APP_NAME}-main-pal.o

${BUILD_DIR}/secam/${APP_NAME}-main-secam.o: ${APP_NAME}-main.s bcdfix
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_SECAM -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/secam/${APP_NAME}-main-secam.lst ${APP_NAME}-main.s -o ${BUILD_DIR}/secam/${APP_NAME}-main-secam.o

${BUILD_DIR}/palx/${APP_NAME}-main-palx.o: ${APP_NAME}-main.s bcdfix
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_PALX -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/palx/${APP_NAME}-main-palx.lst ${APP_NAME}-main.s -o ${BUILD_DIR}/palx/${APP_NAME}-main-palx.o

${BUILD_DIR}/secamx/${APP_NAME}-main-secamx.o: ${APP_NAME}-main.s bcdfix
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_SECAMX -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/secamx/${APP_NAME}-main-secamx.lst ${APP_NAME}-main.s -o ${BUILD_DIR}/secamx/${APP_NAME}-main-secamx.o



#------------------------------------------------------------------------------
# TEST
#------------------------------------------------------------------------------

test: test-1
	@

test-1: build-lib
	$(SIM65)  ${BUILD_DIR}/test/${LIB_NAME}-test-1.bin



#------------------------------------------------------------------------------
# CLEAN
#------------------------------------------------------------------------------

clean: clean-lib clean-test
	$(RM) -r ${BUILD_DIR}

clean-lib:
	$(RM) -r ${BUILD_DIR}/main

clean-test:
	$(RM) -r ${BUILD_DIR}/test

