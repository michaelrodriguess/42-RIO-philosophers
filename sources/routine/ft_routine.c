/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:55:50 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 20:09:41 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
		ft_check_printf('e', p);
		pthread_mutex_lock(&p->m_times_that_eat);
		p->times_that_eat++;
		pthread_mutex_unlock(&p->m_times_that_eat);
		pthread_mutex_lock(&p->m_time_of_last_meal);
		p->time_of_last_meal = ft_time_formated(p);
		pthread_mutex_unlock(&p->m_time_of_last_meal);
		ft_smart_sleep(p->rule->time_to_eat);
		ft_drop_forks(p);
		if (ft_check_die(p) == 0)
			break ;
		ft_check_printf('s', p);
		ft_check_printf('t', p);
		ft_smart_sleep(p->rule->time_to_sleep);
	}
	return (NULL);
}
