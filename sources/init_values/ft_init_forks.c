/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:07:54 by microdri          #+#    #+#             */
/*   Updated: 2023/01/24 14:09:23 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
	philos->rule->forks[index_philo] = 1;
}
