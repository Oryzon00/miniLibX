SRC = main.c	\

OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = output

PATH_MLX =./mlx

LINUX    = -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

%.o: %.c
		$(CC) -I /usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			make -C $(PATH_MLX) all
			$(CC) $(OBJ) mlx/libmlx_Linux.a $(LINUX) -o $(NAME)

clean:
		rm -f $(OBJ) 

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re 
