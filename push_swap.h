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
#define PUSH_SWAP_H

# include <unistd.h>
# include "./libftplus/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;	
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack	*target;

}					t_stack;

//main
t_stack *create_stack(char **argv);
t_stack *create_node(int number);
void	add_to_stack(t_stack **stack, t_stack *new_node);
int	get_size(t_stack *stack);
void	put_index(t_stack *stack);

//good_input
int	only_numbers(int argc, char **argv);
int	no_duplicates(int argc, char **argv);
int	is_it_an_int(int argc, char **argv);
int correct_input(int argc, char **argv);

//s_functions
void swap_function(t_stack *stack);
void sa_function(t_stack **stack_a);
void sb_function(t_stack **stack_b);
void ss_function(t_stack **stack_a, t_stack **stack_b);


//p_functions
void    push_function(t_stack **a, t_stack **b);
void    pb_function(t_stack **a, t_stack **b);
void    pa_function(t_stack **a, t_stack **b);

//r_functions
void    rotate_function(t_stack **stack);
void    ra_function(t_stack **a);
void    rb_function(t_stack **b);
void    rr_function(t_stack **a, t_stack **b);

//rr_functions
void    reverse_rotate_function(t_stack **stack);
void    rra_function(t_stack **a);
void    rrb_function(t_stack **b);
void    rrr_function(t_stack **a, t_stack **b);

#endif
