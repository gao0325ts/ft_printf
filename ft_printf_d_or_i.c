/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:12 by stakada           #+#    #+#             */
/*   Updated: 2024/05/10 16:42:38 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_symbol(int flags, int num, int *len)
{
	if (num < 0)
		(*len) = write(FD, "-", 1);
	else
	{
		if (flags & FLAG_PLUS)
			(*len) = write(FD, "+", 1);
		if (flags & FLAG_SPACE)
			(*len) = write(FD, " ", 1);
	}
}

int	check_digits(int num)
{
	int digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

void	put_decimal_left(t_info info, int num, int *len)
{
	print_symbol(info.flags, num, len);
	if (*len < 0)
		return ;
	while (check_digits(num) < info.precision--)
	{
		if (write(FD, "0", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
	print_decimal(info.precision, num, len);
	if (*len < 0)
		return ;
	while (*len < info.width)
	{
		if (write(FD, " ", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
}

void	put_decimal_right(t_info info, int num, int *len, int output_len)
{
	while (output_len++ < info.width)
	{
		if (write(FD, " ", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
	}
	print_symbol(info.flags, num, len);
	if (*len < 0)
		return ;
	while (check_digits(num) < info.precision--)
	{
		if (write(FD, "0", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
	print_decimal(info.precision, num, len);
}

int check_output_len(t_info info, int num)
{
	int output_len;

	output_len = 0;
	if (num < 0 || info.flags & FLAG_PLUS || info.flags & FLAG_SPACE)
		output_len++;
	if (check_digits(num) < info.precision)
		output_len += info.precision;
	else
		output_len += check_digits(num);
	if (output_len < info.width)
		output_len = info.width;
	return (output_len);
}

int	ft_printf_d_or_i(t_info info, va_list args)
{
	int num;
	int len;
	int output_len;

	num = va_arg(args, int);
	len = 0;
	if (info.flags & FLAG_HASH)
		return (-1);
	if (info.flags & FLAG_HYPHEN)
		put_decimal_left(info, num, &len);
	else
	{
		output_len = check_output_len(info, num);
		put_decimal_right(info, num, &len, output_len);
	}
	return (len);
}
