NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = ft_printf.c \
       src/print_char.c \
       src/print_nbr.c \
       src/print_str.c \
       src/handle_format.c \
	   src/print_hexa.c \
	   src/print_ptr.c \
	   src/print_unsigned.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c include/ft_printf.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

