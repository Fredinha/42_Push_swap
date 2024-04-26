/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:11 by fgomes-f          #+#    #+#             */
/*   Updated: 2024/03/26 13:26:13 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_function(t_stack *stack)
{
    int temp;

    if (stack == NULL || stack->next == NULL)
        return;
    temp = stack->number;
    stack->number = stack->next->number;
    stack->next->number = temp;
}

void sa_function(t_stack **stack_a)
{
    swap_function(*stack_a);
    ft_printf("sa\n");
}

void sb_function(t_stack **stack_b)
{
    swap_function(*stack_b);
    ft_printf("sb\n");
}

void ss_function(t_stack **stack_a, t_stack **stack_b)
{
    swap_function(*stack_a);
    swap_function(*stack_b);
    ft_printf("ss\n");
}
