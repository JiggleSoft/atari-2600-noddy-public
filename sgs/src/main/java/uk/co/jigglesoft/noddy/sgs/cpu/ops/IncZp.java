package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuFlag;

public class IncZp extends AbstractOperation
{
    @Override
    public void onExec(final CpuContext cpuContext)
    {
        //FIXME: !!!
//        final int zp = (cpuContext.getMachineState().getMemory().get(getOperand()).get() + 1) & VALID_INT8_MASK;
//        cpuContext.getMachineState().getMemory().get(getOperand()).set(zp);
       // cpuContext.getMachineState().getRegisters().getFlags().update(zp, CpuFlag.N, CpuFlag.Z);
    }
}
