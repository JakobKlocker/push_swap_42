/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:15:56 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:30:41 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_is_double(t_int_list *lst, t_int_list **stack)
{
	t_int_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		if (lst->nbr == tmp->nbr)
			error_msg(stack);
		while (tmp->next)
		{
			if (tmp->nbr == lst->nbr)
				error_msg(stack);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	print_list(t_int_list *stack_a, t_int_list *stack_b)
{
	ft_printf("stack a: \n");
	while (stack_a)
	{
		ft_printf("%i\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	ft_printf("stack b: \n");
	while (stack_b)
	{
		ft_printf("%i\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
}
