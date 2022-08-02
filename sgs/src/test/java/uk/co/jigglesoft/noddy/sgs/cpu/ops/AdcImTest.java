package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class AdcImTest
{
    AdcIm cut;

    @BeforeEach
    void setUp()
    {
        cut = new AdcIm();
    }

    @AfterEach
    void tearDown()
    {
        cut = null;
    }

    @Test
    void testGetOpCode()
    {
        assertEquals(0x69, cut.getOpCode());
    }

    @Test
    void testGetAddressMode()
    {
        assertEquals(AddressMode6502.IMMEDIATE, cut.getAddressMode());
    }

    @Test
    void testGetOpCodeByteSize()
    {
        assertEquals(1, cut.getOpCodeByteSize());
    }

    @Test
    void testGetOperand()
    {
        for (int i = cut.getOperandMin(); i <= cut.getOperandMax(); i++)
        {
            assertEquals(i, cut.getOperand());
        }
    }

    @Test
    void testSetOperand()
    {
        for (int i = cut.getOperandMin(); i <= cut.getOperandMax(); i++)
        {
            assertEquals(i, cut.getOperand());
        }
    }

    @Test
    void testGetOperandMin()
    {
        assertEquals(0, cut.getOperandMin());
    }

    @Test
    void testGetOperandMax()
    {
        assertEquals(255, cut.getOperandMax());
    }

    @Test
    void testGetOperandByteSize()
    {
        assertEquals(1, cut.getOperandByteSize());
    }

    @Test
    void getMachineCode()
    {
        for (int i = cut.getOperandMin(); i <= cut.getOperandMax(); i++)
        {
            assertTrue(Arrays.equals(new byte[]{(byte) 0x69}, cut.getMachineCode()));
        }
    }

    @Test
    void getAssemblyCode()
    {
        for (int i = cut.getOperandMin(); i <= cut.getOperandMax(); i++)
        {
            assertEquals("ADC\t#" + i + " ; 3 1", cut.getAssemblyCode());
        }
    }

    @Test
    void getByteLength()
    {
        assertEquals(2, cut.getByteLength());
    }

    @Test
    void getClockCount()
    {
        assertEquals(3, cut.getClockCount());
    }

    @Test
    void getClockCountMin()
    {
        assertEquals(3, cut.getClockCountMin());
    }

    @Test
    void getClockCountMax()
    {
        assertEquals(3, cut.getClockCountMax());
    }

    @Test
    void getOperationAffect()
    {
        final OperationAffect operationAffect = cut.getOperationAffect();
        assertNotNull(operationAffect);
        assertEquals(-1, operationAffect.hashCode());//FIXME: !!!
    }

    @Test
    void execute()
    {
        cut.execute(null);//FIXME: !!!
    }

    @Test
    void onExec()
    {
        cut.onExec(null);//FIXME: !!!
    }
}