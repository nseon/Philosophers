/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:00:34 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 19:07:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <pthread.h>

void	print(t_args infos, const char *format)
{
	pthread_mutex_lock(&infos.end->mutex);
	if (!infos.end->status)
	{
		pthread_mutex_unlock(&infos.end->mutex);
		pthread_mutex_lock(infos.print);
		printf(format, get_time(*infos.time_minus), infos.number);
		pthread_mutex_unlock(infos.print);
	}
	else
		pthread_mutex_unlock(&infos.end->mutex);
}
