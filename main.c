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
	int		size;

	if (correct_input(argc, argv) == 0)
		return (0);
	a = create_stack(argv);
	b = NULL;
	size = get_size(a);
	put_index(a);
	if (!stack_is_sorted(a))
		push_swap(&a, &b, size);
	free_the_stack(&a);
	free_the_stack(&b);
	return (0);
}
