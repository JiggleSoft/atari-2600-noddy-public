package uk.co.jigglesoft.noddy.sgs.cpu;

import uk.co.jigglesoft.noddy.sgs.cpu.ops.Operation;

import java.util.ArrayList;
import java.util.List;

public class Program
{
    final List<Operation> operations = new ArrayList<>();

    public String toString()
    {
        final StringBuffer sb = new StringBuffer();
        for (final Operation op : getOperations())
        {
            sb.appen
        d()
        }
    }

    private Operation[] getOperations() {
    }
}
