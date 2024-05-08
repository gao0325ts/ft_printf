#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// void test_va_list(char *str, ...)
// {
//   va_list ap;
//   va_start(ap, str);
//   // const char *string = va_arg(ap, const char *);
//   printf("%s\n", va_arg(ap, const char *));
// }

// int main()
// {
//   // printf("%++d\n", 123);
//   test_va_list("a", "b");
//   // write(1, "%\n", 2);
//   return 0;
// }

#include <stdio.h>

int main(void)
{
	printf("1.[%d]\n", -1);
	printf("2.[%5d]\n", -1);
	printf("3.[%.-1d]\n", -1);
	printf("4.[% d]\n", 1);
	printf("5.[%+d]\n", 1);

	printf("6.[%#-x]\n", 1);

	return 0;
}

// int main(void)
// {
// 	puts("---'-'flag---");
// 	printf("[%10d]\n", 1);
// 	printf("[%-10d]\n", 1);

// 	printf("[%10f]\n", 1.0);
// 	printf("[%-10f]\n", 1.0);

// 	printf("[%10s]\n", "1234");
// 	printf("[%-10s]\n", "1234");

// 	puts("---'0'flag---");
// 	printf("[%10d]\n", 1);
// 	printf("[%010d]\n", 1);

// 	printf("[%10f]\n", 1.0);
// 	printf("[%010f]\n", 1.0);

// 	puts("---'+'flag---");
// 	printf("[%+d]\n", 1);
// 	printf("[%+d]\n", -1);

// 	printf("[%+f]\n", 1.0);
// 	printf("[%+f]\n", -1.0);

// 	puts("---'(space)'flag---");
// 	printf("[% d]\n", 1);
// 	printf("[% d]\n", -1);

// 	printf("[% f]\n", 1.0);
// 	printf("[% f]\n", -1.0);

// 	printf("[%10d]\n", 1);
// 	printf("[% 10d]\n", 1);
// 	printf("[%10d]\n", -1);
// 	printf("[% 10d]\n", -1);

// 	printf("[%10f]\n", 1.0);
// 	printf("[% 10f]\n", 1.0);
// 	printf("[%10f]\n", -1.0);
// 	printf("[% 10f]\n", -1.0);

// 	printf("[%-10f]\n", 1.0);
// 	printf("[%-10f]\n", -1.0);

// 	puts("---'#'flag---");
// 	printf("[%o]\n", 10);
// 	printf("[%#o]\n", 10);

// 	printf("[%x]\n", 10);
// 	printf("[%#x]\n", 10);

// 	printf("[%X]\n", 10);
// 	printf("[%#X]\n", 10);

// 	printf("[%.0f]\n", 1.0);
// 	printf("[%#.0f]\n", 1.0);

// 	printf("[%g]\n", 1.0);
// 	printf("[%#g]\n", 1.0);
// 	printf("[%#.0g]\n", 1.0);

// 	printf("[%G]\n", 1.0);
// 	printf("[%#G]\n", 1.0);
// 	printf("[%#.0G]\n", 1.0);
// }