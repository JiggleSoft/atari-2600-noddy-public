package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;
import uk.co.jigglesoft.noddy.sgs.cpu.DisassemblyUtil;

public abstract class AbstractOperation implements Operation
{
    public static final int VALID_INT8_MASK = 0xFF;
    public static final int VALID_INT16_MASK = 0xFFFF;

    private final int opcode;
    private final AddressMode addressMode;

    int operand;

    public AbstractOperation(final int opcode, final AddressMode addressMode)
    {
        this.opcode = opcode;
        this.addressMode = addressMode;
    }

    @Override
    public int getOpCode()
    {
        return opcode;
    }

    @Override
    public AddressMode getAddressMode()
    {
        return addressMode;
    }

    @Override
    public int getOpCodeByteSize()
    {
        return 1;
    }

    @Override
    public int getOperand()
    {
        return operand;
    }

    @Override
    public void setOperand(int operand)
    {
        this.operand = operand;//FIXME withinig range/mask
    }

    @Override
    public int getOperandMin()
    {
        return 0;
    }

    @Override
    public int getOperandMax()
    {
        switch(getOperandByteSize())
        {
            case 0 : return 0;
            case 1 : return 256;
            case 2 : return 65536;
            default : throw new IllegalStateException();
        }
    }

    @Override
    public int getOperandByteSize()
    {
        return getAddressMode().getOperandByteSize();
    }

    @Override
    public byte[] getMachineCode()
    {
        switch (getOperandByteSize())
        {
            case 0 : return new byte[] { (byte)getOpCode() };
            case 1 : return new byte[] { (byte)getOpCode(), (byte)getOperand() };
            case 2 : return new byte[] { (byte)getOpCode(), (byte)getOperand(), (byte)((getOperand() >> 8) & VALID_INT8_MASK) };
            default : throw new IllegalStateException();
        }
    }

    @Override
    public String getAssemblyCode()
    {
        return DisassemblyUtil.disassembleCode(getMachineCode());
    }

    @Override
    public int getByteLength()
    {
        return getOpCodeByteSize() + getOperandByteSize();
    }

    @Override
    public int getClockCount()
    {
        return 666;
    }

    @Override
    public int getClockCountMin()
    {
        return 666;
    }

    @Override
    public int getClockCountMax()
    {
        return 777;
    }

    @Override
    public OperationAffect getOperationAffect()
    {
        return null;
    }

    @Override
    public void execute(CpuContext machineContext)
    {
        onExec(machineContext);
        //machineContext.getMachineState().
        //incPC(getByteCount());
        //updSR()
        //incClk(getClockCount());
    }

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
