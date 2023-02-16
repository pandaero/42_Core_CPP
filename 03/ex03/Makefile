# Target executable
NAME	:= diamond

# Compiler
CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= -std=c++98

# Source files
SRC_DIR	:= src/
SRC_PRE	:= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
SRC		:= $(addprefix $(SRC_DIR), $(SRC_PRE))

# Object files
BUILD	:= build/
OBJ_PRE	:= $(SRC_PRE:.cpp=.o)
OBJ		:= $(addprefix $(BUILD), $(OBJ_PRE))

# RULES
# Execute the resulting program
run: all
	./$(NAME)

# Run a valgrind check with output to the terminal
valgrind: all
	./valgrind --show-leak-kinds=all --leak-check=full

# Run a valgrind check with output to a log file
valgrind-log: all
	./valgrind --show-leak-kinds=all --leak-check=full --log-file=$(diamond)-memcheck.log

# Make executable and directories
all: $(NAME) directories

# Make directories
directories: $(BUILD)

# Make target executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(COPT) $(OBJ) -o $(NAME)

# Make required object files
$(addprefix $(BUILD), %.o): $(addprefix $(SRC_DIR), %.cpp) | $(BUILD)
	$(CC) $(CFLAGS) $(COPT) -c $^ -o $@

# Make the build directory
$(BUILD):
	mkdir -p build

# Clean intermediary files
clean:
	rm -rf $(BUILD)

# Clean all files
fclean: clean
	rm -rf $(NAME)

# Re-make everything
re: fclean all

# State rules as non-files
.PHONY: all directories clean fclean re run valgrind valgrind-log
