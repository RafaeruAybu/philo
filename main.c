/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:07:32 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:07:34 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void init_all(t_utils *all)
{
	int i;

	pthread_mutex_init(&all->print, NULL);
	pthread_mutex_init(&all->main, NULL);
	pthread_mutex_lock(&all->main);
	all->server.is_philo_dead = 0;
	all->server.is_philos_stopped = 0;
	all->server.ph_status.array = (long long *)malloc
			(sizeof(long long) * all->num_of_philos);
	all->server.ph_status.array_size = all->num_of_philos;
	i = 0;
	while (i < all->server.ph_status.array_size)
	{
		all->server.ph_status.array[i] = -1;
		i++;
	}
	all->philos.fork_mutex_array = (pthread_mutex_t *)malloc
			(sizeof(pthread_mutex_t) * all->num_of_philos);
	i = 0;
	while (i < all->num_of_philos)
	{
		pthread_mutex_init(&all->philos.fork_mutex_array[i], NULL);
		i++;
	}
	all->philos.thread_array = (pthread_t *)malloc
			(sizeof(pthread_t) * all->num_of_philos);
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
	all->philos.counter = 0;
}

//static void	destroy_all(t_utils *all)
//{
//
//}

int	main(int argc, char **argv)
{
	t_utils	all;

	all.global_time = get_global_time();
	if (get_args(argc, argv, &all))
	{
		printf("Bad args!\n");
		return (1);
	}
	init_all(&all);
	if (execute_server(&all))
	{
		printf("Can't execute server!\n");
		return (1);
	}
	if (execute_philos(&all))
	{
		printf("Can't execute philosofers!\n");
		return (1);
	}
	pthread_mutex_lock(&all.main);
	pthread_mutex_unlock(&all.main);
//	destroy_all(&all);
	return (0);
}
