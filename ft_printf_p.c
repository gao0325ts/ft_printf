/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:23:16 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 08:52:06 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer_left(unsigned long long p, t_spec specs, int *len)
{
	put_hexadecimal(p, specs, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_pointer_right(unsigned long long p, t_spec specs, int *len)
{
	print_spaces(check_num_len(specs.precision, check_digits_hex(p)), specs.width, len);
	if (*len < 0)
		return ;
	put_hexadecimal(p, specs, len);
}

int	ft_printf_p(t_spec specs, va_list args)
{
	unsigned long long	p;
	int					len;

	p = va_arg(args, unsigned long long);
	len = 0;
	if (!(specs.flags & FLAG_HYPHEN || specs.flags == 0))
		return (-1);
	if (specs.flags & PREC_FLAG)
		return (-1);
	specs.flags |= FLAG_HASH;
	if (specs.flags & FLAG_HYPHEN)
		put_pointer_left(p, specs, &len);
	else
		put_pointer_left(p, specs, &len);
	return (len);
}
