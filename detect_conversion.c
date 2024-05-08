/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:05:26 by stakada           #+#    #+#             */
/*   Updated: 2024/05/08 09:06:52 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int check_specifiers(char const *s, va_list args, int flags)
// {
//   int len;
//   if (*s == '%')
//   {
//     write(1, "%", 1);
//     return (1);
//   }
//   else if (*s == 'd' || *s == 'i')
//     len = put_signed_decimal(args, flags);
//   else if (*s == 'u')
//     len = put_unsigned_decimal(args, flags);
//   else if (*s == 'x')
//     len = put_lower_hexadecimal(args, flags);
//   else if (*s == 'X')
//     len = put_upper_hexadecimal(args, flags);
//   else if (*s == 'c')
//     len = put_char(args, flags);
//   else if (*s == 's')
//     len = put_string(args, flags);
//   else if (*s == 'p')
//     len = put_address(args, flags);
//   return (len);
// }

int is_invalid_flags(int flags)
{
  if (flags == (FLAG_HASH | FLAG_SPACE))
    return (1);
  if (flags == (FLAG_SPACE | FLAG_PLUS))
    return (1);
  if (flags == (FLAG_HASH | FLAG_PLUS))
    return (1);
  if (flags == (FLAG_HYPHEN | FLAG_ZERO))
    return (1);
  return (0);
}

int set_flags(char const *s, t_list *form_list)
{
  int len;

  len = 0;
  form_list->flags = 0;
  while (*s == '#' || *s == '0' || *s == '-' || *s == ' ' || *s == '+')
  {
    if (*s == '#')
      form_list->flags |= FLAG_HASH;
    else if (*s == '0')
      form_list->flags |= FLAG_ZERO;
    else if (*s == '-')
      form_list->flags |= FLAG_HYPHEN;
    else if (*s == ' ')
      form_list->flags |= FLAG_SPACE;
    else
      form_list->flags |= FLAG_PLUS;
    s++;
  }
  return (is_invalid_flags(form_list->flags));
}

int check_field_size(char const *s, t_list *form_list)
{
  form_list->min_width = 0;
  form_list->precision = 0;

  if (ft_isdigit(*s))
    form_list->min_width = ft_atoi(s);
  s += form_list->min_width;
  if (*s == '.')
    form_list->precision = ft_atoi(++s);
  if (form_list->precision < 0)
    return (-1);
  return (form_list);
}

int detect_conversion(char const *s, va_list args)
{
  int len;
  t_list *form_list;

  len = 0;
  if (set_flags(s, form_list))
    return (-1);
  check_field_size(s, form_list);
  print_args();
}

// #include <stdio.h>

// int main(void)
// {
//   printf("%d\n", remove_invalid_1(0b0000000000001001));
//   return 0;
// }