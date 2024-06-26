/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:48:02 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/11/03 14:27:29 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function checks if the input has onlu numeric characters

int	only_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (j < argc)
	{
		if (argv[j][i] == '-' || argv[j][i] == '+')
			i++;
		if (argv[j][i] == '\0')
			return (0);
		while (argv[j][i] >= '0' && argv[j][i] <= '9')
			i++;
		if (argv[j][i] != '\0')
			return (0);
		i = 0;
		j++;
	}
	return (1);
}

//this function checks if there are no repetead numbers

int	no_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

//this function checks if there is no number bigger than the maximum int
//or smaller than the minimum int

int	is_it_an_int(int argc, char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atol(argv[i]);
		if (nbr < -2147483648)
			return (0);
		if (nbr > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

//this function checks if there are enough arguments
//and it checks all the other potential errors

int	correct_input(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Error\n");
	else if (only_numbers(argc, argv) == 0)
		ft_printf("Error\n");
	else if (no_duplicates(argc, argv) == 0)
		ft_printf("Error\n");
	else if (is_it_an_int(argc, argv) == 0)
		ft_printf("Error\n");
	else
		return (1);
	return (0);
}
