JAVAC ?= javac
JAVACFLAGS ?= --release 8 -Xlint:-options
JAVA ?= java
OUT ?= build
SOURCES := $(shell find src/main/java fuzz -name '*.java')
TEST_SOURCES := $(shell find src/test/java -name '*.java')
.PHONY: all test clean seeds
all:
	mkdir -p $(OUT)/classes
	$(JAVAC) $(JAVACFLAGS) -d $(OUT)/classes $(SOURCES)
	jar cf $(OUT)/ratchet.jar -C $(OUT)/classes .
test: all
	mkdir -p $(OUT)/test-classes
	$(JAVAC) $(JAVACFLAGS) -cp $(OUT)/classes -d $(OUT)/test-classes $(TEST_SOURCES)
	$(JAVA) -cp $(OUT)/classes:$(OUT)/test-classes ratchet.RatchetTest
seeds: all
	$(JAVA) -cp $(OUT)/classes ratchet.SeedGenerator
clean:
	rm -rf $(OUT)
