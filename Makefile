NAME =  libftprintf.a

SRC = ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_p.c ft_printf_s.c \
	  ft_printf_u.c ft_printf_x.c ft_printf_X.c test_printf.c

OBJ = $(SRC:.c=.o)

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
