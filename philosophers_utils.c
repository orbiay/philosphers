/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:47:46 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/02 12:53:56 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

long long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_philosopher	*forks_init(t_philosopher *var)
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print2;
	int				i;

	fork = malloc (sizeof(pthread_mutex_t) * var->members);
	print2 = malloc(sizeof(pthread_mutex_t));
	i = 0;
	pthread_mutex_init(print2, NULL);
	while (i < var->members)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < var->members)
	{
		var[i].print = print2;
		var[i].forks = fork;
		i++;
	}
	return (var);
}

void	ft_usleep(long long sleep)
{
	long long	time;

	time = gettime();
	while (gettime() - time < sleep)
	{
		usleep (250);
	}
}

int	is_intiger(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] > 57 || av[i][j] < 48) && av[i][j] != 43)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arguments(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if ((av[i][j - 1] == '+' && av[i][j] == '\0')
			|| (av[i][j - 1] == '-' && av[i][j] == '\0'))
			return (0);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
