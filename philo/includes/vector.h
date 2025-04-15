/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:43:42 by nseon             #+#    #+#             */
/*   Updated: 2025/04/15 15:17:33 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdint.h>

typedef struct s_vct
{
	int		elem_size;
	int		nb_elem;
	int		capacity;
	void	(*del)(void *);
	uint8_t	data[];
}	t_vct;

void	*vct_init(int elem_size, void (*del)(void *));
t_vct	*get_vct_struct(void *data);
void	free_vct(void *vct);
t_vct	*realloc_vct(t_vct *vct);
int		place_remain(t_vct *vct);
int		vct_size(void *data);
void	vct_delete_next(void *data, int index, int nb);
void	vct_delete_one(void *data, int index);
void	vct_destroy(void *data);
int		vct_insert(void *dataptr, void *value, int index);
int		vct_add(void *dataptr, void *value);

#endif
