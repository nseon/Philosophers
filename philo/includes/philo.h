/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:41:39 by nseon             #+#    #+#             */
/*   Updated: 2025/04/23 17:40:28 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	int				number;
	pthread_mutex_t	mutexi;
	int				i;
}	t_philo;

int	create_n_philos(int number, void*(*start_routine)(void*));

#endif
