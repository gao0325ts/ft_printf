/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:43:57 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 17:11:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_zero_paddings(int digits, t_spec specs, int *len)
{
    while (digits-- > specs.precision)
    {
        if (write(FD, "0", 1) < 0)
        {
            (*len) = -1;
            return ;
        }
        (*len)++;
    }
}
