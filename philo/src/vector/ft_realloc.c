/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:36:26 by nseon             #+#    #+#             */
/*   Updated: 2025/04/15 16:37:13 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "utils.h"

void	*ft_realloc(void *tab, int size, int resize)
{
	void	*new_tab;

	new_tab = malloc(resize);
	if (!new_tab)
		return (NULL);
	ft_memcpy(new_tab, tab, size);
	free(tab);
	return (new_tab);
}
