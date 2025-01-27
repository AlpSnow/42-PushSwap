/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:02:38 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/22 02:26:22 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calculate_rotations_a(t_operations *ops, \
								t_list *a, t_list *target_a)
{
	int	list_size_a;

	list_size_a = ft_lstsize(a);
	if (target_a->upper_half)
	{
		ops->ra = target_a->index;
	}
	else
	{
		ops->rra = list_size_a - target_a->index;
	}
}

static void	calculate_rotations_b(t_operations *ops, \
								t_list *b, t_list *target_b)
{
	int	list_size_b;

	list_size_b = ft_lstsize(b);
	if (target_b->upper_half)
	{
		ops->rb = target_b->index;
	}
	else
	{
		ops->rrb = list_size_b - target_b->index;
	}
}

static void	calculate_rr(t_operations *ops)
{
	if (ops->ra > 0 && ops->rb > 0)
	{
		if (ops->ra > ops->rb)
		{
			ops->rr = ops->rb;
			ops->ra -= ops->rb;
			ops->rb = 0;
		}
		else
		{
			ops->rr = ops->ra;
			ops->rb -= ops->ra;
			ops->ra = 0;
		}
	}
}

static void	calculate_rrr(t_operations *ops)
{
	if (ops->rra > 0 && ops->rrb > 0)
	{
		if (ops->rra > ops->rrb)
		{
			ops->rrr = ops->rrb;
			ops->rra -= ops->rrb;
			ops->rrb = 0;
		}
		else
		{
			ops->rrr = ops->rra;
			ops->rrb -= ops->rra;
			ops->rra = 0;
		}
	}
}

t_operations	calculate_operations(t_list *a, t_list *b, \
									t_list *target_a, t_list *target_b)
{
	t_operations	ops;

	ops.ra = 0;
	ops.rb = 0;
	ops.rra = 0;
	ops.rrb = 0;
	ops.rr = 0;
	ops.rrr = 0;
	calculate_rotations_a(&ops, a, target_a);
	calculate_rotations_b(&ops, b, target_b);
	calculate_rr(&ops);
	calculate_rrr(&ops);
	ops.total = ops.ra + ops.rb + ops.rra + ops.rrb + ops.rr + ops.rrr;
	return (ops);
}
