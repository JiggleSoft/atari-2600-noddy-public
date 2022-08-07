package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.Mnemonic6502.*;

class Mnemonic6502Test
{
    Mnemonic6502[] values;

    @BeforeEach
    void setUp()
    {
        values = Mnemonic6502.values();
    }

    @AfterEach
    void tearDown()
    {
        values = null;
    }

    @Test
    void values()
    {
        assertEquals(256, values.length);
    }

    @Test
    void isStandardOpcode()
    {
        int standadardOpcodeCount = 0;
        int nonStandardOpcodeCount = 0;
        for (Mnemonic6502 cut : values)
        {
            if (cut.isStandardOpcode())
            {
                standadardOpcodeCount++;
            }
            else
            {
                nonStandardOpcodeCount++;
            }
        }
        assertEquals(0, standadardOpcodeCount);
        assertEquals(1, nonStandardOpcodeCount);
    }
}