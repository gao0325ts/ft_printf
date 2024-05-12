/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:05:32 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 15:34:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(const char **s, t_info *info)
{
	info->flags = 0;
	while (**s == '#' || **s == '0' || **s == '-' || **s == ' ' || **s == '+')
	{
		if (**s == '#')
			info->flags |= FLAG_HASH;
		else if (**s == '0')
			info->flags |= FLAG_ZERO;
		else if (**s == '-')
			info->flags |= FLAG_HYPHEN;
		else if (**s == ' ')
			info->flags |= FLAG_SPACE;
		else
			info->flags |= FLAG_PLUS;
		(*s)++;
	}
}

int	is_valid_flags(int flags)
{
	if (flags == (FLAG_HASH | FLAG_SPACE))
		return (-1);
	if (flags == (FLAG_SPACE | FLAG_PLUS))
		return (-1);
	if (flags == (FLAG_HASH | FLAG_PLUS))
		return (-1);
	if (flags == (FLAG_HYPHEN | FLAG_ZERO))
		return (-1);
	return (0);
}

void	check_field_size(const char **s, t_info *info)
{
	info->width = 0;
	info->precision = 0;
	if (ft_isdigit(**s))
	{
		info->flags |= WIDTH_FLAG;
		info->width = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (**s == '.')
	{
		(*s)++;
		if (!ft_isdigit(**s))
			return ;
		info->flags |= PRECISION_FLAG;
		info->precision = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

int	detect_conversion(const char *str, va_list args)
{
	int		len;
	t_info	info;

	len = 0;
	set_flags(&str, &info);
	if (!is_valid_flags(info.flags))
		return (-1);
	check_field_size(&str, &info);
	if (info.precision < 0)
		return (-1);
	len = print_args(str, info, args);
	if (len < 0)
		return (-1);
	return (len);
}
