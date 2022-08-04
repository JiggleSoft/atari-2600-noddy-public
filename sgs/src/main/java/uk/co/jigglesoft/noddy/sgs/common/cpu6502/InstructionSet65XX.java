package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502.*;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.OpCodeStability6502.*;

public enum InstructionSet65XX
{
    BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED),
    ORA_INX(0x01, Mnemonic6502.ORA, ABSOLUTE_INDEXED_X);
    ORA_INX STD
    JAM_IMP JAM_IMP ILL
    SLO_INX ILL
    NOP_ZPG ILL
    ORA_ZPG STD
    ASL_ZPG STD
    SLO_ZPG ILL
    PHP_IMP STD
    ORA_IMM STD
    ASL_ACC STD
    ANC_IMM ILL
    NOP_ABS ILL
    ORA_ABS STD
    ASL_ABS STD
    SLO_ABS ILL
    BPL_REL STD
    ORA_INY STD
    JAM_IMP ILL
    SLO_INY ILL
    NOP_ZPX ILL
    ORA_ZPX STD
    ASL_ZPX STD
    SLO_ZPX ILL
    CLC_IMP STD
    ORA_ABY STD
    NOP_IMP ILL
    SLO_ABY ILL
    NOP_ABX ILL
    ORA_ABX STD
    ASL_ABX STD
    SLO_ABX ILL
    JSR_ABS STD
    AND_INX STD
    JAM_IMP ILL
    RLA_INX ILL
    BIT_ZPG STD
    AND_ZPG STD
    ROL_ZPG STD
    RLA_ZPG ILL
    PLP_IMP STD
    AND_IMM STD
    ROL_ACC STD
    ANC_IMM ILL
    BIT_ABS STD
    AND_ABS STD
    ROL_ABS STD
    RLA_ABS ILL
    BMI_REL STD
    AND_INY STD
    JAM_IMP ILL
    RLA_INY ILL
    NOP_ZPX ILL
    AND_ZPX STD
    ROL_ZPX STD
    RLA_ZPX ILL
    SEC_IMP STD
    AND_ABY STD
    NOP_IMP ILL
    RLA_ABY ILL
    NOP_ABX ILL
    AND_ABX STD
    ROL_ABX STD
    RLA_ABX ILL
    RTI_IMP STD
    EOR_INX STD
    JAM_IMP ILL
    SRE_INX ILL
    NOP_ZPG ILL
    EOR_ZPG STD
    LSR_ZPG STD
    SRE_ZPG ILL
    PHA_IMP STD
    EOR_IMM STD
    LSR_ACC STD
    ALR_IMM ILL
    JMP_ABS STD
    EOR_ABS STD
    LSR_ABS STD
    SRE_ABS ILL
    BVC_REL STD
    EOR_INY STD
    JAM_IMP ILL
    SRE_INY ILL
    NOP_ZPX ILL
    EOR_ZPX STD
    LSR_ZPX STD
    SRE_ZPX ILL
    CLI_IMP STD
    EOR_ABY STD
    NOP_IMP ILL
    SRE_ABY ILL
    NOP_ABX ILL
    EOR_ABX STD
    LSR_ABX STD
    SRE_ABX ILL
    RTS_IMP STD
    ADC_INX STD
    JAM_IMP ILL
    RRA_INX ILL
    NOP_ZPG ILL
    ADC_ZPG STD
    ROR_ZPG STD
    RRA_ZPG ILL
    PLA_IMP STD
    ADC_IMM STD
    ROR_ACC STD
    ARR_IMM ILL
    JMP_IND STD
    ADC_ABS STD
    ROR_ABS STD
    RRA_ABS ILL
    BVS_REL STD
    ADC_INY STD
    JAM_IMP ILL
    RRA_INY ILL
    NOP_ZPX ILL
    ADC_ZPX STD
    ROR_ZPX STD
    RRA_ZPX ILL
    SEI_IMP STD
    ADC_ABY STD
    NOP_IMP ILL
    RRA_ABY ILL
    NOP_ABX ILL
    ADC_ABX STD
    ROR_ABX STD
    RRA_ABX ILL
    NOP_IMM ILL
    STA_INX STD
    NOP_IMM ILL
    SAX_INX ILL
    STY_ZPG STD
    STA_ZPG STD
    STX_ZPG STD
    SAX_ZPG ILL
    DEY_IMP STD
    NOP_IMM ILL
    TXA_IMP STD
    ANE_IMM ILL
    STY_ABS STD
    STA_ABS STD
    STX_ABS STD
    SAX_ABS ILL
    BCC_REL STD
    STA_INY STD
    JAM_IMP ILL
    SHA_INY ILL
    STY_ZPX STD
    STA_ZPX STD
    STX_ZPY STD
    SAX_ZPY ILL
    TYA_IMP STD
    STA_ABY STD
    TXS_IMP STD
    TAS_ABY ILL
    SHY_ABX ILL
    STA_ABX STD
    SHX_ABY ILL
    SHA_ABY ILL
    LDY_IMM STD
    LDA_INX STD
    LDX_IMM STD
    LAX_INX ILL
    LDY_ZPG STD
    LDA_ZPG STD
    LDX_ZPG STD
    LAX_ZPG ILL
    TAY_IMP STD
    LDA_IMM STD
    TAX_IMP STD
    LXA_IMM ILL
    LDY_ABS STD
    LDA_ABS STD
    LDX_ABS STD
    LAX_ABS ILL
    BCS_REL STD
    LDA_INY STD
    JAM_IMP ILL
    LAX_INY ILL
    LDY_ZPX STD
    LDA_ZPX STD
    LDX_ZPY STD
    LAX_ZPY ILL
    CLV_IMP STD
    LDA_ABY STD
    TSX_IMP STD
    LAS_ABY ILL
    LDY_ABX STD
    LDA_ABX STD
    LDX_ABY STD
    LAX_ABY ILL
    CPY_IMM STD
    CMP_INX STD
    NOP_IMM ILL
    DCP_INX ILL
    CPY_ZPG STD
    CMP_ZPG STD
    DEC_ZPG STD
    DCP_ZPG ILL
    INY_IMP STD
    CMP_IMM STD
    DEX_IMP STD
    SBX_IMM ILL
    CPY_ABS STD
    CMP_ABS STD
    DEC_ABS STD
    DCP_ABS ILL
    BNE_REL STD
    CMP_INY STD
    JAM_IMP ILL
    DCP_INY ILL
    NOP_ZPX ILL
    CMP_ZPX STD
    DEC_ZPX STD
    DCP_ZPX ILL
    CLD_IMP STD
    CMP_ABY STD
    NOP_IMP ILL
    DCP_ABY ILL
    NOP_ABX ILL
    CMP_ABX STD
    DEC_ABX STD
    DCP_ABX ILL
    CPX_IMM STD
    SBC_INX STD
    NOP_IMM ILL
    ISC_INX ILL
    CPX_ZPG STD
    SBC_ZPG STD
    INC_ZPG STD
    ISC_ZPG ILL
    INX_IMP STD
    SBC_IMM STD
    NOP_IMP STD
    SBC_IMM ILL
    CPX_ABS STD
    SBC_ABS STD
    INC_ABS STD
    ISC_ABS ILL
    BEQ_REL STD
    SBC_INY STD
    JAM_IMP ILL
    ISC_INY ILL
    NOP_ZPX ILL
    SBC_ZPX STD
    INC_ZPX STD
    ISC_ZPX ILL
    SED_IMP STD
    SBC_ABY STD
    NOP_IMP ILL
    ISC_ABY ILL
    NOP_ABX ILL
    SBC_ABX STD
    INC_ABX STD
    ISC_ABX ILL
    BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED),
    ORA_IXI(0x01, Mnemonic6502.ORA, INDEXED_X_INDIRECT),
    ORA_ZP(0x05, Mnemonic6502.ORA, null);
