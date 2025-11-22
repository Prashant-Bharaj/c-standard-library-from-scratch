/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:55:38 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 19:26:01 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


void assert_list_equal(const char *label, t_list *expected, t_list *actual)
{
    t_list *exp_curr = expected;
    t_list *act_curr = actual;
    size_t index = 0;

    while (exp_curr != NULL && act_curr != NULL)
    {
        // FIX: Cast to (int *) because your test data uses integers.
        // FIX: Added '*' to the right side to compare Value vs Value.
        if (exp_curr->content != act_curr->content)
        {
            printf(C_RED "[KO]   %s at index %zu (exp=%d, got=%d)\n" C_RESET,
                   label, index, 
                   *((unsigned char *)exp_curr->content), 
                   *((unsigned char *)act_curr->content));
            g_failures++;
            return;
        }
        exp_curr = exp_curr->next;
        act_curr = act_curr->next;
        index++;
    }

    if (exp_curr == NULL && act_curr == NULL)
    {
        printf(C_GREEN "[OK]   %s\n" C_RESET, label);
    }
    else
    {
        printf(C_RED "[KO]   %s (Length mismatch at index %zu)\n" C_RESET,
               label, index);
        g_failures++;
    }
}

void test_lstnew(void)
{
    printf(C_YELLOW "\n=== TEST: ft_lstnew ===\n" C_RESET);

    int values[] = { 42, -7, 0, 1001 };
    size_t n = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < n; i++)
    {
        int val = values[i];
        char label[64];

        snprintf(label, sizeof(label), "ft_lstnew(%d)", val);
        t_list *node = ft_lstnew(&val);

        if (node != NULL && node->content == &val && node->next == NULL)
        {
            printf(C_GREEN "[OK]   %s\n" C_RESET, label);
        }
        else
        {
            printf(C_RED   "[KO]   %s\n" C_RESET, label);
            g_failures++;
        }
        free(node);
    }
}

void test_lstadd_front(void)
{
    printf(C_YELLOW "\n=== TEST: ft_lstadd_front ===\n" C_RESET);

    int vals[] = { 1, 2, 3 };
    size_t n = sizeof(vals) / sizeof(vals[0]);

    t_list *actual_list = NULL;

    // 1. Build ACTUAL list using ft_lstadd_front
    // Order of adding: 1, then 2, then 3.
    // Resulting list should be: 3 -> 2 -> 1 -> NULL
    for (size_t i = 0; i < n; i++)
    {
        t_list *new_node = ft_lstnew(&vals[i]);
        ft_lstadd_front(&actual_list, new_node);
    }

    // 2. Build EXPECTED list manually
    // We want to match 3 -> 2 -> 1
    t_list *expected = NULL;
    t_list *node1 = ft_lstnew(&vals[0]); // 1
    t_list *node2 = ft_lstnew(&vals[1]); // 2
    t_list *node3 = ft_lstnew(&vals[2]); // 3

    // Manually link them to form 3 -> 2 -> 1
    node3->next = node2;
    node2->next = node1;
    node1->next = NULL;
    
    expected = node3; // Head is 3

    // 3. Compare
    assert_list_equal("ft_lstadd_front result", expected, actual_list);

    // 4. Clean up (Free both lists)
    t_list *curr;
    while (actual_list != NULL)
    {
        curr = actual_list;
        actual_list = actual_list->next;
        free(curr);
    }
    while (expected != NULL)
    {
        curr = expected;
        expected = expected->next;
        free(curr);
    }
}

int main(void)
{
    printf(C_YELLOW "======= LIBFT TESTS (PARTIAL) =======\n" C_RESET);
    test_lstnew();
    test_lstadd_front();

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
