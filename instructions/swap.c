/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:14:22 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/20 15:33:57 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL || (*lst) == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->previous = first;
	second->next = first;
	second->previous = first->previous;
	first->previous = second;
	*lst = second;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
