#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
# include <unistd.h>

int		*parse_args(int argc, char **argv, int *size);
long	ft_atol_strict(const char *s);
void	check_duplicates(int *arr, int size);
void	error_exit(void);

#endif
