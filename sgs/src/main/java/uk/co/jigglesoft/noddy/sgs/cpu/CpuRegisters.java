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
