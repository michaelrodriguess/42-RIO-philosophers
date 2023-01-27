/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:09:29 by microdri          #+#    #+#             */
/*   Updated: 2023/01/27 18:23:41 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philo *ft_init_philos(t_rules *rule)
{
	t_philo *philos;
	int 	index_philo;

	philos	= malloc(rule->number_of_philosophers * sizeof(t_philo));
	if (!philos)
	{
		free(philos);
		return (0);
	}
	index_philo	= 0;
	while (index_philo < rule->number_of_philosophers)
	{
		philos[index_philo].pid = index_philo + 1;
		philos[index_philo].rule = rule;
		philos[index_philo].times_that_eat = 0;
		ft_init_forks(&philos[index_philo], index_philo);
		index_philo++;
	}
	return (philos);
}
