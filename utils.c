/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:09:25 by igearhea          #+#    #+#             */
/*   Updated: 2021/10/05 20:09:27 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	foo(char **str, int *sign)
{
	while ((**str == ' ') || ((**str >= 9) && (**str <= 13)))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

int	ft_atoi(const char *s)
{
	long long	number;
	int			sign;
	char		*str;

	str = (char *)s;
	sign = 1;
	number = 0;
	foo(&str, &sign);
	while ((*str >= '0') && (*str <= '9'))
	{
		if (number > 2147483647 / 10 || (number == 2147483647 / 10
				&& *str - '0' > 7))
			if (sign == 1)
				return (-1);
		if (number > 2147483648 / 10 || (number == 2147483648 / 10
				&& *str - '0' > 8))
		{
			if (sign != 1)
				return (0);
		}
		number = 10 * number + (*str - '0');
		str++;
	}
	return (sign * (int)number);
}

void	my_printf(t_utils *all, char *str, int index, long long timestamp)
{
	if (all->server.is_philo_dead == 0)
		printf(str, timestamp, index);
}

void	my_sleep(int m_second)
{
	struct timeval	te;
	long long		t0;
	long long		t1;

	gettimeofday(&te, NULL);
	t0 = te.tv_sec * 1000LL + te.tv_usec / 1000;
	t1 = t0;
	while ((t1 - t0) < m_second)
	{
		usleep(50);
		gettimeofday(&te, NULL);
		t1 = te.tv_sec * 1000LL + te.tv_usec / 1000;
	}
}
