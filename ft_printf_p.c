/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilka <emilka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:41:26 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/29 23:43:55 by emilka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_long(unsigned long ptr)
{
	int			i;
	int			j;

	char		*base;
	char		*hex;
	char		tmp;

	base = "0123456789abcdef";
	hex = malloc(17);
	if (!hex)
		return (NULL);
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
	addr = conv_long(ptr);
	if (!addr)
		return (0);
	len = write(1, "0x", 2);
	i = 0;
	while (addr[i])
		len += ft_putchar(addr[i++]);
	free(addr);
	return (len);
}

int	handle_p(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putvoid((unsigned long)ptr));
}
