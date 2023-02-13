/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:51:41 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 13:41:22 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_int_list	*stack_a;
	t_int_list	*stack_b;

	if (argc == 1)
		exit(0);
	stack_b = NULL;
	stack_a = check_argv(argc, argv);
	list_is_double(stack_a, &stack_a);
	do_sorting(stack_a, stack_b);
	return (0);
}
