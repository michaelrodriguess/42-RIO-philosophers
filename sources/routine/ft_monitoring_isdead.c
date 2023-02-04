/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_isdead.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:09 by microdri          #+#    #+#             */
/*   Updated: 2023/02/04 15:03:56 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_monitoring_isdead(t_philo *philos)
{
	int	i;

	while (ft_check_die(philos) == 1)
	{
		if (ft_check_allfull(philos) == 0)
			return ;
		i = 0;
		while (i < philos->rule->number_of_philosophers)
		{
			pthread_mutex_lock(&philos[i].m_time_of_last_meal);
			if ((ft_time_formated(&philos[i]) - philos[i].time_of_last_meal)
				> philos->rule->time_to_die && ft_check_isfull(&philos[i]) == 1)
			{
				pthread_mutex_unlock(&philos[i].m_time_of_last_meal);
				pthread_mutex_lock(&philos->rule->m_flag_someone_die);
				philos->rule->flag_someone_die = 0;
				pthread_mutex_unlock(&philos->rule->m_flag_someone_die);
				ft_check_printf('d', &philos[i]);
				break ;
			}
			else
				pthread_mutex_unlock(&philos[i].m_time_of_last_meal);
			i++;
		}
	}
}
