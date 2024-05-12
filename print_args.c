/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:28:04 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 19:44:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_percent(void)
{
	if (write(FD, "%", 1) < 0)
		return (-1);
	return (1);
}

int	print_args(char const *s, t_spec *specs, va_list args)
{
	int	len;

	len = -1;
	if (*s == 'c')
		len = ft_printf_c(*specs, args);
	if (*s == 's')
		len = ft_printf_s(*specs, args);
	if (*s == 'p')
		len = ft_printf_p(*specs, args);
	if (*s == 'd' || *s == 'i')
		len = ft_printf_d_or_i(*specs, args);
	if (*s == 'u')
		len = ft_printf_u(*specs, args);
	if (*s == 'x')
		len = ft_printf_x(*specs, args);
	if (*s == 'X')
	{
		specs->flags |= IS_X_UPPER;
		len = ft_printf_x(*specs, args);
	}
	if (*s == '%')
		len = ft_printf_percent();
	return (len);
}
