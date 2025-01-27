/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:48:21 by mwallis           #+#    #+#             */
/*   Updated: 2025/01/22 02:31:25 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	int				index;
	int				number_of_operations;
	int				quickest_to_move;
	int				upper_half;
	struct s_list	*next;
	struct s_list	*previous;
	struct s_list	*target;
}	t_list;

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_operations;

void			is_input_correct(char *argv[], int argc, t_list **a);
int				is_list_sorted(t_list *lst);
void			sort_three_elements(t_list **lst);
void			sort(t_list **a, t_list **b);

t_operations	calculate_operations(t_list *a, t_list *b, \
									t_list *target_a, t_list *target_b);
void			assign_operations_count(t_list *a, t_list *b, char list_name);
void			assign_quickest_to_move(t_list *lst);
t_list			*get_quickest_to_move(t_list *lst);
t_list			*find_smallest_number(t_list *lst);
t_list			*find_largest_number(t_list *lst);
void			assign_index_and_position(t_list *lst);
void			align_before_pushing(t_list **lst, \
									t_list *top_node, char list_name);
void			set_target_a(t_list *a, t_list *b);
void			set_target_b(t_list *a, t_list *b);

char			**ft_split(char const *s, char c);
int				ft_atoi_with_validation(const char *nptr, int *is_valid);

t_list			*ft_lstnew(int nbr);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstclear(t_list **lst);

void			sa(t_list **a);
void			sb(t_list **b);
void			ss(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rr(t_list **a, t_list **b);
void			rra(t_list **a);
void			rrb(t_list **b);
void			rrr(t_list **a, t_list **b);

#endif
