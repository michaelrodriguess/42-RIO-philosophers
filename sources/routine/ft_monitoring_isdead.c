/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_isdead.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:09 by microdri          #+#    #+#             */
/*   Updated: 2023/01/29 19:46:28 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_monitoring_isdead(t_philo *philos)
{
	int i;

	while (ft_check_die(philos) == 1)
	{
		if (ft_check_allfull(philos) == 0)
			return ;
		i = 0;
		while(i < philos->rule->number_of_philosophers)
		{
			if((ft_time_formated(&philos[i]) - philos[i].time_of_last_meal) > philos->rule->time_to_die)
			{
				pthread_mutex_lock(&philos->rule->m_flag_someone_die);
				philos->rule->flag_someone_die = 0;
				pthread_mutex_unlock(&philos->rule->m_flag_someone_die);
				printf("%ld\t%d\tdied\n", ft_time_formated(philos), philos[i].pid);
				break ;
			}
			i++;
		}
	}
}