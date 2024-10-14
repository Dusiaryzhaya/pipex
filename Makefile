# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 17:50:06 by anilchen          #+#    #+#              #
#    Updated: 2024/10/02 13:52:01 by anilchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR)

LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SRCS_BONUS = $(wildcard $(SRC_BONUS_DIR)/*.c)
OBJ_BONUS = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

MSG_LIBFT_CREATED = "Libft successfully created."
MSG_EXEC_CREATED = "Executable successfully created."
MSG_BONUS_EXEC_CREATED = "Bonus executable successfully created."
MSG_CLEAN = "Cleaning up..."
MSG_FCLEAN = "Full clean up..."

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_DIR) 
	@echo $(MSG_LIBFT_CREATED)
	
$(NAME): $(OBJ) $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME) 
	@echo $(MSG_EXEC_CREATED)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus: $(LIBFT_NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME_BONUS) 
	@echo $(MSG_BONUS_EXEC_CREATED)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 
	
$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo $(MSG_CLEAN)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo $(MSG_FCLEAN)

re: fclean all

rebonus: fclean $(NAME_BONUS)

.PHONY: all bonus clean fclean re
