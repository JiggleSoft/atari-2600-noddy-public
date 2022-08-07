package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

/**
 *
 */
public class CycleCount6502
{
    /** . */
    private final int standardCycleCount;

    /** . */
    private final int pageCrossCycleCount;

    /** . */
    private final int branchCycleCount;

    /** FIXME: DELETE ME */
    public CycleCount6502()
    {
        this(666, 777, 888);
    }

    public CycleCount6502(final int standardCycleCount)
    {
        this(standardCycleCount, 0, 0);
    }

    public CycleCount6502(final int standardCycleCount, final int pageCrossCycleCount)
    {
        this(standardCycleCount, pageCrossCycleCount, 0);
    }

    public CycleCount6502(final int standardCycleCount, final int pageCrossCycleCount, final int branchCycleCount)
    {
        this.standardCycleCount = standardCycleCount;
        this.pageCrossCycleCount = pageCrossCycleCount;
        this.branchCycleCount = branchCycleCount;
    }

//    @Override
//    public boolean equals(Object o) {
//        if (this == o)
//        {
//            return true;
//        }
//        if (o == null || getClass() != o.getClass())
//        {
//            return false;
//        }
//        final CycleCount6502 that = (CycleCount6502) o;
//        return (this.minimumCycleCount == that.minimumCycleCount) &&
//               (this.pageCrossCycleCount == that.pageCrossCycleCount) &&
//               (this.branchCycleCount == that.branchCycleCount);
//    }
//
//    @Override
//    public int hashCode()
//    {
//        return Objects.hash(minimumCycleCount, pageCrossCycleCount, branchCycleCount);
//    }
//
    public int getStandardCycleCount()
    {
        return standardCycleCount;
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
                "minimumCycleCount=" + standardCycleCount +
                ", pageCrossCycleCount=" + pageCrossCycleCount +
                ", branchCycleCount=" + branchCycleCount +
                '}';
    }
}
