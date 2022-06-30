# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 11:21:24 by sesim             #+#    #+#              #
#    Updated: 2022/06/26 11:22:55 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJ_E = euler_isometric.o

OBJ_V = vector_isometric.o

NAME = vec euler

all : $(NAME)

euler : $(OBJ_E)
	make -C ../mlx
	$(CC) $(CLFAGS) -L ../mlx -l mlx -framework OpenGL -framework AppKit $^ -o $@
	
vec : $(OBJ_V)
	$(CC) $(CLFAGS) -L ../mlx -l mlx -framework OpenGL -framework AppKit $^ -o $@

euler_isometric.o : euler_isometric.c
	$(CC) $(CFLAGS) -c $^

vector_isometric.o : vector_isometric.c
	$(CC) $(CFLAGS) -c $^

clean :
	make -C ../mlx clean
	$(RM) $(OBJ_V) $(OBJ_E)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : euler vec all clean fclean re
