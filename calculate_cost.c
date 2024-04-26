/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:57 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/04/26 15:35:00 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function finds the biggest number in the list

t_stack	*find_max(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a)
	{
		if (a->number > max->number)
			max = a;
		a = a->next;
	}
	return (max);
}

//this function finds the smallest number in the list

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->number < min->number)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

//this function converts the negative numbers to positive

int	no_neg(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

//this function calculates the cost of moving elements between a and b
//if the number is in the bottom part of the stack the cost is negative
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *a;
	temp_b = *b;
	size_a = get_size(temp_a);
	size_b = get_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->position;
		if (temp_b->position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->position) * -1;
		temp_b->cost_a = temp_b->target;
		if (temp_b->target > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target) * -1;
		temp_b = temp_b->next;
	}
}

//this function identifies the cheapest move and make it happen
//it uses the function no_neg because of the function get_cost

void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (no_neg(temp->cost_a) + no_neg(temp->cost_b)
			< no_neg(cheapest))
		{
			cheapest = no_neg(temp->cost_b) + no_neg(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
