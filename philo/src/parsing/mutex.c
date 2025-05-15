/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:15:56 by nseon             #+#    #+#             */
/*   Updated: 2025/05/15 14:23:46 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	init_mutexes(t_args *infos)
{
	if (pthread_mutex_init(&infos->end->mutex, 0))
		return (-1);
	if (pthread_mutex_init((*infos).start, 0))
	{
		pthread_mutex_destroy(&infos->end->mutex);
		return (-1);
	}
	if (pthread_mutex_init((*infos).print, 0))
	{
		pthread_mutex_destroy(&infos->end->mutex);
		pthread_mutex_destroy((*infos).start);
		return (-1);
	}
	pthread_mutex_lock((*infos).start);
	infos->will_die = infos->tt_die;
	infos->end->status = 0;
	return (0);
}

void	destroy_mutexes_forks(t_args infos, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		pthread_mutex_destroy(&infos.forks[i].mutex);
}

void	destroy_init_mutexes(t_args infos)
{
	pthread_mutex_destroy(&infos.end->mutex);
	pthread_mutex_destroy(infos.start);
	pthread_mutex_destroy(infos.print);
}

void	destroy_mutexes(t_args infos)
{
	pthread_mutex_destroy(&infos.end->mutex);
	pthread_mutex_destroy(infos.start);
	pthread_mutex_destroy(infos.print);
	destroy_mutexes_forks(infos, infos.philo_nb);
}
