/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:05:32 by stakada           #+#    #+#             */
/*   Updated: 2024/05/15 21:32:40 by stakada          ###   ########.fr       */
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

int	is_valid_flags(int flags)
{
	if (flags == (FLAG_HASH | FLAG_SPACE))
		return (-1);
	if (flags == (FLAG_SPACE | FLAG_PLUS))
		return (-1);
	if (flags == (FLAG_HASH | FLAG_PLUS))
		return (-1);
	return (0);
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

int	detect_conversion(const char **str, va_list args)
{
	int		len;
	t_spec	specs;

	len = 0;
	(*str)++;
	set_flags(str, &specs);
	if (is_valid_flags(specs.flags))
		return (-1);
	check_field_size(str, &specs);
	if (specs.precision < 0)
		return (-1);
	return (ft_printf_dispatcher(str, specs, args));
}
