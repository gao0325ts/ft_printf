#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	printf("%7.5d\n", 123);
	ft_printf("%7.5d\n", 123);
	// printf("%d\n", printf("%3.-5d", 12345));
	// printf("%d\n", ft_printf("%3.-5d", 12345));
	return (0);
}