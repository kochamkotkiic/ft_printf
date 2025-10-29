#include "ft_printf.h"

char	*conv(unsigned int ptr)
{
	int			i;
	int			j;

	char		*base;
	static char	hex[17];
	char		tmp;

	base = "0123456789abcdef";
	i = 0;
	j = 0;
	if (ptr == 0)
		hex[i++] = '0';
	while (ptr > 0)
	{
		hex[i++] = base[ptr % 16];
		ptr /= 16;
	}
	hex[i] = '\0';
	while (j < i / 2)
	{
		tmp = hex[j];
		hex[j] = hex[i - 1 - j];
		hex[i - 1 - j] = tmp;
		j ++;
	}
	return (hex);
}

int	ft_putxlower(unsigned int ptr)
{
	char	*addr;
	int		len;
	int		i;

	addr = conv(ptr);
	len = 0;
	i = 0;
	while (addr[i])
	{
		len += ft_putchar(addr[i]);
		i ++;
	}
	return (len);
}

int	handle_x(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (ft_putxlower(nbr));
}
