/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:52 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 08:52:06 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str_left(char *s, int strlen, int width)
{
	int	len;

	len = 0;
	while (strlen--)
	{
		if (write(FD, s++, 1) < 0)
			return (-1);
		len++;
	}
	while (width--)
	{
		if (write(FD, " ", 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	put_str_right(char *s, int strlen, int width)
{
	int	len;

	len = 0;
	while (width--)
	{
		if (write(FD, " ", 1) < 0)
			return (-1);
		len++;
	}
	while (strlen--)
	{
		if (write(FD, s++, 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_printf_s(t_spec specs, va_list args)
{
	char	*s;
	int		len;
	int		strlen;

	s = va_arg(args, char *);
	len = 0;
	strlen = ft_strlen(s);
	if (!(specs.flags & FLAG_HYPHEN || specs.flags == 0))
		return (-1);
	if (specs.precision < ft_strlen(s) && specs.flags & PREC_FLAG)
		strlen = specs.precision;
	if (specs.flags & FLAG_HYPHEN)
		len = put_str_left(s, strlen, specs.width - strlen);
	else
		len = put_str_right(s, strlen, specs.width - strlen);
	return (len);
}
