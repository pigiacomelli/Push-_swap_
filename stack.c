/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiacome <pgiacome@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:53:43 by pgiacome          #+#    #+#             */
/*   Updated: 2026/04/18 15:54:32 by pgiacome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(int *values, int capacity)
{
	t_stack	*s;
	int		i;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->data = malloc(sizeof(int) * capacity);
	if (!s->data)
		return (NULL);
	if (values)
	{
		s->size = capacity;
		i = 0;
		while (i < capacity)
		{
			s->data[i] = values[i];
			i++;
		}
	}
	else
		s->size = 0;
	return (s);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	free(s->data);
	free(s);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
