/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:55:50 by microdri          #+#    #+#             */
/*   Updated: 2023/02/04 15:24:05 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_eat(t_philo *philos)
{
	ft_check_printf('e', philos);
	pthread_mutex_lock(&philos->m_time_of_last_meal);
	philos->time_of_last_meal = ft_time_formated(philos);
	pthread_mutex_unlock(&philos->m_time_of_last_meal);
	pthread_mutex_lock(&philos->m_times_that_eat);
	philos->times_that_eat++;
	pthread_mutex_unlock(&philos->m_times_that_eat);
	ft_smart_sleep(philos->rule->time_to_eat, philos);
}

void	*ft_routine(void *philo)
{
	t_philo	*p;

	p = philo;
	while (ft_check_die(p) == 1 && ft_check_isfull(p) == 1)
	{
		ft_take_fork(p, p->fork_first);
		ft_take_fork(p, p->fork_second);
		if (ft_check_die(p) == 0)
			break ;
		ft_eat(p);
		ft_drop_forks(p);
		if (ft_check_die(p) == 0)
			break ;
		ft_check_printf('s', p);
		ft_smart_sleep(p->rule->time_to_sleep, p);
		if (ft_check_die(p) == 0)
			break ;
		ft_check_printf('t', p);
	}
	return (NULL);
}
