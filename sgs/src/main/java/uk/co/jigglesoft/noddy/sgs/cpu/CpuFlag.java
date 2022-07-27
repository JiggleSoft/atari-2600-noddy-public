package uk.co.jigglesoft.noddy.sgs.cpu;

public enum CpuFlag
{
    C(0),
    Z(1),
    I(2),
    D(3),
    B(4),
    V(6),
    N(7);

    final int bitNumber;

    CpuFlag(int bitNumber)
    {
        this.bitNumber = bitNumber;
    }

    public int getBitNumber() {
        return bitNumber;
    }

    public int getBitMask() {
        return 1 << getBitNumber();
    }

    public int getBitMaskInv() {
        return 0xFFFFFFFF ^ getBitMask();
    }
}
