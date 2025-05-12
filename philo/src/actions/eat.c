/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:50:41 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 19:06:01 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "actions.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	is_eating(t_args *infos)
{
	int	plus_one;

	plus_one = (*infos).number;
	if ((*infos).number == (*infos).philo_nb)
		plus_one = 0;
	if (!((*infos).number % 2 == 1 && get_time(*infos->time_minus) < (*infos).tt_eat))
	{
		if (take_fork(*infos))
		{
			print(*infos, "%ld %d is eating\n");
			if (philo_sleep(infos->will_die - get_time(*infos->time_minus), (*infos).tt_eat))
				is_dead(*infos);
			(*infos).forks[(*infos).number - 1].status = 0;
			(*infos).forks[plus_one].status = 0;
			(*infos).will_die = get_time((*infos->time_minus)) + (*infos).tt_die;
			return (1);
		}
	}
	return (0);
}
