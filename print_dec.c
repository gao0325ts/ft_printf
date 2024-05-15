/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:37:49 by stakada           #+#    #+#             */
/*   Updated: 2024/05/15 21:12:47 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal_processing(long long ll)
{
	int		digits;
	char	c;

	digits = 1;
	if (ll >= 10)
		digits += print_decimal_processing(ll / 10);
	c = ll % 10 + '0';
	if (write(FD, &c, 1) < 0)
		return (-1);
	return (digits);
}

void	print_decimal(int num, int *len)
{
	int			tmp;
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
	tmp = print_decimal_processing(ll);
	if (tmp < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += tmp;
}

int	print_u_decimal_processing(unsigned long long ll)
{
	int		digits;
	char	c;

	digits = 1;
	if (ll >= 10)
		digits += print_u_decimal_processing(ll / 10);
	c = ll % 10 + '0';
	if (write(FD, &c, 1) < 0)
		return (-1);
	return (digits);
}

void	print_u_decimal(unsigned int num, int *len)
{
	int					tmp;
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
	tmp = print_decimal_processing(llu);
	if (tmp < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += tmp;
}
