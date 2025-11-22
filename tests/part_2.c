/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:03:22 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 16:31:00 by prasingh         ###   ########.fr       */
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

void test_strtrim(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strtrim ===\n" C_RESET);

    const char *test_cases[][2] = {
        {"  Hello, World!  ", " "},
        {"xxxyHello, World!yyx", "xy"},
        {"NoTrimNeeded", " "},
        {"aaaa", "a"},
        {"", " "},
        {"   ", " "},
    };
    size_t n_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        const char *s1 = test_cases[i][0];
        const char *set = test_cases[i][1];

        char label[128];
        snprintf(label, sizeof(label), "ft_strtrim('%s', '%s')", s1, set);

        // Manually trim using standard functions for comparison
        const char *start = s1;
        while (*start && strchr(set, *start))
            start++;
        const char *end = s1 + strlen(s1) - 1;
        while (end > start && strchr(set, *end))
            end--;
        size_t len = (end >= start) ? (size_t)(end - start + 1) : 0;
        char *std = (char *)malloc(len + 1);
        if (std)
        {
            strncpy(std, start, len);
            std[len] = '\0';
        }
        char *mine = ft_strtrim(s1, set);

        assert_str_equal(label, std, mine);

        free(std);
        free(mine);
    }
}

void    test_split(void)
{
    printf(C_YELLOW "\n=== TEST: ft_split ===\n" C_RESET);

    const char *test_cases[][2] = {
        {"Hello, World! This is a test.", " "},
        {"one,two,three,four", ","},
        {"no_delimiters_here", ","},
        {",leading,and,trailing,commas,", ","},
        {"", ","},
        {"aaaa", "a"},
    };
    size_t n_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        const char *s = test_cases[i][0];
        char c = test_cases[i][1][0];

        char label[128];
        snprintf(label, sizeof(label), "ft_split('%s', '%c')", s, c);

        // Manually split using standard functions for comparison
        size_t expected_count = 0;
        const char *temp = s;
        while (*temp)
        {
            while (*temp == c)
                temp++;
            if (*temp)
            {
                expected_count++;
                while (*temp && *temp != c)
                    temp++;
            }
        }

        char **std = (char **)malloc((expected_count + 1) * sizeof(char *));
        size_t index = 0;
        temp = s;
        while (*temp)
        {
            while (*temp == c)
                temp++;
            if (*temp)
            {
                const char *start = temp;
                while (*temp && *temp != c)
                    temp++;
                size_t len = temp - start;
                std[index] = (char *)malloc(len + 1);
                strncpy(std[index], start, len);
                std[index][len] = '\0';
                index++;
            }
        }
        std[index] = NULL;

        char **mine = ft_split(s, c);

        // Compare results
        size_t j = 0;
        while (std[j] && mine[j])
        {
            char item_label[256];
            snprintf(item_label, sizeof(item_label), "%s [part %zu]", label, j);
            assert_str_equal(item_label, std[j], mine[j]);
            j++;
        }
        // Check for extra items
        if (std[j] || mine[j])
        {
            char item_label[256];
            snprintf(item_label, sizeof(item_label), "%s [part %zu]", label, j);
            assert_str_equal(item_label, std[j], mine[j]);
        }
        // Free allocated memory
        for (size_t k = 0; k < expected_count; k++)
            free(std[k]);
        free(std);
        for (size_t k = 0; mine[k] != NULL; k++)
            free(mine[k]);
        free(mine);
    }
}

void test_itoa(void)
{
    printf(C_YELLOW "\n=== TEST: ft_itoa ===\n" C_RESET);

    int test_values[] = {
        0,
        123,
        -123,
        2147483647,
        -2147483648,
        42,
        -42,
    };
    size_t n_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        int n = test_values[i];

        char label[128];
        snprintf(label, sizeof(label), "ft_itoa(%d)", n);

        char std[12]; // enough for int32
        snprintf(std, sizeof(std), "%d", n);
        char *mine = ft_itoa(n);

        assert_str_equal(label, std, mine);

        free(mine);
    }
}

char to_upper(unsigned int index, char c)
{
    (void)index;
    return (char)toupper((unsigned char)c);
}

void test_strmapi(void)
{
    printf(C_YELLOW "\n=== TEST: ft_strmapi ===\n" C_RESET);

    const char *test_strings[] = {
        "hello",
        "World!",
        "",
        "123abc",
    };
    size_t n_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        const char *s = test_strings[i];

        char label[128];
        snprintf(label, sizeof(label), "ft_strmapi('%s', to_upper)", s);

        // Manually map using standard functions for comparison
        size_t len = strlen(s);
        char *std = (char *)malloc(len + 1);
        for (size_t j = 0; j < len; j++)
            std[j] = to_upper(j, s[j]);
        std[len] = '\0';

        char *mine = ft_strmapi(s, to_upper);

        assert_str_equal(label, std, mine);

        free(std);
        free(mine);
    }
}

int main(void)
{
    printf(C_YELLOW "======= LIBFT TESTS (PARTIAL) =======\n" C_RESET);
    
    // test_substr();
    // test_strjoin();
    // test_strtrim();
    test_split();
    test_itoa();
    test_strmapi();
    
    

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
