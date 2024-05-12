/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:13:38 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 08:52:41 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int check_digits_u(unsigned int num)
{
	int digits;

	digits = 0;
	while(num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int check_digits_hex(unsigned long long num, int prec_flag)
{
    int digits;

    digits = 0;
	if (prec_flag)
		digits += 2;
    while(num)
    {
        num /= 16;
        digits++;
    }
    return (digits);
}

int	check_num_len(int precision, int digits)
{
    int num_len;

	num_len = 0;
	if (digits < precision)
		num_len += precision;
	else
		num_len += digits;
	return (num_len);
}