/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:06:27 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 16:28:28 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "actions.h"

int	set_fork(t_mutint **fork, int n)
{
	int	i;

	i = -1;
	*fork = malloc(n * sizeof(t_mutint));
	if (!*fork)
		return (-1);
	while (++i < n)
	{
		pthread_mutex_init(&((*fork)[i]).mutex, NULL);
		(*fork)[i].status = 0;
	}
	return (0);
}

int	take_fork(t_args infos)
{
	int	plus_one;

	if (infos.philo_nb <= 1)
		return (0);
	plus_one = infos.number;
	if (infos.number == infos.philo_nb)
		plus_one = 0;
	pthread_mutex_lock(&infos.forks[infos.number - 1].mutex);
	pthread_mutex_lock(&infos.forks[plus_one].mutex);
	if (!infos.forks[infos.number - 1].status
		&& !infos.forks[plus_one].status)
	{
		infos.forks[infos.number - 1].status = 1;
		infos.forks[plus_one].status = 1;
		pthread_mutex_unlock(&infos.forks[infos.number - 1].mutex);
		pthread_mutex_unlock(&infos.forks[plus_one].mutex);
		print(infos, "%ld %d has taken a fork\n");
		print(infos, "%ld %d has taken a fork\n");
		return (1);
	}
	pthread_mutex_unlock(&infos.forks[infos.number - 1].mutex);
	pthread_mutex_unlock(&infos.forks[plus_one].mutex);
	return (0);
}
