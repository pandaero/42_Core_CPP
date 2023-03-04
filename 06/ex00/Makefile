# Target executables
NAME1	:= conversion
NAME2	:= tests

# Compiler 
CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= -std=c++98 #-g -fsanitize=address

# Include files
INC_DIR := include/
INC_PRE := Types.hpp Conversions.hpp ScalarConverter.hpp
INC		:= $(addprefix $(INC_DIR), $(INC_PRE))

# Source files
SRC_DIR	:= src/
SRC_PRE	:= Types.cpp Conversions.cpp ScalarConverter.cpp
SRC		:= $(addprefix $(SRC_DIR), $(SRC_PRE))

# Object files
BUILD	:= build/
OBJ_PRE	:= $(SRC_PRE:.cpp=.o)
OBJ		:= $(addprefix $(BUILD), $(OBJ_PRE))

# OS-Protection
ifeq ($(shell uname), Linux)
	BUILD_DIR	:= $(BUILD)
else
	BUILD_DIR	:= $(patsubst %/, %, $(BUILD))
endif

# RULES
all: $(NAME1) $(NAME2) directories

# Make directories
directories: $(BUILD)

# Make target executable
$(NAME1): $(OBJ) $(addprefix $(BUILD), main.o)
	$(CC) $(CFLAGS) $(COPT) $^ -o $(NAME1)

# Make target executable
$(NAME2): $(OBJ) $(addprefix $(BUILD), test.o)
	$(CC) $(CFLAGS) $(COPT) $^ -o $(NAME2)

# Make the main object file
$(addprefix $(BUILD), main.o): $(addprefix $(SRC_DIR), main.cpp) $(INC) | $(BUILD)
	$(CC) $(CFLAGS) $(COPT) -c $< -o $@

# Make the test object file
$(addprefix $(BUILD), test.o): $(addprefix $(SRC_DIR), test.cpp) $(INC) | $(BUILD)
	$(CC) $(CFLAGS) $(COPT) -c $< -o $@

# Make required object files
$(addprefix $(BUILD), %.o): $(addprefix $(SRC_DIR), %.cpp) $(addprefix $(INC_DIR), %.hpp) | $(BUILD)
	$(CC) $(CFLAGS) $(COPT) -c $< -o $@

# Make the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean intermediary files
clean:
	rm -rf $(BUILD)

# Clean all files
fclean: clean
	rm -rf $(NAME)

# Re-make everything
re: fclean all

# State rules as non-files
.PHONY: all directories clean fclean re
