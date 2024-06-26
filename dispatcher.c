/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:28:04 by stakada           #+#    #+#             */
/*   Updated: 2024/05/16 08:45:37 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dispatcher(const char **s, va_list args)
{
	t_spec	specs;

	detect_conversion(s, &specs);
	if (!**s)
		return (0);
	if (**s == 'c')
		return (ft_printf_c(specs, args));
	if (**s == 's')
		return (ft_printf_s(specs, args));
	if (**s == 'p')
		return (ft_printf_p(specs, args));
	if (**s == 'd' || **s == 'i')
		return (ft_printf_d_or_i(specs, args));
	if (**s == 'u')
		return (ft_printf_u(specs, args));
	if (**s == 'x')
		return (ft_printf_x(specs, args));
	if (**s == 'X')
	{
		specs.flags |= IS_X_UPPER;
		return (ft_printf_x(specs, args));
	}
	if (**s == '%')
		return (ft_printf_percent(specs));
	return (write(FD, *s, 1));
}
