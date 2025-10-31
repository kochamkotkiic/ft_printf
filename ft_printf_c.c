/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <emurbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:07:27 by emurbane          #+#    #+#             */
/*   Updated: 2025/10/31 15:08:48 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ssize_t	res;

	res = write(1, &c, 1);
	if (res == -1)
		return (0);
	return (1);
}

int	handle_c(va_list args)
{
	int	charr;

	charr = va_arg(args, int);
	return (ft_putchar((char)charr));
}
