/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:13:11 by nseon             #+#    #+#             */
/*   Updated: 2025/05/13 10:27:37 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "parsing.h"

int		take_fork(t_args infos);
int		is_eating(t_args *infos);
int		philo_sleep(t_args infos, int sleep_time);
void	is_dead(t_args infos);
int		is_sleeping(t_args *infos);
void	check_death(t_args infos);
void	think(t_args infos);
int		get_end_status(t_args infos);
void	print(t_args infos, const char *format);

#endif