/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:05 by stakada           #+#    #+#             */
/*   Updated: 2024/05/16 08:21:39 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char_left(int c, t_spec specs, int *len)
{
	if (write(FD, &c, 1) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len)++;
	print_spaces(1, specs.width, len);
}

void	put_char_right(int c, t_spec specs, int *len)
{
	print_spaces(1, specs.width, len);
	if (*len < 0)
		return ;
	if (write(FD, &c, 1) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len)++;
}

int	ft_printf_c(t_spec specs, va_list args)
{
	char	c;
	int		len;

	c = va_arg(args, int);
	len = 0;
	if (specs.flags & FLAG_HYPHEN)
		put_char_left(c, specs, &len);
	else
		put_char_right(c, specs, &len);
	return (len);
}
