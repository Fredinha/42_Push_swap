/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:13 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/03/26 14:50:15 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_function(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	pb_function(t_stack **a, t_stack **b)
{
	push_function(a, b);
	ft_printf("pb\n");
}

void	pa_function(t_stack **a, t_stack **b)
{
	push_function(b, a);
	ft_printf("pa\n");
}
