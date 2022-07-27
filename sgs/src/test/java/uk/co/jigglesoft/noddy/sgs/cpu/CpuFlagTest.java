package uk.co.jigglesoft.noddy.sgs.cpu;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CpuFlagTest
{
    @Test
    void testCpuFlagCount()
    {
        assertEquals(7, CpuFlag.values().length);
    }

    @Test
    void testCpuFlagContains()
    {
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.C));
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.Z));
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.I));
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.D));
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.B));
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.V));
        assertTrue(List.of(CpuFlag.values()).contains(CpuFlag.N));
    }

    @Test
    void testGetBitNumber()
    {
        assertEquals(0, CpuFlag.C.getBitNumber());
        assertEquals(1, CpuFlag.Z.getBitNumber());
        assertEquals(2, CpuFlag.I.getBitNumber());
        assertEquals(3, CpuFlag.D.getBitNumber());
        assertEquals(4, CpuFlag.B.getBitNumber());
        assertEquals(6, CpuFlag.V.getBitNumber());
        assertEquals(7, CpuFlag.N.getBitNumber());
    }

    @Test
    void testGetBitMask()
    {
        assertEquals(0x01, CpuFlag.C.getBitMask());
        assertEquals(0x02, CpuFlag.Z.getBitMask());
        assertEquals(0x04, CpuFlag.I.getBitMask());
        assertEquals(0x08, CpuFlag.D.getBitMask());
        assertEquals(0x10, CpuFlag.B.getBitMask());
        assertEquals(0x40, CpuFlag.V.getBitMask());
        assertEquals(0x80, CpuFlag.N.getBitMask());
    }

    @Test
    void testGetBitMaskInv()
    {
        assertEquals(0xFFFFFFFE, CpuFlag.C.getBitMaskInv());
        assertEquals(0xFFFFFFFD, CpuFlag.Z.getBitMaskInv());
        assertEquals(0xFFFFFFFB, CpuFlag.I.getBitMaskInv());
        assertEquals(0xFFFFFFF7, CpuFlag.D.getBitMaskInv());
        assertEquals(0xFFFFFFEF, CpuFlag.B.getBitMaskInv());
        assertEquals(0xFFFFFFBF, CpuFlag.V.getBitMaskInv());
        assertEquals(0xFFFFFF7F, CpuFlag.N.getBitMaskInv());
    }
}