/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:45:20 by nseon             #+#    #+#             */
/*   Updated: 2025/05/13 11:29:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <pthread.h>

void	is_dead(t_args infos)
{
	pthread_mutex_lock(&infos.end->mutex);
	if (!infos.end->status)
	{
		infos.end->status = 1;
		pthread_mutex_unlock(&infos.end->mutex);
		pthread_mutex_lock(infos.print);
		printf("%ldms %d died\n", get_time(*infos.time_minus), infos.number);
		pthread_mutex_unlock(infos.print);
	}
	else
		pthread_mutex_unlock(&infos.end->mutex);
}

void	check_death(t_args infos)
{
	if (get_time(*infos.time_minus) > infos.will_die)
		is_dead(infos);
}

int	get_end_status(t_args infos)
{
	int	res;

	pthread_mutex_lock(&infos.end->mutex);
	res = infos.end->status;
	pthread_mutex_unlock(&infos.end->mutex);
	return (res);
}
