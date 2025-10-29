#include "ft_printf.h"

int	ft_putchar(char c)
{
	ssize_t	res;

	res = write(1, &c, 1);
	if (res == -1)
		return  (0);
	return (1);
}

int	handle_c(va_list args)
{
	int	charr;

	charr = va_arg(args, int);
	return (ft_putchar((char)charr));
}
