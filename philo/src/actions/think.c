/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:52:16 by nseon             #+#    #+#             */
/*   Updated: 2025/05/12 16:07:26 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <pthread.h>
#include <stdio.h>
#include "actions.h"

void	think(t_args infos)
{
	print(infos, "%ld %d is thinking\n");
}
