# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/09/03 13:54:15 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

LIST = main validation ft_atoilemin\

OBJS = $(addprefix objs/, $(addsuffix .o, $(LIST)))

all: $(NAME)

objs/%.o: srcs/%.c
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): objs make_lib $(OBJS) libft/libft.a
		@gcc -o $(NAME) $(OBJS) $(LIB)
		@echo ✅lem-in compiled!

make_lib:
	@make -C libft

objs:
		@mkdir objs 2> /dev/null || true

clean:
		@make -C libft/ clean
		@rm -rf ./objs/

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
