/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:08:31 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:08:34 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*philosof(void *in)
{
	int				local_id;
	int				local_time_to_eat;
	struct timeval	te;
	long long		milliseconds;
	t_utils			*all;

	all = (t_utils *)in;
	local_id = all->philos.counter++;
	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	all->server.ph_status.array[local_id] = milliseconds;
	local_time_to_eat = all->number_of_times_each_philosopher_must_eat;
	while (all->server.is_philo_dead != 1 && all->server.is_philos_stopped
		!= 1 && all->num_of_philos != 1)
	{
		if (all->number_of_times_each_philosopher_must_eat != -1)
			all->server.ph_status.array_times_to_eat[local_id]++;
		philo_eat(all, local_id);
		philo_sleep(all, local_id);
		philo_think(all, local_id);
	}
	return (NULL);
}
