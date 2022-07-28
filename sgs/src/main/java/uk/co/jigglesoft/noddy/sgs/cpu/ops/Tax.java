package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuFlag;

public class Tax extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        final int a = cpuContext.getMachineState().getRegisters().getA();
        cpuContext.getMachineState().getRegisters().setX(a);
        cpuContext.getMachineState().getRegisters().getFlags().update(a, CpuFlag.N, CpuFlag.Z);
    }
}
