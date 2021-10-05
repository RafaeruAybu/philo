/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:09:08 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:09:09 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	get_args(int argc, char **argv, t_utils *all)
{
	if (argc != 5 && argc != 6)
		return (-1);
	all->num_of_philos = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	all->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
	{
		all->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (all->number_of_times_each_philosopher_must_eat < 1)
			return (1);
	}
	if (all->num_of_philos < 1 || all->time_to_die < 0 || all->time_to_eat < 0
		|| all->time_to_sleep < 0)
		return (-1);
	return (0);
}
