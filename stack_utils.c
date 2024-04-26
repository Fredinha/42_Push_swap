/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:37:22 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/04/26 15:37:24 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **argv)
{
	t_stack	*a;
	int		i;
	t_stack	*new_node;

	a = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		new_node = create_node(ft_atoi(argv[i]));
		add_to_stack(&a, new_node);
		i++;
	}
	return (a);
}

t_stack	*create_node(int number)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

// criar get_size(t_list *stack)

int	get_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

// criar free_stack (int x)
void	free_the_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
