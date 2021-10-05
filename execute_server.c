/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:08:43 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:08:44 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	execute_server(t_utils *all)
{
	pthread_t	thread;
	int			i;

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
	if (pthread_create(&thread, NULL, &server, (void *)(all)) != 0)
	{
		printf("Cant create thread!\n");
		return (-1);
	}
	pthread_detach(thread);
	return (0);
}
