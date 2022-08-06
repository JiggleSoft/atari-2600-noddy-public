package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502.*;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.OpCodeStability6502.*;

/**
 *
 */
public enum InstructionSet65XX
{
    BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED),
    ORA_INX(0x01, Mnemonic6502.ORA, INDEXED_X_INDIRECT),
    JAM_IMP_02(0x02, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    SLO_INX(0x03, Mnemonic6502.SLO, INDEXED_X_INDIRECT, true, STABLE),
    NOP_ZPG(0x04, Mnemonic6502.NOP, ZERO_PAGE, true, STABLE),
    ORA_ZPG(0x05, Mnemonic6502.ORA, ZERO_PAGE),
    ASL_ZPG(0x06, Mnemonic6502.ASL, ZERO_PAGE),
    SLO_ZPG(0x07, Mnemonic6502.SLO, ZERO_PAGE, true, STABLE),
    PHP_IMP(0x08, Mnemonic6502.PHP, IMPLIED),
    ORA_IMM(0x09, Mnemonic6502.ORA, IMMEDIATE),
    ASL_ACC(0x0A, Mnemonic6502.ASL, ACCUMULATOR),
    ANC_IMM(0x0B, Mnemonic6502.ANC, IMMEDIATE, true, STABLE),
    NOP_ABS_0C(0x0C, Mnemonic6502.NOP, ABSOLUTE, true, STABLE),
    ORA_ABS(0x0D, Mnemonic6502.ORA, ABSOLUTE),
    ASL_ABS(0x0E, Mnemonic6502.ASL, ABSOLUTE),
    SLO_ABS(0x0F, Mnemonic6502.SLO, ABSOLUTE, true, STABLE),
    BPL_REL(0x10, Mnemonic6502.BPL, RELATIVE),
    ORA_INY(0x11, Mnemonic6502.ORA, INDIRECT_INDEXED_Y),
    JAM_IMP_12(0x12, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    SLO_INY(0x13, Mnemonic6502.SLO, INDIRECT_INDEXED_Y, true, STABLE),
    NOP_ZPX_14(0x14, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, STABLE),
    ORA_ZPX(0x15, Mnemonic6502.ORA, ZERO_PAGE_INDEXED_X),
    ASL_ZPX(0x16, Mnemonic6502.ASL, ZERO_PAGE_INDEXED_X),
    SLO_ZPX(0x17, Mnemonic6502.SLO, ZERO_PAGE_INDEXED_X, true, STABLE),
    CLC_IMP(0x18, Mnemonic6502.CLC, IMPLIED),
    ORA_ABY(0x19, Mnemonic6502.ORA, ABSOLUTE_INDEXED_Y),
    NOP_IMP_1A(0x1A, Mnemonic6502.NOP, IMPLIED, true, STABLE),
    SLO_ABY(0x1B, Mnemonic6502.SLO, ABSOLUTE_INDEXED_Y, true, STABLE),
    NOP_ABX_1C(0x1C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, STABLE),
    ORA_ABX(0x1D, Mnemonic6502.ORA, ABSOLUTE_INDEXED_X),
    ASL_ABX(0x1E, Mnemonic6502.ASL, ABSOLUTE_INDEXED_X),
    SLO_ABX(0x1F, Mnemonic6502.SLO, ABSOLUTE_INDEXED_X, true, STABLE),
    JSR_ABS(0x20, Mnemonic6502.JSR, ABSOLUTE),
    AND_INX(0x21, Mnemonic6502.AND, INDEXED_X_INDIRECT),
    JAM_IMP_22(0x22, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    RLA_INX(0x23, Mnemonic6502.RLA, INDEXED_X_INDIRECT, true, STABLE),
    BIT_ZPG(0x24, Mnemonic6502.BIT, ZERO_PAGE),
    AND_ZPG(0x25, Mnemonic6502.AND, ZERO_PAGE),
    ROL_ZPG(0x26, Mnemonic6502.ROL, ZERO_PAGE),
    RLA_ZPG(0x27, Mnemonic6502.RLA, ZERO_PAGE, true, STABLE),
    PLP_IMP(0x28, Mnemonic6502.PLP, IMPLIED),
    AND_IMM(0x29, Mnemonic6502.AND, IMMEDIATE),
    ROL_ACC(0x2A, Mnemonic6502.ROL, ACCUMULATOR),
    ANC_IMM_2B(0x2B, Mnemonic6502.ANC, IMMEDIATE, true, STABLE),
    BIT_ABS(0x2C, Mnemonic6502.BIT, ABSOLUTE),
    AND_ABS(0x2D, Mnemonic6502.AND, ABSOLUTE),
    ROL_ABS(0x2E, Mnemonic6502.ROL, ABSOLUTE),
    RLA_ABS(0x2F, Mnemonic6502.RLA, ABSOLUTE, true, STABLE),
    BMI_REL(0x30, Mnemonic6502.BMI, RELATIVE),
    AND_INY(0x31, Mnemonic6502.AND, INDIRECT_INDEXED_Y),
    JAM_IMP_32(0x32, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    RLA_INY(0x33, Mnemonic6502.RLA, INDIRECT_INDEXED_Y, true, STABLE),
    NOP_ZPX_34(0x34, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, STABLE),
    AND_ZPX(0x35, Mnemonic6502.AND, ZERO_PAGE_INDEXED_X),
    ROL_ZPX(0x36, Mnemonic6502.ROL, ZERO_PAGE_INDEXED_X),
    RLA_ZPX(0x37, Mnemonic6502.RLA, ZERO_PAGE_INDEXED_X, true, STABLE),
    SEC_IMP(0x38, Mnemonic6502.SEC, IMPLIED),
    AND_ABY(0x39, Mnemonic6502.AND, ABSOLUTE_INDEXED_Y),
    NOP_IMP_3A(0x3A, Mnemonic6502.NOP, IMPLIED, true, STABLE),
    RLA_ABY(0x3B, Mnemonic6502.RLA, ABSOLUTE_INDEXED_Y, true, STABLE),
    NOP_ABX_3C(0x3C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, STABLE),
    AND_ABX(0x3D, Mnemonic6502.AND, ABSOLUTE_INDEXED_X),
    ROL_ABX(0x3E, Mnemonic6502.ROL, ABSOLUTE_INDEXED_X),
    RLA_ABX(0x3F, Mnemonic6502.RLA, ABSOLUTE_INDEXED_X, true, STABLE),
    RTI_IMP(0x40, Mnemonic6502.RTI, IMPLIED),
    EOR_INX(0x41, Mnemonic6502.EOR, INDEXED_X_INDIRECT),
    JAM_IMP_42(0x42, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    SRE_INX(0x43, Mnemonic6502.SRE, INDEXED_X_INDIRECT, true, STABLE),
    NOP_ZPG_44(0x44, Mnemonic6502.NOP, ZERO_PAGE, true, STABLE),
    EOR_ZPG(0x45, Mnemonic6502.EOR, ZERO_PAGE),
    LSR_ZPG(0x46, Mnemonic6502.LSR, ZERO_PAGE),
    SRE_ZPG(0x47, Mnemonic6502.SRE, ZERO_PAGE, true, STABLE),
    PHA_IMP(0x48, Mnemonic6502.PHA, IMPLIED),
    EOR_IMM(0x49, Mnemonic6502.EOR, IMMEDIATE),
    LSR_ACC(0x4A, Mnemonic6502.LSR, ACCUMULATOR),
    ALR_IMM(0x4B, Mnemonic6502.ALR, IMMEDIATE, true, STABLE),
    JMP_ABS(0x4C, Mnemonic6502.JMP, ABSOLUTE),
    EOR_ABS(0x4D, Mnemonic6502.EOR, ABSOLUTE),
    LSR_ABS(0x4E, Mnemonic6502.LSR, ABSOLUTE),
    SRE_ABS(0x4F, Mnemonic6502.SRE, ABSOLUTE, true, STABLE),
    BVC_REL(0x50, Mnemonic6502.BVC, RELATIVE),
    EOR_INY(0x51, Mnemonic6502.EOR, INDIRECT_INDEXED_Y),
    JAM_IMP_52(0x52, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    SRE_INY(0x53, Mnemonic6502.SRE, INDIRECT_INDEXED_Y, true, null),
    NOP_ZPX(0x54, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    EOR_ZPX(0x55, Mnemonic6502.EOR, ZERO_PAGE_INDEXED_X),
    LSR_ZPX(0x56, Mnemonic6502.LSR, ZERO_PAGE_INDEXED_X),
    SRE_ZPX(0x57, Mnemonic6502.SRE, ZERO_PAGE_INDEXED_X, true, null),
    CLI_IMP(0x58, Mnemonic6502.CLI, IMPLIED),
    EOR_ABY(0x59, Mnemonic6502.EOR, ABSOLUTE_INDEXED_Y),
    NOP_IMP_5A(0x5A, Mnemonic6502.NOP, IMPLIED, true, null),
    SRE_ABY(0x5B, Mnemonic6502.SRE, ABSOLUTE_INDEXED_Y, true, null),
    NOP_ABX_53(0x5C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    EOR_ABX(0x5D, Mnemonic6502.EOR, ABSOLUTE_INDEXED_X),
    LSR_ABX(0x5E, Mnemonic6502.LSR, ABSOLUTE_INDEXED_X),
    SRE_ABX(0x5F, Mnemonic6502.SRE, ABSOLUTE_INDEXED_X, true, null),
    RTS_IMP(0x60, Mnemonic6502.RTS, IMPLIED),
    ADC_INX(0x61, Mnemonic6502.ADC, INDEXED_X_INDIRECT),
    JAM_IMP_62(0x62, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    RRA_INX(0x63, Mnemonic6502.RRA, INDEXED_X_INDIRECT, true, STABLE),
    NOP_ZPG_64(0x64, Mnemonic6502.NOP, ZERO_PAGE, true, STABLE),
    ADC_ZPG(0x65, Mnemonic6502.ADC, ZERO_PAGE),
    ROR_ZPG(0x66, Mnemonic6502.ROR, ZERO_PAGE),
    RRA_ZPG(0x67, Mnemonic6502.RRA, ZERO_PAGE, true, null),
    PLA_IMP(0x68, Mnemonic6502.PLA, IMPLIED),
    ADC_IMM(0x69, Mnemonic6502.ADC, IMMEDIATE),
    ROR_ACC(0x6A, Mnemonic6502.ROR, ACCUMULATOR),
    ARR_IMM(0x6B, Mnemonic6502.ARR, IMMEDIATE, true, null),
    JMP_IND(0x6C, Mnemonic6502.JMP, INDIRECT),
    ADC_ABS(0x6D, Mnemonic6502.ADC, ABSOLUTE),
    ROR_ABS(0x6E, Mnemonic6502.ROR, ABSOLUTE),
    RRA_ABS(0x6F, Mnemonic6502.RRA, ABSOLUTE, true, null),
    BVS_REL(0x70, Mnemonic6502.BVS, RELATIVE),
    ADC_INY(0x71, Mnemonic6502.ADC, INDIRECT_INDEXED_Y),
    JAM_IMP_72(0x72, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    RRA_INY(0x73, Mnemonic6502.RRA, INDIRECT_INDEXED_Y, true, null),
    NOP_ZPX_74(0x74, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, STABLE),
    ADC_ZPX(0x75, Mnemonic6502.ADC, ZERO_PAGE_INDEXED_X),
    ROR_ZPX(0x76, Mnemonic6502.ROR, ZERO_PAGE_INDEXED_X),
    RRA_ZPX(0x77, Mnemonic6502.RRA, ZERO_PAGE_INDEXED_X, true, null),
    SEI_IMP(0x78, Mnemonic6502.SEI, IMPLIED),
    ADC_ABY(0x79, Mnemonic6502.ADC, ABSOLUTE_INDEXED_Y),
    NOP_IMP_7A(0x7A, Mnemonic6502.NOP, IMPLIED, true, null),
    RRA_ABY(0x7B, Mnemonic6502.RRA, ABSOLUTE_INDEXED_Y, true, null),
    NOP_ABX_7C(0x7C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    ADC_ABX(0x7D, Mnemonic6502.ADC, ABSOLUTE_INDEXED_X),
    ROR_ABX(0x7E, Mnemonic6502.ROR, ABSOLUTE_INDEXED_X),
    RRA_ABX(0x7F, Mnemonic6502.RRA, ABSOLUTE_INDEXED_X, true, null),
    NOP_IMM(0x80, Mnemonic6502.NOP, IMMEDIATE, true, null),
    STA_INX(0x81, Mnemonic6502.STA, INDEXED_X_INDIRECT),
    NOP_IMM_82(0x82, Mnemonic6502.NOP, IMMEDIATE, true, null),
    SAX_INX(0x83, Mnemonic6502.SAX, INDEXED_X_INDIRECT, true, null),
    STY_ZPG(0x84, Mnemonic6502.STY, ZERO_PAGE),
    STA_ZPG(0x85, Mnemonic6502.STA, ZERO_PAGE),
    STX_ZPG(0x86, Mnemonic6502.STX, ZERO_PAGE),
    SAX_ZPG(0x87, Mnemonic6502.SAX, ZERO_PAGE, true, null),
    DEY_IMP(0x88, Mnemonic6502.DEY, IMPLIED),
    NOP_IMM_89(0x89, Mnemonic6502.NOP, IMMEDIATE, true, null),
    TXA_IMP(0x8A, Mnemonic6502.TXA, IMPLIED),
    ANE_IMM(0x8B, Mnemonic6502.ANE, IMMEDIATE, true, HIGHLY_UNSTABLE),
    STY_ABS(0x8C, Mnemonic6502.STY, ABSOLUTE),
    STA_ABS(0x8D, Mnemonic6502.STA, ABSOLUTE),
    STX_ABS(0x9E, Mnemonic6502.STX, ABSOLUTE),
    SAX_ABS(0x8F, Mnemonic6502.SAX, ABSOLUTE, true, null),
    BCC_REL(0x90, Mnemonic6502.BCC, RELATIVE),
    STA_INY(0x91, Mnemonic6502.STA, INDIRECT_INDEXED_Y),
    JAM_IMP_92(0x92, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    SHA_INY(0x93, Mnemonic6502.SHA, INDIRECT_INDEXED_Y, true, UNSTABLE),
    STY_ZPX(0x94, Mnemonic6502.STY, ZERO_PAGE_INDEXED_X),
    STA_ZPX(0x95, Mnemonic6502.STA, ZERO_PAGE_INDEXED_X),
    STX_ZPY(0x96, Mnemonic6502.STX, ZERO_PAGE_INDEXED_Y),
    SAX_ZPY(0x97, Mnemonic6502.SAX, ZERO_PAGE_INDEXED_Y, true, null),
    TYA_IMP(0x98, Mnemonic6502.TYA, IMPLIED),
    STA_ABY(0x99, Mnemonic6502.STA, ABSOLUTE_INDEXED_Y),
    TXS_IMP(0x9A, Mnemonic6502.TXS, IMPLIED),
    TAS_ABY(0x9B, Mnemonic6502.TAS, ABSOLUTE_INDEXED_Y, true, UNSTABLE),
    SHY_ABX(0x9C, Mnemonic6502.SHY, ABSOLUTE_INDEXED_X, true, UNSTABLE),
    STA_ABX(0x9D, Mnemonic6502.STA, ABSOLUTE_INDEXED_X),
    SHX_ABY(0x9E, Mnemonic6502.SHX, ABSOLUTE_INDEXED_Y, true, UNSTABLE),
    SHA_ABY(0x9F, Mnemonic6502.SHA, ABSOLUTE_INDEXED_Y, true, UNSTABLE),
    LDY_IMM(0xA0, Mnemonic6502.LDY, IMMEDIATE),
    LDA_INX(0xA1, Mnemonic6502.LDA, INDEXED_X_INDIRECT),
    LDX_IMM(0xA2, Mnemonic6502.LDX, IMMEDIATE),
    LAX_INX(0xA3, Mnemonic6502.LAX, INDEXED_X_INDIRECT, true, null),
    LDY_ZPG(0xA4, Mnemonic6502.LDY, ZERO_PAGE),
    LDA_ZPG(0xA5, Mnemonic6502.LDA, ZERO_PAGE),
    LDX_ZPG(0xA6, Mnemonic6502.LDX, ZERO_PAGE),
    LAX_ZPG(0xA7, Mnemonic6502.LAX, ZERO_PAGE, true, null),
    TAY_IMP(0xA8, Mnemonic6502.TAY, IMPLIED),
    LDA_IMM(0xA9, Mnemonic6502.LDA, IMMEDIATE),
    TAX_IMP(0xAA, Mnemonic6502.TAX, IMPLIED),
    LXA_IMM(0xAB, Mnemonic6502.LXA, IMMEDIATE, true, HIGHLY_UNSTABLE),
    LDY_ABS(0xAC, Mnemonic6502.LDY, ABSOLUTE),
    LDA_ABS(0xAD, Mnemonic6502.LDA, ABSOLUTE),
    LDX_ABS(0xAE, Mnemonic6502.LDX, ABSOLUTE),
    LAX_ABS(0xAF, Mnemonic6502.LAX, ABSOLUTE, true, null),
    BCS_REL(0xB0, Mnemonic6502.BCS, RELATIVE),
    LDA_INY(0xB1, Mnemonic6502.LDA, INDIRECT_INDEXED_Y),
    JAM_IMP_B2(0xB2, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    LAX_INY(0xB3, Mnemonic6502.LAX, INDIRECT_INDEXED_Y, true, null),
    LDY_ZPX(0xB4, Mnemonic6502.LDY, ZERO_PAGE_INDEXED_X),
    LDA_ZPX(0xB5, Mnemonic6502.LDA, ZERO_PAGE_INDEXED_X),
    LDX_ZPY(0xB6, Mnemonic6502.LDA, ZERO_PAGE_INDEXED_Y),
    LAX_ZPY(0xB7, Mnemonic6502.LAX, ZERO_PAGE_INDEXED_Y, true, null),
    CLV_IMP(0xB8, Mnemonic6502.CLV, IMPLIED),
    LDA_ABY(0xB9, Mnemonic6502.LDA, ABSOLUTE_INDEXED_Y),
    TSX_IMP(0xBA, Mnemonic6502.TSX, IMPLIED),
    LAS_ABY(0xBB, Mnemonic6502.LAS, ABSOLUTE_INDEXED_Y, true, null),
    LDY_ABX(0xBC, Mnemonic6502.LDY, ABSOLUTE_INDEXED_X),
    LDA_ABX(0xBD, Mnemonic6502.LDA, ABSOLUTE_INDEXED_X),
    LDX_ABY(0xBE, Mnemonic6502.LDX, ABSOLUTE_INDEXED_Y),
    LAX_ABY(0xBF, Mnemonic6502.LAX, ABSOLUTE_INDEXED_Y, true, null),
    CPY_IMM(0xC0, Mnemonic6502.CPY, IMMEDIATE),
    CMP_INX(0xC1, Mnemonic6502.CMP, INDEXED_X_INDIRECT),
    NOP_IMM_C2(0xC2, Mnemonic6502.NOP, IMMEDIATE, true, null),
    DCP_INX(0xC3, Mnemonic6502.DCP, INDEXED_X_INDIRECT, true, null),
    CPY_ZPG(0xC4, Mnemonic6502.CPY, ZERO_PAGE),
    CMP_ZPG(0xC5, Mnemonic6502.CMP, ZERO_PAGE),
    DEC_ZPG(0xC6, Mnemonic6502.DEC, ZERO_PAGE),
    DCP_ZPG(0xC7, Mnemonic6502.DCP, ZERO_PAGE, true, null),
    INY_IMP(0xC8, Mnemonic6502.INY, IMPLIED),
    CMP_IMM(0xC9, Mnemonic6502.CMP, IMMEDIATE),
    DEX_IMP(0xCA, Mnemonic6502.DEX, IMPLIED),
    SBX_IMM(0xCB, Mnemonic6502.SBX, IMMEDIATE, true, null),
    CPY_ABS(0xCC, Mnemonic6502.CPY, ABSOLUTE),
    CMP_ABS(0xCD, Mnemonic6502.CMP, ABSOLUTE),
    DEC_ABS(0xCE, Mnemonic6502.DEC, ABSOLUTE),
    DCP_ABS(0xCF, Mnemonic6502.DCP, ABSOLUTE, true, null),
    BNE_REL(0xD0, Mnemonic6502.BNE, RELATIVE),
    CMP_INY(0xD1, Mnemonic6502.CMP, INDIRECT_INDEXED_Y),
    JAM_IMP_D2(0xD2, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    DCP_INY(0xD3, Mnemonic6502.DCP, INDIRECT_INDEXED_Y, true, null),
    NOP_ZPX_D4(0xD4, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    CMP_ZPX(0xD5, Mnemonic6502.CMP, ZERO_PAGE_INDEXED_X),
    DEC_ZPX(0xD6, Mnemonic6502.DEC, ZERO_PAGE_INDEXED_X),
    DCP_ZPX(0xD7, Mnemonic6502.DCP, ZERO_PAGE_INDEXED_X, true, null),
    CLD_IMP(0xD8, Mnemonic6502.CLD, IMPLIED),
    CMP_ABY(0xD9, Mnemonic6502.CMP, ABSOLUTE_INDEXED_Y),
    NOP_IMP_DA(0xDA, Mnemonic6502.NOP, IMPLIED, true, null),
    DCP_ABY(0xDB, Mnemonic6502.DCP, ABSOLUTE_INDEXED_Y, true, null),
    NOP_ABX_DC(0xDC, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    CMP_ABX(0xDD, Mnemonic6502.CMP, ABSOLUTE_INDEXED_X),
    DEC_ABX(0xDE, Mnemonic6502.DEC, ABSOLUTE_INDEXED_X),
    DCP_ABX(0xDF, Mnemonic6502.DCP, ABSOLUTE_INDEXED_X, true, null),
    CPX_IMM(0xE0, Mnemonic6502.CPX, IMMEDIATE),
    SBC_INX(0xE1, Mnemonic6502.SBC, INDEXED_X_INDIRECT),
    NOP_IMM_E2(0xE2, Mnemonic6502.NOP, IMMEDIATE, true, null),
    ISC_INX(0xE3, Mnemonic6502.ISC, INDEXED_X_INDIRECT, true, null),
    CPX_ZPG(0xE3, Mnemonic6502.CPX, ZERO_PAGE),
    SBC_ZPG(0xE4, Mnemonic6502.SBC, ZERO_PAGE),
    INC_ZPG(0xE5, Mnemonic6502.INC, ZERO_PAGE),
    ISC_ZPG(0xE6, Mnemonic6502.ISC, ZERO_PAGE, true, null),
    INX_IMP(0xE7, Mnemonic6502.INX, IMPLIED),
    SBC_IMM(0xE8, Mnemonic6502.SBC, IMMEDIATE),
    NOP_IMP(0xEA, Mnemonic6502.NOP, IMPLIED),
    SBC_IMM_EB(0xEB, Mnemonic6502.SBC, IMMEDIATE, true, null),
    CPX_ABS(0xEC, Mnemonic6502.CPX, ABSOLUTE),
    SBC_ABS(0xED, Mnemonic6502.SBC, ABSOLUTE),
    INC_ABS(0xEE, Mnemonic6502.INC, ABSOLUTE),
    ISC_ABS(0xEF, Mnemonic6502.ISC, ABSOLUTE, true, null),
    BEQ_REL(0xF0, Mnemonic6502.BEQ, RELATIVE),
    SBC_INY(0xF1, Mnemonic6502.SBC, INDIRECT_INDEXED_Y),
    JAM_IMP_F2(0xF2, Mnemonic6502.JAM, IMPLIED, true, KABOOM),
    ISC_INY(0xF3, Mnemonic6502.ISC, INDIRECT_INDEXED_Y, true, null),
    NOP_ZPX_F4(0xF4, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    SBC_ZPX(0xF5, Mnemonic6502.SBC, ZERO_PAGE_INDEXED_X),
    INC_ZPX(0xF6, Mnemonic6502.INC, ZERO_PAGE_INDEXED_X),
    ISC_ZPX(0xF7, Mnemonic6502.ISC, ZERO_PAGE_INDEXED_X, true, null),
    SED_IMP(0xF8, Mnemonic6502.SED, IMPLIED),
    SBC_ABY(0xF9, Mnemonic6502.SBC, ABSOLUTE_INDEXED_Y),
    NOP_IMP_FA(0xFA, Mnemonic6502.NOP, IMPLIED, true, null),
    ISC_ABY(0xFB, Mnemonic6502.ISC, ABSOLUTE_INDEXED_Y, true, null),
    NOP_ABX_FC(0xFC, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    SBC_ABX(0xFD, Mnemonic6502.SBC, ABSOLUTE_INDEXED_X),
    INC_ABX(0xFE, Mnemonic6502.INC, ABSOLUTE_INDEXED_X),
    ISC_ABX(0xFF, Mnemonic6502.ISC, ABSOLUTE_INDEXED_X, true, null)
    ;
//
//    final int opcode;
//    final String mnemonic;
//    final Object[] processorFamily;

    /** . */
    private final int opcode;

    /** . */
    private final Mnemonic6502 mnemonic;

    /** . */
    private final AddressMode6502 addressMode;

    /* TODO: Extra details
    private int clockCycles;

    private int branchExtraCycles;

    private int pageCrossExtraCycles;

    private CpuFlags used;
    private CpuFlags affected;
    private int regsaffected;
    */

    /** . */
    private final boolean illegalInstruction;

    /** . */
    private final OpCodeStability6502 opcodeStability;

    /**
     *
     * @param opcode
     * @param mnemonic
     * @param addressMode
     */
    InstructionSet65XX(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode)
    {
       this(opcode, mnemonic, addressMode, false, STABLE);
    }

    /**
     *
     * @param opcode
     * @param mnemonic
     * @param addressMode
     * @param illegalInstruction
     * @param opcodeStability
     */
    InstructionSet65XX(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode, final boolean illegalInstruction, final OpCodeStability6502 opcodeStability)
    {
        this.opcode = opcode;
        this.mnemonic = mnemonic;
        this.addressMode = addressMode;
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
    public boolean isIllegalInstruction()
    {
        return illegalInstruction;
    }

    /**
     *
     * @return
     */
    public OpCodeStability6502 getOpcodeStability()
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
}
