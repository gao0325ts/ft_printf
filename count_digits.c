/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:13:38 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 13:40:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int num)
{
	int	digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int	count_digits_u(unsigned int num)
{
	int	digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int	count_digits_hex(unsigned long long num)
{
	int	digits;

	digits = 0;
	while (num)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

int	count_padded_len(t_spec specs, int digits)
{
	int	p_digits;

	p_digits = 0;
	if (specs.flags & FLAG_HASH)
		p_digits = 2;
	if (digits < specs.precision)
		p_digits += specs.precision;
	else
		p_digits += digits;
	return (p_digits);
}