# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 18:56:34 by npentini          #+#    #+#              #
#    Updated: 2024/07/26 03:18:04 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c utils/so_long_misc.c utils/so_long_print.c utils/so_long_free.c errors/so_long_error.c errors/so_long_error_func1.c errors/so_long_error_func2.c render/so_long_render_punch1.c render/so_long_render_punch2.c render/so_long_win_img_setup.c render/so_long_render.c
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_TIMESTAMP = $(LIBFT_PATH)/.libf_timestamp
INCS = includes/
COMP = gcc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
OBJ_DIR = objects
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
MLX_DIR = ./mlx
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz -lGL -lGLU

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -I$(MLX_DIR) -o $@ -c $< -g

$(LIBFT_TIMESTAMP): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) -s > /dev/null 2>&1
	@touch $(LIBFT_TIMESTAMP)
	@echo "library has been generated!"

$(NAME): $(OBJS) $(LIBFT_TIMESTAMP)
	@$(COMP) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME) 
	@echo "compilation completed"

clean: 
	@$(DELETE) $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean -s > /dev/null 2>&1
	@echo "Objects has been deleted"
	
fclean: clean
	@$(DELETE) $(NAME)
	@make -C $(LIBFT_PATH) fclean -s > /dev/null 2>&1
	@$(DELETE) $(LIBFT_TIMESTAMP)
	@echo "library has been deleted"

re: fclean all

.PHONY: all clean fclean re