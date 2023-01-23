/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:55:50 by microdri          #+#    #+#             */
/*   Updated: 2023/01/23 18:32:15 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void give_back_forks(t_philo *philos)
{
	pthread_mutex_lock(&philos->rule->mutex_forks[philos->fork_first]);
	if(philos->rule->forks[philos->fork_first] == 0)
		philos->rule->forks[philos->fork_first] = 1;
	pthread_mutex_unlock(&philos->rule->mutex_forks[philos->fork_first]);
	pthread_mutex_lock(&philos->rule->mutex_forks[philos->fork_second]);
	if(philos->rule->forks[philos->fork_second] == 0)
		philos->rule->forks[philos->fork_second] = 1;
	pthread_mutex_unlock(&philos->rule->mutex_forks[philos->fork_second]);
}

void *ft_routine(void *philo)
{
	t_philo *p;

	p = philo; //cast
	while (1)
	{
		ft_take_fork(p, p->fork_first);
		ft_take_fork(p, p->fork_second);
		printf("%ld\t%d\tIs eating\n",ft_current_time(p), p->pid);
		usleep(p->rule->time_to_eat * 1000);
		give_back_forks(p);
		printf("%ld\t%d\tIs sleeping\n",ft_current_time(p), p->pid);
		usleep(p->rule->time_to_sleep * 1000);
		printf("%ld\t%d\tIs thinking\n",ft_current_time(p), p->pid);
		
	}
	return (NULL);
}

