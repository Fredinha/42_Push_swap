/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_target_and_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:23 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/04/26 15:35:26 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function assigns an index to each number in the list
//in ascending order and starting from 1

void	put_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		count;

	current = stack;
	while (current != NULL)
	{
		temp = stack;
		count = 0;
		while (temp != NULL)
		{
			if (temp->number < current->number)
				count++;
			temp = temp->next;
		}
		current->index = count + 1;
		current = current->next;
	}
}

//this function saves the position of each element of the list
//starting from 0 (first element of the stack)

void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

//this function saves the position of the number
//with the smallest index
//(it will be the first element of the final order)

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;

	temp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = temp->position;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = temp->position;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

//this function finds out what is the target
//and returns the position of the target
//it receives the INT MAX as the target index
//and it looks for the closest bigger element in a
//if it doesn't exist, the target is the smallest number in a

int	get_target(t_stack **a, int b_index, int target_index, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

//this function gets the target for each element of the stack

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (temp_b)
	{
		target_pos = get_target(a, temp_b->index, INT_MAX, target_pos);
		temp_b->target = target_pos;
		temp_b = temp_b->next;
	}
}
