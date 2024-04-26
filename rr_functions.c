/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:03:34 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/03/26 17:03:37 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function moves the bottom element of the stack to the top

void	reverse_rotate_function(t_stack **stack)
{
	t_stack	*original_last;
	t_stack	*new_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	original_last = *stack;
	new_last = *stack;
	while (original_last->next != NULL)
		original_last = original_last->next;
	while (new_last->next != original_last)
		new_last = new_last->next;
	new_last->next = NULL;
	original_last->next = *stack;
	*stack = original_last;
}

void	rra_function(t_stack **a)
{
	reverse_rotate_function(a);
	ft_printf("rra\n");
}

void	rrb_function(t_stack **b)
{
	reverse_rotate_function(b);
	ft_printf("rrb\n");
}

void	rrr_function(t_stack **a, t_stack **b)
{
	reverse_rotate_function(a);
	reverse_rotate_function(b);
	ft_printf("rrr\n");
}
