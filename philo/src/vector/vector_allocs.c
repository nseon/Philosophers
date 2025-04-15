/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_allocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:26:01 by nseon             #+#    #+#             */
/*   Updated: 2025/04/15 16:12:27 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>
#include "utils.h"

/*!
* Realloc a vct twice the size & coopy the content
* @param vct The current vector
* @return The new vector or NULL on failure
*/
t_vct	*realloc_vct(t_vct *vct)
{
	t_vct	*resized_vct;
	int		old_capacity;

	old_capacity = vct->capacity;
	resized_vct = ft_realloc(vct, vct->nb_elem * vct->elem_size + sizeof(t_vct),
			(2 * vct->capacity * vct->elem_size) + sizeof(t_vct));
	if (!resized_vct)
		return (NULL);
	resized_vct->capacity = 2 * old_capacity;
	return (resized_vct);
}

