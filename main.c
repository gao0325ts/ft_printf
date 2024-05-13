#include <stdio.h>

int			ft_printf(const char *format, ...);

int main(void)
{
	printf("\n%d\n", ft_printf("%c", 'a'));
    return 0;
}