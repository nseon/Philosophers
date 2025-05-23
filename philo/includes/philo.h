/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:41:39 by nseon             #+#    #+#             */
/*   Updated: 2025/05/05 17:03:29 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "parsing.h"

typedef struct s_philo
{
	int				number;
	pthread_mutex_t	mutexi;
	int				i;
}	t_philo;

int		create_ph(int number, void*(*routine)(void*), t_args args);
void	*routine(void *args);

#endif
