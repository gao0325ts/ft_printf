/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:05 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 12:17:02 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char_left(int c, t_spec specs, int *len)
{
	if (write(FD, &c, 1) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len)++;
	print_spaces(1, specs.width, len);
}

int	put_char_right(int c, t_spec specs, int *len)
{
	print_spaces(1, specs.width, len);
	if (*len < 0)
		return ;
	if (write(FD, &c, 1) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len)++;
}

int	ft_printf_c(t_spec specs, va_list args)
{
	char	c;
	int		len;

	c = va_arg(args, int);
	len = 0;
	if (!(specs.flags & FLAG_HYPHEN || specs.flags == 0) || specs.flags & PREC_FLAG)
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_char_left(c, specs, &len);
	else
		put_char_right(c, specs, &len);
	return (len);
}
