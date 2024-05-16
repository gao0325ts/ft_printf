/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:05:32 by stakada           #+#    #+#             */
/*   Updated: 2024/05/16 09:02:34 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(const char **s, t_spec *specs)
{
	specs->flags = 0;
	while (**s == '#' || **s == '0' || **s == '-' || **s == ' ' || **s == '+')
	{
		if (**s == '#')
			specs->flags |= FLAG_HASH;
		else if (**s == '0')
			specs->flags |= FLAG_ZERO;
		else if (**s == '-')
			specs->flags |= FLAG_HYPHEN;
		else if (**s == ' ')
			specs->flags |= FLAG_SPACE;
		else
			specs->flags |= FLAG_PLUS;
		(*s)++;
	}
}

void	check_field_size(const char **s, t_spec *specs)
{
	specs->width = 0;
	specs->precision = 0;
	if (ft_isdigit(**s))
	{
		specs->width = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (**s == '.')
	{
		specs->flags |= PREC_FLAG;
		(*s)++;
		if (!ft_isdigit(**s))
			return ;
		specs->precision = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

void	detect_conversion(const char **str, t_spec *specs)
{
	(*str)++;
	set_flags(str, specs);
	check_field_size(str, specs);
}
