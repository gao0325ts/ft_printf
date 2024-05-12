#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

//  ##   ##    ##
//  ##   ##   ####
//   ## ##   ##  ##
//   ## ##   ##  ##
//    ###    ######
//    ###    ##  ##
//     #     ##  ##

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
//   return (0);
// }

//    ####
//   ##  ##
//  ##
//  ##
//  ##
//   ##  ##
//    ####

// 対応フラグ：-
// 最小フィールド幅：OK 空白で埋められる
// 精度：ピリオドだけはOK 後ろに数字があったらerror

// int main(void)
// {
//     int tmp;

//     tmp = printf("1.[%c]\n", 'a');
//     printf("1=%d\n", tmp - 5);

//     // printf("2.[%#c]\n", 'a'); // flag_hash
//     // printf("3.[%0c]\n", 'a'); // flag_zero

//     tmp = printf("4.[%-c]\n", 'a');
//     printf("4=%d\n", tmp - 5);

//     tmp = printf("5.[%-5c]\n", 'a');
//     printf("5=%d\n", tmp - 5);

//     // printf("6.[% c]\n", 'a'); // flag_space
//     // printf("7.[%+c]\n", 'a'); // flag_plus

//     tmp = printf("8.[%.c]\n", 'a');
//     printf("8=%d\n", tmp - 5);

//     // printf("9.[%.0c]\n", 'a'); // undefined
//     // printf("10.[%.5c]\n", 'a'); // undefined
//     printf("11.[%0.5c]\n", 'a'); // flag_zero

//     tmp = printf("12.[%5.c]\n", 'a');
//     printf("12=%d\n", tmp - 6);

//     // printf("13.[%0.0c]\n", 'a'); // flag_zero
//     // printf("14.[%0.5c]\n", 'a'); // flag_zero
//     // printf("15.[%05.5c]\n", 'a'); // flag_zero
//     // printf("16.[%5.0c]\n", 'a'); // undefined
//     // printf("17.[%5.5c]\n", 'a'); // undefined

//     tmp = printf("18.[%5c]\n", 'a');
//     printf("18=%d\n", tmp - 6);

//     return (0);
// }

//   #####
//  ##   ##
//  #
//   #####
//       ##
//  ##   ##
//   #####

// 対応フラグ：-
// 最小フィールド幅：OK 文字列の長さより長ければ空白で埋められる
// 精度：OK 文字列の長さより短ければ精度が優先される

// int main(void)
// {
//     int tmp;

//     tmp = printf("1.[%s]\n", "abc");
//     printf("1=%d\n", tmp - 5);

//     // printf("2.[%#s]\n", "abc"); // flag_hash
//     // printf("3.[%0s]\n", "abc"); // flag_zero

//     tmp = printf("4.[%-s]\n", "abc");
//     printf("4=%d\n", tmp - 5);

//     tmp = printf("5.[%-5s]\n", "abc");
//     printf("5=%d\n", tmp - 5);

//     // printf("6.[% s]\n", "abc"); // flag_space
//     // printf("7.[%+s]\n", "abc"); // flag_plus

//     tmp = printf("8.[%.s]\n", "abc");
//     printf("8=%d\n", tmp - 5);

//     tmp = printf("9.[%.0s]\n", "abc");
//     printf("9=%d\n", tmp - 5);

//     tmp = printf("10.[%.5s]\n", "abc");
//     printf("10=%d\n", tmp - 6);

//     // printf("11.[%0.s]\n", "abc"); // flag_zero

//     tmp = printf("12.[%5.s]\n", "abc");
//     printf("12=%d\n", tmp - 6);

//     // printf("13.[%0.0s]\n", "abc"); // flag_zero
//     // printf("14.[%0.5s]\n", "abc"); // flag_zero
//     // printf("15.[%05.5s]\n", "abc"); // flag_zero

//     tmp = printf("16.[%5.0s]\n", "abc");
//     printf("16=%d\n", tmp - 6);

//     tmp = printf("17.[%5.2s]\n", "abc");
//     printf("17=%d\n", tmp - 6);

//     tmp = printf("18.[%5s]\n", "abc");
//     printf("18=%d\n", tmp - 6);

//     tmp = printf("19.[%-5.2s]\n", "abc");
//     printf("19=%d\n", tmp - 6);

//     return (0);
// }

//  ######
//   ##  ##
//   ##  ##
//   #####
//   ##
//   ##
//  ####

// 対応フラグ：-（ただし影響なし）
// 最小フィールド幅：OK 空白で埋められる
// 精度：ピリオドだけはOK 後ろに数字があったらerror

// int main(void)
// {
//     char *s = "abc";
//     void *p = &s;
//     int tmp;

//     tmp = printf("1.[%p]\n", p);
//     printf("1=%d\n", tmp - 5);

//     // printf("2.[%#p]\n", p); // flag_hash
//     // printf("3.[%0p]\n", p); // flag_zero

//     tmp = printf("4.[%-p]\n", p);
//     printf("4=%d\n", tmp - 5);

//     tmp = printf("5.[%-30p]\n", p);
//     printf("5=%d\n", tmp - 5);

