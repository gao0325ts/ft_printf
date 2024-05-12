/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:23:16 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 19:59:59 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer_left(unsigned long long p, t_spec specs, int *len)
{
	put_hexadecimal(p, specs, len);
	if (*len < 0)
		return ;
	while (*len < specs.width)
	{
		if (write(FD, " ", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
}

void	put_pointer_right(unsigned long long p, t_spec specs, int *len)
{
	(*len)++;
	while (p)
	{
		p = p / 16;
		(*len)++;
	}
	while (*len < specs.width)
	{
		if (write(FD, " ", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
	put_hexadecimal(p, specs, len);
}

int	ft_printf_p(t_spec specs, va_list args)
{
	unsigned long long	p;
	int					len;

	p = va_arg(args, unsigned long long);
	len = 0;
	if (!(specs.flags & FLAG_HYPHEN || specs.flags == 0))
		return (-1);
	if (specs.flags & PRECISION_FLAG)
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_pointer_left(p, specs, &len);
	else
		put_pointer_left(p, specs, &len);
	return (len);
}
