package ratchet;

public final class Resolver {
    private Resolver() { }

    public static OperationList resolve(OperationList input, Registry registry) throws RatchetException {
        OperationList output = new OperationList();
        output.setBaseVersion(input.baseVersion());
        output.setTargetVersion(input.targetVersion());
        output.setFlags(input.flags());
        output.setReplayBudget(input.replayBudget());
        resolveInto(input, registry, output, 0);
        return output;
    }

    private static void resolveInto(OperationList input, Registry registry, OperationList output, int depth) throws RatchetException {
        if (depth > 16) {
            throw new RatchetException(RatchetStatus.DEPTH, "version chain too deep");
        }
        for (Operation operation : input.operations()) {
            if (operation.type() == OperationType.CHAIN) {
                byte[] bytes = registry.get(operation.version());
                OperationList child = Parser.parse(bytes);
                resolveInto(child, registry, output, depth + 1);
            } else {
                output.add(operation);
            }
        }
    }
}
