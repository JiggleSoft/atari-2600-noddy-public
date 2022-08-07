package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Stability6502Test
{
    @Test
    void values()
    {
        assertEquals(4, Stability6502.values().length);
    }
}