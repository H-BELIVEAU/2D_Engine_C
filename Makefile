# Dossiers
SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
OBJ_DIR := $(BIN_DIR)/obj

# Liste récursive des .c via wildcard GNU Make (MSYS2 compatible)
SRCS := $(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/*/*.c) \
		$(wildcard $(SRC_DIR)/*/*/*.c)

# Conversion .c → .o dans bin/obj
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TARGET := $(BIN_DIR)/prog.exe

CFLAGS := -Wall -Wextra -I$(INC_DIR)
LDFLAGS := -lSDL3

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	gcc $(OBJS) $(LDFLAGS) -o $@

# Compilation dans bin/obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all run clean
