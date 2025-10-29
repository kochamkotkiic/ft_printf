#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*str;
	int	len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	handle_d(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	return (ft_putnbr(nbr));
}
