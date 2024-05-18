/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:57:59 by stakada           #+#    #+#             */
/*   Updated: 2024/05/17 22:23:34 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_percent_left(t_spec specs, int *len)
{
	if (write(FD, "%", 1) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += 1;
	print_spaces(1, specs.width, len);
}

void	put_percent_right(t_spec specs, int *len)
{
	if (specs.flags & FLAG_ZERO)
		print_zero_paddings(1, specs.width, len);
	else
		print_spaces(1, specs.width, len);
	if (*len < 0)
		return ;
	if (write(FD, "%", 1) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += 1;
}

int	ft_printf_percent(t_spec specs)
{
	int	len;

	len = 0;
	if (specs.flags & FLAG_HYPHEN)
		put_percent_left(specs, &len);
	else
		put_percent_right(specs, &len);
	return (len);
}
