package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuFlag;

public class Iny extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        final int y = (cpuContext.getMachineState().getRegisters().getY() + 1) & VALID_BYTE_MASK;
        cpuContext.getMachineState().getRegisters().setY(y);
        cpuContext.getMachineState().getRegisters().getFlags().update(y, CpuFlag.N, CpuFlag.Z);
    }
}
