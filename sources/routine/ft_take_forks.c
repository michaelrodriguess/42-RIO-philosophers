/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:02 by microdri          #+#    #+#             */
/*   Updated: 2023/01/25 14:43:56 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_take_fork(t_philo *philos, int which_fork)
{
	while(philos->rule->flag_someone_die == 1)
	{
		pthread_mutex_lock(&philos->rule->mutex_forks[which_fork]);
		if(philos->rule->forks[which_fork] == 1)
		{
			philos->rule->forks[which_fork] = 0;
			printf("%ld\t%d\t%s\n", ft_current_time(philos), philos->pid, "Has taken a fork");
			pthread_mutex_unlock(&philos->rule->mutex_forks[which_fork]);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philos->rule->mutex_forks[which_fork]);
			usleep(300);
		}
	}
}
