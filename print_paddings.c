/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paddings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:43:57 by stakada           #+#    #+#             */
/*   Updated: 2024/05/15 21:34:24 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(int digits, int max_len, int *len)
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

void	print_zero_paddings(int digits, int max_len, int *len)
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
