/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:09:29 by microdri          #+#    #+#             */
/*   Updated: 2023/01/25 13:51:19 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philo *ft_init_philos(t_rules *rule)
{
	t_philo *philos;
	int 	index_philo;

	philos	= malloc(rule->number_of_philosophers * sizeof(t_philo));
	index_philo	= 0;
	while (index_philo < rule->number_of_philosophers)
	{
		philos[index_philo].pid = index_philo + 1;
		philos[index_philo].rule = rule;
		ft_init_forks(&philos[index_philo], index_philo);
		index_philo++;
	}
	return (philos);
}
