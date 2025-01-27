/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:30:35 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/20 15:34:00 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (lst == NULL || (*lst) == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = first->next;
	second->previous = NULL;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	*lst = second;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
