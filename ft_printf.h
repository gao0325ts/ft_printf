/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:26:19 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 16:49:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define FD 1
# define FLAG_HASH 0b0000000000000001
# define FLAG_ZERO 0b0000000000000010
# define FLAG_HYPHEN 0b0000000000000100
# define FLAG_SPACE 0b0000000000001000
# define FLAG_PLUS 0b0000000000010000
// # define WIDTH_FLAG 0b0000000000100000
# define PRECISION_FLAG 0b0000000001000000

typedef struct s_spec
{
	int	flags;
	int	width;
	int	precision;
}		t_spec;

int		ft_printf(const char *format, ...);
int		ft_printf_processing(const char *format, va_list args);
int		detect_conversion(const char *str, va_list args);
void	check_field_size(const char **s, t_spec *specs);
int		is_valid_flags(int flags);
void	set_flags(const char **s, t_spec *specs);
int		print_args(char const *s, t_spec specs, va_list args);
int		ft_printf_percent(void);
int		ft_printf_c(t_spec specs, va_list args);
int		put_char_left(char c, int width);
int		put_char_right(char c, int width);
int		ft_printf_s(t_spec specs, va_list args);
int		put_str_left(char *s, int strlen, int width);
int		put_str_right(char *s, int strlen, int width);
int		ft_printf_p(t_spec specs, va_list args);
int		put_pointer_left(unsigned long long p, int width);
int		put_pointer_right(unsigned long long p, int width);
int		ft_printf_d_or_i(t_spec specs, va_list args);
int		put_decimal_left(t_spec specs, int num);
int		put_decimal_right(t_spec specs, int num);

#endif