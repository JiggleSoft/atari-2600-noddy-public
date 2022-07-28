package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuFlag;

public class Inx extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        final int x = (cpuContext.getMachineState().getRegisters().getX() + 1) & VALID_BYTE_MASK;
        cpuContext.getMachineState().getRegisters().setX(x);
        cpuContext.getMachineState().getRegisters().getFlags().update(x, CpuFlag.N, CpuFlag.Z);
    }
}
