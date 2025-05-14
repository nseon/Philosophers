/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:51:03 by nseon             #+#    #+#             */
/*   Updated: 2025/05/14 12:18:49 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parsing.h"
#include <stdio.h>
#include "actions.h"

int	philo_sleep(t_args infos, int sleep_time)
{
	const long int	awakening = get_time(*infos.time_minus) + sleep_time;

	while (get_time(*infos.time_minus) < awakening)
	{
		usleep(200);
		if (get_time(*infos.time_minus) > infos.will_die)
			return (1);
	}
	return (0);
}

int	is_sleeping(t_args *infos)
{
	print(*infos, "%ldms %d is sleeping\n");
	if (philo_sleep(*infos, (*infos).tt_sleep))
	{
		is_dead(*infos);
		return (0);
	}
	return (1);
}
