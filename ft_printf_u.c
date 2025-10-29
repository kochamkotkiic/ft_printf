#include "ft_printf.h"

static int	leng(long n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		c ++;
	}
	return (c);
}
//co gdy chcemu double wypritnowac np?
char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		len;
	int		i;

	len = leng(n);
	i = len - 1;
	res = malloc(len + 1);
	if (!res)
		return NULL;
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res[len] = '\0';
	while (n != 0)
	{
		res[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
int	ft_putnbr(unsigned int n)
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

int	handle_u(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (ft_putnbr(nbr));
}
