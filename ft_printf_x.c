/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:21 by stakada           #+#    #+#             */
/*   Updated: 2024/05/09 22:48:24 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(t_list form_list, va_list args, int is_upper)
{
	unsigned long long x;
	int len;

	x = va_arg(args, unsigned long long);

	len = 0;
	return (len);
}