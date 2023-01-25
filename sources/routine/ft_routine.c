/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:55:50 by microdri          #+#    #+#             */
/*   Updated: 2023/01/25 16:59:56 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void *ft_routine(void *philo)
{
	t_philo *p;

	p = philo;
	while (p->rule->flag_someone_die == 1)
	{
		ft_take_fork(p, p->fork_first);
		ft_take_fork(p, p->fork_second);
		if (p->rule->flag_someone_die == 0)
			break ;
		printf("%ld\t%d\tIs eating\n",ft_time_formated(p), p->pid);
		p->time_of_last_meal = ft_time_formated(p); //get update of last philo eat!
		ft_smart_sleep(p->rule->time_to_eat);
		ft_drop_forks(p);
		if (p->rule->flag_someone_die == 0)
			break ;
		printf("%ld\t%d\tIs sleeping\n",ft_time_formated(p), p->pid);
		ft_smart_sleep(p->rule->time_to_sleep);
	}
	return (NULL);
}

