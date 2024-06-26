/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:26:19 by stakada           #+#    #+#             */
/*   Updated: 2024/05/17 22:49:00 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FD 1
# define FLAG_HASH 0b0000000000000001
# define FLAG_ZERO 0b0000000000000010
# define FLAG_HYPHEN 0b0000000000000100
# define FLAG_SPACE 0b0000000000001000
# define FLAG_PLUS 0b0000000000010000
# define PREC_FLAG 0b0000000000100000
# define IS_X_UPPER 0b0000000001000000

typedef struct s_spec
{
	int	flags;
	int	width;
	int	precision;
}		t_spec;

int		ft_printf(const char *format, ...);
int		ft_printf_processing(const char *format, va_list args);
void	detect_conversion(const char **str, t_spec *specs);
void	set_flags(const char **s, t_spec *specs);
void	check_field_size(const char **s, t_spec *specs);
int		ft_printf_dispatcher(const char **s, va_list args);
int		ft_printf_c(t_spec specs, va_list args);
void	put_char_left(int c, t_spec specs, int *len);
void	put_char_right(int c, t_spec specs, int *len);
int		ft_printf_s(t_spec specs, va_list args);
int		count_strlen(char *s);
void	put_str_left(char *s, t_spec specs, int *len, int strlen);
void	put_str_right(char *s, t_spec specs, int *len, int strlen);
void	print_null(int *len, int strlen);
int		ft_printf_p(t_spec specs, va_list args);
void	put_pointer_left(unsigned long long p, t_spec specs, int *len);
void	put_pointer_right(unsigned long long p, t_spec specs, int *len);
int		ft_printf_d_or_i(t_spec specs, va_list args);
void	print_symbol(int flags, int num, int *len);
void	put_dec_left(t_spec specs, int num, int *len);
void	put_dec_right(t_spec specs, int num, int *len, int output_len);
int		ft_printf_u(t_spec specs, va_list args);
void	put_u_dec_left(unsigned int num, t_spec specs, int *len);
void	put_u_dec_right(unsigned int num, t_spec specs, int *len);
int		ft_printf_x(t_spec specs, va_list args);
void	put_hex_left(unsigned long long num, t_spec specs, int *len);
void	put_hex_right_1(unsigned long long num, t_spec specs, int *len);
void	put_hex_right_2(unsigned long long num, t_spec specs, int *len);
void	print_decimal(int num, t_spec specs, int *len);
int		print_decimal_processing(long long ll);
void	print_u_decimal(unsigned int num, t_spec specs, int *len);
int		print_u_decimal_processing(unsigned long long ll);
void	print_hexadecimal(unsigned long long llu, t_spec specs, int *len);
int		print_hex_upper(unsigned long long llu);
int		print_hex_lower(unsigned long long llu);
void	print_prefix(t_spec specs, int *len);
void	print_spaces(int digits, int max_len, int *len);
void	print_zero_paddings(int digits, int max_len, int *len);
int		count_digits(int num, t_spec specs);
int		count_digits_u(unsigned int num, t_spec specs);
int		count_digits_hex(unsigned long long num, t_spec specs);
int		count_padded_len(t_spec specs, int digits, int is_minus);
int		count_abs_digits(int num, t_spec specs);
int		count_abs_digits_u(unsigned int num, t_spec specs);
int		ft_printf_percent(t_spec specs);
void	put_percent_left(t_spec specs, int *len);
void	put_percent_left(t_spec specs, int *len);

#endif