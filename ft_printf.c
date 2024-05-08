/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:28:29 by stakada           #+#    #+#             */
/*   Updated: 2024/05/08 00:21:36 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_processing(char const *format, va_list args)
{
  int len;
  int tmp;

  len = 0;
  while (*format)
  {
    if (*format == '%')
    {
      tmp = detect_conversion(++format, args);
      if (tmp == -1)
        return (-1);
      len += tmp;
      format += tmp;
    }
    while (*format != '%' && *format)
    {
      write(FD, format, 1);
      len++;
      format++;
    }
  }
  return (len);
}

int ft_printf(const char *format, ...)
{
  va_list args;
  int len;

  len = 0;
  va_start(args, format);
  len = ft_printf_processing(format, args);
  va_end(args);
  return (len);
}

// // test code
// int main(void)
// {
//   ft_printf("abc");
// }