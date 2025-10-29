#include "ft_printf.h"

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
				printed += handle_c(args);
			else if (format[i] == 's')
				printed += handle_s(args);
			else if (format[i] == 'd' || format[i] == 'i')
				printed += handle_d(args);
			else if (format[i] == 'p')
				printed += handle_p(args);
			else if (format[i] == 'x')
				printed += handle_x(args);
			else if (format[i] == 'u')
				printed += handle_u(args);
			else if (format[i] == 'X')
				printed += handle_X(args);
			else if (format[i] == '%')
			{
				printed += 1;
				write(1, "%", 1);
			}
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
