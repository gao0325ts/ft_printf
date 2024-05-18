/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:37:34 by stakada           #+#    #+#             */
/*   Updated: 2024/05/17 22:30:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_processing(const char *format, va_list args)
{
	int	len;
	int	tmp;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp = ft_printf_dispatcher(&format, args);
			if (tmp < 0)
				return (-1);
			len += tmp;
			format++;
		}
		else
		{
			while (*format != '%' && *format)
			{
				if (write(FD, format++, 1) < 0)
					return (-1);
				len++;
			}
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_printf_processing(format, args);
	va_end(args);
	return (result);
}