//    BRK (0x00, "BRK", null, IMPLIED),    ORA(ABSOLUTE_ZP_INDEXED_X),   X02(INVALID_OPCODE),    X03(INVALID_OPCODE),    X04(INVALID_OPCODE),
//    BPL (RELATIVE)
//    ;
//
//    final int opcode;
//    final String mnemonic;
//    final Object[] processorFamily;

    private final int opcode;
    private final Mnemonic6502 mnemonic;
    private final AddressMode6502 addressMode;
    private final boolean illegalInstruction;
    private final OpCodeStability6502 opcodeStability;

    InstructionSet65XX(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode)
    {
       this(opcode, mnemonic, addressMode, false, STABLE);
    }

    InstructionSet65XX(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode, final boolean illegalInstruction, final OpCodeStability6502 opcodeStability)
    {
        this.opcode = opcode;
        this.mnemonic = mnemonic;
        this.addressMode = addressMode;
        this.illegalInstruction = illegalInstruction;
        this.opcodeStability = opcodeStability;
    }

    final int getOpcode()
    {
        return opcode;
    }

    final Mnemonic6502 getMnemonic() { return mnemonic };

    final AddressMode6502 getAddressMode()
    {
        return addressMode;
    }

    public boolean isIllegalInstruction() {
        return illegalInstruction;
    }

    public OpCodeStability6502 getOpcodeStability() {
        return opcodeStability;
    }

    final int getOpcodeByteSize()
    {
        return 1;
    }

    final int getOperandByteSize()
    {
        return addressMode.getOperandByteSize();
    }
}
