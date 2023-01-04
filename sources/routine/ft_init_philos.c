/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:57:41 by microdri          #+#    #+#             */
/*   Updated: 2023/01/03 21:59:00 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philo *ft_init_philos(t_rules *rule)
{
	t_philo *philos;
	int 	index_philo;

	philos		= malloc(rule->number_of_philosophers * sizeof(t_philo));
	index_philo	= 0;
	while (index_philo < rule->number_of_philosophers)
	{
		philos[index_philo].pid = index_philo + 1;
		philos[index_philo].rule = rule;	// todos filosofes vao apontar para a mesma struct!
		ft_init_forks(&philos[index_philo], index_philo);
		index_philo++;
	}
	return (philos);
}

void ft_init_forks(t_philo *philos, int index_philo)
{
	if (philos->pid % 2 == 0)
	{
		philos->fork_first = index_philo - 1;
		philos->fork_second = index_philo;
	}
	else if (philos->pid % 2 == 1)
	{
		philos->fork_first = index_philo;
		if (philos->pid == 1)
			philos->fork_second = philos->rule->number_of_philosophers - 1;
		else
			philos->fork_second = index_philo - 1;
	}
}
