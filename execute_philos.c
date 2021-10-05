/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:08:00 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:08:01 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	create_mutex_objects(t_utils *all)
{
	int	i;

	all->philos.fork_mutex_array = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * all->num_of_philos);
	i = 0;
	while (i < all->num_of_philos)
	{
		pthread_mutex_init(&all->philos.fork_mutex_array[i], NULL);
		i++;
	}
}

static void	malloc_threads(t_utils *all)
{
	all->philos.thread_array = (pthread_t *)malloc
		(sizeof(pthread_t) * all->num_of_philos);
}

static void	init_threads(t_utils *all)
{
	int	i;

	all->server.ph_status.array_times_to_eat = (long long *)malloc
		(sizeof(long long) * all->num_of_philos);
	i = 0;
	while (i < all->num_of_philos)
	{
		if (all->number_of_times_each_philosopher_must_eat != -1)
			all->server.ph_status.array_times_to_eat[i] = 0;
		else
			all->server.ph_status.array_times_to_eat[i] = -1;
		i++;
	}
	i = 0;
	all->philos.counter = 0;
	while (i < all->num_of_philos)
	{
		pthread_create(&all->philos.thread_array[i],
			   NULL, &philosof, (void *)all);
		i++;
	}
}

static void	join_philos(t_utils *all)
{
	int	i;

	i = 0;
	while (i < all->num_of_philos)
	{
		pthread_join(all->philos.thread_array[i], NULL);
		i++;
	}
}

int	execute_philos(t_utils *all)
{
	create_mutex_objects(all);
	malloc_threads(all);
	init_threads(all);
	join_philos(all);
	return (0);
}
