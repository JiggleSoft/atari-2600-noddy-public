package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

/**
 *
 */
public enum StatusRegister6502
{
    C(0),
    Z(1),
    I(2),
    D(3),
    B(4),
    V(6),
    N(7);

    /** . */
    final int bitNumber;

    /**
     *
     * @param bitNumber
     */
    StatusRegister6502(int bitNumber)
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
