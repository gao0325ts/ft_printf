/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paddings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:43:57 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 21:11:18 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_paddings(int digits, int max_len, t_spec specs, int *len)
{
	if (specs.flags & IS_PD_ZERO)
	{
		while (digits++ < max_len)
		{
			if (write(FD, "0", 1) < 0)
			{
				(*len) = -1;
				return ;
			}
			(*len)++;
		}
	}
	else
	{
		while (digits++ < max_len)
		{
			if (write(FD, " ", 1) < 0)
			{
				(*len) = -1;
				return ;
			}
			(*len)++;
		}
	}
}
