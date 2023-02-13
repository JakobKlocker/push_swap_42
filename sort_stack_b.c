/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:13:10 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:09:10 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Checks if median or lower is in list -> till partition
int	num_in_part_lower(t_int_list *stack, int median)
{
	if (stack->nbr <= median)
		return (1);
	if (stack->partition == 1)
		stack = stack->next;
	while (stack && stack->partition == 0)
	{
		if (stack->nbr < median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

//Splits stack A onto B -> smaller than median to b in first Partition
void	split_b(t_int_list **stack_a, t_int_list **stack_b, int median)
{
	int	c;

	c = 0;
	while (stack_b[0] && num_in_part_higher(stack_b[0], median) == 1)
	{
		if (stack_b[0]->nbr >= median)
		{
			stack_b[0]->partition = 0;
			ft_pa(stack_a, stack_b, 1);
		}
		else
		{
			ft_rb(stack_b, 1);
			c++;
		}
		if (stack_b[0] && stack_b[0]->partition == 1)
			break ;
	}
	while (c-- > 0)
		ft_rrb(stack_b, 1);
}

// //Splits stack A onto B -> smaller than median to b in first Partition
// void	split_b_sorted(t_int_list **stack_a, t_int_list **stack_b, int median)
// {
// 	int			c;

// 	(void)stack_a;
// 	c = 0;
// 	while (stack_b[0] && num_in_part_higher(stack_b[0], median) == 1)
// 	{
// 		if (stack_b[0]->nbr >= median)
// 		{
// 			stack_b[0]->partition = 0;
// 			ft_pa(stack_a, stack_b, 0);
// 		}
// 		else
// 		{
// 			ft_rb(stack_b, 0);
// 			c++;
// 		}
// 		if (stack_b[0]->partition == 1)
// 			break ;
// 	}
// 	while (c-- > 0)
// 		ft_rrb(stack_b, 0);
// }
