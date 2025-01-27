/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:59:10 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/22 00:05:06 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_smallest_number(t_list *lst)
{
	int		smallest_number;
	t_list	*list_with_smallest_number;

	smallest_number = INT_MAX;
	list_with_smallest_number = NULL;
	while (lst)
	{
		if (lst->nbr < smallest_number)
		{
			smallest_number = lst->nbr;
			list_with_smallest_number = lst;
		}
		lst = lst->next;
	}
	return (list_with_smallest_number);
}

t_list	*find_largest_number(t_list *lst)
{
	int		largest_number;
	t_list	*list_with_largest_number;

	largest_number = INT_MIN;
	list_with_largest_number = NULL;
	while (lst)
	{
		if (lst->nbr > largest_number)
		{
			largest_number = lst->nbr;
			list_with_largest_number = lst;
		}
		lst = lst->next;
	}
	return (list_with_largest_number);
}

void	assign_operations_count(t_list *a, t_list *b, char list_name)
{
	t_operations	ops;
	t_list			*lst;

	lst = NULL;
	if (list_name == 'a')
		lst = a;
	else if (list_name == 'b')
		lst = b;
	while (lst)
	{
		if (lst->target)
		{
			if (list_name == 'a')
				ops = calculate_operations(a, b, lst, lst->target);
			else if (list_name == 'b')
				ops = calculate_operations(a, b, lst->target, lst);
			lst->number_of_operations = ops.total;
		}
		lst = lst->next;
	}
}

void	assign_index_and_position(t_list *lst)
{
	int	i;
	int	middle;

	i = 0;
	middle = ft_lstsize(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (lst->index <= middle)
			lst->upper_half = 1;
		else
			lst->upper_half = 0;
		i++;
		lst = lst->next;
	}
}

void	align_before_pushing(t_list **lst, t_list *top_node, char list_name)
{
	if (!lst || !*lst || !top_node)
		return ;
	while (*lst != top_node)
	{
		if (list_name == 'a')
		{
			if (top_node->upper_half)
				ra(lst);
			else
				rra(lst);
		}
		else if (list_name == 'b')
		{
			if (top_node->upper_half)
				rb(lst);
			else
				rrb(lst);
		}
	}
}
