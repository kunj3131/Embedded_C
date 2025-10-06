CC = gcc

BUILD_DIR = ./build

SRC_FILE = bitwise.c

PREPROCESSOR_FILE = bitwise.i

ASM_FILE = $(BUILD_DIR)/bitwise.s

OBJ_FILE = $(BUILD_DIR)/bitwise.o

EXE_FILE = $(BUILD_DIR)/bitwise.exe

all: $(BUILD_DIR) $(PREPROCESSOR_FILE) $(ASM_FILE) $(OBJ_FILE) $(EXE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(PREPROCESSOR_FILE): $(SRC_FILE)
	$(CC) -E -P $(SRC_FILE) -o $(PREPROCESSOR_FILE)

$(ASM_FILE): $(PREPROCESSOR_FILE)
	$(CC) -S $(PREPROCESSOR_FILE) -o $(ASM_FILE)

$(OBJ_FILE): $(ASM_FILE)
	$(CC) -c $(ASM_FILE) -o $(OBJ_FILE)

$(EXE_FILE): $(OBJ_FILE)
	$(CC) $(OBJ_FILE) -o $(EXE_FILE)

run: $(EXE_FILE)
	./$(EXE_FILE)

clean: 
	rm -f -r $(BUILD_DIR) $(PREPROCESSOR_FILE) $(ASM_FILE) $(OBJ_FILE) $(EXE_FILE)					