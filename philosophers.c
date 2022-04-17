/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:39:07 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/02 13:54:37 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	check_die_condition(t_philosopher	*philosopher)
{
	int	i;

	i = 0;
	while ((i < philosopher->members && !is_all_finish_eat (philosopher)))
	{
		if ((gettime() - philosopher[i].last_t_eat) >= philosopher->t_die
			&& philosopher->if_true == 1)
		{
			pthread_mutex_lock(philosopher->print);
			printf("\033[0;35m %lld ms : philo number %d died \n",
				(gettime() - philosopher->start_time),
				philosopher[i].index + 1);
			pthread_mutex_destroy(philosopher->forks);
			pthread_mutex_destroy(philosopher->print);
			return ;
		}
		i = (i + 1) % philosopher->members;
	}
}

void	*routine(void	*philos)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philos;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->index]);
		pthread_mutex_lock(philo->print);
		printf("\033[0;32m%llu ms   :philo %d take first fork\033[0m\n",
			(gettime() - philo->start_time), philo->index + 1);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(&philo->forks[(philo->index + 1) % philo->members]);
		norminette(philo);
	}
	return (0);
}

void	*routine2(void	*philos)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philos;
	while (philo->num_of_eat < philo->must_eat)
	{
		pthread_mutex_lock(&philo->forks[philo->index]);
		pthread_mutex_lock(philo->print);
		printf("\033[0;32m%llu ms   :philo %d take first fork\033[0m\n",
			(gettime() - philo->start_time), philo->index + 1);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(&philo->forks[(philo->index + 1) % philo->members]);
		norminette2(philo);
	}
	return (0);
}

void	create_philos(int ac, char **av, int ac2)
{
	int				i;
	t_philosopher	*philosopher;
	pthread_t		*philo;

	philosopher = malloc (sizeof (t_philosopher) * ft_atoi(av[1]));
	philo = malloc ((sizeof (pthread_t) * ac));
	philosopher = initiale_var(av, philosopher, ac2);
	philosopher = forks_init(philosopher);
	i = 0;
	while (i < ac)
	{
		philosopher[i].last_t_eat = gettime();
		if (ac2 == 5)
			pthread_create(&philo[i], NULL, &routine, &philosopher[i]);
		else if (ac2 == 6)
			pthread_create(&philo[i], NULL, &routine2, &philosopher[i]);
		i++;
		usleep (100);
	}
	check_die_condition(philosopher);
}

int	main(int ac, char	**av)
{
	if (ac == 6 || ac == 5)
	{
		if (check_arguments(av) && is_intiger(av))
			create_philos(ft_atoi(av[1]), av, ac);
		else
		{
			printf("Error : There is a problem in arguments.\n");
			return (0);
		}
	}
	else
		printf("Error : the arguments aren't enough or they're too many.\n");
}
