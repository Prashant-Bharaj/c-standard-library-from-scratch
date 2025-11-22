/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:57:34 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 18:58:25 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H


#include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define C_RED   "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"

int g_failures = 0;

void assert_int_equal(const char *label, int expected, int actual)
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

void assert_size_t_equal(const char *label, size_t expected, size_t actual)
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

void assert_str_equal(const char *label, const char *expected, const char *actual)
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

void assert_ptr_equal(const char *label, const void *expected, const void *actual)
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

#endif // TEST_H
