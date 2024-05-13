/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:52 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 12:54:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_str_left(char *s, t_spec specs, int *len, int strlen)
{
	while (strlen--)
	{
		if (write(FD, s++, 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
	print_spaces(*len, specs.width, len);
}

void	put_str_right(char *s, t_spec specs, int *len, int strlen)
{
	print_spaces(strlen, specs.width, len);
	if (*len < 0)
		return ;
	while (strlen--)
	{
		if (write(FD, s++, 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
}

void	print_null(int *len)
{
	if (write(FD, "(null)", 6) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) = 6;
}

int	ft_printf_s(t_spec specs, va_list args)
{
	char	*s;
	int		len;
	int		strlen;

	s = va_arg(args, char *);
	len = 0;
	if (!(specs.flags & FLAG_HYPHEN || specs.flags == 0))
		return (-1);
	if (!s)
		print_null(&len);
	strlen = ft_strlen(s);
	if (specs.flags & PREC_FLAG && specs.precision < strlen)
		strlen = specs.precision;
	if (specs.flags & FLAG_HYPHEN)
		put_str_left(s, specs, &len, strlen);
	else
		put_str_right(s, specs, &len, strlen);
	return (len);
}