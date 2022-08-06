package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502.*;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.OpCodeStability6502.*;

/**
 *
 */
public enum InstructionSet65XX
{
    BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED),
    ORA_INX(0x01, Mnemonic6502.ORA, ABSOLUTE_INDEXED_X),
    JAM_IMP(0x02, Mnemonic6502.JAM, IMPLIED, true, null),
    SLO_INX(0x03, Mnemonic6502.SLO, INDEXED_X_INDIRECT, true, null),
    NOP_ZPG(0x04, Mnemonic6502.NOP, ZERO_PAGE, true, null),
    ORA_ZPG(0x05, Mnemonic6502.ORA, ZERO_PAGE),
    ASL_ZPG(0x06, Mnemonic6502.ASL, ZERO_PAGE),
    SLO_ZPG(0x07, Mnemonic6502.SLO, ZERO_PAGE, true, null),
    PHP_IMP(0x08, Mnemonic6502.PHP, IMPLIED),
    ORA_IMM(0x09, Mnemonic6502.ORA, IMMEDIATE),
    ASL_ACC(0x0A, Mnemonic6502.ASL, ACCUMULATOR),
    ANC_IMM(0x0B, Mnemonic6502.ANC, IMMEDIATE, true, null),
    NOP_ABS(0x0C, Mnemonic6502.NOP, ABSOLUTE, true, null),
    ORA_ABS(0x0D, Mnemonic6502.ORA, ABSOLUTE),
    ASL_ABS(0x0E, Mnemonic6502.ASL, ABSOLUTE),
    SLO_ABS(0x0F, Mnemonic6502.SLO, ABSOLUTE, true, null),
    BPL_REL(0x10, Mnemonic6502.BPL, RELATIVE),
    ORA_INY(0x11, Mnemonic6502.ORA, INDIRECT_INDEXED_Y),
