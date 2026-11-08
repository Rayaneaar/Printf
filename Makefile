NAME = printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_strlen.c src/print_char.c src/print_hex.c src/print_nbr.c src/print_str.c src/handle_format.c src/print_ptr.c src/print_unsigned.c src/ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
