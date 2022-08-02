package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class TxaTest
{
    Txa cut;

    @BeforeEach
    void setUp()
    {
        cut = new Txa();
    }

    @AfterEach
    void tearDown()
    {
        cut = null;
    }

    @Test
    void testGetOpCode()
    {
        assertEquals(0x8A, cut.getOpCode());
    }

    @Test
    void testGetAddressMode()
    {
        assertEquals(AddressMode6502.IMPLIED, cut.getAddressMode());
    }

    @Test
    void testGetOpCodeByteSize()
    {
        assertEquals(1, cut.getOpCodeByteSize());
    }

    @Test
    void testGetOperand()
    {
        assertThrows(IllegalStateException.class, () -> { cut.getOperand(); } );
    }

    @Test
    void testSetOperand()
    {
        assertThrows(IllegalStateException.class, () -> { cut.setOperand(123); } );
    }

    @Test
    void testGetOperandMin()
    {
        assertEquals(-1, cut.getOperandMin());
    }

    @Test
    void testGetOperandMax()
    {
        assertEquals(-1, cut.getOperandMax());
    }

    @Test
    void testGetOperandByteSize()
    {
        assertEquals(0, cut.getOperandByteSize());
    }

    @Test
    void getMachineCode()
    {
        assertTrue(Arrays.equals(new byte[] { (byte)0x8A }, cut.getMachineCode()));
    }

    @Test
    void getAssemblyCode()
    {
        assertEquals("TXA\t; 2 1", cut.getAssemblyCode());
    }

    @Test
    void getByteLength()
    {
        assertEquals(1, cut.getByteLength());
    }

    @Test
    void getClockCount()
    {
        assertEquals(2, cut.getClockCount());
    }

    @Test
    void getClockCountMin()
    {
        assertEquals(2, cut.getClockCountMin());
    }

    @Test
    void getClockCountMax()
    {
        assertEquals(2, cut.getClockCountMax());
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