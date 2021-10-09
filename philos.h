/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:07:46 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:07:50 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philosofers_status_map
{
	long long	*array;
	long long	*array_times_to_eat;
	int			array_size;
}				t_philosofers_status_map;

typedef struct s_server
{
	t_philosofers_status_map	ph_status;
	int							is_philo_dead;
	int							is_philos_stopped;
}				t_server;

typedef struct s_philosofers
{
	int				counter;
	pthread_t		*thread_array;
	pthread_mutex_t	*fork_mutex_array;
}				t_philosofers;

typedef struct s_utils
{
	long long		global_time;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			dead;
	int				number_of_times_each_philosopher_must_eat;
	t_server		server;
	t_philosofers	philos;
	pthread_mutex_t	main;
	pthread_mutex_t print;
}				t_utils;

int		get_args(int argc, char **argv, t_utils *all);
int		execute_server(t_utils *all);
void	*server(void *serv_arg);
int		execute_philos(t_utils *all);
void	*philosof(void *in);
void	philo_eat(t_utils *all, int index);
void	philo_sleep(t_utils *all, int index);
void	philo_think(t_utils *all, int index);
void	my_printf(t_utils *all, char *str, int index, long long timestamp);
void	my_sleep(int m_second);
int		ft_atoi(const char *s);
long long	get_global_time(void);

#endif
