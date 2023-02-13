/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:11:02 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:09:05 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Checks if median or lower is in list -> till partition
int	num_in_part_higher(t_int_list *stack, int median)
{
	if (stack->nbr >= median)
		return (1);
	if (stack->partition == 1)
		stack = stack->next;
	while (stack && stack->partition == 0)
	{
		if (stack->nbr >= median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

//Splits stack A onto B -> smaller than median to b in first Partition
void	split_a(t_int_list **stack_a, t_int_list **stack_b, int median)
{
	int	c;

	c = 0;
	while (stack_a[0] && stack_a[0]->partition == 0
		&& num_in_part_lower(stack_a[0], median) == 1)
	{
		if (stack_a[0]->nbr <= median)
		{
			stack_a[0]->partition = 0;
			ft_pb(stack_a, stack_b, 1);
		}
		else
		{
			ft_ra(stack_a, 1);
			c++;
		}
	}
	stack_b[0]->partition = 1;
	while (c-- > 0)
		ft_rra(stack_a, 1);
}

//Splits stack A onto B -> smaller than median to b in first Partition
void	first_split_a(t_int_list **stack_a, t_int_list **stack_b, int median)
{
	while (stack_a[0] && stack_a[0]->partition == 0
		&& num_in_part_lower(stack_a[0], median) == 1)
	{
		if (stack_a[0]->nbr <= median)
		{
			stack_a[0]->partition = 0;
			ft_pb(stack_a, stack_b, 1);
		}
		else
		{
			ft_ra(stack_a, 1);
		}
	}
	stack_b[0]->partition = 1;
}

// //Splits stack A onto B -> smaller than median to b in first Partition
// void	split_a_sorted(t_int_list **stack_a, t_int_list **stack_b, int median)
// {
// 	int			c;

// 	c = 0;
// 	while (stack_a[0] && stack_a[0]->partition == 0
// 		&& num_in_part_lower(stack_a[0], median) == 1)
// 	{
// 		if (stack_a[0]->nbr <= median)
// 		{
// 			stack_a[0]->partition = 0;
// 			ft_pb(stack_a, stack_b, 1);
// 		}
// 		else
// 		{
// 			ft_ra(stack_a, 1);
// 			c++;
// 		}
// 	}
// 	stack_b[0]->partition = 1;
// 	while (c-- > 0)
// 		ft_rra(stack_a, 1);
// }
