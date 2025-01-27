/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:44:28 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/20 16:43:14 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_list **lst)
{
	if (((*lst)->nbr > (*lst)->next->nbr)
		&& ((*lst)->nbr > (*lst)->next->next->nbr))
		ra(lst);
	if (((*lst)->nbr < (*lst)->next->nbr)
		&& ((*lst)->next->nbr > (*lst)->next->next->nbr))
		rra(lst);
	if ((*lst)->nbr > (*lst)->next->nbr)
		sa(lst);
}

int	is_list_sorted(t_list *lst)
{
	if (lst == NULL)
		return (1);
	while (lst->next != NULL)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	push_swap(t_list **a, t_list **b)
{
	if (is_list_sorted(*a) == 0)
	{
		if (ft_lstsize(*a) == 2)
			sa(a);
		else if (ft_lstsize(*a) == 3)
			sort_three_elements(a);
		else
			sort(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (write(2, "Error\n", 6), 1);
	}
	is_input_correct(argv, argc, &a);
	push_swap(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
