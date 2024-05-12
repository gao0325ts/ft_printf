/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:28:04 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 15:30:04 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_percent(void)
{
	if (write(FD, "%", 1) < 0)
		return (-1);
	return (1);
}

int	print_args(char const *s, t_info info, va_list args)
{
	int	len;

	len = -1;
	if (*s == 'c')
		len = ft_printf_c(info, args);
	if (*s == 's')
		len = ft_printf_s(info, args);
	if (*s == 'p')
		len = ft_printf_p(info, args);
	if (*s == 'd' || *s == 'i')
		len = ft_printf_d_or_i(info, args);
	if (*s == 'u')
		len = ft_printf_u(info, args);
	if (*s == 'x')
		len = ft_printf_x(info, args, 0);
	if (*s == 'X')
		len = ft_printf_x(info, args, 1);
	if (*s == '%')
		len = ft_printf_percent();
	return (len);
}
