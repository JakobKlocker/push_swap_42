/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:58:05 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 11:06:03 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (size > i)
	{
		j = i + 1;
		while (size > j)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median_generic(t_int_list *stack)
{
	int	*arr;
	int	i;
	int	len;
	int	ret;

	i = 0;
	len = size_till_part(stack->next) + 1;
	arr = malloc(len * sizeof(int));
	while (stack && len > i)
	{
		arr[i] = stack->nbr;
		stack = stack->next;
		i++;
	}
	sort_array(arr, len);
	ret = arr[len / 2];
	free(arr);
	return (ret);
}
