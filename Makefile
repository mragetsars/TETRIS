CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS ?=

OBJ_DIR := obj

ifeq ($(OS),Windows_NT)
EXE_EXT := .exe
else
EXE_EXT := .out
endif

TARGET := tetris$(EXE_EXT)
TEST_TARGET := $(OBJ_DIR)/test_tetris_logic$(EXE_EXT)

SRC := src/main.c src/tetris.c src/console.c
TEST_SRC := tests/test_tetris_logic.c src/tetris.c src/console.c

.PHONY: all clean run test

all: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

$(TEST_TARGET): $(TEST_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
	find $(OBJ_DIR) -type f ! -name '.gitkeep' -delete 2>/dev/null || true
