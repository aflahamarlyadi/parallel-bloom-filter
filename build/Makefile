# Define directories
SRC_DIR = ../src
INCLUDE_DIR = ../include
DATA_DIR = ../data

# Define target binaries
BIN_SERIAL = bloom_filter_serial
BIN_PARALLEL = bloom_filter_parallel

# Define source files
SRC_SERIAL = $(SRC_DIR)/bloom_filter_serial.c $(SRC_DIR)/sha256.c $(SRC_DIR)/murmurhash3.c
SRC_PARALLEL = $(SRC_DIR)/bloom_filter_parallel.c $(SRC_DIR)/sha256.c $(SRC_DIR)/murmurhash3.c

# Define object files
OBJ_SERIAL = $(SRC_DIR)/bloom_filter_serial.o $(SRC_DIR)/sha256.o $(SRC_DIR)/murmurhash3.o
OBJ_PARALLEL = $(SRC_DIR)/bloom_filter_parallel.o $(SRC_DIR)/sha256.o $(SRC_DIR)/murmurhash3.o

# Compiler and flags
CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR)
LDFLAGS = -lm
OMP_FLAGS = -fopenmp

# Targets
all: $(BIN_SERIAL) $(BIN_PARALLEL)

$(BIN_SERIAL): $(OBJ_SERIAL)
	$(CC) $(OBJ_SERIAL) -o $(BIN_SERIAL) $(LDFLAGS)

$(BIN_PARALLEL): $(OBJ_PARALLEL)
	$(CC) $(OBJ_PARALLEL) -o $(BIN_PARALLEL) $(OMP_FLAGS) $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(OMP_FLAGS) -c $< -o $@

run: $(BIN_SERIAL) $(BIN_PARALLEL)
	./$(BIN_SERIAL) sha256 $(DATA_DIR)/LITTLE_WOMEN.txt $(DATA_DIR)/MOBY_DICK.txt $(DATA_DIR)/SHAKESPEARE.txt
	./$(BIN_SERIAL) murmurhash3 $(DATA_DIR)/LITTLE_WOMEN.txt $(DATA_DIR)/MOBY_DICK.txt $(DATA_DIR)/SHAKESPEARE.txt
	./$(BIN_PARALLEL) sha256 $(DATA_DIR)/LITTLE_WOMEN.txt $(DATA_DIR)/MOBY_DICK.txt $(DATA_DIR)/SHAKESPEARE.txt
	./$(BIN_PARALLEL) murmurhash3 $(DATA_DIR)/LITTLE_WOMEN.txt $(DATA_DIR)/MOBY_DICK.txt $(DATA_DIR)/SHAKESPEARE.txt

clean:
	/bin/rm -f $(BIN_SERIAL) $(BIN_PARALLEL) $(SRC_DIR)/*.o
