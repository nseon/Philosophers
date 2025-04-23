/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:55:22 by nseon             #+#    #+#             */
/*   Updated: 2025/04/23 17:27:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"
#include <sys/time.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	int	*args;

	args = malloc((argc - 1) * sizeof (int));
	if (!args)
		return (1);
	if (verif_args(argc, argv) == -1)
		return (1);
	fill_args(args, argc, argv);
	return (0);
}
