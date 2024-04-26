/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:29:06 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/11/03 17:15:52 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libftplus/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;	
	int				index;
	int				position;
	int				cost_a;
	int				cost_b;
	int				target;

}					t_stack;

//calculate_cost
t_stack	*find_max(t_stack *a);
t_stack	*find_min(t_stack *stack);
int		no_neg(int number);
void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);

//good_input
int		only_numbers(int argc, char **argv);
int		no_duplicates(int argc, char **argv);
int		is_it_an_int(int argc, char **argv);
int		correct_input(int argc, char **argv);

//index_target_and_position
void	put_index(t_stack *stack);
void	get_position(t_stack **stack);
int		get_lowest_index_position(t_stack **stack);
int		get_target(t_stack **a, int b_index, int target_index, int target_pos);
void	get_target_position(t_stack **a, t_stack **b);

//main
bool	stack_is_sorted(t_stack *a);

//moving
void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	do_rotate_a(t_stack **a, int *cost);
void	do_rotate_b(t_stack **b, int *cost);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

//p_functions
void	push_function(t_stack **a, t_stack **b);
void	pb_function(t_stack **a, t_stack **b);
void	pa_function(t_stack **a, t_stack **b);

//push_swap
void	push_all_save_two(t_stack **a, t_stack **b);
void	reorder_based_on_lowest(t_stack **a);
void	*sort_three(t_stack **a);
void	big_sort(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b, int size);

//r_functions
void	rotate_function(t_stack **stack);
void	ra_function(t_stack **a);
void	rb_function(t_stack **b);
void	rr_function(t_stack **a, t_stack **b);

//rr_functions
void	reverse_rotate_function(t_stack **stack);
void	rra_function(t_stack **a);
void	rrb_function(t_stack **b);
void	rrr_function(t_stack **a, t_stack **b);

//s_functions
void	swap_function(t_stack *stack);
void	sa_function(t_stack **stack_a);
void	sb_function(t_stack **stack_b);
void	ss_function(t_stack **stack_a, t_stack **stack_b);

//stack_utils
t_stack	*create_stack(char **argv);
t_stack	*create_node(int number);
void	add_to_stack(t_stack **stack, t_stack *new_node);
int		get_size(t_stack *stack);
void	free_the_stack(t_stack **stack);

#endif
