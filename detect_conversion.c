/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:05:32 by stakada           #+#    #+#             */
/*   Updated: 2024/05/10 11:29:36 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(const char **s, t_info *form_list)
{
	form_list->flags = 0;
	while (**s == '#' || **s == '0' || **s == '-' || **s == ' ' || **s == '+')
	{
		if (**s == '#')
			form_list->flags |= FLAG_HASH;
		else if (**s == '0')
			form_list->flags |= FLAG_ZERO;
		else if (**s == '-')
			form_list->flags |= FLAG_HYPHEN;
		else if (**s == ' ')
			form_list->flags |= FLAG_SPACE;
		else
			form_list->flags |= FLAG_PLUS;
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

void	check_field_size(const char **s, t_info *form_list)
{
	form_list->width_flag = 0;
	form_list->width = 0;
	form_list->precision_flag = 0;
	form_list->precision = 0;
	if (ft_isdigit(**s))
	{
		form_list->width_flag = 1;
		form_list->width = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (**s == '.')
	{
		(*s)++;
		if (!ft_isdigit(**s))
			return ;
		form_list->precision_flag = 1;
		form_list->precision = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

int	detect_conversion(const char *str, va_list args)
{
	int		len;
	t_info	form_list;

	len = 0;
	set_flags(&str, &form_list);
	if (!is_valid_flags(form_list.flags))
		return (-1);
	check_field_size(&str, &form_list);
	if (form_list.precision < 0)
		return (-1);
	len = print_args(str, form_list, args);
	if (len < 0)
		return (-1);
	return (len);
}
