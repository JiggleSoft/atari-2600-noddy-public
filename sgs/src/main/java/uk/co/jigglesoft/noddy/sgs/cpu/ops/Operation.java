package uk.co.jigglesoft.noddy.sgs.cpu.ops;

public interface Operation
{
    int getByteLength();
    int getClockCount();
    int getClockCountMax();
    boolean isAffectStatus();
    boolean isAffectConditionFlags();
    boolean isAffectCpuStatus();
    boolean isAffectStack();
    boolean isAffectMemory();
    boolean isAffectMemoryZp();
    boolean isAffectMemoryStack();
    boolean isAffectMemoryOther();
    boolean isAffectRegister();
    boolean isAffectRegiseterA();
    boolean isAffectRegiseterX();
    boolean isAffectRegiseterY();
    void execute();
}
