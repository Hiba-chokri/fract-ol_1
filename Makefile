NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

SRCS = draw_frac.c hooks.c init_frac.c utils.c fractol.c calculate_ships.c coloring.c ft_parsing.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -os -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
    
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all