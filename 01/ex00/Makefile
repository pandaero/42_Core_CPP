# Target executable
NAME	:= walkingdead

# Compiler 
CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= -std=c++98

# Source files
SRC		:= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

# Build directory for objects
BUILD	:= build/

# Object files
OBJ		:= $(SRC:.cpp=.o)

# RULES
all: $(NAME) directories

# Make directories
directories: $(BUILD)

# Make target executable
$(NAME): $(addprefix $(BUILD), $(OBJ))
	$(CC) $(CFLAGS) $(COPT) $(addprefix $(BUILD), $(OBJ)) -o $(NAME)

# Make required object files
$(addprefix $(BUILD), %.o): %.cpp | $(BUILD)
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
.PHONY: all directories clean fclean re
