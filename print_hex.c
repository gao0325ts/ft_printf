/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:20:34 by stakada           #+#    #+#             */
/*   Updated: 2024/05/09 21:37:53 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_hex_upper(unsigned long long llu)
{
    int digits;
    char c;

    digits = 1;
    if (llu > 15)
        digits += put_hex_lower(llu / 16);
    c = "0123456789ABCDEF"[llu % 16];
    if (write(1, &c, 1) < 0)
        return (-1);
    return (digits);
}

int put_hex_lower(unsigned long long llu)
{
    int digits;
    char c;

    digits = 1;
    if (llu > 15)
        digits += put_hex_lower(llu / 16);
    c = "0123456789abcdef"[llu % 16];
    if (write(1, &c, 1) < 0)
        return (-1);
    return (digits);
}

int put_hexadecimal(unsigned long long llu, int is_upper)
{
    int digits;

    digits = 2;
    if (is_upper)
    {
        if (write(FD, "0X", 2) < 0)
            return (-1);
        digits += put_hex_upper(llu);
    }
    else
    {
        if (write(FD, "0x", 2) < 0)
            return (-1);
        digits += put_hex_lower(llu);
    }
    return (digits);
}

// #include <stdio.h>

// int main(void)
// {
//     int tmp = 0;
//     char *str = "abc";
//     void *p = str;
//     tmp = printf("%p\n", p);
//     printf("%d\n", tmp - 1);
//     tmp = put_hexadecimal((unsigned long long)p, 0);
//     printf("%d\n", tmp);
//     return (0);
// }