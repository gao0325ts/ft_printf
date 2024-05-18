/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:20:34 by stakada           #+#    #+#             */
/*   Updated: 2024/05/17 22:45:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_upper(unsigned long long llu)
{
	int		digits;
	char	c;

	digits = 0;
	if (llu >= 16)
		digits += print_hex_upper(llu / 16);
	c = "0123456789ABCDEF"[llu % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (digits);
}

int	print_hex_lower(unsigned long long llu)
{
	int		digits;
	char	c;

	digits = 0;
	if (llu >= 16)
		digits += print_hex_lower(llu / 16);
	c = "0123456789abcdef"[llu % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (digits);
}

void	print_hexadecimal(unsigned long long llu, t_spec specs, int *len)
{
	if (specs.flags & IS_X_UPPER)
	{
		if (print_hex_upper(llu) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len) += count_digits_hex(llu, specs);
	}
	else
	{
		if (print_hex_lower(llu) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len) += count_digits_hex(llu, specs);
	}
}

void	print_prefix(t_spec specs, int *len)
{
	if (specs.flags & FLAG_HASH)
	{
		if (specs.flags & IS_X_UPPER)
		{
			if (write(FD, "0X", 2) < 0)
			{
				(*len) = -1;
				return ;
			}
		}
		else
		{
			if (write(FD, "0x", 2) < 0)
			{
				(*len) = -1;
				return ;
			}
		}
		(*len) += 2;
	}
}

// #include <stdio.h>

// int main(void)
// {
//     int tmp = 0;
//     char *str = "abc";
//     void *p = str;
//     tmp = printf("%p\n", p);
//     printf("%d\n", tmp - 1);
//     tmp = put_hexadecimal((unsigned long long)p, 0);
//     printf("%d\n", tmp);
//     return (0);
// }