/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:12 by stakada           #+#    #+#             */
/*   Updated: 2024/05/09 22:34:04 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_d_or_i(t_list form_list, va_list args)
{
    int num;
    int len;

    num = va_arg(args, int);
    len = 0;
    putnbr_fd(num, FD);
    return (len);
}