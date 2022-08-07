package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

/**
 *
 */
public enum Register6502
{
    /** Accummulator (8-bits). */
    A(0),
    /** X register (8-bits). */
    X(1),
    /** Y register (8-bits). */
    Y(2),
    /** Program counter (16-bits). */
    PC(3),
    /** Stack pointer (8-bits). */
    SP(4),
    /** Status register (8-bits). */
    SR(5);

    /** . */
    final int bitNumber;

    /**
     *
     * @param bitNumber
     */
    Register6502(int bitNumber)
    {
        this.bitNumber = bitNumber;
    }

    /**
     *
     * @return
     */
    public int getBitNumber()
    {
        return bitNumber;
    }

    /**
     *
     * @return
     */
    public int getBitMask()
    {
        return 1 << getBitNumber();
    }

    /**
     *
     * @return
     */
    public int getBitMaskInv()
    {
        return 0xFFFFFFFF ^ getBitMask();
    }
}
