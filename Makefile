##
## EPITECH PROJECT, 2025
## minishell2
## File description:
## Makefile
##

NAME = mysh

BUILD = build

LIB = $(BUILD)/lib/my/libmy.a

SRC = $(shell find src/ -type f -name "*.c")
OBJ = $(addprefix $(BUILD)/, $(SRC:.c=.o))

TEST_SRC = $(shell \
	find tests/ -path tests/tester -prune -o -type f -name "*.c" -print)
TEST_SRC += $(filter-out src/main.c, $(SRC))
TEST_OBJ = $(addprefix $(BUILD)/, $(TEST_SRC:.c=.o))

LIB_SRC = $(shell find lib/ -type f -name "*.c")
LIB_OBJ = $(addprefix $(BUILD)/, $(LIB_SRC:.c=.o))

CC = gcc
INCLUDE_DIRS = -Iinclude
WARNING_FLAGS = -Wall -Wextra -Wshadow
CFLAGS = $(INCLUDE_DIRS) $(WARNING_FLAGS)
LDFLAGS = -L$(BUILD)/lib/my -lmy

ifdef DEBUG
CFLAGS += -g3
endif

ifdef COVERAGE
BUILD = build/gcov
CFLAGS += --coverage
LDFLAGS += -lgcov
endif

.PHONY: all re clean fclean tests_run

all: $(BUILD) $(NAME) unit_tests

$(BUILD):
ifdef VERBOSE
	@$(info Creating build directory)
endif
	mkdir -p $@

$(BUILD)/%.o: %.c
ifdef VERBOSE
	@$(info compiling $<)
endif
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(LIB_OBJ)
ifdef VERBOSE
	@$(info Linking lib files into $@)
endif
	ar rc $@ $(LIB_OBJ)

$(NAME): $(LIB) $(OBJ)
ifdef VERBOSE
	@$(info Linking src files into $@)
endif
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

unit_tests: $(LIB) $(TEST_OBJ)
ifdef VERBOSE
	@$(info Linking tests files into $@)
endif
	$(CC) -o $@ $(TEST_OBJ) $(LDFLAGS) -lcriterion

tests_run:
ifdef VERBOSE
	@$(info Running tests)
endif
	$(MAKE) COVERAGE=1 unit_tests
	./unit_tests
	gcovr --exclude tests/

clean:
ifdef VERBOSE
	@$(info Removing build directory)
endif
	rm -rf $(BUILD)/

fclean: clean
ifdef VERBOSE
	@$(info Removing source files)
endif
	rm -f $(NAME)
	rm -f $(LIB)
	rm -f unit_tests

re: fclean all
