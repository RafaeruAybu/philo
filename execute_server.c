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

	if (pthread_create(&thread, NULL, &server, (void *)(all)) != 0)
	{
		printf("Cant create thread!\n");
		return (-1);
	}
	pthread_detach(thread);
	return (0);
}
