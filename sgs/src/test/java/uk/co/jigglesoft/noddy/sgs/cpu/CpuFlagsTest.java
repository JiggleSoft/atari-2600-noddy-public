package uk.co.jigglesoft.noddy.sgs.cpu;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CpuFlagsTest
{
    @Test
    void testConstructorDefault()
    {
        final CpuFlags cut = new CpuFlags();
        assertEquals(0, cut.getValue());
        assertEquals(0, cut.getFlags().size());
    }

    @Test
    void testConstructorValue()
    {
        {
            final CpuFlags cut = new CpuFlags(0);
            assertEquals(0, cut.getValue());
            assertEquals(0, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(1);
            assertEquals(1, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(2);
            assertEquals(2, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(4);
            assertEquals(4, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(8);
            assertEquals(8, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(16);
            assertEquals(16, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(64);
            assertEquals(64, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(128);
            assertEquals(128, cut.getValue());
            assertEquals(1, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(0xDF);
            assertEquals(0xDF, cut.getValue());
            assertEquals(7, cut.getFlags().size());
        }
        {
            final CpuFlags cut = new CpuFlags(0xFFFFFFFF);
            assertEquals(0xDF, cut.getValue());
            assertEquals(7, cut.getFlags().size());
        }
    }

    @Test
    void testEquals()
    {
        final CpuFlags cut = new CpuFlags(0x13);
        assertNotEquals(null, cut);
        assertNotEquals(new CpuFlags(0x12), cut);
        assertEquals(new CpuFlags(0x13), cut);
        assertEquals(cut, cut);
    }

    @Test
    void testHashCode()
    {
        final CpuFlags cut = new CpuFlags(0x13);
        assertNotEquals(0, cut.hashCode());
        assertNotEquals(new CpuFlags(0x12).hashCode(), cut.hashCode());
        assertEquals(new CpuFlags(0x13).hashCode(), cut.hashCode());
        assertEquals(cut.hashCode(), cut.hashCode());
    }

    @Test
    void getValue()
    {
    }

    @Test
    void setValue() {
    }

    @Test
    void getFlags() {
    }

    @Test
    void setFlags() {
    }

    @Test
    void testToString() {
    }
}