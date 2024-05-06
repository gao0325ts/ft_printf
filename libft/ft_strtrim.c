/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:43:00 by stakada           #+#    #+#             */
/*   Updated: 2024/05/03 22:03:05 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *str, const char *to_find)
{
	while (*to_find != '\0')
	{
		if (*str == *to_find)
			return (1);
		to_find++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(&s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (is_set(&s1[end], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 2);
	result[end - start + 1] = '\0';
	return (result);
}

// int main(void)
// {
//   printf("(expected)%s\n(result)%s\n", "hello ", ft_strtrim("hello world",
//		"world"));
//   printf("(expected)%s\n(result)%s\n", " world", ft_strtrim("hello world",
//		"hello"));
//   printf("(expected)%s\n(result)%s\n", "hello world",
//	ft_strtrim("hello world", ""));
//   printf("(expected)%s\n(result)%s\n", "", ft_strtrim("", ""));
//   printf("(expected)%s\n(result)%s\n", "hello world",
//	ft_strtrim("    hello world     ", " "));
//   printf("(expected)%s\n(result)%s\n", "hello \n\t\r world",
//	ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n", " \n\t\r"));
//   printf("(expected)%s\n(result)%s\n", " ", ft_strtrim("hello world",
//		"abcdefghijklmnopqrstuvwxyz"));
//   return (0);
// }
