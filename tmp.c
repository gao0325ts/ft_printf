#include <stdio.h>

int	main(void)
{
	int d = 123;
	int m = -123;
	// int tmp;
	printf("1.[%d]\n", m);
	// printf("2.[%#d]\n", m); // flag_hash
	printf("3.[%2d]\n", m);
	printf("4.[%-d]\n", m);
	printf("5.[%0.10d]\n", m);
	printf("6.[%- 2d]\n", m);
	printf("7.[%+-2d]\n", m);
	printf("8.[%.d]\n", m);
	printf("9.[%.0d]\n", m);
	printf("10.[%5.d]\n", m);
	printf("11.[%0.d]\n", m);
	printf("12.[%+1.2d]\n", m);
    printf("13.[%-8d]\n", d);
	printf("13-2.[%-8d]\n", m);
	printf("14.[%1.4d]\n", d);
	printf("14-2.[%1.4d]\n", m);
	printf("15.[%+10.5d]\n", m);
	printf("16.[%5.0d]\n", m);
	printf("17.[%5.6d]\n", m);
	printf("18.[%- 8d]\n", m);
	printf("19.[%-10.5d]\n", m);
	return (0);
}