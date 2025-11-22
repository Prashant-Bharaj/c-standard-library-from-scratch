/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:03:22 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 18:59:14 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

void to_upper_striteri(unsigned int index, char *c)
{
    (void)index;
    *c = (char)toupper((unsigned char)*c);
}

void    test_striteri(void)
{
    printf(C_YELLOW "\n=== TEST: ft_striteri ===\n" C_RESET);

    const char *test_strings[] = {
        "hello",
        "World!",
        "",
        "123abc",
    };
    size_t n_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        char *s = strdup(test_strings[i]);

        char label[128];
        snprintf(label, sizeof(label), "ft_striteri('%s', to_upper)", s);

        // Manually iterate using standard functions for comparison
        size_t len = strlen(s);
        char *std = strdup(s);
        for (size_t j = 0; j < len; j++)
            std[j] = to_upper(j, std[j]);

        ft_striteri(s, to_upper_striteri);
        assert_str_equal(label, std, s);

        free(std);
        free(s);
    }
}

void    test_putchar_fd(void)
{
    printf(C_YELLOW "\n=== TEST: ft_putchar_fd ===\n" C_RESET);

    // Since ft_putchar_fd writes to a file descriptor,
    // we will test it by writing to a temporary file
    const char *filename = "temp_test_putchar_fd.txt";
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for testing ft_putchar_fd\n" C_RESET);
        g_failures++;
        return;
    }
    int fd = fileno(file);

    const char *test_string = "Hello, World!";
    for (size_t i = 0; test_string[i] != '\0'; i++)
    {
        ft_putchar_fd(test_string[i], fd);
    }
    fclose(file);

    // Now read back the file and compare
    file = fopen(filename, "r");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for reading in ft_putchar_fd test\n" C_RESET);
        g_failures++;
        return;
    }
    char buffer[50];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    assert_str_equal("ft_putchar_fd output", test_string, buffer);

    // Clean up
    remove(filename);
}

void    test_putstr_fd(void)
{
    printf(C_YELLOW "\n=== TEST: ft_putstr_fd ===\n" C_RESET);

    // Since ft_putstr_fd writes to a file descriptor,
    // we will test it by writing to a temporary file
    const char *filename = "temp_test_putstr_fd.txt";
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for testing ft_putstr_fd\n" C_RESET);
        g_failures++;
        return;
    }
    int fd = fileno(file);

    const char *test_string = "Hello, World! This is a test of ft_putstr_fd.";
    ft_putstr_fd(test_string, fd);
    fclose(file);

    // Now read back the file and compare
    file = fopen(filename, "r");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for reading in ft_putstr_fd test\n" C_RESET);
        g_failures++;
        return;
    }
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    assert_str_equal("ft_putstr_fd output", test_string, buffer);

    // Clean up
    remove(filename);
}

void test_putendl_fd(void)
{
    printf(C_YELLOW "\n=== TEST: ft_putendl_fd ===\n" C_RESET);

    const char *filename = "temp_test_putendl_fd.txt";
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for write\n" C_RESET);
        g_failures++;
        return;
    }
    int fd = fileno(file);

    const char *test_string = "Hello World\nThis world is crazy!\n don't know what to expect\n";
    ft_putendl_fd((char *)test_string, fd);
    fclose(file);

    file = fopen(filename, "r");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for read\n" C_RESET);
        g_failures++;
        return;
    }

    char buffer[1024];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[bytes_read] = '\0';
    fclose(file);
    char expected[1024];
    snprintf(expected, sizeof(expected), "%s\n", test_string);

    assert_str_equal("ft_putendl_fd check", expected, buffer);

    remove(filename);
}

void    test_putnbr_fd(void)
{
    printf(C_YELLOW "\n=== TEST: ft_putnbr_fd ===\n" C_RESET);
    
    const char *filename = "temp_test_putnbr_fd.txt";
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for testing ft_putnbr_fd\n" C_RESET);
        g_failures++;
        return;
    }
    int fd = fileno(file);

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

        ft_putnbr_fd(n, fd);
        ft_putchar_fd('\n', fd);
    }
    fclose(file);

    // Now read back the file and compare
    file = fopen(filename, "r");
    if (!file)
    {
        printf(C_RED "[KO]   Could not open file for reading in ft_putnbr_fd test\n" C_RESET);
        g_failures++;
        return;
    }
    char buffer[256];
    size_t index = 0;
    for (size_t i = 0; i < n_tests; i++)
    {
        int n = test_values[i];
        char expected[13];
        snprintf(expected, sizeof(expected), "%d\n", n);

        fgets(buffer, sizeof(buffer), file);
        assert_str_equal("ft_putnbr_fd output", expected, buffer);
    }
    fclose(file);
    remove(filename);
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
    test_striteri();
    test_putchar_fd();
    test_putstr_fd();
    test_putendl_fd();
    test_putnbr_fd();
    

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
