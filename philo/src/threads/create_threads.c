/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:25:18 by nseon             #+#    #+#             */
/*   Updated: 2025/04/23 17:40:20 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include "vector.h"

int	create_n_philos(int number, void*(*start_routine)(void*))
{
	int			i;
	pthread_t	id;
	pthread_t	*threadids;

	i = -1;
	threadids = malloc(number * sizeof(int));
	if (!threadids)
		return (-1);
	while (++i < number)
	{
		if (pthread_create(&id, NULL, start_routine, NULL) != 0)
			break;
	}
	return (0);
}
