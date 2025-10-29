#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	handle_c(va_list args);
int	ft_putnbr_int(int n);
int	handle_d(va_list args);
int	ft_putstr(char *s);
int	handle_s(va_list args);
int	handle_p(va_list args);
int	ft_putxlower(unsigned int ptr);
int	ft_putxupper(unsigned int ptr);
int	handle_x(va_list args);
int	handle_X(va_list args);
int	ft_putvoid(unsigned long ptr);
char	*ft_utoa(unsigned int n);
int	ft_putnbr_unsigned(unsigned int n);
int	handle_u(va_list args);
int	leng(long n);
char	*conv(unsigned int ptr);
char	*conv_long(unsigned long ptr);
char	*conv_upper(unsigned int ptr);

#endif
