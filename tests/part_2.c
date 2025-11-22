/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:03:22 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 12:02:17 by prasingh         ###   ########.fr       */
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

void test_substr(void)
{
    printf(C_YELLOW "\n=== TEST: ft_substr ===\n" C_RESET);

    const char *tests[] = {
        "Hello, World!",
        "",
        "Short",
        "A longer string to test substr function.",
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        const char *str = tests[i];
        size_t len = strlen(str);

        for (size_t start = 0; start <= len; start++)
        {
            for (size_t sub_len = 0; sub_len <= len - start + 1; sub_len++)
            {
                char label[128];
                snprintf(label, sizeof(label), "ft_substr('%s', %zu, %zu)", str, start, sub_len);

                char *std = strndup(str + start, sub_len);
                char *mine = ft_substr(str, start, sub_len);

                assert_str_equal(label, std, mine);

                free(std);
                free(mine);
            }
        }
    }
}

void test_strjoin(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strjoin ===\n" C_RESET);

    const char *test_cases[][2] = {
        {"Hello, ", "World!"},
        {"", ""},
        {"Foo", ""},
        {"", "Bar"},
        {"Longer string ", "with another longer string."},
    };
    size_t n_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        const char *s1 = test_cases[i][0];
        const char *s2 = test_cases[i][1];

        char label[128];
        snprintf(label, sizeof(label), "ft_strjoin('%s', '%s')", s1, s2);

        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);
        char *std = (char *)malloc(len1 + len2 + 1);
        if (std)
        {
            strcpy(std, s1);
            strcat(std, s2);
        }
        char *mine = ft_strjoin(s1, s2);

        assert_str_equal(label, std, mine);

        free(std);
        free(mine);
    }
}

int main(void)
{
    printf(C_YELLOW "======= LIBFT TESTS (PARTIAL) =======\n" C_RESET);
    
    test_substr();
    test_strjoin();
    

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
