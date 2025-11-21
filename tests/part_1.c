/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:21:56 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/21 17:49:49 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define C_RED   "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"

static int g_failures = 0;

static void assert_int_equal(const char *label, int expected, int actual)
{
    if (expected == actual)
        printf(C_GREEN "[OK]   %s (exp=%d, got=%d)\n" C_RESET,
               label, expected, actual);
    else
    {
        printf(C_RED   "[KO]   %s (exp=%d, got=%d)\n" C_RESET,
               label, expected, actual);
        g_failures++;
    }
}

static void assert_size_t_equal(const char *label, size_t expected, size_t actual)
{
    if (expected == actual)
        printf(C_GREEN "[OK]   %s (exp=%zu, got=%zu)\n" C_RESET,
               label, expected, actual);
    else
    {
        printf(C_RED   "[KO]   %s (exp=%zu, got=%zu)\n" C_RESET,
               label, expected, actual);
        g_failures++;
    }
}

static void assert_str_equal(const char *label, const char *expected, const char *actual)
{
    int equal = 0;

    if (!expected && !actual)
        equal = 1;
    else if (expected && actual && strcmp(expected, actual) == 0)
        equal = 1;

    if (equal)
        printf(C_GREEN "[OK]   %s (exp=\"%s\", got=\"%s\")\n" C_RESET,
               label,
               expected ? expected : "(null)",
               actual ? actual : "(null)");
    else
    {
        printf(C_RED   "[KO]   %s (exp=\"%s\", got=\"%s\")\n" C_RESET,
               label,
               expected ? expected : "(null)",
               actual ? actual : "(null)");
        g_failures++;
    }
}

static void assert_ptr_equal(const char *label, const void *expected, const void *actual)
{
    if (expected == actual)
        printf(C_GREEN "[OK]   %s (exp=%p, got=%p)\n" C_RESET,
               label, expected, actual);
    else
    {
        printf(C_RED   "[KO]   %s (exp=%p, got=%p)\n" C_RESET,
               label, expected, actual);
        g_failures++;
    }
}

static void test_isalpha(void)
{
    printf(C_YELLOW "\n=== TEST: ft_isalpha ===\n" C_RESET);

    int chars[] = { 'a', 'Z', '0', '9', ' ', '@', 'k', '\n', 'x' };
    size_t n = sizeof(chars) / sizeof(chars[0]);

    for (size_t i = 0; i < n; i++)
    {
        char c = (char)chars[i];
        char label[64];

        snprintf(label, sizeof(label), "ft_isalpha('%c')", c);
        int std = isalpha(c);
        int mine = ft_isalpha(c);

        assert_int_equal(label, std!=0, mine!=0);
    }
}

static void test_isdigit(void)
{
    printf(C_YELLOW "\n=== TEST: ft_isdigit ===\n" C_RESET);

    int chars[] = { 'a', 'Z', '0', '5', '9', ' ', '@', '3', '\n' };
    size_t n = sizeof(chars) / sizeof(chars[0]);

    for (size_t i = 0; i < n; i++)
    {
        char c = (char)chars[i];
        char label[64];

        snprintf(label, sizeof(label), "ft_isdigit('%c')", c);
        int std = isdigit(c);
        int mine = ft_isdigit(c);

        assert_int_equal(label, std!=0, mine!=0);
    }
}

static void test_isalnum(void)
{
    printf(C_YELLOW "\n=== TEST: ft_isalnum ===\n" C_RESET);

    int chars[] = { 'a', 'Z', '0', '5', '9', ' ', '@', '3', '\n', '~', '\033' };
    size_t n = sizeof(chars) / sizeof(chars[0]);

    for (size_t i = 0; i < n; i++)
    {
        char c = (char)chars[i];
        char label[64];

        snprintf(label, sizeof(label), "ft_isalnum('%c')", c);
        int std = isalnum((unsigned char)c);
        int mine = ft_isalnum((unsigned char)c);

        assert_int_equal(label, std!=0, mine!=0);
    }
}

