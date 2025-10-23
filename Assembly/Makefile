# =====================================================
# ARM Assembly Starter Project for WSL
# =====================================================

TARGET  := hello
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

AS       := arm-linux-gnueabi-as
LD       := arm-linux-gnueabi-ld
QEMU     := qemu-arm
RM       := rm -rf

SRC      := $(SRC_DIR)/hello.s
OBJ      := $(OBJ_DIR)/hello.o
BIN      := $(BIN_DIR)/$(TARGET)

# Default build rule
all: $(BIN)
	@echo "Build complete: $(BIN)"

# Create directories automatically
$(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@

# Assemble and link
$(OBJ): $(SRC) | $(OBJ_DIR)
	$(AS) -o $@ $<

$(BIN): $(OBJ) | $(BIN_DIR)
	$(LD) -o $@ $<

# Run with QEMU
run: $(BIN)
	@echo "Running under QEMU..."
	@$(QEMU) $(BIN)

# Clean
clean:
	@$(RM) $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned build artifacts."

.PHONY: all run clean