//     // printf("6.[% p]\n", p); // flag_space
//     // printf("7.[%+p]\n", p); // flag_plus

//     tmp = printf("8.[%.p]\n", p);
//     printf("8=%d\n", tmp - 5);

//     // printf("9.[%.0p]\n", p); // undefined
//     // printf("10.[%.5p]\n", p); // undefined
//     // printf("11.[%0.p]\n", p); // flag_zero

//     tmp = printf("12.[%30.p]\n", p);
//     printf("12=%d\n", tmp - 6);

//     // printf("13.[%0.0p]\n", p); // flag_zero
//     // printf("14.[%0.5p]\n", p); // flag_zero
//     // printf("15.[%05.5p]\n", p); // flag_zero

//     // printf("16.[%5.0p]\n", p); // undefined
//     // printf("17.[%5.2p]\n", p); // undefined

//     tmp = printf("18.[%30p]\n", p);
//     printf("18=%d\n", tmp - 6);

//     // printf("19.[%-5.2p]\n", p); // undefined

//     tmp = printf("20.[%p]\n", NULL);
//     printf("20=%d\n", tmp - 6);

//     return (0);
// }

//  #####
//   ## ##
//   ##  ##
//   ##  ##
//   ##  ##
//   ## ##
//  #####

// 対応フラグ：-, 0,  , +
// 最小フィールド幅：OK
// 精度：OK

// int	main(void)
// {
// 	int	m;

// 	int d = 123;
// 	m = -123;
// 	// int tmp;
// 	printf("1.[%d]\n", m);
// 	// printf("2.[%#d]\n", m); // flag_hash
// 	printf("3.[%5d]\n", m);
// 	printf("4.[%-d]\n", m);
// 	printf("5.[%10d]\n", m);
// 	printf("6.[%- 2d]\n", m);
// 	printf("7.[%+-2d]\n", m);
// 	printf("8.[%.d]\n", m);
// 	printf("9.[%.0d]\n", m);
// 	printf("10.[%5.d]\n", m);
// 	printf("11.[%0.d]\n", m);
// 	printf("12.[%+1.2d]\n", m);
// 	printf("13.[%0.8d]\n", d);
// 	printf("13-2.[%0.8d]\n", m);
// 	printf("14.[%1.4d]\n", d);
// 	printf("14-2.[%1.4d]\n", m);
// 	printf("15.[%+10.5d]\n", m);
// 	printf("16.[%5.0d]\n", m);
// 	printf("17.[%5.6d]\n", m);
// 	printf("18.[%- 8d]\n", m);
// 	printf("19.[%-10.5d]\n", m);
// 	return (0);
// }



//  ##   ##
//  ##   ##
//  ##   ##
//  ##   ##
//  ##   ##
//  ##   ##
//   #####

// 対応フラグ：-, 0
// 最小フィールド幅：OK
// 精度：OK

// int	main(void)
// {
// 	unsigned int u = 123;
// 	// int tmp;
// 	printf("a.[%u]\n", u);
// 	// printf("b.[%#u]\n", u); // flag_hash
// 	printf("c.[%010u]\n", u);
// 	printf("d.[%-u]\n", u);
// 	printf("e.[%10u]\n", u);
// 	// printf("f.[%- 2u]\n", u); // flag_space
// 	printf("g.[%10.5u]\n", u);
// 	printf("h.[%.u]\n", u);
// 	printf("i.[%0.10u]\n", u);
// 	printf("j.[%10.0u]\n", u);
// 	printf("k.[%0.u]\n", u);
// 	// printf("l.[%+1.2u]\n", u); // flag_plus
// 	printf("m.[%09u]\n", u);
// 	printf("n.[%1.4u]\n", u);
// 	// printf("o.[%+10.5u]\n", u); // flag_plus
// 	printf("p.[%5.0u]\n", u);
// 	printf("q.[%5.6u]\n", u);
// 	printf("r.[%-8u]\n", u);
// 	printf("s.[%-10.5u]\n", u);
// 	return (0);
// }



//  ##  ##
//  ##  ##
//   ####
//    ##
//   ####
//  ##  ##
//  ##  ##

// 対応フラグ：#, -, 0
// 最小フィールド幅：OK
// 精度：OK

int	main(void)
{
	int x = 255;
	// int tmp;
	printf("a.[%x]\n", x);
	printf("b.[%#x]\n", x); // flag_hash
	printf("c.[%#010x]\n", x);
	printf("d.[%x]\n", x);
	printf("e.[%-10x]\n", x);
	// printf("f.[%- 2x]\n", x); // flag_space
	printf("g.[%10.5x]\n", x);
	printf("h.[%.x]\n", x);
	printf("i.[%0.10x]\n", x);
	printf("j.[%10.0x]\n", x);
	printf("k.[%0.x]\n", x);
	// printf("l.[%+1.2x]\n", x); // flag_plus
	printf("m.[%09x]\n", x);
	printf("n.[%1.4x]\n", x);
	// printf("o.[%+10.5x]\n", x); // flag_plus
	printf("p.[%5.0x]\n", x);
	printf("q.[%5.6x]\n", x);
	printf("r.[%-8x]\n", x);
	printf("s.[%-10.5x]\n", x);
	return (0);
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