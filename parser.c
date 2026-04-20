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
	if (s[i] == '\0' || s[i] == ' ')
		return (0);
	while (s[i] && s[i] != ' ')
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
	while (*s && *s != ' ')
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

static int	count_tokens(char *s)
{
	int	count;
	int	in_token;

	count = 0;
	in_token = 0;
	while (*s)
	{
		if (*s != ' ' && !in_token)
		{
			in_token = 1;
			count++;
		}
		else if (*s == ' ')
			in_token = 0;
		s++;
	}
	return (count);
}

static int	fill_numbers(int *numbers, int argc, char **argv)
{
	int		i;
	int		j;
	char	*s;
	int		k;

	k = 0;
	i = 1;
	while (i < argc)
	{
		s = argv[i];
		j = 0;
		while (s[j])
		{
			while (s[j] == ' ')
				j++;
			if (s[j])
			{
				if (!valid_number(&s[j]))
					return (-1);
				numbers[k++] = (int)ft_atol_strict(&s[j]);
				while (s[j] && s[j] != ' ')
					j++;
			}
		}
		i++;
	}
	return (k);
}

int	*parse_args(int argc, char **argv, int *size)
{
	int	i;
	int	count;
	int	*numbers;

	if (argc <= 1)
		return (NULL);
	count = 0;
	i = 1;
	while (i < argc)
	{
		count += count_tokens(argv[i]);
		i++;
	}
	if (count == 0)
		return (NULL);
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		error_exit();
	if (fill_numbers(numbers, argc, argv) == -1)
	{
		free(numbers);
		error_exit();
	}
	*size = count;
	check_duplicates(numbers, *size);
	return (numbers);
}
