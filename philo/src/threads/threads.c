/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:25:18 by nseon             #+#    #+#             */
/*   Updated: 2025/05/14 13:22:38 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include <stdlib.h>
#include "parsing.h"
#include <stdio.h>

int	wait_philos(pthread_t *threadids, int number)
{
	int	i;

	i = -1;
	while (++i < number)
		if (pthread_join(threadids[i], NULL))
			return (-1);
	return (0);
}

int	create_ph(int number, void*(*routine)(void*), t_args args)
{
	int			i;
	pthread_t	*threadids;
	t_args		*new_args;

	i = -1;
	threadids = malloc(number * sizeof(pthread_t));
	if (!threadids)
		return (-1);
	while (++i < number)
	{
		args.number = i + 1;
		if (duplicate_args(&new_args, args) == -1)
			break ;
		if (pthread_create(threadids + i, NULL, routine, new_args) != 0)
		{
			free(new_args);
			break ;
		}
	}
	*args.time_minus = get_time(0);
	pthread_mutex_unlock(args.start);
	if (wait_philos(threadids, i) == -1)
		return (-1);
	free(threadids);
	return (0);
}
