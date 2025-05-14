/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:52:16 by nseon             #+#    #+#             */
/*   Updated: 2025/05/13 11:30:25 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <pthread.h>
#include <stdio.h>
#include "actions.h"

void	think(t_args infos)
{
	print(infos, "%ldms %d is thinking\n");
}
