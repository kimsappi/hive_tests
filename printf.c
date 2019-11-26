#include "ft_printf.h"
#include <stdio.h>

int main() {
double d = 123.45678901234;
int ret1;
int ret2;
	char a[] = "asd";
ret1 = ret1 = ft_printf("##########asd\n%s\n%c\n", "123", 'X');
ret2 = printf("##########asd\n%s\n%c\n", "123", 'X');
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%-05da\n", 123);
ret2 = printf("%-05da\n", 123);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("next line should be hex:\n");
ret2 = printf("next line should be hex:\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%x\n", 200);
ret2 = printf("%x\n", 200);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("ptr: %p\n", a);
ret2 = printf("ptr: %p\n", a);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("nullptr: %p\n", NULL);
ret2 = printf("nullptr: %p\n", NULL);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("real\nft\n");
ret2 = printf("real\nft\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%05d\n", 123);
ret2 = printf("%05d\n", 123);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%05d\n", 123);
ret2 = printf("%05d\n", 123);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%5%\n");
ret2 = printf("%5%\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%08x\n", 42);
ret2 = printf("%08x\n", 42);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%05.3d\n", -42);
ret2 = printf("%05.3d\n", -42);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%p\n%7pa\n", NULL, NULL);
ret2 = printf("%p\n%7pa\n", NULL, NULL);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("% h\n");
ret2 = printf("% h\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%.3s\n", NULL);
ret2 = printf("%.3s\n", NULL);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("#%08.5x#\n", 0);
ret2 = printf("#%08.5x#\n", 0);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("#%#-3x#\n", 0);
ret2 = printf("#%#-3x#\n", 0);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("\n###\n%.10f\n", d);
ret2 = printf("\n###\n%.10f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%.10f\n###\n", d);
ret2 = printf("%.10f\n###\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("&ft_printf: %p\n", &ft_printf);
ret2 = printf("&ft_printf: %p\n", &ft_printf);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = printf("&printf   : %p\n", &printf);
ret2 = printf("&printf   : %p\n", &printf);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = printf("&var      : %p\n", &d);
ret2 = printf("&var      : %p\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("&ft_printf: %p\n", &printf);
ret2 = printf("&ft_printf: %p\n", &printf);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

d = 0.999999;
ret1 = ft_printf("ft:%f\n", d);
ret2 = printf("ft:%f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

d = 0.9999999;
ret1 = ft_printf("ft:%f\n", d);
ret2 = printf("ft:%f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

d = -0.000001;
ret1 = ft_printf("ft:%f\n", d);
ret2 = printf("ft:%f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%.3s\n", "hello");
ret2 = printf("%.3s\n", "hello");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

ret1 = ft_printf("%p\n", &d);
ret2 = printf("%p\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n") : 0; printf("\n\n");

return 0;
}
