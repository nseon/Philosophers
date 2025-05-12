/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:51:03 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 19:06:15 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parsing.h"
#include <stdio.h>
#include "actions.h"

int	philo_sleep(int	time_left, int sleep_time)
{
	int	count;

	count = -1;
	while ((++count) < sleep_time)
	{
		usleep(1000);
		if (count > time_left)
			return (1);
	}
	return (0);
}

int	is_sleeping(t_args *infos)
{
	print(*infos, "%ld %d is sleeping\n");
	if (philo_sleep(infos->will_die - get_time(*infos->time_minus), (*infos).tt_sleep))
	{
		is_dead(*infos);
		return (0);
	}
	return (1);
}
