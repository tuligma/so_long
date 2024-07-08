# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 18:56:34 by npentini          #+#    #+#              #
#    Updated: 2024/07/08 20:27:30 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
INCS = includes
COMP = cc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
OBJ_DIR = objects
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(COMP) $(CFLAGS) $(INCS) -o $@ -c $< -g

$(LIBFT):
	@make -C $(LIBFT_PATH) -s > /dev/null 2>&1
	@echo "library has been generated!"

$(NAME): $(OBJS) $(LIBFT)
	@$(COMP) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "compilation completed"
clean: 
	@$(DELETE) $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean -s > /dev/null 2>&1
	@echo "Objects has been deleted"
	
fclean:
	@$(DELETE) $(NAME)
	@make -C $(LIBFT_PATH) fclean -s > /dev/null 2>&1
	@echo "library has been deleted"

re: fclean all

.PHONY: all clean fclean re