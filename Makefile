# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataji <ataji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 23:19:39 by ataji             #+#    #+#              #
#    Updated: 2023/01/15 13:44:39 by ataji            ###   ########.fr        #
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
	parsingcub3d/dividingmap.c\
	parsingcub3d/checkzero.c\
	parsingcub3d/parsetwopartsofmap.c\
	raycasting/check_wall_utils.c\
	raycasting/check_wall.c\
	raycasting/handler.c\
	raycasting/mini_map.c\
	raycasting/mlx_win.c\
	raycasting/ply_positions.c\
	raycasting/render_utils.c\
	raycasting/render.c\
	raycasting/utils.c\
	raycasting/generate3dprojection.c\
	main.c
	
OBJS = $(SRCS:%.c=%.o)

all : $(NAME) clean

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^ -fsanitize=address -g

%.o : %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ -fsanitize=address -g

clean :
	@$(RM) $(OBJS)

fclean :
	@$(RM) $(OBJS) $(NAME)

re : fclean all