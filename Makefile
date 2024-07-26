# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 18:56:34 by npentini          #+#    #+#              #
#    Updated: 2024/07/26 20:13:17 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c utils/so_long_misc.c utils/so_long_print.c utils/so_long_free.c \
	errors/so_long_error.c errors/so_long_error_func1.c errors/so_long_error_func2.c \
	render/so_long_render_punch1.c render/so_long_render_punch2.c render/so_long_win_img_setup.c render/so_long_render.c \
	game/so_long_game_hook.c game/so_long_game_move.c game/so_long_game_move_select_image.c game/so_long_game_rotation.c \
	utils/so_long_free_utils.c utils/so_long_free_utils_mlx.c utils/so_long_init.c
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
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm
MLX_LIB_FILE = $(MLX_DIR)/libmlx.a
MLX_REPO = "https://github.com/42Paris/minilibx-linux.git"

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -I$(MLX_DIR) -o $@ -c $< -g

$(LIBFT_TIMESTAMP): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) -s > /dev/null 2>&1
	@touch $(LIBFT_TIMESTAMP)
	@echo "library has been generated!	☑️"

$(MLX_LIB_FILE):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning MiniLibX repository...🔁"; \
		git clone $(MLX_REPO) > /dev/null 2>&1 && \
		mv minilibx-linux $(MLX_DIR); \
	fi
	@make -C $(MLX_DIR) -s > /dev/null 2>&1
	@echo "MiniLibX library has been built!	☑️"

$(NAME): $(MLX_LIB_FILE) $(OBJS) $(LIBFT_TIMESTAMP)
	@$(COMP) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME) 
	@echo "compilation completed!		☑️"

clean: 
	@$(DELETE) $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean -s > /dev/null 2>&1
	@echo "Objects has been deleted.	✅"
	
fclean: clean
	@$(DELETE) $(NAME)
	@make -C $(LIBFT_PATH) fclean -s > /dev/null 2>&1
	@$(DELETE) $(LIBFT_TIMESTAMP)
	@echo "library has been deleted.	✅"

re: fclean all

.PHONY: all clean fclean re