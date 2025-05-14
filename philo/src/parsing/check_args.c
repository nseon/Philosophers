/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:47:22 by nseon             #+#    #+#             */
/*   Updated: 2025/05/14 13:17:44 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>
#include <stdio.h>

int	num_is_good(int nb)
{
	if (nb < 0)
		return (0);
	return (1);
}

char	*choose_elem(int i)
{
	char	*use;

	if (i == 1)
		use = ft_strdup("nb_of_philo");
	else if (i == 2)
		use = ft_strdup("time_to_die");
	else if (i == 3)
		use = ft_strdup("time_to_eat");
	else if (i == 4)
		use = ft_strdup("time_to_sleep");
	else if (i == 5)
		use = ft_strdup("[nb_of_times_each_philo_must_eat]");
	else
		use = NULL;
	return (use);
}

int	print_error(int i, char *arg)
{
	char	*use;
	char	*error;

	use = choose_elem(i);
	if (!use)
		return (-1);
	if (ft_atoi(arg) == -2)
		error = ft_strdup("is incorrectly formatted");
	else if (arg[0] == '-')
		error = ft_strdup("is a negative number");
	else
		error = ft_strdup("is bigger than an int");
	if (!error)
		return (free(use), -1);
	printf("%-34s %s\n", use, error);
	free(use);
	free(error);
	return (0);
}

int	verif_args(int argc, char **args)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo  nb_of_philo  time_to_die  time_to_eat"
			"  time_to_sleep  [nb_of_times_each_philo_must_eat]\n");
		return (-1);
	}
	while (args[++i])
	{
		if (!num_is_good(ft_atoi(args[i])))
		{
			if (print_error(i, args[i]) == -1)
				return (-1);
			error = 1;
		}
	}
	if (error)
		return (-1);
	return (0);
}
