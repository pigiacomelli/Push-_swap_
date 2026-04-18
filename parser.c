/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiacome <pgiacome@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:53:43 by pgiacome          #+#    #+#             */
/*   Updated: 2026/04/18 15:54:32 by pgiacome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	valid_number(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol_strict(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s == '\0')
		error_exit();
	while (*s)
	{
		result = result * 10 + (*s - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			error_exit();
		s++;
	}
	return (result * sign);
}

void	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				error_exit();
			j++;
		}
		i++;
	}
}

int	*parse_args(int argc, char **argv, int *size)
{
	int	i;
	int	*numbers;

	if (argc <= 1)
		return (NULL);
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		error_exit();
	i = 1;
	while (i < argc)
	{
		if (!valid_number(argv[i]))
			error_exit();
		numbers[i - 1] = (int)ft_atol_strict(argv[i]);
		i++;
	}
	*size = argc - 1;
	check_duplicates(numbers, *size);
	return (numbers);
}
