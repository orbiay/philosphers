/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:45:47 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/01 10:48:26 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include<pthread.h>
# include <sys/time.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct philosopher
{
	long long		start_time;
	int				members;
	int				index;
	long long		t_eat;
	long long		t_sleep;
	long long		t_die;
	long long		last_t_eat;
	long long		num_of_eat;
	pthread_mutex_t	*forks;
	int				must_eat;
	pthread_mutex_t	*print;
	int				if_true;
}t_philosopher;

int				ft_atoi(const char *str);
int				is_intiger(char **av);
int				check_arguments(char **av);
long long		gettime(void);
t_philosopher	*forks_init(t_philosopher *var);
void			ft_usleep(long long sleep);
void			norminette2(t_philosopher	*philo);
void			norminette(t_philosopher	*philo);
t_philosopher	*initiale_var(char **av, t_philosopher *philos, int ac );
int				is_all_finish_eat(t_philosopher	*philosopher);
#endif
