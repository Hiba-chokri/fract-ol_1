NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = draw_frac.c exit_fract.c init_frac.c utils.c fractol.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
    
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all