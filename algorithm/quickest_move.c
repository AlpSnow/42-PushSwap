/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:05:23 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/21 22:30:02 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reset_quickest_move(t_list *lst)
{
	while (lst)
	{
		lst->quickest_to_move = 0;
		lst = lst->next;
	}
}

void	assign_quickest_to_move(t_list *lst)
{
	int		lowest_number_of_operations;
	t_list	*tmp;

	lowest_number_of_operations = INT_MAX;
	tmp = NULL;
	reset_quickest_move(lst);
	while (lst)
	{
		if (lst->number_of_operations < lowest_number_of_operations)
		{
			lowest_number_of_operations = lst->number_of_operations;
			tmp = lst;
		}
		lst = lst->next;
	}
	if (tmp)
		tmp->quickest_to_move = 1;
}

t_list	*get_quickest_to_move(t_list *lst)
{
	while (lst)
	{
		if (lst->quickest_to_move == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
