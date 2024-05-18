/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:37:49 by stakada           #+#    #+#             */
/*   Updated: 2024/05/17 22:52:52 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal_processing(long long ll)
{
	int		digits;
	char	c;

	digits = 0;
	if (ll >= 10)
		digits += print_decimal_processing(ll / 10);
	c = ll % 10 + '0';
	if (write(FD, &c, 1) < 0)
		return (-1);
	return (digits);
}

void	print_decimal(int num, t_spec specs, int *len)
{
	long long	ll;

	ll = (long long)num;
	if (ll < 0)
		ll = -ll;
	if (ll == 0)
	{
		if (write(FD, "0", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len) += 1;
		return ;
	}
	if (print_decimal_processing(ll) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += count_abs_digits(num, specs);
}

int	print_u_decimal_processing(unsigned long long ll)
{
	int		digits;
	char	c;

	digits = 0;
	if (ll >= 10)
		digits += print_u_decimal_processing(ll / 10);
	c = ll % 10 + '0';
	if (write(FD, &c, 1) < 0)
		return (-1);
	return (digits);
}

void	print_u_decimal(unsigned int num, t_spec specs, int *len)
{
	unsigned long long	llu;

	llu = (unsigned long long)num;
	if (llu == 0)
	{
		if (write(FD, "0", 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len) += 1;
		return ;
	}
	if (print_decimal_processing(llu) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += count_abs_digits_u(num, specs);
}
