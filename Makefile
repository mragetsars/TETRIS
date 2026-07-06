CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS ?=

BUILD_DIR := build
TARGET := $(BUILD_DIR)/tetris
TEST_TARGET := $(BUILD_DIR)/test_tetris_logic

SRC := src/main.c src/tetris.c src/console.c
TEST_SRC := tests/test_tetris_logic.c src/tetris.c src/console.c

.PHONY: all clean run test

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

$(TEST_TARGET): $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
