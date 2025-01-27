/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:34:45 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/15 21:14:21 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static int	check_duplicates(t_list *a)
{
	t_list	*current;
	t_list	*watch_rest;

	current = a;
	while (current != NULL)
	{
		watch_rest = current->next;
		while (watch_rest != NULL)
		{
			if (current->nbr == watch_rest->nbr)
			{
				return (0);
			}
			watch_rest = watch_rest->next;
		}
		current = current->next;
	}
	return (1);
}

static int	check_input(char *argv[], int argc, t_list **a)
{
	int		i;
	int		is_valid;
	int		value;
	t_list	*tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			return (0);
		if ((argv[i][0] == '+' || argv[i][0] == '-') && argv[i][1] == '\0')
			return (0);
		value = ft_atoi_with_validation(argv[i++], &is_valid);
		if (is_valid == 0)
			return (0);
		tmp = ft_lstnew(value);
		if (tmp == NULL)
			return (0);
		ft_lstadd_back(a, tmp);
	}
	if (check_duplicates(*a) == 0)
		return (0);
	return (1);
}

void	is_input_correct(char *argv[], int argc, t_list **a)
{
	if (argc == 2 && (argv[0] == NULL || argv[0][0] == '\0'))
	{
		free_argv(argv);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (check_input(argv, argc, a) == 0)
	{
		ft_lstclear(a);
		if (argc == 2)
		{
			free_argv(argv);
		}
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		free_argv(argv);
	}
}
