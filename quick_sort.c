/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:06:52 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 12:05:52 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_3_helper_1(t_int_list **stack_a)
{
	ft_sa(stack_a, 1);
	ft_ra(stack_a, 1);
	ft_sa(stack_a, 1);
	ft_rra(stack_a, 1);
	ft_sa(stack_a, 1);
}

// void	quick_sort_3_helper_2(t_int_list **stack_a)
// {
// 	ft_sa(stack_a, 1);
// 	ft_ra(stack_a, 1);
// 	ft_sa(stack_a, 1);
// 	ft_rra(stack_a, 1);
// 	ft_sa(stack_a, 1);
// }

void	quick_sort_3_helper(t_int_list **stack_a,
							int first,
							int second,
							int third)
{
	if (first > second && first < third)
		ft_sa(stack_a, 1);
	else if (first > second && first > third && third > second)
	{
		ft_sa(stack_a, 1);
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (first < second && second > third && first < third)
	{
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (first > second && first > third && third < second)
		quick_sort_3_helper_1(stack_a);
	else if (first < second && third < first && first > third)
	{
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
}

void	quick_sort_3(t_int_list **stack_a, t_int_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	(void)stack_b;
	if ((stack_a[0]->next && stack_a[0]->next->next == NULL)
		|| (stack_a[0]->next && stack_a[0]->next->next->partition == 1))
	{
		if (stack_a[0]->next && stack_a[0]->nbr > stack_a[0]->next->nbr)
		{
			ft_sa(stack_a, 1);
			return ;
		}
		else
			return ;
	}
	if (stack_a[0]->next == NULL)
		return ;
	first = stack_a[0]->nbr;
	second = stack_a[0]->next->nbr;
	third = stack_a[0]->next->next->nbr;
	quick_sort_3_helper(stack_a, first, second, third);
}

//Main Sort Function
void	quick_sort(t_int_list *stack_a, t_int_list *stack_b)
{
	int	median;

	while (size_till_part(stack_a) > 2 && stacks_sorted(stack_a, NULL) == 0)
	{
		median = get_median_generic(stack_a);
		first_split_a(&stack_a, &stack_b, median);
	}
	while (stacks_sorted(stack_a, stack_b) == 0)
	{
		while (size_till_part(stack_a) > 2 && stacks_sorted(stack_a, NULL) == 0)
		{
			median = get_median_generic(stack_a);
			split_a(&stack_a, &stack_b, median);
		}
		quick_sort_3(&stack_a, &stack_b);
		stack_a->partition = 1;
		median = get_median_generic(stack_b);
		split_b(&stack_a, &stack_b, median);
	}
	while (stack_b)
		ft_pa(&stack_a, &stack_b, 1);
	free_all(&stack_a, &stack_b);
}
