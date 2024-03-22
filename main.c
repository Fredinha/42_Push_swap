/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:35:35 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/03/19 17:00:27 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(char **argv)
{
	t_stack	*a;
	int		i;
	t_stack 	*new_node;
	
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
t_stack *create_node(int number)
{
	t_stack *node;
	
	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = number;
	node->next = NULL;
	//node->prev = NULL;
	return(node);
//	struct s_stack	*next;
//	struct s_stack	*prev;
}

void	add_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!stack)
		return ;
	if(!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current = *stack;
		//current->prev = NULL;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

// criar get_size(int argc, char **argv)

// criar put_index(int a)

// criar push_swap(int a, int b)

// criar free_stack (int x)

int	main(int argc, char **argv)
{
	t_stack	*a;
//	t_stack	*b;
//	struct s_stack	*next;
//	struct s_stack	*prev;	
//	int		size;
	t_stack	*current; //isto e so para testar
	
	if (correct_input(argc, argv) == 0)
		return (0);
	a = create_stack(argv);
//	b = NULL;
//	size = argc - 1;
	current = a; //isto e so para testar
	//este while tbm e so para testar
	while (current != NULL)
	{
		ft_printf("The element is %i\n", current->data);
		if (current->prev != NULL)
			ft_printf("The previous element is %i\n", current->prev->data);
		else
			ft_printf("No previous element\n");
		if (current->next != NULL)
			ft_printf("The next element is %i\n\n", current->next->data);
		else
			ft_printf("No next element\n\n");
		current = current->next;
	}
//	size = get_size(argc, argv);	
/*	put_index(a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b); */
//ft_printf ("Everything seems fine!\n");
}
