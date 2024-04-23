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
	t_stack	*b;
//	struct s_stack	*next;
//	struct s_stack	*prev;	
	int		size;
//	t_stack	*current; //isto e so para testar
	if (correct_input(argc, argv) == 0)
		return (0);
	a = create_stack(argv);
	b = NULL;
//	size = argc - 1;
	 //isto e so para testar
	//este while tbm e so para testar
	size = get_size(a);	
	put_index(a);
	//ra_function(&a);
//	rra_function(&a);
	///sa_function(&a);
	//put_index(a);
	//current = a;
	/*while (current != NULL)
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
	
//	ft_printf("The size of the list is %i\n\n", size);*/
	if (!stack_is_sorted(a))
		push_swap(&a, &b, size);
	free_the_stack(&a);
	free_the_stack(&b);
	return (0);
//ft_printf ("Everything seems fine!\n");
}
