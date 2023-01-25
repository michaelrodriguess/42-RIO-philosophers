/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:54:38 by microdri          #+#    #+#             */
/*   Updated: 2023/01/25 12:01:20 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_drop_forks(t_philo *philos)
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
