# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/09/13 16:13:46 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -g
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

LIST = main validation atoilemin roomsfinder validation_errors savelinks \
	solution sup_lem_in bfs_finder print_way work_with_memory findonemoreway \
	save_goodways test\

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
