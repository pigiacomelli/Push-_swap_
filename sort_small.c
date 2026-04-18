/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiacome <pgiacome@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:53:43 by pgiacome          #+#    #+#             */
/*   Updated: 2026/04/18 15:54:32 by pgiacome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_small.h"

void	sort_two(t_stack *a)
{
	if (a->data[0] > a->data[1])
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	max;

	max = stack_max(a);
	if (a->data[0] == max)
		ra(a);
	else if (a->data[1] == max)
		rra(a);
	if (a->data[0] > a->data[1])
		sa(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;

	while (a->size > 3)
	{
		min = stack_min(a);
		while (a->data[0] != min)
		{
			if (index_of(a, min) <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
