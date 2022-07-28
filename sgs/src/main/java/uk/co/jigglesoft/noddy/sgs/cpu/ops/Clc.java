package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;

public class Clc extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        cpuContext.getMachineState().getRegisters().getFlags().setC(false);
    }
}