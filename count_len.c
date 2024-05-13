/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:44 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 21:03:22 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_padded_len(t_spec specs, int digits)
{
	int	p_len;

	p_len = 0;
	if (specs.flags & FLAG_HASH)
		p_len = 2;
    if (num < 0 || specs.flags & FLAG_PLUS || specs.flags & FLAG_SPACE)
		p_len++;
	if (digits < specs.precision)
		p_len += specs.precision;
	else
		p_len += digits;
	return (p_len);
}
