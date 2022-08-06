package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import java.util.Objects;

/**
 * The addressing modes of the 65XX Microprocessor Family.
 */
public enum AddressMode6502
{
    /** Implied addressing - the data and/or destination is mandatory for the instruction. */
    IMPLIED(0, "IMP"),

    /** Accummulator addressing - the A (accummulator) register is the target. */
    ACCUMULATOR(0, "ACC"),

    /** Immediate addressing - the byte following the opcode is the literal data value. */
    IMMEDIATE(1, "IMM"),

    /** Relative addressing - the byte following the opcode is a PC (program counter) relative address. */
    RELATIVE(1, "REL"),

    /** Absolute Zero Page addressing - FIXME. */
    ZERO_PAGE(1, "ZPG"),

    /** Absolute addressing - FIXME. */
    ABSOLUTE(2, "ABS"),

    /** Indirect addressing - FIXME. */
    INDIRECT(2, "IND"),

    /** Zero Page X Indexed addressing - FIXME. */
    ZERO_PAGE_INDEXED_X(1, "ZPX"),

    /** Zero Page Y Indexed addressing - FIXME. */
    ZERO_PAGE_INDEXED_Y(1, "ZPY"),

    /** Absolute X Indexed addressing - FIXME. */
    ABSOLUTE_INDEXED_X(2, "ABX"),

    /** Absolute Y Indexed addressing - FIXME. */
    ABSOLUTE_INDEXED_Y(2, "ABY"),

    /** Zero Page X Indexed, Indirect addressing - FIXME. */
    INDEXED_X_INDIRECT(1, "XIN"),

    /** Zero Page Indirect, Y Indexed addressing - FIXME. */
    INDIRECT_INDEXED_Y(1, "INY");

    /** Operand byte size. */
    private final int operandByteSize;

    /** Addressing mode three letter abbreviation. */
    private final String abbreviation;

    /**
     *
     * @param operandByteSize
     */
    AddressMode6502(final int operandByteSize, final String abbreviation)
    {
        Objects.requireNonNull(abbreviation);

        this.operandByteSize = operandByteSize;
        this.abbreviation = abbreviation;
    }

    /**
     * Get the operand byte size if it can be determined from the addressing mode.
     * @return
     */
    public int getOperandByteSize()
    {
        return operandByteSize;
    }

    /**
     * Get the operand byte size if it can be determined from the addressing mode.
     * @return
     */
    public String getAbbreviation()
    {
        return abbreviation;
    }
}
