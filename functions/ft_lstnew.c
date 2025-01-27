/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:36:25 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/13 21:41:42 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		return (NULL);
	new_element->nbr = nbr;
	new_element->index = 0;
	new_element->number_of_operations = 0;
	new_element->quickest_to_move = 0;
	new_element->upper_half = 0;
	new_element->next = NULL;
	new_element->previous = NULL;
	new_element->target = NULL;
	return (new_element);
}
