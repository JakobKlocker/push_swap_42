/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:55:24 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:08:53 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
}

int	stack_size_sorted(t_int_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->is_sorted == 0)
			i++;
	}
	return (i);
}
