#include "stack.h"

int	stack_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = a->data[0];
	while (i < a->size)
	{
		if (min > a->data[i])
			min = a->data[i];
		i++;
	}
	return (min);
}

int	stack_max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = a->data[0];
	while (i < a->size)
	{
		if (max < a->data[i])
			max = a->data[i];
		i++;
	}
	return (max);
}

int	index_of(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
