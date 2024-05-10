/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:37:49 by stakada           #+#    #+#             */
/*   Updated: 2024/05/10 14:52:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_decimal_processing(long long ll)
{
	int		digits;
	char	c;

	digits = 1;
	if (ll > 9)
		digits += print_decimal_processing(ll / 10);
	c = ll % 10 + '0';
	if (write(1, &c, 1) < 0)
        return (-1);
	return (digits);
}

void	print_decimal(int precision, int num, int *len)
{
    int tmp;
    long long ll;

    ll = (long long)num;
    if (ll < 0)
    {
        if (write(FD, "-", 1) < 0)
        {
            (*len) = -1;
            return ;
        }
        ll = -ll;
        (*len)++;
    }
    tmp = print_decimal_processing(ll);
    if (tmp < 0)
        (*len) = -1;
    (*len) += tmp;
}
