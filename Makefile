# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/08/28 15:43:11 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

LIST = main\

OBJS = $(addprefix objs/, $(addsuffix .o, $(LIST)))

all: $(NAME)

objs/%.o: srcs/%.c
		@echo
		@echo 🇷🇺 🇷🇺 🇷🇺 🇷🇺 🇷🇺 🇷🇺 🇷🇺 🇷🇺 🇷🇺
		@echo Recompiled these files:
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): objs $(OBJS)
		@echo "-----------------------";
		@make -C libft
		@gcc -o $(NAME) $(OBJS) $(LIB)
		@echo ✅lem-in compiled!
		@echo "-----------------------";
		@echo

objs:
		@mkdir objs

clean:
		@make -C libft/ clean
		@rm -rf ./objs/

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
