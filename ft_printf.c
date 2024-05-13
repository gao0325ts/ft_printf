/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:37:34 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 22:31:46 by stakada          ###   ########.fr       */
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
			tmp = detect_conversion(++format, args);
			if (tmp == -1)
				return (-1);
			len += tmp;
			format += tmp;
		}
		while (*format != '%' && *format)
		{
			if (write(FD, format, 1) < 0)
				return (-1);
			len++;
			format++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = ft_printf_processing(format, args);
	va_end(args);
	return (result);
}