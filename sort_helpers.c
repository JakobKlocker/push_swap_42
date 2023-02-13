/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:42:40 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:08:44 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_nbr_in_stck(t_int_list *stack)
{
	int	i;
	int	pos;
	int	nbr;

	i = 1;
	pos = 1;
	if (!stack)
		return (-1);
	nbr = stack->nbr;
	while (stack->next && stack->next->is_sorted == 0)
	{
		if (nbr > stack->next->nbr)
		{
			pos = i + 1;
			nbr = stack->next->nbr;
		}
		stack = stack->next;
		i++;
	}
	return (nbr);
}

int	biggest_nbr_in_stck(t_int_list *stack)
{
	int	i;
	int	pos;
	int	nbr;

	i = 1;
	pos = 1;
	if (!stack)
		return (-1);
	nbr = stack->nbr;
	while (stack->next && stack->next->is_sorted == 0)
	{
		if (nbr < stack->next->nbr)
		{
			pos = i + 1;
			nbr = stack->next->nbr;
		}
		stack = stack->next;
		i++;
	}
	return (nbr);
}

int	smallest_pos_in_stck(t_int_list *stack)
{
	int	i;
	int	pos;
	int	nbr;

	i = 1;
	pos = 1;
	if (!stack)
		return (-1);
	nbr = stack->nbr;
	while (stack->next)
	{
		if (nbr > stack->next->nbr)
		{
			pos = i + 1;
			nbr = stack->next->nbr;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	biggest_pos_in_stck(t_int_list *stack)
{
	int	i;
	int	pos;
	int	nbr;

	i = 1;
	pos = 1;
	if (!stack)
		return (-1);
	nbr = stack->nbr;
	while (stack->next && stack->next->is_sorted == 0)
	{
		if (nbr < stack->next->nbr)
		{
			pos = i + 1;
			nbr = stack->next->nbr;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	stack_size(t_int_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
