/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:02 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 12:02:55 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Print the List

//Swap the first 2 elements at the top of stack a
void	ft_sa(t_int_list **stack_a, int f_bool)
{
	t_int_list	*tmp;

	tmp = stack_a[0]->next;
	stack_a[0]->next = tmp->next;
	stack_a[0]->prev = tmp;
	tmp->next = stack_a[0];
	tmp->prev = NULL;
	if (stack_a[0]->next)
		stack_a[0]->next->prev = stack_a[0];
	stack_a[0] = tmp;
	if (f_bool == 1)
	{
		ft_printf("sa\n");
	}
}

//Swap the first 2 elements at the top of stack b
void	ft_sb(t_int_list **stack_a, int f_bool)
{
	t_int_list	*tmp;

	tmp = stack_a[0]->next;
	stack_a[0]->next = tmp->next;
	stack_a[0]->prev = tmp;
	tmp->next = stack_a[0];
	tmp->prev = NULL;
	if (stack_a[0]->next)
		stack_a[0]->next->prev = stack_a[0];
	stack_a[0] = tmp;
	if (f_bool == 1)
	{
		ft_printf("sb\n");
	}
}

//Swap the first 2 elements at the top of stack a and stack b
void	ft_ss(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
}

void	ft_pa(t_int_list **stack_a, t_int_list **stack_b, int f_bool)
{
	t_int_list	*tmp;

	tmp = *stack_b;
	if (stack_b[0])
		stack_b[0] = stack_b[0]->next;
	if (stack_b[0])
		stack_b[0]->prev = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = tmp;
		stack_a[0]->next = NULL;
		stack_a[0]->prev = NULL;
	}
	else
		int_lstadd_front(stack_a, tmp);
	if (f_bool == 1)
	{
		ft_printf("pa\n");
	}
}

void	ft_pb(t_int_list **stack_a, t_int_list **stack_b, int f_bool)
{
	t_int_list	*tmp;

	tmp = *stack_a;
	if (stack_a[0])
		stack_a[0] = stack_a[0]->next;
	if (stack_a[0])
		stack_a[0]->prev = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = tmp;
		stack_b[0]->next = NULL;
		stack_b[0]->prev = NULL;
	}
	else
		int_lstadd_front(stack_b, tmp);
	if (f_bool == 1)
	{
		ft_printf("pb\n");
	}
}
