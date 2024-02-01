/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:46:20 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/10/24 17:45:14 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int    ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	*s6;
	char	*s7;
	char	*s8;
	int		i;

	i = 0;
	s1 = "12345";
	s2 = "12346";
	s3 = "12344";
	s4 = "123456789";
	s5 = "1234";
	s6 = "1235";
	s7 = "";
	s8 = "13111";

	printf("this is s1: %s\nthis is s2: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));
	printf("this is s1: %s\nthis is s3: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s3, strcmp(s1, s3), ft_strcmp(s1, s3));
	printf("this is s1: %s\nthis is s4: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s4, strcmp(s1, s4), ft_strcmp(s1, s4));
	printf("this is s1: %s\nthis is s5: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s5, strcmp(s1, s5), ft_strcmp(s1, s5));
	printf("this is s1: %s\nthis is s6: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s6, strcmp(s1, s6), ft_strcmp(s1, s6));
	printf("this is s1: %s\nthis is s7: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s7, strcmp(s1, s7), ft_strcmp(s1, s7));
	printf("this is s1: %s\nthis is s8: %s\nthis is the result: %d\nthis is my result: %d\n\n", s1, s8, strcmp(s1, s8), ft_strcmp(s1, s8));
}*/
