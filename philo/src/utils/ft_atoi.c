/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:07:40 by nseon             #+#    #+#             */
/*   Updated: 2025/04/23 16:13:28 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && '0' <= nptr[i] && nptr[i] <= '9')
	{
		if ((result * 10 + (nptr[i] - '0')) / 10 != result
			&& !(result == 214748364 && nptr[i] == '8' && sign == -1))
			return (-1);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '\0')
		return (result * sign);
	return (-2);
}