static void test_isascii(void)
{
    printf(C_YELLOW "\n=== TEST: ft_isascii ===\n" C_RESET);

    int chars[] = { -1, 0, 65, 97, 127, 128, 255, '/033', 's', '\n', '\xFF' , '\x00'};
    size_t n = sizeof(chars) / sizeof(chars[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = chars[i];
        char label[64];

        snprintf(label, sizeof(label), "ft_isascii(%d)", c);
        int std = isascii(c);
        int mine = ft_isascii(c);

        assert_int_equal(label, std, mine);
    }
}

void test_isprint(void)
{
    printf(C_YELLOW "\n=== TEST: ft_isprint ===\n" C_RESET);
    
    int chars[] = {'\n', ' ', '1', 'a', '~', '\0'};
    size_t n = sizeof(chars) / sizeof(chars[0]);
    
    for(size_t i = 0; i < n; i++)
    {
        int c = chars[i];
        char label[64];

        snprintf(label, sizeof(label), "ft_isprint(%d)", c);
        int std = isprint(c);
        int mine = ft_isprint(c);
        
        assert_int_equal(label, std!=0, mine!=0);
    }
}

static void test_strlen(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strlen ===\n" C_RESET);
    char *strings[] = { "ahas\0df", "Z", "0\0\0a", "9", "" , "@\033a", "k\322s", "\n", "x" };
    size_t n = sizeof(strings) / sizeof(strings[0]);

    for (size_t i = 0; i < n; i++)
    {
        char label[64];

        snprintf(label, sizeof(label), "ft_strlen('%s')", strings[i]);
        size_t std = strlen(strings[i]);
        size_t mine = ft_strlen(strings[i]);

        assert_size_t_equal(label, std, mine);
    }
}

static void test_memset(void)
{
    printf(C_YELLOW "\n=== TEST: ft_memset ===\n" C_RESET);

    char buffer1[] = "Hello, World!";
    char buffer2[] = "Hello, World!";

    memset(buffer1, 'A', sizeof(buffer1)-4);
    ft_memset(buffer2, 'A', sizeof(buffer2)-4);
    
    for (size_t i = 0; i < sizeof(buffer1); i++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_memset buffer[%zu]", i);
        assert_int_equal(label, buffer1[i], buffer2[i]);
    }
}

void test_bzero(void)
{
    printf(C_YELLOW "\n=== TEST: ft_bzero ===\n" C_RESET);

    char buffer1[] = "Hello, World!";
    char buffer2[] = "Hello, World!";

    bzero(buffer1, 5);
    ft_bzero(buffer2, 5);
    
    for (size_t i = 0; i < sizeof(buffer1); i++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_bzero buffer[%zu]", i);
        assert_int_equal(label, buffer1[i], buffer2[i]);
    }
}

void test_memcpy(void)
{
    printf(C_YELLOW "\n=== TEST: ft_memcpy ===\n" C_RESET);

    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];

    memcpy(dest1, src, sizeof(src));
    ft_memcpy(dest2, src, sizeof(src));
    
    for (size_t i = 0; i < sizeof(src); i++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_memcpy dest[%zu]", i);
        assert_int_equal(label, dest1[i], dest2[i]);
    }
}

void    test_memmove(void)
{
    printf(C_YELLOW "\n=== TEST: ft_memmove ===\n" C_RESET);

    char buffer1[] = "Hello, World!";
    char buffer2[] = "Hello, World!";

    ft_memmove(buffer1 + 2, buffer1, sizeof(buffer1) - 2);
    memmove(buffer2+2, buffer2, sizeof(buffer2) - 2);
    
    for (size_t i = 0; i < sizeof(buffer1); i++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_memmove buffer[%zu]", i);
        assert_int_equal(label, buffer1[i], buffer2[i]);
    }
}

void test_strlcpy(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strlcpy ===\n" C_RESET);

    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];

    size_t ret1 = strlcpy(dest1, src, sizeof(dest1));
    size_t ret2 = ft_strlcpy(dest2, src, sizeof(dest2));
    
    assert_size_t_equal("ft_strlcpy return value", ret1, ret2);
    
    for (size_t i = 0; i < sizeof(src); i++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_strlcpy dest[%zu]", i);
        assert_int_equal(label, dest1[i], dest2[i]);
    }
}

