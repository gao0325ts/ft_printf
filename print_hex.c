/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:20:34 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 08:47:49 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_upper(unsigned long long llu)
{
	int		digits;
	char	c;

	digits = 1;
	if (llu > 15)
		digits += put_hex_lower(llu / 16);
	c = "0123456789ABCDEF"[llu % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (digits);
}

int	print_hex_lower(unsigned long long llu)
{
	int		digits;
	char	c;

	digits = 1;
	if (llu > 15)
		digits += put_hex_lower(llu / 16);
	c = "0123456789abcdef"[llu % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (digits);
}

void	print_prefix(int is_upper, int *len)
{
	if (is_upper)
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

void	print_hexadecimal(unsigned long long llu, t_spec specs, int *len)
{
	if (specs.flags & FLAG_HASH)
	{
		print_prefix(specs.flags & IS_X_UPPER, len);
		if (*len < 0)
			return ;
	}
	if (specs.flags & IS_X_UPPER)
		(*len) += put_hex_upper(llu);
	else
		(*len) += put_hex_lower(llu);
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