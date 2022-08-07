package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CycleCount6502Test
{
    private CycleCount6502 cut;

    @BeforeEach
    void setUp()
    {
        cut = new CycleCount6502(123, 456, 789);
    }

    @AfterEach
    void tearDown()
    {
        cut = null;
    }

//    @Test
//    void testEquals()
//    {
//        assertEquals(cut, cut);
//        assertEquals(new CycleCount6502(123, 456, 789), cut);
//        assertNotEquals(new CycleCount6502(234, 456, 789), null);
//        assertNotEquals(new CycleCount6502(234, 456, 789), cut);
//        assertNotEquals(new CycleCount6502(123, 567, 789), cut);
//        assertNotEquals(new CycleCount6502(123, 456, 890), cut);
//        //TODO: check descendent class with same values and different values.
//    }
//
//    @Test
//    void testHashCode()
//    {
//        assertEquals(cut.hashCode(), cut.hashCode());
//        assertEquals(new CycleCount6502(123, 456, 789).hashCode(), cut.hashCode());
//        assertNotEquals(new CycleCount6502(234, 456, 789).hashCode(), cut.hashCode());
//        assertNotEquals(new CycleCount6502(123, 567, 789).hashCode(), cut.hashCode());
//        assertNotEquals(new CycleCount6502(123, 456, 890).hashCode(), cut.hashCode());
//    }
//
    @Test
    void getStandardCycleCount()
    {
        assertEquals(123, cut.getStandardCycleCount());
    }

    @Test
    void getPageCrossCycleCount()
    {
        assertEquals(456, cut.getPageCrossCycleCount());
    }

    @Test
    void getBranchCycleCount()
    {
        assertEquals(789, cut.getBranchCycleCount());
    }

    @Test
    void testToString()
    {
        assertEquals("CycleCount6502{standardCycleCount=123, pageCrossCycleCount=456, branchCycleCount=789}", cut.toString());
    }
}