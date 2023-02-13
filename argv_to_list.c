/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:11:50 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 12:07:49 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_int_list	*inp_to_list(char **argv)
{
	int			i;
	t_int_list	*lst;

	i = -1;
	lst = NULL;
	while (argv[++i])
	{
		if (lst == NULL)
			lst = int_lstnew(ft_atoi(argv[i]));
		else
			int_lstadd_back(&lst, int_lstnew(ft_atoi(argv[i])));
	}
	return (lst);
}
*/

t_int_list	*int_lstnew(int nbr)
{
	t_int_list	*new_node;

	new_node = malloc(sizeof(t_int_list));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->is_sorted = 0;
	new_node->partition = 0;
	return (new_node);
}

void	int_lstadd_front(t_int_list **lst, t_int_list *new)
{
	if (!new)
		return ;
	new->next = lst[0];
	new->prev = NULL;
	lst[0]->prev = new;
	lst[0] = new;
}

void	int_lstadd_back(t_int_list **lst, t_int_list *new)
{
	t_int_list	*tmp;

	if (new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = int_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

t_int_list	*int_lstlast(t_int_list *lst)
{
	if (lst == NULL)
	{
		return (lst);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
