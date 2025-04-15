/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:40:05 by nseon             #+#    #+#             */
/*   Updated: 2025/04/15 13:20:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_realloc(void *tab, int size, int resize);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
