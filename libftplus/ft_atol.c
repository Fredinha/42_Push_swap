/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:10:07 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/10/30 18:28:41 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

long	ft_atol(char *str)
{
	long	i;
	long	result;
	long	signal;

	signal = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * signal);
}

/*int	main(void)
{
	long	a;
	long	b;
	long	c;
	long	d;
	long	e;
	long	f;
	long	g;
	long	h;
	long    aa;
    long    bb;
    long    cc;
    long    dd;
    long    ee;
    long    ff;
	long	gg;
	long	hh;

	aa = atol("   +---+1234");
	bb = atol("  		 -++-+745627");
	cc = atol("-78");
	dd = atol("123456");
	ee = atol("f  -34");
	ff = atol("  876f99");
	gg = atol("   -75463774");
	hh = atol("   9588493");
	a = ft_atol("   +---+1234");
    b = ft_atol("              -++-+745627");
    c = ft_atol("-78");
    d = ft_atol("123456");
    e = ft_atol("f  -34");
    f = ft_atol("  876f99");
	g = ft_atol("   -75463774");
    h = ft_atol("   9588493");

	printf("real %ld, mine %ld\n", aa, a);
	printf("real %ld, mine %ld\n", bb, b);
	printf("real %ld, mine %ld\n", cc, c);
	printf("real %ld, mine %ld\n", dd, d);
	printf("real %ld, mine %ld\n", ee, e);
	printf("real %ld, mine %ld\n", ff, f);
	printf("real %ld, mine %ld\n", gg, g);
	printf("real %ld, mine %ld\n", hh, h);

}*/
