/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:28:04 by stakada           #+#    #+#             */
/*   Updated: 2024/05/09 22:48:14 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_percent(void)
{
    if (write(FD, "%", 1) < 0)
        return (-1);
    return (1);
}

int print_args(char const *s, t_list form_list, va_list args)
{
    int len;

    len = 0;
    if (*s == 'c')
        len = ft_printf_c(form_list, args);
    if (*s == 's')
        len = ft_printf_s(form_list, args);
    if (*s == 'p')
        len = ft_printf_p(form_list, args);
    if (*s == 'd' || *s == 'i')
        len = ft_printf_d_or_i(form_list, args);
    if (*s == 'u')
        len = ft_printf_u(form_list, args);
    if (*s == 'x')
        len = ft_printf_x(form_list, args, 0);
    if (*s == 'X')
        len = ft_printf_x(form_list, args, 1);
    if (*s == '%')
        len = ft_printf_percent();
    return (len);
}
