/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:05:02 by nseon             #+#    #+#             */
/*   Updated: 2025/04/10 18:28:02 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

/*!
* Allocate memory for the vector & init his values
* @param elem_size sizeof (elem_type)
* @param del delete function
* @return Pointer to the start of the data or NULL on failure
*/
void	*vct_init(int elem_size, void (*del)(void *))
{
	t_vct	*vct;

	vct = malloc(sizeof(t_vct) + elem_size);
	if (!vct)
		return (NULL);
	vct->elem_size = elem_size;
	vct->del = del;
	vct->nb_elem = 0;
	vct->capacity = 1;
	return (&vct->data);
}

/*!
* Get the beginning of the vector's structure
* @param data Vct->data
* @return Pointer to the start of the vector's structure
*/
t_vct	*get_vct_struct(void *data)
{
	return (&((t_vct *)data)[-1]);
}

/*!
* Free the vector's structure
* @param data Vector data
*/
void	free_vct(void *data)
{
	free(get_vector_struct(data));
}
