/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:55:50 by microdri          #+#    #+#             */
/*   Updated: 2023/02/01 18:27:40 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void *ft_routine(void *philo)
{
	t_philo *p;

	p = philo;
	while (ft_check_die(p) == 1 && ft_check_isfull(p) == 1)
	{
		ft_take_fork(p, p->fork_first);
		ft_take_fork(p, p->fork_second);
		if (ft_check_die(p) == 0)
			break;
		printf("%ld\t%d\tIs eating\n",ft_time_formated(p), p->pid);
		pthread_mutex_lock(&p->m_times_that_eat);
		p->times_that_eat++; // lock times_that_eat
		pthread_mutex_unlock(&p->m_times_that_eat);
		pthread_mutex_lock(&p->m_time_of_last_meal);
		p->time_of_last_meal = ft_time_formated(p); //lock time_of_last_meal and get update of last philo eat!
		pthread_mutex_unlock(&p->m_time_of_last_meal);
		ft_smart_sleep(p->rule->time_to_eat);
		ft_drop_forks(p);
		if (ft_check_die(p) == 0)
			break;
		printf("%ld\t%d\tIs sleeping\n",ft_time_formated(p), p->pid);
		ft_smart_sleep(p->rule->time_to_sleep);
	}
	return (NULL);
}