void test_strlcat(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strlcat ===\n" C_RESET);

    char src[] = " World!";
    char dest1[20] = "Hello,";
    char dest2[20] = "Hello,";

    size_t ret1 = strlcat(dest1, src, sizeof(dest1));
    size_t ret2 = ft_strlcat(dest2, src, sizeof(dest2));
    
    assert_size_t_equal("ft_strlcat return value", ret1, ret2);
    
    for (size_t i = 0; i < sizeof(dest1); i++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_strlcat dest[%zu]", i);
        assert_int_equal(label, dest1[i], dest2[i]);
    }
}

void test_toupper(void)
{
    printf(C_YELLOW "\n=== TEST: ft_toupper ===\n" C_RESET);

    for (int c = 0; c <= 255; c++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_toupper(%d)", c);
        int std = toupper(c);
        int mine = ft_toupper(c);
        assert_int_equal(label, std, mine);
    }
}

void test_tolower(void)
{
    printf(C_YELLOW "\n=== TEST: ft_tolower ===\n" C_RESET);

    for (int c = 0; c <= 255; c++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_tolower(%d)", c);
        int std = tolower(c);
        int mine = ft_tolower(c);

        assert_int_equal(label, std, mine);
    }
}

void    test_strchr(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strchr ===\n" C_RESET);

    const char *str = "Hello, World!";
    for (int c = -1; c <= 128; c++)
    {
        char label[64];
        snprintf(label, sizeof(label), "ft_strchr('%s', %d)", str, c);
        char *std = strchr(str, c);
        char *mine = ft_strchr(str, c);

        assert_ptr_equal(label, std, mine);
    }
}

void    test_strrchr(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strrchr ===\n" C_RESET);

    const char *str = "Hello, World!";
    char label[64];
    for (int c = -1; c <= 128; c++)
    {

        snprintf(label, sizeof(label), "ft_strrchr('%s', %d)", str, c);
        char *std = strrchr(str, c);
        char *mine = ft_strrchr(str, c);

        assert_ptr_equal(label, std, mine);
    }
    str = NULL;
    snprintf(label, sizeof(label), "ft_strrchr('%s', %d)", str, 'A');
    char *std = strrchr(str, 'A');
    char *mine = ft_strrchr(str, 'A');
    assert_ptr_equal(label, std, mine);
}

void test_strncmp(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strncmp ===\n" C_RESET);

    const char *pairs[][2] = {
        {"Hello", "Hello"},
        {"Hello", "Hell"},
        {"Hello", "Hello, World!"},
        {"abc", "abd"},
        {"", ""},
        {"abc", ""},
        {"", "abc"},
        {"same", "same"},
        {"case", "Case"},
    };
    size_t n_pairs = sizeof(pairs) / sizeof(pairs[0]);

    for (size_t i = 0; i < n_pairs; i++)
    {
        const char *s1 = pairs[i][0];
        const char *s2 = pairs[i][1];

        for (size_t n = 0; n <= 10; n++)
        {
            char label[128];
            snprintf(label, sizeof(label), "ft_strncmp('%s', '%s', %zu)", s1, s2, n);
            int std = strncmp(s1, s2, n);
            int mine = ft_strncmp(s1, s2, n);

            // Normalize return values to -1, 0, 1
            if (std < 0) std = -1;
            else if (std > 0) std = 1;

            if (mine < 0) mine = -1;
            else if (mine > 0) mine = 1;

            assert_int_equal(label, std, mine);
        }
    }
}

int main(void)
{
    printf(C_YELLOW "======= LIBFT TESTS (PARTIAL) =======\n" C_RESET);

    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    // test_toupper();
    // test_tolower();
    test_strchr();
    test_strncmp();

    printf(C_YELLOW "\n=====================================\n" C_RESET);
    if (g_failures == 0)
    {
        printf(C_GREEN "ALL TESTS PASSED 🎉\n" C_RESET);
        return 0;
    }
    else
    {
        printf(C_RED "%d TEST(S) FAILED ❌\n" C_RESET, g_failures);
        return 1;
    }
}
