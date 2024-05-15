/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:23:16 by stakada           #+#    #+#             */
/*   Updated: 2024/05/15 21:33:05 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer_left(unsigned long long p, t_spec specs, int *len)
{
	print_prefix(specs, len);
	if (*len < 0)
		return ;
	print_hexadecimal(p, specs, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_pointer_right(unsigned long long p, t_spec specs, int *len)
{
	print_spaces(count_digits_hex(p, specs) + 2, specs.width, len);
	if (*len < 0)
		return ;
	print_prefix(specs, len);
	if (*len < 0)
		return ;
	print_hexadecimal(p, specs, len);
}

int	ft_printf_p(t_spec specs, va_list args)
{
	unsigned long long	p;
	int					len;

	p = va_arg(args, unsigned long long);
	len = 0;
	specs.flags |= FLAG_HASH;
	if (specs.flags & FLAG_HYPHEN)
		put_pointer_left(p, specs, &len);
	else
		put_pointer_right(p, specs, &len);
	return (len);
}
