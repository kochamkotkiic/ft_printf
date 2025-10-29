#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(write(1, "(null)", 6));
	while(s[i])
	{
		ft_putchar(s[i]);
		i ++;
	}
	return (i);
}

int	handle_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (ft_putstr(str));
}
