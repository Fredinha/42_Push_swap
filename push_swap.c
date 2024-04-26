/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:36:57 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/04/26 15:36:59 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function sends every number from a to b except from the 2 smallest ones

void	push_all_save_two(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb_function(a, b);
			pushed++;
		}
		else
			ra_function(a);
		i++;
	}
	while (size - pushed > 2)
	{
		pb_function(a, b);
		pushed++;
	}
}

//this function reorders the ctack a
//it puts the element with the lowest index on the top

void	reorder_based_on_lowest(t_stack **a)
{
	int	lowest;
	int	size;

	size = get_size(*a);
	lowest = get_lowest_index_position(a);
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			rra_function(a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			ra_function(a);
			lowest--;
		}
	}
}

//this function sorts the 3 numbers
//the biggest goes to the bottom
//and the other two are swapped if needed

void	*sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_max(*stack);
	if (biggest == *stack)
		ra_function(stack);
	if (biggest == (*stack)->next)
		rra_function(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa_function(stack);
	return (*stack);
}

//if the list has more than 3 numbers it comes here
//this function sends all elements from a to b except 2
//then every number gets a target and the cheapest number is moved

void	big_sort(t_stack **a, t_stack **b)
{
	push_all_save_two(a, b);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!stack_is_sorted(*a))
		reorder_based_on_lowest(a);
}

//this function decides which algorithm to apply

void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa_function(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
		big_sort(a, b);
}
