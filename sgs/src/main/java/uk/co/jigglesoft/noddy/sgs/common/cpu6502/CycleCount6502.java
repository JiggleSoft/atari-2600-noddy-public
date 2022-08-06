package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import java.util.Objects;

public class CycleCount6502
{
    /** . */
    private final int minimumCycleCount;

    /** . */
    private final int pageCrossCycleCount;

    /** . */
    private final int branchCycleCount;

    public CycleCount6502(final int minimumCycleCount)
    {
        this(minimumCycleCount, 0, 0);
    }

    public CycleCount6502(final int minimumCycleCount, final int pageCrossCycleCount)
    {
        this(minimumCycleCount, pageCrossCycleCount, 0);
    }

    public CycleCount6502(final int minimumCycleCount, final int pageCrossCycleCount, final int branchCycleCount)
    {
        this.minimumCycleCount = minimumCycleCount;
        this.pageCrossCycleCount = pageCrossCycleCount;
        this.branchCycleCount = branchCycleCount;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
        {
            return true;
        }
        if (o == null || getClass() != o.getClass())
        {
            return false;
        }
        final CycleCount6502 that = (CycleCount6502) o;
        return (this.minimumCycleCount == that.minimumCycleCount) &&
               (this.pageCrossCycleCount == that.pageCrossCycleCount) &&
               (this.branchCycleCount == that.branchCycleCount);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(minimumCycleCount, pageCrossCycleCount, branchCycleCount);
    }

    public int getMinimumCycleCount()
    {
        return minimumCycleCount;
    }

    public int getPageCrossCycleCount()
    {
        return pageCrossCycleCount;
    }

    public int getBranchCycleCount()
    {
        return branchCycleCount;
    }

    @Override
    public String toString() {
        return "CycleCount6502{" +
                "minimumCycleCount=" + minimumCycleCount +
                ", pageCrossCycleCount=" + pageCrossCycleCount +
                ", branchCycleCount=" + branchCycleCount +
                '}';
    }
}
