/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:52 by stakada           #+#    #+#             */
/*   Updated: 2024/05/09 19:25:52 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_str_left(char *s, int strlen, int width)
{
    int len;

    len = 0;
    while (strlen--)
    {
        if (write(FD, s++, 1) < 0)
            return (-1);
        len++;
    }
    while (width--)
    {
        if (write(FD, " ", 1) < 0)
            return (-1);
        len++;
    }
    return (len);
}

int put_str_right(char *s, int strlen, int width)
{
    int len;

    len = 0;
    while (width--)
    {
        if (write(FD, " ", 1) < 0)
            return (-1);
        len++;
    }
    while (strlen--)
    {
        if (write(FD, s++, 1) < 0)
            return (-1);
        len++;
    }
    return (len);
}

int ft_printf_s(t_list form_list, va_list args)
{
    char *s;
    int len;
    int strlen;

    s = va_arg(args, char *);
    len = 0;
    strlen = ft_strlen(s);
    if (!(form_list.flags == FLAG_HYPHEN || form_list.flags == 0))
        return (-1);
    if (form_list.precision < ft_strlen(s) && form_list.precision_flag)
        strlen = form_list.precision;
    if (form_list.flags == FLAG_HYPHEN)
        len = put_str_left(s, strlen, form_list.width - strlen);
    else
        len = put_str_right(s, strlen, form_list.width - strlen);
    return (len);
}
