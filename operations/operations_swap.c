#include "operations.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || b->size < 2)
		return ;
	tmp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
	tmp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = tmp;
	write(1, "ss\n", 3);
}
