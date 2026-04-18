#include "operations/operations.h"
#include "stack.h"

static void	push_max_back(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (b->size > 0)
	{
		max = stack_max(b);
		pos = index_of(b, max);
		if (pos <= b->size / 2)
		{
			while (b->data[0] != max)
				rb(b);
		}
		else
		{
			while (b->data[0] != max)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk;
	int	limit;
	int	pushed;

	chunk = 20;
	limit = chunk;
	pushed = 0;
	while (a->size > 0)
	{
		if (a->data[0] < limit)
		{
			pb(a, b);
			pushed++;
			if (b->data[0] < limit - (chunk / 2))
				rb(b);
		}
		else
			ra(a);
		if (pushed == limit)
			limit += chunk;
	}
	push_max_back(a, b);
}
