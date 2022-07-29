package uk.co.jigglesoft.noddy.sgs.cpu.ops;

public enum AddressMode
{
    INVALID_OPCODE,
    IMPLIED,
    ACCUMULAOR,
    IMMEDIATE,
    ABSOLUTE_ZERO_PAGE,
    ABSOLUTE,
    ABSOLUTE_ZP_INDEXED_X,
    ABSOLUTE_ZP_INDEXED_Y,
    ABSOLUTE_INDEXED_X,
    ABSOLUTE_INDEXED_Y,
    RELATIVE,
    INDEXED_INDIRECT_X,
            INDIRECT_INDEXED_Y;

    public int getOperandByteSize() {
        return -1;
    }
}
