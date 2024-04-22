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
	node->number = number;
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

// criar put_index(int a)

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

//fazer o sort_three

void *sort_three(t_stack **a)
{
	if ((*a)->number == find_max(*a))
		ra_function(a);
	else if ((*a)->next->number == find_max(*a))
		rra_function(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa_function(a);
}



void	prepare_everything(t_stack *a, t_stack *b)
{
	put_index(a);
	put_index(b);
	define_target(a, b);
	cost_analysis(a, b);
	define_cheapest(a);
}

//move_to_b
//prepare_everything
//move_to_a

//fazer o big sort

void	big_sort(t_stack **a, t_stack **b)
{
	int		size;

	size = get_size(*a);
	if (size-- > 3 && !stack_is_sorted(*a))
		pb_function(a, b);
	if (size-- > 3 && !stack_is_sorted(*a))
		ft_pb(a, b);
	while (size > 3 && !stack_is_sorted(*a))
	{
		prepare_everything(a, b);
		ft_move_to_b(a, &b);
	}
	ft_sort_three(a);
	while (b)
	{
		prepare_everything(b, a);
		ft_move_to_a(b, a);
	}
	put_index(*a);
	free_the_stack(&b);
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

// criar free_stack (int x)
void free_the_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

bool	stack_is_sorted(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (temp->number < a->number)
				return (false);
			temp = temp->next;
		}
		a = a->next;
	}
	return (true);
}	

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;
//	struct s_stack	*next;
//	struct s_stack	*prev;	
	int		size;
//	t_stack	*b;
	int		size_a;

	size_a = ft_stack_size(*a);
	b = NULL;
	if (size_a-- > 3 && !check_sort(*a))
		ft_pb(a, &b, 1);
	if (size_a-- > 3 && !check_sort(*a))
		ft_pb(a, &b, 1);
	if (size_a > 3 && !check_sort(*a))
		ft_move_to_b(a, &b);
	ft_sort_three(a);
	while (b)
	{
		init_stack_b(b, *a);
		ft_move_to_a(&b, a);
	}
	set_index(*a);
	ft_stackclear(&b, ft_free);int		sizee;
	t_stack	*current; //isto e so para testar

	if (correct_input(argc, argv) == 0)
		return (0);
	a = create_stack(argv);
	//b = NULL;
//	size = argc - 1;
	 //isto e so para testar
	//este while tbm e so para testar
	size = get_size(a);	
	put_index(a);
	//ra_function(&a);
//	rra_function(&a);
	///sa_function(&a);
	//put_index(a);
	current = a;
	while (current != NULL)
	{
		ft_printf("The element is %i\n", current->number);
		if (current->prev != NULL)
			ft_printf("The previous element is %i\n", current->prev->number);
		else
			ft_printf("No previous element\n");
		if (current->next != NULL)
			ft_printf("The next element is %i\n", current->next->number);
		else
			ft_printf("No next element\n");
		ft_printf("The index is %i\n\n", current->index);
		current = current->next;
	}
	//pb_function(&a, &b);

	//sizee = argc - 1;
	
	ft_printf("The size of the list is %i\n\n", size);
//	ft_printf("The sizee of the list is %i\n", sizee);
	
	
	//sizee = argc - 1;
	
//	ft_printf("The size of the list is %i\n\n", size);
	if (!stack_is_sorted(a))
		push_swap(&a, &b, size);
	free_the_stack(a);
	free_the_stack(b);
//ft_printf ("Everything seems fine!\n");
}
