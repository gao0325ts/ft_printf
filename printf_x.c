/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:21 by stakada           #+#    #+#             */
/*   Updated: 2024/05/17 23:31:25 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex_left(unsigned long long num, t_spec specs, int *len)
{
	if (num)
		print_prefix(specs, len);
	if (*len < 0)
		return ;
	print_zero_paddings(count_digits_hex(num, specs), specs.precision, len);
	if (*len < 0)
		return ;
	if (!(!num && specs.flags & PREC_FLAG && !specs.precision))
		print_hexadecimal(num, specs, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_hex_right_1(unsigned long long num, t_spec specs, int *len)
{
	print_spaces(count_padded_len(specs, count_digits_hex(num, specs), 0),
		specs.width, len);
	if (*len < 0)
		return ;
	if (num)
		print_prefix(specs, len);
	if (*len < 0)
		return ;
	print_zero_paddings(count_digits_hex(num, specs), specs.precision, len);
	if (*len < 0)
		return ;
	if (!(!num && specs.flags & PREC_FLAG && !specs.precision))
		print_hexadecimal(num, specs, len);
}

void	put_hex_right_2(unsigned long long num, t_spec specs, int *len)
{
	if (specs.flags & FLAG_ZERO)
	{
		if (num)
			print_prefix(specs, len);
		print_zero_paddings(count_padded_len(specs, count_digits_hex(num,
					specs), 0), specs.width, len);
		if (*len < 0)
			return ;
	}
	else
	{
		print_spaces(count_padded_len(specs, count_digits_hex(num, specs), 0),
			specs.width, len);
		if (*len < 0)
			return ;
		if (num)
			print_prefix(specs, len);
		if (*len < 0)
			return ;
	}
	if (!(!num && specs.flags & PREC_FLAG && !specs.precision))
		print_hexadecimal(num, specs, len);
}

int	ft_printf_x(t_spec specs, va_list args)
{
	unsigned int	x;
	int				len;

	x = va_arg(args, unsigned int);
	len = 0;
	if (x == 0)
		specs.flags &= ~FLAG_HASH;
	if (specs.flags & FLAG_HYPHEN)
		put_hex_left(x, specs, &len);
	else if (specs.flags & PREC_FLAG)
		put_hex_right_1(x, specs, &len);
	else
		put_hex_right_2(x, specs, &len);
	return (len);
}
