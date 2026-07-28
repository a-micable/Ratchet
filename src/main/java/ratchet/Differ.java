package ratchet;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public final class Differ {
    private Differ() { }

    public static OperationList diff(byte[] base, byte[] target, String baseName, String targetName) {
        OperationList out = new OperationList();
        out.setBaseVersion(baseName);
        out.setTargetVersion(targetName);
        ByteSuffixAutomaton index = new ByteSuffixAutomaton(base);
        int targetPos = 0;
        int insertStart = 0;
        while (targetPos < target.length) {
            Match match = index.longestPrefix(target, targetPos);
            if (match.length >= 4) {
                if (targetPos > insertStart) {
                    out.add(Operation.insert(Arrays.copyOfRange(target, insertStart, targetPos)));
                }
                out.add(Operation.copy(match.offset, match.length));
                targetPos += match.length;
                insertStart = targetPos;
            } else {
                targetPos++;
            }
        }
        if (targetPos > insertStart) {
            out.add(Operation.insert(Arrays.copyOfRange(target, insertStart, targetPos)));
        }
        if (base.length > 0) {
            out.add(Operation.delete(0, base.length));
        }
        return out;
    }

    public static byte[] diffBytes(byte[] base, byte[] target, String baseName, String targetName) {
        return Parser.write(diff(base, target, baseName, targetName));
    }

    private static final class Match {
        final int offset;
        final int length;

        Match(int offset, int length) {
            this.offset = offset;
            this.length = length;
        }
    }

    private static final class ByteSuffixAutomaton {
        private final State[] states;
        private int size = 1;
        private int last;

        ByteSuffixAutomaton(byte[] base) {
            states = new State[Math.max(1, base.length * 2)];
            states[0] = new State();
            states[0].link = -1;
            for (int i = 0; i < base.length; i++) {
                extend(base[i] & 0xff, i);
            }
        }

        Match longestPrefix(byte[] target, int start) {
            int state = 0;
            int length = 0;
            int offset = 0;
            for (int i = start; i < target.length; i++) {
                Integer next = states[state].next.get(Integer.valueOf(target[i] & 0xff));
                if (next == null) {
                    break;
                }
                state = next.intValue();
                length++;
                offset = states[state].firstPosition - length + 1;
            }
            return new Match(offset, length);
        }

        private void extend(int value, int position) {
            int current = size++;
            states[current] = new State();
            states[current].length = states[last].length + 1;
            states[current].firstPosition = position;

            int parent = last;
            while (parent != -1 && !states[parent].next.containsKey(Integer.valueOf(value))) {
                states[parent].next.put(Integer.valueOf(value), Integer.valueOf(current));
                parent = states[parent].link;
            }
            if (parent == -1) {
                states[current].link = 0;
            } else {
                int next = states[parent].next.get(Integer.valueOf(value)).intValue();
                if (states[parent].length + 1 == states[next].length) {
                    states[current].link = next;
                } else {
                    int clone = size++;
                    states[clone] = new State(states[next]);
                    states[clone].length = states[parent].length + 1;
                    Integer linked = states[parent].next.get(Integer.valueOf(value));
                    while (parent != -1 && linked != null && linked.intValue() == next) {
                        states[parent].next.put(Integer.valueOf(value), Integer.valueOf(clone));
                        parent = states[parent].link;
                        if (parent != -1) {
                            linked = states[parent].next.get(Integer.valueOf(value));
                        }
                    }
                    states[next].link = clone;
                    states[current].link = clone;
                }
            }
            last = current;
        }

        private static final class State {
            final Map<Integer, Integer> next = new HashMap<Integer, Integer>();
            int link;
            int length;
            int firstPosition;

            State() { }

            State(State source) {
                next.putAll(source.next);
                link = source.link;
                length = source.length;
                firstPosition = source.firstPosition;
            }
        }
    }
}
