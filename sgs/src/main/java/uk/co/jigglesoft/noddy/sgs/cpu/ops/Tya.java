package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuFlag;

public class Tya extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        final int y = cpuContext.getMachineState().getRegisters().getY();
        cpuContext.getMachineState().getRegisters().setA(y);
        cpuContext.getMachineState().getRegisters().getFlags().update(y, CpuFlag.N, CpuFlag.Z);
    }
}
