package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuFlag;

public class Txa extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        final int x = cpuContext.getMachineState().getRegisters().getX();
        cpuContext.getMachineState().getRegisters().setA(x);
        cpuContext.getMachineState().getRegisters().getFlags().update(x, CpuFlag.N, CpuFlag.Z);
    }
}
