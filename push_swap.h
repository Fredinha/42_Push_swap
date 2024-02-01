/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:29:06 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/11/03 17:15:52 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include "./libftplus/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int	only_numbers(int argc, char **argv);
int	no_duplicates(int argc, char **argv);
int	is_it_an_int(int argc, char **argv);
int correct_input(int argc, char **argv);
t_stack *create_stack(char **argv);
t_stack *create_node(int number);
void	add_to_stack(t_stack **stack, t_stack *new_node);


#endif
