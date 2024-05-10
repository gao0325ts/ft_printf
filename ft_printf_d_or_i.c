/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:12 by stakada           #+#    #+#             */
/*   Updated: 2024/05/10 11:27:28 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_digits(int num)
{
	int	digits;

	digits = 1;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int	put_plus_or_space(int flags, int num, int *len)
{
	if (flags & FLAG_PLUS && num > 0)
	{
		if (write(FD, "+", 1) < 0)
			return (-1);
		(*len)++;
	}
	if (flags & FLAG_SPACE && num > 0)
	{
		if (write(FD, " ", 1) < 0)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_decimal(int num)
{
    
}

int	put_decimal_left(t_info form_list, int num)
{
	int	len;
	int	digits;

	len = 0;
	digits = check_digits(num);
	if (put_plus_or_space(form_list.flags, num, &len))
		return (-1);
	if (len < form_list.precision)
		return (len);
}

int	put_decimal_right(t_info form_list, int num)
{
	int	len;

	len = 0;
	if (put_plus_or_space(form_list.flags, num, &len))
		return (-1);
	return (len);
}

int	ft_printf_d_or_i(t_info form_list, va_list args)
{
	int num;
	int len;

	num = va_arg(args, int);
	len = 0;
	if (form_list.flags == FLAG_HASH)
		return (-1);
	if (form_list.flags & FLAG_HYPHEN)
		len = put_decimal_left(form_list, num);
	else
		len = put_decimal_right(form_list, num);
	return (len);
}