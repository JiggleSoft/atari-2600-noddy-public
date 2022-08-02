package uk.co.jigglesoft.noddy.sgs.cpu.ops;

import uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502;
import uk.co.jigglesoft.noddy.sgs.cpu.CpuContext;

public interface Operation
{
    int getOpCode();
    AddressMode6502 getAddressMode();
    int getOpCodeByteSize();
    int getOperand();
    void setOperand(final int operand);
    int getOperandMin();
    int getOperandMax();
    int getOperandByteSize();
    byte[] getMachineCode();
    String getAssemblyCode();
    int getByteLength();
    int getClockCount();
    int getClockCountMin();
    int getClockCountMax();
    OperationAffect getOperationAffect();
    void execute(final CpuContext machineContext);
}
