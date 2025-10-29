#include "ft_printf.h"

static char	*allocate(int len)
{
	char	*res;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*res;

	nb = n;
	len = leng(nb);
	res = allocate(len);
	if (!res)
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

int	ft_putnbr_int(int n)
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
	return (ft_putnbr_int(nbr));
}
