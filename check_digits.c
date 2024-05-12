/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:13:38 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 17:13:58 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_digits(int num)
{
	int digits;

	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int check_digits_u(unsigned int num)
{
	int digits;

	digits = 0;
	while(num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}