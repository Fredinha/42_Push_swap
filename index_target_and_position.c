#include "push_swap.h"

void	put_index(t_stack *stack)
{
	t_stack *current;
	t_stack	*temp;
	int	count;

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

// retorna a posicao do menor index na stack
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
