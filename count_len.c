/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:44 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 21:52:21 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_padded_len(t_spec specs, int digits)
{
	int	pd_len;

	pd_len = 0;
	if (specs.flags & FLAG_HASH)
		pd_len = 2;
    if (num < 0 || specs.flags & FLAG_PLUS || specs.flags & FLAG_SPACE)
		pd_len++;
	if (digits < specs.precision)
		pd_len += specs.precision;
	else
		pd_len += digits;
	return (pd_len);
}
