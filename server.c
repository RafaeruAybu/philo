/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:09:02 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:09:03 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	check_every_count_must_eat(t_utils *all)
{
	int	j;

	j = 0;
	if (all->number_of_times_each_philosopher_must_eat != -1)
	{
		while (j < all->num_of_philos)
		{
			if (all->server.ph_status.array_times_to_eat[j]
				!= all->number_of_times_each_philosopher_must_eat)
				break ;
			if (j == (all->num_of_philos - 1)
				&& all->server.ph_status.array_times_to_eat[j]
				== all->number_of_times_each_philosopher_must_eat)
			{
				all->server.is_philos_stopped = 1;
				pthread_mutex_unlock(&all->main);
				return (1);
			}
			j++;
		}
	}
	return (0);
}

static int	main_loop(t_utils *all, long long milliseconds)
{
	int	i;

	i = 0;
	while (i < all->server.ph_status.array_size)
	{
		if (all->server.ph_status.array[i] != -1)
		{
			if ((milliseconds - all->server.ph_status.array[i])
				>= all->time_to_die)
			{
				my_printf(all, "%lld %d is died\n", i + 1,
					  milliseconds - all->global_time);
				all->server.is_philo_dead = 1;
				pthread_mutex_unlock(&all->main);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	*server(void *serv_arg)
{
	t_utils			*all;
	struct timeval	te;
	long long		milliseconds;

	all = (t_utils *)(serv_arg);
	while (1)
	{
		if (check_every_count_must_eat(all))
			return (NULL);
		usleep(50);
		gettimeofday(&te, NULL);
		milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
		if (main_loop(all, milliseconds))
			return (NULL);
	}
	return (NULL);
}
