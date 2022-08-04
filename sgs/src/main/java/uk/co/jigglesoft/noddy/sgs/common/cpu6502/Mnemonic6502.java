package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

/**
 * .
 */
public enum Mnemonic6502
{
    ADC(true),
    ALR(false),
    ANC(false),
    AND(true),
    ANE(false),
    ARR(false),
    ASL(true),
    BCC(true),
    BCS(true),
    BEQ(true),
    BIT(true),
    BMI(true),
    BNE(true),
    BPL(true),
    BRK(true),
    BVC(true),
    BVS(true),
    CLC(true),
    CLD(true),
    CLI(true),
    CLV(true),
    CMP(true),
    CPX(true),
    CPY(true),
    DCP(false),
    DEC(true),
    DEX(true),
    DEY(true),
    EOR(true),
    INC(true),
    INX(true),
    INY(true),
    ISC(false),
    JAM(false),
    JMP(true),
    JSR(true),
    LAS(false),
    LAX(false),
    LDA(true),
    LDX(true),
    LDY(true),
    LSR(true),
    LXA(false),
    NOP(true),
    ORA(true),
    PHA(true),
    PHP(true),
    PLA(true),
    PLP(true),
    RLA(false),
    ROL(true),
    ROR(true),
    RRA(false),
    RTI(true),
    RTS(true),
    SAX(false),
    SBC(true),
    SBX(false),
    SEC(true),
    SED(true),
    SEI(true),
    SHA(false),
    SHX(false),
    SHY(false),
    SLO(false),
    SRE(false),
    STA(true),
    STX(true),
    STY(true),
    TAS(false),
    TAX(true),
    TAY(true),
    TSX(true),
    TXA(true),
    TXS(true),
    TYA(true);

    /** . */
    private final boolean standardOpcode;

    /**
     *
     * @param standardOpcode
     */
    Mnemonic6502(final boolean standardOpcode)
    {
        this.standardOpcode = standardOpcode;
    }

    /**
     *
     * @return
     */
    public boolean isStandardOpcode()
    {
        return standardOpcode;
    }
}

