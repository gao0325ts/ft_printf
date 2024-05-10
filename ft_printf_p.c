/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:23:16 by stakada           #+#    #+#             */
/*   Updated: 2024/05/10 11:27:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer_left(unsigned long long p, int width)
{
	int	len;

	len = 0;
	len += put_hexadecimal(p, 0);
	while (len++ < width)
		if (write(FD, " ", 1) < 0)
			return (-1);
	return (len);
}

int	put_pointer_right(unsigned long long p, int width)
{
	int	len;

	len = 1;
	while (p)
	{
		p = p / 16;
		len++;
	}
	while (len++ < width)
		if (write(FD, " ", 1) < 0)
			return (-1);
	put_hexadecimal(p, 1);
	return (len);
}

int	ft_printf_p(t_info form_list, va_list args)
{
	unsigned long long	p;
	int					len;

	p = va_arg(args, unsigned long long);
	len = 0;
	if (!(form_list.flags == FLAG_HYPHEN || form_list.flags == 0))
		return (-1);
	if (form_list.precision_flag)
		return (-1);
	if (form_list.flags == FLAG_HYPHEN)
		len = put_pointer_left(p, form_list.precision);
	else
		len = put_pointer_left(p, form_list.precision);
	return (len);
}
