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

static void	clean_all(t_utils *all)
{
	int	i;

	free(all->server.ph_status.array);
	pthread_mutex_destroy(&all->main);
	i = 0;
	while (i < all->num_of_philos)
	{
		pthread_mutex_destroy(&all->philos.fork_mutex_array[i]);
		i++;
	}
	free(all->philos.fork_mutex_array);
	free(all->philos.thread_array);
	free(all->server.ph_status.array_times_to_eat);
}

static long long	get_global_time(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

int	main(int argc, char **argv)
{
	t_utils	all;

	all.global_time = get_global_time();
	if (get_args(argc, argv, &all))
	{
		printf("Bad args!\n");
		return (1);
	}
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
	clean_all(&all);
	return (0);
}
