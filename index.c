#include "index.h"
#include <stdlib.h>

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_copy(int *arr, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	sort_int_array(copy, size);
	return (copy);
}

void	index_stack(t_stack *a)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = sorted_copy(a->data, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->data[i] == sorted[j])
			{
				a->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}
