/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:34:55 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/29 12:25:25 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/ft_printf.h"
# include "libft/libft.h"

typedef struct s_infos
{
	int					max_nbr;
	int					min_nbr;
	int					size;
}						t_infos;

typedef struct s_int_list
{
	int					nbr;
	int					is_sorted;
	int					partition;
	struct s_int_list	*next;
	struct s_int_list	*prev;
}						t_int_list;

//Argv_checks
int						modified_atoi(char *str);
void					range_check(char *str, t_int_list **stack,
							char **split);
void					is_int(char *str, t_int_list **stack, char **split);
t_int_list				*check_argv(int argc, char **argv);
void					error_msg(t_int_list **stack);

//Argv to List
t_int_list				*inp_to_list(char **argv);
t_int_list				*int_lstnew(int nbr);
void					int_lstadd_front(t_int_list **lst, t_int_list *new);
void					int_lstadd_back(t_int_list **lst, t_int_list *new);
t_int_list				*int_lstlast(t_int_list *lst);

//List checks
void					list_is_double(t_int_list *lst, t_int_list **stack);
void					print_list(t_int_list *stack_a, t_int_list *stack_b);

//Sort Functions
void					ft_sa(t_int_list **stack_a, int f_bool);
void					ft_sb(t_int_list **stack_b, int f_bool);
void					ft_ss(t_int_list **stack_a, t_int_list **stack_b);
void					ft_pa(t_int_list **stack_a, t_int_list **stack_b,
							int f_bool);
void					ft_pb(t_int_list **stack_a, t_int_list **stack_b,
							int f_bool);
//Sort Functions 1
void					ft_ra(t_int_list **stack_a, int f_bool);
void					ft_rb(t_int_list **stack_b, int f_bool);
void					ft_rr(t_int_list **stack_a, t_int_list **stack_b);
void					ft_rra(t_int_list **stack_a, int f_bool);
void					ft_rrb(t_int_list **stack_b, int f_bool);
//Sort Functions 2
void					ft_rrr(t_int_list **stack_a, t_int_list **stack_b);

//Sort Logic
void					do_sorting(t_int_list *stack_a, t_int_list *stack_b);

void					sort_3(t_int_list **stack_a, t_int_list **stack_b);
void					sort_5(t_int_list *stack_a, t_int_list *stack_b,
							t_infos *infos);
//Sort Logic unused
t_int_list				*selection_sort(t_int_list *stack_a,
							t_int_list *stack_b);
void					bubble_sort(t_int_list **stack_a, t_int_list **stack_b);

//Sort Helpers
int						smallest_nbr_in_stck(t_int_list *stack);
int						biggest_nbr_in_stck(t_int_list *stack);
int						smallest_pos_in_stck(t_int_list *stack);
int						biggest_pos_in_stck(t_int_list *stack);
int						stack_size(t_int_list *stack);
int						is_sorted(t_int_list *stack_a, t_int_list *stack_b);
int						is_sorted_reverse(t_int_list *stack_a,
							t_int_list *stack_b);

//Sort Helpers 100
int						get_median(t_int_list **sorted_list1, int ign);
void					push_to_b(t_int_list **stack_a, t_int_list **stack_b,
							int median);
void					push_to_b_sorted(t_int_list **stack_a,
							t_int_list **stack_b, int median);
void					push_to_a(t_int_list **stack_a, t_int_list **stack_b,
							int median);
void					push_to_a_sorted(t_int_list **stack_a,
							t_int_list **stack_b, int median);
void					sorted_index(t_int_list **stack);
int						is_sorted_both(t_int_list *stack_a,
							t_int_list *stack_b);
int						stack_size_sorted(t_int_list *stack);

//Sort Helpers 100_1
void					remove_is_sorted(t_int_list **lst);

//New
void					quick_sort(t_int_list *stack_a, t_int_list *stack_b);
int						stacks_sorted(t_int_list *stack_a, t_int_list *stack_b);
void					split_a(t_int_list **stack_a, t_int_list **stack_b,
							int median);
int						num_in_part_higher(t_int_list *stack, int median);
int						num_in_part_lower(t_int_list *stack, int median);

//sort_stack_b
void					split_b(t_int_list **stack_a, t_int_list **stack_b,
							int median);
void					split_b_sorted(t_int_list **stack_a,
							t_int_list **stack_b, int median);
int						get_median_b(t_int_list *sorted_a,
							t_int_list *sorted_b);
int						num_in_part_lower(t_int_list *stack, int median);
int						get_median_generic(t_int_list *stack);
int						size_till_part(t_int_list *stack_a);

void					first_split_a(t_int_list **stack_a,
							t_int_list **stack_b, int median);
void					free_all(t_int_list **stack_a, t_int_list **stack_b);
void					free_split(char **split);

#endif