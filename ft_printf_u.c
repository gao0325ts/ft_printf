/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:25:55 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 22:26:54 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_u_dec_left(unsigned int num, t_spec specs, int *len)
{
	if (specs.flags & PREC_FLAG)
	{
		print_zero_paddings(count_digits_u(num), specs.precision, len);
		if (*len < 0)
			return ;
		print_u_decimal(num, len);
		if (*len < 0)
			return ;
		print_spaces(count_digits_u(num), specs.width, len);
	}
	else
	{
		print_u_decimal(num, len);
		if (*len < 0)
			return ;
		print_spaces(count_digits_u(num), specs.width, len);
	}
}

void	put_u_dec_right(unsigned int num, t_spec specs, int *len)
{
	if (specs.flags & PREC_FLAG)
	{
		print_spaces(count_padded_len(specs, count_digits_u(num), 0),
			specs.precision, len);
		if (*len < 0)
			return ;
		print_zero_paddings(count_digits_u(num), specs.width, len);
		if (*len < 0)
			return ;
	}
	else
	{
		if (specs.flags & FLAG_ZERO)
			print_zero_paddings(count_digits_u(num), specs.width, len);
		else
			print_spaces(count_digits_u(num), specs.width, len);
		if (*len < 0)
			return ;
	}
	print_u_decimal(num, len);
}

int	ft_printf_u(t_spec specs, va_list args)
{
	unsigned int	u;
	int				len;

	u = va_arg(args, unsigned int);
	len = 0;
	if (!(specs.flags & FLAG_HYPHEN || specs.flags & FLAG_ZERO
			|| specs.flags == 0))
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_u_dec_left(u, specs, &len);
	else
		put_u_dec_right(u, specs, &len);
	return (len);
}
