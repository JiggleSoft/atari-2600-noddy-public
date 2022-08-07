package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.StatusRegister6502.*;

class StatusRegister6502Test
{
    @Test
    void values()
    {
        assertEquals(7, StatusRegister6502.values().length);
    }

    @Test
    void getBitNumber()
    {
        assertEquals(0, C.getBitNumber());
        assertEquals(1, Z.getBitNumber());
        assertEquals(2, I.getBitNumber());
        assertEquals(3, D.getBitNumber());
        assertEquals(4, B.getBitNumber());
        assertEquals(6, V.getBitNumber());
        assertEquals(7, N.getBitNumber());
    }

    @Test
    void getBitMask()
    {
        assertEquals(0, C.getBitMask());
        assertEquals(1, Z.getBitMask());
        assertEquals(2, I.getBitMask());
        assertEquals(3, D.getBitMask());
        assertEquals(4, B.getBitMask());
        assertEquals(6, V.getBitMask());
        assertEquals(7, N.getBitMask());
    }

    @Test
    void getBitMaskInv()
    {
        assertEquals(0, C.getBitMaskInv());
        assertEquals(1, Z.getBitMaskInv());
        assertEquals(2, I.getBitMaskInv());
        assertEquals(3, D.getBitMaskInv());
        assertEquals(4, B.getBitMaskInv());
        assertEquals(6, V.getBitMaskInv());
        assertEquals(7, N.getBitMaskInv());
    }
}