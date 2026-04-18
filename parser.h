/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiacome <pgiacome@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:53:43 by pgiacome          #+#    #+#             */
/*   Updated: 2026/04/18 15:54:32 by pgiacome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
# include <unistd.h>

int		*parse_args(int argc, char **argv, int *size);
long	ft_atol_strict(const char *s);
void	check_duplicates(int *arr, int size);
void	error_exit(void);

#endif
