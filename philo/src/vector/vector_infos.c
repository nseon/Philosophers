/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:38:59 by nseon             #+#    #+#             */
/*   Updated: 2025/04/16 09:57:19 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*!
 * @param data Vector data
 * @return Number of element in data
 */
int	vct_size(void *data)
{
	return (get_vct_struct(data)->nb_elem);
}

/*!
 * @param data Vector data
 * @return Total capacity of the data
 */
int	vct_capacity(void *data)
{
	return (get_vct_struct(data)->capacity);
}

/*!
 * @param vct The vector
 * @return Unused capacity of the data
 */
int	place_remain(t_vct *vct)
{
	return (vct->capacity - vct->nb_elem);
}
