/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:14:58 by nseon             #+#    #+#             */
/*   Updated: 2025/05/19 11:01:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include "parsing.h"

int		set_fork(t_args *infos, int n);
int		take_fork(t_args infos);;
void	release_fork(t_args infos, int index);

#endif