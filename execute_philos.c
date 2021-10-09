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

static void	init_threads(t_utils *all)
{
	int	i;

	i = 0;
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
		i += 2;
	}
	my_sleep(all->time_to_eat - 10);
	i = 1;
	while (i < all->num_of_philos)
	{
		pthread_join(all->philos.thread_array[i], NULL);
		i += 2;
	}
}

int	execute_philos(t_utils *all)
{
	init_threads(all);
	join_philos(all);
	return (0);
}
