/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:55:22 by nseon             #+#    #+#             */
/*   Updated: 2025/04/17 13:51:55 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"
#include <sys/time.h>

void	*test(void *inf)
{
	t_philo	*infos;
	struct timeval	time;

	gettimeofday(&time, NULL);
	infos = inf;
	pthread_mutex_lock(&infos->mutexi);
	printf("%ldms  i am thread number %d\n", time.tv_sec * 1000 + time.tv_usec / 1000, infos->i);
	pthread_mutex_unlock(&infos->mutexi);
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	*threadid;
	pthread_t	id;
	t_philo		infos;
	int			i;

	infos.i = 1;
	threadid = vct_init(sizeof (pthread_t), NULL);
	if (!threadid)
		return (1);
	pthread_mutex_init(&infos.mutexi, NULL);
	if (verif_args(argc, argv) == -1)
		return (1);
	while (infos.i <= 10)
	{
		pthread_create(&id, 0, &test, &infos);
		vct_add(&threadid, &id);
		pthread_mutex_lock(&infos.mutexi);
		infos.i++;
		pthread_mutex_unlock(&infos.mutexi);
	}
	i = -1;
	while (++i < vct_size(threadid))
		pthread_join(threadid[i], NULL);
	vct_destroy(threadid);
	return (0);
}
