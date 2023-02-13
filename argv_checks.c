/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:04:04 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 12:21:30 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modified_atoi(char *str)
{
	int	i;
	int	minus_counter;
	int	ret;

	i = 0;
	minus_counter = 0;
	ret = 0;
	if (str[i] == '-')
	{
		minus_counter++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	if (minus_counter != 0)
		return (ret * -1);
	return (ret);
}

void	range_check(char *str, t_int_list **stack, char **split)
{
	char	*cmp;

	cmp = ft_itoa(ft_atoi(str));
	if (ft_strncmp(cmp, str, ft_strlen(str) != 0))
	{
		free(cmp);
		free_split(split);
		error_msg(stack);
	}
	free(cmp);
}

// void	range_check(char *str, t_int_list **stack, char **split)
// {
// 	int	is_sign;

// 	is_sign = 0;
// 	if (str[0] == '-' || str[0] == '+')
// 		is_sign = 1;
// 	if (ft_strlen(str) > 10 + is_sign)
// 	{
// 		free_split(split);
// 		error_msg(stack);
// 	}
// 	if (str[0] == '-' && ft_strncmp(str, "-2147483647", 11) > 0)
// 	{
// 		free_split(split);
// 		error_msg(stack);
// 	}
// 	else if (str[0] == '+' && ft_strncmp(str, "+2147483648", 11) > 0)
// 	{
// 		error_msg(stack);
// 		free_split(split);
// 	}
// 	else if (str[0] >= '0' && str[0] <= '9' && ft_strncmp(str, "2147483648",
// 			10) > 0)
// 	{
// 		free_split(split);
// 		error_msg(stack);
// 	}
// }

void	is_int(char *str, t_int_list **stack, char **split)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i + 1] == '\0')
	{
		free_split(split);
		error_msg(stack);
	}
	while (str[++i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			free_split(split);
			error_msg(stack);
		}
	}
}

t_int_list	*check_argv(int argc, char **argv)
{
	char		**split;
	int			i;
	int			j;
	t_int_list	*ret;

	ret = NULL;
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j])
		{
			is_int(split[j], &ret, split);
			range_check(split[j], &ret, split);
			if (ret == NULL)
				ret = int_lstnew(ft_atoi(split[j]));
			else
				int_lstadd_back(&ret, int_lstnew(ft_atoi(split[j])));
		}
		free_split(split);
	}
	return (ret);
}

void	error_msg(t_int_list **stack)
{
	free_all(stack, NULL);
	write(2, "Error\n", 6);
	exit(0);
}
