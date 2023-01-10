# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataji <ataji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 23:19:39 by ataji             #+#    #+#              #
#    Updated: 2023/01/10 14:50:39 by ataji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
INC = cub3d/cub3d.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = libft/ft_split.c\
	libft/ft_splitnewline.c\
	libft/ft_strcmp.c\
	libft/ft_substr.c\
	libft/ft_atoi.c\
	libft/ft_strlen.c\
	libft/ft_strcpy.c\
	libft/ft_strdup.c\
	libft/ft_isdigit.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	parsingcub3d/cub3d.c\
	parsingcub3d/cub3d_utils.c\
	parsingcub3d/compass_colore.c\
	parsingcub3d/counters.c\
	parsingcub3d/parser.c\
	parsingcub3d/checkzero.c\
	parsingcub3d/parsetwopartsofmap.c\
	parsingcub3d/main.c
	
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS) $(NAME)

re : fclean all