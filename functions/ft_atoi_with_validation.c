/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_with_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:37:49 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/13 19:25:35 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_with_validation(const char *nptr, int *is_valid)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	*is_valid = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = sign * -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i++] - 48);
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-1 * result) < INT_MIN))
			return (*is_valid = 0, 0);
	}
	if (nptr[i] != '\0')
		*is_valid = 0;
	return (sign * result);
}
