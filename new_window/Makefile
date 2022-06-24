# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 11:21:24 by sesim             #+#    #+#              #
#    Updated: 2022/06/25 08:12:04 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = new_window.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

all : $(NAME)

fdf: $(OBJS)
	make -C ../mlx
	$(CC) $(CLFAGS) -L ../mlx -l mlx -framework OpenGL -framework AppKit $^ -o $@

clean :
	make -C ../mlx clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : fdf all clean fclean re
