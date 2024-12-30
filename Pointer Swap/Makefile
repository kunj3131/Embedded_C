CC = gcc

BUILD_DIR = ./build

SRC_FILE = swap_number.c

OBJ_FILE = $(BUILD_DIR)/swap_number.o

ASM_FILE = $(BUILD_DIR)/swap_number.s

PRE_PROCESSOR_FILE = swap_number.i

EXE_FILE = $(BUILD_DIR)/swap_number.exe

all: $(BUILD_DIR) $(PRE_PROCESSOR_FILE) $(ASM_FILE) $(OBJ_FILE) $(EXE_FILE)

$(BUILD_DIR): 
	mkdir -p $(BUILD_DIR)

$(PRE_PROCESSOR_FILE): $(SRC_FILE) 
	$(CC) -E -P $(SRC_FILE) -o $(PRE_PROCESSOR_FILE)

$(ASM_FILE): $(PRE_PROCESSOR_FILE)
	$(CC) -S $(PRE_PROCESSOR_FILE) -o $(ASM_FILE)

$(OBJ_FILE): $(ASM_FILE)
	$(CC) -c $(ASM_FILE) -o $(OBJ_FILE)

$(EXE_FILE): $(OBJ_FILE)
	$(CC) $(OBJ_FILE) -o $(EXE_FILE)

run: $(EXE_FILE)
	./$(EXE_FILE)

clean:
	rm -f -r $(BUILD_DIR) $(PRE_PROCESSOR_FILE) $(ASM_FILE) $(OBJ_FILE) $(EXE_FILE)              