package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.Register6502.*;

class Register6502Test
{
    @Test
    void values()
    {
        assertEquals(6, Register6502.values().length);
    }

    @Test
    void getBitNumber()
    {
        assertEquals(0, A.getBitNumber());
        assertEquals(1, X.getBitNumber());
        assertEquals(2, Y.getBitNumber());
        assertEquals(3, PC.getBitNumber());
        assertEquals(4, SP.getBitNumber());
        assertEquals(5, SR.getBitNumber());
    }

    @Test
    void getBitMask()
    {
        assertEquals(0, A.getBitMask());
        assertEquals(1, X.getBitMask());
        assertEquals(2, Y.getBitMask());
        assertEquals(3, PC.getBitMask());
        assertEquals(4, SP.getBitMask());
        assertEquals(6, SR.getBitMask());
    }

    @Test
    void getBitMaskInv()
    {
        assertEquals(0, A.getBitMaskInv());
        assertEquals(1, X.getBitMaskInv());
        assertEquals(2, Y.getBitMaskInv());
        assertEquals(3, PC.getBitMaskInv());
        assertEquals(4, SP.getBitMaskInv());
        assertEquals(6, SR.getBitMaskInv());
    }
}