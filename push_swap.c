#include "push_swap.h"

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

//fazer o sort_three


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

// criar push_swap(int a, int b)

void	push_swap (t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa_function(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
		big_sort(a, b);
}

