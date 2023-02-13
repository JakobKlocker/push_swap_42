/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:01:23 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:51:47 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sorting(t_int_list *stack_a, t_int_list *stack_b)
{
	t_infos	infos;

	infos.min_nbr = smallest_nbr_in_stck(stack_a);
	infos.max_nbr = biggest_nbr_in_stck(stack_a);
	infos.size = stack_size(stack_a);
	if (is_sorted(stack_a, stack_b) == 1)
	{
		free_all(&stack_a, &stack_b);
		return ;
	}
	if (infos.size <= 3)
	{
		sort_3(&stack_a, &stack_b);
		free_all(&stack_a, &stack_b);
	}
	else if (infos.size == 5)
		sort_5(stack_a, stack_b, &infos);
	else
		quick_sort(stack_a, stack_b);
}

void	sort_3(t_int_list **stack_a, t_int_list **stack_b)
{
	if (is_sorted(stack_a[0], NULL) == 1)
		return ;
	(void)stack_b;
	if (stack_a[0]->nbr > stack_a[0]->next->nbr
		&& stack_a[0]->nbr < stack_a[0]->next->next->nbr)
		ft_sa(stack_a, 1);
	else if (stack_a[0]->nbr > stack_a[0]->next->nbr)
		ft_ra(stack_a, 1);
	else
		ft_rra(stack_a, 1);
	if (stack_a[0]->nbr > stack_a[0]->next->nbr)
		ft_sa(stack_a, 1);
}

//Michael logic
void	sort_5(t_int_list *stack_a, t_int_list *stack_b, t_infos *infos)
{
	while (stack_size(stack_a) != 3)
	{
		if (infos->max_nbr == stack_a->nbr || infos->min_nbr == stack_a->nbr)
			ft_pb(&stack_a, &stack_b, 1);
		else
			ft_ra(&stack_a, 1);
	}
	sort_3(&stack_a, &stack_b);
	if (stack_b->next && stack_b->nbr > stack_b->next->nbr)
		ft_sb(&stack_b, 1);
	if (smallest_nbr_in_stck(stack_a) < stack_b->nbr)
	{
		ft_pa(&stack_a, &stack_b, 1);
		ft_ra(&stack_a, 1);
		ft_pa(&stack_a, &stack_b, 1);
	}
	else
	{
		ft_pa(&stack_a, &stack_b, 1);
		ft_pa(&stack_a, &stack_b, 1);
		ft_ra(&stack_a, 1);
	}
	free_all(&stack_a, &stack_b);
}

int	is_sorted(t_int_list *stack_a, t_int_list *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
