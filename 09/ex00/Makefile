# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 09:23:13 by pandalaf          #+#    #+#              #
#    Updated: 2023/03/18 18:39:50 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target executable
NAME	:= btc

# Compiler 
CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra
COPT	:= -std=c++98

# Default arguments
ifndef	ARGS
	ARGS = input/input.txt
endif

# Debug and leak-checking options. Usage: make DEBUG=1 LEAKS=1
ifeq ($(DEBUG), 1)
	COPT += -g
endif
ifeq ($(LEAKS), 1)
	COPT += -fsanitize=address
endif

# Include files
INC_DIR := include/
INC_PRE := BitcoinExchange.hpp
INC		:= $(addprefix $(INC_DIR), $(INC_PRE))

# Source files
SRC_DIR	:= src/
SRC_PRE	:= main.cpp BitcoinExchange.cpp
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
all: $(NAME) directories

run: all
	./$(NAME) $(ARGS)

# Make directories
directories: $(BUILD)

# Make target executable
$(NAME): $(OBJ) #$(addprefix $(BUILD), main.o)
	$(CC) $(CFLAGS) $(COPT) $^ -o $(NAME)

# Make the main object file
$(addprefix $(BUILD), main.o): $(addprefix $(SRC_DIR), main.cpp) $(INC) | $(BUILD)
	$(CC) $(CFLAGS) $(COPT) $(DEFS) -c $< -o $@

# Make required object files
$(addprefix $(BUILD), %.o): $(addprefix $(SRC_DIR), %.cpp) $(addprefix $(INC_DIR), %.hpp) | $(BUILD)
	$(CC) $(CFLAGS) $(COPT) -c $< -o $@

# Make the build directory
$(BUILD):
	mkdir -p $(BUILD_DIR)

# Clean intermediary files
clean:
	rm -rf $(BUILD_DIR)

# Clean all files
fclean: clean
	rm -rf $(NAME)

# Re-make everything
re: fclean all

# State rules as non-files
.PHONY: all run directories clean fclean re
