/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:28:22 by nseon             #+#    #+#             */
/*   Updated: 2025/04/15 15:03:13 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>
#include "utils.h"

/*!
 * Return a pointeur to the next free bite
 * @param dataptr A pointer to the data
 * @return A pointer to the free bite
 */
void	*get_last_dest(void *dataptr)
{
	void	**data;
	t_vct	*vct_struct;

	data = (void **)dataptr;
	vct_struct = get_vct_struct(*data);
	if (!place_remain(vct_struct))
	{
		vct_struct = realloc_vct(vct_struct);
		if (!vct_struct)
			return (NULL);
		*data = vct_struct->data;
		return (&vct_struct[vct_struct->elem_size * vct_struct->nb_elem++]);
	}
}

/*!
 * Add a value at the end of the data
 * @param dataptr A pointer to the data
 * @param value The value to be added
 * @return 0 or -1 on failure
 */
int	vct_add(void *dataptr, void *value)
{
	void	**data;
	void	**dest;

	data = (void **)dataptr;
	if (!value)
	{
		vct_destroy(*data);
		return (-1);
	}
	dest = get_last_dest(data);
	if (!dest)
	{
		if (get_vct_struct(*data)->del)
			get_vct_struct(*data)->del(value);
		return (-1);
	}
	ft_memcpy(dest, value, get_vct_struct(*data)->nb_elem);
	return (0);
}

/*!
 * Return a pointeur to the insert dest
 * @param dataptr A pointer to the data
 * @param index Position of the element
 * @return A pointer to the element
 */
void	*get_insert_dest(void *dataptr, int index)
{
	void	**data;
	t_vct	*vct_struct;

	data = (void **)dataptr;
	vct_struct = get_vct_struct(*data);
	if (!place_remain(vct_struct))
	{
		vct_struct = realloc_vct(vct_struct);
		if (!vct_struct)
			return (NULL);
		*data = vct_struct->data;
	}
	ft_memmove(&vct_struct->data[(index + 1) * vct_struct->elem_size],
		&vct_struct[index * vct_struct->elem_size],
		(vct_struct->nb_elem - index) * vct_struct->elem_size);
	vct_struct->nb_elem += 1;
	return (&vct_struct->data[vct_struct->elem_size * index]);
}

/*!
 * Insert a value at the index
 * @param dataptr A pointer to the data
 * @param value The value to be added
 * @param index Position of the insert
 * @return 0 or -1 on failure
 */
int	vct_insert(void *dataptr, void *value, int index)
{
	void	**data;
	void	**dest;

	data = (void **)dataptr;
	if (!value)
	{
		vct_destroy(*data);
		return (-1);
	}
	dest = get_insert_dest(data, index);
	if (!dest)
	{
		if (get_vct_struct(*data)->del)
			get_vct_struct(*data)->del(value);
		return (-1);
	}
	ft_memcpy(dest, value, get_vct_struct(*data)->elem_size);
	return (0);
}
