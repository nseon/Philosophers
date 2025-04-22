/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:24:27 by nseon             #+#    #+#             */
/*   Updated: 2025/04/17 13:19:16 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utils.h"

/*!
* Delete the next nb elements of the data
* @param data Vector's data
* @param index The position of the first element to be deleted
* @param nb The number of element to be deleted
*/
void	vct_delete_next(void *data, int index, int nb)
{
	int		i;
	t_vct	*vct;

	i = -1;
	vct = get_vct_struct(data);
	if (vct->del)
		while (++i < nb)
			vct->del(vct->data + (i + index) * vct->elem_size);
	ft_memmove(&vct->data[index * vct->elem_size],
		&vct->data[(index + nb) * vct->elem_size],
		(vct->nb_elem - index - nb) * vct->elem_size);
	vct->nb_elem -= nb;
}

/*!
* Delete one element of the data
* @param data Vector's data
* @param index Position of the element
*/
void	vct_delete_one(void *data, int index)
{
	vct_delete_next(data, index, 1);
}

/*!
* Delete all the elements of the data & free it
* @param data Vector's data
*/
void	vct_destroy(void *data)
{
	vct_delete_next(data, 0, get_vct_struct(data)->nb_elem);
	free(get_vct_struct(data));
}
