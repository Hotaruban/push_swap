# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 01:00:03 by jhurpy            #+#    #+#              #
#    Updated: 2023/09/28 20:43:45 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I includes
#S_FLAGS = -g -fsanitize=address,undefined,leak

# Commands
RM = rm -rf
AR = ar rc

# Target library name and directories
NAME = push_swap
LIBFT = ./libft/libft.a
SRC_DIR = src
SRC_FILES =	00_main.c \
			01_join_split.c \
			02_creat_stack.c \
			03_link_list.c \
			04_sort_small.c \
			05_sort_big.c \
			06_sort_stack.c \
			07_set_data.c \
			08_ra_rb_rr.c \
			09_rra_rrb_rrr.c \
			10_pa_pb.c \
			11_error_exit.c \
			12_free.c \
			13_utils.c \

OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = ./libft
INCS = -I$(INC_DIR) -I$(LIBFT_DIR)

# Sources, objects and dependencies
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJECTS = $(SOURCES:%.c=%.o)

NAME_BONUS = checker
SRC_DIR_BONUS = src_bonus
SRC_FILES_BONUS =	main.c \
					actions.c \
					check_action.c \
					create_actions.c \
					sorting.c \
					check_sorting.c \
					create_stack.c \
					errors_exit.c \
					free.c \
					join_split.c \
					link_list.c \

SOURCES_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)

# Default target, build the library
all: $(LIBFT_DIR) $(NAME)

# Rule to build each personal library
$(LIBFT):
	make -C $(LIBFT_DIR)

# Target library build rule
$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCS) -o $(NAME)

#bonus: all $(OBJECTS_BONUS) $(NAME_BONUS)
#	$(CC) $(C_FLAGS) $< $(INCS) -o $(NAME_BONUS)

bonus: all $(OBJECTS_BONUS) $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCS) -o $@

# Clean object files
clean:
	$(RM) ./src/*.o ./src_bonus/*.o
	make clean -C $(LIBFT_DIR)

# Clean object files and target library
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(LIBFT_DIR)/libft.a
	make fclean -C $(LIBFT_DIR)

# Clean and rebuild the target library
re: fclean all

# Check code style
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c ;
	@norminette -R CheckDefine $(INC_DIR)/*.h ;
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR_BONUS)/*.c ;
	@norminette -R CheckDefine $(SRC_DIR_BONUS)/*.h ;
	@norminette -R CheckForbiddenSourceHeader $(LIBFT_DIR)/src/*.c ;
	@norminette -R CheckDefine $(LIBFT_DIR)/includes/*.h

# Phony targets
.PHONY: all clean fclean re norm
