CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIB_FILES = $(wildcard $(LIB_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
LIB_OBJ_FILES = $(patsubst $(LIB_DIR)/%.c, $(BUILD_DIR)/%.o, $(LIB_FILES))

all: run

run: $(OBJ_FILES) $(LIB_OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I lib

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f program $(BUILD_DIR)/*.o

.PHONY: all clean

ifeq "$(wildcard $(BUILD_DIR))" ""
$(info Creating build directory...)
$(shell mkdir $(BUILD_DIR))
endif
