NAME =  libftprintf

SRC = ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_p.c ft_printf_s.c \
	  ft_printf_u.c ft_printf_x.c ft_printf_X.c test_printf.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re