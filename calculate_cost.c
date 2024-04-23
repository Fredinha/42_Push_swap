#include "push_swap.h"

//fazer o find_max

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


//fazer o find_min

t_stack	*find_min(t_stack *stack)
{
	t_stack	min;

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

int	transform_negatives(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

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
		temp_b->cost_a = temp_b->target_position;
		if (temp_b->target_position > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_position) * -1;
		temp_b = temp_b->next;
	}
}

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
		if (transform_negatives(tmp->cost_a) + transform_negatives(temp->cost_b) < transform_negatives(cheapest))
		{
			cheapest = transform_negatives(temp->cost_b) + transform_negatives(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
