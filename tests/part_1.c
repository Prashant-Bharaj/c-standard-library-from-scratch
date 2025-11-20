#include <stdio.h>
#include <string.h>
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
        int std = isalpha((unsigned char)c);
        int mine = ft_isalpha((unsigned char)c);

        assert_int_equal(label, std != 0, mine != 0);
    }
}


int main(void)
{
    printf(C_YELLOW "======= LIBFT TESTS (PARTIAL) =======\n" C_RESET);

    test_isalpha();

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
