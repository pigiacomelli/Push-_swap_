#include "algorithm.h"
#include "chunk_sort.h"
#include "operations/operations.h"
#include "sort_small.h"

int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = a->size;
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->data[0] >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
			if (is_sorted(a))
				break ;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else if (a->size > 5 && a->size <= 100)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
