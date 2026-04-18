#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}		t_stack;

t_stack	*stack_init(int *values, int size);
void	stack_free(t_stack *s);
int		is_sorted(t_stack *a);
int		stack_min(t_stack *a);
int		stack_max(t_stack *a);
int		index_of(t_stack *a, int value);

#endif
