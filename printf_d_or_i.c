/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:12 by stakada           #+#    #+#             */
/*   Updated: 2024/05/15 21:33:01 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_symbol(int flags, int num, int *len)
{
	if (num < 0)
	{
		if (write(FD, "-", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
	}
	else if (flags & FLAG_PLUS)
	{
		if (write(FD, "+", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
	}
	else if (flags & FLAG_SPACE)
	{
		if (write(FD, " ", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
	}
	(*len)++;
}

void	put_dec_left(t_spec specs, int num, int *len)
{
	if (num < 0 || specs.flags & FLAG_PLUS || specs.flags & FLAG_SPACE)
		print_symbol(specs.flags, num, len);
	if (*len < 0)
		return ;
	print_zero_paddings(count_abs_digits(num, specs), specs.precision, len);
	if (*len < 0)
		return ;
	if (!(!num && specs.flags & PREC_FLAG && !specs.precision))
		print_decimal(num, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_dec_right_1(t_spec specs, int num, int *len)
{
	print_spaces(count_padded_len(specs, count_abs_digits(num, specs), num < 0),
		specs.width, len);
	if (*len < 0)
		return ;
	if (num < 0 || specs.flags & FLAG_PLUS || specs.flags & FLAG_SPACE)
		print_symbol(specs.flags, num, len);
	if (*len < 0)
		return ;
	print_zero_paddings(count_abs_digits(num, specs), specs.precision, len);
	if (*len < 0)
		return ;
	if (!(!num && specs.flags & PREC_FLAG && !specs.precision))
		print_decimal(num, len);
}

void	put_dec_right_2(t_spec specs, int num, int *len)
{
	if (specs.flags & FLAG_ZERO)
	{
		if (num < 0 || specs.flags & FLAG_PLUS || specs.flags & FLAG_SPACE)
			print_symbol(specs.flags, num, len);
		if (*len < 0)
			return ;
		print_zero_paddings(count_padded_len(specs, count_abs_digits(num,
					specs), num < 0), specs.width, len);
	}
	else
	{
		print_spaces(count_padded_len(specs, count_abs_digits(num, specs),
				num < 0), specs.width, len);
		if (*len < 0)
			return ;
		if (num < 0 || specs.flags & FLAG_PLUS || specs.flags & FLAG_SPACE)
			print_symbol(specs.flags, num, len);
	}
	if (*len < 0)
		return ;
	if (!(!num && specs.flags & PREC_FLAG && !specs.precision))
		print_decimal(num, len);
}

int	ft_printf_d_or_i(t_spec specs, va_list args)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = 0;
	if (specs.flags & FLAG_HYPHEN)
		put_dec_left(specs, num, &len);
	else if (specs.flags & PREC_FLAG)
		put_dec_right_1(specs, num, &len);
	else
		put_dec_right_2(specs, num, &len);
	return (len);
}
