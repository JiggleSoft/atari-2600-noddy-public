package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InstructionSet65XXTest
{
    InstructionSet65XX[] values;

    @BeforeEach
    void setUp()
    {
        values = InstructionSet65XX.values();
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
        for (InstructionSet65XX cut : values)
        {
            //length and underscore
            assertEquals(cut.name().substring(0, 3), cut.getMnemonic().name(), cut.toString());
            assertEquals(cut.name().substring(4, 7), cut.getAddressMode().getAbbreviation(), cut.toString());
        }
    }

    @Test
    void getOpcode()
    {
        for (InstructionSet65XX cut : values)
        {
            assertEquals(cut.ordinal(), cut.getOpcode(), cut.toString());
        }
    }

    @Test
    void getMnemonic()
    {
        for (InstructionSet65XX cut : values)
        {
            assertEquals(cut.name().substring(0, 3), cut.getMnemonic().name(), cut.toString());
        }
    }

    @Test
    void getAddressMode()
    {
        final InstructionSet65XX[] values = InstructionSet65XX.values();
        //FIXME: assertEquals(256, values.length);
        for (InstructionSet65XX cut : values)
        {
            assertEquals(cut.name().substring(4, 7), cut.getAddressMode().getAbbreviation(), cut.toString());
        }
    }

    @Test
    void isIllegalInstruction()
    {
        for (InstructionSet65XX cut : values)
        {
            cut.isIllegalInstruction();
            //getMnemonic.is.....
        }
    }

    @Test
    void getOpcodeStability()
    {
        for (InstructionSet65XX cut : values)
        {
            cut.getOpcodeStability();
        }
    }

    @Test
    void getOpcodeByteSize()
    {
        for (InstructionSet65XX cut : values)
        {
            assertEquals(1, cut.getOpcodeByteSize(), cut.toString());
        }
    }

    @Test
    void getOperandByteSize()
    {
        for (InstructionSet65XX cut : values)
        {
            cut.getOperandByteSize();
        }
    }
}