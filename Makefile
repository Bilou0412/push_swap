# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:41:57 by soutin            #+#    #+#              #
#    Updated: 2023/06/30 12:31:10 by bmoudach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		:=		src
OBJ_DIR		:=		obj
LIBFT_DIR	=		libft

NAME		=		push_swap
SRC			=		$(wildcard $(SRC_DIR)/*.c)
OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT		=		libft/libft.a

CPPFLAGS	=		-I./include -I./libft/include
CFLAGS		=		-Wall -Werror -Werror -g3

$(NAME):			$(OBJ) 
						$(MAKE) -C $(LIBFT_DIR)
						$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

all:				$(NAME)

clean:
					rm -rf $(OBJ_DIR)
					$(MAKE) clean -C $(LIBFT_DIR)

fclean:				clean
						rm -f $(NAME)
						$(MAKE) fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean re
