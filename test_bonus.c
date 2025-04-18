/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:17:09 by jvan-der          #+#    #+#             */
/*   Updated: 2025/04/18 14:32:52 by jvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
static void    print_uppercase(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        putchar(toupper(*str));
        str++;
    }
    putchar('\n');
}

void    *duplicate_str(void *content)
{
    return strdup((char *)content);
}

void    delete_content(void *content)
{
    free(content);
}

int main(void)
{
    // Create a few sample nodes
    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("first"));
    t_list *node2 = ft_lstnew(strdup("second"));
    t_list *node3 = ft_lstnew(strdup("third"));

    // Add nodes to the list
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    // Iterate and print contents
    printf("Original list:\n");
    ft_lstiter(list, print_uppercase);

    // Map contents to a new list
    t_list *mapped = ft_lstmap(list, duplicate_str, delete_content);
    printf("\nMapped list:\n");
    ft_lstiter(mapped, print_uppercase);

    // Delete one node from original list
    printf("\nDeleting one node (second)...\n");
    ft_lstdelone(node2, delete_content);
    node1->next = node3; // skip over deleted node

    printf("Original list after deletion:\n");
    ft_lstiter(list, print_uppercase);

    // Clear both lists
    ft_lstclear(&list, delete_content);
    ft_lstclear(&mapped, delete_content);

    printf("\nBoth lists cleared.\n");
    return 0;
}
*/
