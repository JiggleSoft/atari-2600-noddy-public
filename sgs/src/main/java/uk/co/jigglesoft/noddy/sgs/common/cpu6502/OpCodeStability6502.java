package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

public enum OpCodeStability6502
{
    /** These instructions are stable and have well understood regular behaviour. */
    STABLE,
    /** . */
    UNSTABLE,
    /** . */
    HIGHLY_UNSTABLE,
    /** These instructions will lock-up the CPU in the T1 state with $FF on the data bus until reset. */
    KABOOM
}
