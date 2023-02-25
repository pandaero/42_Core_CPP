# Target executable
NAME	:= maging

# Compiler 
CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= -std=c++98 #-g -fsanitize=address

# Source files
SRC_DIR	:= src/
SRC_PRE	:= main.cpp
SRC		:= $(addprefix $(SRC_DIR), $(SRC_PRE))

# Object files
BUILD	:= build/
OBJ_PRE	:= $(SRC_PRE:.cpp=.o)
OBJ		:= $(addprefix $(BUILD), $(OBJ_PRE))

# RULES
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
$(patsubst %/,%,$(BUILD)):
	mkdir -p $(BUILD)

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
