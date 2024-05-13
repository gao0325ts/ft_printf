#include <stdio.h>

int main(void)
{
    char *s = "abc";
    void *p = &s;
    int tmp;

    tmp = printf("1.[%p]\n", p);
    printf("1=%d\n", tmp - 5);

    // printf("2.[%#p]\n", p); // flag_hash
    // printf("3.[%0p]\n", p); // flag_zero

    tmp = printf("4.[%-p]\n", p);
    printf("4=%d\n", tmp - 5);

    tmp = printf("5.[%-30p]\n", p);
    printf("5=%d\n", tmp - 5);

    // printf("6.[% p]\n", p); // flag_space
    // printf("7.[%+p]\n", p); // flag_plus

    tmp = printf("8.[%.p]\n", p);
    printf("8=%d\n", tmp - 5);

    // printf("9.[%.0p]\n", p); // undefined
    // printf("10.[%.5p]\n", p); // undefined
    // printf("11.[%0.p]\n", p); // flag_zero

    tmp = printf("12.[%30.p]\n", p);
    printf("12=%d\n", tmp - 6);

    // printf("13.[%0.0p]\n", p); // flag_zero
    // printf("14.[%0.5p]\n", p); // flag_zero
    // printf("15.[%05.5p]\n", p); // flag_zero

    // printf("16.[%5.0p]\n", p); // undefined
    // printf("17.[%5.2p]\n", p); // undefined

    tmp = printf("18.[%30p]\n", p);
    printf("18=%d\n", tmp - 6);

    // printf("19.[%-5.2p]\n", p); // undefined

    tmp = printf("20.[%p]\n", NULL);
    printf("20=%d\n", tmp - 6);

    return (0);
}
