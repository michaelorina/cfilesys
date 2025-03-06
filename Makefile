CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/fs.c src/dir_ops.c
OBJ = $(SRC:src/%.c=build/%.o)
TEST_SRC = tests/tests.c
TEST_OBJ = build/tests.o
BIN = build/cfilesys
TEST_BIN = build/test_cfilesys

all: build $(BIN)

$(BIN): build/main.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC) | tests
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf build/*.o build/cfilesys build/test_cfilesys

build:
	mkdir -p build

tests:
	mkdir -p tests
