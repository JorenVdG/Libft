/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:23:15 by jvan-der          #+#    #+#             */
/*   Updated: 2025/04/18 15:18:17 by jvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

// Helper Macros
#define TEST(name, cond) do { \
    if (cond) printf("[PASS] %s\n", name); \
    else printf("[FAIL] %s\n", name); \
} while (0)

char shift_char(unsigned int i, char c)
{
    (void)i;
    return c + 1;
}

void shift_char_in_place(unsigned int i, char *c)
{
    (void)i;
    *c += 1;
}
// Function Prototypes for each test
void test_part1(void);
void test_part2(void);
void test_output(void);

int main(void)
{
    printf("========== LIBFT TEST ==========\n\n");

    test_part1();
    test_part2();
    test_output();

    return 0;
}

void test_part1(void)
{
    printf("\n--- Part 1: Libc Functions ---\n");

    // Character checks
    TEST("ft_isalpha", (ft_isalpha('A') != 0) == (isalpha('A') != 0) \
    && (ft_isalpha('1') != 0) == (isalpha('1') != 0));
    TEST("ft_isdigit", (ft_isdigit('9') != 0) == (isdigit('9') != 0)  \
    && (ft_isdigit('A') != 0) == (isdigit('A') != 0));
    TEST("ft_isalnum", (ft_isalnum('9') != 0) == (isalnum('9') != 0)  \
    && (ft_isalnum('#') != 0) == (isalnum('#') != 0));
    TEST("ft_isascii", (ft_isascii('A') != 0) == (isascii('A') != 0)  \
    && (ft_isascii(200) != 0) == (isascii(200) != 0));
    TEST("ft_isprint", (ft_isprint('A') != 0) == (isprint('A') != 0)  \
    && (ft_isprint(31) != 0) == (isprint(31) != 0));

    // Memory and string
    char s1[] = "Hello";
    char s2[] = "Hello";
    TEST("ft_strlen", ft_strlen(s1) == strlen(s2));

    char buffer[10];
    ft_memset(buffer, 'a', 5);
    TEST("ft_memset", memcmp(buffer, "aaaaa", 5) == 0);

    char bz[10] = "123456";
    ft_bzero(bz, 4);
    TEST("ft_bzero", memcmp(bz, "\0\0\0\0", 4) == 0);

    char src[] = "12345";
    char dest1[10], dest2[10];
    ft_memcpy(dest1, src, 5);
    memcpy(dest2, src, 5);
    TEST("ft_memcpy", memcmp(dest1, dest2, 5) == 0);

    char mov1[] = "abcdef";
    ft_memmove(mov1 + 2, mov1, 4);
    char mov2[] = "abcdef";
    memmove(mov2 + 2, mov2, 4);
    TEST("ft_memmove", memcmp(mov1, mov2, 6) == 0);

    char lcpy_dest[10];
    ft_strlcpy(lcpy_dest, "Hello", 10);
    TEST("ft_strlcpy", strcmp(lcpy_dest, "Hello") == 0);

    char lcat_dest[20] = "Hi ";
    ft_strlcat(lcat_dest, "there", 20);
    TEST("ft_strlcat", strcmp(lcat_dest, "Hi there") == 0);

    TEST("ft_toupper", ft_toupper('a') == toupper('a'));
    TEST("ft_tolower", ft_tolower('Z') == tolower('Z'));

    TEST("ft_strchr", ft_strchr("hello", 'e') == strchr("hello", 'e'));
    TEST("ft_strrchr", ft_strrchr("hello", 'l') - "hello" \
		    == strrchr("hello", 'l') - "hello");

    TEST("ft_strncmp", ft_strncmp("abc", "abc", 3) == strncmp("abc", "abc", 3));
    TEST("ft_memchr", ft_memchr("abcde", 'c', 5) != NULL);
    TEST("ft_memcmp", ft_memcmp("abc", "abc", 3) == 0);

    TEST("ft_strnstr", ft_strnstr("hello world", "world", 11) != NULL);
    TEST("ft_atoi", ft_atoi("  -123") == atoi("  -123"));

    // calloc
    void *c = ft_calloc(5, sizeof(int));
    TEST("ft_calloc", c != NULL);
    free(c);

    // strdup
    char *d = ft_strdup("hello");
    TEST("ft_strdup", strcmp(d, "hello") == 0);
    free(d);
}
void test_part2(void)
{
    printf("\n--- Part 2: Additional Functions ---\n");

    // ft_substr
    char *sub = ft_substr("hello world", 6, 5);
    TEST("ft_substr", strcmp(sub, "world") == 0);
    free(sub);

    // ft_strjoin
    char *join = ft_strjoin("hello", "world");
    TEST("ft_strjoin", strcmp(join, "helloworld") == 0);
    free(join);

    // ft_strtrim
    char *trim = ft_strtrim("  hello  ", " ");
    TEST("ft_strtrim", strcmp(trim, "hello") == 0);
    free(trim);

    // ft_split
    char **split = ft_split("hello world test", ' ');
    TEST("ft_split", strcmp(split[0], "hello") == 0  \
		    && strcmp(split[1], "world") == 0 && split[3] == NULL);
    for (int i = 0; split[i]; i++) free(split[i]);
    free(split);

    // ft_itoa
    char *itoa = ft_itoa(-12345);
    TEST("ft_itoa", strcmp(itoa, "-12345") == 0);
    free(itoa);

    // ft_strmapi
    char *mapped = ft_strmapi("abc", shift_char);
    TEST("ft_strmapi", strcmp(mapped, "bcd") == 0);
    free(mapped);

    // ft_striteri
    char str[] = "abc";
    ft_striteri(str, shift_char_in_place);
    TEST("ft_striteri", strcmp(str, "bcd") == 0);
}


void test_output(void)
{
    printf("\n--- Part 3: Output Functions ---\n");
    printf("Check visually if output looks correct:\n");

    ft_putchar_fd('A', 1);
    write(1, " <- should be A\n", 16);

    ft_putstr_fd("Hello", 1);
    write(1, " <- should be Hello\n", 21);

    ft_putendl_fd("Line", 1); // newline after
    write(1, "(Above should be: Line\\n)\n", 27);

    ft_putnbr_fd(12345, 1);
    write(1, " <- should be 12345\n", 21);
}
*/
