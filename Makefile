# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:47:28 by ceatgie           #+#    #+#              #
#    Updated: 2022/06/12 11:40:18 by ceatgie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	main.c\
			libft/ft_split.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlen.c\
			libft/ft_strnstr.c\
			parsing/ft_get_paths.c\
			parsing/ft_path.c\
			utils/ft_cmd_not_found.c\
			utils/ft_finish.c\
			utils/ft_free_double_array.c\
			utils/ft_how_to_use.c\


OBJS= $(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra
.c.o:
		${CC} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re