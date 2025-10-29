/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:41:26 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/29 14:10:54 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv(unsigned long ptr)
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

int	ft_putvoid(unsigned long ptr)
{
	char	*addr;
	int		len;
	int		i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = conv(ptr);
	len = 2;
	i = 0;
	write(1, "0x", 2);
	while (addr[i])
	{
		len += ft_putchar(addr[i]);
		i ++;
	}
	return (len);
}

int	handle_p(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putvoid((unsigned long)ptr));
}
