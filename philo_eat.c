/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:08:19 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:08:20 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	for_even(t_utils *all, int left_fork_index,
				 int right_fork_index, int index)
{
	struct timeval	te;
	long long		milliseconds;

	pthread_mutex_lock(&all->philos.fork_mutex_array[right_fork_index]);
	pthread_mutex_lock(&all->philos.fork_mutex_array[left_fork_index]);
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	my_printf(all, "%lld %d is eating\n", index + 1,
		  milliseconds - all->global_time);
	my_sleep(all->time_to_eat);
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	all->server.ph_status.array[index] = milliseconds;
	pthread_mutex_unlock(&all->philos.fork_mutex_array[left_fork_index]);
	pthread_mutex_unlock(&all->philos.fork_mutex_array[right_fork_index]);
}

void	for_odd(t_utils *all, int left_fork_index,
				int right_fork_index, int index)
{
	struct timeval	te;
	long long		milliseconds;

	pthread_mutex_lock(&all->philos.fork_mutex_array[left_fork_index]);
	pthread_mutex_lock(&all->philos.fork_mutex_array[right_fork_index]);
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	my_printf(all, "%lld %d is eating\n", index + 1,
		  milliseconds - all->global_time);
	my_sleep(all->time_to_eat);
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	all->server.ph_status.array[index] = milliseconds;
	pthread_mutex_unlock(&all->philos.fork_mutex_array[right_fork_index]);
	pthread_mutex_unlock(&all->philos.fork_mutex_array[left_fork_index]);
}

void	philo_eat(t_utils *all, int index)
{
	int				left_fork_index;
	int				right_fork_index;

	if (index == (all->num_of_philos - 1))
	{
		left_fork_index = index;
		right_fork_index = 0;
	}
	else
	{
		left_fork_index = index;
		right_fork_index = index + 1;
	}
	if (index % 2)
		for_odd(all, left_fork_index, right_fork_index, index);
	else
		for_even(all, left_fork_index, right_fork_index, index);
}
