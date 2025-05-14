/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:00:34 by nseon             #+#    #+#             */
/*   Updated: 2025/05/14 12:55:53 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <pthread.h>

void	print(t_args infos, const char *format)
{
	const long int	time = get_time(*infos.time_minus);

	pthread_mutex_lock(infos.print);
	pthread_mutex_lock(&infos.end->mutex);
	if (!infos.end->status)
	{
		pthread_mutex_unlock(&infos.end->mutex);
		printf(format, time, infos.number);
		pthread_mutex_unlock(infos.print);
	}
	else
	{
		pthread_mutex_unlock(infos.print);
		pthread_mutex_unlock(&infos.end->mutex);
	}
}
