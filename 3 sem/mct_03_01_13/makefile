СС := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -I./inc
UTFLAGS := -lcheck

SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.c)

INC_DIR := ./inc
INCFILES := $(wildcard $(INC_DIR)/*.h)

OUT_DIR := ./out
OBJFILES := $(CFILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

UNIT_DIR := ./unit_tests
UNITFILES := $(wildcard $(UNIT_DIR)/*.c)

UNIT_OBJ := $(UNITFILES:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)
UNIT_OBJ += $(filter-out $(OUT_DIR)/main.o,$(OBJFILES))

app.exe: $(OUT_DIR) $(OBJFILES)
	$(CC) -ggdb $(OBJFILES) -o $@

$(OUT_DIR):
	@mkdir -p $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c $(INCFILES)
	$(CC) $(CFLAGS) -c $< -o $@

unit_tests.exe: $(OUT_DIR) $(UNIT_OBJ)
	$(CC) $(UNIT_OBJ) -o $@ $(UTFLAGS)

$(OUT_DIR)/%.o: $(UNIT_DIR)/%.c $(INCFILES)
	$(CC) $(CFLAGS) $(UTFLAGS) -c $< -o $@

.PHONY : clean

clean:
	$(RM) *.exe -rf $(OUT_DIR)