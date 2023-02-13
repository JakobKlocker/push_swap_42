/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:23:19 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 12:07:35 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Stack A ist komplett sorted and Stack B reverse Sorted
int	stacks_sorted(t_int_list *stack_a, t_int_list *stack_b)
{
	if (stack_a)
	{
		while (stack_a->next)
		{
			if (stack_a->nbr > stack_a->next->nbr)
				return (0);
			stack_a = stack_a->next;
		}
	}
	if (stack_b)
	{
		while (stack_b->next)
		{
			if (stack_b->nbr < stack_b->next->nbr)
				return (0);
			stack_b = stack_b->next;
		}
	}
	return (1);
}

int	size_till_part(t_int_list *stack_a)
{
	int	c;

	c = 0;
	if (!stack_a)
		return (0);
	while (stack_a && stack_a->partition == 0)
	{
		c++;
		stack_a = stack_a->next;
	}
	return (c);
}

void	free_all(t_int_list **stack_a, t_int_list **stack_b)
{
	t_int_list	*tmp;

	if (!stack_a)
		return ;
	while (stack_a[0])
	{
		tmp = stack_a[0]->next;
		free(stack_a[0]);
		stack_a[0] = tmp;
	}
	if (!stack_b)
		return ;
	while (stack_b[0])
	{
		tmp = stack_b[0]->next;
		free(stack_b[0]);
		stack_b[0] = tmp;
	}
}
