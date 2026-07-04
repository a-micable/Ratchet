CC ?= gcc
CFLAGS ?= -Wall -Werror -Wextra -pedantic -std=c11 -O2 -g
CPPFLAGS ?= -Iinclude
SRC_LIB = src/parser.c src/patcher.c src/differ.c src/resolver.c src/compressor.c src/registry.c src/crc32.c
OBJ_LIB = $(SRC_LIB:.c=.o)
.PHONY: all test clean seeds
all: ratchet tests/test_ratchet tools/generate_seeds
ratchet: $(OBJ_LIB) src/cli.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(OBJ_LIB) src/cli.o
tests/test_ratchet: $(OBJ_LIB) tests/test_ratchet.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(OBJ_LIB) tests/test_ratchet.o
tools/generate_seeds: $(OBJ_LIB) tools/generate_seeds.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(OBJ_LIB) tools/generate_seeds.o
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
test: tests/test_ratchet
	./tests/test_ratchet
seeds: tools/generate_seeds
	./tools/generate_seeds
clean:
	rm -f src/*.o tests/*.o tools/*.o ratchet tests/test_ratchet tools/generate_seeds
