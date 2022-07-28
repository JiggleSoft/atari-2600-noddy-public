package uk.co.jigglesoft.noddy.sgs.cpu;

public final class CpuRegisters
{
    private static final int VALID_MASK = 0xFF;

    public int A;
    public int X;
    public int Y;
    public int SP;
    public int PC;
    public int SR;

    public CpuRegisters() {
    }

    public int getA() {
        return A;
    }

    public void setA(int a) {
        A = a & VALID_MASK;
    }

    public int getX() {
        return X;
    }

    public void setX(int x) {
        X = x & VALID_MASK;
    }

    public int getY() {
        return Y;
    }

    public void setY(int y) {
        Y = y & VALID_MASK;
    }

    public int getSP() {
        return SP;
    }

    public void setSP(int SP) {
        this.SP = SP & VALID_MASK;
    }

    public int getPC() {
        return PC;
    }

    public void setPC(int PC) {
        this.PC = PC & VALID_MASK;
    }

    public int getSR() {
        return SR;
    }

    public void setSR(int SR) {
        this.SR = SR;
    }

    private boolean getFlagBool(final CpuFlag cpuFlags)
    {
        return (getSR() & cpuFlags.getBitMask()) != 0;
    }

    private void setFlagBool(final CpuFlag cpuFlags, final boolean value)
    {
        setSR((getSR() & cpuFlags.getBitMaskInv()) | (value ? cpuFlags.getBitMask() : 0));
    }

    public boolean getC() { return getFlagBool(CpuFlag.C); }

    public void setC(final boolean value) { setFlagBool(CpuFlag.C, value); }

    public boolean getZ() { return getFlagBool(CpuFlag.Z); }

    public void setZ(final boolean value) { setFlagBool(CpuFlag.Z, value); }

    public boolean getI() { return getFlagBool(CpuFlag.I); }

    public void setI(final boolean value) { setFlagBool(CpuFlag.I, value); }

    public boolean getD() { return getFlagBool(CpuFlag.D); }

    public void setD(final boolean value) { setFlagBool(CpuFlag.D, value); }

    public boolean getB() { return getFlagBool(CpuFlag.B); }

    public void setB(final boolean value) { setFlagBool(CpuFlag.B, value); }

    public boolean getV() { return getFlagBool(CpuFlag.V); }

    public void setV(final boolean value) { setFlagBool(CpuFlag.V, value); }

    public boolean getN() { return getFlagBool(CpuFlag.N); }

    public void setN(final boolean value) { setFlagBool(CpuFlag.N, value); }

    @Override
    public String toString() {
        return "CpuRegisters{" +
                "A=" + A +
                ", X=" + X +
                ", Y=" + Y +
                ", SP=" + SP +
                ", PC=" + PC +
                ", SR=" + SR +
                '}';
    }

    public CpuFlags getFlags() {
        return null;
    }

    public void update(int y, CpuFlag ... flags) {
    }
}
