#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_putcharptr(char *c)
{
    if (c)
        printf("%c", *c);
}
 
void ft_putcharptri(unsigned int i, char *c) {if (c) printf("%c", *c + i);}
 
char ft_smap(char c) { return c + 1; }
 
char ft_smapi(unsigned int i, char c) {return c + i;}
 
void ft_printlstitem(t_list *elem) {ft_putendl((char *)(elem->content));}
 
void    ft_lstdelete1(void *content, size_t n) {free(content); (void)n;}
 
t_list *ft_lstmaptest(t_list *elem) {((char *)elem->content)[0] = 's'; return elem;}
 
int main(void)
{
    int *test = malloc(4);
    int *real = malloc(4);
    char *x;
    char *tests = malloc(4);
    char *reals = malloc(4);
    char *tests2 = malloc(4);
    char *reals2 = malloc(4);
    size_t ret;
    size_t ret2;
 
 
    ft_putendl("TESTS BEGIN HERE\nThere shouldn't be any errors or warnings above this(?).");
 
    *test = 999999999;
    ft_memset(test, 150, 4);
    *real = 999999999;
    memset(real, 150, 4);
    if (memcmp(real, test, 4))
        printf("memset fail\n");
 
    ft_bzero(test, 4);
    bzero(real, 4);
    if (memcmp(real, test, 4))
        printf("bzero fail\n");
 
    *real = 999999999;
    ft_memcpy(test, real, 4);
    if (memcmp(real, test, 4))
        printf("memcpy fail\n");
 
    ft_putendl("all g up to memcpy?");
 
// TODO HUGE ERROR WITH MEMCCPY DOESNT WORK WITHOUT X WORKAROUND
 
    strcpy(tests, "123");
    strcpy(reals, "abc");
    x = ft_memccpy(tests, reals, 'x', 4);
    if (x)
        printf("memccpy1 fail\n");
    if (memcmp(tests, reals, 4))
        printf("memccpy2 fail\n");
    x = (char *)ft_memccpy(tests, reals, 'b', 4);
    if (memcmp(reals, tests, 4))
        printf("memccpy3 fail\n");
    if (*x != 'c')
        printf("memccpy4 fail\n");
 
    if (ft_memchr(tests, 'x', 4))
        printf("memchr1 fail\n");
    if (ft_memchr(tests, 'b', 4) != memchr(tests, 'b', 4))
        printf("memchr2 fail\n");
 
    strcpy(tests, "12c");
    strcpy(reals, "abc");
    tests = ft_memmove(tests, reals, 1);
    if (!memcmp(reals, tests, 4))
        printf("memmove fail\n");
    x = ft_memmove(tests, reals, 2);
    if (memcmp(reals, tests, 4))
        printf("memmove2 fail\n");
    if (x != tests)
        ft_putendl("memmove3 fail");
    char    srcm[] = "lorem ipsum dolor sit amet";
    char    *testm;
    testm = srcm + 1;
    testm = ft_memmove(testm, "consectetur", 5);
    testm = ft_memmove(testm, "con\0sec\0\0te\0tur", 10);
    testm = ft_memmove(testm, srcm, 8);
    ft_memmove(srcm, testm, 8);
    if (memcmp("con\0secc\0t dolor sit a", testm, 21))
        printf("memmove4 fail (overlapping memory areas)\n");
 
    if (ft_memcmp(reals, tests, 4))
        ft_putendl("memcmp fail");
    strcpy(reals, "123");
    strcpy(tests, "223");
    if (ft_memcmp(reals, tests, 4) >= 0)
        ft_putendl("memcmp2 fail");
    if (ft_memcmp(tests, reals, 4) <= 0)
        ft_putendl("memcmp3 fail");
 
    if (ft_strlen(reals) != 3)
        ft_putendl("strlen fail");
   
    ft_putendl("all g up to strdup?");
 
    x = ft_strdup(reals);
    if (memcmp(x, reals, 4))
        printf("strdup fail\n");
    free(x);
    x = ft_strdup("");
    if (!x)
        ft_putendl("strdup2 fail");
    if (*x)
        ft_putendl("strdup3 fail");
 
    strcpy(reals, "12");
    strcpy(tests, "223");
    tests = ft_strcpy(tests, reals);
    if (memcmp(tests, reals, 3))
        ft_putendl("strcpy1 fail");
    ft_strcpy(tests, "");
    if (memcmp(tests, &reals[2], 1))
        ft_putendl("strcpy2 fail");
 
    strcpy(reals, "abc");
    strcpy(tests, "123");
    ft_strncpy(tests, "abc", 1);
    if (strcmp("a23", tests))
        printf("strncpy1 fail\n");
    ft_strncpy(tests, "abcdefg", 3);
    if (strcmp("abc", tests))
        printf("strncpy2 fail\n");
    char *testnc = calloc(50, 1);
    char *realnc = calloc(50, 1);
    memset(testnc, 's', 13);
    memset(realnc, 's', 13);
    ft_strncpy(testnc, "", 3);
    strncpy(realnc, "", 3);
    if (memcmp(realnc, testnc, 10))
        ft_putendl("strncpy does not pad 0 when copying empty string");
   
    strcpy(tests, "");
    ft_strcat(tests, "1");
    if (strcmp(tests, "1"))
        ft_putendl("strcat1");
    ft_strcat(tests, "23");
    if (strcmp(tests, "123"))
        ft_putendl("strcat2");
 
    strcpy(tests, "");
    ft_strncat(tests, "12345", 3);
    if (strcmp(tests, "123"))
        ft_putendl("strcat2");
 
    ft_putendl("all g up to strncat?");
 
    strcpy(reals, "abc");
    strcpy(tests, "");
    strcpy(reals2, "abc");
    strcpy(tests2, "");
    ret = ft_strlcat(tests, reals, 4);
    ret2 = strlcat(tests2, reals2, 4);
    if (ret != ret2)
        ft_putendl("strlcat1");
    if (memcmp(tests, tests2, 4))
        ft_putendl("strlcat2");
    strcpy(tests, "");
    strcpy(tests2, "");
    ret = ft_strlcat(tests, reals, 3);
    ret2 = strlcat(tests2, reals2, 3);
    if (ret != ret2)
        ft_putendl("strlcat3");
    if (memcmp(tests, tests2, 3))
        ft_putendl("strlcat4");
    strcpy(tests, "asd");
    strcpy(tests2, "asd");
    ret = ft_strlcat(tests, reals, 1);
    ret2 = strlcat(tests2, reals2, 1);
    if (ret != ret2)
        ft_putendl("strlcat5");
    if (memcmp(tests, tests2, 3))
        ft_putendl("strlcat6");
    strcpy(tests, "asd");
    strcpy(tests2, "asd");
    ret = ft_strlcat(tests, reals, 0);
    ret2 = strlcat(tests2, reals2, 0);
    if (ret != ret2)
        ft_putendl("strlcat7");
    if (memcmp(tests, tests2, 3))
        ft_putendl("strlcat8");
    free(reals2);
    free(tests2);
 
    reals = strchr("abcabbcbabc", 'c');
    tests = ft_strchr("abcabbcbabc", 'c');
    if (strcmp(reals, tests))
        ft_putendl("strchr1 fail");
    reals = strchr("abcabbcbabc", 'x');
    tests = ft_strchr("abcabbcbabc", 'x');
    if (tests)
        ft_putendl("strchr2 fail");
 
    reals = strrchr("abcabbcbabc", 'c');
    tests = ft_strrchr("abcabbcbabc", 'c');
    if (strcmp(reals, tests))
        ft_putendl("strrchr1 fail");
    reals = strrchr("abcabbcbabc", 'x');
    tests = ft_strrchr("abcabbcbabc", 'x');
    if (tests)
        ft_putendl("strrchr2 fail");
 
    ft_putendl("all g up to strrchr?");
 
    reals = strstr("abababcabababc", "ababc");
    tests = ft_strstr("abababcabababc", "ababc");
    if (strcmp(reals, tests))
        ft_putendl("strstr1 fail");
    reals = strstr("ababababababc", "ababc");
    tests = ft_strstr("ababababababc", "ababc");
    if (strcmp(reals, tests))
        ft_putendl("strstr2 fail");
    reals = strstr("ababababababc", "");
    tests = ft_strstr("ababababababc", "");
    if (strcmp(reals, tests))
        ft_putendl("strstr3 fail");
    if (ft_strstr("abc", "x"))
        ft_putendl("strstr4 fail");
    if (ft_strstr("", "x"))
        ft_putendl("strstr5 fail");
    if (!ft_strstr("", ""))
        ft_putendl("strstr6 fail");
 
 
    reals = strnstr("abababcabababc", "ababc", 20);
    tests = ft_strnstr("abababcabababc", "ababc", 20);
    if (strcmp(reals, tests))
        ft_putendl("strnstr1 fail");
    reals = strnstr("ababababababc", "ababc", 20);
    tests = ft_strnstr("ababababababc", "ababc", 20);
    if (strcmp(reals, tests))
        ft_putendl("strnstr2 fail");
    reals = strnstr("ababababababc", "", 20);
    tests = ft_strnstr("ababababababc", "", 20);
    if (strcmp(reals, tests))
        ft_putendl("strnstr3 fail");
    if (ft_strnstr("abc", "x", 20))
        ft_putendl("strnstr4 fail");
    reals = strnstr("ababababababc", "", 10);
    tests = ft_strnstr("ababababababc", "", 10);
    if (strcmp(reals, tests))
        ft_putendl("strnstr5 fail");
    reals = strnstr("ababababababc", "", 11);
    tests = ft_strnstr("ababababababc", "", 11);
    if (strcmp(reals, tests))
        ft_putendl("strnstr6 fail");
    reals = strnstr("ababababababc", "", 12);
    tests = ft_strnstr("ababababababc", "", 12);
    if (strcmp(reals, tests))
        ft_putendl("strnstr7 fail");
    reals = strnstr("ababababababc", "", 13);
    tests = ft_strnstr("ababababababc", "", 13);
    if (strcmp(reals, tests))
        ft_putendl("strnstr8 fail");
    if (ft_strnstr("", "x", 1))
        ft_putendl("strnstr9 fail");
    if (!ft_strnstr("", "", 1))
        ft_putendl("strnstr10 fail");
 
    ft_putendl("THESE ERRORS BETWEEN #### AREN'T REAl ERRORS UNLESS THE SIGNS ARE DIFFERENT\n##############################################");
    if (strcmp("abc", "abc") != ft_strcmp("abc", "abc"))
        ft_putendl("strcmp1");
    printf("strcmp: %d ft_: %d\n", strcmp("abc", "abx"), ft_strcmp("abc", "abx"));
    if (strcmp("abc", "abx") != ft_strcmp("abc", "abx"))
        ft_putendl("huom strcmp2");
    printf("strcmp: %d ft_: %d\n", strcmp("abc", "aba"), ft_strcmp("abc", "aba"));
    if (strcmp("abc", "aba") != ft_strcmp("abc", "aba"))
        ft_putendl("huom strcmp3");
    char a[4] = { 1,2,3,0 };
    char b[4] = { 1,2,-3,0 };
    printf("strcmp: %d ft_: %d\n", strcmp(a, b), ft_strcmp(a, b));
    char c[4] = { 1,2,3,0 };
    char d[4] = { 1,2,10,0 };
    printf("strcmp: %d ft_: %d\n", strcmp(c, d), ft_strcmp(c, d));
    char e[4] = { 1,2,'a',0 };
    char f[4] = { 1,2,'x',0 };
    printf("strcmp: %d ft_: %d\n", strcmp(e, f), ft_strcmp(e, f));
    char s1[4] = "abc";
    char s2[4] = "aba";
    printf("strcmp: %d ft_: %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
    // Oh well they here now so why baleet
 
    printf("strncmp: %d ft_: %d\n", strncmp("abc", "abc", 5), ft_strncmp("abc", "abc", 5));
    if (strncmp("abc", "abc", 5) != ft_strncmp("abc", "abc", 5))
        ft_putendl("strncmp1");
    printf("strncmp: %d ft_: %d\n", strncmp("abc", "abc", 2), ft_strncmp("abc", "abc", 2));
    if (strncmp("abc", "abc", 2) != ft_strncmp("abc", "abc", 2))
        ft_putendl("strncmp2");
    printf("strncmp: %d ft_: %d\n", strncmp("abc", "aba", 5), ft_strncmp("abc", "aba", 5));
    if (strncmp("abc", "aba", 5) != ft_strncmp("abc", "aba", 5))
        ft_putendl("strncmp3");
    printf("strncmp: %d ft_: %d\n", strncmp("abc", "abx", 5), ft_strncmp("abc", "abx", 5));
    if (strncmp("abc", "abx", 5) != ft_strncmp("abc", "abx", 5))
        ft_putendl("strncmp4");
    printf("strncmp: %d ft_: %d\n", strncmp(a, b, 4), ft_strncmp(a, b, 4));
    ft_putendl("##############################################");
 
    char *atoi1 = "";
    char *atoi2 = "5";
    char *atoi3 = "-5";
    char *atoi4 = "- 5";
    char *atoi5 = "+5";
    char *atoi6 = "\t\n  \n 5";
    char *atoi7 = "a5";
    char *atoi8 = "5a";
    char *atoi9 = "\t\n  \n 5 \t";
    char *atoi10 = "5-";
    char *atoi11 = "0";
    char *atoi12 = "2147483647";
    char *atoi13 = "-2147483648";
    char *atoi14 = "2147483648";
    char *atoi15 = "99999999999999";
    char *atoi16 = "\e10";
    if (atoi(atoi1) != ft_atoi(atoi1))
        ft_putendl("atoi1");
    if (atoi(atoi2) != ft_atoi(atoi2))
        ft_putendl("atoi1a");
    if (atoi(atoi3) != ft_atoi(atoi3))
        ft_putendl("atoi1b");
    if (atoi(atoi4) != ft_atoi(atoi4))
        ft_putendl("atoi1d");
    if (atoi(atoi5) != ft_atoi(atoi5))
        ft_putendl("atoi1f");
    if (atoi(atoi6) != ft_atoi(atoi6))
        ft_putendl("atoi1g");
    if (atoi(atoi7) != ft_atoi(atoi7))
        ft_putendl("atoi1h");
    if (atoi(atoi8) != ft_atoi(atoi8))
        ft_putendl("atoi1u");
    if (atoi(atoi9) != ft_atoi(atoi9))
        ft_putendl("atoi1q");
    if (atoi(atoi10) != ft_atoi(atoi10))
        ft_putendl("atoi1ukj");
    if (atoi(atoi11) != ft_atoi(atoi11))
        ft_putendl("atoi1hdg");
    if (atoi(atoi12) != ft_atoi(atoi12))
        ft_putendl("atoi1fsdg");
    if (atoi(atoi13) != ft_atoi(atoi13))
        ft_putendl("atoi1fds");
    if (atoi(atoi14) != ft_atoi(atoi14))
        ft_putendl("atoi1fd");
    if (atoi(atoi15) != ft_atoi(atoi15))
        ft_putendl("atoi15");
    if (atoi(atoi16) != ft_atoi(atoi16))
        ft_putendl("atoi16");
    char *atoitests = malloc(10);
    strcpy(atoitests, "142");
    int i = 0;
    while (i < 255)
    {
        atoitests[0] = i;
        if (atoi(atoitests) != ft_atoi(atoitests))
            printf("atoi fails when first character is ascii %d\n", i);
        ++i;
    }
    i = 0;
    strcpy(atoitests, "4215");
    {
        atoitests[2] = i;
        if (atoi(atoitests) != ft_atoi(atoitests))
            printf("atoi fails when middle character is ascii %d\n", i);
        ++i;
    }
 
 
    if (ft_isalpha('a' - 1) || ft_isalpha('z' + 1))
        ft_putendl("isalpha1");
    if (!ft_isalpha('a') || !ft_isalpha('z') || !ft_isalpha('k'))
        ft_putendl("isalpha2");
 
    if (ft_isdigit(5) || ft_isdigit(47))
        ft_putendl("idigit1");
    if (!ft_isdigit('0') || !ft_isdigit('5') || !ft_isdigit('9'))
        ft_putendl("isdigit2");
 
    if (ft_isalnum('a' - 1) || ft_isalnum('z' + 1))
        ft_putendl("isalnum1");
    if (!ft_isalnum('a') || !ft_isalnum('z') || !ft_isalnum('0'))
        ft_putendl("isalnum2");
 
    if (ft_isascii(-1) || ft_isascii(128))
        ft_putendl("isascii1");
    if (!ft_isascii(0) || !ft_isascii(5) || !ft_isascii(127))
        ft_putendl("isascii2");
 
    if (ft_isprint(' ' - 1) || ft_isprint('~' + 1))
        ft_putendl("isprint1");
    if (!ft_isprint(' ') || !ft_isprint('~') || !ft_isprint(42))
        ft_putendl("isprint2");
 
    if (ft_toupper('a') != 'A')
        ft_putendl("toupper1");
    if (ft_toupper('z') != 'Z')
        ft_putendl("toupper2");
    if (ft_toupper('A') != 'A')
        ft_putendl("toupper3");
    if (ft_toupper('a' - 1) != 'a' - 1)
        ft_putendl("toupper4");
 
    if (ft_tolower('a') != 'a')
        ft_putendl("ft_tolower1");
    if (ft_tolower('Z') != 'z')
        ft_putendl("ft_tolower1");
    if (ft_tolower('A') != 'a')
        ft_putendl("ft_tolower1");
    if (ft_tolower('A' - 1) != 'A' - 1)
        ft_putendl("ft_tolower1");
 
    ft_putendl("---------------------");
    ft_putendl("Standard library functions end here");
    ft_putendl("---------------------");
 
        // Here goes additional functions
    int zeroint = 0;
    tests = ft_memalloc(4);
    if (memcmp(&zeroint, tests, 4))
        printf("memalloc\n");
 
    ft_memdel((void **)(&tests));
    if (tests)
        printf("memdel\n");
 
    ft_putendl("passes memdel without segfault");
 
    tests = ft_strnew(3);
    if (memcmp(&zeroint, tests, 4))
        printf("strnew\n");
    strcpy(tests, "asd");
    tests = ft_strnew(0);
    if (memcmp(&zeroint, tests, 1))
        printf("strnew2\n");
 
    ft_putendl("passes strnew without segfault");
 
    ft_strdel(&tests);
    if (tests)
        printf("strdel\n");
 
    tests = ft_strnew(4);
    strcpy(tests, "asd");
    ft_strclr(tests);
    if (memcmp(tests, &zeroint, 4))
        printf("strclr\n");
 
    ft_putendl("passes strclr without segfault");
 
    strcpy(tests, "asd");
    ft_putendl("The next 2 lines should match (ft_striter):\nasd");
    ft_striter(tests, &ft_putcharptr);
    printf("\n\n");
 
    ft_putendl("The next 2 lines should match(ft_striteri):\natf");
    ft_striteri(tests, &ft_putcharptri);
    printf("\n\n");
 
    int p = 999999999;
    memcpy(tests, &p, 4);
    tests = ft_strmap("asd", &ft_smap);
    if (strcmp(tests, "bte"))
        ft_putendl("strmap");
       
    memcpy(tests, &p, 4);
    strcpy(tests, "asd");
    tests = ft_strmapi("asd", &ft_smapi);
    if (strcmp(tests, "atf"))
        ft_putendl("strmapi");
 
    if (ft_strequ("asdfdsg", "asdfgsh"))
        printf("strequ\n");
    if (ft_strequ("abcde", "abcde") != 1)
        ft_putendl("strequ2");
 
    if (ft_strnequ("asdfgh", "asdfgg", 5) != 1)
        printf("strnequ\n");
    if (ft_strnequ("abc", "abd", 2) != 1)
        ft_putendl("strnequ2");
    if (ft_strnequ("abc", "abc", 5) != 1)
        printf("strnequ3\n");
    if (ft_strnequ("abcd", "abce", 4))
        ft_putendl("strnequ4");
 
    ft_putendl("strnequ passed without segfault");
 
    if (strcmp(ft_strsub("12345", 2, 2), "34"))
        ft_putendl("strsub1");
    if (strcmp(ft_strsub("12345", 0, 1), "1"))
        ft_putendl("strsub2");
    if (strcmp(ft_strsub("12345", 0, 0), ""))
        ft_putendl("strsub3");
 
    if (strcmp(ft_strjoin("abc", "12345"), "abc12345"))
        ft_putendl("join1");
    if (strcmp(ft_strjoin("", "1"), "1"))
        ft_putendl("join2");
    if (strcmp(ft_strjoin("1", ""), "1"))
        ft_putendl("join3");
 
    char *s;
    s = ft_strtrim("abc");
    if (strcmp(s, "abc"))
        ft_putendl("strtrim1");
    if (strcmp("abc", ft_strtrim("  \t  \t \nabc\t \t \t \n    \t")))
        ft_putendl("strtrim2");
 
    ft_putendl("ft_strtrim passes");
 
    char **split = ft_strsplit(" a\tb c ", ' ');
    if (strcmp(split[0], "a\tb"))
        printf("strsplit1\n");
    if (strcmp(split[1], "c"))
        printf("strsplit2\n");
    if (split[2])
        printf("strsplit3\n");
 
    split = ft_strsplit("********", '*');
    if (split[0])
        printf("strsplit4\n");
 
    if (strcmp(ft_itoa(0), "0"))
        ft_putendl("itoa0");
    if (strcmp(ft_itoa(-5), "-5"))
        ft_putendl("itoa-5");
    if (strcmp(ft_itoa(5), "5"))
        ft_putendl("itoa5");
    if (strcmp(ft_itoa(-2147483648), "-2147483648"))
        ft_putendl("itoa min");
    if (strcmp(ft_itoa(2147483647), "2147483647"))
        ft_putendl("itoa max");
 
    ft_putendl("itoa done");
 
    ft_putstr("The following line pairs should match\n");
    ft_putnbr(0);
    printf("\n0\n\n");
    ft_putnbr(-5);
    printf("\n-5\n\n");
    ft_putnbr(-2147483648);
    printf("\n-2147483648\n\n");
    ft_putnbr(2147383647);
    printf("\n2147383647\n\n");
 
 
    ft_putendl("Checked parts 1 and 2. Also there should be 2 empty lines before this (maybe)");
    ft_putendl("Maybe manually check all the _fd functions and ft_putchar");
    ft_putendl("--------------------------------");
    ft_putendl("Checking bonuses");
 
 
    t_list *head = ft_lstnew("asd", 4);
    ft_lstadd(&head, ft_lstnew("123", 4));
    if (memcmp(head->content, "123", 4))
        printf("lstadd or lstnew fail\n");
    if (memcmp(head->next->content, "asd", 4))
        printf("probably lstadd fail\n");
    ft_lstadd(&head, ft_lstnew("xyz", 4));
    ft_putendl("the following 3 lines should be repeated after an empty line (lstiter):\nsyz\ns23\nssd\n");
    t_list *head2 = ft_lstmap(head, &ft_lstmaptest);
    ft_lstiter(head2, &ft_printlstitem);
 
    ft_putendl("If so, lstadd, lstnew, lstmap and lstiter tested.\n###");
   
    ft_lstdelone(&(head->next->next), &ft_lstdelete1);
    if (head->next->next)
        ft_putendl("lstdelone fail");
    ft_lstdel(&head, &ft_lstdelete1);
    if (head)
        ft_putendl("lstdel fail");
    ft_putendl("If the previous line is '###', lstdel and lstdelone worked");
   
   
   
    return 0;
}
