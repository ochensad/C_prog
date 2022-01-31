СС := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -I./inc
UTFLAGS := -lcheck

SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.c)

INC_DIR := ./inc
INCLUDEFILES := $(wildcard $(INC_DIR)/*.h)

UNIT_DIR := ./unit_tests
UNITFILES := $(wildcard $(UNIT_DIR)/*.c)

OUT_DIR := ./out
OBJFILES := $(CFILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

UNIT_OBJ := $(UNITFILES:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)
UNIT_OBJ += $(filter-out $(OUT_DIR)/main.o,$(OBJFILES))

$(OUT_DIR):
	@mkdir -p $@

unit_tests.exe: $(OUT_DIR) $(UNIT_OBJ)
	$(CC) $(UNIT_OBJ) -o $@ $(UTFLAGS)

$(OUT_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_C_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(UNIT_DIR)/%.c $(INCLUDEFILES)
	$(CC) $(CFLAGS) $(UTFLAGS) -c $< -o $@

.PHONY : clean  unit 

unit: unit_tests.exe
	./$^

clean:
	$(RM) *.o *.exe -rf $(OUT_DIR)
