/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:21:42 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/21 22:29:51 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*find_closest_smaller(t_list *b, int a_nbr)
{
	int		closest_number_below;
	t_list	*lst_target;

	closest_number_below = INT_MIN;
	lst_target = NULL;
	while (b)
	{
		if (b->nbr < a_nbr && b->nbr > closest_number_below)
		{
			closest_number_below = b->nbr;
			lst_target = b;
		}
		b = b->next;
	}
	return (lst_target);
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*lst_target;

	if (b == NULL || ft_lstsize(b) == 0)
		return ;
	while (a)
	{
		lst_target = find_closest_smaller(b, a->nbr);
		if (lst_target == NULL)
			a->target = find_largest_number(b);
		else
			a->target = lst_target;
		a = a->next;
	}
}

static t_list	*find_closest_larger(t_list *a, int b_nbr)
{
	int		closest_number_higher;
	t_list	*lst_target;

	closest_number_higher = INT_MAX;
	lst_target = NULL;
	while (a)
	{
		if (a->nbr > b_nbr && a->nbr < closest_number_higher)
		{
			closest_number_higher = a->nbr;
			lst_target = a;
		}
		a = a->next;
	}
	return (lst_target);
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list	*lst_target;

	if (a == NULL || ft_lstsize(a) == 0)
		return ;
	while (b)
	{
		lst_target = find_closest_larger(a, b->nbr);
		if (lst_target == NULL)
			b->target = find_smallest_number(a);
		else
			b->target = lst_target;
		b = b->next;
	}
}
