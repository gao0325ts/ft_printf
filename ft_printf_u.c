/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:25:55 by stakada           #+#    #+#             */
/*   Updated: 2024/05/09 22:33:04 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_u(t_list form_list, va_list args)
{
    unsigned int u;
    int len;

    u = va_arg(args, unsigned int);
    len = 0;
    
    return (len);
}