СС := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -I./inc
GCOVFLAGS := -O0 --coverage 
UTFLAGS := -lcheck
STATFLAGS := ar rc
IND_FLAG := ranlib
DYNFLAGS := -Wl,--subsystem,windows
DEF_FLAGS := -D EXPORT_LIB
LIB_FLAGS := -L. ./out -ltask


# Получение переменных с файлами

FUNC_DIR := func_tests

SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.c)

INC_DIR := ./inc
INCLUDEFILES := $(wildcard $(INC_DIR)/*.h)

INCLUDE_C_FILES := $(filter-out $(INC_DIR)/check_%.h,$(INCLUDEFILES))
INCLUDE_UNIT_FILES := $(filter $(INC_DIR)/check_%.h,$(INCLUDEFILES))

UNIT_DIR := ./unit_tests
UNITFILES := $(wildcard $(UNIT_DIR)/*.c)

OUT_DIR := ./out
OBJFILES := $(CFILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

LIB_DIR := ./lib
DIN_LIB := $(LIB_DIR)/io_lib.c
DYN_LIB_NAME := libtask.dll
STAT_LIB := $(LIB_DIR)/task_lib.c
STAT_LIB_NAME := $(OUT_DIR)/libtask.a

UNIT_OBJ := $(UNITFILES:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)
UNIT_OBJ += $(filter-out $(OUT_DIR)/main.o,$(OBJFILES))

# Функции
app.exe : $(OUT_DIR) $(OBJFILES) $(STAT_LIB_NAME) $(DYN_LIB_NAME)
	$(CC) -ggdb $(OBJFILES) $(STAT_LIB_NAME) $(DYN_LIB_NAME) -o $@

$(OUT_DIR):
	@mkdir -p $@

$(OUT_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_C_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

$(STAT_LIB_NAME) : $(STAT_LIB)
	$(CC) $(CFLAGS) -c $< -o $(OUT_DIR)/task_lib.o
	$(STATFLAGS) $@ $(OUT_DIR)/task_lib.o
	$(IND_FLAG) $@

$(DYN_LIB_NAME) : $(DIN_LIB)
	$(CC) $(CFLAGS) $(DEF_FLAGS) -c $< -o $(OUT_DIR)/io_lib.o
	$(CC) -shared $(OUT_DIR)/io_lib.o $(DYNFLAGS) -o $@


unit_tests.exe: $(OUT_DIR) $(UNIT_OBJ) $(STAT_LIB_NAME) $(DYN_LIB_NAME)
	$(CC) $(UNIT_OBJ) $(STAT_LIB_NAME) -o $@ $(UTFLAGS)

$(OUT_DIR)/%.o: $(UNIT_DIR)/%.c $(INCLUDE_UNIT_FILES) $(INCLUDE_C_FILES)
	$(CC) $(CFLAGS) $(UTFLAGS) -c $< -o $@

func_tests.exe: $(OUT_DIR) $(OBJFILES) $(STAT_LIB_NAME) $(DYN_LIB_NAME)
	$(CC) $(GCOVFLAGS) $(OBJFILES) $(STAT_LIB_NAME) $(DYN_LIB_NAME) -o $@


.PHONY : clean func unit flag

coverage: func_tests.exe

func: coverage func_tests.exe 
	cd $(FUNC_DIR) && ./all_test.sh
	gcov -f -r $(OUT_DIR)/*.gcno
	mv *.gcov $(OUT_DIR)

unit: unit_tests.exe
	./$^

clean:
	$(RM) *.o *.exe *.dll *.a -rf $(OUT_DIR)
