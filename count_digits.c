/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:13:38 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 13:22:13 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_digits(int num)
{
	size_t	digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

size_t	count_digits_u(unsigned int num)
{
	size_t	digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

size_t	count_digits_hex(unsigned long long num)
{
	size_t	digits;

	digits = 0;
	while (num)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

size_t	count_padded_digits(t_spec specs, int digits)
{
	size_t	p_digits;

	p_digits = 0;
	if (specs.flags & FLAG_HASH)
		p_digits = 2;
	if (digits < specs.precision)
		p_digits += specs.precision;
	else
		p_digits += digits;
	return (p_digits);
}
