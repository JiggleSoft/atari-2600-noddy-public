package uk.co.jigglesoft.noddy.sgs.common.cpu6502;

import static uk.co.jigglesoft.noddy.sgs.common.cpu6502.AddressMode6502.*;

public enum InstructionSet65XX
{

    BRK_IMP(0x00, Mnemonic6502.BRK, IMPLIED),
    ORA_IXI(0x01, Mnemonic6502.ORA, INDEXED_X_INDIRECT),
    ORA_ZP(0x05, Mnemonic6502.ORA, null);
//    BRK (0x00, "BRK", null, IMPLIED),    ORA(ABSOLUTE_ZP_INDEXED_X),   X02(INVALID_OPCODE),    X03(INVALID_OPCODE),    X04(INVALID_OPCODE),
//    BPL (RELATIVE)
//    ;
//
//    final int opcode;
//    final String mnemonic;
//    final Object[] processorFamily;

    final int opcode;
    final Mnemonic6502 mnemonic;
    final AddressMode6502 addressMode;

    InstructionSet65XX(final int opcode, final Mnemonic6502 mnemonic, final AddressMode6502 addressMode)
    {
        this.opcode = opcode;
        this.mnemonic = mnemonic;
        this.addressMode = addressMode;
    }

    final int getOpcode()
    {
        return opcode;
    }

    final Mnemonic6502 getMnemonic() { return mnemonic };

    final AddressMode6502 getAddressMode()
    {
        return addressMode;
    }

    final int getOpcodeByteSize()
    {
        return 1;
    }

    final int getOperandByteSize()
    {
        return addressMode.getOperandByteSize();
    }
}
