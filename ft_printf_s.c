/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:52 by stakada           #+#    #+#             */
/*   Updated: 2024/05/14 16:51:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_strlen(char *s)
{
	if (!s)
		return (6);
	return ((int)ft_strlen(s));
}

void	put_str_left(char *s, t_spec specs, int *len, int strlen)
{
	if (!s)
	{
		print_null(len, strlen);
		if (*len < 0)
			return ;
	}
	else
	{
		while (strlen--)
		{
			if (write(FD, s++, 1) < 0)
			{
				(*len) = -1;
				return ;
			}
			(*len)++;
		}
	}
	print_spaces(*len, specs.width, len);
}

void	put_str_right(char *s, t_spec specs, int *len, int strlen)
{
	int	i;

	i = 0;
	print_spaces(strlen, specs.width, len);
	if (*len < 0)
		return ;
	if (!s)
	{
		print_null(len, strlen);
		if (*len < 0)
			return ;
	}
	else
	{
		while (strlen--)
		{
			// printf("\nstrlen=%d\nnow=%c\n", strlen, s[i]);
			if (write(FD, &s[i++], 1) < 0)
			{
				(*len) = -1;
				return ;
			}
			(*len)++;
		}
	}
}

void	print_null(int *len, int strlen)
{
	char	str[7];
	int		i;

	i = 0;
	ft_strlcpy(str, "(null)", 7);
	while (strlen--)
	{
		if (write(FD, &str[i++], 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
}

int	ft_printf_s(t_spec specs, va_list args)
{
	char *s;
	int len;
	int strlen;

	s = va_arg(args, char *);
	// printf("s=%s\n", s);
	len = 0;
	// printf("%d\n", specs.precision);
	strlen = count_strlen(s);
	// printf("%d\n", strlen);
	if (specs.flags & PREC_FLAG && specs.precision < strlen)
		strlen = specs.precision;
	// printf("strlen=%d\n", strlen);
	if (specs.flags & FLAG_HYPHEN)
		put_str_left(s, specs, &len, strlen);
	else
		put_str_right(s, specs, &len, strlen);
	return (len);
}