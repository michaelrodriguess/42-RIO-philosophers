/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_isdead.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:09 by microdri          #+#    #+#             */
/*   Updated: 2023/01/24 22:44:47 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_monitoring_isdead(t_philo *philos)
{
	int i;

	while (philos->rule->flag_someone_die == 1)
	{
		i = 0;
		philos->time_of_last_meal = ft_get_time();
		while(i < philos->rule->number_of_philosophers)
		{
			if(philos[i].time_of_last_meal > philos->rule->time_to_die)
			{
				philos->rule->flag_someone_die = 0;
				break ;
			}
			i++;
		}
	}
}

