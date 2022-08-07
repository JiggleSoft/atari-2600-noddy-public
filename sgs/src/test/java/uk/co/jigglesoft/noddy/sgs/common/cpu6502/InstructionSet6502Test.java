package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InstructionSet6502Test
{
    InstructionSet6502[] values;

    @BeforeEach
    void setUp()
    {
        values = InstructionSet6502.values();
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
    void name()
    {
        for (InstructionSet6502 cut : values)
        {
            //FIXME: order expects + length and underscore
            assertEquals(cut.name().substring(0, 3), cut.getMnemonic().name(), cut.toString());
            assertEquals(cut.name().substring(4, 7), cut.getAddressMode().getAbbreviation(), cut.toString());
        }
    }

    @Test
    void getOpcode()
    {
        for (InstructionSet6502 cut : values)
        {
            assertEquals(cut.ordinal(), cut.getOpcode(), cut.toString());
        }
    }

    @Test
    void getMnemonic()
    {
        for (InstructionSet6502 cut : values)
        {
            assertEquals(cut.name().substring(0, 3), cut.getMnemonic().name(), cut.toString());
        }
    }

    @Test
    void getAddressMode()
    {
        for (InstructionSet6502 cut : values)
        {
            assertEquals(cut.name().substring(4, 7), cut.getAddressMode().getAbbreviation(), cut.toString());
        }
    }

    @Test
    void getCycleCount()
    {
        for (InstructionSet6502 cut : values)
        {
            final CycleCount6502 cycleCount = cut.getCycleCount();
            assertNotNull(cycleCount);
//            assertEquals(0, cycleCount.getMinimumCycleCount(), cut.toString());
//            assertEquals(0, cycleCount.getPageCrossCycleCount(), cut.toString());
//            assertEquals(0, cycleCount.getBranchCycleCount(), cut.toString());
        }
    }

    @Test
    void getOpcodeState()
    {
        for (InstructionSet6502 cut : values)
        {
            final OpcodeState6502 opcodeState = cut.getOpcodeState();

            assertNotNull(opcodeState);
//            assertEquals(0, opcodeState.(), cut.toString());
//            assertEquals(0, opcodeState.getMinimumCycleCount(), cut.toString());
//            assertEquals(0, opcodeState.getMinimumCycleCount(), cut.toString());
//            assertEquals(0, opcodeState.getMinimumCycleCount(), cut.toString());
//            assertEquals(0, opcodeState.getMinimumCycleCount(), cut.toString());
//            assertEquals(0, opcodeState.getPageCrossCycleCount(), cut.toString());
//            assertEquals(0, opcodeState.getBranchCycleCount(), cut.toString());
        }
    }

    @Test
    void isIllegalInstruction()
    {
        for (InstructionSet6502 cut : values)
        {
            boolean expected = false;
            expected = (cut.name().substring(7, 8).equals("_")) || (cut.name().startsWith("ZZZ_"));
            assertEquals(expected, cut.isIllegalInstruction(), cut.toString());
            //getMnemonic.is.....
        }
    }

    @Test
    void getOpcodeStability()
    {
        for (InstructionSet6502 cut : values)
        {
            cut.getOpcodeStability();
        }
    }

    @Test
    void getOpcodeByteSize()
    {
        for (InstructionSet6502 cut : values)
        {
            assertEquals(1, cut.getOpcodeByteSize(), cut.toString());
        }
    }

    @Test
    void getOperandByteSize()
    {
        for (InstructionSet6502 cut : values)
        {
            final int operandByteSize = cut.getOperandByteSize();
            int expected = -1;
            switch (cut.getAddressMode())
            {
                case IMPLIED :
                case ACCUMULATOR :
                    expected = 0;
                    break;
                case IMMEDIATE :
                case RELATIVE :
                case ZERO_PAGE :
                case ZERO_PAGE_INDEXED_X :
                case ZERO_PAGE_INDEXED_Y :
                case INDEXED_X_INDIRECT :
                case INDIRECT_INDEXED_Y :
                    expected = 1;
                    break;
                case ABSOLUTE :
                case INDIRECT :
                case ABSOLUTE_INDEXED_X :
                case ABSOLUTE_INDEXED_Y :
                    expected = 2;
                    break;
                default:
                    fail("Unexpected Address Mode value for " + cut.toString());
            }
            assertEquals(expected, operandByteSize, cut.toString());
        }
    }
}