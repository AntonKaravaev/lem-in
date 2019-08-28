# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 15:14:49 by crenly-b          #+#    #+#              #
#    Updated: 2019/08/25 14:27:52 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC_PATH = includes/
INC = $(addprefix -I, $(INC_PATH))
FLAGS = -Wall -Wextra -Werror
SRC = find_ch.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memdel.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
	ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
	ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	length_int.c super_check.c ft_memcpy.c ft_memchr.c ft_memcmp.c get_next_line.c\
	ft_str2del.c

OBJ = $(SRC:.c=.o)
OBJ_PATH = objects/

.PHONY: all clean fclean re move movedel

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ✅libft compiled!


move:
	mkdir $(OBJ_PATH) 2> /dev/null || true
	mv $(OBJ) $(OBJ_PATH)

movedel:
	@rm -rf $(OBJ_PATH)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
