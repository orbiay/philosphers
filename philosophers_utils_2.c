/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:11:51 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/02 12:26:21 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	is_all_finish_eat(t_philosopher	*philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->members)
	{
		if (philosopher[i].num_of_eat != philosopher->must_eat)
			return (0);
		i++;
	}
	return (1);
}

t_philosopher	*initiale_var(char	**av, t_philosopher	*philos, int ac )
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].members = ft_atoi(av[1]);
		philos[i].index = i;
		philos[i].start_time = gettime();
		philos[i].t_die = (ft_atoi(av[2]));
		philos[i].t_eat = (ft_atoi(av[3]));
		philos[i].t_sleep = (ft_atoi(av[4]));
		philos[i].must_eat = -1;
		philos[i].num_of_eat = 0;
		philos[i].if_true = 1;
		if (ac == 6)
			philos[i].must_eat = ft_atoi(av[5]);
		i++;
	}
	return (philos);
}

void	norminette2(t_philosopher	*philo)
{
	pthread_mutex_lock(philo->print);
	printf("\033[0;34m%llu ms   :philo %d take second fork\033[0m\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	philo->if_true = 0;
	printf("\033[0;31m%llu ms   :philo %d started eating \033[0m\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock (philo->print);
	philo->last_t_eat = gettime();
	ft_usleep(philo->t_eat);
	philo->num_of_eat++;
	philo->if_true = 1;
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d sleeping\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->t_sleep);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d thinking\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
}

void	norminette(t_philosopher	*philo)
{
	pthread_mutex_lock(philo->print);
	printf("\033[0;34m%llu ms   :philo %d take second fork\033[0m\n",
		(gettime() - philo->start_time), philo->index + 1);
	philo->if_true = 0;
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d started eating \n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	philo->last_t_eat = gettime();
	ft_usleep(philo->t_eat);
	philo->if_true = 1;
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d sleeping\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->t_sleep);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d thinking\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
}
