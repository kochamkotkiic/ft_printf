#include "../libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i ++;
			if (format[i]=='c')
				printed += ft_putchar(va_arg(args, char));//pobiera arg po ,
			//...
		}
		else
		{
			printed += ft_putchar(format[i]);
		}
		i ++;
	}
	va_end(args);
	return (printed);
}
