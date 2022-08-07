package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502.*;

class AddressMode65XXTest
{
    @Test
    void values()
    {
        assertEquals(13, AddressMode6502.values().length);
    }

    @Test
    void getOperandByteSize()
    {
        assertEquals(0, IMPLIED.getOperandByteSize());
        assertEquals(0, ACCUMULATOR.getOperandByteSize());
        assertEquals(1, IMMEDIATE.getOperandByteSize());
        assertEquals(1, RELATIVE.getOperandByteSize());
        assertEquals(1, ZERO_PAGE.getOperandByteSize());
        assertEquals(2, ABSOLUTE.getOperandByteSize());
        assertEquals(2, INDIRECT.getOperandByteSize());
        assertEquals(1, ZERO_PAGE_INDEXED_X.getOperandByteSize());
        assertEquals(1, ZERO_PAGE_INDEXED_Y.getOperandByteSize());
        assertEquals(2, ABSOLUTE_INDEXED_X.getOperandByteSize());
        assertEquals(2, ABSOLUTE_INDEXED_Y.getOperandByteSize());
        assertEquals(1, INDEXED_X_INDIRECT.getOperandByteSize());
        assertEquals(1, INDIRECT_INDEXED_Y.getOperandByteSize());
     }
}
