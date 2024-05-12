/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:05 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 16:49:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char_left(char c, int width)
{
	int	len;

	len = 0;
	if (write(FD, &c, 1))
		return (-1);
	len++;
	while (--width)
	{
		if (write(FD, " ", 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	put_char_right(char c, int width)
{
	int	len;

	len = 0;
	while (--width)
	{
		if (write(FD, " ", 1) < 0)
			return (-1);
		len++;
	}
	if (write(FD, &c, 1))
		return (-1);
	len++;
	return (len);
}

int	ft_printf_c(t_spec specs, va_list args)
{
	char	c;
	int		len;

	c = va_arg(args, char);
	len = 0;
	if (!(specs.flags == FLAG_HYPHEN || specs.flags == 0))
		return (-1);
	if (specs.flags & PRECISION_FLAG)
		return (-1);
	if (specs.flags == FLAG_HYPHEN)
		len = put_char_left(c, specs.width);
	else
		len = put_char_right(c, specs.width);
	return (len);
}
