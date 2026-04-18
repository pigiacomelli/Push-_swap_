#include "algorithm.h"
#include "index.h"
#include "parser.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*values;
	int		size;

	if (argc < 2)
		return (0);
	values = parse_args(argc, argv, &size);
	a = stack_init(values, size);
	b = stack_init(NULL, size);
	free(values);
	index_stack(a);
	push_swap(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
