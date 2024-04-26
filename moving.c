/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:45 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/04/26 15:35:47 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function calls the rrr function as many times as needed
void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr_function(a, b);
	}
}

//this function calls the rr function as many times as needed

void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr_function(a, b);
	}
}

//this fucntion calls the ra or rra function as many times as needed
void	do_rotate_a(t_stack **a, int *cost)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			ra_function(a);
			(*cost)--;
		}
	}
	else if (*cost < 0)
	{
		while (*cost < 0)
		{
			rra_function(a);
			(*cost)++;
		}
	}
}

///this fucntion calls the rb or rrb function as many times as needed

void	do_rotate_b(t_stack **b, int *cost)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			rb_function(b);
			(*cost)--;
		}
	}
	else if (*cost < 0)
	{
		while (*cost < 0)
		{
			rrb_function(b);
			(*cost)++;
		}
	}
}
//if the cost is negative
//it means the numbers are in the bottom half of the stack
//that means it's better to reverse rotate
//otherwise is better to rotate

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	pa_function(a, b);
}
