/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:24:22 by nseon             #+#    #+#             */
/*   Updated: 2025/05/14 12:55:38 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <actions.h>
#include <unistd.h>

void	*routine(void *args)
{
	t_args		infos;

	infos = *(t_args *)args;
	pthread_mutex_lock(infos.start);
	pthread_mutex_unlock(infos.start);
	if (infos.number % 2 != 0)
		usleep(10000);
	while (1)
	{
		think(infos);
		while (!is_eating(&infos))
		{
			check_death(infos);
			if (get_end_status(infos))
				break ;
		}
		if (infos.eat_nb == 0)
			break ;
		is_sleeping(&infos);
		if (get_end_status(infos))
			break ;
	}
	free(args);
	return (0);
}
