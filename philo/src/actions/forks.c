/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:06:27 by nseon             #+#    #+#             */
/*   Updated: 2025/05/15 14:23:46 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "actions.h"
#include <unistd.h>
#include "mutex.h"

int	set_fork(t_args *infos, int n)
{
	int	i;
	int	res;

	i = -1;
	(*infos).forks = malloc(n * sizeof(t_mutint));
	if (!*fork)
		return (-1);
	while (++i < n)
	{
		res = pthread_mutex_init(&(*infos).forks->mutex, NULL);
		if (res)
		{
			destroy_mutexes_forks(*infos, i);
			return (-1);
		}
		(*infos).forks[i].status = 0;
	}
	return (0);
}

void	take_one_fork(t_args infos, int index)
{
	while (1)
	{
		check_death(infos);
		if (get_end_status(infos))
			break ;
		pthread_mutex_lock(&infos.forks[index].mutex);
		if (!infos.forks[index].status)
		{
			infos.forks[index].status = 1;
			pthread_mutex_unlock(&infos.forks[index].mutex);
			print(infos, "%ldms %d has taken a fork\n");
			return ;
		}
		pthread_mutex_unlock(&infos.forks[index].mutex);
		usleep(200);
	}
}

int	take_fork(t_args infos)
{
	int	plus_one;

	plus_one = infos.number;
	if (infos.number == infos.philo_nb)
		plus_one = 0;
	take_one_fork(infos, infos.number - 1);
	take_one_fork(infos, plus_one);
	return (1);
}

void release_fork(t_args infos, int index)
{
	pthread_mutex_lock(&infos.forks[index].mutex);
	infos.forks[index].status = 0;
	pthread_mutex_unlock(&infos.forks[index].mutex);
}
