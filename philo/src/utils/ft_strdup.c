/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:24:19 by nseon             #+#    #+#             */
/*   Updated: 2025/04/16 10:37:01 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(ft_strlen(s) + 1);
	if (tab == NULL)
		return (0);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}
