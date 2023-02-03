/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:11:42 by microdri          #+#    #+#             */
/*   Updated: 2023/02/03 18:03:11 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_init_mutex(t_rules *rule, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		pthread_mutex_init(&rule->mutex_forks[i], NULL);
		pthread_mutex_init(&philos[i].m_times_that_eat, NULL);
		pthread_mutex_init(&rule->m_flag_someone_die, NULL);
		pthread_mutex_init(&philos[i].m_time_of_last_meal, NULL);
		pthread_mutex_init(&rule->m_printf, NULL);
		i++;
	}
}

void	ft_destroy_mutex(t_rules *rule, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		pthread_mutex_destroy(&rule->mutex_forks[i]);
		pthread_mutex_destroy(&philos[i].m_times_that_eat);
		pthread_mutex_destroy(&rule->m_flag_someone_die);
		pthread_mutex_destroy(&philos[i].m_time_of_last_meal);
		pthread_mutex_destroy(&rule->m_printf);
		i++;
	}
}
