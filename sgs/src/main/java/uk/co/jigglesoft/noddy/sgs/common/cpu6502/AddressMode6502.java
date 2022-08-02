package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

/**
 * The addressing modes of the 65XX Microprocessor Family.
 */
public enum AddressMode6502
{
    /** This opcode is invalid. */
    //REVIEW: remove this - INVALID_OPCODE(),

    /** Implied addressing - the data and/or destination is mandatory for the instruction. */
    IMPLIED(0),

    /** Accummulator addressing - the A (accummulator) register is the target. */
    ACCUMULATOR(0),

    /** Immediate addressing - the byte following the opcode is the literal data value. */
    IMMEDIATE(1),

    /** Relative addressing - the byte following the opcode is a PC (program counter) relative address. */
    RELATIVE(1),

    /** Absolute Zero Page addressing - FIXME. */
    ZERO_PAGE(1),

    /** Absolute addressing - FIXME. */
    ABSOLUTE(2),

    /** Indirect addressing - FIXME. */
    INDIRECT(2),

    /** Zero Page X Indexed addressing - FIXME. */
    ZERO_PAGE_INDEXED_X(1),

    /** Zero Page Y Indexed addressing - FIXME. */
    ZERO_PAGE_INDEXED_Y(1),

    /** Absolute X Indexed addressing - FIXME. */
    ABSOLUTE_INDEXED_X(2),

    /** Absolute Y Indexed addressing - FIXME. */
    ABSOLUTE_INDEXED_Y(2),

    /** Zero Page X Indexed, Indirect addressing - FIXME. */
    INDEXED_X_INDIRECT(1),

    /** Zero Page Indirect, Y Indexed addressing - FIXME. */
    INDIRECT_INDEXED_Y(1);

    /** Operand byte size. */
    private final int operandByteSize;

    private final String abbreviation;

    /**
     *
     */
    AddressMode6502()
    {
        this(-1, null);
    }

    /**
     *
     * @param operandByteSize
     */
    AddressMode6502(final int operandByteSize, final String abbreviation)
    {
        this.operandByteSize = operandByteSize;this.abbreviation = abbreviation;
    }

    /**
     * Get the operand byte size if it can be determined from the addressing mode.
     * @return
     * @throws UnsupportedOperationException
     */
    public int getOperandByteSize() throws UnsupportedOperationException
    {
        if (operandByteSize == -1)
        {
            throw new UnsupportedOperationException();
        }
        return operandByteSize;
    }

    /**
     * Get the operand byte size if it can be determined from the addressing mode.
     * @return
     * @throws UnsupportedOperationException
     */
    public int getAbbreviation() throws UnsupportedOperationException
    {
        if (abbreviation == null)
        {
            throw new UnsupportedOperationException();
        }
        return abbreviation;
    }
}
