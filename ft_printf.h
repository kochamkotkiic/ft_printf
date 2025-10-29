#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	handle_c(va_list args);
int	ft_putnbr(int n);
int	handle_d(va_list args);
int	ft_putstr(char *s);
int	handle_s(va_list args);

#endif
