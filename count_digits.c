/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:27:52 by stakada           #+#    #+#             */
/*   Updated: 2024/05/15 21:35:54 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int num, t_spec specs)
{
	int	digits;

	digits = 0;
	if (!num && specs.flags & PREC_FLAG && !specs.precision)
		return (0);
	else if (!num)
		return (1);
	else if (num < 0)
		digits++;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int	count_abs_digits(int num, t_spec specs)
{
	int	abs_digits;

	abs_digits = 0;
	if (!num && specs.flags & PREC_FLAG && !specs.precision)
		return (0);
	else if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		abs_digits++;
	}
	return (abs_digits);
}

int	count_abs_digits_u(unsigned int num, t_spec specs)
{
	int	abs_digits;

	abs_digits = 0;
	if (!num && specs.flags & PREC_FLAG && !specs.precision)
		return (0);
	else if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		abs_digits++;
	}
	return (abs_digits);
}

int	count_digits_u(unsigned int num, t_spec specs)
{
	int	digits;

	digits = 0;
	if (!num && specs.flags & PREC_FLAG && !specs.precision)
		return (0);
	else if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int	count_digits_hex(unsigned long long num, t_spec specs)
{
	int	digits;

	digits = 0;
	if (!num && specs.flags & PREC_FLAG && !specs.precision)
		return (0);
	else if (!num)
		return (1);
	while (num)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}
