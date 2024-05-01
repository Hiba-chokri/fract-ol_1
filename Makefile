NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address -g3

SRCS = draw_frac.c exit_fract.c init_frac.c utils.c fractol.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
    
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all