//    JAM_IMP(0x12, Mnemonic6502.JAM, IMPLIED, true, null),
    SLO_INY(0x13, Mnemonic6502.SLO, INDIRECT_INDEXED_Y, true, null),
    NOP_ZPX(0x14, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    ORA_ZPX(0x15, Mnemonic6502.ORA, ZERO_PAGE_INDEXED_X),
    ASL_ZPX(0x16, Mnemonic6502.ASL, ZERO_PAGE_INDEXED_X),
    SLO_ZPX(0x17, Mnemonic6502.SLO, ZERO_PAGE_INDEXED_X, true, null),
    CLC_IMP(0x18, Mnemonic6502.CLC, IMPLIED),
    ORA_ABY(0x19, Mnemonic6502.ORA, ABSOLUTE_INDEXED_Y),
    NOP_IMP(0x1A, Mnemonic6502.NOP, IMPLIED, true, null),
    SLO_ABY(0x1B, Mnemonic6502.SLO, ABSOLUTE_INDEXED_Y, true, null),
    NOP_ABX(0x1C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    ORA_ABX(0x1D, Mnemonic6502.ORA, ABSOLUTE_INDEXED_X),
    ASL_ABX(0x1E, Mnemonic6502.ASL, ABSOLUTE_INDEXED_X),
    SLO_ABX(0x1F, Mnemonic6502.SLO, ABSOLUTE_INDEXED_X, true, null),
    JSR_ABS(0x20, Mnemonic6502.JSR, ABSOLUTE),
    AND_INX(0x21, Mnemonic6502.AND, INDEXED_X_INDIRECT),
//    JAM_IMP(0x22, Mnemonic6502.JAM, IMPLIED, true, null),
    RLA_INX(0x23, Mnemonic6502.RLA, INDEXED_X_INDIRECT, true, null),
    BIT_ZPG(0x24, Mnemonic6502.BIT, ZERO_PAGE),
    AND_ZPG(0x25, Mnemonic6502.AND, ZERO_PAGE),
    ROL_ZPG(0X26, Mnemonic6502.ROL, ZERO_PAGE),
    RLA_ZPG(0X27, Mnemonic6502.RLA, ZERO_PAGE, true, null),
    PLP_IMP(0X28, Mnemonic6502.PLP, IMPLIED),
    AND_IMM(0X29, Mnemonic6502.AND, IMMEDIATE),
    ROL_ACC(0X2A, Mnemonic6502.ROL, ACCUMULATOR),
//    ANC_IMM(0X2B, Mnemonic6502.ANC, IMMEDIATE, true, null),
    BIT_ABS(0X2C, Mnemonic6502.BIT, ABSOLUTE),
    AND_ABS(0X2D, Mnemonic6502.AND, ABSOLUTE),
    ROL_ABS(0X2E, Mnemonic6502.ROL, ABSOLUTE),
    RLA_ABS(0X2F, Mnemonic6502.RLA, ABSOLUTE, true, null),
    BMI_REL(0X30, Mnemonic6502.BMI, RELATIVE),
//    AND_INY(0X31, Mnemonic6502.AND, ),
//    JAM_IMP(0X32, Mnemonic6502.JAM, IMPLIED, true, null),
    RLA_INY(0X33, Mnemonic6502.RLA, INDIRECT_INDEXED_Y, true, null),
//    NOP_ZPX(0X34, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    AND_ZPX(0X35, Mnemonic6502.AND, ZERO_PAGE_INDEXED_X),
    ROL_ZPX(0X36, Mnemonic6502.ROL, ZERO_PAGE_INDEXED_X),
    RLA_ZPX(0X37, Mnemonic6502.RLA, ZERO_PAGE_INDEXED_X, true, null),
    SEC_IMP(0X38, Mnemonic6502.SEC, IMPLIED),
    AND_ABY(0X39, Mnemonic6502.AND, ABSOLUTE_INDEXED_Y),
//    NOP_IMP(0X3A, Mnemonic6502.NOP, IMPLIED, true, null),
    RLA_ABY(0X3B, Mnemonic6502.RLA, ABSOLUTE_INDEXED_Y, true, null),
//    NOP_ABX(0X3C, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    AND_ABX(0X3D, Mnemonic6502.AND, ABSOLUTE_INDEXED_X),
    ROL_ABX(0X3E, Mnemonic6502.ROL, ABSOLUTE_INDEXED_X),
    RLA_ABX(0X3F, Mnemonic6502.RLA, ABSOLUTE_INDEXED_X, true, null),
    RTI_IMP(0X40, Mnemonic6502.RTI, IMPLIED),
    EOR_INX(0X41, Mnemonic6502.EOR, INDEXED_X_INDIRECT),
//    JAM_IMP(0X42, Mnemonic6502.JAM, IMPLIED, true, null),
    SRE_INX(0X43, Mnemonic6502.SRE, INDEXED_X_INDIRECT, true, null),
//    NOP_ZPG(0X44, Mnemonic6502.NOP, ZERO_PAGE, true, null),
    EOR_ZPG(0X45, Mnemonic6502.EOR, ZERO_PAGE),
    LSR_ZPG(0X46, Mnemonic6502.LSR, ZERO_PAGE),
    SRE_ZPG(0X47, Mnemonic6502.SRE, ZERO_PAGE, true, null),
    PHA_IMP(0X48, Mnemonic6502.PHA, IMPLIED),
    EOR_IMM(0X49, Mnemonic6502.EOR, IMMEDIATE),
    LSR_ACC(0X4A, Mnemonic6502.LSR, ACCUMULATOR),
    ALR_IMM(0X4B, Mnemonic6502.ALR, IMMEDIATE, true, null),
    JMP_ABS(0X4C, Mnemonic6502.JMP, ABSOLUTE),
    EOR_ABS(0X4D, Mnemonic6502.EOR, ABSOLUTE),
    LSR_ABS(0X4E, Mnemonic6502.LSR, ABSOLUTE),
    SRE_ABS(0X4F, Mnemonic6502.SRE, ABSOLUTE, true, null),
    BVC_REL(0X40, Mnemonic6502.BVC, RELATIVE),
    EOR_INY(0X40, Mnemonic6502.EOR, INDIRECT_INDEXED_Y),
//    JAM_IMP(0X43, Mnemonic6502.JAM, IMPLIED, true, null),
    SRE_INY(0X43, Mnemonic6502.SRE, INDIRECT_INDEXED_Y, true, null),
//    NOP_ZPX(0X53, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    EOR_ZPX(0X50, Mnemonic6502., ),
    LSR_ZPX(0X50, Mnemonic6502., ),
    SRE_ZPX(0X53, Mnemonic6502., true, null),
    CLI_IMP(0X50, Mnemonic6502., ),
    EOR_ABY(0X50, Mnemonic6502., ),
    NOP_IMP(0X53, Mnemonic6502., true, null),
    SRE_ABY(0X53, Mnemonic6502., true, null),
    NOP_ABX(0X53, Mnemonic6502., true, null),
    EOR_ABX(0X50, Mnemonic6502., ),
    LSR_ABX(0X50, Mnemonic6502., ),
    SRE_ABX(0X53, Mnemonic6502., true, null),
    RTS_IMP(0X50, Mnemonic6502.RTS, ),
    ADC_INX(0X50, Mnemonic6502.ADC, ),
    JAM_IMP(0X53, Mnemonic6502.JAM, true, null),
    RRA_INX(0X53, Mnemonic6502.RRA, true, null),
//    NOP_ZPG(0X53, Mnemonic6502.NOP, true, null),
    ADC_ZPG(0X50, Mnemonic6502.ADC, ),
    ROR_ZPG(0X50, Mnemonic6502.ROR, ),
    RRA_ZPG(0X53, Mnemonic6502.RRA, true, null),
    PLA_IMP(0X50, Mnemonic6502.PLA, ),
    ADC_IMM(0X60, Mnemonic6502.ADC, ),
    ROR_ACC(0X60, Mnemonic6502.ROR, ACCUMULATOR),
    ARR_IMM(0X63, Mnemonic6502.ARR, true, null),
    JMP_IND(0X60, Mnemonic6502.JMP, ),
    ADC_ABS(0X60, Mnemonic6502.ADC, ABSOLUTE),
    ROR_ABS(0X60, Mnemonic6502.ROR, ABSOLUTE),
    RRA_ABS(0X63, Mnemonic6502.RRA, ABSOLUTE, true, null),
    BVS_REL(0X60, Mnemonic6502.BVS, ),
    ADC_INY(0X60, Mnemonic6502.ADC, ),
    JAM_IMP(0X63, Mnemonic6502.JAM, true, null),
    RRA_INY(0X63, Mnemonic6502.RRA, true, null),
//    NOP_ZPX(0X63, Mnemonic6502.NOP, true, null),
    ADC_ZPX(0X60, Mnemonic6502.ADC, ),
    ROR_ZPX(0X60, Mnemonic6502.ROR, ),
    RRA_ZPX(0X63, Mnemonic6502.RRA, true, null),
    SEI_IMP(0X60, Mnemonic6502.SEI, ),
    ADC_ABY(0X60, Mnemonic6502.ADC, ),
    NOP_IMP(0X63, Mnemonic6502.NOP, true, null),
    RRA_ABY(0X63, Mnemonic6502.RRA, true, null),
//    NOP_ABX(0X73, Mnemonic6502.NOP, true, null),
    ADC_ABX(0X70, Mnemonic6502.ADC, ),
    ROR_ABX(0X70, Mnemonic6502.ROR, ),
    RRA_ABX(0X73, Mnemonic6502.RRA, true, null),
    NOP_IMM(0X73, Mnemonic6502.NOP, true, null),
    STA_INX(0X70, Mnemonic6502.STA, ),
//    NOP_IMM(0X73, Mnemonic6502.NOP, true, null),
    SAX_INX(0X73, Mnemonic6502.SAX, true, null),
    STY_ZPG(0X70, Mnemonic6502.STY, ),
    STA_ZPG(0X70, Mnemonic6502.STA, ),
    STX_ZPG(0X70, Mnemonic6502.STX, ),
    SAX_ZPG(0X73, Mnemonic6502.SAX, true, null),
    DEY_IMP(0X70, Mnemonic6502.DEY, ),
    NOP_IMM(0X73, Mnemonic6502.NOP, true, null),
    TXA_IMP(0X70, Mnemonic6502.TXA, ),
    ANE_IMM(0X73, Mnemonic6502.ANE, true, null),
    STY_ABS(0X70, Mnemonic6502.STY, ABSOLUTE),
    STA_ABS(0X70, Mnemonic6502.STA, ABSOLUTE),
    STX_ABS(0X70, Mnemonic6502.STX, ABSOLUTE),
    SAX_ABS(0X83, Mnemonic6502.SAX, ABSOLUTE, true, null),
    BCC_REL(0X80, Mnemonic6502.BCC, ),
    STA_INY(0X80, Mnemonic6502.STA, ),
    JAM_IMP(0X83, Mnemonic6502.JAM, true, null),
    SHA_INY(0X83, Mnemonic6502.SHA, true, null),
    STY_ZPX(0X80, Mnemonic6502.STY, ),
    STA_ZPX(0X80, Mnemonic6502.STA, ),
    STX_ZPY(0X80, Mnemonic6502.STX, ),
    SAX_ZPY(0X83, Mnemonic6502.SAX, true, null),
    TYA_IMP(0X80, Mnemonic6502., ),
    STA_ABY(0X80, Mnemonic6502., ),
    TXS_IMP(0X80, Mnemonic6502., ),
    TAS_ABY(0X83, Mnemonic6502., true, null),
    SHY_ABX(0X83, Mnemonic6502., true, null),
    STA_ABX(0X80, Mnemonic6502., ),
    SHX_ABY(0X83, Mnemonic6502., true, null),
    SHA_ABY(0X83, Mnemonic6502., true, null),
    LDY_IMM(0X90, Mnemonic6502., ),
    LDA_INX(0X90, Mnemonic6502., ),
    LDX_IMM(0X90, Mnemonic6502., ),
    LAX_INX(0X93, Mnemonic6502., true, null),
    LDY_ZPG(0X90, Mnemonic6502., ),
    LDA_ZPG(0X90, Mnemonic6502., ),
    LDX_ZPG(0X90, Mnemonic6502., ),
    LAX_ZPG(0X93, Mnemonic6502., true, null),
    TAY_IMP(0X90, Mnemonic6502., ),
    LDA_IMM(0X90, Mnemonic6502., ),
    TAX_IMP(0X90, Mnemonic6502., ),
    LXA_IMM(0X93, Mnemonic6502., true, null),
    LDY_ABS(0X90, Mnemonic6502., ABSOLUTE),
    LDA_ABS(0X90, Mnemonic6502., ABSOLUTE),
    LDX_ABS(0X90, Mnemonic6502., ABSOLUTE),
    LAX_ABS(0X93, Mnemonic6502., ABSOLUTE, true, null),
    BCS_REL(0X90, Mnemonic6502., ),
    LDA_INY(0X90, Mnemonic6502., ),
    JAM_IMP(0XA3, Mnemonic6502., true, null),
    LAX_INY(0xA3, Mnemonic6502., true, null),
    LDY_ZPX(0XA0, Mnemonic6502., ),
    LDA_ZPX(0XA0, Mnemonic6502., ),
    LDX_ZPY(0XA0, Mnemonic6502., ),
    LAX_ZPY(0XA3, Mnemonic6502., true, null),
    CLV_IMP(0XA0, Mnemonic6502., ),
    LDA_ABY(0XA0, Mnemonic6502., ),
    TSX_IMP(0XA0, Mnemonic6502., ),
    LAS_ABY(0XA3, Mnemonic6502., true, null),
    LDY_ABX(0XA0, Mnemonic6502., ),
    LDA_ABX(0XA0, Mnemonic6502., ),
    LDX_ABY(0XA0, Mnemonic6502., ),
    LAX_ABY(0XA3, Mnemonic6502., true, null),
    CPY_IMM(0XA0, Mnemonic6502., ),
    CMP_INX(0XA0, Mnemonic6502., ),
    NOP_IMM(0XA3, Mnemonic6502., true, null),
    DCP_INX(0XB3, Mnemonic6502., true, null),
    CPY_ZPG(0XB0, Mnemonic6502.CPY, ),
    CMP_ZPG(0XB0, Mnemonic6502.CMP, ),
    DEC_ZPG(0XB0, Mnemonic6502.DEC, ),
    DCP_ZPG(0XB3, Mnemonic6502., true, null),
    INY_IMP(0XB0, Mnemonic6502., ),
    CMP_IMM(0XB0, Mnemonic6502., ),
    DEX_IMP(0XB0, Mnemonic6502., ),
    SBX_IMM(0XB3, Mnemonic6502., true, null),
    CPY_ABS(0XB0, Mnemonic6502., ABSOLUTE),
    CMP_ABS(0XB0, Mnemonic6502., ABSOLUTE),
    DEC_ABS(0XB0, Mnemonic6502., ABSOLUTE),
    DCP_ABS(0XB3, Mnemonic6502., ABSOLUTE, true, null),
    BNE_REL(0XB0, Mnemonic6502., ),
    CMP_INY(0XB0, Mnemonic6502., ),
    JAM_IMP(0XB3, Mnemonic6502., true, null),
    DCP_INY(0XB3, Mnemonic6502., true, null),
    NOP_ZPX(0XB3, Mnemonic6502., true, null),
    CMP_ZPX(0XB0, Mnemonic6502., ),
    DEC_ZPX(0XB0, Mnemonic6502., ),
    DCP_ZPX(0XC3, Mnemonic6502., true, null),
    CLD_IMP(0XC0, Mnemonic6502., ),
    CMP_ABY(0XC0, Mnemonic6502., ),
    NOP_IMP(0XC3, Mnemonic6502., true, null),
    DCP_ABY(0XC3, Mnemonic6502., true, null),
    NOP_ABX(0XC3, Mnemonic6502., true, null),
    CMP_ABX(0XC0, Mnemonic6502., ),
    DEC_ABX(0XC0, Mnemonic6502., ),
    DCP_ABX(0XC3, Mnemonic6502., true, null),
    CPX_IMM(0XC0, Mnemonic6502., ),
    SBC_INX(0XC0, Mnemonic6502., ),
    NOP_IMM(0XC3, Mnemonic6502., true, null),
    ISC_INX(0XC3, Mnemonic6502., true, null),
    CPX_ZPG(0XC0, Mnemonic6502., ),
    SBC_ZPG(0XC0, Mnemonic6502., ),
    INC_ZPG(0XD0, Mnemonic6502., ),
    ISC_ZPG(0XD3, Mnemonic6502.ISC, true, null),
    INX_IMP(0XD0, Mnemonic6502.INX, ),
    SBC_IMM(0XD0, Mnemonic6502.SBC, ),
    NOP_IMP(0XD0, Mnemonic6502.NOP, ),
    SBC_IMM(0XD3, Mnemonic6502.SBC, true, null),
    CPX_ABS(0XD0, Mnemonic6502.CPX, ABSOLUTE),
    SBC_ABS(0XD0, Mnemonic6502.SBC, ABSOLUTE),
    INC_ABS(0XD0, Mnemonic6502.INC, ABSOLUTE),
    ISC_ABS(0XD3, Mnemonic6502.ISC, ABSOLUTE, true, null),
    BEQ_REL(0XD0, Mnemonic6502.BEQ, ),
    SBC_INY(0XD0, Mnemonic6502.SBC, ),
    JAM_IMP(0XD3, Mnemonic6502.JAM, IMPLIED, true, null),
    ISC_INY(0XD3, Mnemonic6502.ISC, INDIRECT_INDEXED_Y, true, null),
    NOP_ZPX(0XD3, Mnemonic6502.NOP, ZERO_PAGE_INDEXED_X, true, null),
    SBC_ZPX(0XD0, Mnemonic6502.SBC, ZERO_PAGE_INDEXED_X),
    INC_ZPX(0XD0, Mnemonic6502.INC, ZERO_PAGE_INDEXED_X),
    ISC_ZPX(0x03, Mnemonic6502.ISC, ZERO_PAGE_INDEXED_X, true, null),
    SED_IMP(0x00, Mnemonic6502.SED, IMPLIED),
    SBC_ABY(0x00, Mnemonic6502.SBC, ABSOLUTE_INDEXED_Y),
    NOP_IMP(0x03, Mnemonic6502.NOP, IMPLIED, true, null),
    ISC_ABY(0x03, Mnemonic6502.ISC, ABSOLUTE_INDEXED_Y, true, null),
    NOP_ABX(0x03, Mnemonic6502.NOP, ABSOLUTE_INDEXED_X, true, null),
    SBC_ABX(0x00, Mnemonic6502.SBC, ABSOLUTE_INDEXED_X),
    INC_ABX(0x00, Mnemonic6502.INC, ABSOLUTE_INDEXED_X),
    ISC_ABX(0x03, Mnemonic6502.ISC, ABSOLUTE_INDEXED_X, true, null),
    //BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED),
    ORA_IXI(0x01, Mnemonic6502.ORA, INDEXED_X_INDIRECT),
    ORA_ZP(0x05, Mnemonic6502.ORA, null);
//    BRK (0x00, "BRK", null, IMPLIED),    ORA(ABSOLUTE_ZP_INDEXED_X),   X02(INVALID_OPCODE),    X03(INVALID_OPCODE),    X04(INVALID_OPCODE),
//    BPL (RELATIVE)
//    ;
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
