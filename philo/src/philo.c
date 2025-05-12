/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:55:22 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 13:52:12 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"
#include <sys/time.h>
#include "philo.h"
#include <sys/time.h>

int	main(int argc, char **argv)
{
	t_args			args;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	t_mutint		end;
	long int		time_minus;

	time_minus = 0;
	args = (t_args){0};
	args.end = &end;
	args.start = &start;
	args.print = &print;
	args.time_minus = &time_minus;
	if (verif_args(argc, argv) == -1)
		return (1);
	fill_args(&args.philo_nb, argc - 1, argv + 1);
	init_end_start(&args);
	if (set_fork(&args.forks, args.philo_nb) == -1)
		return (1);
	if (create_ph(args.philo_nb, routine, args) == -1)
		return (1);
	free(args.forks);
	return (0);
}
