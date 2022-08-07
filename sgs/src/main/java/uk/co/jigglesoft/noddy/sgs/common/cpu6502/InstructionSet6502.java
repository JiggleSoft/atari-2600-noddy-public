package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502.*;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.Stability6502.*;

/**
 *
 */
public enum InstructionSet6502
{
    BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED, new CycleCount6502(7)),
    ORA_XIN(0x01, Mnemonic6502.ORA, INDEXED_X_INDIRECT, new CycleCount6502(6)),
    JAM_IMP_02(0x02, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    SLO_XIN(0x03, Mnemonic6502.SLO, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    NOP_ZPG(0x04, Mnemonic6502.NOP, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    ORA_ZPG(0x05, Mnemonic6502.ORA, ZERO_PAGE, new CycleCount6502()),
    ASL_ZPG(0x06, Mnemonic6502.ASL, ZERO_PAGE, new CycleCount6502()),
    SLO_ZPG(0x07, Mnemonic6502.SLO, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    PHP_IMP(0x08, Mnemonic6502.PHP, IMPLIED, new CycleCount6502()),
    ORA_IMM(0x09, Mnemonic6502.ORA, IMMEDIATE, new CycleCount6502()),
    ASL_ACC(0x0A, Mnemonic6502.ASL, ACCUMULATOR, new CycleCount6502()),
    ANC_IMM(0x0B, Mnemonic6502.ANC, IMMEDIATE, new CycleCount6502(), true, STABLE),
    NOP_ABS_0C(0x0C, Mnemonic6502.NOP, ABSOLUTE, new CycleCount6502(), true, STABLE),
    ORA_ABS(0x0D, Mnemonic6502.ORA, ABSOLUTE, new CycleCount6502()),
    ASL_ABS(0x0E, Mnemonic6502.ASL, ABSOLUTE, new CycleCount6502()),
    SLO_ABS(0x0F, Mnemonic6502.SLO, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BPL_REL(0x10, Mnemonic6502.BPL, RELATIVE, new CycleCount6502()),
    ORA_INY(0x11, Mnemonic6502.ORA, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_12(0x12, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    SLO_INY(0x13, Mnemonic6502.SLO, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ZPX_14(0x14, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    ORA_ZPX(0x15, Mnemonic6502.ORA, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    ASL_ZPX(0x16, Mnemonic6502.ASL, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    SLO_ZPX(0x17, Mnemonic6502.SLO, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    CLC_IMP(0x18, Mnemonic6502.CLC, IMPLIED, new CycleCount6502()),
    ORA_ABY(0x19, Mnemonic6502.ORA, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    NOP_IMP_1A(0x1A, Mnemonic6502.NOP, IMPLIED, new CycleCount6502(), true, STABLE),
    SLO_ABY(0x1B, Mnemonic6502.SLO, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ABX_1C(0x1C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    ORA_ABX(0x1D, Mnemonic6502.ORA, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    ASL_ABX(0x1E, Mnemonic6502.ASL, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    SLO_ABX(0x1F, Mnemonic6502.SLO, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    JSR_ABS(0x20, Mnemonic6502.JSR, ABSOLUTE, new CycleCount6502()),
    AND_XIN(0x21, Mnemonic6502.AND, INDEXED_X_INDIRECT, new CycleCount6502()),
    JAM_IMP_22(0x22, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    RLA_XIN(0x23, Mnemonic6502.RLA, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    BIT_ZPG(0x24, Mnemonic6502.BIT, ZERO_PAGE, new CycleCount6502()),
    AND_ZPG(0x25, Mnemonic6502.AND, ZERO_PAGE, new CycleCount6502()),
    ROL_ZPG(0x26, Mnemonic6502.ROL, ZERO_PAGE, new CycleCount6502()),
    RLA_ZPG(0x27, Mnemonic6502.RLA, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    PLP_IMP(0x28, Mnemonic6502.PLP, IMPLIED, new CycleCount6502()),
    AND_IMM(0x29, Mnemonic6502.AND, IMMEDIATE, new CycleCount6502()),
    ROL_ACC(0x2A, Mnemonic6502.ROL, ACCUMULATOR, new CycleCount6502()),
    ANC_IMM_2B(0x2B, Mnemonic6502.ANC, IMMEDIATE, new CycleCount6502(), true, STABLE),
    BIT_ABS(0x2C, Mnemonic6502.BIT, ABSOLUTE, new CycleCount6502()),
    AND_ABS(0x2D, Mnemonic6502.AND, ABSOLUTE, new CycleCount6502()),
    ROL_ABS(0x2E, Mnemonic6502.ROL, ABSOLUTE, new CycleCount6502()),
    RLA_ABS(0x2F, Mnemonic6502.RLA, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BMI_REL(0x30, Mnemonic6502.BMI, RELATIVE, new CycleCount6502()),
    AND_INY(0x31, Mnemonic6502.AND, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_32(0x32, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    RLA_INY(0x33, Mnemonic6502.RLA, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ZPX_34(0x34, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    AND_ZPX(0x35, Mnemonic6502.AND, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    ROL_ZPX(0x36, Mnemonic6502.ROL, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    RLA_ZPX(0x37, Mnemonic6502.RLA, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    SEC_IMP(0x38, Mnemonic6502.SEC, IMPLIED, new CycleCount6502()),
    AND_ABY(0x39, Mnemonic6502.AND, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    NOP_IMP_3A(0x3A, Mnemonic6502.NOP, IMPLIED, new CycleCount6502(), true, STABLE),
    RLA_ABY(0x3B, Mnemonic6502.RLA, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ABX_3C(0x3C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    AND_ABX(0x3D, Mnemonic6502.AND, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    ROL_ABX(0x3E, Mnemonic6502.ROL, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    RLA_ABX(0x3F, Mnemonic6502.RLA, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    RTI_IMP(0x40, Mnemonic6502.RTI, IMPLIED, new CycleCount6502()),
    EOR_XIN(0x41, Mnemonic6502.EOR, INDEXED_X_INDIRECT, new CycleCount6502()),
    JAM_IMP_42(0x42, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    SRE_XIN(0x43, Mnemonic6502.SRE, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    NOP_ZPG_44(0x44, Mnemonic6502.NOP, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    EOR_ZPG(0x45, Mnemonic6502.EOR, ZERO_PAGE, new CycleCount6502()),
    LSR_ZPG(0x46, Mnemonic6502.LSR, ZERO_PAGE, new CycleCount6502()),
    SRE_ZPG(0x47, Mnemonic6502.SRE, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    PHA_IMP(0x48, Mnemonic6502.PHA, IMPLIED, new CycleCount6502()),
    EOR_IMM(0x49, Mnemonic6502.EOR, IMMEDIATE, new CycleCount6502()),
    LSR_ACC(0x4A, Mnemonic6502.LSR, ACCUMULATOR, new CycleCount6502()),
    ALR_IMM(0x4B, Mnemonic6502.ALR, IMMEDIATE, new CycleCount6502(), true, STABLE),
    JMP_ABS(0x4C, Mnemonic6502.JMP, ABSOLUTE, new CycleCount6502()),
    EOR_ABS(0x4D, Mnemonic6502.EOR, ABSOLUTE, new CycleCount6502()),
    LSR_ABS(0x4E, Mnemonic6502.LSR, ABSOLUTE, new CycleCount6502()),
    SRE_ABS(0x4F, Mnemonic6502.SRE, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BVC_REL(0x50, Mnemonic6502.BVC, RELATIVE, new CycleCount6502()),
    EOR_INY(0x51, Mnemonic6502.EOR, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_52(0x52, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    SRE_INY(0x53, Mnemonic6502.SRE, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ZPX(0x54, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    EOR_ZPX(0x55, Mnemonic6502.EOR, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    LSR_ZPX(0x56, Mnemonic6502.LSR, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    SRE_ZPX(0x57, Mnemonic6502.SRE, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    CLI_IMP(0x58, Mnemonic6502.CLI, IMPLIED, new CycleCount6502()),
    EOR_ABY(0x59, Mnemonic6502.EOR, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    NOP_IMP_5A(0x5A, Mnemonic6502.NOP, IMPLIED, new CycleCount6502(), true, STABLE),
    SRE_ABY(0x5B, Mnemonic6502.SRE, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ABX_53(0x5C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    EOR_ABX(0x5D, Mnemonic6502.EOR, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    LSR_ABX(0x5E, Mnemonic6502.LSR, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    SRE_ABX(0x5F, Mnemonic6502.SRE, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    RTS_IMP(0x60, Mnemonic6502.RTS, IMPLIED, new CycleCount6502()),
    ADC_XIN(0x61, Mnemonic6502.ADC, INDEXED_X_INDIRECT, new CycleCount6502()),
    JAM_IMP_62(0x62, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    RRA_XIN(0x63, Mnemonic6502.RRA, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    NOP_ZPG_64(0x64, Mnemonic6502.NOP, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    ADC_ZPG(0x65, Mnemonic6502.ADC, ZERO_PAGE, new CycleCount6502()),
    ROR_ZPG(0x66, Mnemonic6502.ROR, ZERO_PAGE, new CycleCount6502()),
    RRA_ZPG(0x67, Mnemonic6502.RRA, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    PLA_IMP(0x68, Mnemonic6502.PLA, IMPLIED, new CycleCount6502()),
    ADC_IMM(0x69, Mnemonic6502.ADC, IMMEDIATE, new CycleCount6502()),
    ROR_ACC(0x6A, Mnemonic6502.ROR, ACCUMULATOR, new CycleCount6502()),
    ARR_IMM(0x6B, Mnemonic6502.ARR, IMMEDIATE, new CycleCount6502(), true, STABLE),
    JMP_IND(0x6C, Mnemonic6502.JMP, INDIRECT, new CycleCount6502()),
    ADC_ABS(0x6D, Mnemonic6502.ADC, ABSOLUTE, new CycleCount6502()),
    ROR_ABS(0x6E, Mnemonic6502.ROR, ABSOLUTE, new CycleCount6502()),
    RRA_ABS(0x6F, Mnemonic6502.RRA, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BVS_REL(0x70, Mnemonic6502.BVS, RELATIVE, new CycleCount6502()),
    ADC_INY(0x71, Mnemonic6502.ADC, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_72(0x72, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    RRA_INY(0x73, Mnemonic6502.RRA, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ZPX_74(0x74, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    ADC_ZPX(0x75, Mnemonic6502.ADC, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    ROR_ZPX(0x76, Mnemonic6502.ROR, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    RRA_ZPX(0x77, Mnemonic6502.RRA, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    SEI_IMP(0x78, Mnemonic6502.SEI, IMPLIED, new CycleCount6502()),
    ADC_ABY(0x79, Mnemonic6502.ADC, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    NOP_IMP_7A(0x7A, Mnemonic6502.NOP, IMPLIED, new CycleCount6502(), true, STABLE),
    RRA_ABY(0x7B, Mnemonic6502.RRA, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ABX_7C(0x7C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    ADC_ABX(0x7D, Mnemonic6502.ADC, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    ROR_ABX(0x7E, Mnemonic6502.ROR, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    RRA_ABX(0x7F, Mnemonic6502.RRA, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    NOP_IMM(0x80, Mnemonic6502.NOP, IMMEDIATE, new CycleCount6502(), true, STABLE),
    STA_XIN(0x81, Mnemonic6502.STA, INDEXED_X_INDIRECT, new CycleCount6502()),
    NOP_IMM_82(0x82, Mnemonic6502.NOP, IMMEDIATE, new CycleCount6502(), true, STABLE),
    SAX_XIN(0x83, Mnemonic6502.SAX, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    STY_ZPG(0x84, Mnemonic6502.STY, ZERO_PAGE, new CycleCount6502()),
    STA_ZPG(0x85, Mnemonic6502.STA, ZERO_PAGE, new CycleCount6502()),
    STX_ZPG(0x86, Mnemonic6502.STX, ZERO_PAGE, new CycleCount6502()),
    SAX_ZPG(0x87, Mnemonic6502.SAX, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    DEY_IMP(0x88, Mnemonic6502.DEY, IMPLIED, new CycleCount6502()),
    NOP_IMM_89(0x89, Mnemonic6502.NOP, IMMEDIATE, new CycleCount6502(), true, STABLE),
    TXA_IMP(0x8A, Mnemonic6502.TXA, IMPLIED, new CycleCount6502()),
    ANE_IMM(0x8B, Mnemonic6502.ANE, IMMEDIATE, new CycleCount6502(), true, HIGHLY_UNSTABLE),
    STY_ABS(0x8C, Mnemonic6502.STY, ABSOLUTE, new CycleCount6502()),
    STA_ABS(0x8D, Mnemonic6502.STA, ABSOLUTE, new CycleCount6502()),
    STX_ABS(0x8E, Mnemonic6502.STX, ABSOLUTE, new CycleCount6502()),
    SAX_ABS(0x8F, Mnemonic6502.SAX, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BCC_REL(0x90, Mnemonic6502.BCC, RELATIVE, new CycleCount6502()),
    STA_INY(0x91, Mnemonic6502.STA, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_92(0x92, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    SHA_INY(0x93, Mnemonic6502.SHA, INDIRECT_INDEXED_Y, new CycleCount6502(), true, UNSTABLE),
    STY_ZPX(0x94, Mnemonic6502.STY, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    STA_ZPX(0x95, Mnemonic6502.STA, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    STX_ZPY(0x96, Mnemonic6502.STX, ZERO_PAGE_INDEXED_Y, new CycleCount6502()),
    SAX_ZPY(0x97, Mnemonic6502.SAX, ZERO_PAGE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    TYA_IMP(0x98, Mnemonic6502.TYA, IMPLIED, new CycleCount6502()),
    STA_ABY(0x99, Mnemonic6502.STA, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    TXS_IMP(0x9A, Mnemonic6502.TXS, IMPLIED, new CycleCount6502()),
    TAS_ABY(0x9B, Mnemonic6502.TAS, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, UNSTABLE),
    SHY_ABX(0x9C, Mnemonic6502.SHY, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, UNSTABLE),
    STA_ABX(0x9D, Mnemonic6502.STA, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    SHX_ABY(0x9E, Mnemonic6502.SHX, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, UNSTABLE),
    SHA_ABY(0x9F, Mnemonic6502.SHA, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, UNSTABLE),
    LDY_IMM(0xA0, Mnemonic6502.LDY, IMMEDIATE, new CycleCount6502()),
    LDA_XIN(0xA1, Mnemonic6502.LDA, INDEXED_X_INDIRECT, new CycleCount6502()),
    LDX_IMM(0xA2, Mnemonic6502.LDX, IMMEDIATE, new CycleCount6502()),
    LAX_XIN(0xA3, Mnemonic6502.LAX, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    LDY_ZPG(0xA4, Mnemonic6502.LDY, ZERO_PAGE, new CycleCount6502()),
    LDA_ZPG(0xA5, Mnemonic6502.LDA, ZERO_PAGE, new CycleCount6502()),
    LDX_ZPG(0xA6, Mnemonic6502.LDX, ZERO_PAGE, new CycleCount6502()),
    LAX_ZPG(0xA7, Mnemonic6502.LAX, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    TAY_IMP(0xA8, Mnemonic6502.TAY, IMPLIED, new CycleCount6502()),
    LDA_IMM(0xA9, Mnemonic6502.LDA, IMMEDIATE, new CycleCount6502()),
    TAX_IMP(0xAA, Mnemonic6502.TAX, IMPLIED, new CycleCount6502()),
    LXA_IMM(0xAB, Mnemonic6502.LXA, IMMEDIATE, new CycleCount6502(), true, HIGHLY_UNSTABLE),
    LDY_ABS(0xAC, Mnemonic6502.LDY, ABSOLUTE, new CycleCount6502()),
    LDA_ABS(0xAD, Mnemonic6502.LDA, ABSOLUTE, new CycleCount6502()),
    LDX_ABS(0xAE, Mnemonic6502.LDX, ABSOLUTE, new CycleCount6502()),
    LAX_ABS(0xAF, Mnemonic6502.LAX, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BCS_REL(0xB0, Mnemonic6502.BCS, RELATIVE, new CycleCount6502()),
    LDA_INY(0xB1, Mnemonic6502.LDA, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_B2(0xB2, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    LAX_INY(0xB3, Mnemonic6502.LAX, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    LDY_ZPX(0xB4, Mnemonic6502.LDY, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    LDA_ZPX(0xB5, Mnemonic6502.LDA, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    LDX_ZPY(0xB6, Mnemonic6502.LDX, ZERO_PAGE_INDEXED_Y, new CycleCount6502()),
    LAX_ZPY(0xB7, Mnemonic6502.LAX, ZERO_PAGE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    CLV_IMP(0xB8, Mnemonic6502.CLV, IMPLIED, new CycleCount6502()),
    LDA_ABY(0xB9, Mnemonic6502.LDA, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    TSX_IMP(0xBA, Mnemonic6502.TSX, IMPLIED, new CycleCount6502()),
    LAS_ABY(0xBB, Mnemonic6502.LAS, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    LDY_ABX(0xBC, Mnemonic6502.LDY, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    LDA_ABX(0xBD, Mnemonic6502.LDA, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    LDX_ABY(0xBE, Mnemonic6502.LDX, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    LAX_ABY(0xBF, Mnemonic6502.LAX, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    CPY_IMM(0xC0, Mnemonic6502.CPY, IMMEDIATE, new CycleCount6502()),
    CMP_XIN(0xC1, Mnemonic6502.CMP, INDEXED_X_INDIRECT, new CycleCount6502()),
    NOP_IMM_C2(0xC2, Mnemonic6502.NOP, IMMEDIATE, new CycleCount6502(), true, STABLE),
    DCP_XIN(0xC3, Mnemonic6502.DCP, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    CPY_ZPG(0xC4, Mnemonic6502.CPY, ZERO_PAGE, new CycleCount6502()),
    CMP_ZPG(0xC5, Mnemonic6502.CMP, ZERO_PAGE, new CycleCount6502()),
    DEC_ZPG(0xC6, Mnemonic6502.DEC, ZERO_PAGE, new CycleCount6502()),
    DCP_ZPG(0xC7, Mnemonic6502.DCP, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    INY_IMP(0xC8, Mnemonic6502.INY, IMPLIED, new CycleCount6502()),
    CMP_IMM(0xC9, Mnemonic6502.CMP, IMMEDIATE, new CycleCount6502()),
    DEX_IMP(0xCA, Mnemonic6502.DEX, IMPLIED, new CycleCount6502()),
    SBX_IMM(0xCB, Mnemonic6502.SBX, IMMEDIATE, new CycleCount6502(), true, STABLE),
    CPY_ABS(0xCC, Mnemonic6502.CPY, ABSOLUTE, new CycleCount6502()),
    CMP_ABS(0xCD, Mnemonic6502.CMP, ABSOLUTE, new CycleCount6502()),
    DEC_ABS(0xCE, Mnemonic6502.DEC, ABSOLUTE, new CycleCount6502()),
    DCP_ABS(0xCF, Mnemonic6502.DCP, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BNE_REL(0xD0, Mnemonic6502.BNE, RELATIVE, new CycleCount6502()),
    CMP_INY(0xD1, Mnemonic6502.CMP, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_D2(0xD2, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    DCP_INY(0xD3, Mnemonic6502.DCP, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ZPX_D4(0xD4, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    CMP_ZPX(0xD5, Mnemonic6502.CMP, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    DEC_ZPX(0xD6, Mnemonic6502.DEC, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    DCP_ZPX(0xD7, Mnemonic6502.DCP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    CLD_IMP(0xD8, Mnemonic6502.CLD, IMPLIED, new CycleCount6502()),
    CMP_ABY(0xD9, Mnemonic6502.CMP, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    NOP_IMP_DA(0xDA, Mnemonic6502.NOP, IMPLIED, new CycleCount6502(), true, STABLE),
    DCP_ABY(0xDB, Mnemonic6502.DCP, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ABX_DC(0xDC, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    CMP_ABX(0xDD, Mnemonic6502.CMP, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    DEC_ABX(0xDE, Mnemonic6502.DEC, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    DCP_ABX(0xDF, Mnemonic6502.DCP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    CPX_IMM(0xE0, Mnemonic6502.CPX, IMMEDIATE, new CycleCount6502()),
    SBC_XIN(0xE1, Mnemonic6502.SBC, INDEXED_X_INDIRECT, new CycleCount6502()),
    NOP_IMM_E2(0xE2, Mnemonic6502.NOP, IMMEDIATE, new CycleCount6502(), true, STABLE),
    ISC_XIN(0xE3, Mnemonic6502.ISC, INDEXED_X_INDIRECT, new CycleCount6502(), true, STABLE),
    CPX_ZPG(0xE4, Mnemonic6502.CPX, ZERO_PAGE, new CycleCount6502()),
    SBC_ZPG(0xE5, Mnemonic6502.SBC, ZERO_PAGE, new CycleCount6502()),
    INC_ZPG(0xE6, Mnemonic6502.INC, ZERO_PAGE, new CycleCount6502()),
    ISC_ZPG(0xE7, Mnemonic6502.ISC, ZERO_PAGE, new CycleCount6502(), true, STABLE),
    INX_IMP(0xE8, Mnemonic6502.INX, IMPLIED, new CycleCount6502()),
    SBC_IMM(0xE9, Mnemonic6502.SBC, IMMEDIATE, new CycleCount6502()),
    NOP_IMP(0xEA, Mnemonic6502.NOP, IMPLIED, new CycleCount6502()),
    SBC_IMM_EB(0xEB, Mnemonic6502.SBC, IMMEDIATE, new CycleCount6502(), true, STABLE),
    CPX_ABS(0xEC, Mnemonic6502.CPX, ABSOLUTE, new CycleCount6502()),
    SBC_ABS(0xED, Mnemonic6502.SBC, ABSOLUTE, new CycleCount6502()),
    INC_ABS(0xEE, Mnemonic6502.INC, ABSOLUTE, new CycleCount6502()),
    ISC_ABS(0xEF, Mnemonic6502.ISC, ABSOLUTE, new CycleCount6502(), true, STABLE),
    BEQ_REL(0xF0, Mnemonic6502.BEQ, RELATIVE, new CycleCount6502()),
    SBC_INY(0xF1, Mnemonic6502.SBC, INDIRECT_INDEXED_Y, new CycleCount6502()),
    JAM_IMP_F2(0xF2, Mnemonic6502.JAM, IMPLIED, new CycleCount6502(), true, KABOOM),
    ISC_INY(0xF3, Mnemonic6502.ISC, INDIRECT_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ZPX_F4(0xF4, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    SBC_ZPX(0xF5, Mnemonic6502.SBC, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    INC_ZPX(0xF6, Mnemonic6502.INC, ZERO_PAGE_INDEXED_X, new CycleCount6502()),
    ISC_ZPX(0xF7, Mnemonic6502.ISC, ZERO_PAGE_INDEXED_X, new CycleCount6502(), true, STABLE),
    SED_IMP(0xF8, Mnemonic6502.SED, IMPLIED, new CycleCount6502()),
    SBC_ABY(0xF9, Mnemonic6502.SBC, ABSOLUTE_INDEXED_Y, new CycleCount6502()),
    NOP_IMP_FA(0xFA, Mnemonic6502.NOP, IMPLIED, new CycleCount6502(), true, STABLE),
    ISC_ABY(0xFB, Mnemonic6502.ISC, ABSOLUTE_INDEXED_Y, new CycleCount6502(), true, STABLE),
    NOP_ABX_FC(0xFC, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE),
    SBC_ABX(0xFD, Mnemonic6502.SBC, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    INC_ABX(0xFE, Mnemonic6502.INC, ABSOLUTE_INDEXED_X, new CycleCount6502()),
    ISC_ABX(0xFF, Mnemonic6502.ISC, ABSOLUTE_INDEXED_X, new CycleCount6502(), true, STABLE);

    /** . */
    private final int opcode;

    /** . */
    private final Mnemonic6502 mnemonic;

    /** . */
    private final AddressMode6502 addressMode;

    /** . */
    private final CycleCount6502 cycleCounts;

    /** . */
    private final OpcodeState6502 opcodeState;

    /** . */
    private final boolean illegalInstruction;

    /** . */
    private final Stability6502 opcodeStability;

    /**
     *
     * @param opcode
     * @param mnemonic
     * @param addressMode
     * @param cycleCount
     */
    InstructionSet6502(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode, final CycleCount6502 cycleCount)
    {
       this(opcode, mnemonic, addressMode, cycleCount, false, STABLE);
    }

    /**
     *
     * @param opcode
     * @param mnemonic
     * @param addressMode
     * @param cycleCount
     * @param illegalInstruction
     * @param opcodeStability
     */
    InstructionSet6502(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode, final CycleCount6502 cycleCount, final boolean illegalInstruction, final Stability6502 opcodeStability)
    {
        this.opcode = opcode;
        this.mnemonic = mnemonic;
        this.addressMode = addressMode;
        this.cycleCounts = cycleCount;
        this.opcodeState = null;
        this.illegalInstruction = illegalInstruction;
        this.opcodeStability = opcodeStability;
    }

    /**
     *
     * @return
     */
    final int getOpcode()
    {
        return opcode;
    }

    /**
     *
     * @return
     */
    final Mnemonic6502 getMnemonic()
    {
        return mnemonic;
    }

    /**
     *
     * @return
     */
    final AddressMode6502 getAddressMode()
    {
        return addressMode;
    }

    /**
     *
     * @return
     */
    public CycleCount6502 getCycleCount()
    {
        return cycleCounts;
    }

    /**
     *
     * @return
     */
    public OpcodeState6502 getOpcodeState()
    {
        return opcodeState;
    }

    /**
     *
     * @return
     */
    public boolean isIllegalInstruction()
    {
        return illegalInstruction;
    }

    /**
     *
     * @return
     */
    public Stability6502 getOpcodeStability()
    {
        return opcodeStability;
    }

    /**
     *
     * @return
     */
    final int getOpcodeByteSize()
    {
        return 1;
    }

    /**
     * s
     * @return
     */
    final int getOperandByteSize()
    {
        return addressMode.getOperandByteSize();
    }

    /**
     *
     * @return
     */
    final int getByteSize()
    {
        return getOpcodeByteSize() + getOperandByteSize();
    }
}
