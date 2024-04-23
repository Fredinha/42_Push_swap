#include "push_swap.h"

void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr_funcrion(a, b);
	}
}

/* ft_rotate_both:
 */
void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr_function(a, b);
	}
}

/* do_rotate_a:
 *
 */
void	do_rotate_a(t_stack **a, int *cost)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			ra_function(a);
			(*cost)--;
		}
	}
	else if (*cost < 0)
	{
		while (*cost < 0)
		{
			rra_function(a);
			(*cost)++;
		}
	}
}

/* ft_rotate_b:
 *
 */
void	do_rotate_b(t_stack **b, int *cost)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			rb_function(b);
			(*cost)--;
		}
	}
	else if (*cost < 0)
	{
		while (*cost < 0)
		{
			rrb_function(b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	pa_function(a, b);
}
