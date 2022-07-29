package uk.co.jigglesoft.noddy.sgs.cpu;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class CpuFlags
{
    private static final int VALID_MASK = 0xDF;

    private int value;

    public CpuFlags()
    {
        this(0);
    }

    public CpuFlags(int value)
    {
        this.value = value & VALID_MASK;
    }

    public CpuFlags(final Set<CpuFlag> flags)
    {
        setFlags(flags);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CpuFlags cpuFlags = (CpuFlags) o;
        return value == cpuFlags.value;
    }

    @Override
    public int hashCode() {
        return Objects.hash(value);
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value & VALID_MASK;
    }

    public Set<CpuFlag> getFlags()
    {
        final Set<CpuFlag> flags = new HashSet<CpuFlag>(7);
        for (CpuFlag flag : CpuFlag.values())
        {
            if ((getValue() & flag.getBitMask()) != 0)
            {
                flags.add(flag);
            }
        }
        return flags;
    }

    public void setFlags(final Set<CpuFlag> flags)
    {
        int value = 0;
        for (CpuFlag flag : flags)
        {
            value |= flag.getBitMask();
        }
        setValue(value);
    }

    private boolean getFlagBool(final CpuFlag cpuFlags)
    {
        return (getValue() & cpuFlags.getBitMask()) != 0;
    }

    private void setFlagBool(final CpuFlag cpuFlags, final boolean value)
    {
        setValue((getValue() & cpuFlags.getBitMaskInv()) | (value ? cpuFlags.getBitMask() : 0));
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
        return "CpuFlags{" +
                "value=" + value +
                '}';
    }

    public void update(int y, CpuFlag ... flags) {
    }
}
