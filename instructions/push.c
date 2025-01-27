/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:37:52 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/21 20:41:14 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **departure, t_list **destination)
{
	t_list	*tmp;

	if (departure == NULL || (*departure) == NULL)
		return ;
	tmp = *departure;
	*departure = (*departure)->next;
	if (*departure != NULL)
		(*departure)->previous = NULL;
	tmp->next = *destination;
	if (*destination != NULL)
		(*destination)->previous = tmp;
	*destination = tmp;
	(*destination)->previous = NULL;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
