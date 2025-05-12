/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:35:33 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 19:03:08 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <pthread.h>

typedef struct s_mutint
{
	pthread_mutex_t	mutex;
	int				status;
}	t_mutint;

typedef struct s_args
{
	int				philo_nb;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				eat_nb;
	int				number;
	pthread_mutex_t	*start;
	pthread_mutex_t	*print;
	t_mutint		*end;
	t_mutint		*forks;
	long int		*time_minus;
	int				will_die;
}	t_args;

int			verif_args(int argc, char **args);
void		fill_args(int *args, int argc, char **argv);
int			set_fork(t_mutint **fork, int n);
int			duplicate_args(t_args **newargs, t_args args);
long int	get_time(long int minus);
void		init_end_start(t_args *infos);

#endif
