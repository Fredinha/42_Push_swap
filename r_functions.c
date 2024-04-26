/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:22:42 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/03/26 16:22:46 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_function(t_stack **stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	*stack = (*stack)->next;
	current->next->next = NULL;
}

void	ra_function(t_stack **a)
{
	rotate_function(a);
	ft_printf("ra\n");
}

void	rb_function(t_stack **b)
{
	rotate_function(b);
	ft_printf("rb\n");
}

void	rr_function(t_stack **a, t_stack **b)
{
	rotate_function(a);
	rotate_function(b);
	ft_printf("rr\n");
}
