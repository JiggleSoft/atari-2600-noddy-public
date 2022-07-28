package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;

public abstract class AbstractOperation //implements Operation
{
    public static final int VALID_BYTE_MASK = 0xFF;

    //Object getCpuState()
//    {
//        return null;
//    }
    public abstract void onExec(final CpuContext cpuContext);

    /*

//    getCpuState().updateFlags(N|Z, tempYReg);
//    getCPuState().incByteLenth(getByteLength());
//    getCpuState().incClockCOunt(getClockCount());
     */
}
