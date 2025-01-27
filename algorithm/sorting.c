/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:47:19 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/21 22:29:55 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	transfer_a_to_b(t_list **a, t_list **b)
{
	t_list			*cheapest;
	t_operations	ops;

	cheapest = get_quickest_to_move(*a);
	if (!cheapest)
		return ;
	if (!cheapest->target)
		return (align_before_pushing(a, cheapest, 'a'), pb(a, b));
	ops = calculate_operations(*a, *b, cheapest, cheapest->target);
	while (ops.rr-- > 0)
		rr(a, b);
	while (ops.rrr-- > 0)
		rrr(a, b);
	while (ops.ra-- > 0)
		ra(a);
	while (ops.rb-- > 0)
		rb(b);
	while (ops.rra-- > 0)
		rra(a);
	while (ops.rrb-- > 0)
		rrb(b);
	pb(a, b);
}

static void	transfer_b_to_a(t_list **b, t_list **a)
{
	t_list			*cheapest;
	t_operations	ops;

	cheapest = get_quickest_to_move(*b);
	if (!cheapest)
		return ;
	if (!cheapest->target)
		return (align_before_pushing(b, cheapest, 'b'), pa(a, b));
	ops = calculate_operations(*a, *b, cheapest->target, cheapest);
	while (ops.rr-- > 0)
		rr(a, b);
	while (ops.rrr-- > 0)
		rrr(a, b);
	while (ops.ra-- > 0)
		ra(a);
	while (ops.rb-- > 0)
		rb(b);
	while (ops.rra-- > 0)
		rra(a);
	while (ops.rrb-- > 0)
		rrb(b);
	pa(a, b);
}

static void	bring_min_to_top(t_list **a)
{
	t_list	*list_with_smallest_number;

	list_with_smallest_number = find_smallest_number(*a);
	if (list_with_smallest_number == NULL)
		return ;
	assign_index_and_position(*a);
	while (*a != list_with_smallest_number)
	{
		if (list_with_smallest_number->upper_half)
			ra(a);
		else
			rra(a);
	}
}

static void	initialize_list(t_list *a, t_list *b, char list_name)
{
	assign_index_and_position(a);
	assign_index_and_position(b);
	if (list_name == 'a')
	{
		set_target_a(a, b);
		assign_operations_count(a, b, 'a');
		assign_quickest_to_move(a);
	}
	else if (list_name == 'b')
	{
		set_target_b(a, b);
		assign_operations_count(a, b, 'b');
		assign_quickest_to_move(b);
	}
}

void	sort(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	while (len_a > 3 && is_list_sorted(*a) == 0)
	{
		initialize_list(*a, *b, 'a');
		transfer_a_to_b(a, b);
		len_a--;
	}
	sort_three_elements(a);
	while (*b)
	{
		initialize_list(*a, *b, 'b');
		transfer_b_to_a(b, a);
	}
	bring_min_to_top(a);
}
