#include <stdio.h>

// int main(void)
// {
//     // char *s = "abc";
//     void *p = NULL;
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

int main(void)
{
    int tmp;

    tmp = printf("1.[%s]\n", NULL);
    printf("1=%d\n", tmp - 5);

    // printf("2.[%#s]\n", "abc"); // flag_hash
    // printf("3.[%0s]\n", "abc"); // flag_zero

    tmp = printf("4.[%-s]\n", "abc");
    printf("4=%d\n", tmp - 5);

    tmp = printf("5.[%-10.3s]\n", NULL);
    printf("5=%d\n", tmp - 5);

    // printf("6.[% s]\n", "abc"); // flag_space
    // printf("7.[%+s]\n", "abc"); // flag_plus

    tmp = printf("8.[%.s]\n", "abc");
    printf("8=%d\n", tmp - 5);

    tmp = printf("9.[%.0s]\n", "abc");
    printf("9=%d\n", tmp - 5);

    tmp = printf("10.[%.5s]\n", "abc");
    printf("10=%d\n", tmp - 6);

    // printf("11.[%0.s]\n", "abc"); // flag_zero

    tmp = printf("12.[%5.s]\n", "abc");
    printf("12=%d\n", tmp - 6);

    // printf("13.[%0.0s]\n", "abc"); // flag_zero
    // printf("14.[%0.5s]\n", "abc"); // flag_zero
    // printf("15.[%05.5s]\n", "abc"); // flag_zero

    tmp = printf("16.[%5.0s]\n", "abc");
    printf("16=%d\n", tmp - 6);

    tmp = printf("17.[%5.2s]\n", "abc");
    printf("17=%d\n", tmp - 6);

    tmp = printf("18.[%5s]\n", "abc");
    printf("18=%d\n", tmp - 6);

    tmp = printf("19.[%-5.2s]\n", "abc");
    printf("19=%d\n", tmp - 6);

    return (0);
}