/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:45:36 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:08:22 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//(rotate a): Shift up all elements of stack a by 1.
void	ft_ra(t_int_list **stack_a, int f_bool)
{
	t_int_list	*last;

	if (stack_a[0] == NULL || stack_a[0]->next == NULL)
		return ;
	last = stack_a[0];
	while (last->next)
	{
		last = last->next;
	}
	last->next = stack_a[0];
	stack_a[0] = stack_a[0]->next;
	stack_a[0]->prev = NULL;
	last->next->next = NULL;
	last->next->prev = last;
	if (f_bool == 1)
	{
		ft_printf("ra\n");
	}
}

//(rotate b): Shift up all elements of stack b by 1
void	ft_rb(t_int_list **stack_b, int f_bool)
{
	t_int_list	*last;

	if (stack_b[0] == NULL || stack_b[0]->next == NULL)
		return ;
	last = stack_b[0];
	while (last->next)
	{
		last = last->next;
	}
	last->next = stack_b[0];
	stack_b[0] = stack_b[0]->next;
	stack_b[0]->prev = NULL;
	last->next->next = NULL;
	last->next->prev = last;
	if (f_bool == 1)
	{
		ft_printf("rb\n");
	}
}

//ra and rb at the same time
void	ft_rr(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	ft_printf("rr\n");
}

void	ft_rra(t_int_list **stack_a, int f_bool)
{
	t_int_list	*last;

	if (stack_a[0] == NULL || stack_a[0]->next == NULL)
		return ;
	last = stack_a[0];
	while (last->next)
	{
		last = last->next;
	}
	last->next = stack_a[0];
	last->prev->next = NULL;
	last->prev = NULL;
	stack_a[0]->prev = last;
	stack_a[0] = last;
	if (f_bool == 1)
	{
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_int_list **stack_b, int f_bool)
{
	t_int_list	*last;

	if (stack_b[0] == NULL || stack_b[0]->next == NULL)
		return ;
	last = stack_b[0];
	while (last->next)
	{
		last = last->next;
	}
	last->next = stack_b[0];
	last->prev->next = NULL;
	last->prev = NULL;
	stack_b[0]->prev = last;
	stack_b[0] = last;
	if (f_bool == 1)
	{
		ft_printf("rrb\n");
	}
}
