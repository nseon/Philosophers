/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:31 by nseon             #+#    #+#             */
/*   Updated: 2025/05/15 14:23:46 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include <parsing.h>

int		init_mutexes(t_args *infos);
void	destroy_mutexes(t_args infos);
void	destroy_mutexes_forks(t_args infos, int size);
void	destroy_init_mutexes(t_args infos);

#endif
