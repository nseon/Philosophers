/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:24:22 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 16:13:42 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <actions.h>

void	*routine(void *args)
{
	t_args		infos;

	infos = *(t_args *)args;
	pthread_mutex_lock(infos.start);
	pthread_mutex_unlock(infos.start);
	while (1)
	{
		think(infos);
		if (get_end_status(infos))
			break ;
		while (!is_eating(&infos))
		{
			check_death(infos);
			if (get_end_status(infos))
				break ;
		}
		if (get_end_status(infos))
			break ;
		is_sleeping(&infos);
		if (get_end_status(infos))
			break ;
	}
	free(args);
	return (0);
}
