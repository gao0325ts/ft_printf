/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:26:19 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 10:33:13 by stakada          ###   ########.fr       */
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
# define PREC_FLAG 0b0000000001000000
# define IS_X_UPPER 0b0000000010000000

typedef struct s_spec
{
	int	flags;
	int	width;
	int	precision;
}		t_spec;

int	ft_printf(const char *format, ...);
int	ft_printf_processing(const char *format, va_list args);
int	detect_conversion(const char *str, va_list args);
void	set_flags(const char **s, t_spec *specs);
int	is_valid_flags(int flags);
void	check_field_size(const char **s, t_spec *specs);
int	ft_printf_dispatcher(char const *s, t_spec *specs, va_list args);
int	ft_printf_c(t_spec specs, va_list args);
int	put_char_left(char c, int width);
int	put_char_right(char c, int width);
int	ft_printf_s(t_spec specs, va_list args);
int	put_str_left(char *s, int strlen, int width);
int	put_str_right(char *s, int strlen, int width);
int	ft_printf_p(t_spec specs, va_list args);
void	put_pointer_left(unsigned long long p, t_spec specs, int *len);
void	put_pointer_right(unsigned long long p, t_spec specs, int *len);
int	ft_printf_d_or_i(t_spec specs, va_list args);
void	print_symbol(int flags, int num, int *len);
int check_output_len(t_spec specs, int num);
void	put_dec_left(t_spec specs, int num, int *len);
void	put_dec_right(t_spec specs, int num, int *len, int output_len);
int	ft_printf_u(t_spec specs, va_list args);
void	put_u_dec_left(unsigned int num, t_spec specs, int *len);
void	put_u_dec_right(unsigned int num, t_spec specs, int *len);
int	ft_printf_x(t_spec specs, va_list args);
void	put_hex_left(unsigned long long num, t_spec specs, int *len);
void	put_hex_right_1(unsigned long long num, t_spec specs, int *len);
void	put_hex_right_2(unsigned long long num, t_spec specs, int *len);
int	ft_printf_percent(void);

#endif