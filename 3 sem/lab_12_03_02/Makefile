СС := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic
DYNFLAGS := -Wl,--subsystem,windows


OUT_DIR := ./out

LIB_DIR := ./lib
DIN_LIB := $(LIB_DIR)/task.c
DYN_LIB_NAME := $(LIB_DIR)/libtask.dll

$(OUT_DIR):
	@mkdir -p $@

$(DYN_LIB_NAME) : $(DIN_LIB)
	$(CC) $(CFLAGS) -c $< -o $(OUT_DIR)/task.o
	$(CC) -shared $(OUT_DIR)/task.o $(DYNFLAGS) -o $@

PHONY:

run: $(OUT_DIR) $(DYN_LIB_NAME)
	python3 main.py

clean:
	$(RM) *.o *.exe *.dll *.a -rf $(OUT_DIR)