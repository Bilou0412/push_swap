# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoudach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 16:59:48 by bmoudach          #+#    #+#              #
#    Updated: 2023/06/16 10:58:27 by bmoudach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	srcs
OBJS_DIR	=	objs

NAME		=	libft.a
SRCS		:=	$(wildcard $(SRCS_DIR)/*.c)
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CFLAGS		=	-Wall -Wextra -Werror -I./include
CC		= 	gcc

$(NAME):		$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re



