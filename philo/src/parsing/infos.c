/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:15:32 by nseon             #+#    #+#             */
/*   Updated: 2025/05/15 13:17:34 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"
#include <pthread.h>

void	fill_args(int *args, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
		*(args + i) = ft_atoi(argv[i]);
	if (argc == 4)
		*(args + i) = -1;
}

int	duplicate_args(t_args **newargs, t_args args)
{
	int	i;

	i = -1;
	*newargs = malloc(sizeof(t_args));
	if (!*newargs)
		return (-1);
	**newargs = args;
	return (0);
}
